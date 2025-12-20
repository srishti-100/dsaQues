class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int rows = strs.size();
        int cols = strs[0].length();
        bool flag = true;
        int count = 0;

        for(int i = 0; i<cols; i++){
            for(int j = 0; j<rows-1; j++){
                if(strs[j][i] > strs[j+1][i]){
                    flag  = false;  
                    break;
                }
            }
            if(flag == false){
                count++;
            }
            flag = true;
        }
        return count;
    }
};