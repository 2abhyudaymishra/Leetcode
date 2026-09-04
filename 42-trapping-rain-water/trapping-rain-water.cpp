class Solution {
public:
    int trap(vector<int>& height) {
        int size = height.size();
        vector<int>next(size);
        int maxi = 0;
        for(int i=size-1; i>=0; i--){
            maxi = max(maxi, height[i]);
            next[i]= maxi;
        }
        int prev = 0;
        int ans = 0;
        for(int i=0; i<size;i++){
            prev = max(prev, height[i]);
            int minHeight = min(prev, next[i]);
            ans += minHeight - height[i];
        }

        return ans;

    }
};