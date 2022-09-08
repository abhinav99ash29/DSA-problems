class Solution {
    vector<int> sol;
public:
    
    
    void split(int l, int r, vector<pair<int, int>>& nums) {
        if (l>=r) return;
        int mid = (l+r)/2;
        split(l,mid,nums);
        split(mid+1,r,nums);
        vector<pair<int, int>> left;
        left.assign(nums.begin()+l,nums.begin()+mid+1);
        vector<pair<int, int>> right;
        right.assign(nums.begin()+mid+1,nums.begin()+r+1);
        int i=l,j=mid+1,k=l;
        int cnt = 0;
        while(i<=mid && j<=r) {
            int i1 = i-l;
            int j1 = j-(mid+1);
            if (left[i1].first>right[j1].first) {
                nums[k] = right[j1];
                j++;
                cnt++;
            } else {
                nums[k] = left[i1];
                sol[left[i1].second]+=cnt;
                i++;
            }
            k++;
        }
        while(i<=mid) {
            int i1 = i-l;
            nums[k] = left[i1];
            sol[left[i1].second]+=cnt;
            i++;
            k++;
        }
        while(j<=r) {
            int j1 = j-(mid+1);
            nums[k] = right[j1];
            j++;
            k++;
        }
    }
    
    
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        sol = vector<int>(n,0);
        vector<pair<int,int>> nums1;
        for(int i=0;i<n;i++) nums1.push_back({nums[i],i});
        split(0,n-1,nums1);
        return sol;
    }
};
