class Solution {
public:
    void sortColors(vector<int>& nums) {
        int x = 0;
        int y = 0;
        int z = 0;

        for (auto num: nums) {
            if (num==0) x++;
            else if (num==1) y++;
            else z++;
        }
        for (int i=0;i<nums.size(); ++i) {
            if(x > 0) {
                nums[i] = 0;
                x--;
            } else if (y > 0) {
                nums[i] = 1;
                y--;
            } else {
                nums[i] = 2;
            }

        }
    }
};