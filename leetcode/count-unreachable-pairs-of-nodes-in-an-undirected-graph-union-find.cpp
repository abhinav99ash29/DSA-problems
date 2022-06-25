class Solution {
    vector<int> parent;
    vector<int> size; 
    long long total;
public:
    
    int find(int x) {
        while(parent[x]!=x) {
            x = parent[parent[parent[x]]];
        }
        return x;
    }
    
    void union1(int x, int y) {
        int parx = find(x);
        int pary = find(y);
        if (parx!=pary) {
            total-=size[parx]*size[pary];
            if (size[parx]>size[pary]) {
            parent[pary] = parx;
            size[parx]+=size[pary];   
            } else {
                parent[parx] = pary;
                size[pary]+=size[parx];   
            }
        }
    }
    
    
    long long countPairs(int n, vector<vector<int>>& edges) {
        parent.resize(n,0);
        size.resize(n,1);
        total = (long long)((long long)n*(n-1))/2;
        for(int i=0;i<n;i++) parent[i]=i;
        for(vector<int> &ed: edges) {
            union1(ed[0],ed[1]);
        }
        return total;
    }
};
