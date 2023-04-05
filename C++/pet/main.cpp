#include <iostream>
#include <fstream>
#include <string>
#include "Game.h"
#include <cstdlib>
#include <ctype.h>

using namespace std;

int main()
{
    Game game;
    int max = 0;

    while (true)
    {
        cout << "What's range would you like? Enter -1 for difficulty section, -2 to view scores: " << endl;

        if (!(cin >> max))
        {
            cin.clear();  // make sure that std::cin is happy to do something
            cin.ignore(); // ignore the offending character
        }

        int value(0);
        while (max == -1)
        {
            max = game.generate_env();
        }
        if (max == -2)
        {
            game.print_score();
        }
        else if ((max == 1) || (max == 0))
        {
            cout << "Invaild input" << endl;
        }
        else
            break;
    }

    game.generate_num(max);

    while (true)
    {
        string str = game.input_guess();
        if (str == "You got it right!")
        {
            cout << str << endl;
            break;
        }
        else
            cout << str << endl;
    }

    cout << "I was thinking of " << game.get_answer() << endl;
    cout << "Attempts: " << (game.get_guess()).size() << endl;
    cout << "Guesses:  " << endl;
    int i = 1;
    for (auto g : game.get_guess())
    {

        cout << i << ". " << g << endl;
        i++;
    }
    char c;
    cout << "Save score? Y/N:" << endl;
    cin >> c;

    if (toupper(c) == 'Y')
    {
        game.save_score(max);
    }
}