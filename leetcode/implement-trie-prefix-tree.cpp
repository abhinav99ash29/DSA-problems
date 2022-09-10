class Trie {
    bool word;
    vector<Trie*> next;
public:
    Trie() {
        word = false;
        next.resize(26,nullptr);
    }
    
    void insert(string word) {
        Trie* node = this;
        for(char &ch: word) {
            ch-='a';
            if (!node->next[ch]) {
                node->next[ch] = new Trie();
                node = node->next[ch];
            } else {
                node = node->next[ch];
            }
        }
        node->word = true;
        
    }
    
    bool search(string word) {
        Trie* node = this;
        for(char &ch: word) {
            ch-='a';
            if (!node->next[ch]) {
                return false;
            } else {
                node = node->next[ch];
            }
        }
        return node->word;
    }
    
    bool startsWith(string prefix) {
        Trie* node = this;
        for(char &ch: prefix) {
            ch-='a';
            if (!node->next[ch]) {
                return false;
            } else {
                node = node->next[ch];
            }
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
