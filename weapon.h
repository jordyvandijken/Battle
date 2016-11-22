#ifndef WEAPON_H
#define WEAPON_H

#include <string>
#include <iostream>
#include <vector>

class Weapon
{
public:
	Weapon();
	virtual ~Weapon();
	void setName(std::string name);
	void setNum(int num);
	void setMinDamage(int miD);
	void setMaxDamage(int maD);
	std::string getWeaponName();
 	int getWeaponDamage();
	int getWeaponMinDamage();
	int getWeaponMaxDamage();
	int getAverageDamage();
	int getNum();

private:
	int min_Damage;
	int max_Damage;
	int weaponNum;
	std::string weaponName;

};

#endif
