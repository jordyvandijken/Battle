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
    Person(std::string customName, int _health, int _damage, int _type);
    ~Person();
    int getHealth();
    int getDamage();
    int getDamage(std::string m);
    int getMedicSkills();
    int getFightingSkills();
    int getKills();
    std::string getName();
    std::string getGender();
    Weapon* getWeapon();
    void addKill();
    void takeDamage(int _damage);
    void attack(Person* first,Person* second);
    void attackPerson(Person* first,Person* second);
    void attackSameFightingSkills(Person* first,Person* second);
    void counterAttack(Person* first,Person* second);
    void getHimSelf();
    void stealWeapon(Person* alive,Person* dead);
    void setweapon(Weapon* wep);
    void weapons(int option);

  private:
    std::string name;
    std::string gender;
    int health;
    int damage;
    int medicSkills;
    int fightingSkills;
    int kills;
    int armor;
    Weapon* weapon;
};

#endif
