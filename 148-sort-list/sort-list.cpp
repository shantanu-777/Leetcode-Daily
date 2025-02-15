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
    ListNode* sortList(ListNode* head) {
        vector<int> arr;
        ListNode* temp = head;
        
        // Extract values from the linked list and store them in the vector
        while(temp != nullptr){
            arr.push_back(temp->val);
            temp = temp->next;
        }
        
        // Sort the vector
        sort(arr.begin(), arr.end());
        
        // Update the linked list with sorted values
        temp = head;
        for(int i = 0; temp != nullptr; i++){
            temp->val = arr[i];
            temp = temp->next;
        }     
        return head; 
       
    }
};