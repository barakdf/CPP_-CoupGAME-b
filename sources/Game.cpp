//
// Created by barak on 25/04/2022.
//

#include "Game.hpp"
#include <algorithm>

using namespace coup;

void Game::add(const std::string& name) {
    if (m_size == 6) {
        throw std::invalid_argument("game is in full capacity\n");
    }
    if (std::binary_search(this->members.begin(), this->members.end(), name)) {
        throw std::invalid_argument("this name is already exist!\n");
    }
    this->members.push_back(name);
    this->m_size++;
    if (m_size == 2) {
        game_status = _ready;
    }
    this->initialized_players++;
}

std::string Game::turn() const {
    return members.at(this->p_turn);
}

void Game::notify() {
//    std::cout << m_size << std::endl;
    if (game_status == _preMatch) {
        throw std::invalid_argument("Not enough players!\n");
    }
    this->p_turn = (p_turn+1)%m_size;
}

std::vector<std::string> Game::players() const{
    return (this->members);
}
std::string Game::winner() const {
    if (m_size > 1) {
        throw std::invalid_argument("Only last man standing can be the winner!\n");
    }
    return this->members.at(0);
}
//
//Game::~Game() {
//    if (initialized_players == 0) {
//        delete (this->members);
//    } else {
//        initialized_players--;
//    }
//}

void Game::coup_player(const std::string &name) {
    
}
