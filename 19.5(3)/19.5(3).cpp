#include <iostream>
#include <fstream>

int main() {
    std::ifstream list;
    list.open("List.txt");

    std::string dates, name, surname;
    float payment, sum = 0, max = 0;

    if (!list.is_open()) std::cout << "yet" << std::endl;
    while (!(list.eof())) {
        list >> name >> surname >> payment >> dates;

        sum += payment;

        if (payment > max) max = payment;
    }
    list.close();

    std::cout << "Amount of payments: " << sum << std::endl;
    std::cout << "Maximum payout: " << max << std::endl;


    return 0;
}
