class Trie {
    public: 
    vector<Trie*> child;
    bool isSuffix;
    Trie() {
        child.resize(26,NULL);
        isSuffix = false;
    }
};


class Solution {
    Trie* root;
    map<Trie*, int> mp;
public:
    Solution() {
        root = new Trie();
    }
    
    Trie* add(Trie* root, char c) {
        root->isSuffix = true;
        if (root->child[c-'a']) {
            return root->child[c-'a'];
        }
        return root->child[c-'a'] = new Trie();
        
    }
    
    int minimumLengthEncoding(vector<string>& words) {
        for(string& s: words) {
            Trie* curr = root;
            for(int i=s.size()-1;i>=0;i--) {
                curr = add(curr,s[i]);
            }
            mp[curr] = s.size();
        }
        int ans = 0;
        for(auto m: mp) {
           if (!m.first->isSuffix) {
               m.first->isSuffix = true;
               ans+=m.second+1;
           }
        }
        return ans;
    }
};
