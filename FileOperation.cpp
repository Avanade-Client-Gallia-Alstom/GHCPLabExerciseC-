#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::string filePath = "C:/Users/g.b.das/Documents/HelloWorld.txt";
    std::ifstream inputFile(filePath);

    if (inputFile.is_open()) {
        std::string line;
        while (std::getline(inputFile, line)) {
            std::cout << line << std::endl;
        }
        inputFile.close();
    } else {
        std::cout << "Failed to open file: " << filePath << std::endl;
    }

    return 0;
}
