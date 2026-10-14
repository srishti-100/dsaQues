class Solution {
public:
    int myAtoi(string s) {
        //remove leading spaces
        int i =0;
        int m = s.length();
        while(i<m && s[i]==' ') i++;
        string t = s.substr(i);

        //remove trailing spaces
        int n = t.length();
        i = n-1;
        while(i>=0 && t[i]==' ') i--;

        t = t.substr(0,i+1);

        if(t.empty()) return 0;

        char ch = t[0];
        bool neg = false; 
        int start = 0;
        if(ch=='-'){
            neg = true;
            start = 1;
        }
        else if(ch=='+'){
            neg = false;
            start = 1;
        }
        else if(!(ch >= '0' && ch <= '9')) {
            return 0; 
        }

        long long num = 0;

        if(neg){
            for(int i = start; i<t.length(); i++){
                if(!(t[i]>='0' && t[i]<='9')) break;
                int digit = t[i]-'0';

                if(num > (-(long long)INT_MIN-digit)/10){
                    return INT_MIN;
                }

                num = (num*10) + digit;
                
            }
        }
        else{
            for(int i = start; i<t.length(); i++){
                if(!(t[i]>='0' && t[i]<='9')) break;
                int digit = t[i]-'0';

                if(num > ((long long)INT_MAX - digit)/10){
                    return INT_MAX;
                }
                num = (num*10) + digit;
                
            }
        }

        if(neg){
            if(num > (long long)INT_MAX +1) return INT_MIN;
            return (int)(-num);
        } 
        if(num > (long long)INT_MAX) return INT_MAX;
        return (int)num;
    }
};