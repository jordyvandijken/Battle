#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>

#include "weapons.h"

class Person {
  public:
    Person();
    ~Person();
    char getHealth();
    char getDamage();
    char getDamage(std::string m);
    char getMedicSkills();
    char getFightingSkills();
    char getKills();
    std::string getName();
    Weapon* getWeapon();
    void addKill();
    void takeDamage(char _damage);
    void attack(Person* first,Person* second);
    void attackPerson(Person* first,Person* second);
    void attackSameFightingSkills(Person* first,Person* second);
    void counterAttack(Person* first,Person* second);
    void getHimSelf();

  private:
    std::string name;
    std::string gender;
    char health;
    char damage;
    char medicSkills;
    char fightingSkills;
    char kills;
    char armor;
    Weapon* weapon;
};

#endif
