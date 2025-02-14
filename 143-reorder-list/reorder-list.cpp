class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next || !head->next->next) return; // Edge cases
        
        ListNode* t = head;
        stack<ListNode*> st;

        // Push all nodes onto the stack
        while (t) {
            st.push(t);
            t = t->next;
        }

        ListNode* t2 = head;
        int n = st.size();
        
        // Reordering process
        for (int i = 0; i < n / 2; i++) {
            ListNode* top = st.top();
            st.pop();

            top->next = t2->next;
            t2->next = top;
            t2 = top->next;
        }

        // Ensure the last node points to NULL to avoid cycles
        if (t2) t2->next = nullptr;
    }
};