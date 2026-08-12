class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        bool onepresent = false;
        for(int i=0;i<n;i++){
            if(nums[i]==1)onepresent =true;
            if(nums[i]<=0 || nums[i]>n)nums[i]=1;
        }
        if(!onepresent)return 1;

        for(int i=0;i<n;i++){
            int index = abs(nums[i])-1;
            if(nums[index]>0)nums[index] = -nums[index];
        }

        for(int i=0;i<n;i++){
            if(nums[i]>0)return i+1;
        }
        return nums.size()+1;
    }
};