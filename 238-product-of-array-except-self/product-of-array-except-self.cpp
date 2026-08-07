class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int>prefix(size);
        vector<int>suffix(size);
        vector<int>ans(size);
        int preProd = 1;
        int sufProd = 1;
        for(int i =0;i<size;i++){
            prefix[i] = preProd;
            suffix[size-i-1] = sufProd;
            preProd *= nums[i];
            sufProd *= nums[size-i-1]; 
        }
        for(int i=0;i<size;i++){
            ans[i]= prefix[i]*suffix[i];
        }
        return ans;
    }
};