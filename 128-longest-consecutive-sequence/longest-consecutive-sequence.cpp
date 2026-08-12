class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)return 0;
        unordered_set<int>st;
        int maxLen = 1;
        for(auto it: nums)st.insert(it);

        for(auto x : st){
            if(st.find(x-1)!=st.end())continue;
            int n = x;
            int len=1;
            while(st.find(n+1)!=st.end()){
                len++;
                n=n+1;
            }
            maxLen = max(maxLen , len);
        }
        return maxLen;
    }
};