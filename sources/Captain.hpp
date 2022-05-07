//
// Created by barak on 25/04/2022.
//

#ifndef CPP__COUPGAME_A_CAPTAIN_HPP
#define CPP__COUPGAME_A_CAPTAIN_HPP


#include "Player.hpp"

class Captain: public Player {
private:
    Player *c_victim;
public:
   Captain (coup::Game &game, const std::string &name): Player(game,name), c_victim(nullptr){}

    std::string role() const override;
//    void coup(const Player &target) override;

    /** Special Skills */
    void block(Player &attacker);
    void blocked();
    void steal(Player &victim);
};


#endif //CPP__COUPGAME_A_CAPTAIN_HPP
