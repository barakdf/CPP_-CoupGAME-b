//
// Created by barak on 25/04/2022.
//
/** ~Fields -->
 *  p_turn -> pointing on the member who has the turn.
 *  m_size -> store the current playing group size.
 *  Vector members -> store all the game participants
 *
 *  ~Functions -->
 *  turn() -> printing the member that has the turn.
 *
 *  players() -> return list of the current playing members names
 *
 *  */
#ifndef CPP__COUPGAME_A_GAME_HPP
#define CPP__COUPGAME_A_GAME_HPP

#include <iostream>
#include <vector>
//#include "Player.hpp"

namespace coup {
    class Game {
    private:
        size_t initialized_players;
        size_t p_turn;
        size_t m_size;
        std::vector<std::string> *members;


    public:
        Game() : p_turn(0), m_size(0),initialized_players(0), members(new std::vector<std::string>) {}

        void add(const std::string& name);

        std::string turn() const;

        std::vector<std::string> players() const;

        std::string winner() const;

        void coup_player(const std::string &name);

        void notify();

        ~Game();

    };
}

#endif //CPP__COUPGAME_A_GAME_HPP
