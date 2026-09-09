class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        
        sort(nums.begin(), nums.end());
        
        int closestSum = nums[0] + nums[1] + nums[2];
        
        for (int i = 0; i < n - 2; ++i) {
            int low = i + 1;
            int high = n - 1;
            
            while (low < high) {
                int currentSum = nums[i] + nums[low] + nums[high];
                
                if (currentSum == target) {
                    return currentSum;
                }
                
                if (abs(target - currentSum) < abs(target - closestSum)) {
                    closestSum = currentSum;
                }
                
                if (currentSum < target) {
                    low++;
                } else {
                    high--;
                }
            }
        }
        
        return closestSum;
    }
};
