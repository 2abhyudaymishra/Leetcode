class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int count= 0;
        int prev=0;
        for(int i=1;i<intervals.size();i++){
            int prevStart = intervals[prev][0];
            int prevEnd = intervals[prev][1];
            int currStart = intervals[i][0];
            int currEnd = intervals[i][1];

            if(currStart< prevEnd){
                if(currEnd < prevEnd){
                    prev = i;
                }else{
                    //dont change prev;
                }
                count++;
            }else{
                prev= i;
            }
        }
    
        return count;
    }
};