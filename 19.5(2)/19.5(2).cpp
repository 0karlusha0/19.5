#include <iostream>
#include <fstream>
#include <string>

int main() {
    while (true) {
        std::cout << "Enter the path to the file: " << std::endl;
        std::string path;
        std::getline(std::cin, path);

        std::ifstream test;
        char buffer[50];
        test.open(path, std::ios::binary);


        if (test.is_open()) {
            while (!test.eof()) {
                test.read(buffer, sizeof(buffer) - 1);
                buffer[sizeof(buffer) - 1] = 0;
                if (test.gcount() < sizeof(buffer)) {
                    buffer[test.gcount()] = 0;
                }
                std::cout << buffer;

            }
            test.close();
            break;
        }
        else {
            std::cout << "Incorrect data has been entered. Try again." << std::endl;
        }

    }

    return 0;
}