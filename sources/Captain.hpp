//
// Created by barak on 25/04/2022.
//

#ifndef CPP__COUPGAME_A_CAPTAIN_HPP
#define CPP__COUPGAME_A_CAPTAIN_HPP


#include "Player.hpp"

class Captain: public Player {
public:
   Captain (coup::Game &game, const std::string &name): Player(game,name){}

    std::string role() const override;
//    void coup(const Player &target) override;

    /** Special Skills */
    void block(const Player &attacker);
    void steal(Player &victim);
};


#endif //CPP__COUPGAME_A_CAPTAIN_HPP
