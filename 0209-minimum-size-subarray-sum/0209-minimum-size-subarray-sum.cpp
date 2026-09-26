class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0, sum=0;
        int minK = INT_MAX;
        for (int right=0; right<nums.size(); ++right) {
            sum += nums[right];
            while (sum >= target) {
                minK = min(right - left + 1, minK);
                sum -= nums[left];
                left++;
            }
        }
        if (minK == INT_MAX) return 0;
        return minK;
    }
};