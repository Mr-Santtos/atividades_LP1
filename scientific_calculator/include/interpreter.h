#ifndef INTERPRETER_H
#define INTERPRETER_H

#include <string>

namespace system {
class Interpreter {
public:
    Interpreter() = default;
    // parse textual commands and return normalized action string
    std::string parse(const std::string& input);
};
} // namespace system

#endif // INTERPRETER_H
