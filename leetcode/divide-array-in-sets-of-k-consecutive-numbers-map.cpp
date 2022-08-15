class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        map<int, int> mp;
        for(auto& i: nums) {
            mp[i]++;
        }
        while(mp.size()) {
           int x = mp.begin()->first; 
            // cout<<endl<<x<<" "; 
            mp[x]--;
            if (mp[x]==0) mp.erase(x);
           for(int i=2;i<=k;i++) {
               if (mp.count(x+1)>0) {
                   mp[x+1]--;
                   if (mp[x+1]==0) mp.erase(x+1);
                   x=x+1;
                   // cout<<x<<" ";
               } else {
                   return false;
               }
           } 
        }
        return true;
    }
};
