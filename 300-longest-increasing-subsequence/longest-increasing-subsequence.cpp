class Solution {

public:
    int longestSubsequenceFinder(vector<int>& nums, int index ,int lastTakenIndex, vector<vector<int>>&dp){
        if(index >= nums.size()){
            return 0;
        }
        if(dp[index+1][lastTakenIndex+1]!=-1){
            return dp[index+1][lastTakenIndex+1];
        }
        //For ans evalutaion by skipping current number
        int skippedLength  = longestSubsequenceFinder(nums, index+1, lastTakenIndex,dp);

        int takenLength = 0;
        //considering current number only for valid scenario
        if(lastTakenIndex==-1 || nums[index] > nums[lastTakenIndex] ){
            takenLength = longestSubsequenceFinder(nums, index+1, index, dp) + 1;
        }

        return dp[index+1][lastTakenIndex+1] = max(skippedLength , takenLength);

    }
    int lengthOfLIS(vector<int>& nums) {
        int size = nums.size();
        vector<vector<int>>dp(size+1 , vector<int> (size+1,-1));
        return longestSubsequenceFinder(nums, 0, -1, dp);
    }
};