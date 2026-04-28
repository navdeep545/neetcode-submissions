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
ListNode* mergeTwoLists(ListNode* l1,ListNode* l2){

    ListNode dummy(0) ;
    ListNode* tail = &dummy ;

    auto temp1 = l1 ;
    auto temp2 = l2 ;

    while(temp1 && temp2){
        if(temp1->val <= temp2->val){
            tail->next = temp1 ;
            temp1 = temp1->next ;
        }
        else {
            tail->next = temp2 ;
            temp2 = temp2->next ;
        }
        tail = tail->next ;
    }

    if(temp1) tail->next = temp1 ;
    if(temp2) tail->next = temp2 ;

    return dummy.next ;
}

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return NULL ;
        if(lists[0] == NULL) return NULL ;
        ListNode* newList = lists[0] ;

        for(int i=1;i<lists.size();i++){
            newList = mergeTwoLists(newList,lists[i]) ;
        }

        return newList ;
    }
};
