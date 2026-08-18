class Solution {
public:
    bool isPalindrome(string s) {
        string temp = "";
        for(auto it: s){
            if(it==' ')continue;
            int smaller = tolower(it)-'a';
            int number = tolower(it)-'0';
            if((smaller >=0 && smaller<26) || (number >=0 && number<=9) )temp.push_back(tolower(it));
        }
        cout<<temp;
        int start=0 ;
        int end = temp.length()-1;
        while(start<end){
            if(temp[start++]!=temp[end--])return false;
        }
        return true;
    }
};