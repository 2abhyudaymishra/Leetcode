class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if(n==1)return;

        int firstDec = n-2;
        //find first dec index 
        while(firstDec>=0 && nums[firstDec]>= nums[firstDec+1])firstDec--;
        //last permutation
        if(firstDec==-1){
            sort(nums.begin(), nums.end());
            return ;
        }

        //find next greater swap and sort the rest to get next greater permutation
        int last = n-1;
        int greaterDigit = INT_MIN;
        while(last>firstDec){
            if(nums[last]>nums[firstDec])break;
            last--;
        }
        swap(nums[last], nums[firstDec]);
        sort(nums.begin()+firstDec+1, nums.end());
    }
};