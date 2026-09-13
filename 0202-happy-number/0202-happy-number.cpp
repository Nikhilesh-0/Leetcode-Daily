class Solution {
public:
    bool isHappy(int n) {
        vector<int> nums;
        int num = n;
        int sum = 0;
        while (num) {
            int digit = num%10;
            num = num/10;
            sum += digit*digit;
            if (num == 0) {
                if (sum == 1) return true;
                if (find(nums.begin(), nums.end(), sum) != nums.end() || sum==n) return false;
                nums.push_back(sum);
                num = sum;
                sum = 0;
            }
        }
        return false;
    }
};