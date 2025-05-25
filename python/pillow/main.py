from PIL import Image, ImageDraw, ImageFont

image = Image.open("original.jpg")
watermark = ImageDraw.Draw(image)
font = ImageFont.truetype("arial.ttf", 36)
watermark.text((10, 10), "© AI Generated", font=font, fill=(255, 255, 255, 128))
image.save("watermarked.jpg")
