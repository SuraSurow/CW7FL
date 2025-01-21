//
// Created by bolo on 19.01.25.
//

#ifndef TESTTEMPLATE_H
#define TESTTEMPLATE_H
#include <vector>
#include <gtest/internal/gtest-filepath.h>


class TestLoader {
    void scanNameFiles();
    std::string searchPathByName(std::string& name);
public:
    std::vector<std::string>filesNamesVector;
    std::vector<std::string>filesPathsVector;

    TestLoader() {
        scanNameFiles();
    }

    ~TestLoader();



    std::vector<std::string> getNameFiles() ;
    std::vector<std::string> getPathFiles() ;
    std::string getPathByName(std::string name) ;
    void runSelectedGoogleTest(const std::string& pathToFile, const std::string& nameOfTest);
    void runAllGoogleTest(const std::string& pathToFile) ;


};



#endif //TESTTEMPLATE_H