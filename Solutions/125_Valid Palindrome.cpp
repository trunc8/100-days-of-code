class Solution {
public:
    bool isPalindrome(string s) {
        string s_filtered = "";
        for( auto ch : s ){
            ch = std::tolower(ch);
            if( (ch >= 'a' and ch <= 'z') or (ch >= '0' and ch <= '9') )
                s_filtered += ch;
        }
        int len = s_filtered.length();
        if( !len )
            return true;
        for( int i=0; i<(len-1); i++ ){
            if( s_filtered[i] != s_filtered[len-1-i] )
                return false;
        }
        return true;
    }
};
