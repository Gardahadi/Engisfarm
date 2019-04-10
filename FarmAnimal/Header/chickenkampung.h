// File: chickenkampung.h
#ifndef chickenkampung_H
#define chickenkampung_H

#include "farmanimal.h"
#include "../../Product/Header/chickenegg.h"
#include "../../Product/Header/chickenmeat.h"

class ChickenKampung : public FarmAnimal{
public:
	//konstruktor mengeset atribut hungry menjadi false dan living_time menjadi default
	ChickenKampung();
	//prosedur Bersuara menuliskan suara ChickenKampung ke layar
	string bersuara();
	FarmProduct getProduct(bool);
	FarmProduct kill();
	int getId();
};

#endif
