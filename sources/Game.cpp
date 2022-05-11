//
// Created by barak on 25/04/2022.
//

#include "Game.hpp"
#include <algorithm>

const int MAX_GAME_SIZE = 6;
using namespace coup;

/** this method is used to add new player to the game.
 *  this method control the status of the game and determine if the game is ready to start.
 *  initial checks in this method is:
 *      check if the game is already running to prevent players to join an active game.
 *      check if the game is in full capacity (valid only to 2-6 players)
 *  when new player join the game he will be added to the game vector (list of the active participant players).*/
size_t Game::add(const std::string& name) {
    if (game_status == _running) {
        throw std::invalid_argument("game already started!\n");
    }
    if (m_size == MAX_GAME_SIZE) {
        throw std::invalid_argument("game is in full capacity\n");
    }

    this->members.push_back(name);
    this->m_size++;
    if (m_size == 2) {
        game_status = _ready;
    }
    this->initialized_players++;
    return (m_size - 1);
}

/** this method return to the player the name of the current player that have the turn */
std::string Game::turn() const {
    return members.at(this->p_turn);
}

/** in every action of the players they call this method to notify the player they made their turn,
 *  when this method is called the server is passing the turn to the next player.
 *  initial check in this method:
 *      if the game status is prematch, will throw an error because the game is not ready to start.
 *  this method is determine when the game is starting.*/
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

/** this method return the list of active participating players in the game */
std::vector<std::string> Game::players() const{
    return (this->members);
}

/** this method return the winner of the game,
 *  checking if the game is started and if only one player has left.*/
std::string Game::winner() const {
    if (game_status != _running) {
        throw std::invalid_argument("the game did not started\n");
    }
    if (m_size > 1) {
        throw std::invalid_argument("Only last man standing can be the winner!\n");
    }
    return this->members.at(0);
}

/** this method can be called by any contessa player to block an assassin operation.
 *  receiving 3 parameters, the victim position and name, and the assassin position
 *  inserting the victim back to the game, increasing the size of the players,
 *  if the assassin turn was after his victim we increasing the turn pointer other to balanced the order of the turns in the game. */
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

/** this method can be called from any character type in the game, used to coup other player
 *  this method receive 2 parameters, target name and the attacker name.
 *  eject the target player from the game and decreasing the size of the active players.
 *  in order the balance the game turn pointer we check if the attacker turn was after the target:
 *      in case false -> we increasing the turn pointer.*/
void Game::coup_player(const std::string &target_name, const std::string &attker_name) {

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
