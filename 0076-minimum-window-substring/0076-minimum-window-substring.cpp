class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty() || s.length() < t.length()) return "";

        unordered_map<char, int> t_freq;
        for (char c : t) t_freq[c]++;

        unordered_map<char, int> window_freq;
        int left = 0, right = 0;
        int required_unique_chars = t_freq.size();
        int formed_unique_chars = 0;

        int min_len = INT_MAX;
        int start_idx = 0;

        while (right < s.length()) {
            char c = s[right];
            window_freq[c]++;

            if (t_freq.count(c) && window_freq[c] == t_freq[c]) {
                formed_unique_chars++;
            }

            while (formed_unique_chars == required_unique_chars) {
                if (right - left + 1 < min_len) {
                    min_len = right - left + 1;
                    start_idx = left;
                }

                char left_char = s[left];
                window_freq[left_char]--;

                if (t_freq.count(left_char) && window_freq[left_char] < t_freq[left_char]) {
                    formed_unique_chars--;
                }
                left++;
            }
            right++;
        }

        return min_len == INT_MAX ? "" : s.substr(start_idx, min_len);
    }
};
