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

  while(people.size() > 1) {
    // pick random players
    int playerAttackt = randomNumber(people.size());
    int playerGetAttackt = randomNumber(people.size());

    // attack them or it get him self
    if (playerAttackt == playerGetAttackt) {
        people[playerAttackt]->getHimSelf();

    } else {
        people[playerAttackt]->attack(people[playerGetAttackt]);
    }

    if (people[playerAttackt]->getHealth() <= 0) {
      Person *p = people[playerAttackt];
      delete p;
      people.erase (people.begin() + playerAttackt);
    }

    if (people[playerGetAttackt]->getHealth() <= 0) {
      Person *p = people[playerGetAttackt];
      delete p;
      people.erase (people.begin() + playerGetAttackt);
    }
  }

  cout << "=================================" << endl;
  cout << people[0]->getName() << " won with: " << people[0]->getHealth() << " health left" << endl;
  cout << people[0]->getDamage() << " attack damage" << endl;
  cout << people[0]->getMedicSkills() << " medic skills" << endl;
  cout << people[0]->getKills() << " amount kills" << endl;
  duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;

  std::cout<<"time: "<< duration / 60 << endl;

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
