#ifndef GAME
#define GAME
#include <vector>
#include <memory>

class Game
{
private:
    int correct_answer;
    std::vector<int> guess_list{};

public:
    Game() = default;
    ~Game() = default;
    void generate_num(int &max);
    std::string input_guess();
    int generate_env();
    std::vector<int> get_guess();
    int get_answer();
    std::string check_answer(int &guess);
    void save_score(int &max);
    void print_score();
};

#endif
