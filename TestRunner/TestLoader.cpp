//
// Created by bolo on 19.01.25.
//

#include "TestLoader.h"
#include <iostream>
#include <filesystem>
#include <string>


#define PATH_TO_TESTS_DIRECTORY "/home/bolo/CLionProjects/CW7FL/Test/Cases"

std::string getClearNameFileName(const std::string& path) {
    size_t lastSlash = path.find_last_of("/\\");
    if (lastSlash == std::string::npos) {
        return path;
    }
    return path.substr(lastSlash + 1);
}


void TestLoader::scanNameFiles() {
    std::string directoryPath = PATH_TO_TESTS_DIRECTORY;
    size_t countFile = 0;
    try {
        for (const auto& file : std::filesystem::directory_iterator(directoryPath)) {
            if (file.is_regular_file()) {
                const auto& filePath = file.path();
                const auto& fileName = filePath.filename().string();
                if (fileName.rfind("test_", 0) == 0 && filePath.extension() == ".h") {
                    fileAbsolutePaths.push_back(getClearNameFileName(filePath.string()));
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
        return fileAbsolutePaths;
    }

