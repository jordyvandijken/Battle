#include "person.h"

Person::Person() {
  srand (time(NULL));
  std::string genderS[4] = {"male","female","apache helicopter","non-binary"};
  std::string namePartsStart[48] = {"jordy","corne","lars","dern","andy","jeffery","teis","nino","bobby","gidi","robin","john","peter","frank","johan","roy","rolf","kevin","roan","jasper","owen","neill","max","jason","jesse","dylan","omar","yochem","daan","stein","beau","sam","peter","jorn","harry","daniel","wouter","glen","bo","dennis","tobias","noud","rick","tim","james","vince","rob","anjo"};
  std::string namePartsEnd[25] = {" van dijken"," steenhuis"," werther"," Alfrink"," andriessen"," holdenburg"," hogeveen"," plop"," snow"," van liempd","baker","howard","rhine","livingstone","land","turner","dare","parker","neville","conley","king","bond","adems","chapman","jackson"};
  gender = genderS[rand()%2];
  name = (namePartsStart[(rand()%48)] + namePartsEnd[(rand()%10)]);
  health = rand() % 75 + 26;
  damage = rand() % 28 + 3;
  medicSkills = rand() % 25 + 1;
  fightingSkills = rand() % 60 + 11;
  armor = 10;
  kills = 0;
  weapon = new Fist();
}

std::string Person::getName() {
  return name;
}

// get amount of health
char Person::getHealth() {
  return health;
}

// get amount of damage
char Person::getDamage() {
  return damage + weapon->getWeaponDamage();
}

// get min and max damage
char Person::getDamage(std::string m) {
  if (m == "min") {
    return damage + weapon->getWeaponMinDamage();
  } else if (m == "max") {
    return damage + weapon->getWeaponMaxDamage();
  }
  return 255;
}

// get amount of medicSkills
char Person::getMedicSkills() {
  return medicSkills;
}

// get amount of fightingSkills
char Person::getFightingSkills() {
  return fightingSkills;
}

// get amount of kills
char Person::getKills() {
  return kills;
}

// get weapon
Weapon* Person::getWeapon() {
  return weapon;
}

// add kill
void Person::addKill() {
  kills++;
}

// take damage
void Person::takeDamage(char _damage) {
  health -= _damage - armor;
  armor -= _damage / 2;
}

// attack someone
void Person::attack(Person* first,Person* second) {
  // attack person if fightingSkills is higher
  if (second->getFightingSkills() < fightingSkills) {
    attackPerson(second);
  // the other person has the same fightingSkills
  } else if (second->getFightingSkills() == getFightingSkills()) { // they are equal in fightingSkills
    attackSameFightingSkills(second);
  // the other person has a higher fightingSkill
  } else {
    second->attackPerson(first);
  }
}

void Person::attackPerson(Person* first,Person* second) {
  p->takeDamage(getDamage());
  // if (p->getHealth() <= 0) { // add the kill if he is dead
  //   addKill();
  // }
}

void Person::attackSameFightingSkills(Person* first,Person* second) {
  int option = rand() % 2 + 1;
  if (option == 1) { // they both get damage
    p->takeDamage(damage);
    //takeDamage(p->getDamage());
  } else if (option == 2) {
    option = rand() % 2 + 1;
    if (option == 1){  // they one de
      p->takeDamage(damage/2);
    } else {
      //takeDamage(p->getDamage()/2);
    }
  }
  // if (p->getHealth() <= 0) {
  //   addKill();
  // }
  // if (getHealth() <= 0) {
  //   p->addKill();
  // }
}

void Person::counterAttack(Person* first,Person* second) {
  takeDamage(p->getDamage());
  // if (p->getHealth() <= 0) {
  //   addKill();
  // }
}

void Person::getHimSelf() {
  int option = rand() % 2 + 1;
  if (option == 1) {
    if (health < 100) {
      health += medicSkills;
    }
  } else if (option == 2) {
    delete(weapon);
    weapon = new Ak();
  }
}

Person::~Person()
{
  delete(weapon);
}
