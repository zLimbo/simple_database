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

enum StatementType {
  STATEMENT_INSERT,
  STATEMENT_SELECT,
};

class Statement {
 public:
  PrepareResult prepare(const std::string& cmd);
  void execute();

  StatementType type;
};

class SimpleDatabase {
 public:
  int loop();
  void print_prompt() const;
  MetaCommandResult do_meta_command(const std::string& cmdBuf) const;

 private:
};

class CommandBuffer {
 public:
  void read(std::istream& in);
  std::string get_cmd();

 private:
  std::string cmd;
};

};  // namespace zlimbo