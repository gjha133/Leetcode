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
    ListNode* mergeNodes(ListNode* head) {
        auto temp = head->next;
        bool first = true;
        ListNode* newHead = NULL;
        auto cur = newHead;
        while(temp)
        {
            int sum = 0;
            while(temp->val != 0)
            {
                sum += temp->val;
                temp = temp->next;
            }
            ListNode* node = new ListNode(sum); 
            if(first) 
            {
                newHead = node;
                cur = node;
                first = false;
            }
            else 
            {
                cur->next = node;
                cur = cur->next;
            }
            
            temp = temp->next;            
        }
        
        cur->next = NULL;
        delete head;
        return newHead;
    }
};