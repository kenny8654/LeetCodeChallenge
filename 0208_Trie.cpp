/**
Runtime: 60 ms, Beats: 94.52%
Memory: 45.1 MB, Beats: 54.24%
**/
class Node {
private:
public:
    Node* child[26];
    bool is_end;
    Node(): is_end(false){
        for(int i=0; i<26; i++){
            child[i] = nullptr;
        }
    }
};

class Trie {
private:
    Node* root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* curr = root;
        for(auto& c:word){
            int idx = int(c-'a');
            if(curr->child[idx] == nullptr){
                curr->child[idx] = new Node();
            }
            curr = curr->child[idx];
        }
        curr->is_end = true;
    }
    
    bool search(string word) {
        Node* curr = root;
        for(auto& c:word){
            int idx = int(c-'a');
            if(curr->child[idx] == nullptr)
                return false;
            curr = curr->child[idx];
        }
        return (curr->is_end)? true: false;
    }
    
    bool startsWith(string prefix) {
        Node* curr = root;
        for(auto& c:prefix){
            int idx = int(c-'a');
            if(curr->child[idx] == nullptr)
                return false;
            curr = curr->child[idx];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
