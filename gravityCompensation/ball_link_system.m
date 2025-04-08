% inital theta
theta1 = pi/4;
theta2 = pi/6;

% dt
t = 10;
dt = 0.01;
N = t/dt;

% Create a figure
figure;
clf;
hold on;
axis equal;
axis([-2.2 2.2 -2.2 2.2]);  % Fixed axis limits
grid on;
% Plot handle initialization (just to speed up updates)
arm_plot = plot([0, 0, 0], [0, 0, 0], '-o', 'LineWidth', 2);
title_handle = title('');
yline(0, '--k', 'Ground');  % Ground line for reference

% simulate the process:
% arm starts at initial position
% no torque applied to the joint
% no initial speed of joint
% the arm is supposed to fall onto the ground
ddq = dynamics(theta1, theta2, 0, 0, 0, 0);
dq = [0; 0];
q = [theta1; theta2];
L1 = 1; L2 = 1;
tau = [0; 0];
% Simulation loop
for i = 1:N

    ddq = dynamics(q(1), q(2), dq(1), dq(2), tau(1), tau(2));  % No torque
    dq = dq + ddq * dt;      % Update velocity
    q = q + dq * dt;         % Update position

    % Constraint: prevent falling through ground
    pos = kinematics(q(1), q(2))
    tau = gravityCompensation(q)

    draw(arm_plot, q(1), q(2), dt, title_handle);
end

%% ------------------------ %%
% gravity compensation function
function tau = gravityCompensation(q)

L1 = 1; L2 = 1;
m1 = 1; m2 = 1;
g = 9.81;
theta1 = q(1); theta2 = q(2);

% G(q) (partial derivative to theta1 and theta2 with gravity vector)
G = [(m1*L1/2 + m2*L1)*g*cos(theta1) + m2*g*L2/2*cos(theta1 + theta2);
      m2*g*L2/2*cos(theta1 + theta2)];

tau = G;

end
%% ------------------------ %%

%% ------------------------ %%
% dynamics function
function pos = kinematics(theta1, theta2)

L1 = 1; L2 = 1;
x1 = L1 * cos(theta1);         y1 = L1 * sin(theta1);
x2 = x1 + L2 * cos(theta1 + theta2);
y2 = y1 + L2 * sin(theta1 + theta2);

pos = [[x1, x2]; [y1, y2]];
end
%% ------------------------ %%


%% ------------------------ %%
% dynamics function
function ddq = dynamics(theta1, theta2, dtheta1, dtheta2, tau1, tau2)
    % Parameters
    m1 = 1; m2 = 1;
    L1 = 1; L2 = 1;
    g = 9.81;
    
    % Inertia terms (mid-link mass assumed at half-length)
    I1 = (1/12) * m1 * L1^2;
    I2 = (1/12) * m2 * L2^2;
    
    % Composite constants
    a = I1 + I2 + m2 * L1^2;
    b = m2 * L1 * L2 / 2;
    d = I2 + m2 * (L2^2) / 4;
    
    % Mass matrix M(q)
    M = [a + 2*b*cos(theta2), d + b*cos(theta2);
         d + b*cos(theta2), d];

    % Coriolis and centrifugal terms (derived from M)
    C = [-b*sin(theta2)*dtheta2*(2*dtheta1 + dtheta2);
          b*sin(theta2)*dtheta1^2];

    % G(q) (partial derivative to theta1 and theta2 with gravity vector)
    G = [(m1*L1/2 + m2*L1)*g*cos(theta1) + m2*g*L2/2*cos(theta1 + theta2);
          m2*g*L2/2*cos(theta1 + theta2)];
    
    % Torques
    Tau = [tau1; tau2];
    
    % Compute joint accelerations
    ddq = M \ (Tau - C - G);
end
%% ------------------------ %%

%% ------------------------ %%
% draw function
function draw(arm_plot, theta1, theta2, dt, title_handle)
    L1 = 1;
    L2 = 1;
    x0 = 0; y0 = 0;
    pos = kinematics(theta1, theta2);
    
    set(arm_plot, 'XData', [x0 pos(1, :)], 'YData', [y0 pos(2, :)]);
    set(title_handle, 'String', sprintf('\\theta_1 = %.2f rad, \\theta_2 = %.2f rad', theta1, theta2));

    pause(dt);
end
%% ------------------------ %%