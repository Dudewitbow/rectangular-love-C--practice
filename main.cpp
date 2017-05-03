#include <iostream>
#include <cstdlib>
#include <ctime>
#include "rectangle.h"
using namespace std;

void calculateIntersection(rectangle a, rectangle b);

int main() {
	srand(time(0));
	for(int i = 0; i < 3; i++){
		rectangle one;
		rectangle two;
		calculateIntersection(one,two);
	}
	return 0;
}

void calculateIntersection(rectangle a, rectangle b) {
	cout << "#############################################\n\n";
	cout << a << "\n\n" << b << "\n\n";
	rectangle c;

	if (b.leftX < a.leftX) {
		swap(a, b);
	}

	int aRightX = a.leftX + a.width - 1;
	int bRightX = b.leftX + b.width - 1;

	if (b.leftX > aRightX) {
		cout << "Rectangles do not intersect\n\n";
		return; //b.leftX is greater than the far right boundary, so cannot intersect, less than is taken care of since the beginning
	}

	else {
		//b.left is within boundary, test vertical
		int aTopY = a.bottomY + a.height - 1;
		int bTopY =  b.bottomY + b.height - 1;
		c.leftX = b.leftX; //for sure established value

		if(bTopY <= aTopY && a.bottomY <= bTopY){
			//Btop is within bounds of A
			if(b.bottomY <= aTopY && a.bottomY <= b.bottomY){
				//bottom is also within bounds generate C
				c.bottomY = b.bottomY;
				c.height = b.height;
				if(bRightX < aRightX){
					c.width = bRightX - c.leftX + 1;
				}
				else{
					c.width = aRightX - c.leftX + 1;
				}
			}
			else{
				//bottom is not in bounds of A, but top is, generate C
				c.bottomY = a.bottomY;
				c.height = bTopY - a.bottomY + 1; //height is from abottom to btop
				if(bRightX < aRightX){
					c.width = bRightX - c.leftX + 1;
				}
				else{
					c.width = aRightX - c.leftX + 1;
				}
			}
		}
		else if(b.bottomY <= aTopY && a.bottomY <= b.bottomY){
			//top is not in bound but bottom is, generate C
			c.bottomY = b.bottomY;
			c.height = aTopY - b.bottomY + 1;
			if(bRightX < aRightX){
				c.width = bRightX - c.leftX + 1;
			}
			else{
				c.width = aRightX - c.leftX + 1;
			}
		}
		else{
			cout << "Rectangles do not intersect\n\n";
			return;
		}
		cout << "The intersecting rectangle is:\n" << c << endl << endl;
}

return;
}
