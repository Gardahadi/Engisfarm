#include "../Header/chickenkampung.h"

ChickenKampung::ChickenKampung(){
	FarmAnimal::egg = true;
	FarmAnimal::milk = false;
	FarmAnimal::meat = true;
}
string ChickenKampung::bersuara(){
	return "pok pok petoook";
}
FarmProduct ChickenKampung::getProduct(bool isKill){
	if (isKill){
		ChickenMeat meat;
		return meat;
	}
	else{
		if (hasProduct){
			ChickenEgg egg;
			hasProduct = false;
			return egg;
		}
		else
			throw "ayam kampung ini tidak memiliki produk saat ini";
	}
}
int ChickenKampung::getId(){
	if (hungry)
		return 1;
	else
		return 2;
	
}