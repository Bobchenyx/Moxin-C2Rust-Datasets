/*
 * @lc app=leetcode.cn id=24 lang=c
 *
 * [24] 两两交换链表中的节点
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode ln_st;

//【算法思路】链表。设置哑节点，方便处理
struct ListNode* swapPairs(struct ListNode* head){
    ln_st dummy;
    dummy.next = head;

    // hh记录动态头节点，tt记录动态尾节点，mm记录中间节点
    ln_st *hh = &dummy, *tt = &dummy, *mm, *tail;

    //先移动尾节点，并进行计数
    int cnt = 0;
    while(tt != NULL)
    {
        if(cnt != 2)
        {
            cnt++;
            tt = tt->next;
            continue;
        }

        cnt = 0;

        // [hh] | [mm] [tt] | [tail]
        mm = hh->next;
        tail = tt->next;

        // 开始调换
        hh->next = tt;
        tt->next = mm;
        mm->next = tail;

        hh = mm;
        tt = hh;
    }

    return dummy.next;
}


// @lc code=end