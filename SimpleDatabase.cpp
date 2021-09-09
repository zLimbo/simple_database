#include "SimpleDatabase.h"
#include <iostream>
namespace zlimbo {

int SimpleDatabase::loop() {
    while (true) {
        printPrompt();
        InputBuffer inputBuffer;
        inputBuffer.readInput();
        std::string cmd = inputBuffer.getCmd();
        if (cmd == ".exit") {
            return EXIT_SUCCESS;
        } else {
            std::cout << "Unrecognized command " << cmd << std::endl;
        }
    }
}

void SimpleDatabase::printPrompt() {
    std::cout << "sdb > ";
}


void InputBuffer::readInput() {
    std::getline(std::cin, cmd);
}

std::string InputBuffer::getCmd() {
    return cmd;
}

};  // namespace zlimbo