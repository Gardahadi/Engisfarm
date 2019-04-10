// File: cow.h
#ifndef cow_H
#define cow_H

#include "farmanimal.h"
#include "../../Product/Header/cowmilk.h"
#include "../../Product/Header/cowmeat.h"

class Cow : public FarmAnimal{
public:
	//konstruktor mengeset atribut hungry menjadi false dan living_time menjadi default
	Cow();
	//prosedur Bersuara menuliskan suara Cow ke layar
	string bersuara();
	FarmProduct getProduct(bool);
	FarmProduct kill();
	int getId();
};

#endif
