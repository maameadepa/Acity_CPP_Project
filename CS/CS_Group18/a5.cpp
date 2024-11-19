/*QUESTION ONE*/
/*Code for multiplication table*/
#include <iostream>
#include <iomanip> 
using namespace std;

int main() {
    
/*Displaying the multiplication table*/
    for (int i = 0; i <= 12; i++) {
        
        cout << i << "\t"; 
        
        for (int j = 0; j <= 12; j++) {
        
            cout << i * j << "\t"; 
        }
        
        cout << endl;
    }
    return 0;
}


/*QUESTION TWO*/
/*PART ONE: INFINITE DONUT PROBLEM*/
#include <iostream>
#include <cstdlib> 
#include <ctime>
using namespace std;

int main() {
    int donuts = 0;
    while (donuts < 12) {
        cout << "Making donut #" <<++donuts << endl;

/*PART TWO: SKIPPING BURNT DONUT*/
        donuts++;
        if (donuts == 6) {
            cout << "Skipping donut #" <<donuts <<" (burnt)" << endl;
            continue;
        }
        cout << "Making donut " <<donuts <<endl;
    }

/*PART THREE: RANDOM SUPER DONUT */
    while (donuts < 12) {
        donuts++;
        if (donuts == 6) {
            cout << "Skipping donut #" << donuts << " (burnt)" << endl;
            continue;
        }
        if (rand() % 3 == 0) {  // 1 in 3 chance
            cout << "Making SUPER donut #" << donuts << endl;
        } else {
            cout << "Making donut #" << donuts << endl;
        }
    }

/*EXTRA CHALLENGE: INFINITE DONUTS WITH BREAKS*/
    while (true) {
        donuts++;
        if (donuts % 100 == 0) {
            cout << "Taking a break after making " << donuts << " donuts!" << endl;
            continue; 
        }
        cout << "Making donut #" << donuts << endl;
    }
  return 0;
}
    
/*QUESTION THREE*/
/*THE PRINCESS' EPIC QUEST*/
#include <iostream>
#include <cstdlib> // For rand()
#include <ctime>   // For time()
using namespace std;

int main() {
    srand(time(0));  // Seed random number generator
    int attack, dragon_health = 50, princess_health = 50, dragon_attack, princess_attack = rand() % 10 + 1;;
    
/*PART ONE: BATTLING FIVE MONSTERS*/
    for (int i = 1; i <= 5; i++) {
        cout << "Fighting monster #" << i << endl;
        while (true) {
            attack = rand() % 6 + 1;  // Roll a dice (1 to 6)
            cout << "Princess attacks with strength " << attack << endl;
            if (attack > 3) {
                cout << "Monster defeated!" << endl;
                break; // Monster defeated
            } else {
                cout << "Princess takes damage and must fight again!" << endl;
            }
        }
    }

/*PART TWO: THE FINAL BOSS BATTLE*/
    cout << "The Final Boss Battle begins!" << endl;

    while (dragon_health > 0 && princess_health > 0) {
        
        // Princess attacks
        dragon_health -= princess_attack;
        cout << "Princess attacks with " << princess_attack << " damage. Dragon's health: " << dragon_health << endl;

/*DRAGON DEFEATED*/
        if (dragon_health <= 0) {
            break; 
        }

/*DRAGON ATTACK*/
        int dragonAttack = rand() % 10 + 1;
        princess_health -= dragon_attack;
        cout << "Dragon attacks with " << dragon_attack << " damage. Princess's health: " << princess_health<< endl;

        if (princess_health <= 0) {
            cout << "The princess has fallen. The dragon wins!" << endl;
            return 0;  // End the game
        }
    }
    cout << "The dragon is defeated!" << endl;

/*PART THREE: CLAIMING THE PRINCE*/
    cout << "Congratulations! Princess Valeria has defeated the dragon and rescued Prince Theodore!" << endl;
    return 0;
}