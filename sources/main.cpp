/**
 * Common variables and method to all kind of characters:
 * ~int coin
 * ~Game game
 * ~String name
 * ~Status
 * ~Action
 *
 *
 *  Ambassador :
 *  skills:
 *      Offensive -> Transfer().
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




//int main() {
//    std::cout << "Hello, World!" << std::endl;
//    return 0;
//}
