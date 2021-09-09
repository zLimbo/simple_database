#pragma once
#include <string>

namespace zlimbo {

enum MetaCommandResult {
    META_COMMAND_SUCCESS,
    META_COMMAND_UNRECOGNIZED_COMMAND,
};

enum PrepareResult {
    PREPARE_SUCCESS,
    PREPARE_UNRECOGNIZED_STATEMENT,
};

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