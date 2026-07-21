class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int>lastIndex(26);
        vector<bool> selected(26);

        //store the last index
        for(int i=0; i<s.length();i++)lastIndex[s[i]-'a']=i;

        string str = "";
        for(int i=0;i<s.length();i++){
            if(selected[s[i]-'a'])continue;

            while(str.length()>0 && str.back()>s[i] && lastIndex[str.back()-'a']>i){//can be included later
                selected[str.back()-'a']=0;
                str.pop_back();
            }
            str+=s[i];
            selected[s[i]-'a']=1;
            
        }


        return str;


    }
};