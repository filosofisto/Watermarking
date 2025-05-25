from stegano import lsb

# Hide a message
secret = lsb.hide("original.png", "This image was AI-generated")
secret.save("output_stego.png")

