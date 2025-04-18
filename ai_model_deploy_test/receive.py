import requests
import time
import numpy as np
import matplotlib.pyplot as plt

starttime = time.time()
# response = requests.post("http://52.54.217.197/info")


# Path to your image
image_path = "D:/ai_model_deploy_test/test_image3.jpg"

# Open the image file in binary mode
with open(image_path, "rb") as f:
    files = {"file": ("test_image.jpg", f, "image/jpeg")}
    response = requests.post("http://52.54.217.197/segment", files=files)
endtime = time.time()

raw_res = response.json()
np_res = np.array(raw_res["mask"])
# Plot as image
plt.imshow(np_res, cmap='gray')  # 'gray' for grayscale, or 'viridis', 'hot', etc.
plt.title("Tensor Image")
plt.axis('off')
plt.show()

print("latency: ", endtime - starttime)