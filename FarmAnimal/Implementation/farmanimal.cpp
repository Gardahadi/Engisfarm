#include "../Header/farmanimal.h"

int FarmAnimal::jumlah = 0;

//konstruktor FarmAnimal, mengeset hungry dan hasProduct menjadi false, living_time mejadi default, menambah static int jumlah
FarmAnimal::FarmAnimal(){
	hungry = true;
	hasProduct = false;
	living_time = default_living_time;
	hungry_time = default_hungry_time;
	jumlah++;
	hasMoved = false;
}

//destruktor FarmAnimal, mengurangi static int jumlah
FarmAnimal::~FarmAnimal(){
	jumlah--;
}
//prosedur makan mengembalikan living_time menjadi default dan hasProduct = true
void FarmAnimal::makan(){
	if (hungry){
		living_time = default_living_time;
		hasProduct = true;
		setHungry(false);
		hungry_time = default_hungry_time;
		
	}
}
//prosedur update dipanggil setiap tick
// void FarmAnimal::update(){
// 	if (hungry){
// 		living_time--;
// 		if (living_time == 0){
// 			cout << "Seekor animal telah pergi mencari makan di surga animal" << endl;
// 		}
// 		else
// 			Move();
// 	}
// }
//prosedur virtual void makeHungry
void FarmAnimal::setHungry(bool hungry){
	this->hungry = hungry;
}
//fungsi boolean isHungry mengembalikan true jika atribut hungry bernilai true
bool FarmAnimal::isHungry(){
	return hungry;
}
bool FarmAnimal::getMoved(){
	return hasMoved;
}
void FarmAnimal::setMoved(bool moved){
	hasMoved = moved;
}
void FarmAnimal::updateHungryTime(){
	if(!hungry){
		hungry_time--;
		if(hungry_time==0){
			hungry = true;
			living_time = default_living_time;
		}
	}
}

void FarmAnimal::updateLivingTime(){
	if(hungry){
		living_time--;
	}
}

int FarmAnimal::getLivingTime(){
	return living_time;
}

// bool FarmAnimal::is_safe_to_move(int x){
// 	List <int> around = LivingThings::lookAround();
// 	if ((around.getElmt(x)<=12)||(around.getElmt(x)>=19))
// 		return false;
// 	else
// 		return true;
	
// }
// void FarmAnimal::Move(){
// 	//membuat kandidat arah berisi 0,1,2,3
// 	List<int> direction_candidate;
// 	for (int i=0; i<4; i++){
// 		direction_candidate.add(i);
// 	} 
// 	//mencari arah random yang bisa dijalani
// 	int jlh_kandidat = 4;
// 	int idx = rand()%jlh_kandidat;
// 	int direction = direction_candidate.getElmt(idx); 
// 	bool found = is_safe_to_move(direction);
// 	while ((!found)&&(jlh_kandidat>0))
// 	{
// 		int *X;
// 		direction_candidate.removeAt(idx,X);
// 		jlh_kandidat--;

// 		idx = rand()%jlh_kandidat;
// 		direction = direction_candidate.getElmt(idx);
// 		found = is_safe_to_move(direction);
// 	}
// 	if (!found)
// 		direction = -1;

// 	//bergerak ke arah direction
// 	switch (direction){
// 		case 0: //utara
// 			int y = Renderables::getY();
// 			Renderables::setY(y-1);
// 			break;
// 		case 1: //timur
// 			int x = Renderables::getX();
// 			Renderables::setX(x+1);
// 			break;
// 		case 2: //selatan
// 			int y = Renderables::getY();
// 			Renderables::setY(y+1);
// 			break;
// 		case 3: //barat
// 			int x = Renderables::getX();
// 			Renderables::setX(x-1);
// 			break;
// 		default: //diam di tempat
// 			break;
// 	}
// }

//deklarasi fungsi pure virtual
bool FarmAnimal::isEgg(){
	return egg;
}
bool FarmAnimal::isMilk(){
	return milk;
}
bool FarmAnimal::isMeat(){
	return meat;
}
//fungsi static
int FarmAnimal::getJumlah(){
	return jumlah;
}
