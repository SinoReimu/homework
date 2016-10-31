#include "array.h"
#include <iostream>
#include <string>

using namespace std;

Node* clone (Node* a) {
  Node* newNode = new Node;
  Node* curr;
  Node* temp;
  temp = a;
  newNode->key = -1;
  newNode->next = NULL;
  curr = newNode;
  for (;;) {
    Node* n = new Node;
    n->key = temp->key;
    n->value = temp->value;
    curr->next = n;
    curr = n;
    if (temp->next == NULL) {
      break;
    } else {
      temp = temp->next;
    }
  }
  return newNode;
}

void show (Node* a) {
  Node* temp;
	string r = "";
	bool h = true;
	temp = a->next;
	for(;;) {
		if (temp->value != 0) {
			if (h == false) {
				if (temp->value > 0)
					r = r + "+";
			} else
				h = false;

			if (temp->value > 0) {
				if (temp->value != 1){
          char a[32];
          sprintf(a,"%g",temp->value);
					r = r + string(a);
        }
				else if (temp->key == 0)
					r = r + "1";
			} else {
				if (temp->value == -1 && temp->key != 0)
					r = r + "-";
				else {
          char a[32];
          sprintf(a,"%g",temp->value);
          r = r + string(a);
        }
			}
			if (temp->key != 0) {
				if (temp->key == 1)
					r = r + "x";
				else
					r = r + "x^" + to_string(temp->key);
			}
		}
		if (temp->next == NULL)
    	break;
		else
			temp = temp->next;
	}
	if (r.length() == 0)
		r = "0";
  cout.unsetf(ios::fixed);
	cout << r;
}

float get (int k, Node* a) {
  float r = 0;
	Node* temp;
	temp = a;
	for(;;) {
		if (temp->key == k) {
			r = temp->value;
			break;
		}
		if (temp->next == NULL)
			break;
	  else
			temp = temp->next;
	}
	return r;
}

void insert (int k, float v, Node* a) {
  Node* temp;
  Node* pre;
	temp = a;
	for(;;) {
		if (temp->key > k)
			break;
		else if (temp->key == k) {
			temp->value = temp->value + v;
			return;
		}
		pre = temp;
		if (temp->next != NULL) {
			temp = temp->next;
		} else {
			temp = NULL;
			break;
		}
	}
	Node* az = new Node;
	az->next = temp;
	az->key = k;
	az->value = v;
	pre->next = az;
}

void deleteK (Node* a, int k) {
  Node* pre;
  Node* temp;
	temp = a;
	for(;;) {
		if (temp->key == k) {
			pre->next = temp->next;
			break;
		}
		if (temp->next == NULL) {
			break;
		} else {
			pre = temp;
			temp = temp->next;
		}
	}
}
