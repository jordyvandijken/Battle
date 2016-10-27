#include "person.h"

Person::Person() {
  std::string genderS[3] = {"male","female","apache helicopter"};
  std::string namePartsStart[47] = {"jordy","corne","lars","dern","andy","jeffery","teis","nino","bobby","gidi","robin","john","peter","frank","johan","roy","rolf","kevin","roan","jasper","owen","neill","max","jason","jesse","dylan","omar","yochem","daan","stein","beau","sam","peter","jorn","harry","daniel","wouter","glen","bo","enzo","tobias","noud","rick","tim","james","vince","rob"};
  std::string namePartsEnd[10] = {" van dijken"," steenhuis"," werther"," Alfrink"," andriessen"," holdenburg"," hogeveen"," plop"," pannekoek"," van liempd"};
  gender = genderS[rand()%2];
  name = (namePartsStart[(rand()%10)] + namePartsEnd[(rand()%10)]);
  health = rand() % 75 + 26;
  damage = rand() % 28 + 3;
  medicSkills = rand() % 25 + 1;
  fightingSkills = rand() % 60  + 11;
  armor = 10;
  kills = 0;
}

std::string Person::getName() {
  return name;
}

// get amount of health
int Person::getHealth() {
  return health;
}

// get amount of damage
int Person::getDamage() {
  return damage;
}

// get amount of medicSkills
int Person::getMedicSkills() {
  return medicSkills;
}

// get amount of fightingSkills
int Person::getFightingSkills() {
  return fightingSkills;
}

// get amount of kills
int Person::getKills() {
  return kills;
}

// add kill
void Person::addKill() {
  kills++;
}

// take damage
void Person::takeDamage(int _damage) {
  health -= _damage - armor;
  armor -= _damage / 2;
}

// attack someone
void Person::attack(Person* p) {
  if (p->getFightingSkills() < fightingSkills) { // attack that person
    attackPerson(p);
  } else if (p->getFightingSkills() == getFightingSkills()) { // they are equal in fightingSkills
    attackSameFightingSkills(p);
  } else {

  }
}

void Person::attackPerson(Person* p) {
  p->takeDamage(damage);
  if (p->getHealth() <= 0) { // add the kill if he is dead
    addKill();
  }
}

void Person::attackSameFightingSkills(Person* p) {
  int option = rand() % 2 + 1;
  if (option == 1) { // they both get damage
    p->takeDamage(damage);
    //takeDamage(p->getDamage());
  } else if (option == 2) {
    option = rand() % 2 + 1;
    if (option == 1){  // they one de
      p->takeDamage(damage/2);
    } else {
      takeDamage(p->getDamage()/2);
    }
  }
}

void Person::counterAttack(Person* p) {
  takeDamage(p->getDamage());
  if (p->getHealth() <= 0) {
    p->addKill();
  }
}

void Person::getHimSelf() {
  if (health < 100) {
    health += medicSkills;
  }
}

Person::~Person()
{
  //std::cout << "plop" << std::endl;
}
