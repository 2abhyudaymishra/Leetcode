class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        if(n==0){
            intervals.push_back(newInterval);
            return intervals;
        }

        int ind= 0;
        int newStart=newInterval[0];
        int newEnd=newInterval[1];
        while(ind< n && intervals[ind][1]<newStart)ind++;
        if(ind==n){
            intervals.push_back(newInterval);
            return intervals;
        }
        intervals.insert(intervals.begin()+ind, newInterval);
        n++;
        ind++;
        while(ind<n){
            int prevStart= intervals[ind-1][0];
            int prevEnd= intervals[ind-1][1];
            int currStart= intervals[ind][0];
            int currEnd = intervals[ind][1];
            if(currStart <= prevEnd){
                intervals[ind-1][0] = min(currStart, prevStart);
                intervals[ind-1][1]= max(prevEnd, currEnd);
                intervals.erase(intervals.begin()+ind);
                n--;
            }else{
                ind++;
            }

        }

        return intervals;


    }
};