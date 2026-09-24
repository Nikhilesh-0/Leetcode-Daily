class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> result;
        if (s.size() < 10) return result;

        unordered_set<string> seen;
        unordered_set<string> repeated;

        for (int i = 0; i <= s.size() - 10; i++) {
            string seq = s.substr(i, 10);
            if (seen.count(seq)) {
                repeated.insert(seq);
            } else {
                seen.insert(seq);
            }
        }

        for (const string& seq : repeated) {
            result.push_back(seq);
        }

        return result;
    }
};