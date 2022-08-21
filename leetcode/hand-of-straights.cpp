class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int, int> mp;
        for(int& i: hand) mp[i]++;
        
        for(auto& itr: mp) {
            if (itr.second) {
                int k = itr.first;
                // cout<<k<<" "<<itr.second<<endl;
                for(int i=groupSize-1;i>=0;i--) {
                    if (mp[k]>mp[k+i]) {
                        return false;
                    } else {
                        mp[k+i]-=mp[k];
                    }
                }
            }
        }
        return true;
    }
};
