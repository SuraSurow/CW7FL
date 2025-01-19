#include "Calculator.h"
#include <algorithm>
#include <list>
#include <stdexcept>
#include <unordered_set>

Calculator::Calculator(std::string init) : init(std::move(init)) {
    parser();
    calculate("");
}

void Calculator::parser() {
    std::list<std::string> num_sym;
    if (base_system == "HEX") {num_sym = hex_symb;}
    if (base_system == "DEC") {num_sym = dec_symb;}
    if (base_system == "OCT") {num_sym = oct_symb;}
    if (base_system == "BIN") {num_sym = bin_symb;}
    std::unordered_set<std::string> num_sys_set(num_sym.begin(), num_sym.end());
    std::unordered_set<std::string> oper_set(operation_symb.begin(), operation_symb.end());

    for (int i = 0; i < init.size(); i++) {
        std::string temp_number;
        std::string str_iter(1, init[i]);
        if (oper_set.contains(str_iter)) {
            this->tokenize.push_back(str_iter);
        }
        int j = i;
        while (num_sys_set.contains(str_iter) && j<init.size()) {
            str_iter = std::string(1, init[j]);
            temp_number += str_iter;
            j++;
            str_iter = std::string(1, init[j]);
        }
        if (!temp_number.empty()){
            this->tokenize.push_back(temp_number);
            i=j-1;
        }
        temp_number.clear();
    }

    for (auto it : this->tokenize) {
        if (oper_set.contains(it)) {
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
    std::string m_op;
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
    if (std::holds_alternative<std::string>(mixed_tokens.front())) {
        m_op = std::get<std::string>(mixed_tokens.front());
        mixed_tokens.pop_front();
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
    calculate(m_op);
    return_result();
}

void Calculator::return_result() {
    //todo check word size!
    this->result = std::to_string(result_int);
}