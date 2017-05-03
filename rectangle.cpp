#include <cstdlib>
#include <ctime>
#include <iostream>
#include "rectangle.h"

using namespace std;

ostream& operator<<(ostream& os, const rectangle& a) {
	os << "Rectangle\nLeft X: " << a.leftX << "\nBottom Y: " << a.bottomY << "\nWidth: " << a.width << "\nHeight: " << a.height;
	return os;
}

rectangle::rectangle(){
	generateRandom();

}

rectangle::rectangle(int a, int b, int c, int d){
	leftX = a;
	bottomY = b;
	width = c;
	height = d;
}

void rectangle::generateRandom(){
	leftX = rand()%75;
	bottomY = rand()%75;
	width = rand()%30;
	height = rand()%30;
}
