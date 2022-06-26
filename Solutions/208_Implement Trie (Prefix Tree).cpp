
// Solution 1: Using vector of node pointers
struct Node{
    vector<shared_ptr<Node>> nodeptr;
    char ch;
    bool is_end_of_word;
};

class Trie {
private:
    shared_ptr<Node> root;
public:
    Trie() {
        root = shared_ptr<Node>(new Node());
    }
    
    void insert(string word) {
        shared_ptr<Node> curr_node = root;
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
                shared_ptr<Node> new_node = shared_ptr<Node>(new Node());
                new_node->ch = w;
                new_node->is_end_of_word = false;
                curr_node->nodeptr.push_back(new_node);
                curr_node = new_node;
            }
        }
        curr_node->is_end_of_word = true;
        
    }
    
    bool search(string word) {
        shared_ptr<Node> curr_node = root;
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
        shared_ptr<Node> curr_node = root;
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


// Solution 2: Using 26 size array and using index position to infer letter
struct Node{
    shared_ptr<Node> nodeptr[26];
    bool is_end_of_word;
};

class Trie {
private:
    shared_ptr<Node> root;
public:
    Trie() {
        root = shared_ptr<Node>(new Node());
    }
    
    void insert( string word ) {
        shared_ptr<Node> curr_node = root;
        for( auto w : word ) {
            if( !curr_node->nodeptr[ w-'a' ] ) {
                curr_node->nodeptr[ w-'a' ] = shared_ptr<Node>( 
                    new Node() );
                curr_node->nodeptr[ w-'a' ]->is_end_of_word = false;
            }
            curr_node = curr_node->nodeptr[ w-'a' ];
        }
        curr_node->is_end_of_word = true;        
    }
    
    bool search( string word ) {
        shared_ptr<Node> curr_node = root;
        for( auto w : word ) {
            if( !curr_node->nodeptr[ w-'a' ] )
                return false;
            curr_node = curr_node->nodeptr[ w-'a' ];
        }
        return curr_node->is_end_of_word;
    }
    
    bool startsWith( string prefix ) {
        shared_ptr<Node> curr_node = root;
        for( auto w : prefix ) {   
            if( !curr_node->nodeptr[ w-'a' ] )
                return false;
            curr_node = curr_node->nodeptr[ w-'a' ];
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
