class Solution {
public:
    string decodeAtIndex(string s, int k) {
        /*
        string tape;

        for(int i =0; i<s.length(); i++){
            if(s[i]>=97 && s[i]<=122){
                tape+=s[i];
            }
            else{
                int cnt = int(s[i]-'0')-1;
                while(cnt>0){
                    tape+=tape;
                    cnt--;
                }
            }
        }
        string ans="";
        ans+=tape[k-1];
        return ans;
        */

        long long int length = 0;

        int i =0;
        while(length<k){
            if(s[i]>=97 && s[i]<=122){
                length++;
            }
            else{
                length*=s[i]-'0';
            }
            i++;
        }

        for(int j = i-1; j>=0; j--){
            if(s[j]>=97 && s[j]<=122){
                if(k==0 || k== length){
                    string ans="";
                    ans+=s[j];
                    return ans;
                   
                }
                 length--;
            }
            else{
                length/=s[j]-'0';
                k=k%length;
            }
        }
        return "";
    }
};