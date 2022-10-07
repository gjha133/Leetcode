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
    void reorderList(ListNode* head) {
        if(head == NULL) return;
        auto midNode = mid(head);
        auto head2 = midNode->next;
        midNode->next = NULL;
        head2 = reverse(head2);
        
        // Merge
        
        auto h = head;
        while(head2)
        {
            auto temp = head2->next;
            head2->next = h->next;
            h->next = head2;
            head2 = temp;
            h = h->next->next;
        }
    }
    
    ListNode* reverse(ListNode* node)
    {
        ListNode* prev = NULL;
        ListNode* curr = node;
        ListNode* next = NULL;
        
        while(curr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        return prev;
    }
    
    ListNode* mid(ListNode* node)
    {
        auto slow = node;
        auto fast = node;
        
        while(fast->next and fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }
};