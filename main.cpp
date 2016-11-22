#include "main.h"

using namespace std;

// amount of people
int amount = 100000;

// start here
int main() {
  srand(time(NULL));

  std::clock_t start;
  double duration;
  start = std::clock();

  // create people
  vector<Person*> people;
  for (int i = 1; i < amount; i++) {
    Person* p = new Person();
    people.push_back(p);
  }

  // here is your MAMA
  //Person* p = new Person("Your MAMA", 999, 9999, 3);
  //people.push_back(p);

  // attack until there is one left
  while(people.size() > 1) {
    // pick random players
    int playerAttackt = randomNumber(people.size());
    int playerGetAttackt = randomNumber(people.size());

    // attack them or it get him self
    if (playerAttackt == playerGetAttackt) {
        people[playerAttackt]->getHimSelf();
    // do something with the other person
    } else {
        people[playerAttackt]->attack(people[playerAttackt],people[playerGetAttackt]);
    }

    // delete if person is dead
    if (people[playerAttackt]->getHealth() <= 0) {
      Person *p = people[playerAttackt];
      delete p;
      people.erase (people.begin() + playerAttackt);
    }

    // delete if person is dead
    if (people[playerGetAttackt]->getHealth() <= 0) {
      Person *p = people[playerGetAttackt];
      delete p;
      people.erase (people.begin() + playerGetAttackt);
    }
  }

  // there is one person left
  cout << "=================================" << endl;
  cout << people[0]->getName() << " won with: " << ((int)people[0]->getHealth()) << " health left" << endl;
  cout << people[0]->getName() << " gender is: " << people[0]->getGender() << endl;
  cout << "and used " << people[0]->getWeapon()->getWeaponName() << " as weapon" << endl;
  cout << "min attack damage is: " << ((int)people[0]->getDamage("min")) << " and max damage is: " << ((int)people[0]->getDamage("max")) << endl;
  cout << ((int)people[0]->getMedicSkills()) << " medic skills" << endl;
  cout << ((int)people[0]->getKills()) << " amount kills" << endl;
  cout << people[0]->getName() << " has " << ((int)people[0]->getFightingSkills()) << " fightingSkills" << endl;
  duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;

  int sec = duration;
  int min = 0;
  while (sec > 60) {
    min++;
    sec -= 60;
  }

  std::cout<<"time "<< min << ":" << sec << endl;

  delete people[0];
  people.clear();
  return 0;
}

// gen randomNumber
int randomNumber(int amount) {
  return (rand() % amount);
}

// simple text
void say(std::string text) {
  cout << text << endl;
}
