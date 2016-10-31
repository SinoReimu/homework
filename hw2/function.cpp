#include <unistd.h>
#include <stdlib.h>
#include <cstring>
#include <iostream>
#include "includes/function.h"
#include "includes/stack.h"
#include "includes/helper.h"

using namespace std;
struct newNode {
    int x,y;
    int (*data)[8];
};

void exit (int startX, int startY, int (*base)[8]) {
	exit(0);
}

int getAccessiableNodeCount (int (*da)[8], int x, int y) {
	int count = 0;
	if (x+1<8&&y+2<8&&da[x+1][y+2]==0) count++;
	if (x-1>=0&&y+2<8&&da[x-1][y+2]==0) count++;
	if (x+1<8&&y-2>=0&&da[x+1][y-2]==0) count++;
	if (x-1>=0&&y-2>=0&&da[x-1][y-2]==0) count++;
	if (x+2<8&&y+1<8&&da[x+2][y+1]==0) count++;
	if (x-2>=0&&y+1<8&&da[x-2][y+1]==0) count++;
	if (x+2<8&&y-1>=0&&da[x+2][y-1]==0) count++;
	if (x-2>=0&&y-1>=0&&da[x-2][y-1]==0) count++;
	return count;
}
	
void greedBackUp (int startX, int startY, int (*base)[8], int speed) {
	int count = 0;
	Queue q;
	base[startX][startY] = 1;
	q.push(base, 1, startX, startY);

	for(;;) {
	    count ++;
	    newNode* (*list) = new newNode*[8];
	    int index = 0;
	    if (q.empty()) break;
	    Node* a = q.front();
	    q.pop();
	    int (*da)[8] = a->data;
	    int cur = a->current; 
	    int x = a->curX;
	    int y = a->curY;
	    print(da, cur);
	    cout << "total use: " << count << " steps." << endl;
	    if(cur == 64) pause();
	    
	    if (x+1<8&&y+2<8&&da[x+1][y+2]==0) {newNode* n = new newNode;int (*newMap)[8] = new int[8][8];memcpy(newMap, da, sizeof(int)*64);newMap[x+1][y+2] = cur+1;n->x=x+1;n->y=y+2;n->data=newMap;list[index]=n;index++;}
	    if (x-1>=0&&y+2<8&&da[x-1][y+2]==0) {newNode* n = new newNode;int (*newMap)[8] = new int[8][8];memcpy(newMap, da, sizeof(int)*64);newMap[x-1][y+2] = cur+1;n->x=x-1;n->y=y+2;n->data=newMap;list[index]=n;index++;}
	    if (x+1<8&&y-2>=0&&da[x+1][y-2]==0) {newNode* n = new newNode;int (*newMap)[8] = new int[8][8];memcpy(newMap, da, sizeof(int)*64);newMap[x+1][y-2] = cur+1;n->x=x+1;n->y=y-2;n->data=newMap;list[index]=n;index++;}
	    if (x-1>=0&&y-2>=0&&da[x-1][y-2]==0) {newNode* n = new newNode;int (*newMap)[8] = new int[8][8];memcpy(newMap, da, sizeof(int)*64);newMap[x-1][y-2] = cur+1;n->x=x-1;n->y=y-2;n->data=newMap;list[index]=n;index++;}
	    if (x+2<8&&y+1<8&&da[x+2][y+1]==0) {newNode* n = new newNode;int (*newMap)[8] = new int[8][8];memcpy(newMap, da, sizeof(int)*64);newMap[x+2][y+1] = cur+1;n->x=x+2;n->y=y+1;n->data=newMap;list[index]=n;index++;}
  	    if (x-2>=0&&y+1<8&&da[x-2][y+1]==0) {newNode* n = new newNode;int (*newMap)[8] = new int[8][8];memcpy(newMap, da, sizeof(int)*64);newMap[x-2][y+1] = cur+1;n->x=x-2;n->y=y+1;n->data=newMap;list[index]=n;index++;}
	    if (x+2<8&&y-1>=0&&da[x+2][y-1]==0) {newNode* n = new newNode;int (*newMap)[8] = new int[8][8];memcpy(newMap, da, sizeof(int)*64);newMap[x+2][y-1] = cur+1;n->x=x+2;n->y=y-1;n->data=newMap;list[index]=n;index++;}
	    if (x-2>=0&&y-1>=0&&da[x-2][y-1]==0)  {newNode* n = new newNode;int (*newMap)[8] = new int[8][8];memcpy(newMap, da, sizeof(int)*64);newMap[x-2][y-1] = cur+1;n->x=x-2;n->y=y-1;n->data=newMap;list[index]=n;index++;}
	    newNode *temp;
	    for (int i=0;i<index;i++) 
		for (int j=i+1;j<index;j++) {
			if (getAccessiableNodeCount(list[i]->data, list[i]->x, list[i]->y) < getAccessiableNodeCount(list[j]->data, list[j]->x, list[j]->y)) {
				temp = list[i];
				list[i] = list[j];
				list[j] = temp;
			}
		}
	    for (int i=0;i<index;i++) {
		newNode * l = list[i];
		q.push(l->data, cur+1, l->x, l->y);
	    }
            sleep(speed);
	}
}

void greedBackUpSlow (int startX, int startY, int (*base)[8]) {
	greedBackUp(startX, startY, base, 1);
}

void greedBackUpFast (int startX, int startY, int (*base)[8]) {
	greedBackUp(startX, startY, base, 0);
}

void baseBackUp (int startX, int startY, int (*base)[8], int speed) {
	int count;
	Queue q;
	base[startX][startY] = 1;
	q.push(base, 1, startX, startY);

	for(;;) {
	    count ++;
	    if (q.empty()) break;
	    Node* a = q.front();
	    q.pop();
	    int (*da)[8] = a->data;
	    int cur = a->current; 
	    int x = a->curX;
	    int y = a->curY;
	    print(da, cur);
	    cout << "total use	: " << count << " steps" << endl; 
	    if(cur == 64) pause();
	    if (x+1<8&&y+2<8&&da[x+1][y+2]==0) {
		int (*newMap)[8] = new int[8][8];
		memcpy(newMap, da, sizeof(int)*64);
		newMap[x+1][y+2] = cur+1;
		q.push(newMap, cur+1, x+1, y+2);
	    }

	    if (x+1<8&&y-2>=0&&da[x+1][y-2]==0) {
		int (*newMap)[8] = new int[8][8];
		memcpy(newMap, da, sizeof(int)*64);
		newMap[x+1][y-2] = cur+1;
		q.push(newMap, cur+1, x+1, y-2);
	    }
	    if (x-1>=0&&y+2<8&&da[x-1][y+2]==0) {
		int (*newMap)[8] = new int[8][8];
		memcpy(newMap, da, sizeof(int)*64);
		newMap[x-1][y+2] = cur+1;
		q.push(newMap, cur+1, x-1, y+2);
	    }
	    if (x-1>=0&&y-2>=0&&da[x-1][y-2]==0) {
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
	    if (x+2<8&&y-1>=0&&da[x+2][y-1]==0) {
		int (*newMap)[8] = new int[8][8];
		memcpy(newMap, da, sizeof(int)*64);
		newMap[x+2][y-1] = cur+1;
		q.push(newMap, cur+1, x+2, y-1);
	    }
	    if (x-2>=0&&y+1<8&&da[x-2][y+1]==0) {
		int (*newMap)[8] = new int[8][8];
		memcpy(newMap, da, sizeof(int)*64);
		newMap[x-2][y+1] = cur+1;
		q.push(newMap, cur+1, x-2, y+1);
	    }
	    if (x-2>=0&&y-1>=0&&da[x-2][y-1]==0) {
		int (*newMap)[8] = new int[8][8];
		memcpy(newMap, da, sizeof(int)*64);
		newMap[x-2][y-1] = cur+1;
		q.push(newMap, cur+1, x-2, y-1);
	    }
	    sleep(speed);
	}
}

void baseBackUpSlow (int startX, int startY, int (*base)[8]) {
	baseBackUp(startX, startY, base, 1);
}

void baseBackUpFast (int startX, int startY, int (*base)[8]) {
	baseBackUp(startX, startY, base, 0);
}
