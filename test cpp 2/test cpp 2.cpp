#include <iostream>
#include <string> 
#include <regex>
#include <chrono>

bool is_integer(const std::string& s);

int main()
{
    srand(time(NULL));
    int correctGuess = 1 + ((rand() / 327.67)-1);
    std::cout << "Guess the number which ranges from 1-100\n";

    while (true) {
        std::string guessAsString;
        std::cout << "> ";
        std::cin >> guessAsString;

        if (!is_integer(guessAsString)) {
            std::cout << "Your guess is not a valid integer you fucking moron\n";
            continue;
        }

        int guess = std::stoi(guessAsString);

        if (guess < 1 || guess > 100) {
            std::cout << "Your guess is out of range??? Did you even try??\n";
            continue;
        }

        if (guess == correctGuess) {
            std::cout << "ZAMN! Your guess is correct!! wohoo!!\n";
            std::cout << "Guess the number which ranges from 1-100\n";
            correctGuess = 1 + ((rand() / 327.67) - 1);
        }
        else if (guess > correctGuess) {
            std::cout << "Its lower than that...\n";
        }
        else if (guess < correctGuess) {
            std::cout << "Its higher than that...\n";
        }
    }
}

bool is_integer(const std::string& s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}