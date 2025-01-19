//
// Created by bolo on 18.01.25.
//

#ifndef CALCULATOR_H
#define CALCULATOR_H

#pragma once
#include <string>

class Calculator {
public:
    explicit Calculator(std::string init);
    std::string init;
    std::string result;
    std::string base_system = "DEC";
private:
    void parser();
};



#endif //CALCULATOR_H
