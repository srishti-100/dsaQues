class Solution {
public:
    int helper(int n){
        int mult = 1;

        while(n!=0){
            int r = n%10;
            mult *= r;
            n/=10;
        }
        return mult;
    }
    int smallestNumber(int n, int t) {
        for(int i = n; i<=100; i++){
            if(helper(i)%t==0){
                return i;
            }
        }
        return -1;
    }
};