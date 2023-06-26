
class Solution {
public:
    long long totalCost(vector<int>& arr, int k, int candidates) {
        long long cost = 0;
        int n = arr.size();

        int next_head = candidates;
        int next_tail = n-candidates-1;

        priority_queue<int, vector<int>, greater<int>> pq1;
        priority_queue<int, vector<int>, greater<int>> pq2;

         for(int j =0; j<candidates; j++){
                    pq1.push(arr[j]);
                }
        int des = max(n-candidates, candidates);
        for(int j =n-1; j>=des; j--){
            pq2.push(arr[j]);
        }

        for(int i =0; i<k; i++){
            if(next_head<=next_tail){
                if(pq2.empty()||!pq1.empty() && pq1.top()<=pq2.top()){
                    cost+=pq1.top();
                    pq1.pop();
                    pq1.push(arr[next_head]);
                    next_head++;
                }
                else{
                    cost+=pq2.top();
                    pq2.pop();
                    pq2.push(arr[next_tail]);
                    next_tail--;
                }
                
            }
            else{
                if(pq2.empty()||!pq1.empty() && pq1.top()<=pq2.top()){
                    cost+=pq1.top();
                    pq1.pop();                   
                }
                else{
                    cost+=pq2.top();
                    pq2.pop();
                }
                
            }

        }

        return cost;

    }
};