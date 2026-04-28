class TrieNode {
public:
    vector<TrieNode*> children;
    bool isTerminal;

    TrieNode() : children(26, nullptr), isTerminal(false) {}
};

class PrefixTree {
private:
    TrieNode* root;

    void clear(TrieNode* node) {
        for (TrieNode* child : node->children) {
            if (child) {
                clear(child);
            }
        }
        delete node;
    }

public:
    PrefixTree() { root = new TrieNode(); }

    ~PrefixTree() { clear(root); }

    void insert(const string& word) {
        TrieNode* cur = root;
        for (char c : word) {
            int ind = c - 'a';
            if (ind < 0 || ind >= 26) {
                throw invalid_argument("Input contains invalid characters");
            }
            if (!cur->children[ind]) {
                cur->children[ind] = new TrieNode();
            }
            cur = cur->children[ind];
        }
        cur->isTerminal = true;
    }

    bool search(const string& word) {
        TrieNode* cur = root;
        for (char c : word) {
            int ind = c - 'a';
            if (ind < 0 || ind >= 26) {
                return false;  // Invalid character
            }
            if (!cur->children[ind]) {
                return false;
            }
            cur = cur->children[ind];
        }
        return cur->isTerminal;
    }

    bool startsWith(const string& prefix) {
        TrieNode* cur = root;
        for (char c : prefix) {
            int ind = c - 'a';
            if (ind < 0 || ind >= 26) {
                return false;  // Invalid character
            }
            if (!cur->children[ind]) {
                return false;
            }
            cur = cur->children[ind];
        }
        return true;
    }
};
