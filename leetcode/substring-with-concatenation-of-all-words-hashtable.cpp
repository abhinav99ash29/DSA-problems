class Solution {
public:
    
    bool check(int start, int n, string s, int sublen, int wlen, map<string, int>& wordcount) {
        map<string, int> wordfound;
        int wused = 0;
        for(int i=start;i<start+sublen;i+=wlen) {
            string w = s.substr(i,wlen);
            if (wordcount.count(w)==0) return false;
            wordfound[w]++;
            if (wordfound[w]<=wordcount[w]) wused++;
            else return false;
        }
        return wused == n;
    }
    
    vector<int> findSubstring(string s, vector<string>& words) {
        int n = words.size();
        int wlen = words[0].size();
        int sublen = wlen*n;
        map<string, int> wordcount;
        for(auto& w: words) {
            wordcount[w]++;
        }
        vector<int> sol;
        for(int i=0;i<(s.size()-sublen+1);i++) {
            if (check(i,n,s,sublen,wlen,wordcount)) {
                sol.push_back(i);
            }
        }
        return sol;
    }
};
