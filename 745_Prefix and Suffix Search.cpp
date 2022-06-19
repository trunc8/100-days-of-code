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
    
    int getIndex(string prefix) {
        if (!this->startsWith(prefix))
            return -1;
        
        Node* curr_node = root;
        for (auto w : prefix) {          
            for (auto n : curr_node->nodeptr) {
                if (w == n->ch) {
                    curr_node = n;
                    break;
                }                    
            }
        }
        vector<Node*> children;
        while (curr_node->ch != ';') {
            children = curr_node->nodeptr;
            if (children.size()==0)
                return -1;
            curr_node = children[0];
        }
        vector<char> index_char;
        while (true) {
            children = curr_node->nodeptr;
            if (children.size()==0)
                break;
            curr_node = children[0];
            index_char.push_back(curr_node->ch);
        }
        int index_num = 0;
        for (auto ch : index_char) {
            int digit = ch - '0';
            index_num = index_num*10 + digit;
        }
        return index_num;
    }
};

class WordFilter {
private:
    Trie* dict;
public:
    WordFilter(vector<string>& words) {
        dict = new Trie();
        for (int i=words.size()-1; i>=0; i--) {
            string word = words[i];
            for (int j=word.length()-1; j>=0; j--) {
                string suf_pre_word = word.substr(j)+"#"+word+";"+to_string(i);
                dict->insert (suf_pre_word);
            }
        }
    }
    
    int f(string prefix, string suffix) {
        string suf_pre_word = suffix + "#" + prefix;
        return dict->getIndex(suf_pre_word);
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */
