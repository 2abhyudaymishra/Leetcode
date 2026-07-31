class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char, int>frequencyMap;
        int pushes = 0;
        priority_queue<int>pq;
        //count and character map;
        for(auto ch : word)frequencyMap[ch]++;

        //dec order as per their frequency
        for(auto it : frequencyMap)pq.push(it.second);

        int numKey=2;
        int step=1;
        while(!pq.empty()){
            int count = pq.top();
            pq.pop();
            pushes+=(step * count);
            numKey++;
            if(numKey==10){
                numKey=2;
                step++;
            }
        }

        return pushes;
    }
};