//
// Created by bolo on 18.01.25.
//
#include "Calculator.h"
#include "Addition.h"





 additionMinusNumberToMinusNumber(){
    Calculator test = Calculator("23+-5");
    if (test.result == "18")
      return testing::AssertionSuccess();
    else
        return testing::AssertionFailure();
}
