# !.unet/bin/python

from fastapi import FastAPI, UploadFile, File
import torch
from torchvision import transforms
from PIL import Image
import io

from transformers import SegformerImageProcessor, AutoModelForSemanticSegmentation
from PIL import Image
import torch.nn as nn
import numpy as np


print("u-net testing application ...")

# # Load your U-Net model
# # from unet_model import UNet  # your model definition
# # model = UNet()
# # model.load_state_dict(torch.load("unet_model.pth", map_location="cpu"))
# # model.eval()

app = FastAPI()

# Load the model and processor
processor = SegformerImageProcessor.from_pretrained("mattmdjaga/segformer_b2_clothes")
model = AutoModelForSemanticSegmentation.from_pretrained("mattmdjaga/segformer_b2_clothes")

@app.post("/segment")
async def segment(file: UploadFile = File(...)):
    # Read the uploaded image
    image_bytes = await file.read()
    image = Image.open(io.BytesIO(image_bytes)).convert("RGB")
    
    print("well received the image ...")
    
    # # Or load from disk (for testing)
    # image = Image.open("/home/ubuntu/steve/test_image.jpg")

    # Preprocess
    inputs = processor(images=image, return_tensors="pt")
    outputs = model(**inputs)
    logits = outputs.logits.cpu()

    # Resize prediction to match original image size
    upsampled_logits = nn.functional.interpolate(
        logits,
        size=image.size[::-1],
        mode="bilinear",
        align_corners=False,
    )

    # Get segmentation prediction
    pred_seg = upsampled_logits.argmax(dim=1)[0]

    # Convert to NumPy array and then to list
    img = pred_seg.cpu().numpy().tolist()

    # return {"mask": "send back the mask"}
    return {"mask": img}

@app.post("/info")
async def info():
    return {"system": "unet-inference-server", "name": "ubuntu", "ip": "13.219.250.188"}