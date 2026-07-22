class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int oneCount =0;
        for(auto it: s)if(it=='1')oneCount++;
        string t = "1" + s +"1";
        //asper Q first 
        //convert 1 within zeros 
        //convert 0 within one
        //so if we take make number of zeros containing one our prob is solve
        //eg -> 10011001 ->  10000001 -> 11111111  we directly count max-> 001100
        vector<pair<char,int>>arr; // count of contigous char 
        for(auto it: s){
            //diff char 
            if(arr.empty() || arr.back().first!=it){
                arr.push_back({it,1});
            }else{
                arr.back().second++;
            }
        }

        int maxTrade=0;
        for(int i=1; i+1<arr.size();i++){
            //this whole can be converted
            if(arr[i-1].first=='0' && arr[i].first=='1' && arr[i+1].first=='0'){
                maxTrade = max(maxTrade, arr[i-1].second+ arr[i+1].second);//one inise is already considered in one count;
            }
        }


        return oneCount + maxTrade;
    }
};