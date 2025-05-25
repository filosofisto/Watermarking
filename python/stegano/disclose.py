# Reveal the hidden message
from stegano import lsb
message = lsb.reveal("output_stego.png")
print("Hidden message:", message)