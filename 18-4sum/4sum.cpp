class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        if(n<3)return{};
        sort(nums.begin(),nums.end());
        set<vector<int>>ans;
        for(int i=0;i<n-3; i++){
            for(int j=i+1; j<n-2;j++){
                long long newTarget = (long long)target - (long long)nums[i]- (long long)nums[j];
                int start=j+1;
                int end = n-1;
                while(start<end){
                    if(nums[start]+nums[end]==newTarget){
                        ans.insert({nums[i],nums[j],nums[start],nums[end]});
                        start++;end--;
                    }
                    else if(nums[start]+nums[end]<newTarget)start++;
                    else end--;
                }
            }
        }
        vector<vector<int>>temp (ans.begin() , ans.end());
        return temp;
    }
};