class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        // Step 1: Interleave copied nodes with the original list
        Node* curr = head;
        while (curr) {
            Node* copy = new Node(curr->val);
            copy->next = curr->next;
            curr->next = copy;
            curr = copy->next;
        }

        // Step 2: Assign random pointers for the copied nodes
        curr = head;
        while (curr) {
            if (curr->random) {
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next; // Move to the next original node
        }

        // Step 3: Separate the copied list from the original list
        Node* dummy = new Node(-1);
        Node* copyCurr = dummy;
        curr = head;
        while (curr) {
            Node* copy = curr->next;
            copyCurr->next = copy;
            copyCurr = copy;

            curr->next = copy->next; // Restore the original list
            curr = curr->next;       // Move to the next original node
        }

        return dummy->next;
    }
};
