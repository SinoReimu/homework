#include <cstdio>

#ifndef Stack_H
#define Stack_H

template<class T>
struct Node
{  
    Node<T> *next;  
    T c;
};
 
template<class T>
class Stack  
{  
public:  
    Stack<T>()  
    {  
        Node<T> *node = new Node<T>;    
        node->next = NULL;
        node->c = 0;  
        qfront = qrear = node;  
    }  

    bool empty() const;  
    void pop();  
    Node<T>*  front();  
    Node<T>*  back();
    void push(T);
    int size() const;  
private:  
    Node<T> *qfront,*qrear;  
};  

template<class T>
Node<T>* Stack<T>::back()  
{  
    if(!empty())  
        return qrear;  
}  
template<class T>
Node<T>* Stack<T>::front()  
{  
    if(!empty())  
    {  
        Node<T> *p=qfront;  
        return p;  
    }else return NULL;
}  
template<class T>
bool Stack<T>::empty() const  
{  
    if(qfront==qrear)  
        return true;  
    else  
        return false;  
}  
template<class T>
void Stack<T>::pop()  
{  
    if(!empty())  
    {  
        Node<T> *p=qfront;  
        qfront=p->next;  
        if(p==qrear)  
            qrear=qfront;  
        delete p;  
        p=NULL;  
  
    }  
}  

template<class T>
void Stack<T>::push(T i)  
{  
    Node<T> *node=new Node<T>;  
    node->c=i;
    node->next=qfront;   
    qfront=node;  
}  

template<class T>
int Stack<T>::size() const  
{  
    Node<T> *p=qfront;  
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
#endif
