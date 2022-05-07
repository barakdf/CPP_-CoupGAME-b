//
// Created by barak on 25/04/2022.
//

#include "Player.hpp"

Player::Player(coup::Game &games, const std::string &name):coin(0), name(name) {
    this->game = games;
    this->game.add(name);
}

std::string Player::get_name() const{
    return this->name;
}

int Player::coins() const {
    return coin;
}

void Player::income() {
    this->action = _income;
    this->coin++;
}

void Player::foreign_aid() {
    this->action = _foreign_aid;
    this->coin += 2;
}

void Player::coup(const Player &target) {
    this->action = _coup;
    this->game.coup_player(target.get_name());
}

/** Getters */
int Player::get_status() const {
    return this->status;
}

int Player::get_action() const {
    return this->action;
}

int Player::set_coins(int amount) {
    /* the first check for actions such as coup and assassin coup.*/
    if (amount > 2 && this->coin < (-amount)) {
        throw std::invalid_argument("not enough coins for this action!\n");
    }
    /* this if for captain steal and ambassador transfer */
    if (amount < 0) {
        int taken = 0;
        for (int i = coin; i >=0 ; ++i) {
            taken++;
        }
        return taken;
    }
    /* for ambassador destination transfer*/
    this->coin += amount;
    return -1;
}
