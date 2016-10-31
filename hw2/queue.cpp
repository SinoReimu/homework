#include "queue.h"
#include <iostream>
using namespace std;
Node* Queue::back()  
{  
    if(!empty())  
        return qrear;  
}  

Node* Queue::front()  
{  
    if(!empty())  
    {  
        Node *p=qfront->next;  
        return p;  
    }else return NULL;
}  
  
bool Queue::empty() const  
{  
    if(qfront==qrear)  
        return true;  
    else  
        return false;  
}  

void Queue::pop()  
{  
    if(!empty())  
    {  
        Node *p=qfront->next;  
        qfront->next=p->next;  
        if(p==qrear)  
            qrear=qfront;  
        delete p;  
        p=NULL;  
  
    }  
}  

void Queue::push(int (*t)[8], int cur, int curX, int curY)  
{  
    Node *node=new Node;  
    node->data=t;
    node->curX=curX;
    node->curY=curY;
	node->current=cur;
    node->next=NULL;  
    qrear->next=node;  
    qrear=node;  
}  

int Queue::size() const  
{  
    Node *p=qfront;  
    if(empty())  
        return 0;  
    else  
    {  
        int i=1;  
        while(p->next!=qrear)  
        {  
            p=p->next;  
            i++;  
        }  
        return i;  
    }  
}  
