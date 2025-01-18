//
// Created by bolo on 18.01.25.
//

#ifndef CALCULATOR_H
#define CALCULATOR_H

#pragma once
#include <list>
#include <string>
#include <unordered_set>
#include <variant>
#include <vector>

class Calculator {
public:
    explicit Calculator(std::string init);
    std::string init;
    std::list<std::string> tokenize;
    std::list<std::variant<int, std::string>> mixed_tokens;
    std::string result;
    int result_int = 0;

private:
    std::string base_system = "DEC";
    std::list<std::string> hex_symb = {"0", "1","2","3","4","5","6","7","8","9","A","B","C","D","E","F"};
    std::list<std::string> dec_symb = {"0","1","2","3","4","5","6","7","8","9"};
    std::list<std::string> oct_symb = {"0","1","2","3","4","5","6","7"};
    std::list<std::string> bin_symb = {"0","1"};
    std::list<std::string> operation_symb = {"+","-","*","/","="};
    void parser();
    void calculate(std::string math_operator);
    void return_result();
};



#endif //CALCULATOR_H
