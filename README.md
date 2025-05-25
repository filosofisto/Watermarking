# Watermarking

Sample of Stenograph using Python and C++.

## Python

The Python sample use the stegano library.
First install the library with the command:

    pip install stegano
    
Now execute the hide.py script to add a Watermark on the image (png format).
To retrieve the hidden message, execute the disclose.py.

# C++
In the C++ folder exists a sample using LBS steganography (least significant bit) but for BMP files.
This sample does not use any library but a pure C++ code.
For more complex sample it is posible to use the OpenCV library.