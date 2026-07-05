class Solution {
public:
    double myPow(double x, int n) {

        /*
        if(x==1) return x;
        bool flag = true;
        if(n<0){
            flag = false;
        }

        double ans = 1;
        for(int i =0; i<abs(n); i++){
            ans = ans*x;
        }

        if(flag) return ans;
        return 1/ans;
        */
        if(x==0) return x;
        long nn = n;
        if(n<0) nn = -1*nn;
        double ans = 1;
        while(nn!=0){
            if(nn%2==0){
                x = x*x;
                nn = nn/2;
            }
            else{
                ans = ans*x;
                nn= nn-1;
            }
        }
        if(n>0)
            return ans;
        return (long)1/ans;
    }
};