class Solution {
public:
    int minSetSize(vector<int>& arr) {
        map<int, int> mp;
        for(int& i: arr) {
            mp[i]++;
        }
        vector<int> vec(mp.size(),0);
        for(auto& m: mp) {
            vec.push_back(m.second);
        }
        sort(vec.begin(), vec.end(), greater<int>());
        
        int n = arr.size();
        int cnt = 0;
        
        for(int i=0;i<vec.size();i++) {
            cnt+=vec[i];
            if (cnt >= n/2) return i+1;
        }
        return -1;
    }
};
