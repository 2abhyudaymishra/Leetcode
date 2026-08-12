class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count=0;
        long long prefixSum =0;
        unordered_map<long long, int>mp;
        for(int i=0;i<nums.size();i++){
            
            prefixSum +=nums[i];            
            if(prefixSum==k)count++;

            if(mp.find(prefixSum-k)!=mp.end())count+=mp[prefixSum-k];
            mp[prefixSum]++;
        }

        return count;
    }
};