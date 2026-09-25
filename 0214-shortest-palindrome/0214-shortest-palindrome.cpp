class Solution {
public:
    string shortestPalindrome(string s) {
        string rev_s = s;
        reverse(rev_s.begin(), rev_s.end());
        
        string combined = s + "#" + rev_s;
        int n = combined.length();
        
        vector<int> pi(n, 0);
        for (int i = 1; i < n; i++) {
            int j = pi[i - 1];
            while (j > 0 && combined[i] != combined[j]) {
                j = pi[j - 1];
            }
            if (combined[i] == combined[j]) {
                j++;
            }
            pi[i] = j;
        }
        
        int longest_palindrome_len = pi[n - 1];
        
        string suffix_to_add = s.substr(longest_palindrome_len);
        reverse(suffix_to_add.begin(), suffix_to_add.end());
        
        return suffix_to_add + s;
    }
};
