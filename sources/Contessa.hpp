//
// Created by barak on 25/04/2022.
//

#ifndef CPP__COUPGAME_A_CONTESSA_HPP
#define CPP__COUPGAME_A_CONTESSA_HPP


#include "Player.hpp"

class Contessa: public Player {
//private:
//    int coin;
//    coup::Game *game;
public:
   Contessa (coup::Game &game, const std::string &name): Player(game,name){}

    std::string role() const override;
//    void coup(const Player &target) override;

    /** Special Skills */
    void block(Player &attacker);
};


#endif //CPP__COUPGAME_A_CONTESSA_HPP
