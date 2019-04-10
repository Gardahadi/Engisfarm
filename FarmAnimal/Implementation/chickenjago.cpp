#include "../Header/chickenjago.h"

//konstruktor mengeset atribut hungry menjadi false dan living_time menjadi default
ChickenJago::ChickenJago(){
	FarmAnimal::egg = false;
	FarmAnimal::milk = false;
	FarmAnimal::meat = true;
}
//prosedur Bersuara menuliskan suara ChickenJago ke layar
string ChickenJago::bersuara(){
	return "kukuruyuuuuuk";
}
FarmProduct ChickenJago::getProduct(bool isKill){
	if (isKill){
		ChickenMeat meat;
		return meat;
	}
	else
		throw "ChickenJago tidak memiliki telur";
	
}
int ChickenJago::getId(){
	if (hungry){
		return 3;
	}
	else{
		return 4;
	}
}