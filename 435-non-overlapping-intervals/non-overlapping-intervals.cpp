class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> temp;
        temp.push_back(intervals[0]);

        for(int i=1;i<intervals.size();i++){
            int prevStart = temp.back()[0];
            int prevEnd = temp.back()[1];
            int currStart = intervals[i][0];
            int currEnd = intervals[i][1];

            if(currStart< prevEnd){
                if(prevEnd > currEnd){
                    temp.pop_back();
                }else{
                    continue;
                }
            }
            temp.push_back(intervals[i]);
            
        }
    
        return intervals.size() - temp.size() ;
    }
};