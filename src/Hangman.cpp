#pragma once

#include <iostream>
#include <unistd.h>
#include "Hangman.h"


char stoch(std::string str) {
    char* char_arr;
    std::string str_obj(std::move(str));
    char_arr = &str_obj[0];
    return *char_arr;
}

void Hangman::main() {
    std::cout << "Hello! You have now entered Hangman! You can guess wrong only " << guesses;
    std::cout << " times... Let's start!" << std::endl;
    sleep(1);
    clear();

    while (!finished) {
        clear();
        if (word == guessed_word) {
            std::cout << "You won!" << std::endl;
            break;
        }

        std::cout << "Health: " << guesses << std::endl;
        std::cout << "Word: " << guessed_word << std::endl;
        std::cout << "Your guess: ";

        std::string guess;
        std::cin >> guess;

        if (guess.length() > 1) {
            std::cout << "Your guess can be only 1 character long!" << std::endl;
            continue;
        }

        if (includes(stoch(guess))) {
            std::cout << "Correct!" << std::endl;
            guessed_word.replace(index(stoch(guess)), 1, guess);
        }
        else {
            std::cout << "Wrong!" << std::endl;
            guesses--;
        }
    }
}

void Hangman::clear() {
    system("cls");
}

bool Hangman::includes(char character) const {
    for (char character_ : word) {
        if (character == character_) {
            return true;
        }
    }

    return false;
}

int Hangman::index(char ch) const {
    for (int i = 0; i < word.length(); i++) {
        if (word[i] == ch) {
            return i;
        }
    }

    return -1;
}
