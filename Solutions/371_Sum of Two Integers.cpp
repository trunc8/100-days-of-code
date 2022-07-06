// Solution 1
class Solution {
public:
    int getSum(int a, int b) {
        if( b>0 )
            while(b--)
                a++;
        else
            while(b++)
                a--;
        return a;
    }
};

// Solution 2: Referred discussions, unsigned int is a nice nuance
class Solution {
public:
    int getSum(int a, int b) {
        int c_and = a&b;
        int c_xor = a^b;
        if( c_and == 0 ) return c_xor;
        return getSum( (unsigned int)c_and << 1, c_xor );
    }
};
