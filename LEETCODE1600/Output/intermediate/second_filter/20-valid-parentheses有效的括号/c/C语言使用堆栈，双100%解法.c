/*采用期待的迫切程度算法来解决*/
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10

typedef struct{
    char *top;
    char *base;
    int stacksize;
}SqStack;


char GetTop(SqStack S);
void InitStack(SqStack *S);
void Push(SqStack *S,char n);
void Pop(SqStack *S);
bool StackEmpty(SqStack S);

bool isValid(char * s){
    SqStack S;
    InitStack(&S);
    int i=0;
    bool flag = true;
    int len = strlen(s);
    while(i<len&&flag){
    	switch(s[i]){
    		case '(': {
    			Push(&S,s[i]);
    			i++;
				break;
			}
			case ')':{
				if(!StackEmpty(S)&&GetTop(S)=='(') Pop(&S);
				else flag = false;
				i++;
				break;
			}
			case '[': {
    			Push(&S,s[i]);
    			i++;
				break;
			}
			case ']':{
				if(!StackEmpty(S)&&GetTop(S)=='[') Pop(&S);
				else flag = false;
				i++;	
				break;
		}
			case '{': {
    			Push(&S,s[i]);
    			i++;
				break;
			}
			case '}':{
				if(!StackEmpty(S)&&GetTop(S)=='{') Pop(&S);
				else flag = false;
				i++;	
				break;
			}
		}
	}
	if(StackEmpty(S)&&flag) return true;
	else return false;
	
}


char GetTop(SqStack S){
	return *(S.top-1);
}

void InitStack(SqStack *S){
    (*S).base = (char*)malloc(STACK_INIT_SIZE * sizeof(char));
    (*S).top = (*S).base;
    (*S).stacksize = STACK_INIT_SIZE;
}


void Push(SqStack *S,char n){
    if((*S).top-(*S).base>=(*S).stacksize){
        (*S).base = (char*)realloc((*S).base,((*S).stacksize+STACKINCREMENT)*sizeof(char));
        (*S).top = (*S).base + (*S).stacksize;
        (*S).stacksize += STACKINCREMENT;
    }
    *(*S).top++ = n;
}


void Pop(SqStack *S){
    --(*S).top;
}


bool StackEmpty(SqStack S){
    if(S.top==S.base) return true;
    else return false;
}