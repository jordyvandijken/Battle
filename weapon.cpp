#include "weapon.h"


Weapon::Weapon(){
  weaponName = "none";
  min_Damage = 0;
  max_Damage = 0;
  weaponNum = 0;
}

void Weapon::setName(std::string name) {
  weaponName = name;
}

void Weapon::setNum(int num) {
  weaponNum = num;
}

void Weapon::setMinDamage(int miD) {
  min_Damage = miD;
}

void Weapon::setMaxDamage(int maD) {
  max_Damage = maD;
}

std::string Weapon::getWeaponName() {
  return weaponName;
}

int Weapon::getWeaponDamage() {
  return (rand() % (max_Damage - min_Damage) + min_Damage);
}

int Weapon::getAverageDamage(){
  return ((max_Damage + min_Damage) / 2);
}

int Weapon::getWeaponMinDamage(){
  return min_Damage;
}

int Weapon::getWeaponMaxDamage(){
  return max_Damage;
}

int Weapon::getNum() {
  return weaponNum;
}

Weapon::~Weapon(){

}
