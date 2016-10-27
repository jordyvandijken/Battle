#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>

class Person {
  public:
    Person();
    ~Person();
    int getHealth();
    int getDamage();
    int getMedicSkills();
    int getFightingSkills();
    int getKills();
    std::string getName();
    void addKill();
    void takeDamage(int _damage);
    void attack(Person* p);
    void attackPerson(Person* p);
    void attackSameFightingSkills(Person* p);
    void counterAttack(Person* p);
    void getHimSelf();

  private:
    std::string name;
    std::string gender;
    int health;
    int damage;
    int medicSkills;
    int fightingSkills;
    int kills;
    int armor;
};

#endif
