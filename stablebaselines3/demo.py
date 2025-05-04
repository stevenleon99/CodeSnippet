import gymnasium as gym
from gymnasium import spaces
from gymnasium.envs.registration import register
import numpy as np
from stable_baselines3 import PPO
import matplotlib.pyplot as plt
import time

# -----------------------------
# Custom Two-Link Pendulum Env
# -----------------------------
class TwoLinkPendulumEnv(gym.Env):
    metadata = {"render_modes": ["human"], "render_fps": 60}

    def __init__(self):
        super().__init__()

        self.dt = 0.05
        self.g = 9.8
        self.m1 = 1.0
        self.m2 = 1.0
        self.l1 = 1.0
        self.l2 = 1.0

        # Observation space: [cos(theta1), sin(theta1), cos(theta2), sin(theta2), dtheta1, dtheta2]
        high = np.array([1.0]*4 + [np.inf]*2, dtype=np.float32)
        self.observation_space = spaces.Box(low=-high, high=high, dtype=np.float32)

        # Action: torque at joint 1
        self.action_space = spaces.Box(low=-2.0, high=2.0, shape=(1,), dtype=np.float32)

        self.state = None
        self.viewer_initialized = False

    def reset(self, seed=None, options=None):
        super().reset(seed=seed)
        self.state = np.random.uniform(low=-0.1, high=0.1, size=(4,))
        return self._get_obs(), {}

    def _get_obs(self):
        theta1, theta2, dtheta1, dtheta2 = self.state
        return np.array([
            np.cos(theta1), np.sin(theta1),
            np.cos(theta2), np.sin(theta2),
            dtheta1, dtheta2
        ], dtype=np.float32)

    def step(self, action):
        theta1, theta2, dtheta1, dtheta2 = self.state
        torque = np.clip(action[0], -2.0, 2.0)

        # Physics (simplified)
        ddtheta1 = (-self.g / self.l1 * np.sin(theta1) + torque / (self.m1 * self.l1 ** 2))
        ddtheta2 = (-self.g / self.l2 * np.sin(theta2))

        dtheta1 += ddtheta1 * self.dt
        dtheta2 += ddtheta2 * self.dt
        theta1 += dtheta1 * self.dt
        theta2 += dtheta2 * self.dt

        self.state = np.array([theta1, theta2, dtheta1, dtheta2], dtype=np.float32)

        # Reward: upright + smooth movement
        upright_reward = np.cos(theta1) + np.cos(theta2)
        energy_penalty = 0.01 * (dtheta1**2 + dtheta2**2) + 0.001 * torque**2
        reward = upright_reward - energy_penalty

        terminated = False  # Keep training continuous
        truncated = False
        return self._get_obs(), reward, terminated, truncated, {}


    def render(self):
        if not hasattr(self, 'fig'):
            self.fig, self.ax = plt.subplots()
            self.ax.set_aspect('equal')
            self.ax.set_xlim(-2.5, 2.5)
            self.ax.set_ylim(-2.5, 2.5)
            self.line1, = self.ax.plot([], [], 'o-', lw=4, color='blue')
            self.line2, = self.ax.plot([], [], 'o-', lw=4, color='red')
            plt.ion()
            plt.show()

        theta1, theta2, _, _ = self.state
        x1 = self.l1 * np.sin(theta1)
        y1 = -self.l1 * np.cos(theta1)
        x2 = x1 + self.l2 * np.sin(theta2)
        y2 = y1 - self.l2 * np.cos(theta2)

        self.line1.set_data([0, x1], [0, y1])
        self.line2.set_data([x1, x2], [y1, y2])
        self.fig.canvas.draw()
        self.fig.canvas.flush_events()

# -----------------------------
# Register the Environment
# -----------------------------
register(
    id="TwoLinkPendulum-v0",
    entry_point=__name__ + ":TwoLinkPendulumEnv"
)

# -----------------------------
# Training & Evaluation Script
# -----------------------------
def main():
    env = gym.make("TwoLinkPendulum-v0")

    # Train the PPO agent
    model = PPO("MlpPolicy", env, verbose=1)
    model.learn(total_timesteps=200_000)

    # Evaluate the trained policy
    obs, _ = env.reset()
    for _ in range(500):
        action, _ = model.predict(obs, deterministic=True)
        obs, reward, terminated, truncated, _ = env.step(action)
        env.render()
        time.sleep(env.unwrapped.dt)
        if terminated or truncated:
            obs, _ = env.reset()

    plt.ioff()
    plt.show()

if __name__ == "__main__":
    main()