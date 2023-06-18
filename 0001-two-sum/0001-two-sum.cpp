class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>> temp;
        for(int i =0; i<nums.size(); i++){
            temp.push_back(make_pair(nums[i],i));
        }

        sort(temp.begin(), temp.end());
        vector<int> ans;

        int i =0; int j = nums.size()-1;

        while(i<j){
            int sum = temp[i].first + temp[j].first;
            if(sum == target){
                ans.push_back(temp[i].second);
                ans.push_back(temp[j].second);
                break;
            }
            else if(sum<target) i++;
            else j--;
        }
        return ans;
    }
};