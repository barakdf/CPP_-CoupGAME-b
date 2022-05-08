//
// Created by barak on 25/04/2022.
//

#include "Contessa.hpp"

//Contessa::Contessa (coup::Game &game,const std::string &name):coin(0) {
//    this->game = &game;
//    this->game->add(name);
//}
std::string Contessa::role() const {
    return "Contessa";
}
//void Contessa::coup(const Player &target) {
//
//}

/** Special Skills */
void Contessa::block(Player &attacker) {
    if (attacker.get_action() != _assassinate || attacker.role() != "Assassin") {
        throw std::invalid_argument("Invalid Contessa block!\n");
    }
    attacker.get_last_couped().get_status() = _alive;
    this->game->revive((int )attacker.get_last_couped().get_position(),
                       attacker.get_last_couped().get_name(), attacker.get_position());

}