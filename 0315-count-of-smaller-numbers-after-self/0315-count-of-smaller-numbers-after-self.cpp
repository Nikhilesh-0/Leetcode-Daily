class Solution {
public:
    void mergeAndCount(vector<pair<int, int>>& arr, int start, int mid, int end, vector<int>& counts) {
        vector<pair<int, int>> temp(end - start + 1);
        int left = start, right = mid + 1;
        int k = 0;
        int rightSmallerCount = 0;

        while (left <= mid && right <= end) {
            if (arr[right].first < arr[left].first) {
                rightSmallerCount++;
                temp[k++] = arr[right++];
            } else {
                counts[arr[left].second] += rightSmallerCount;
                temp[k++] = arr[left++];
            }
        }

        while (left <= mid) {
            counts[arr[left].second] += rightSmallerCount;
            temp[k++] = arr[left++];
        }

        while (right <= end) {
            temp[k++] = arr[right++];
        }

        for (int i = start; i <= end; i++) {
            arr[i] = temp[i - start];
        }
    }

    void mergeSort(vector<pair<int, int>>& arr, int start, int end, vector<int>& counts) {
        if (start >= end) return;

        int mid = start + (end - start) / 2;
        mergeSort(arr, start, mid, counts);
        mergeSort(arr, mid + 1, end, counts);
        mergeAndCount(arr, start, mid, end, counts);
    }

    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> counts(n, 0);
        vector<pair<int, int>> arr(n);

        for (int i = 0; i < n; i++) {
            arr[i] = {nums[i], i};
        }

        mergeSort(arr, 0, n - 1, counts);
        return counts;
    }
};
