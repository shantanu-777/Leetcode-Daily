// TrieNode class representing each node in the Trie
class TrieNode {
public:
    TrieNode* children[26];  // Array to store child nodes (26 letters in English)
    bool isEndOfWord;        // Marks end of a valid word
    string word;             // Stores the word at end node

    TrieNode() {
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;  // Initialize all children as NULL
        }
        isEndOfWord = false;
        word = "";
    }
};

// Trie class to store words efficiently
class Trie {
public:
    TrieNode* root;  // Root of Trie
    vector<string> ans;  // Stores words found in the board

    Trie() { root = new TrieNode(); }  // Constructor initializes root node

    // Insert a word into the Trie
    void insert(string& word) {
        TrieNode* node = root;
        for (auto ch : word) {
            int index = ch - 'a';  // Convert character to index
            if (node->children[index] == NULL) {
                node->children[index] = new TrieNode();  // Create new TrieNode if not exists
            }
            node = node->children[index];  // Move to next node
        }
        node->isEndOfWord = true;  // Mark end of word
        node->word = word;         // Store word at the end node
    }

    // Direction vectors for moving in 4 directions (up, down, left, right)
    int x[4] = {1, -1, 0, 0};
    int y[4] = {0, 0, 1, -1};

    // Function to check if a word exists in the board using Trie
    void check(vector<vector<char>>& board, int i, int j, int n, int m, TrieNode* node) {
        // Boundary conditions and pruning if character is already visited
        if (i >= n || i < 0 || j >= m || j < 0) return;
        if (board[i][j] == '#' || node->children[board[i][j] - 'a'] == NULL) return;

        node = node->children[board[i][j] - 'a'];  // Move to the next Trie node

        // If a word is found in Trie, add to result list
        if (node->isEndOfWord) {
            ans.push_back(node->word);
            node->isEndOfWord = false;  // Mark as found to avoid duplicates
        }

        char temp = board[i][j];  // Store current character
        board[i][j] = '#';        // Mark cell as visited

        // Explore all 4 directions
        for (int k = 0; k < 4; k++) {
            int nx = i + x[k];
            int ny = j + y[k];
            check(board, nx, ny, n, m, node);
        }

        board[i][j] = temp;  // Restore character after backtracking
    }
};

// Solution class to find words in the board
class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int n = board.size();
        int m = board[0].size();

        Trie* tr = new Trie();  // Create Trie instance

        // Insert all words into the Trie
        for (auto word : words) {
            tr->insert(word);
        }

        // Start DFS from each cell in the board
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                tr->check(board, i, j, n, m, tr->root);
            }
        }

        return tr->ans;  // Return list of words found in board
    }
};
//Time Complexity:O(W * L + N * M * 4^L)
//W = Number of words
//L = Average word length
//N, M = Dimensions of board