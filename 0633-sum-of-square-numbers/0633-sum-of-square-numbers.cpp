class Solution {
public:
    bool judgeSquareSum(int c) {
        /*
        unordered_map<long, int> ump;

        for(int i=0; i<=sqrt(c); i++){
            ump[i*i]++;
            int req = c - i*i;

            if(ump[req]){
                return true;
            }
        }

        return false;
        */

        for(int i = 2; i<=sqrt(c); i++){
            if(c%i==0){
                int count = 0;
                while(c%i==0){
                    count++;
                    c=c/i;
                }
                if(i%4==3 && count%2!=0){
                    return false;
                }
            }
        }
        return c%4 != 3;
    
    }
};