//
// Created by barak on 25/04/2022.
//

#ifndef CPP__COUPGAME_A_PLAYER_HPP
#define CPP__COUPGAME_A_PLAYER_HPP
#include <iostream>
#include "Game.hpp"
using namespace coup;
//#include "Game.hpp"
enum status {dead, alive};
enum action {_income, _foreign_aid, _coup, _transfer, _steal, _tax};
class Player {
protected:
    int coin;
    Game game;
    std::string name;
    int action = -1;
    int status = alive;
public:
    Player(Game &game, const std::string &name);
    int coins() const;
    void income();
    void foreign_aid();
    std::string get_name() const;
    void coup(const Player &target);
    virtual std::string role() const = 0;
};


#endif //CPP__COUPGAME_A_PLAYER_HPP
