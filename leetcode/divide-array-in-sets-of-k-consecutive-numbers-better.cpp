class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        map<int, int> mp;
        for(auto& i: nums) {
            mp[i]++;
        }
        for(auto& it: mp) {
            int x = it.first;
            if (mp[x]>0) {
                for(int i=k-1;i>=0;i--) {
                    if ((mp[x+i]-=mp[x])<0) return false;
                }
            }
        }
        return true;
    }
};
