/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head->next == nullptr)
            return nullptr;
        ListNode * p = head, * q = head;
        for (int i = 0; i < n; ++i)
        {
            p = p->next;
        }
        if (p == nullptr)
        {
            q = head->next;
            delete head;
            return q;
        }
        while (p->next != nullptr)
        {
            p = p->next;
            q = q->next;
        }
        p = q->next->next;
        delete q->next;
        q->next = p;
        return head;
    }
};