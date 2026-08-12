class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]<=0 || nums[i]>n)nums[i]=0;
        }

        for(int i=0;i<n;i++){
            if(nums[i]==0 || abs(nums[i])==i+1 || nums[i]<0 )continue;
            int index = nums[i]-1;
            nums[i]=-nums[i];
            swap(nums[i], nums[index]);
            i--;
        }

        for(int i=0;i<n;i++){
            if(abs(nums[i])!=i+1)return i+1;
        }
        return nums.size()+1;
    }
};