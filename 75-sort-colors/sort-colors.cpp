class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero=0;
        int n = nums.size();
        int two = n-1;
        
        for(int i=0;i<=two;i++){
            if(nums[i]==0){
                swap(nums[i],nums[zero++]);
            }
            else if(nums[i]==2){
                swap(nums[i--],nums[two--]);
            }
        }   
    }
};