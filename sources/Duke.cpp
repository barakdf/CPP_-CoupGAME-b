//
// Created by barak on 25/04/2022.
//

#include "Duke.hpp"

//Duke::Duke (coup::Game &game, const std::string& name):coin(0) {
//    this->game = &game;
//    this->game->add(name);
//}
std::string Duke::role() const {
    return "Duke";
}
//void Duke::coup(const Player &target){
//
//}

/** Special Skills */
void Duke::block(Player &greedy) {
    if (greedy.get_action() != _foreign_aid) {
        throw std::invalid_argument("Invalid Duke block!\n");
    }
    greedy.foreign_blocked();
    greedy.get_action() = _income;
}

void Duke::tax() {
    if (check_10_coins()) {
        throw std::invalid_argument("Must coup!\n");
    }
    if (!check_turn()) {
        throw std::invalid_argument("Not your turn\n");
    }
    this->coin += 3;
    this->action = _assassinate;
    this->game->notify();
}
