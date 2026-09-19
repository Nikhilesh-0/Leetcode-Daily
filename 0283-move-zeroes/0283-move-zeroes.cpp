class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int w = 0;
        for (int r=0; r<nums.size(); ++r) {
            if (nums[r] != 0) {
                nums[w] = nums[r];
                ++w;
            }
        }
        while (w < nums.size()) {
            nums[w] = 0;
            ++w;
        }
    }
};