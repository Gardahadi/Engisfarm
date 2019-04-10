//File: truck.h

#ifndef truck_H
#define truck_H
#include "facility.h"

#define MAXREADY 5

//Truck merupakan turunan dari class Facility

class Truck : public Facility{
public:
    Truck();
    void setNotReady();
    int render(); //mengembalikan char yang akan diprint pada map
    bool isAvailable(); //mengembalikan true jika truck bisa dipakai
    //Untuk update keadaan truck
    void updateCell(UpdateType); 
    void interactCell();

private:
    int ready; //melambangkan seberapa lama lagi hingga truck bisa dipakai
};
#endif
