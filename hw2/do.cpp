#include <iostream>
#include <unistd.h>
#include <cstring>
#include "queue.h"
#include "helper.h"

using namespace std;



int main (){
	int base[8][8] = {0};
	int startX = -1,startY = -1;
	while (startX<0||startY<0||startX>7||startY>7) {
	    cout << endl;
		cout << "Please input start x y(1~8):";
		cin >> startX >> startY;
		startX --;
		startY --;
	}
	cout << "OK, point start at （" << startX+1 << "," << startY+1 << ")."<< endl;
	cout << "Now, start step after 2 seconds" << endl;
	//sleep(2); 
	Queue q;
	base[startX][startY] = 1;
	q.push(base, 1, startX, startY);


	for(;;) {
	    if (q.empty()) break;
	    Node* a = q.front();
	    int (*da)[8] = a->data;
	    int cur = a->current; 
	    int x = a->curX;
	    int y = a->curY;
	    if (cur == 64)print(da, cur);
	    if (x+1<8&&y+2<8&&da[x+1][y+2]==0) {
		int (*newMap)[8] = new int[8][8];
		memcpy(newMap, da, sizeof(int)*64);
		newMap[x+1][y+2] = cur+1;
		q.push(newMap, cur+1, x+1, y+2);
	    }

	    if (x+1<8&&y-2>0&&da[x+1][y-2]==0) {
		int (*newMap)[8] = new int[8][8];
		memcpy(newMap, da, sizeof(int)*64);
		newMap[x+1][y-2] = cur+1;
		q.push(newMap, cur+1, x+1, y-2);
	    }
	    if (x-1>0&&y+2<8&&da[x-1][y+2]==0) {
		int (*newMap)[8] = new int[8][8];
		memcpy(newMap, da, sizeof(int)*64);
		newMap[x-1][y+2] = cur+1;
		q.push(newMap, cur+1, x-1, y+2);
	    }
	    if (x-1>0&&y-2>0&&da[x-1][y-2]==0) {
		int (*newMap)[8] = new int[8][8];
		memcpy(newMap, da, sizeof(int)*64);
		newMap[x-1][y-2] = cur+1;
		q.push(newMap, cur+1, x-1, y-2);
	    }
	    if (x+2<8&&y+1<8&&da[x+2][y+1]==0) {
		int (*newMap)[8] = new int[8][8];
		memcpy(newMap, da, sizeof(int)*64);
		newMap[x+2][y+1] = cur+1;
		q.push(newMap, cur+1, x+2, y+1);
	    }
	    if (x+2<8&&y-1>0&&da[x+2][y-1]==0) {
		int (*newMap)[8] = new int[8][8];
		memcpy(newMap, da, sizeof(int)*64);
		newMap[x+2][y-1] = cur+1;
		q.push(newMap, cur+1, x+2, y-1);
	    }
	    if (x-2>0&&y+1<8&&da[x-2][y+1]==0) {
		int (*newMap)[8] = new int[8][8];
		memcpy(newMap, da, sizeof(int)*64);
		newMap[x-2][y+1] = cur+1;
		q.push(newMap, cur+1, x-2, y+1);
	    }
	    if (x-2>0&&y-1>0&&da[x-2][y-1]==0) {
		int (*newMap)[8] = new int[8][8];
		memcpy(newMap, da, sizeof(int)*64);
		newMap[x-2][y-1] = cur+1;
		q.push(newMap, cur+1, x-2, y-1);
	    }
	    q.pop();
	    //usleep(200);
	}

    return 0;
}

