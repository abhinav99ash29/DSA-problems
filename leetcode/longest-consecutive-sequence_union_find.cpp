class Solution {
    vector<int> parent;
    vector<int> size;
    int maxSize = 1;
public:
    int find(int x) {
        while(x != parent[x]) {
            x = parent[x];
        }
        return x;
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
        map<int, int> mp;
        int n = nums.size();
        if (n == 0) return 0;
        parent.resize(n, 0);
        size.resize(n, 1);
        for(int i=0;i<n;i++) {
            parent[i] = i;
            if (mp.find(nums[i]) != mp.end()) continue;
            
            if (mp.find(nums[i] - 1) != mp.end()) {
                union1(i, mp[nums[i]-1]);
            }
            
            if (mp.find(nums[i] + 1) != mp.end()) {
                union1(i, mp[nums[i]+1]);
            }
            mp[nums[i]] = i;
        }
        return maxSize;
    }
};
