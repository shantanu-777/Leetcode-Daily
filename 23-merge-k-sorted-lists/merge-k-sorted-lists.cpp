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

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Priority queue to store (value, list index, pointer to the node)
        priority_queue<tuple<int, int, ListNode*>, vector<tuple<int, int, ListNode*>>, greater<tuple<int, int, ListNode*>>> minheap;

        for (int i = 0; i < lists.size(); i++) {
            if (lists[i] != nullptr) {
                minheap.push(make_tuple(lists[i]->val, i, lists[i]));
            }
        }

        ListNode* result = nullptr;
        ListNode* resultTail = nullptr;  // Tail pointer 

        while (!minheap.empty()) {
            auto [value, listIndex, node] = minheap.top();
            minheap.pop();

            // Append the smallest value to the result list
            if (result == nullptr) {
                result = new ListNode(value);
                resultTail = result;
            } else {
                resultTail->next = new ListNode(value);
                resultTail = resultTail->next;
            }

            // Push the next node from the same list into the heap, if available means not nullptr
            if (node->next != nullptr) {
                minheap.push(make_tuple(node->next->val, listIndex, node->next));
            }
        }

        return result;
    }
};