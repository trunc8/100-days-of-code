struct Node{
    vector<Node*> nodeptr;
    char ch;
    bool is_end_of_word;
};

class Trie {
private:
    Node* root;
public:
    Trie() {
        root = new Node();
        // root->is_end_of_word = true;
    }
    
    void insert(string word) {
        Node* curr_node = root;
        bool found_so_far = true;
        for (auto w : word) {
            
            bool ch_found = false;
            
            if(found_so_far) {                
                for (auto n : curr_node->nodeptr) {
                    if (w == n->ch) {
                        curr_node = n;
                        ch_found = true;
                        break;
                    }                    
                }
                found_so_far = ch_found;
            }
            
            if (!ch_found) {
                Node* new_node = new Node();
                new_node->ch = w;
                new_node->is_end_of_word = false;
                curr_node->nodeptr.push_back(new_node);
                curr_node = new_node;
            }
        }
        curr_node->is_end_of_word = true;
        
    }
    
    bool search(string word) {
        Node* curr_node = root;
        for (auto w : word) {            
            bool ch_found = false;           
            for (auto n : curr_node->nodeptr) {
                if (w == n->ch) {
                    curr_node = n;
                    ch_found = true;
                    break;
                }                    
            }
            if(!ch_found)
                return false;
        }
        return curr_node->is_end_of_word;
    }
    
    bool startsWith(string prefix) {
        Node* curr_node = root;
        for (auto w : prefix) {            
            bool ch_found = false;           
            for (auto n : curr_node->nodeptr) {
                if (w == n->ch) {
                    curr_node = n;
                    ch_found = true;
                    break;
                }                    
            }
            if(!ch_found)
                return false;
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
