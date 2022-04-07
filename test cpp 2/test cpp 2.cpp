#include <iostream>
#include <string> 
#include <regex>
#include <chrono>

bool is_integer(const std::string& s);

int main()
{
    int maxNum = 100;

    bool whileFlag = true;

    while (whileFlag) {
        std::cout << "Please select a difficulty level! (enter the number)\n";
        std::cout << " 0. Way too easy\n";
        std::cout << " 1. Easy\n";
        std::cout << " 2. Medium\n";
        std::cout << " 3. Hard\n";
        std::cout << " 4. Very Hard\n";
        std::cout << " 5. Impossible\n";

        whileFlag = false;

        std::string selectedLevel;
        std::cout << "> ";
        std::cin >> selectedLevel;

        if (selectedLevel == "0") {
            maxNum = 10;
        }
        else if (selectedLevel == "1") {
            maxNum = 50;
        }
        else if (selectedLevel == "2") {
            maxNum = 100;
        }
        else if (selectedLevel == "3") {
            maxNum = 250;
        }
        else if (selectedLevel == "4") {
            maxNum = 1000;
        }
        else if (selectedLevel == "5") {
            maxNum = 10000;
        }
        else {
            whileFlag = true;
            std::cout << "Invalid difficulty!\n";
        }
    }
    srand(time(NULL));

    while(true) {
        int correctGuess = 1 + ((rand() / (32767 / maxNum)) - 1);
        int attempts = 0;
        std::cout << "Guess the number which ranges from 1-" << maxNum << "!\n";

        while (true) {
            std::string guessAsString;
            std::cout << "> ";
            std::cin >> guessAsString;

            if (!is_integer(guessAsString) || guessAsString.length() > 6) {
                std::cout << "Your guess is not a valid numer (only accepts 1-6 chars)\n";
                continue;
            }

            int guess = std::stoi(guessAsString);

            if (guess < 1 || guess > maxNum) {
                std::cout << "Your guess is out of range??? Did you even try??\n";
                continue;
            }

            attempts++;

            if (guess == correctGuess) {
                std::cout << "ZAMN! Your guess is correct!! It only took you " << attempts << " attempts!\n";
                break;
            }
            else if (guess > correctGuess) {
                std::cout << "Its lower than that...\n";
            }
            else if (guess < correctGuess) {
                std::cout << "Its higher than that...\n";
            }
        }
    }
}

bool is_integer(const std::string& s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}