class Solution {
    vector<vector<int>> ans;
public:
    
    void fn(int k, int n, int i, vector<int> &soFar) {
        if (k==0) {
            if (n==0) ans.push_back(soFar);
            return;
        }
        
        if (i>9) return;
        
        soFar.push_back(i);
        fn(k-1,n-i,i+1,soFar);
        soFar.pop_back();
        fn(k,n,i+1,soFar);
            
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> soFar;
        fn(k,n,1,soFar);
        return ans;
    }
};
