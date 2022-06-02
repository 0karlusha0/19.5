#include <iostream>
#include <fstream>
#include <string>

enum {
    SECTOR1 = 1 << 0,
    SECTOR2 = 1 << 1,
    SECTOR3 = 1 << 2,
    SECTOR4 = 1 << 3,
    SECTOR5 = 1 << 4,
    SECTOR6 = 1 << 5,
    SECTOR7 = 1 << 6,
    SECTOR8 = 1 << 7,
    SECTOR9 = 1 << 8,
    SECTOR10 = 1 << 9,
    SECTOR11 = 1 << 10,
    SECTOR12 = 1 << 11,
    SECTOR13 = 1 << 12
};

void read_to_write(std::ifstream& file, char* buffer) {
    while (!file.eof()) {
        file.read(buffer, sizeof(buffer) - 1);
        buffer[sizeof(buffer) - 1] = 0;
        if (file.gcount() < sizeof(buffer)) {
            buffer[file.gcount()] = 0;
        }
        std::cout << buffer;
    }
    file.close();

}
int main() {

    int viewers = 0, player = 0, state = 0;
    std::string question_path, answer_path, player_answer, sec;
    char buffer[100];
    int sector = 1;
    std::ifstream question, answer;


    while (player < 6 && viewers < 6) {

        std::cout << "Current sector: " << sector << std::endl;
        std::cout << "Enter the offset: " << std::endl;
        int offset;
        std::cin >> offset;

        if (sector + offset < 1) sector += 13;
        if (sector + offset > 13) sector -= (13 * ((sector + offset) / 13));
        sector += offset;



        while (!question.is_open()) {
            sec = std::to_string(sector);
            if (!(state & 1 << (sector - 1))) {
                state |= 1 << (sector - 1);
                question_path = "questions\\" + sec + ".txt";
                answer_path = "answers\\" + sec + ".txt";
                std::cout << "Sector " << sector << " is selected." << std::endl;
                question.open(question_path);
            }
            else if (sector < 12) sector++;
            else sector = 1;
        }

        read_to_write(question, buffer);

        std::cout << "\nEnter the answer: " << std::endl;
        std::cin >> player_answer;

        answer.open(answer_path);
        answer >> buffer;
        answer.close();

        if (buffer == player_answer) {
            std::cout << "The answer is correct!" << std::endl;
            player++;
        }
        else {
            std::cout << "The answer is incorrect!" << std::endl;
            viewers++;
        }


        if (player > viewers)
            std::cout << "The current score is " << player << ":" << viewers << " in favor of the player."
            << std::endl;
        else if (viewers > player)
            std::cout << "The current score is " << viewers << ":" << player << " in favor of the viewers."
            << std::endl;
        else
            std::cout << "The current score is equal. " << player << ":" << viewers << std::endl;
    }



    if (player > viewers)
        std::cout << "Player win!" << std::endl;
    else
        std::cout << "Viewers won!" << std::endl;
    return 0;
}
