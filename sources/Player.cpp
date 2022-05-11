//
// Created by barak on 25/04/2022.
//

#include "Player.hpp"
const int COUP_COST = 7, COUP_ASSASSIN_COST = 3, COUP_MUST_VALUE = 10;

/** constructor - initialize fields: coin -> 0, name -> given parameter name, last_couped -> null
 *  game pointer in player class will point at the given game parameter.
 *  call the game add method to add *this player to game and store this player start game index*/
Player::Player(coup::Game &games, const std::string &name):coin(0), name(name), last_couped(nullptr) {
    this->game = &games;
    this->p_index = this->game->add(name);
}

/** return *this player amount of coins */
int Player::coins() const {
    return this->coin;
}

/** Player common actions */

/** add one coin to *this player */
void Player::income() {
    if (check_10_coins()) {
        throw std::invalid_argument("Must coup!\n");
    }
    if (!check_turn()) {
        throw std::invalid_argument("Not your turn " + this->name + " its " + this->game->turn() + " turn\n");
    }
    this->action = _income;
    this->coin++;
    this->game->notify();
}

/** add 2 to coins to *this player, updating player last action status to _foreign_aid.
 * this operation can be blocked and can be indicated by other player within the last action status.*/
void Player::foreign_aid() {
    if (check_10_coins()) {
        throw std::invalid_argument("Must coup!\n");
    }
    if (!check_turn()) {
        throw std::invalid_argument("Not your turn " + this->name + " its " + this->game->turn() + " turn\n");
    }
    this->action = _foreign_aid;
    this->coin += 2;
    this->game->notify();
}

/** this method get another player reference as parameter and cost 7 coins.
 *  the player who call this method is banning other player from the game.
 *  at the function body we updating the Game of the operation and the vector of participating players.
 *  ~in Case of Assassin character we check if the assassin using hes unique skill of coup at 3 coins cost.
 *  */
void Player::coup(Player &target) {
    if (!check_turn()) {
        throw std::invalid_argument("Not your turn" + this->name + " its " + this->game->turn() + " turn\n");
    }
    if (target.get_status() == _dead) {
        throw std::invalid_argument("This player is missing from the game!\n");
    }
    if (this->role() == "Assassin" && this->coin < COUP_COST) {
        this->set_coins(-COUP_ASSASSIN_COST);
        this->action = _assassinate;
    } else {
        this->set_coins(-COUP_COST);
        this->action = _coup;
    }
    target.get_status() = _dead;
    this->game->coup_player( target.get_name(), this->get_name());
    this->last_couped = &target;
}

/** Getters & Setters*/
/** returning the current status */
int Player::get_status() const {
    return this->status;
}
int& Player::get_status() {
    return this->status;
}

/** returning *this player name */
std::string Player::get_name() const{
    return this->name;
}

/** returning the last action of *this player */
int Player::get_action() const {
    return this->action;
}
int& Player::get_action() {
    return this->action;
}

/** returning the position of *this player in the game turns*/
size_t Player::get_position() const {
    return this->p_index;
}

/** returning the last player who was couped by *this player */
Player& Player::get_last_couped() {
    return *(this->last_couped);
}

/** Coin handler*/

/** this method is used to handle all of money transaction between players and individual player.
 *  this method get parameter that describes the amount we want to reduce/increase from/to *this player.
 *  by dividing the amount to 3 options, coup, steal/transfer or increasing (for example: income/foreign_aid/outcome of block operation)
 *  returning the taken amount (for example to know how much the captain was able to steal)
 *  or returning -1 if the operation was increasing attitude*/
int Player::set_coins(int amount) {
    /* the first check for actions such as coup and assassin coup.*/
//    int cost = (-1) * amount;
    if (amount < -2 && this->coin < (-amount)) {
        throw std::invalid_argument("not enough coins for this action!\n");
    }
    /* this if for captain steal and ambassador transfer */
    if (amount < 0) {
        int taken = 0;
        for (int i = coin; i >0 && taken < (-amount) ; --i) {
            taken++;
            this->coin--;
        }
        return taken;
    }
    /* for blocked actions*/
    this->coin += amount;
    return -1;
}

/** Common player blocked
 *  relevant for all players that has been blocked by the Duke*/

void Player::foreign_blocked() {
    set_coins(-2);
}

/** CHECKS */
/** check if the player have 10 coins, called by action methods made by the player (except Block and coup)
 *  this check is preventing from players to break the rule where every player have to coup when he posses 10 coins */
bool Player::check_10_coins() const {
    return this->coin >= COUP_MUST_VALUE;
}

/** check if the player who try to make an action have the turn, called by any action except block.*/
bool Player::check_turn() {
    return this->name == this->game->turn();
}