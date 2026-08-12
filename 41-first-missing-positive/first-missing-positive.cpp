class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if(nums.size()==1)return nums[0]==1?2:1;
        int n =nums.size();
        vector<int>temp(n,0);
        for(int i=0;i<n;i++){
            if(nums[i]<=0 || nums[i]>nums.size())continue;
            temp[nums[i]-1]=1;
        }

        for(int i=0;i<n;i++){
            if(temp[i]!=1)return i+1;
        }
        return nums.size()+1;
    }
};