class Solution {
    vector<vector<int>> ans;
public:
    void fn(int i, int tar, vector<int>& arr, vector<int>& soFar) {
        int n = arr.size();
        if (tar==0) {
            ans.push_back(soFar);
            return;
        }
        if(i>=n) return;
        int j=i;
        while((j+1)<n&&arr[j]==arr[j+1]) {
                j++;
        }
        fn(j+1,tar,arr,soFar);
        if (arr[i]<=tar) {
            soFar.push_back(arr[i]);
            fn(i+1,tar-arr[i],arr,soFar);
            soFar.pop_back();
        }
        
    }
    
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> soFar;
        sort(candidates.begin(), candidates.end());
        fn(0,target,candidates,soFar);
        return ans;
    }
};
