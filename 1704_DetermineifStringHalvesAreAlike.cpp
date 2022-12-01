class Solution {
private:
    unsigned int nVowels(string s){
        // uppercase 
        for(unsigned int i=0; i<s.size(); i++)
            if(s[i] >= 'a') s[i] = s[i] - ('a' - 'A');

        // count number of vowels
        unsigned int n = 0;
        for(unsigned int i=0; i<s.size(); i++)
            if(s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
                n = n + 1;
        
        return n;
    }
public:
    bool halvesAreAlike(string s) {
        // split into two half
        string a = s.substr(0, s.size()/2);
        string b = s.substr(s.size()/2, s.size()/2);

        // number of vowels 
        return nVowels(a)==nVowels(b);
    }
};