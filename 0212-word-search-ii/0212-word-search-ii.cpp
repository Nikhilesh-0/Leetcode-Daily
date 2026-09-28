#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    struct TrieNode {
        TrieNode* children[26];
        string word = ""; 
        
        TrieNode() {
            for (int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
        }
    };

    void insertWord(TrieNode* root, const string& word) {
        TrieNode* curr = root;
        for (char ch : word) {
            int index = ch - 'a';
            if (!curr->children[index]) {
                curr->children[index] = new TrieNode();
            }
            curr = curr->children[index];
        }
        curr->word = word;
    }

    void dfs(vector<vector<char>>& board, int r, int c, TrieNode* curr, vector<string>& result) {
        char ch = board[r][c];
        int index = ch - 'a';
        
        if (!curr->children[index]) return;
        
        curr = curr->children[index];
        
        if (!curr->word.empty()) {
            result.push_back(curr->word);
            curr->word = ""; 
        }

        board[r][c] = '#';

        int dRow[] = {-1, 1, 0, 0};
        int dCol[] = {0, 0, -1, 1};

        for (int i = 0; i < 4; i++) {
            int newR = r + dRow[i];
            int newC = c + dCol[i];

            if (newR >= 0 && newR < board.size() && newC >= 0 && newC < board[0].size() && board[newR][newC] != '#') {
                dfs(board, newR, newC, curr, result);
            }
        }

        board[r][c] = ch;
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();
        for (const string& word : words) {
            insertWord(root, word);
        }

        vector<string> result;
        int rows = board.size();
        int cols = board[0].size();

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                dfs(board, r, c, root, result);
            }
        }

        return result;
    }
};
