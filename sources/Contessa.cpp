//
// Created by barak on 25/04/2022.
//

#include "Contessa.hpp"


/** return Contessa as the role of this player.*/
std::string Contessa::role() const {
    return "Contessa";
}


/** Special Skills */
/** contessa */
/** contessa block skill is used to block an assassination
 *  assassination is an operation made any assassin player who coup other player with the cost of 3 coin
 *  this method receive a Player Object reference as parameter.
 *  initial check for this method is to check either the Player we want to block is an assassin and if so if he is guilty.
 *  the method call other method (revive()) in the game class and passing the last victim of the assassination position and name
 *  and the attacker position.
 *  the revive method is specified and documented in game class */
void Contessa::block(Player &attacker) {
    if (attacker.get_action() != _assassinate || attacker.role() != "Assassin") {
        throw std::invalid_argument("Invalid Contessa block!\n");
    }
    attacker.get_last_couped().get_status() = _alive;
    this->game->revive((int )attacker.get_last_couped().get_position(),
                       attacker.get_last_couped().get_name(), attacker.get_position());

}