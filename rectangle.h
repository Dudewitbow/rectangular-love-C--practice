#ifndef RECTANGLE_H_
#define RECTANGLE_H_
#include <iostream>
using namespace std;

class rectangle{
	friend ostream& operator<< (ostream& os, const rectangle&);
public:
	int leftX;
	int bottomY;

	int width;
	int height;

public:
	rectangle();
	rectangle(int, int, int, int);
	void generateRandom();
};




#endif
