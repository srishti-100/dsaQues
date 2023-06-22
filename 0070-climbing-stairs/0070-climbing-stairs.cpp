class Solution {
public:
//tle
/*
    void helper(int n,int& count){
        if(n==0){
            count++;
            return;
        }
        if(n<0) return;

        helper(n-1,count);
        helper(n-2,count);
    }
    int climbStairs(int n) {
        int count =0;
       helper(n,count);
       return count;
    }
    */
    //memoization
    /*
    int helper(int n,vector<int>& count){
        if(n==0){
            return 1;
        }
        if(n<0) return 0;
        if(count[n]!=-1){
            return count[n];
        }
        int ans1 = helper(n-1,count);
        int ans2 = helper(n-2,count);
        count[n]=ans1+ans2;
        return count[n];
    }


    int climbStairs(int n) {
        vector<int> count(n+1,-1);
       int ans = helper(n,count);
       return count[n];
    }
    */
    int climbStairs(int n) {
        vector<int> count(n+1,0);
       count[0]=1;
       count[1] = 1;

       for(int i =2; i<n+1; i++){
           count[i]= count[i-1]+count[i-2];
       }

       return count[n];
    }
};