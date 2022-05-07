//
// Created by barak on 25/04/2022.
//

#include "Captain.hpp"

std::string Captain::role() const {
    return "Captain";
}

/** Special Skills */
void Captain::block(const Player &attacker) {

}

void Captain::steal(Player &victim) {
    if (!check_turn()) {
        throw std::invalid_argument("Not your turn\n");
    }
    this->game.notify();
}