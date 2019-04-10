// File: chickenjago.h
#ifndef chickenjago_H
#define chickenjago_H

#include "farmanimal.h"
#include "../../Product/Header/chickenmeat.h"

class ChickenJago : public FarmAnimal{
public:
	//konstruktor mengeset atribut hungry menjadi false dan living_time menjadi default
	ChickenJago();
	//prosedur Bersuara menuliskan suara ChickenJago ke layar
	string bersuara();
	FarmProduct kill();
	FarmProduct getProduct(bool);
	int getId();
};

#endif
