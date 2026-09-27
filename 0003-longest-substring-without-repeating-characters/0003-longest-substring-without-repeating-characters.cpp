class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> lastIdx(256, -1);
        
        int maxLength = 0;
        int left = 0; 
        
        for (int right = 0; right < s.length(); ++right) {
            if (lastIdx[s[right]] >= left) {
                left = lastIdx[s[right]] + 1;
            }
            
            lastIdx[s[right]] = right;
            
            maxLength = max(maxLength, right - left + 1);
        }
        
        return maxLength;
    }
};
