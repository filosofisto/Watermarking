//
// Created by filos on 25/05/2025.
//

#include <fstream>
#include <vector>
#include <iostream>

#include "steganography.h"

#include <cstdint>

bool hideMessage(const std::string& inputBmp, const std::string& outputBmp, const std::string& message)
{
    std::ifstream input(inputBmp, std::ios::binary);
    std::ofstream output(outputBmp, std::ios::binary);

    if (!input || !output) return false;

    std::vector<char> buffer((std::istreambuf_iterator<char>(input)), {});
    if (buffer.size() < 54) return false; // BMP header size

    size_t dataOffset = *reinterpret_cast<uint32_t*>(&buffer[10]);
    size_t capacity = ((buffer.size() - 54) - dataOffset) / 8;
    if (message.size() + 1 > capacity) return false;

    // Copy original image
    output.write(buffer.data(), buffer.size());

    input.close();
    output.close();

    std::fstream stego(outputBmp, std::ios::in | std::ios::out | std::ios::binary);
    if (!stego) return false;
    stego.seekp(dataOffset);

    std::string msg = message + '\0';
    for (char ch : msg) {
        for (int i = 0; i < 8; ++i) {
            char bit = (ch >> i) & 1;
            char pixelByte;
            stego.read(&pixelByte, 1);
            pixelByte = (pixelByte & ~1) | bit;
            stego.seekp(-1, std::ios::cur);
            stego.write(&pixelByte, 1);
        }
    }

    stego.close();
    return true;
}

std::string revealMessage(const std::string& stegoBmp)
{
    std::ifstream input(stegoBmp, std::ios::binary);
    if (!input) return "";

    std::vector<char> buffer((std::istreambuf_iterator<char>(input)), {});
    size_t dataOffset = *reinterpret_cast<uint32_t*>(&buffer[10]);

    std::string result;
    char ch = 0;
    int bitCount = 0;

    for (size_t i = dataOffset; i < buffer.size(); ++i) {
        ch |= (buffer[i] & 1) << bitCount;
        ++bitCount;
        if (bitCount == 8) {
            if (ch == '\0') break;
            result += ch;
            ch = 0;
            bitCount = 0;
        }
    }

    return result;
}
