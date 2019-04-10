// File: goldenplatypus.h
#ifndef goldenplatypus_H
#define goldenplatypus_H

#include "../../Product/Header/platypusegg.h"
#include "../../Product/Header/platypusmilk.h"
#include "../../Product/Header/farmproduct.h"
#include "farmanimal.h"

class GoldenPlatypus : public FarmAnimal{
public:
	//konstruktor mengeset atribut hungry menjadi false dan living_time menjadi default
	GoldenPlatypus();
	//prosedur Bersuara menuliskan suara GoldenPlatypus ke layar
	string bersuara();
	FarmProduct getProduct(bool);
	int getId();
};

#endif
