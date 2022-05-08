//
// Created by barak on 25/04/2022.
//

#include "Player.hpp"

Player::Player(coup::Game &games, const std::string &name):coin(0), name(name), last_couped(nullptr) {
    this->game = &games;
    this->p_index = this->game->add(name);
}

int Player::coins() const {
    return this->coin;
}

/** Player common actions */
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

void Player::coup(Player &target) {
    if (!check_turn()) {
        throw std::invalid_argument("Not your turn" + this->name + " its " + this->game->turn() + " turn\n");
    }
    if (target.get_status() == _dead) {
        throw std::invalid_argument("This player is missing from the game!\n");
    }
    if (this->role() == "Assassin" && this->coin < 7) {
        this->set_coins(-3);
        this->action = _assassinate;
    } else {
        this->set_coins(-7);
        this->action = _coup;
    }
    target.get_status() = _dead;
    this->game->coup_player(target.get_name(), target.get_name(), this->get_name());
    this->last_couped = &target;
}

/** Getters & Setters*/
int Player::get_status() const {
    return this->status;
}

std::string Player::get_name() const{
    return this->name;
}
int& Player::get_status() {
    return this->status;
}

int Player::get_action() const {
    return this->action;
}
int& Player::get_action() {
    return this->action;
}

size_t Player::get_position() const {
    return this->p_index;
}

Player& Player::get_last_couped() {
    return *(this->last_couped);
}

/** Coin handler*/
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

/** Common player blocked */
void Player::foreign_blocked() {
    set_coins(-2);
}

/** CHECKS */
bool Player::check_10_coins() const {
    return this->coin >= 10;
}

bool Player::check_turn() {
//    std::cout << "size is " << this->game.turn() << std::endl;
    return this->name == this->game->turn();
}