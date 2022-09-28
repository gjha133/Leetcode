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
    
    int length(ListNode* head)
    {
        ListNode* t1 = head;
        int count = 0;
        while(t1)
        {
            count++;
            t1 = t1->next;
        }
        return count;
    }
    
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        if(n == length(head))
        {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }
        if(head->next == NULL && n==1) return NULL;
        ListNode* tobedeleted = head;
        for(int i=0; i<n-1; i++)
        {
            tobedeleted = tobedeleted->next;
        }
        ListNode* p2 = head;
        ListNode* t1 = tobedeleted->next;
        while(t1->next)
        {
            t1 = t1->next;
            p2 = p2->next;
        }
        tobedeleted = p2->next;
        p2->next = tobedeleted->next;
        delete tobedeleted;
        return head;
    }
};