class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        string repeated = a;
        int count = 1;

        // Keep repeating a until its length is at least as long as b
        while (repeated.size() < b.size()) {
            repeated += a;
            count++;
        }

        // Check if b is already a substring
        if (repeated.find(b) != string::npos) {
            return count;
        }

        // One more repetition is sometimes needed (e.g. when b wraps around)
        repeated += a;
        count++;

        if (repeated.find(b) != string::npos) {
            return count;
        }

        // Still not found → impossible
        return -1;
    }
};