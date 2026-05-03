/*
 * Dice Gambling Game
 *
 * Two-player dice game against the computer. The player bets
 * from a starting balance of $1000. Higher roll wins the bet;
 * a tie is a push. Game ends when the player quits or goes broke.
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

double funds = 1000.0;

double placeBet() {
  double amt;
  cout << "How much would you like to bet? $";
  cin >> amt;
  while (amt <= 0 || amt > funds) {
    cout << "Invalid. Enter a bet between $1 and $" << funds << ": $";
    cin >> amt;
  }
  return amt;
}

int rollDie() {
  return (rand() % 6) + 1;
}

bool askPlayAgain() {
  char choice;
  do {
    cout << "Play again? (Y/N): ";
    cin >> choice;
  } while (tolower(choice) != 'y' && tolower(choice) != 'n');
  return tolower(choice) == 'y';
}

int main() {
  srand(static_cast<unsigned>(time(nullptr)));
  cout << "=== Dice Gambling Game ===\n";

  do {
    cout << "\nCurrent balance: $" << funds << "\n";
    double bet = placeBet();

    int playerRoll   = rollDie();
    int opponentRoll = rollDie();
    cout << "You rolled: " << playerRoll
         << "  |  Opponent rolled: " << opponentRoll << "\n";

    if (playerRoll > opponentRoll) {
      funds += bet;
      cout << "You won $" << bet << "!\n";
    } else if (playerRoll < opponentRoll) {
      funds -= bet;
      cout << "You lost $" << bet << ".\n";
    } else {
      cout << "Tie — no change.\n";
    }

    if (funds <= 0) {
      cout << "You're broke. Game over.\n";
      break;
    }
  } while (askPlayAgain());

  cout << "\nFinal balance: $" << funds << "\n";
  return 0;
}
