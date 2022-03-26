class Solution {
    vector<int> parent;
    vector<int> size;
    int maxSize = 1;
public:
    int find(int x) {
        if (x == parent[x])
            return x;
        return find(parent[x]);
    }
    
    void union1(int x, int y) {
        int rootx = find(x);
        int rooty = find(y);
        if (rootx != rooty) {
            parent[rooty] = rootx;
            size[rootx]+=size[rooty];
            maxSize = max(maxSize, size[rootx]);   
        }
    }
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        map<int, int> mp;
        int n = nums.size();
        parent.resize(n, 0);
        size.resize(n, 1);
        
        for(int i=0;i<n;i++) {
            parent[i] = i;
            if (mp.find(nums[i]) != mp.end()) continue;
            mp[nums[i]] = i;
        }
        for(auto m: mp) {
            if (mp.find(m.first - 1) != mp.end()) {
                union1(m.second, mp[m.first-1]);
            }
            if (mp.find(m.first + 1) != mp.end()) {
                union1(m.second, mp[m.first+1]);
            }
        }
        return maxSize;
    }
};
