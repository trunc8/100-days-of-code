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
