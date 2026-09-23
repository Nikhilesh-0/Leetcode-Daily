class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string doubled = s + s;        
        string middle = doubled.substr(1, doubled.length() - 2);
        
        return middle.find(s) != string::npos;
    }
};
