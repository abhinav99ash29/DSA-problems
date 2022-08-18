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
        
        int n = arr.size();
        vector<int> count(n+1);
        for(int& freq: vec) {
            count[freq]++;
        }
        int cnt = 0;
        int num = 0;
        int des = (n+1)/2;
        for(int i=count.size()-1;i>=0;i--) {
            // cout<<i<<" "<<count[i]<<endl;
            if (count[i]) {
             for(int j=1;j<=count[i];j++) {
                cnt+=i;
                num++;
                if (cnt>=des) return num;
             }   
            }
        }
        return -1;
    }
};
