class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size(); int fp=n-1;
        vector<int> ans;
        for(int i=0;i<n;i++) {
            if(nums[i]>=0)
            {fp=i; break;}
            
        }
        int i=fp; fp--;
        while(i<n && fp>=0) {
              if(abs(nums[i]) < abs(nums[fp])) {
                    ans.push_back(nums[i]*nums[i]);
                  i++;
                } else {
                  ans.push_back(nums[fp]*nums[fp]);
                  fp--;
              }
        }
        while(fp>=0){
            ans.push_back(nums[fp]*nums[fp]);
            fp--;
        }
        while(i<n) {
         ans.push_back(nums[i]*nums[i]);
        i++;
        }
        return ans;
    }
};
