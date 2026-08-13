class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> mergedInterval;
        sort(intervals.begin(), intervals.end());
        for(auto interval : intervals){
            if(mergedInterval.empty()){
                mergedInterval.push_back(interval);
                continue;
            }
            int prevStart = mergedInterval.back()[0];
            int prevEnd = mergedInterval.back()[1];
            int currStart= interval[0];
            int currEnd = interval[1];
            if(prevEnd >=currStart){
                mergedInterval.back()[1]= max(prevEnd, currEnd);
                mergedInterval.back()[0]= min(prevStart, currStart);
            }else{
                mergedInterval.push_back(interval);
            }
        }
        return mergedInterval;
    }
};