//
// Created by barak on 25/04/2022.
//

#include "Ambassador.hpp"
#include "Captain.hpp"

std::string Ambassador::role() const {
    return "Ambassador";
}
//void Ambassador::coup(const Player &target) {
//
//}

/** Special Skills */
/** Offensive*/
void Ambassador::transfer(Player &from, Player &to) {
    if (check_10_coins()) {
        throw std::invalid_argument("Must coup!\n");
    }
    if (!check_turn()) {
        throw std::invalid_argument("Not your turn\n");
    }
    if (from.get_status() == _dead || to.get_status() == _dead) {
        throw std::invalid_argument("One of the players is missing\n");
    }
    if (from.coins() == 0) {
        throw std::invalid_argument("cant transfer from this player\n");
    }
    int taken = from.set_coins(-1);
    to.set_coins(taken);
    this->action = _transfer;
    this->game->notify();
}
/** Defensive */
void Ambassador::block(Player &attacker) {
    if(attacker.get_action() != _steal || this->status == _dead) {
        throw std::invalid_argument("Ambassador Invalid Block\n");
    }
    dynamic_cast<Captain *>(&attacker)->blocked();
}
