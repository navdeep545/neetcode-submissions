/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> maps;
        Node* temp = head;
        Node dummy(-1) ;
        Node* prev = &dummy ;
        while (temp) {
            if (!maps.count(temp)) {
                maps[temp] = new Node(temp->val);
            }
            prev->next = maps[temp];
            prev = maps[temp];
            if (temp->random) {
                if (!maps.count(temp->random)) {
                    maps[temp->random] = new Node(temp->random->val);
                }
                prev->random = maps[temp->random];
            }

            temp = temp->next;
        }

        return maps[head];
    }
};