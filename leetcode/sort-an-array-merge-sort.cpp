class Solution {
public:
    
    vector<int> merge(vector<int>& a, vector<int>& b) {
        int m  = a.size(), n = b.size();
        int i=0,j=0;
        vector<int> ans;
        while(i<m&&j<n) {
            if (a[i]<b[j]) {
                ans.push_back(a[i]);
                i++;
            } else {
                ans.push_back(b[j]);
                j++;
            }
        }
        while(i<m) {
            ans.push_back(a[i]);
            i++;
        }
        while(j<n) {
            ans.push_back(b[j]);
            j++;
        }
        return ans;
    }
    
    vector<int> sort(vector<int>& arr, int i, int j) {
        if (i>j) return {};
        if (i==j) return {arr[i]};
        int mid = (i+j)/2;
        vector<int> arr1 = sort(arr,i,mid);
        vector<int> arr2 = sort(arr,mid+1,j);
        vector<int> ans = merge(arr1, arr2);
        return ans;
    }
    
    vector<int> sortArray(vector<int>& nums) {
        return sort(nums, 0, nums.size()-1);
    }
};
