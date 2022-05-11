//
// Created by barak on 25/04/2022.
//

#include "Captain.hpp"

/** return Captain as the role of this player.*/
std::string Captain::role() const {
    return "Captain";
}

/** Special Skills */
/** Defensive
 *  Captain block skill is used for blocking any steals made by the other Captain players in the game.
 *  this method receive one Player object reference as parameter.
 *  two initial check is made, if the Player who we want to block is innocent, or he is out of the game.
 *  in Case its legal block, we call blocked() method that specified in Captain class.*/
void Captain::block(Player &attacker) {
    if(attacker.get_action() != _steal || this->status == _dead ) {
        throw std::invalid_argument("Ambassador Invalid Block\n");
    }
    dynamic_cast<Captain *>(&attacker)->blocked();
}

/** Offensive
 *  Captain steal skill is removing 2 coins from other player and adds them to *this Captain player.
 *  this method initial checks is:
 *      to check if *this player posses 10 coins at this turn
 *      if it this player's turn
 *      if the player who we want to still is in the game.
 *
 *  stealing is implemented by set_coins() method
 *  updating last_action of this player to "_steal"
 *  that can be detected by other players who have the ability to block*/
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

/** this method is calling by other players (ambassador or other captains)  to block *this player from last steal action*/
void Captain::blocked() {
    this->c_victim->set_coins(2);
    this->set_coins(-2);
    this->action = _income;
}