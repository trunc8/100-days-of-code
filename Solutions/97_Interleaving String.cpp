class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int l1=s1.length();
        int l2=s2.length();
        int l3=s3.length();
        if( l3 != l1+l2 )
            return false;
        else if( l1*l2 == 0 )
            return s3 == s1+s2;
        vector< vector<bool> > dp( l1+1, vector<bool>(l2+1) );
        dp[0][0] = 1;
        
        for( int i=1; i<=l1; i++ ){
            dp[i][0] = s1.substr(0,i)==s3.substr(0,i);
        }
        for( int j=1; j<=l2; j++ ){
            dp[0][j] = s2.substr(0,j)==s3.substr(0,j);
        }
        
        for( int i=1; i<=l1; i++ ){
            for( int j=1; j<=l2; j++ ){
                dp[i][j] = max( dp[i-1][j] and s3[i+j-1]==s1[i-1],
                              dp[i][j-1] and s3[i+j-1]==s2[j-1] );
            }
        }
        
        return dp[l1][l2];
    }
};
