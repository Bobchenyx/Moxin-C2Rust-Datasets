#define MAXSIZE 1000

typedef struct {
    int *data;
    int top;
} MinStack;

MinStack* minStackCreate() {
    MinStack *obj = malloc(sizeof(MinStack));
    obj->data = malloc(MAXSIZE*sizeof(int));
    obj->top = -1;
    return obj;
}

void minStackPush(MinStack* obj, int x) {
  if(obj->top == MAXSIZE-1){
      return;
  } else {
      obj->top++;
      obj->data[obj->top] = x;
  }
}

void minStackPop(MinStack* obj) {
  if(obj->top == -1){
      return;
  }else{
      obj->top--;
  }
}

int minStackTop(MinStack* obj) {
  if(obj->top == -1){
      return;
  }
  return obj->data[obj->top];
}

int minStackGetMin(MinStack* obj) {
  if(obj->top == -1) {
      return;
  }
  int min = obj->data[0];
  for(int i = 0;i <= obj->top; i++){
      if(obj->data[i] < min){
          min = obj->data[i];
      }
  }
  return min;
}

void minStackFree(MinStack* obj) {
    free(obj->data);
    obj->data = NULL;
    free(obj);
    obj = NULL;
}