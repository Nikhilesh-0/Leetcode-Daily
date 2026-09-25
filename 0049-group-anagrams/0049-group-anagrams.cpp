class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagramMap;
        
        for (string s : strs) {
            string sorted_s = s;
            sort(sorted_s.begin(), sorted_s.end()); 
            
            anagramMap[sorted_s].push_back(s); 
        }
        
        vector<vector<string>> result;
        for (auto& pair : anagramMap) {
            result.push_back(pair.second);
        }
        
        return result;
    }
};
