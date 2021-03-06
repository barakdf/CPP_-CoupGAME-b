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
    enum game_st {_preMatch, _ready, _running};
    class Game {
    private:
        size_t initialized_players;
        size_t p_turn;
        size_t m_size;
        std::vector<std::string> members;
        int game_status = _preMatch;

    public:
        Game() : p_turn(0), m_size(0),initialized_players(0) {}

        size_t add(const std::string& name);

        std::string turn() const;

        std::vector<std::string> players() const;

        std::string winner() const;

        void coup_player(const std::string &target_name, const std::string &attker_name);

        void notify();

        void revive(int victim_pos, const std::string &name, size_t assassin_pos);

//        ~Game();

    };
}

#endif //CPP__COUPGAME_A_GAME_HPP
