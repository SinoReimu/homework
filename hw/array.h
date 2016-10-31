#ifndef ARRAY_H
#define ARRAY_H
typedef struct Node {
  int key;
  float value;
  Node* next;
};

extern void deleteK (Node* , int);
extern Node* clone (Node*);
extern void show (Node*);
extern float get (int, Node*);
extern void insert (int, float, Node*);

#endif
