//
// Created by bolo on 19.01.25.
//

#include "TestLoader.h"
#include <iostream>
#include <filesystem>
#include <string>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <regex>

#define PATH_TO_TESTS_DIRECTORY "/home/bolo/CLionProjects/CW7FL/Test/Cases"

std::string getClearNameFileName(const std::string& path) {
    size_t lastSlash = path.find_last_of("/\\");
    if (lastSlash == std::string::npos) {
        return path;
    }
    std::string name  = path.substr(lastSlash + 1);
    name = name.substr(5, name.size() - 5);//usunieecie prefixa test_
    name = name.substr(0, name.size() - 2);//a tutaj .h
   return  name;// zwraca sama nazwe klasy czytaj tez i pliku


}


void TestLoader::scanNameFiles() {
    std::string directoryPath = PATH_TO_TESTS_DIRECTORY;
    size_t countFile = 0;
    try {
        for (const auto& file : std::filesystem::directory_iterator(directoryPath)) {
            if (file.is_regular_file()) {
                const auto& filePath = file.path();
                filesPathsVector.push_back(filePath);
                const auto& fileName = filePath.filename().string();
                if (fileName.rfind("test_", 0) == 0 && filePath.extension() == ".h") {
                    filesNamesVector.push_back(getClearNameFileName(filePath.string()));
                    countFile++;
                }
            }
        }
        std::cout << "Total number of test files: " << countFile << std::endl;
    } catch (const std::filesystem::filesystem_error& e) {
        std::cerr << "Error accessing directory: " << e.what() << std::endl;
    }
}

std::vector<std::string> TestLoader::getNameFiles()
    {
        return filesNamesVector;
    }

std::vector<std::string> TestLoader::getPathFiles()
{
    return filesPathsVector;
}

std::string TestLoader::searchPathByName(std::string& name) {
    std::string targetName = "test_" + name + ".h";
    for (const auto path : filesPathsVector) {
        size_t lastSlash = path.find_last_of("/\\");
        if (lastSlash == std::string::npos) {
            return path;
        }
        if (targetName == path.substr(lastSlash + 1)) {
            return path;
        }
    }
    return "";
}
std::string TestLoader::getPathByName(std::string Name) {
    for ( const auto& name : filesNamesVector) {
        std::string path = searchPathByName(Name);
        std::cout << path << std::endl;
        if ( path != "" ) {
            return path;
        }
    }
    return "";
}



void TestLoader::runAllGoogleTest(const std::string& pathToFile) {
    std::string compileCommand = "g++ -o temp_test_runner " + pathToFile +
                                  " -lgtest -lgtest_main -pthread";
    if (std::system(compileCommand.c_str()) != 0) {
        std::cerr << "Error: Compilation failed for " << pathToFile << std::endl;
        return;
    }
    std::string runCommand = "./temp_test_runner";
    if (std::system(runCommand.c_str()) != 0) {
        std::cerr << "Error: Test execution failed for " << pathToFile << std::endl;
    }
    std::system("rm -f temp_test_runner");
}

void TestLoader::runSelectedGoogleTest(const std::string& pathToFile, const std::string& nameOfTest) {

    std::string compileCommand = "g++ -o temp_test_runner " + pathToFile +
                                  " -lgtest -lgtest_main -pthread";
    if (std::system(compileCommand.c_str()) != 0) {
        std::cerr << "Error: Compilation failed for " << pathToFile << std::endl;
        return;
    }
    std::string runCommand = "./temp_test_runner --gtest_filter=" + nameOfTest + ".*";
    if (std::system(runCommand.c_str()) != 0) {
        std::cerr << "Error: Test execution failed for " << nameOfTest << " in " << pathToFile << std::endl;
    }
    std::system("rm -f temp_test_runner");
}


std::vector<std::vector<std::string>> parseTestFile(const std::string& filePath) {
    std::vector<std::string> testCategories;
    std::vector<std::vector<std::string>> testNamesByCategory;

    std::ifstream file(filePath);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file: " << filePath << std::endl;
        return {};
    }

    std::string line;
    std::regex defineRegex(R"(#define\s+(\w+))");            //  #define <Nazwa>
    std::regex testRegex(R"(\b(\w+)\((\w+),)");              // NazwaTestu(NazwaKategorii, NazwaTestu)

    while (std::getline(file, line)) {
        std::smatch match;

        // Szukamy #define
        if (std::regex_search(line, match, defineRegex)) {
            std::string category = match[1].str();
            if (category.find("TEST") != std::string::npos) {
                testCategories.push_back(category);
                testNamesByCategory.emplace_back();
            }
        }

        // Szukamy nazw testów dla bieżącej kategorii
        if (!testCategories.empty()) {
            if (std::regex_search(line, match, testRegex)) {
                std::string testCategory = match[1].str();
                std::string testName = match[2].str();//todo chyba blad niewiem czy nie odwrotnie , sprawdzic

                auto it = std::find(testCategories.begin(), testCategories.end(), testCategory);
                if (it != testCategories.end()) {
                    size_t index = std::distance(testCategories.begin(), it);
                    testNamesByCategory[index].push_back(testName);
                }
            }
        }
    }

    file.close();
    return testNamesByCategory;
}



