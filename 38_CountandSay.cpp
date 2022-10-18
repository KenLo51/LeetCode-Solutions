class Solution {
public:
    int runLength(char *str){
        if(*str == '\0') return 0;
        int length;
        for(length=1; str[length]==str[0]; length++);
        return length;
    }
    string countAndSay(int n) {
        string result("1");
        for(int i=1; i<n; i++){
            string newResult;
            
            char* resultCstr = (char*)result.c_str();
            while(*resultCstr != '\0'){
                int l = runLength(resultCstr);
                newResult += (char)(l+'0');
                newResult += (char)(*resultCstr);
                resultCstr += l;
            }
            result = newResult;
        }
        return result;
    }
};