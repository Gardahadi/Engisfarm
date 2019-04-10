#include "../Header/bull.h"


//konstruktor mengeset atribut hungry menjadi false dan living_time menjadi default
Bull::Bull(){
	FarmAnimal::egg = false;
	FarmAnimal::milk = false;
	FarmAnimal::meat = true;
}
//prosedur Bersuara menuliskan suara Bull ke layar
string Bull::bersuara(){
	return "(Manly) Moooo...";
}
FarmProduct Bull::getProduct(bool isKill){
	if (isKill){
		CowMeat meat;
		return meat;
	}
	else
		throw "Bull tidak memiliki susu";
	
}
int Bull::getId(){
	if (hungry)
		return 11;
	else
		return 12;
	
}