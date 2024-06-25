class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){
            return false;
        }
        long num = 0;

        int y = x;

        while(y!=0){
            num = num*10 +(y%10);
            y/=10;
        }

        if(x==num) return true;
        return false;

    }
};