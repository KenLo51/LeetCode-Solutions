class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        // hash table of N-occurrences
        unordered_map<int,unsigned int> occurrences;
        for(int value : arr){
            if(occurrences.count(value))
                occurrences[value] += 1;
            else
                occurrences[value] = 0;
        }

        // copy to vector
        vector<unsigned int> Noccurrence;
        for ( auto it = occurrences.begin(); it != occurrences.end(); ++it )
            Noccurrence.push_back(it->second);

        // sort the number of occurrences
        sort (Noccurrence.begin(), Noccurrence.end());

        // check same number
        for(unsigned int i=0; i<(Noccurrence.size()-1); i++)
            if(Noccurrence[i] == Noccurrence[i+1]) return false;
        return true;
    }
};