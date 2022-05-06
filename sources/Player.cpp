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
    this->coin++;
}

void Player::foreign_aid() {
    this->coin += 2;
}

void Player::coup(const Player &target) {
    this->game.coup_player(target.get_name());
}