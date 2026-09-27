#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
private:
    bool canForm(const string& word, const unordered_set<string>& wordSet) {
        if (wordSet.empty()) return false;
        
        int n = word.length();
        vector<bool> dp(n + 1, false);
        dp[0] = true; 
        
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (dp[j] && wordSet.count(word.substr(j, i - j))) {
                    dp[i] = true;
                    break; 
                }
            }
        }
        
        return dp[n];
    }

public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string& a, const string& b) {
            return a.length() < b.length();
        });
        
        unordered_set<string> wordSet;
        vector<string> result;
        
        for (const string& word : words) {
            if (canForm(word, wordSet)) {
                result.push_back(word);
            }
            wordSet.insert(word);
        }
        
        return result;
    }
};
