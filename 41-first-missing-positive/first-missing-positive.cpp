class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        //handle negative numbrs
        int n = nums.size();

        for(int i =0; i<n; i++){
            if(nums[i]<=0)nums[i]=n+1;
        }
        //index marking for positive numbers
        for(int i=0; i<n; i++){
            int index = abs(nums[i]);
            if(index>n || index==0 || nums[index-1]<0)continue;
            nums[index-1] = -nums[index-1];
        }
        for(int i=0; i<n; i++){
            if(nums[i]>=0) return i+1;
        }
        return n+1;
    }
};