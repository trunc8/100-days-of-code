// Solution 1: Quite redundant
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        vector<int> front_score( cardPoints );
        vector<int> back_score( cardPoints );
        int front_sum = 0;
        int back_sum = 0;
        for( int i=0; i<k; i++ ){
            front_sum      += cardPoints[i];
            front_score[i] =  front_sum;
            back_sum       += cardPoints[cardPoints.size()-1-i];
            back_score[cardPoints.size()-1-i]  =  back_sum;
        }
        int max_score = INT_MIN;
        for( int front=0; front <= k; front++ ){
            int front_back_sum =  0;
            if( front )
                front_back_sum += front_score[front-1];
            int back = k-front;
            if( back )
                front_back_sum += back_score[cardPoints.size()-back];
            if( front_back_sum > max_score ){
                max_score = front_back_sum;
            }
        }
        return max_score;
    }
};

// Solution 2: Referred hint. Maintained window of [N-k] minsum
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int tot_sum = 0;
        for( auto card : cardPoints )
            tot_sum += card;
        int answer  = INT_MIN;
        int N       = cardPoints.size();
        int mid_sum = 0;
        int index;
        for( index = 0; index < N-k; index++ ){
            mid_sum += cardPoints.at(index);
        }
        answer      = max(answer, tot_sum-mid_sum);
        for( ; index < N; index++ ){
            mid_sum += cardPoints.at( index );
            mid_sum -= cardPoints.at( index-(N-k) );
            answer  = max(answer, tot_sum-mid_sum);            
        }
        return answer;
    }
};
