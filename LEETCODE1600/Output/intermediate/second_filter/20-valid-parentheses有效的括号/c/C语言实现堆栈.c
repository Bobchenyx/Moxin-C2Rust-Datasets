typedef struct{
    char *data;
    int capacity;
    int top;
} Stack;

void init(Stack * s, int capacity)
{
    s->data = (char *)malloc(sizeof(char)*(capacity + 1));
    s->capacity = capacity;
    s->top = -1;
}

void push(Stack * s, char e)
{
    s->data[++s->top] = e;
}
void pop(Stack *s)
{
    s->top--;
}

char top(Stack * s)
{
    return s->data[s->top];
}

bool isValid(char * s){
    Stack stack;
    int n = strlen(s);
    init(&stack, n);
    for(int i = 0; i < n; i++){
        switch(s[i]){
            case '(' :
            case '[' :
            case '{' : push(&stack, s[i]); break;
            case ')' :
            case ']' :
            case '}' : {
                if(stack.top == -1) return false;
                char e = top(&stack);
                if(e == '(' && s[i] == ')') pop(&stack);
                else if(e == '[' && s[i] == ']') pop(&stack);
                else if(e == '{' && s[i] == '}') pop(&stack);
                else return false;
                break;
            }
            default: break;
        }
    }

    if(stack.top == -1) return true;
    else return false;
}