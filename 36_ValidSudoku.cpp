class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        std::set<char> appearedSet;

        // check each row
        for(unsigned int row=0; row<9; row++){
            appearedSet.clear();
            for(unsigned int col=0; col<9; col++){
                char currDigit = board[row][col];
                if(currDigit == '.') continue; // not a number
                if(appearedSet.count(currDigit)) return false; // number is repeat in current row
                appearedSet.insert(currDigit); // add number to set
            }
        }
        // check each column
        for(unsigned int col=0; col<9; col++){
            appearedSet.clear();
            for(unsigned int row=0; row<9; row++){
                char currDigit = board[row][col];
                if(currDigit == '.') continue; // not a number
                if(appearedSet.count(currDigit)) return false; // number is repeat in current row
                appearedSet.insert(currDigit); // add number to set
            }
        }
        // check sub-boxes
        for(unsigned int boxIdx=0; boxIdx<9; boxIdx++){
            appearedSet.clear();
            for(unsigned int digitOffset=0; digitOffset<9; digitOffset++){
                // transform index
                unsigned int row = ((boxIdx / 3) * 3) + (digitOffset / 3);
                unsigned int col = ((boxIdx % 3) * 3) + (digitOffset % 3);

                char currDigit = board[row][col];
                if(currDigit == '.') continue; // not a number
                if(appearedSet.count(currDigit)) return false; // number is repeat in current row
                appearedSet.insert(currDigit); // add number to set
            }
        }
        return true;
    }
};