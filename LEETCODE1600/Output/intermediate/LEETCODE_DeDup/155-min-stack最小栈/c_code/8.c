#define MIN_VAL -65536
#define INVALID_VAL 65535
#define INVALID_POINTER -1
#define INIT_SIZE 100
#define SPACE_EXPAND_FACTOR 2

typedef struct {
    int *vals;
    int top; //top pointer
	int spaceSize;
	int minVal;
} MinStack;

/** initialize your data structure here. */

MinStack* minStackCreate() {
    MinStack *stack = (MinStack *)malloc(sizeof(MinStack));
    stack->vals = NULL;
    stack->spaceSize = 0;
	stack->top = INVALID_POINTER;
	stack->minVal = MIN_VAL;
    return stack;
}

void minStackPush(MinStack* obj, int x) {
    MinStack *stack = obj;
    if(stack == NULL) {
		printf("stack == NULL\n");
        return;
    }

	if(stack->spaceSize == 0) {
		stack->vals = (int *)malloc(INIT_SIZE * sizeof(int));
		stack->spaceSize = INIT_SIZE;
		stack->top = 0;
		stack->vals[stack->top] = x;
		stack->minVal = x;		
	}
	else {
		if (stack->top < stack->spaceSize - 1) {
			stack->top++;
			stack->vals[stack->top] = x;
			stack->minVal = stack->minVal < x ? stack->minVal : x;
		}
		else {
			int oldSpaceSize = stack->spaceSize;
			stack->spaceSize = SPACE_EXPAND_FACTOR * stack->spaceSize;
			int *temp1 = (int *)malloc(stack->spaceSize * sizeof(int));
			memcpy(temp1, stack->vals, oldSpaceSize * sizeof(int));
			stack->top++;
			temp1[stack->top] = x;
			stack->minVal = stack->minVal < x ? stack->minVal : x;
			free(stack->vals);
			stack->vals = temp1;		
		}
	}
#if 0
	printf("push:stack = ");
	for(int i = stack->top; 0 <= i; i--) {
		printf("%d->",stack->vals[i]);
	}
	printf("\n");	
#endif
    return;
}

void minStackPop(MinStack* obj) {
    MinStack *stack = obj;
    if(stack == NULL) {
		printf("stack == NULL\n");
        return;
    }    
    int *temp1 = NULL;
    int *temp2 = NULL;
	if(stack->top == INVALID_POINTER) {
		printf("top is invalid\n");
        return;
    }
	else if(stack->top == 0) {
         free(stack->vals);
         stack->spaceSize = 0;
		 stack->vals = NULL;
         stack->top = INVALID_POINTER;
		 stack->minVal = MIN_VAL;
    }
    else if(stack->top > 0) {
		if(stack->minVal == stack->vals[stack->top]) {
			stack->minVal = stack->vals[stack->top - 1];
			for(int i = stack->top - 1; 0 <= i; i--) {
				stack->minVal = stack->minVal < stack->vals[i] ? stack->minVal :stack->vals[i];
			}
		}
		stack->vals[stack->top] = INVALID_VAL;
		stack->top--;
    }
	
	if(stack->top == INVALID_POINTER) {
		printf("pop:stack is null\n");
	}
	else {
	    printf("pop:stack = ");
	    for(int i = stack->top; 0 <= i; i--) {
	    	printf("%d->",stack->vals[i]);
	    }
	    printf("\n");	
	}

    return;  
}

int minStackTop(MinStack* obj) {
    MinStack *stack = obj;
    if(stack == NULL) {
		printf("stack == NULL\n");
        return 0;
    }

	if(stack->top == INVALID_POINTER) {
		printf("top is invalid\n");
        return 0;
    }

	printf("top:%d\n",stack->vals[stack->top]);
	return stack->vals[stack->top];  
}

int minStackGetMin(MinStack* obj) {
    MinStack *stack = obj;
    int min = 0;
    int i = 0;
    if(stack == NULL) {
		printf("stack == NULL\n");
        return 0;
    }
	printf("getmin:%d\n",stack->minVal);
	return stack->minVal;  
}

void minStackFree(MinStack* obj) {
        MinStack *stack = obj;
        if(stack == NULL) {
		   printf("stack == NULL\n");
           return;
        }          
        free(stack->vals);
        stack->vals = NULL;
        free(stack);
		stack = NULL;
        return;
}