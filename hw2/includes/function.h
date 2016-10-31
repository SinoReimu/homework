#ifndef FUNCTION_H
#define FUNCTION_H

typedef void (*function) (int, int,int(*) [8]);
void exit (int startX, int startY, int (*base)[8]);
void greedBackUpSlow (int startX, int startY, int (*base)[8]);
void greedBackUpFast (int startX, int startY, int (*base)[8]);
void baseBackUpSlow (int startX, int startY, int (*base)[8]);
void baseBackUpFast (int startX, int startY, int (*base)[8]);
#endif
