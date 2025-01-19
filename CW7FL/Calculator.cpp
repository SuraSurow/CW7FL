#include "Calculator.h"

#include <algorithm>
#include <list>
#include <stdexcept>
#include <unordered_set>

Calculator::Calculator(std::string init) : init(std::move(init)) {

}

void Calculator::parser() {
    std::list<std::string> num_sym;
    if (base_system == "HEX") {num_sym = hex_symb;}
    if (base_system == "DEC") {num_sym = dec_symb;}
    if (base_system == "OCT") {num_sym = oct_symb;}
    if (base_system == "BIN") {num_sym = bin_symb;}
    std::unordered_set<std::string> num_sys_set(num_sym.begin(), num_sym.end());
    std::unordered_set<std::string> oper_set(operation_symb.begin(), operation_symb.end());
    for (char c : this->init) {
        std::string temp_number;
        if (num_sys_set.contains(&c)) {
            temp_number += c;
            continue;
        }
        if (oper_set.contains(&c)) {
            this->tokenize.push_back(temp_number);
            temp_number = "";
            temp_number += c;
            this->tokenize.push_back(temp_number);
            temp_number = "";
            continue;
        }
    }
    for (auto it : this->tokenize) {
        if (num_sys_set.contains(it)) {
            mixed_tokens.emplace_back(it);
        }else {
            if (base_system == "HEX") {mixed_tokens.emplace_back(std::stoi(it, nullptr, 16));}
            if (base_system == "DEC") {mixed_tokens.emplace_back(std::stoi(it, nullptr, 10));}
            if (base_system == "OCT") {mixed_tokens.emplace_back(std::stoi(it, nullptr, 8));}
            if (base_system == "BIN") {mixed_tokens.emplace_back(std::stoi(it, nullptr, 2));}
        }
    }

}

void Calculator::calculate(std::string math_operator) {
    // Pusta lista , lub tylko operator
    if (mixed_tokens.empty() ||
       (mixed_tokens.size() == 1 && std::holds_alternative<std::string>(mixed_tokens.front()))) {
        return_result();
        return;
       }

    // Pojedyńcza liczna
    if (mixed_tokens.size() == 1 && std::holds_alternative<int>(mixed_tokens.front())) {
        result_int = std::get<int>(mixed_tokens.front());
        return_result();
        return;
    }

    // stos działań
    while (!mixed_tokens.empty() && std::holds_alternative<int>(mixed_tokens.front())) {
        int current = std::get<int>(mixed_tokens.front());
        mixed_tokens.pop_front();

        if (math_operator.empty() || math_operator == "+") {
            result_int += current;
        } else if (math_operator == "-") {
            result_int -= current;
        } else if (math_operator == "*") {
            result_int *= current;
        } else if (math_operator == "/") {
            if (current == 0) {
                throw std::runtime_error("Division by zero");
            }
            result_int /= current;
        }
    }

    return_result();
}

void Calculator::return_result() {
    //todo check word size!
    this->result = std::to_string(result_int);
}