//
// Created by barak on 25/04/2022.
//

#include "Ambassador.hpp"
#include "Captain.hpp"

/** return Ambassador as the role of this player.*/
std::string Ambassador::role() const {
    return "Ambassador";
}
//void Ambassador::coup(const Player &target) {
//
//}

/** Special Skills */
/** Offensive
 *  Ambassador transfer skill is transferring 1 coin from one player to another.
 *  the method receive two parameters, both are Player object references
 *  the method made the initial checks to be a legal action.
 *  using the set_coin() method to make the transfer */
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
/** Defensive
 *  Ambassador block skill is used for blocking any steals made by the Captain players in the game.
 *  this method receive one Player object reference as parameter.
 *  two initial check is made, if the Player who we want to block is innocent, or he is out of the game.
 *  in Case its legal block, we call blocked() method that specified in Captain class.*/
void Ambassador::block(Player &attacker) {
    if(attacker.get_action() != _steal || this->status == _dead) {
        throw std::invalid_argument("Ambassador Invalid Block\n");
    }
    dynamic_cast<Captain *>(&attacker)->blocked();
}
