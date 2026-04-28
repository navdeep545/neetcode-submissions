
class Node {

public :
    bool isTerminal ;
    char data ;
    vector<Node*> children ;
    Node(){
        data = 0 ;
        isTerminal = false ;
        children.assign(26,nullptr) ;
    }
    Node(char _data){
        data = _data ;
        isTerminal = false ;
        children.assign(26,nullptr) ;
    }
};


class PrefixTree {

    Node* node ;

public:
    PrefixTree() {
        node = new Node ;
    }
    
    void insert(string word) {
        insert(word,node) ;
    }
    
    bool search(string word) {
        return search(word,node) ;
    }
    
    bool startsWith(string prefix) {
        return startsWith(prefix,node) ;
    }


private:
    void insert(string s,Node* node){
    if(s == "") {node->isTerminal = true ; return ;}
    int ind = s[0]-'a' ;
    Node* child ;
    if(node->children[ind] != nullptr) child = node->children[ind] ;
    else {
        child = new Node(s[0]) ;
        node->children[ind] = child ;
    }
    return insert(s.substr(1),child) ;
}

bool search(string s,Node* node){
    if(s == "") return node->isTerminal ;
    int ind = s[0]-'a' ;
    Node* child = node->children[ind] ;
    if(child == nullptr) return false ;

    return search(s.substr(1),child) ;
}

bool startsWith(string s,Node* node){
    if(s == "") return true ;
    int ind = s[0]-'a' ;
    Node* child = node->children[ind] ;
    if(child == nullptr) return false ;

    return startsWith(s.substr(1),child) ;
}

};
