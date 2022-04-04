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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* t1 = head;
        for(int i=0; i<k-1; i++) t1 = t1->next;
        ListNode* slow = head;
        ListNode* fast = t1->next;
        while(fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
        
        swap(slow->val, t1->val);
        delete fast;
        return head;
        
        
        
        /*vector<int> ll;
        ListNode* temp1 = head;
        ListNode* temp2 = head;
        while(temp1 != NULL)
        {
            ll.push_back(temp1->val);
            temp1 = temp1->next;            
        }
        int temp = ll[k-1];
        ll[k-1] = ll[ll.size() - k];
        ll[ll.size() - k] = temp;
        int j=0;
        while(temp2 != NULL)
        {
            temp2->val = ll[j];
            j++;
            temp2 = temp2->next;
        }
        
        return head;*/
    }
};