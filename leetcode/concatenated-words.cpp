class Solution {
public:
    class Trie {
        public:
        vector<Trie*> child;
        bool word;
        Trie() {
            child.resize(26,nullptr);
            word = false;
        }
    };

    void addword(string word, Trie* root) {
        Trie* node = root;
        for(char& c: word) {
            if (node->child[c-'a']==nullptr) {
                node->child[c-'a'] = new Trie();
            }
            node = node->child[c-'a'];
        }
        node->word = true;
    }

    int check(Trie* root, string s, int i) {
        // cout<<s<<" "<<i<<endl;
        if (i>=s.size()) {
            // cout<<0<<endl;
            return 0;
        }
        int cnt = INT_MIN;
        Trie* node = root;
        while(i<s.size()) {
            node = node->child[s[i]-'a'];
            if (!node) {
                // cout<<"INT_MIN"<<endl;
                return INT_MIN;
            }
            if (node->word == true) {
                cnt = max(cnt, 1+check(root, s, i+1));
                if (cnt>1) break;
            }
            i++;
        }
        // cout<<cnt<<endl;
        return cnt;
    }

    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string> ans;
        Trie* root = new Trie();
        for(string& s: words) {
            addword(s, root);
        }
        for(string& s: words) {
            if (check(root, s, 0)>=2) ans.push_back(s);
        }
        return ans;
    }
};
