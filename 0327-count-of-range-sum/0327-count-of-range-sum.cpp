class Solution {
public:
    int mergeAndCount(vector<long long>& sums, int start, int mid, int end, int lower, int upper) {
        int count = 0;
        int lowBound = mid + 1;
        int highBound = mid + 1;

        for (int i = start; i <= mid; i++) {
            while (lowBound <= end && sums[lowBound] - sums[i] < lower) {
                lowBound++;
            }
            while (highBound <= end && sums[highBound] - sums[i] <= upper) {
                highBound++;
            }
            count += (highBound - lowBound);
        }

        vector<long long> temp;
        int left = start, right = mid + 1;

        while (left <= mid && right <= end) {
            if (sums[left] <= sums[right]) {
                temp.push_back(sums[left++]);
            } else {
                temp.push_back(sums[right++]);
            }
        }

        while (left <= mid) temp.push_back(sums[left++]);
        while (right <= end) temp.push_back(sums[right++]);

        for (int i = start; i <= end; i++) {
            sums[i] = temp[i - start];
        }

        return count;
    }

    int mergeSort(vector<long long>& sums, int start, int end, int lower, int upper) {
        if (start >= end) return 0;

        int mid = start + (end - start) / 2;
        int count = mergeSort(sums, start, mid, lower, upper);
        count += mergeSort(sums, mid + 1, end, lower, upper);
        count += mergeAndCount(sums, start, mid, end, lower, upper);

        return count;
    }

    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        vector<long long> sums(n + 1, 0);
        
        for (int i = 0; i < n; i++) {
            sums[i + 1] = sums[i] + nums[i];
        }

        return mergeSort(sums, 0, n, lower, upper);
    }
};
