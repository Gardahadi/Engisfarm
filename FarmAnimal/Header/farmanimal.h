// File: farmanimal.h
#ifndef FARMANIMAL_H
#define FARMANIMAL_H

#include "../../Product/Header/farmproduct.h"
#include <iostream>
#include <cstdlib>
#include <cstring>

#define default_living_time 5
#define default_hungry_time 5

using namespace std;

class FarmAnimal {
protected://knpa nda private?
	bool hungry; //variabel penanda bahwa hewan lapar
	bool egg; //menandakan jenis hewan penghasil telur
	bool milk; //menandakan jenis hewan penghasil susu
	bool meat; //menandakan jenis hewan penghasil daging
	int hungry_time;//variabel penanda tick yang dimiliki sebelum hewan hungry
	int living_time; //variabel penanda tick yang dimiliki sebelum hewan mati kelaparan
	bool hasProduct; // Animal sudah siap untuk product atau belum
	bool hasMoved;
	static int jumlah;
public:
	//konstruktor FarmAnimal, mengeset hungry dan hasProduct menjadi false, living_time mejadi default, menambah static int jumlah
	FarmAnimal();
	//destruktor FarmAnimal, mengurangi statis int jumlah
	~FarmAnimal();
	//prosedur makan mengembalikan living_time menjadi default
	void makan();
	//prosedur update dipanggil setiap tick
	// void update();
	//prosedur virtual void setHungry
	void setHungry(bool);
	//fungsi boolean isHungry mengembalikan true jika atribut hungry bernilai true
	bool isHungry();
	bool getMoved();
	void setMoved(bool moved);
	//prosedur update hungry time
	void updateHungryTime();
	//prosedur update living time
	void updateLivingTime();
	//prosedur get living time
	int getLivingTime();
	//deklarasi fungsi pure virtual
	virtual string bersuara() = 0;
	//prosedur move animal
	// bool is_safe_to_move(int);
	// void move();
	bool isEgg();
	bool isMilk();
	bool isMeat();
	virtual FarmProduct getProduct(bool) = 0;
	static int getJumlah();
	virtual int getId() = 0;
};

#endif