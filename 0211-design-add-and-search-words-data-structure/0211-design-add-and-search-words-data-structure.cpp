class WordDictionary {
public:
    struct TrieNode {
        TrieNode* children[26];
        bool isEndOfWord;
        
        TrieNode() {
            isEndOfWord = false;
            for (int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
        }
    };
    
    TrieNode* root;

    bool searchInNode(string& word, int index, TrieNode* node) {
        if (!node) return false;
        if (index == word.length()) return node->isEndOfWord;
        
        char ch = word[index];
        
        if (ch == '.') {
            for (int i = 0; i < 26; i++) {
                if (node->children[i] && searchInNode(word, index + 1, node->children[i])) {
                    return true;
                }
            }
            return false;
        } else {
            int childIndex = ch - 'a';
            return searchInNode(word, index + 1, node->children[childIndex]);
        }
    }

    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* curr = root;
        for (char ch : word) {
            int index = ch - 'a';
            if (curr->children[index] == nullptr) {
                curr->children[index] = new TrieNode();
            }
            curr = curr->children[index];
        }
        curr->isEndOfWord = true;
    }
    
    bool search(string word) {
        return searchInNode(word, 0, root);
    }
};
