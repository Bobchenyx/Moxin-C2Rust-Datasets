#define MAXSIZE 2000
typedef struct {
    int *data;
    int top;
} MinStack;


/** initialize your data structure here. */

MinStack* minStackCreate() {
    MinStack *obj;
    obj=malloc(sizeof( MinStack));
    obj->data=malloc(sizeof(int)*MAXSIZE);
    obj->top=0;
    return obj;
}

void minStackPush(MinStack* obj, int x) {
  if((obj->top)==0)
  {
       obj->data[(obj->top)++]=x;
       obj->data[(obj->top)++]=x;
  }
  else if(obj->top==MAXSIZE-2)
  {

  }

  else 
  {
      int temp=obj->data[obj->top-1];//注意
      obj->data[(obj->top)++]=x;

      if(temp<x)
          obj->data[(obj->top)++]=temp;
      else
          obj->data[(obj->top)++]=x;

  }  

}

void minStackPop(MinStack* obj) {
  if(obj->top<0)
    return;
   obj->top--;
   obj->top--;
}

int minStackTop(MinStack* obj) {
    if(obj->top==0)
      return;
    return obj->data[(obj->top)-2];
}

int minStackGetMin(MinStack* obj) {

    return obj->data[(obj->top)-1];
}

void minStackFree(MinStack* obj) {
    free(obj->data);
    obj->data=NULL;
    free(obj);

}