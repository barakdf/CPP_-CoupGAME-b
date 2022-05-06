//
// Created by barak on 25/04/2022.
//

#ifndef CPP__COUPGAME_A_ASSASSIN_HPP
#define CPP__COUPGAME_A_ASSASSIN_HPP

#include "Player.hpp"

class Assassin: public Player {
public:
   Assassin (coup::Game &game, const std::string &name): Player(game,name){}

    std::string role() const override;
//    void coup(const Player &target) override;

    /** Special Skills */

};
#endif //CPP__COUPGAME_A_ASSASSIN_HPP
