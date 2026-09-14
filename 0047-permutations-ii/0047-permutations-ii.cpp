class Solution {
public:
vector<vector<int>> ans;
    void find (int i, vector<int> &nums) {
        if (i >= nums.size()) {
            ans.push_back(nums);
            return;
        }
        unordered_set<int> st;
        for (int j=i; j<nums.size(); ++j) {
            if (st.find(nums[j]) != st.end()) continue;
            st.insert(nums[j]);
            swap(nums[i], nums[j]);
            find(i+1, nums);
            swap(nums[i], nums[j]);
        }
        return;
    }
        
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        find(0, nums);
        return ans;
    }
};