#include <iostream>

#include "steganography.h"

int main(int argc, char* argv[])
{
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <source> <target>" << std::endl;
        return EXIT_FAILURE;
    }

    std::string intputBmp{argv[1]};
    std::string outputBmp{argv[2]};
    std::string message = "This is a hidden message!";

    if (!hideMessage(intputBmp, outputBmp, message)) {
        std::cerr << "Error hideing message!" << std::endl;
        return EXIT_FAILURE;
    }

    std::string recoveredMessage = revealMessage(outputBmp);
    std::cout << "Recovered message: " << recoveredMessage << std::endl;

    return EXIT_SUCCESS;
}