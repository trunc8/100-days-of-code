// Solution 1: Come up on my own but unhappy with this.
// Saw testcases and patched up as I saw problems. Till the
// very end unsure if I have all case coverage
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int size = nums.size();
        if( size <= 2) return true;
        
        int rule_break = 0;
        if( nums.at(1) <= nums.at(2) and nums.at(0) > nums.at(1) ){
            nums.at(0) = nums.at(1);
            rule_break++;
            // cout << "First elem\n";
        } // first element
        
        int i = 1;
        while( rule_break <= 1 and i <= size-2 ){
            int prev_elem = nums.at(i-1);
            int curr_elem = nums.at(i);
            int next_elem = nums.at(i+1);
            if( prev_elem > curr_elem and 
                ( curr_elem > next_elem or prev_elem > next_elem) )
                return false;
            
            if( prev_elem <= next_elem and (prev_elem - curr_elem)*
                (next_elem - curr_elem) <= 0 ){}
            else if( prev_elem > next_elem ){}
            else{
                rule_break++;
                // cout << "Mid elem\n";
                nums.at(i) = prev_elem;
            }
            i++;            
        }
        
        if( nums.at(size-3) <= nums.at(size-2) and nums.at(size-2) > nums.at(size-1) ){
            nums.at(size-1) = nums.at(size-2);
            rule_break++;
            // cout << "Last elem\n";
        } // last element
        return rule_break <= 1;
    }
};


// Solution 2: Understood from discussion
class Solution {
public:
    bool checkPossibility(vector<int>& a) {
        int rule_break = 0;
        for( int i=1; i<a.size(); i++ ){
            if( a[i-1] > a[i] ){
                if( rule_break++) 
                    return false;
                if( i>1 and i<a.size()-1 and a[i-2] > a[i] and 
                   a[i-1] > a[i+1] )    
                    return false;
            }
        }
        return true;
    }
};
