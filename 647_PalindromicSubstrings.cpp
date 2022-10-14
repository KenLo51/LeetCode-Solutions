class Solution {
public:
    bool isPalindromic(string s){
        for(int i=0; i<s.length()/2; i++){
            if(s[i] != s[s.length()-i-1]) return false;
        }
        return true;
    }
    int countSubstrings(string s) {
        int num = 0;
        for(int i=0; i<s.length(); i++){
            for(int j=i+1; j<=s.length(); j++){
                if(isPalindromic( s.substr(i,j-i) )){
                    num++;
                }
            }
        }
        return num;
    }
};