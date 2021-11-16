#include "SimpleDatabase.h"

#include <iostream>

namespace zlimbo {

int SimpleDatabase::loop() {
    while (true) {
        print_prompt();
        CommandBuffer cmdBuf;
        cmdBuf.read(std::cin);
        std::string cmd = cmdBuf.get_cmd();
        if (cmd[0] == '.') {
            switch (do_meta_command(cmd)) {
                case META_COMMAND_SUCCESS:
                    continue;
                case META_COMMAND_UNRECOGNIZED_COMMAND:
                    std::cout << "Unrecognized command '" << cmd << "'"
                              << std::endl;
                    continue;
            }
        }

        Statement statement;
        switch (statement.prepare(cmd)) {
            case PREPARE_SUCCESS:
                break;
            case PREPARE_UNRECOGNIZED_STATEMENT:
                std::cout << "Unrecognized keyword at start of '" << cmd << "'"
                          << std::endl;
                continue;
        }
        statement.execute();
        std::cout << "Executed." << std::endl;
    }
}

void SimpleDatabase::print_prompt() const { std::cout << "sdb > "; }

MetaCommandResult SimpleDatabase::do_meta_command(
    const std::string& cmd) const {
    if (cmd == ".exit") {
        exit(EXIT_SUCCESS);
    } else {
        return META_COMMAND_UNRECOGNIZED_COMMAND;
    }
}

void CommandBuffer::read(std::istream& in) { std::getline(in, cmd); }

std::string CommandBuffer::get_cmd() { return cmd; }

PrepareResult Statement::prepare(const std::string& cmd) {
    if (cmd.substr(0, 6) == "insert") {
        type = STATEMENT_INSERT;
        return PREPARE_SUCCESS;
    }
    if (cmd == "select") {
        type = STATEMENT_SELECT;
        return PREPARE_SUCCESS;
    }

    return PREPARE_UNRECOGNIZED_STATEMENT;
}

void Statement::execute() {
    switch (type) {
        case STATEMENT_INSERT:
            std::cout << "This is where we would do an insert." << std::endl;
            break;
        case STATEMENT_SELECT:
            std::cout << "This is where we would do a select." << std::endl;
            break;
    }
}

};  // namespace zlimbo