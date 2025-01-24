#include "Calculator.h"
#include <algorithm>
#include <format>
#include <list>
#include <stdexcept>
#include <unordered_set>

Calculator::Calculator(std::string init) : init(std::move(init)) {
    parser();
    calculate();
}

void Calculator::return_in_base() {
    if (base_system == "HEX") {
        this->result = std::format("{:x}", this->result_int);
    } else if (base_system == "DEC") {
        this->result = std::to_string(this->result_int);
    } else if (base_system == "OCT") {
        this->result = std::format("{:o}", this->result_int);
    } else if (base_system == "BIN") {
        this->result = std::format("{:b}", this->result_int);
    }
}

void Calculator::parser() {
    std::list<std::string> num_sym;
    if (base_system == "HEX") {num_sym = hex_symb;}
    else if (base_system == "DEC") {num_sym = dec_symb;}
    else if (base_system == "OCT") {num_sym = oct_symb;}
    else if (base_system == "BIN") {num_sym = bin_symb;}
    std::unordered_set<std::string> num_sys_set(num_sym.begin(), num_sym.end());
    std::unordered_set<std::string> oper_set(operation_symb.begin(), operation_symb.end());

    for (int i = 0; i < init.size(); i++) {
        std::string temp_number;
        std::string str_iter(1, init[i]);
        bool is_negative = false;

        if (str_iter == "-" && i < init.size()-1) {
            std::string next_char(1, init[i+1]);
            if (num_sys_set.contains(next_char)) {
                is_negative = true;
                i++;
                str_iter = next_char;
            }
        }

        if (oper_set.contains(str_iter) && !is_negative) {
            this->tokenize.push_back(str_iter);
        }

        int j = i;
        while (num_sys_set.contains(str_iter) && j<init.size()) {
            str_iter = std::string(1, init[j]);
            temp_number += str_iter;
            j++;
            str_iter = std::string(1, init[j]);
        }

        if (!temp_number.empty()) {
            if (is_negative) temp_number = "-" + temp_number;
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

void Calculator::calculate() {
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

        if (m_op.empty() || m_op == "+") {
            result_int += current;
        } else if (m_op == "-") {
            result_int -= current;
        } else if (m_op == "*") {
            result_int *= current;
        } else if (m_op == "/") {
            if (current == 0) {
                throw std::runtime_error("Division by zero");
            }
            result_int /= current;
        } else if (m_op == "&") { //AND
            result_int &= current;
        }else if (m_op == "|") { //OR
            result_int |= current;
        }else if (m_op == "^") { //XOR
            result_int ^= current;
        }else if (m_op == "!") { //NOT
            result_int = !current;
        }else if (m_op == "%") { //MODULO
            result_int %= current;
        }
        m_op = "";
    }
    calculate();
    return_result();
}

void Calculator::return_in_word_size() {
    /*
        int64_t - QWORD: -9223372036854775808 do 9223372036854775807
        int32_t - DWORD: -2147483648 do 2147483647
        int16_t - WORD: -32768 do 32767
        int8_t - Bajt: -128 do 127
     */
    if (word_length == "QWORD") {
        const int64_t res = result_int;
        this->result = std::to_string(res);
    } else if (word_length == "DWORD") {
        const int32_t res = result_int;
        this->result = std::to_string(res);
    } else if (word_length == "WORD") {
        const int16_t res = result_int;
        this->result = std::to_string(res);
    } else if (word_length == "BYTE") {
        const int8_t res = result_int;
        this->result = std::to_string(res);
    } else {
        throw std::runtime_error("Invalid word length");
    }
}

void Calculator::return_result() {
    this->result = std::to_string(result_int);
}

void Calculator::rotate_left() {
    this->result_int = (this->result_int << 1) | (this->result_int >> (sizeof(this->result_int) * 8 - 1));
}

void Calculator::rotate_right() {
    this->result_int = (this->result_int >> 1) | (this->result_int << (sizeof(this->result_int) * 8 - 1));
}

void Calculator::shift_left() {
    this->result_int = this->result_int << 1;
}

void Calculator::shift_right() {
   this->result_int = this->result_int >> 1;
}
