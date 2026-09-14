class Solution {
public:
    vector<vector<int>> ans;
    void find (int i, vector<int> &nums) {
        if (i >= nums.size()) {
            ans.push_back(nums);
            return;
        }
        for (int j=i; j<nums.size(); ++j) {
            swap(nums[i], nums[j]);
            find(i+1, nums);
            swap(nums[i], nums[j]);
        }
        return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        find(0, nums);
        return ans;
    }
};