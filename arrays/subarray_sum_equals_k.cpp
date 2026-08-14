// LeetCode 560 - Subarray Sum Equals K
// Approach: Prefix Sum + Unordered Map
// Time Complexity: O(n)
// Space Complexity: O(n)


class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
    unordered_map<int,int> mp;

    mp[0] = 1;

    int count = 0;
    int prefixSum = 0;

    for(int i = 0; i < nums.size(); i++){
        prefixSum +=nums[i];

        int remove = prefixSum - k;

        if(mp.find(remove) != mp.end()){
            count += mp[remove]; //look first
        }
        mp[prefixSum]++;  //save afterwards
    }  
    return count;
    }
};