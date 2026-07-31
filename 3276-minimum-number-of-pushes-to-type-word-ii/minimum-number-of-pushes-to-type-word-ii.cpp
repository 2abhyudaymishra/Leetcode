class Solution {
public:
    int minimumPushes(string word) {
        int total_pushes = 0;
        vector<int>freq (26, 0);
        //count and character map;
        for(auto ch : word)freq[ch-'a']++;

        //dec order as per their frequency
        sort(freq.begin(), freq.end(), greater<int>());

        //count pushes as per the order in key pad
        for(int i=0;i<26;i++){
            cout<<freq[i]<<" ";
            if(freq[i]==0)break;
            total_pushes += freq[i]* ( (i/8)+1 );
        }

        return total_pushes;
    }
};