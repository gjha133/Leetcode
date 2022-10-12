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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* newHead = NULL;
        
        while(head)
        {
            auto temp = head;
            head = head->next;
            temp->next = NULL;
            
            if(newHead == NULL) newHead = temp;
            else if(newHead->val >= temp->val)
            {
                temp->next = newHead;
                newHead = temp;
            }
            else
            {
                auto node = newHead;
                while(node->next)
                {
                    if(temp->val > node->val and temp->val <= node->next->val)
                    {
                        temp->next = node->next;
                        node->next = temp;
                        break;
                    }
                    node = node->next;
                }
                
                //inserting the temp node at the end
                if(node->next==NULL) node->next = temp;
            }
        }
        
        return newHead;
    }
};