class Solution {
    vector<int> sol;
public:
    
    void fn(int left, int n, string s, int sublen, int wlen, map<string, int>& wordcount) {
        map<string, int> wordfound;
        int wused = 0;
        bool excess = false;
        for(int right=left;right<s.size()-wlen+1;right+=wlen) {
            string sub = s.substr(right,wlen);
            if (wordcount.count(sub)==0) {
                wused=0;
                excess = false;
                left = right+wlen;
                wordfound.clear();
                continue;
            } else {
                while (right-left == sublen || excess) {
                    string lw = s.substr(left,wlen);
                    left+=wlen;
                    wordfound[lw]--;
                    if (wordfound[lw]==wordcount[lw]) {
                        excess=false;
                    } else {
                        wused--;
                    }
                }
            }
            wordfound[sub]++;
            if(wordfound[sub]<=wordcount[sub]) {
                wused++;
            } else {
                excess=true;
            }
            if (wused == n && !excess) {
                    sol.push_back(left);
            }
        }
    }
    
    vector<int> findSubstring(string s, vector<string>& words) {
        int n = words.size();
        int wlen = words[0].size();
        int sublen = wlen*n;
        map<string, int> wordcount;
        for(auto& w: words) {
            wordcount[w]++;
        }
        for(int i=0;i<wlen;i++) {
           fn(i,n,s,sublen,wlen,wordcount);
        }
        return sol;
    }
};
