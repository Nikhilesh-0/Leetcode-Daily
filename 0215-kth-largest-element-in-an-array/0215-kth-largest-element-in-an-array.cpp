class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int targetIdx = nums.size() - k; 
        return quickselect(nums, 0, nums.size() - 1, targetIdx);
    }

    int quickselect(vector<int>& nums, int left, int right, int targetIdx) {
        if (left == right) return nums[left];
        
        int pivotIdx = left + (right - left) / 2;
        int pivotValue = nums[pivotIdx];
        
        int i = left - 1;
        int j = right + 1;
        
        while (true) {
            do { i++; } while (nums[i] < pivotValue);
            do { j--; } while (nums[j] > pivotValue);
            if (i >= j) break;
            swap(nums[i], nums[j]);
        }
        
        if (targetIdx <= j) {
            return quickselect(nums, left, j, targetIdx);
        } else {
            return quickselect(nums, j + 1, right, targetIdx);
        }
    }
};
