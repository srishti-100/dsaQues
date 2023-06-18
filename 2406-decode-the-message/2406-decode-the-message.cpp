class Solution {
public:
    string decodeMessage(string key, string message) {
         string A="",B="",C="",D="";
        for(int i=0;i<key.size();i++){
            if(key[i]!=' ')
                A+=key[i];
        }
        for(int i=0;i<A.size();i++){
            int j;
            for(j=0;j<i;j++){
                if(A[i]==A[j]){   
                    break;  
                }           
            }
            if(j==i){        
                B+=A[i];  
            }             
        }
        C=B;
        sort(C.begin(),C.end());
        for(int i=0;i<message.size();i++){
            if(message[i]==' ')
                D+=' ';
            for(int j=0;j<B.size();j++){
                if(message[i]==B[j]){
                    D+=C[j];
                    break;
                }
            }
        }
        return D;
    }
};