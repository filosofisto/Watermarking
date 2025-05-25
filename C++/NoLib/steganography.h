//
// Created by filos on 25/05/2025.
//

#ifndef STEGANOGRAPHY_H
#define STEGANOGRAPHY_H

#include <string>

bool hideMessage(const std::string& inputBmp, const std::string& outputBmp, const std::string& message);
std::string revealMessage(const std::string& stegoBmp);

#endif //STEGANOGRAPHY_H
