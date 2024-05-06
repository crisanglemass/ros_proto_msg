import os
import base64
from PIL import Image



# Open the image and get its size
def get_size(image_path):
    with Image.open(image_path) as img:
        image_size = img.size
        return image_size

# Convert the image to base64 encoding and calculate the size
def get_base64_size(image_path):
    with open(image_path, "rb") as img_file:
        image_data = img_file.read()
        base64_data = base64.b64encode(image_data)
        base64_size = len(base64_data)
        return base64_size


if __name__ == "__main__":
    # Define the image path
    image_path = "../image.jpg"
    image_size= get_size(image_path=image_path)
    base64_size=get_base64_size(image_path=image_path)
    print("Image size:", image_size)
    print("Base64 size:", base64_size)
   