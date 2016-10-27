#include "weapon.h"


Weapon::Weapon(){
  weaponName = "none";
  min_Damage = 0;
  max_Damage = 0;
  //std::string names[7] = {"fist","revolver","ak-47","bat","knive","p90","bow"};
  //std::vector<int> w_min_damage = {2,15,30,10,15,25,20};
  //std::vector<int> w_max_damage = {30,40,90,35,40,75,70};
}

void Weapon::setName(std::string name) {
  weaponName = name;
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

int Weapon::getWeaponMinDamage(){
  return min_Damage;
}

int Weapon::getWeaponMaxDamage(){
  return max_Damage;
}

Weapon::~Weapon(){

}
