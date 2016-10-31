#include <cstdio>

#ifndef QUEUE_H
#define QUEUE_H

struct Node  
{  
    Node *next;  
    int current;
    int curX,curY;
    int (*data)[8];
};
  
class Queue  
{  
public:  
    Queue()  
    {  
        Node *node = new Node;  
        node->data = NULL;  
        node->next = NULL;
	node->curX = -1;
	node->curY = -1;
        node->current = -1;  
        qfront = qrear = node;  
    }  

    bool empty() const;  
    void pop();  
    Node*  front();  
    Node*  back();
    void push(int (*)[8], int, int, int);
    int size() const;  
private:  
    Node *qfront,*qrear;  
};  
#endif
