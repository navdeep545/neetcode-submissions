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

ListNode* findCenterAndPrev(ListNode* head){
    if(!head || !head->next) return head ;
     ListNode* prev = NULL ;
        auto slow = head ;
        auto fast = head ;
        while(fast && fast->next){
            prev = slow ;
            slow = slow->next ;
            fast = fast->next->next ;
        }

        return prev ;
}

ListNode* reverse(ListNode* head){
    if(!head || !head->next) return head;
    auto temp = head->next ;
    head->next = NULL ;
    while(temp){
        auto temp1=temp->next ;
        temp->next = head; 
        head = temp ;
        temp = temp1 ;
    }

    return head ;
}

public:
    void reorderList(ListNode* head) {
        ListNode* prev = findCenterAndPrev(head) ;
        auto head1 = prev->next ;
        prev->next = NULL ;
        auto head2 = reverse(head1) ;
        prev = head ;
        while(head2 && prev && prev->next){
            auto temp1 = prev->next ;
            prev->next = head2 ;
            head2 = head2->next ;
            prev->next->next = temp1 ;
            prev = temp1 ;
        }
        if(head2) prev->next = head2 ;
    }
};
