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
    ListNode* reverseKGroup(ListNode* head, int k) {
        cin.sync_with_stdio(false);
        if(head == NULL or head->next == NULL) return head;
        
        ListNode dummy(0);
        dummy.next = head;
        
        ListNode *prev = &dummy, *cur = head, *next = NULL;
        int len = lenLL(head);
        int groups = len/k;
        
        while(groups--)
        {
            for(int i = 1; i < k; i++)
            {
                next = cur->next;
                cur->next = next->next;
                next->next = prev->next;
                prev->next = next;
                if(i == k-1)
                {
                    prev = cur;
                    cur = cur->next;
                }
            }
        }
        
        return dummy.next;
    }

private:
    int lenLL(ListNode* head)
    {
        auto node = head;
        int len = 0;
        while(node)
        {
            len++;
            node = node->next;
        }
        return len;
    }
};