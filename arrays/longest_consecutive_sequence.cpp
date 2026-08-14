// LeetCode 128 - Longest Consecutive Sequence
// Approach: Hash Set
// Time: O(n)
// Space: O(n)


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        unordered_set<int> st(nums.begin(),nums.end()); 

        int longest = 0;
    
        //traverse every unique number
        for(int num : st){

            // Start only if num is the first element of a sequence
            if(st.find(num - 1) == st.end()){

                int current = num;
                int count = 1;

                //count consecutive numbers
                while(st.find(current + 1) != st.end()){
                    current ++;
                    count ++;
                }
                longest = max(longest,count);
            }

        }
        return longest;
    }
};