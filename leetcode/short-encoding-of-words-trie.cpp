class Trie {
    public: 
    vector<Trie*> child;
    bool isSuffix;
    bool isUsed;
    Trie() {
        child.resize(26,NULL);
        isSuffix = false;
        isUsed = false;
    }
};


class Solution {
    Trie* root;
public:
    Solution() {
        root = new Trie();
    }
    
    void add(Trie* root, string s, int i) {
        if (i==s.size()) {
            return;
        }
        if (root->child[s[i]-'a']) {
            root->isSuffix = true;
            add(root->child[s[i]-'a'],s,i+1);
        } else {
            root->child[s[i]-'a'] = new Trie();
            root->isSuffix = true;
            add(root->child[s[i]-'a'],s,i+1);
        }
    }
    
    bool isSuffix(Trie* root, string s, int i) {
        if (i==s.size()) {
            if (!root->isSuffix && !root->isUsed) {
                root->isUsed = true;
                return false;
            }
            return true;
        }
        if (root->child[s[i]-'a']) {
            return isSuffix(root->child[s[i]-'a'],s,i+1);
        }
        
        return false;
    }
    
    int minimumLengthEncoding(vector<string>& words) {
        for(string& s: words) {
            reverse(s.begin(), s.end());
            add(root,s,0);
        }
        string ans = "";
        for(string& s: words) {
            if (!isSuffix(root,s,0)) {
                reverse(s.begin(),s.end());
                ans+=s+'#';
            }
        }
        return ans.size();
    }
};
