//
// Created by bolo on 19.01.25.
//

#ifndef TESTTEMPLATE_H
#define TESTTEMPLATE_H
#include <vector>
#include <gtest/internal/gtest-filepath.h>


class TestLoader {
public:
    std::vector<std::string>fileAbsolutePaths;
    TestLoader() = default;

    ~TestLoader();

    void scanNameFiles();

    std::vector<std::string> getNameFiles() ;



};



#endif //TESTTEMPLATE_H