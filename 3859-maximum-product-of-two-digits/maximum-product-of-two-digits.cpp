class Solution {
public:
    int maxProduct(int n) {
        string str = to_string(n);
        sort(str.begin(),str.end());
        int a = str.back()-'0';
        int b = str[str.size()-2]-'0';
        return a*b;
    }
};