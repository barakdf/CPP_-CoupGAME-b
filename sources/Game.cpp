//
// Created by barak on 25/04/2022.
//

#include "Game.hpp"
#include <algorithm>

using namespace coup;

size_t Game::add(const std::string& name) {
    if (game_status == _running) {
        throw std::invalid_argument("game already started!\n");
    }
    if (m_size == 6) {
        throw std::invalid_argument("game is in full capacity\n");
    }
//    if (std::binary_search(this->members.begin(), this->members.end(), name)) {
//        throw std::invalid_argument("this name is already exist!\n");
//    }
    this->members.push_back(name);
    this->m_size++;
    if (m_size == 2) {
        game_status = _ready;
    }
    this->initialized_players++;
    return (m_size - 1);
}

std::string Game::turn() const {
    return members.at(this->p_turn);
}

void Game::notify() {
//    std::cout << m_size << std::endl;
    if (game_status == _preMatch) {
        throw std::invalid_argument("Not enough players!\n");
    }
    // initialize game status to running at the first turn in the game
    if (this->game_status == _ready) {
        this->game_status = _running;
    }
    this->p_turn = (p_turn+1)%m_size;
}

std::vector<std::string> Game::players() const{
    return (this->members);
}
std::string Game::winner() const {
    if (game_status != _running) {
        throw std::invalid_argument("the game did not started\n");
    }
    if (m_size > 1) {
        throw std::invalid_argument("Only last man standing can be the winner!\n");
    }
    return this->members.at(0);
}

void Game::revive(int victim_pos, const std::string &name, size_t assassin_pos) {
    auto index = this->members.begin() + (int )victim_pos;
    this->members.insert(index ,name);
    this->m_size++;
    if (assassin_pos > victim_pos) {
        this->notify();
    } else {
        this->p_turn = this->p_turn % this->m_size;
    }

}
//
//Game::~Game() {
//    if (initialized_players == 0) {
//        delete (this->members);
//    } else {
//        initialized_players--;
//    }
//}

void Game::coup_player(const std::string &name,  const std::string &target_name, const std::string &attker_name) {
//    if (this->members.at(target_idx) != name) {
//        throw std::invalid_argument("the specific name does not exist in the game\n");
//    }
    bool attk_after_target = true;
    for (size_t i = 0; i < this->members.size(); ++i) {
        if (this->members.at(i) == attker_name) {
            attk_after_target = false;
        }
        if (this->members.at(i) == target_name) {
            this->members.erase(this->members.begin() + (int )i);
            break;
        }

    }
    this->m_size--;
    if(attk_after_target) {
        this->p_turn = (this->p_turn % m_size);
    } else {
        this->notify();
    }

}
