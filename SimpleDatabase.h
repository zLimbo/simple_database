#pragma once
#include <string>

namespace zlimbo {

class SimpleDatabase {

public:
    int loop();
    void printPrompt();

private:


};


class InputBuffer {
public:
    void readInput();
    std::string getCmd();

private:
    std::string cmd;
};


}; // namespace zlimbo