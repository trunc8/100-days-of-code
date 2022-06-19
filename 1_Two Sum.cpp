// O(n^2), brute force
class Solution1 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int LI, RI;
        for (LI=0; LI<nums.size(); LI++) {
            for (RI=LI+1; RI<nums.size(); RI++) {
                if (nums[LI] + nums[RI] == target) {
                    vector<int> soln {LI, RI};
                    return soln;
                }
            }
        }
        vector<int> soln {0,0};
        return soln;
    }
};


// O(2*n)
class Solution2 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map <int, int> hashtable;
        for (int index=0; index<nums.size(); index++)
            hashtable.insert(make_pair(nums[index], index));
        for (int right_index=nums.size()-1; right_index>= 0; right_index--) {
            auto it = hashtable.find( target - nums[right_index] );
            if (it!=hashtable.end() and it->second!=right_index) {
                vector<int> soln {it->second, right_index};
                return soln;
            }
        }
        vector<int> soln {0,0};
        return soln;
    }
};

// O(n), referred discussions for this soln
class Solution3 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map <int, int> hashtable;
        for (int i=0; i<nums.size(); i++) {
            if (hashtable.find(target - nums[i]) != hashtable.end())
                return {i, hashtable[target - nums[i]]};
            hashtable[nums[i]] = i;
        }
        return {};
    }
};
