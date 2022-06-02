#include <iostream>
#include <fstream>

int main() {
    std::ifstream words;
    words.open("words.txt");
    std::cout << "Enter the word: " << std::endl;
    std::string word;
    std::cin >> word;

    std::string cur;
    int co = 0;
    while (!words.eof()) {
        words >> cur;
        if (cur == word) {
            co++;
        }
    }
    words.close();

    std::cout << co << std::endl;
    return 0;
}
