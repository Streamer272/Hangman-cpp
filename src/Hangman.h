#pragma once

#include <string>

class Hangman {
private:
    const std::string word = "wizard";
    mutable std::string guessed_word = "______";
    int guesses = 10;
    bool finished = false;
public:
    void main();
    bool includes(char character) const;
    int index(char ch) const;
    static void clear();
};
