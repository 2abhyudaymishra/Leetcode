class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans=0;
        int start=0;
        int end= height.size()-1;
        while(start<end){
            int currAns = min(height[start], height[end]) * (end-start);
            ans = max(ans,currAns); 
            if(height[start]<height[end])start++;
            else end--;
        }

        return ans;
    }
};