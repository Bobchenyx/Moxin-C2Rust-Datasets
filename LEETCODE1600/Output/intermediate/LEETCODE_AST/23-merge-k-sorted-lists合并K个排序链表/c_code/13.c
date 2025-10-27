/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#define MAX_LEN         10000

int compare(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

//【算法思路】合并多个有序序列，使用快排，思路简单效率高
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
    if(listsSize == 0)
        return NULL;
    
    int *res_ = (int *)malloc(MAX_LEN * sizeof(int));
    
    int cnt = 0;
    
    struct ListNode * cur;
    
    for(int i = 0; i < listsSize; i++)
    {
        cur = lists[i];
        
        while(cur != NULL)
        {
            res_[cnt++] = cur->val;
            
            cur = cur->next;
        }
    }
    
    if(cnt == 0)
        return NULL;
    
    qsort(res_, cnt, sizeof(int), compare);
    
    struct ListNode *res = (struct ListNode *)malloc(cnt * sizeof(struct ListNode));
    
    cur = &res[0];
    
    for(int i = 0; i < cnt - 1; i++)
    {
        cur->val = res_[i];
        
        cur->next = &res[i + 1];
        
        cur = cur->next;
    }
    
    cur->val = res_[cnt - 1];
    cur->next = NULL;
        
    return res;
}