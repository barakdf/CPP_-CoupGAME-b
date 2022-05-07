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
    if (std::binary_search(this->members->begin(), this->members->end(), name)) {
        throw std::invalid_argument("this name is already exist!\n");
    }
    this->members->push_back(name);
    this->m_size++;
    this->initialized_players++;
}

std::string Game::turn() const {
    return members->at(this->p_turn);
}

void Game::notify() {
//    std::cout << m_size << std::endl;
    this->p_turn = (p_turn+1)%m_size;
}

std::vector<std::string> Game::players() const{
    return *(this->members);
}
std::string Game::winner() const {

    return this->members->at(0);
}

Game::~Game() {
    if (initialized_players == 0) {
        delete (this->members);
    } else {
        initialized_players--;
    }
}

void Game::coup_player(const std::string &name) {

}
