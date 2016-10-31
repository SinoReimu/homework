#include <iostream>
#include <unistd.h>

#include "includes/stack.h"
#include "includes/helper.h"
#include "includes/function.h"

using namespace std;

function f[] = {baseBackUpSlow, baseBackUpFast, greedBackUpSlow, greedBackUpFast, exit}; //use python thread to set function list

int main () {
	int base[8][8] = {0};
	int startX = -1,startY = -1;
	int way;

	while (startX<0||startY<0||startX>7||startY>7) {
	    cout << endl;
		cout << "Please input start x y(1~8):";
		cin >> startX >> startY;
		startX --;
		startY --;
	}
	cout << "OK, point start at （" << startX+1 << "," << startY+1 << ")."<< endl;
	cout << "Please select a way to search :\n1)Base backup slow\n2)Base backup fast\n3)Greedy way to search backup slow\n4)Greedy way to search backup fast\n5)exit"<<endl;
	cin >> way;
	cout << "Now, start step after 2 seconds" << endl;
	sleep(2); 
	f[way-1](startX, startY, base);
    return 0;
}


