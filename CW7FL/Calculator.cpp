//
// Created by bolo on 18.01.25.
//

#include "Calculator.h"

#include <list>

Calculator::Calculator(std::string init) : init(std::move(init)) {

}
/*
void Calculator::parser() {
    std::list<std::string> hex_symb = {"0", "1","2","3","4","5","6","7","8","9","A","B","C","D","E","F"};
    std::list<std::string> dec_symb = {"0","1","2","3","4","5","6","7","8","9"};
    std::list<std::string> oct_symb = {"0","1","2","3","4","5","6","7"};
    std::list<std::string> bin_symb = {"0","1"};
    for (char c : this->init) {
        std::string number;
        if (std::find(dec_symb.begin(), dec_symb.end(), c) != dec_symb.end()) {
        
        }
    }
}
*/
