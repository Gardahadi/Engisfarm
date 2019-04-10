#include "../Header/platypus.h"

Platypus::Platypus(){
	FarmAnimal::egg = true;
	FarmAnimal::milk = true;
	FarmAnimal::meat = false;
}

//prosedur Bersuara menuliskan suara Platypus ke layar
string Platypus::bersuara(){
	return "krrrrrrr...";
}
FarmProduct Platypus::getProduct(bool isKill){
	if (isKill){
		throw "kamu tidak boleh membunuh seekor platypus";
	}
	else
	{
		if (hasProduct){
			hasProduct = false;
			int x = rand() % 2;
			if (x == 0){
				PlatypusMilk milk;
				return milk;
			}
			else{
				PlatypusEgg egg;
				return egg;
			}
		}
		else{
			throw "Platypus ini tidak mempunyai produk saat ini";
		}
	}
}
int Platypus::getId(){
	if (hungry)
		return 9;
	else
	{
		return 10;
	}
	
}