/**
* listhelpers.hpp has been provided by the instructor as starter code
* contains the following procedures to work with lists:
* display, append, insert, remove, length
*/
#include "listhelpers.hpp"

#include <cstdlib>   // srand, rand
#include <ctime>     // time
#include <iostream>  // std::cin, std::cout
#include <string>    // std::string, std::getline
#include <vector>    // std::vector

std::vector<int> createSecret() {
    std::vector <int> code = {};
    int counter = 0;
    while (counter <  4) //4 times
    {
        int val = rand() % 10;
        code.push_back(val);
        counter = counter + 1;
    }
    return {code};    
}

std::vector<std::string> getHint(std::vector<int> secret, std::vector<int> guess) {
    std::vector <std::string> hint = {};
    int index = 0;

    while(index < secret.size())
    {
        if(secret[index] == guess[index])
        {
            hint.push_back("0");
        }
        else
        {
            hint.push_back("X");
        }
        index = index + 1;
    }
    return {hint};   
}

bool winGame(std::vector<int> secret, std::vector<int> guess) {
    {
    return secret == guess; 
    }
}

int main()
{
    srand(time(0));    // seeds random number generator
    int random_num = rand() % 10;    // random number between 0 and 9
    
    std::vector<int> secret_code = createSecret();
    std::vector<int> user_guess = {};
    std::vector<std::string> hint = {};    // an empty list

    int secret_code_length = 4;
    int num_guesses = 0;

    std::cout << "Welcome to Number Wordle!\n";
    
    while (!winGame(secret_code, user_guess))    // while you have not won the game yet
    {
        std::cout << "\nEnter your guess: ";
        
        user_guess = {}; //reset guess for next guess
        for (int counter = 0; counter < secret_code_length; counter = counter + 1)
        {
            int input;
            std::cin >> input;
            user_guess.push_back(input);    
        }

        hint = getHint(secret_code, user_guess);
        display(hint);
        num_guesses = num_guesses + 1;
    }

    std::cout << "Congrats!  You guessed the code!  It took you " << num_guesses << " tries.\n";
    return 0;
}
