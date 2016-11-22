#include "person.h"

Person::Person() {
  srand (time(NULL));
  std::string genderS[4] = {"male","female","apache helicopter","non-binary"};
  std::string namePartsStart[49] = {"jordy","corne","lars","dern","andy","jeffery","teis","nino","bobby","gidi","robin","john","peter","frank","johan","roy","rolf","kevin","roan","jasper","owen","neill","max","jason","jesse","dylan","omar","yochem","daan","stein","beau","sam","peter","jorn","harry","daniel","wouter","glen","bo","dennis","tobias","noud","rick","tim","james","vince","rob","anjo","maik"};
  std::string namePartsEnd[26] = {" van dijken"," steenhuis"," werther"," Alfrink"," andriessen"," holdenburg"," hogeveen"," plop"," snow"," van liempd","baker","howard","rhine","livingstone","land","turner","dare","parker","neville","conley","king","bond","adems","chapman","jackson","lichtenlamp"};
  gender = genderS[rand() % 2];
  name = (namePartsStart[(rand() % 48)] + namePartsEnd[(rand() % 10)]);
  health = rand() % 75 + 26;
  damage = rand() % 28 + 3;
  medicSkills = rand() % 25 + 1;
  fightingSkills = rand() % 60 + 11;
  armor = 10;
  kills = 0;
  weapon = new Fist();
}

Person::Person(std::string customName, int _health, int _damage, int _type) {
  srand (time(NULL));
  std::string genderS[4] = {"male","female","apache helicopter","non-binary"};
  gender = genderS[_type];
  name = customName;
  health = _health;
  damage = _damage;
  medicSkills = rand() % 25 + 1;
  fightingSkills = rand() % 60 + 11;
  armor = 10;
  kills = 0;
  weapon = new Fist();
}

std::string Person::getName() {
  return name;
}

std::string Person::getGender() {
  return gender;
}

// get amount of health
int Person::getHealth() {
  return health;
}

// get amount of damage
int Person::getDamage() {
  return damage + weapon->getWeaponDamage();
}

// get min and max damage
int Person::getDamage(std::string m) {
  if (m == "min") {
    return damage + weapon->getWeaponMinDamage();
  } else if (m == "max") {
    return damage + weapon->getWeaponMaxDamage();
  }
  return 255;
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

// get weapon of person
Weapon* Person::getWeapon() {
  return weapon;
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
void Person::attack(Person* first,Person* second) {
  // attack person if fightingSkills is higher
  if (second->getFightingSkills() < fightingSkills) {
    attackPerson(first,second);
  // the other person has the same fightingSkills
  } else if (second->getFightingSkills() == getFightingSkills()) { // they are equal in fightingSkills
    attackSameFightingSkills(first,second);
  // the other person has a higher fightingSkill
  } else {
    second->attackPerson(second,first);
  }
}

void Person::attackPerson(Person* attacker,Person* victim) {
  victim->takeDamage(getDamage());
  if (victim->getHealth() <= 0) { // add the kill if he is dead
    attacker->addKill();
    attacker->stealWeapon(attacker,victim);
  }
}

void Person::attackSameFightingSkills(Person* attacker,Person* victim) {
  int option = rand() % 2 + 1;
  if (option == 1) { // they both get damage
    victim->takeDamage(damage);
    victim->attackPerson(attacker,victim);
  } else if (option == 2) {
    option = rand() % 2 + 1;
    if (option == 1){
      victim->takeDamage(damage);
    } else {
      victim->attackPerson(victim,attacker);
    }
  }
  if (victim->getHealth() <= 0) {
    attacker->addKill();
    attacker->stealWeapon(attacker,victim);
  }
  if (attacker->getHealth() <= 0) {
    victim->addKill();
    victim->stealWeapon(victim,attacker);
  }
}

void Person::counterAttack(Person* first,Person* second) {
  // the second person counterAttacks
  second->attackPerson(second,first);
  if (second->getHealth() <= 0) {
    addKill();
  }
}

void Person::getHimSelf() {
  int option = rand() % 100 + 1;
  if (option < 75) {
    if (health < 100) {
      health += medicSkills;
    }
  } else if (option >= 75) {
    weapons(rand() % 5 + 1);
  }
}

void Person::stealWeapon(Person* alive,Person* dead) {
  if (alive->getWeapon()->getAverageDamage() < dead->getWeapon()->getAverageDamage()){
    alive->weapons(dead->getWeapon()->getNum());
  }
}

void Person::setweapon(Weapon* wep = new Fist()) {
  delete weapon;
  weapon = wep;
}

void Person::weapons(int option) {
  Weapon* ak = new Ak();
  Weapon* awp = new Awp();
  Weapon* bow = new Bow();
  Weapon* famas = new Famas();
  Weapon* revolver = new Revolver();
  Weapon* sillneedone = new Awp();

  if (option == 1 && weapon->getAverageDamage() < ak->getAverageDamage()) {
    setweapon(new Ak());
    return;
  } else if (option == 2 && weapon->getAverageDamage() < awp->getAverageDamage()) {
    setweapon(new Awp());
    return;
  } else if (option == 3 && weapon->getAverageDamage() < bow->getAverageDamage()) {
    setweapon(new Bow());
    return;
  } else if (option == 4 && weapon->getAverageDamage() < famas->getAverageDamage()) {
    setweapon(new Famas());
    return;
  } else if (option == 5 && weapon->getAverageDamage() < revolver->getAverageDamage()) {
    setweapon(new Revolver());
    return;
  } else if (option == 6 && weapon->getAverageDamage() < famas->getAverageDamage()) {
    delete weapon;
    weapon = new Awp();
    return;
  }

  delete ak;
  delete awp;
  delete bow;
  delete famas;
  delete revolver;
  delete sillneedone;
}

Person::~Person()
{
  delete weapon;
}
