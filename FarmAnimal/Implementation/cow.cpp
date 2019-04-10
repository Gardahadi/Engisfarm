#include "../Header/cow.h"

Cow::Cow(){
	FarmAnimal::egg = false;
	FarmAnimal::milk = true;
	FarmAnimal::meat = true;
}

//prosedur Bersuara menuliskan suara Cow ke layar
string Cow::bersuara(){
	return "Moooo...";
}

FarmProduct Cow::getProduct(bool isKill){
	if (isKill){
		CowMeat meat;
		return meat;
	}
	else{
		if (hasProduct)
		{
			hasProduct = false;
			CowMilk milk;
			return milk;
		}
		else{
			throw "Sapi ini tidak mempunyai produk saat ini";
		}
	}
}
int Cow::getId(){
	if (hungry)
		return 5;
	else
	{
		return 6;
	}
	
}