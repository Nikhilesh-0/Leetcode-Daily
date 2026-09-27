class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        
        vector<vector<string>> result;
        int left = 0;
        int right = products.size() - 1;
        
        for (int i = 0; i < searchWord.length(); ++i) {
            char c = searchWord[i];
            
            while (left <= right && (products[left].length() <= i || products[left][i] != c)) {
                left++;
            }
            
            while (left <= right && (products[right].length() <= i || products[right][i] != c)) {
                right--;
            }
            
            vector<string> currentSuggestions;
            for (int j = 0; j < 3 && left + j <= right; ++j) {
                currentSuggestions.push_back(products[left + j]);
            }
            
            result.push_back(currentSuggestions);
        }
        
        return result;
    }
};
