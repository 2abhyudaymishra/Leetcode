class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int zeroCount= 0;
        int ans= 0;
        unordered_map<int,int>mp;
        mp[0]=-1;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==0)zeroCount++;
            else zeroCount--;
            if(mp.find(zeroCount)!=mp.end())ans= max(ans, i - mp[zeroCount]);
            else mp[zeroCount]=i;
        }
        return ans;
    }
};