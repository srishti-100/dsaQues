class Solution {
public:
    vector<int> nse(vector<int> arr){
        stack<int> st;

        int n = arr.size();
        vector<int> ans(n,-1);

        for(int i = n-1; i>=0; i--){
            while(!st.empty()){
                if(arr[st.top()] < arr[i]){
                    ans[i] = st.top();
                    break;
                }
                else{
                    st.pop();
                }
            }
            st.push(i);
        }

        for(int i =0; i<n; i++) if(ans[i]==-1) ans[i]=n;
        return ans;

    }

    vector<int> pse(vector<int> arr){
        stack<int> st;

        int n = arr.size();
        vector<int> ans(n,-1);

        for(int i = 0; i<n; i++){
            while(!st.empty()){
                if(arr[st.top()] < arr[i]){
                    ans[i] = st.top();
                    break;
                }
                else{
                    st.pop();
                }
            }
            st.push(i);
        }


        return ans;

    }

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int maxArea = 0;
        vector<int> ns = nse(heights);
        vector<int> ps = pse(heights);

        for(int i =0; i<n; i++){
            int val = heights[i]*(ns[i]-ps[i]-1);
            maxArea = max(maxArea,val);
        }

        return maxArea;
    }
};