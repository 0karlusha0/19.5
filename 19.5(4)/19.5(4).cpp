#include <iostream>
#include <fstream>
#include <string>
int main() {
    std::cout << "Enter the path to the file: " << std::endl;
    std::string path;
    std::cin >> path;

    std::ifstream file;
    file.open(path, std::ios::binary);
    char png[4];

    if (file.is_open()) {
        if (path.substr(path.length() - 4) == ".png") {
            file.read(png, sizeof(png));
            if (png[0] == -119 && png[1] == 'P' && png[2] == 'N' && png[3] == 'G') {
                std::cout << "Yet" << std::endl;
            }
            else std::cout << "Nope" << std::endl;
        }
        else std::cout << "Nope" << std::endl;
        file.close();
    }
    else
        std::cout << "Incorrect data has been entered." << std::endl;


    return 0;
}
