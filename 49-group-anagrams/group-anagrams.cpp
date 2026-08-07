class Solution {
public:
    string codeString(string str){
        vector<int> hash(26);
        for(auto ch : str){
            hash[ch-'a']++;
        }

        string s;
        for(int i=0; i< 26; i++){
            if(hash[i]!=0){
                s.push_back(i+'a');
                s.push_back(hash[i]+'0');
            }
        }
        return s;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mp;
        for(auto str : strs){
            string code = codeString(str);
            mp[code].push_back(str);
        }
        vector<vector<string>> ans;
        for(auto it: mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};