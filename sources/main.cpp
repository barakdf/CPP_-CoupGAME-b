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


//int main() {
//    Game scenario;
//    Assassin assassin{scenario, "asi"};
//    Ambassador ambassador{scenario, "ambi"};
//    Captain captain{scenario, "capi"};
//    Contessa contessa{scenario, "conti"};
//    Duke duke{scenario, "duk"};
//
//    /** Start Game */
//
//    assassin.income();
//    ambassador.income();
//    captain.income();
//    contessa.income();
//    duke.tax();
//    std::cout << "Game coin STATUS: assassin: 1, ambassador: 1, captain: 1, contessa: 1, duke: \n" << std::endl;
//
//    assassin.foreign_aid();
//    ambassador.foreign_aid();
//    std::cout << " --duke is blocking the ambassador from taking double coin" << std::endl;
//    duke.block(ambassador);
//    std::cout << " --captain is trying to steal 2 coins from the ambassador " << std::endl;
//    captain.steal(ambassador);
//    std::cout << " --the ambassador is blocking captain stealing" << std::endl;
//    ambassador.block(captain);
//    contessa.income();
//    duke.tax();
//
//    std::cout << "\nGame coin STATUS: assassin: 3, ambassador: 1, captain: 1, contessa: 2, duke: \n" << std::endl;
//
//    std::cout << " --the assassin is trying to assassinate duke " << std::endl;
//    assassin.coup(duke);
//    std::cout << " --contessa is blocking the assassin operation and saves duke's life " << std::endl;
//    contessa.block(assassin);
//    std::cout << " --the ambassador is transferring one coin from contessa to assassin" << std::endl;
//    ambassador.transfer(contessa, assassin);
//    std::cout << " --captain is stealing 2 coins from duke, the ambassador is not blocking this operation" << std::endl;
//    captain.steal(duke);
//    contessa.foreign_aid();
//    std::cout << " --duke is not blocking contessa double coin" << std::endl;
//    duke.tax();
//
//    std::cout << "\nGame coin STATUS: assassin: 1, ambassador: 1, captain: 1, contessa: 3, duke: \n" << std::endl;
//
//    assassin.foreign_aid();
//    std::cout << " --duke is blocking assassin from double coin" << std::endl;
//    duke.block(assassin);
//    std::cout << " --the ambassador is transferring one coin from captain to the assassin " << std::endl;
//    ambassador.transfer(captain, assassin);
//    std::cout << " --the duke is not blocking captain from double coin " << std::endl;
//    captain.foreign_aid();
//    contessa.foreign_aid();
//    std::cout << " --duke is betraying contessa who saved him life from the assassin and coup her " << std::endl;
//    duke.coup(contessa);
//
//
//    std::cout << "\nGame coin STATUS: assassin: 2, ambassador: 1, captain: 2, contessa: DEAD, duke: \n" << std::endl;
//
//    assassin.income();
//    ambassador.foreign_aid();
//    std::cout << " --duke is blocking ambassador from getting double coin" << std::endl;
//    duke.block(ambassador);
//    captain.steal(assassin);
//    std::cout << " --ambassador is blocking captain from stealing 2 coins from the assassin " << std::endl;
//    ambassador.block(captain);
//    duke.tax();
//
//    std::cout << "\nGame coin STATUS: assassin: 3, ambassador: 1, captain: 2, contessa: DEAD, duke: 3 \n" << std::endl;
//
//   std::cout << " --the assassin is eliminating the captain, contessa is already dead so captain can be saved " << std::endl;
//
//    assassin.coup(captain);
//    ambassador.transfer(duke, assassin);
//    duke.tax();
//
//    std::cout << "\nGame coin STATUS: assassin: 0, ambassador: 1, captain: DEAD, contessa: DEAD, duke: 5 \n" << std::endl;
//
//    assassin.income();
//    ambassador.foreign_aid();
//    std::cout << " --duke is blocking ambassador from taking double coin " << std::endl;
//    duke.block(ambassador);
//    duke.tax();
//
//    std::cout << "\nGame coin STATUS: assassin: 1, ambassador: 1, captain: DEAD, contessa: DEAD, duke: 7 \n" << std::endl;
//
//    assassin.income();
//    ambassador.transfer(duke, assassin);
//    duke.tax();
//
//    std::cout << "\nGame coin STATUS: assassin: 3, ambassador: 1, captain: DEAD, contessa: DEAD, duke: 9 \n" << std::endl;
//
//    std::cout << " --the assassin is eliminating the duke and contessa cannot save him because he betrayed and killed her" << std::endl;
//    assassin.coup(duke);
//    std::cout << " --ambassador is taking double coin and duke is DEAD so he cant block him " << std::endl;
//    ambassador.foreign_aid();
//
//    std::cout << "\nGame coin STATUS: assassin: 0, ambassador: 3, captain: DEAD, contessa: DEAD, duke: DEAD \n" << std::endl;
//
//    assassin.foreign_aid();
//    ambassador.foreign_aid();
//
//    std::cout << "\nGame coin STATUS: assassin: 2, ambassador: 5, captain: DEAD, contessa: DEAD, duke: DEAD \n" << std::endl;
//
//    assassin.foreign_aid();
//    ambassador.foreign_aid();
//
//    std::cout << "\nGame coin STATUS: assassin: 4, ambassador: 7, captain: DEAD, contessa: DEAD, duke: DEAD \n" << std::endl;
//
//    assassin.coup(ambassador);
//
//
//    /** Game Ends */
//
//    std::cout << "game end : winner is ~ " << scenario.winner() << " ~" << std::endl;
//
//
//}
