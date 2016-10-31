#include <iostream>
#include <stack.h>
#include <helper.h>

using namespace std;

int main (){
    print();  
    push(10); push(9); push(7); push(6); push(5);  
    push(4);  push(3); push(2); push(1); push(0);  
    printf("push压入数值后：\n");  
    print();  
    printf("\n");  
    pop();  
    pop();  
    printf("经过pop弹出几个元素后的堆栈元素:\n");  
    print();  
    printf("\n");  
    printf("top()调用出来的值: %d\n",top());  
	return 0;
}

