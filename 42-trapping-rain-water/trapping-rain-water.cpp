class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int>maxRightHeight(n);
        int end= n-1;
        int nextHeight= 0;
        int trappedWater =0;
        while(end>=0){
            maxRightHeight[end]=nextHeight;
            nextHeight = max(nextHeight, height[end]);
            end--;
        }
        int prevHeight = 0;
        for(int i=0; i<n; i++){
            int minHeight = min(prevHeight, maxRightHeight[i]);
            if(height[i] < minHeight){
                trappedWater+= minHeight - height[i];
            }
            prevHeight = max(prevHeight, height[i]);
        }
        return trappedWater;
    }
};