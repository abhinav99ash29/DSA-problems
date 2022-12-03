class Solution {
public:
    string frequencySort(string s) {
        vector<int> cnt(256,0);
        for(char& c: s) {
            cnt[c]++;
        }
        priority_queue<pair<int, char>> q;
        for(int i=0;i<256;i++) {
            if (cnt[i]!=0) {
                q.push({cnt[i],(char)i});
            }
        }
        string ans = "";
        while(q.size()) {
            for(int i=0;i<q.top().first;i++) {
                ans+=q.top().second;
            }
            q.pop();
        }
        return ans;
    }
};
