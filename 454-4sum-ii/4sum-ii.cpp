class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<long long, int>mp;
        int ans=0;
        int n = nums4.size();
        for(int i=0;i<n;i++){
            for(int j=0; j<n; j++){
                long long sum = nums3[i]+nums4[j];
                mp[-sum]++;
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0; j<n; j++){
                long long sum = nums1[i]+ nums2[j];
                if(mp.find(sum)!=mp.end())ans+=mp[sum];
            }
        }
        return ans;
    }
};