//
// Created by barak on 25/04/2022.
//

#ifndef CPP__COUPGAME_A_AMBASSADOR_HPP
#define CPP__COUPGAME_A_AMBASSADOR_HPP


#include "Player.hpp"

class Ambassador: public Player {
public:
    Ambassador(coup::Game &game, const std::string &name): Player(game,name){}
    std::string role() const override;
//    void coup(const Player &target) override;

    /** Special Skills */
    /** Offensive*/
    void transfer(Player &from, Player &to);

    /** Defensive */
    void block(const Player &attacker);
};


#endif //CPP__COUPGAME_A_AMBASSADOR_HPP
