#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <iomanip>
#include <unistd.h>
#include "includes/helper.h"

using namespace std;

void print(int map[][8], int current) {  
    system("clear");
    cout.setf(ios::left);
    for (int i=0; i<8; i++) {
	for (int j=0; j<8; j++) {
	    int number = map[i][j];
	    if (number == 0)
		printf("\033[44;36m%-3d\033[0m", number);
	    else if (number == current)
		printf("\033[41;36m%-3d\033[0m", number);
	    else 
		printf("\033[42;36m%-3d\033[0m", number);
	}	
	cout << endl;
    }
}  
