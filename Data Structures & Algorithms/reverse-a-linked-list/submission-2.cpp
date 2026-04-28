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
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next) return head ;
        auto temp = head->next ;
        head->next = NULL ;
        while(temp){
            auto temp1 = temp->next ;
            temp->next = head; 
            head = temp ;
            temp = temp1 ;
        }

        return head ;
    }
};
