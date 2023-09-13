class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();

        vector<int> candies(n,1);
        //left pass
        //leave 0th index candy
        for(int i = 1; i<n; i++){
            if(ratings[i]>ratings[i-1])
                candies[i] = 1+candies[i-1];
        }

        //right pass
        //leave n-1th index candy
        for(int i = n-2; i>=0; i--){
            if(ratings[i]>ratings[i+1]){
                candies[i]=max(candies[i],1+candies[i+1]);
            }
        }

        int sum =0;
        for(int i =0; i<n; i++){
            sum+=candies[i];
        }

        return sum;

    }
};