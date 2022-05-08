//
// Created by barak on 25/04/2022.
//

#ifndef CPP__COUPGAME_A_PLAYER_HPP
#define CPP__COUPGAME_A_PLAYER_HPP
#include <iostream>
#include "Game.hpp"
using namespace coup;
//#include "Game.hpp"

class Player {
protected:
    enum status {_dead, _alive};
    enum action {_income, _foreign_aid, _coup, _transfer, _steal, _tax, _assassinate};
    int coin;
    Game *game;
    std::string name;
    int action = -1;
    int status = _alive;
    size_t p_index;
    bool check_10_coins() const;
    Player *last_couped;
public:
    Player(Game &game, const std::string &name);
    int coins() const;
    void income();
    void foreign_aid();
    std::string get_name() const;
    void coup(Player &target);

    /** Getters */
    int get_status() const;
    int& get_status();
    int get_action() const;
    int& get_action();
    int set_coins(int amount);
    size_t get_position() const;
    Player& get_last_couped();

    bool check_turn();
    virtual std::string role() const = 0;
    void foreign_blocked();

};


#endif //CPP__COUPGAME_A_PLAYER_HPP
