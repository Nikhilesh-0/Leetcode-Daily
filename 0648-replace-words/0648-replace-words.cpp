#include <vector>
#include <string>
#include <sstream>

using namespace std;

struct TrieNode {
    TrieNode* children[26] = {nullptr};
    bool isEnd = false;
};

class Solution {
private:
    void insert(TrieNode* root, const string& word) {
        TrieNode* curr = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!curr->children[idx]) {
                curr->children[idx] = new TrieNode();
            }
            curr = curr->children[idx];
        }
        curr->isEnd = true;
    }

    string findRoot(TrieNode* root, const string& word) {
        TrieNode* curr = root;
        string prefix = "";
        for (char c : word) {
            int idx = c - 'a';
            if (!curr->children[idx]) break;
            
            prefix += c;
            curr = curr->children[idx];
            
            if (curr->isEnd) return prefix;
        }
        return word; 
    }

public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        TrieNode* root = new TrieNode();
        
        for (const string& word : dictionary) {
            insert(root, word);
        }
        
        stringstream ss(sentence);
        string word;
        string result = "";
        
        while (ss >> word) {
            if (!result.empty()) {
                result += " ";
            }
            result += findRoot(root, word);
        }
        
        return result;
    }
};
