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
    ListNode* removeNthFromEnd(ListNode* head, int K) {
        
        if(K == 0) return head;
        if(!head) return head;
        auto temp = head;
        while(K--) temp = temp->next;
        if(!temp) return head->next;

        auto node = head;
        while(temp->next)
        {
            temp = temp->next;
            node = node->next;
        }

        node->next = node->next->next;
        return head;
    }
};