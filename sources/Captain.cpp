//
// Created by barak on 25/04/2022.
//

#include "Captain.hpp"

std::string Captain::role() const {
    return "Captain";
}

/** Special Skills */
void Captain::block(Player &attacker) {
    if(attacker.get_action() != _steal || this->status == _dead ) {
        throw std::invalid_argument("Ambassador Invalid Block\n");
    }
    dynamic_cast<Captain *>(&attacker)->blocked();
}

void Captain::steal(Player &victim) {
    if (check_10_coins()) {
        throw std::invalid_argument("Must coup!\n");
    }
    if (!check_turn()) {
        throw std::invalid_argument("Not your turn\n");
    }
    if (victim.get_status() == _dead) {
        throw std::invalid_argument("This player is missing from the game\n");
    }
    int taken = victim.set_coins(-2);
    this->set_coins(taken);
    this->c_victim = &victim;
    this->action = _steal;
    this->game->notify();
}
void Captain::blocked() {
    this->c_victim->set_coins(2);
    this->set_coins(-2);
    this->action = _income;
}