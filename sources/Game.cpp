//
// Created by barak on 25/04/2022.
//

#include "Game.hpp"

using namespace coup;

void Game::add(const std::string& name) {
    this->members->push_back(name);
    initialized_players++;
}

std::string Game::turn() const {
    return members->at(p_turn);
}
std::vector<std::string> Game::players() const{
    return *(this->members);
}
std::string Game::winner() const {

    return this->players().at(0);
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
