from transformers import SegformerImageProcessor, AutoModelForSemanticSegmentation
import matplotlib.pyplot as plt
from PIL import Image
import torch.nn as nn
import numpy as np

processor = SegformerImageProcessor.from_pretrained("mattmdjaga/segformer_b2_clothes")
model = AutoModelForSemanticSegmentation.from_pretrained("mattmdjaga/segformer_b2_clothes")
image = Image.open("D:/ai_model_deploy_test/test_image.jpg")
inputs = processor(images=image, return_tensors="pt")
outputs = model(**inputs)
logits = outputs.logits.cpu()
upsampled_logits = nn.functional.interpolate(
    logits,
    size=image.size[::-1],
    mode="bilinear",
    align_corners=False,
)
pred_seg = upsampled_logits.argmax(dim=1)[0]
tensor_img = pred_seg.cpu()
# Convert to NumPy
img = tensor_img.numpy()

# Plot as image
plt.imshow(img, cmap='gray')  # 'gray' for grayscale, or 'viridis', 'hot', etc.
plt.title("Tensor Image")
plt.axis('off')
plt.show()
