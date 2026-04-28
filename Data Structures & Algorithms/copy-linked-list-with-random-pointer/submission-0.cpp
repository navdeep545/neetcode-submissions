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
        unordered_map<Node*,Node*> maps  ;
        Node* temp = head ;
        while(temp){
            maps[temp] = new Node(temp->val) ;
            temp = temp->next ;
        }
        for(auto &[purana,nava]:maps){
            if(maps.count(purana->next)){
                nava->next = maps[purana->next] ;
            }
            if(maps.count(purana->random)){
                nava->random = maps[purana->random] ;
            }
        }

        return maps[head] ;
    }
};