class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i=0; i<n-2; ++i) {
            if(i>0 && nums[i] == nums[i-1]) continue;
            int low = i+1;
            int high = n-1;
            while (low < high) {
                if (-nums[i] == nums[low] + nums[high]) {
                    ans.push_back({nums[i], nums[low], nums[high]});
                    low++;
                    high--;
                    while (nums[low] == nums[low-1] && low<high) {
                        low++;
                    }
                    while (nums[high] == nums[high+1] && high>low) {
                        high--;
                    }
                } else if (-nums[i] < nums[low] + nums[high]) {
                    high--;
                } else {
                    low++;
                }
            }
        }
        return ans;
    }
};