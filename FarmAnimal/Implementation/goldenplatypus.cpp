#include "../Header/goldenplatypus.h"

GoldenPlatypus::GoldenPlatypus(){
	FarmAnimal::egg = true;
	FarmAnimal::milk = true;
	FarmAnimal::meat = false;
}

//prosedur Bersuara menuliskan suara GoldenPlatypus ke layar
string GoldenPlatypus::bersuara(){
	return "krrrrrrr...";
}
FarmProduct GoldenPlatypus::getProduct(bool isKill){
	if (isKill){
		throw "kamu tidak boleh membunuh seekor platypus";
	}
	else{
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
			throw "GoldenPlatypus ini tidak mempunyai produk saat ini";
		}
	}
}
int GoldenPlatypus::getId(){
	if (hungry)
		return 7;
	else
	{
		return 8;
	}
}