#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int cal_max_row(int n)
{
    int val = 1;
    int i;
    
    for (i = 0; i < 2 * n - 1; i++) {
        val = val * 2;
    }

    return val;
}

/* 已使用左括号和右括号的个数 需要满足整体左（右）括号使用次数不超过n 
 * 使用右括号时 右括号的当前使用此时总小于当前已使用的左括号 存入栈 */
typedef struct stack_node_s {
    int left;
    int right;
    int i;
} stack_node_t;

typedef struct stack_s {
    int top;
    stack_node_t *stack_node;
} stack_t;

void push_stack(stack_t *stack, int left, int right, int i)
{
    stack->top++;
    stack->stack_node[stack->top].left = left;
    stack->stack_node[stack->top].right = right;
    stack->stack_node[stack->top].i = i;    
}

void pop_stack(stack_t *stack, int *left, int *right, int *i)
{
    *left = stack->stack_node[stack->top].left;
    *right = stack->stack_node[stack->top].right;
    *i = stack->stack_node[stack->top].i;
    stack->top--;
}

int is_stack_empty(stack_t *stack)
{
    return (stack->top == 0) ? 1 : 0;
}

/* 记录找到的有效串的总数 */
char ** generateParenthesis(int n, int* returnSize)
{
    char **result = NULL;
    char *tmp_array = NULL;
    int max_row = 0;
    int i;
    int left, right;
    char c;
    stack_t stack;
    char *ret;
    int array_found = 0;

    max_row = cal_max_row(n);
    result = (char **)calloc(1, sizeof(char*) * max_row);
    tmp_array = (char *)calloc(1, sizeof(char) * (2 * n + 1));
    if (n == 0) {
        tmp_array[0] = '\0';
        result[0] = (char*)calloc(1, sizeof(char) * (2 * n + 1));
        strcpy(result[0], tmp_array);
        *returnSize = 1;
        return result;
    }

    stack.top = 0;
    /* 查找树的深度最深就是2n+1 */
    stack.stack_node = (stack_node_t *)calloc(1, (2 * n + 1) * sizeof(stack_node_t));

    /* 实现二叉树的中序遍历，成功遍历到的叶子节点就是符合的字符串 */
    left = 1;
    right = 0;
    c = '(';
    i = 0;
    while ((is_stack_empty(&stack) != 1) || ((left <= n) && (left >= right))) { /* 循环条件 栈空 或者 左括号和右括号有一个小于n 这个代表还有节点未遍历到 */
        tmp_array[i] = c;
        if ((left <= n) && (left >= right)) {
            push_stack(&stack, left, right, i);
            i++;
            left++;
            c = '(';
        } else {
            pop_stack(&stack, &left, &right, &i);
            i++;
            if ((left == n) && (right == n) && (i == 2 * n)) {
                tmp_array[i] = '\0';
                result[array_found] = (char*)calloc(1, sizeof(char) * (2 * n + 1));
                ret = strcpy(result[array_found], tmp_array);
                array_found++;
            }
            right++;
            c = ')';
        }
    }
    free(tmp_array);
    *returnSize = array_found;
    return result;
}