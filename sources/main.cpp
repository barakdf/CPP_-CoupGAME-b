/**
 * Common variables and method to all kind of characters:
 * Vars:
 * ~int coin
 * ~Game game
 * ~String name
 * ~enum status
 * ~enum action
 *Methods:
 * Coins()
 * Income()
 * Foreign_aid()
 * get_name()
 * get_status()
 * get_action()
 * coup()
 *
 *  Ambassador :
 *  skills:
 *      Offensive -> Transfer(). **Implemented
 *      Defensive -> block() *steal.
 *
 *  Assassin :
 *  skills:
 *      Offensive -> coup () *can use it from 3 coins to 6 with a risk.
 *
 *  Captain :
 *  skills:
 *      Offensive -> Steal().
 *      Defensive -> block() *other steal
 *
 *  Contessa :
 *  skills:
 *      Defensive -> block() *Assassination
 *
 *  Duke :
 *  skills:
 *      Offensive -> Tax()
 *      Defensive -> block() *foreign_aid
 *
 *
 *  Additional Info:
 *  ~~ Player cannot have negative coin value. (captain steal, Ambassador transfer) (exception)
 *  ~~ The turns order is determined within the join order of the players to the game. (exception)
 *  ~~ Player cannot play not in his turn (exception)
 *  ~~ Player who can use block skill can only block specific roles:
 *      Duke - (Anyone who made foreign_aid)
 *      Ambassador - (Captain when he steal)
 *      Captain - (other Captain when he steal)
 *      Contessa - (Assassin on assassination)
 *
 *  ~~ More than one player can have same role.
 *  ~~ Player who possess 10 coins or more must perform a coup operation.
 *  ~~ block Operations can be perform in any time between a full round of turns.
 *  ~~ Player who got blocked on foreign_aid op return the two coins and ends his turn.
 *  ~~ Player (can/can't ?) block an already blocked operation.
 *  ~~ Captain can steal from other player even if he have less then 2 coins.
 *  ~~ Cannot make an operation on a player who don't participant in the game anymore.
 *  ?? does ambasssador can transfer coin to himself.
 *  */

#include <iostream>
#include "Player.hpp"
#include "Duke.hpp"
#include "Assassin.hpp"
#include "Ambassador.hpp"
#include "Captain.hpp"
#include "Contessa.hpp"

/** [duke, assassin, Ambassador, contessa]
 *  [0, 1, 2]*/

//int main() {
//    Game game_8{}; // build game . add players
//    Duke duke{game_8, "Moshe"};
//    Assassin assassin{game_8, "Yossi"};
//    Ambassador ambassador{game_8, "Meirav"};
//    Captain captain{game_8, "Reut"};
//    Contessa contessa{game_8, "Gilad"};
//    for (const std::string& player : game_8.players()) {
//        std::cout << player << ", ";
//    }
//    std::cout<<std::endl;
//
//    for (int i = 0; i < 7; i++) {
//        duke.income();
//        assassin.income();
//        ambassador.income();
//        captain.income();
//        contessa.income();
//    }
//// each one has 7 coins, enough for using coup()
//    duke.coup(assassin); //moshe -> yossi
//    for (const std::string& player : game_8.players()) {
//        std::cout << player << ", ";
//    }
//    std::cout<<std::endl << "turn -> " << game_8.turn() << std::endl;
//
//    ambassador.coup(contessa); // meirav -> gilad
//    for (const std::string& player : game_8.players()) {
//        std::cout << player << ", ";
//    }
//    std::cout<<std::endl << "turn -> " << game_8.turn() << std::endl;
//
//    captain.coup(ambassador); // reut -> meirav
//    for (const std::string& player : game_8.players()) {
//        std::cout << player << ", ";
//    }
//    std::cout<<std::endl << "turn -> " << game_8.turn() << std::endl;
//
//    duke.income();
//    std::cout<<std::endl << "turn -> " << game_8.turn() << std::endl;
//    captain.income();
//    std::cout<<std::endl << "turn -> " << game_8.turn() << std::endl;
//}
