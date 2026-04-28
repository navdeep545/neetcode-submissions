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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Create a dummy node to simplify edge cases like removing the head
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        // Initialize two pointers, both starting from the dummy node
        ListNode* first = dummy;
        ListNode* second = dummy;
        
        // Move the first pointer n+1 steps ahead, to ensure there's a gap of n between first and second
        for(int i = 0; i <= n; i++) {
            first = first->next;
        }
        
        // Move both pointers together until first reaches the end
        while(first != nullptr) {
            first = first->next;
            second = second->next;
        }
        
        // Now second is pointing at the node before the node to delete
        ListNode* nodeToDelete = second->next;
        second->next = second->next->next;
        
        // Delete the node
        delete nodeToDelete;
        
        // Return the new head
        ListNode* newHead = dummy->next;
        delete dummy;  // Clean up the dummy node
        return newHead;
    }
};
