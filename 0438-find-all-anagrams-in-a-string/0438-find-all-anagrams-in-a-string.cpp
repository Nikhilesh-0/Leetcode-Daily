class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        int n = s.size(), m = p.size();
        if (n < m) return result;

        vector<int> p_count(26, 0), s_count(26, 0);

        // Build frequency of p and the first window of s
        for (int i = 0; i < m; i++) {
            p_count[p[i] - 'a']++;
            s_count[s[i] - 'a']++;
        }

        // Check the first window
        if (p_count == s_count) result.push_back(0);

        // Slide the window
        for (int i = m; i < n; i++) {
            // Add the new character
            s_count[s[i] - 'a']++;
            // Remove the character that is leaving the window
            s_count[s[i - m] - 'a']--;

            if (p_count == s_count) {
                result.push_back(i - m + 1);
            }
        }

        return result;
    }
};