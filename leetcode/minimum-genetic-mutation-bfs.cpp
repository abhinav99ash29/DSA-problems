class Solution {
    bool dis(string a, string b) {
        int cnt = 0;
        for(int i=0;i<8;i++) {
            cnt+=a[i]!=b[i] ? 1 : 0;
        }
        return cnt==1;
    }
public:
    int minMutation(string start, string end, vector<string>& bank) {
        int n = bank.size();
        unordered_map<string, bool> vis;
        queue<pair<string,int>> q;
        q.push({start,0});
        while(q.size()>0) {
            auto p = q.front(); q.pop();
            if (p.first == end) return p.second;
            vis[p.first] = true;
            for(int i=0;i<n;i++) {
                if (!vis[bank[i]] && dis(p.first, bank[i])) {
                    q.push({bank[i],p.second+1});
                }
            }
        }
        return -1;
    }
};
