#include <memory>
#include <fstream>
#include <iostream>
#include "Game.h"
#include <string>
#include <cstdlib>
#include <ctype.h>

using namespace std;

void Game::generate_num(int &max)
{
    srand((unsigned)time(0));
    cout << "I'm thinking of a number between 1 and " << max << endl;
    correct_answer = rand() % max + 1;
}

string Game::input_guess()
{
    int guess;
    cout << "What's your guess? " << endl;
    if (!(cin >> guess))
    {
        cout << "Invaild input" << endl;
        cin.clear();  // make sure that std::cin is happy to do something
        cin.ignore(); // ignore the offending character
    }
    guess_list.push_back(guess);
    string str = check_answer(guess);
    return str;
}

int Game::generate_env()
{

    string difficulty;
    cout << "Select Difficulty: Easy, Medium, Hard: " << endl;

    if (!(cin >> difficulty))
    {
        cin.clear();  // make sure that std::cin is happy to do something
        cin.ignore(); // ignore the offending character
    }

    difficulty[0] = toupper(difficulty[0]);
    if (difficulty == "Easy")
    {
        cout << "Difficulty Selection: " << difficulty << endl;
        return 50;
    }
    else if (difficulty == "Medium")
    {
        cout << "Difficulty Selection: " << difficulty << endl;
        return 200;
    }
    else if (difficulty == "Hard")
    {
        cout << "Difficulty Selection: " << difficulty << endl;
        return 2000;
    }
    else
        cout << "No selection made" << endl;
    return -1;
}

std::vector<int> Game::get_guess()
{
    return guess_list;
}

int Game::get_answer()
{
    return correct_answer;
}

string Game::check_answer(int &guess)
{
    if (guess > correct_answer)
    {
        return ("The number is less then " + to_string(guess));
    }
    else if (guess < correct_answer)
    {
        return ("The number is greater then " + to_string(guess));
    }
    else
    {
        return "You got it right!";
    }
}
void Game::save_score(int &max)
{
    string name;
    cout << "Enter a name to save your score: " << endl;
    cin >> name;
    ofstream outfile;

    outfile.open("../scores.txt", std::ios_base::app); // append instead of overwrite
    outfile << name << ": " << guess_list.size() << " Range: 1 to " << max << endl;
}
void Game::print_score()
{
    string str;
    ifstream ifs{"../scores.txt"};
    while (getline(ifs, str))
    {
        cout << str << endl;
    }
}