unordered_map<string,int> * frequenciesPtr;
class Solution {
public:
    //lexicographical order 
    static bool compFunction(string i1, string i2){
        if((*frequenciesPtr)[i1] == (*frequenciesPtr)[i2]){
            int len = (i1.length() > i2.length())? i2.length() : i1.length();
            for(int i=0; i<len; i++){
                if(i1[i] == i2[i]) continue;
                return i1[i] < i2[i];
            }
            return i1.length() < i2.length();
        }
        return (*frequenciesPtr)[i1] > (*frequenciesPtr)[i2];
    }
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> frequencies;
        
        for(string word : words){
            // if the word has been appeared
            if(frequencies.count(word) == 0){
                frequencies.insert( {{word,1}} ); 
                continue;
            }
            // <word> is a new word
            frequencies[word] = frequencies[word] + 1;
        }
        
        // build array
        vector<string> resultArr;
        vector<int> freqArr;
        vector<int> indicesArr;
        for ( auto it = frequencies.begin(); it != frequencies.end(); ++it ){
            resultArr.push_back(it->first);
            freqArr.push_back(it->second);
            indicesArr.push_back(indicesArr.size());
        }
        
        // sort by frequencies
        frequenciesPtr = &frequencies;
        sort(resultArr.begin(), resultArr.end(), compFunction);
        
        // cut-off
        resultArr.resize(k);
        
        return resultArr;
    }
};