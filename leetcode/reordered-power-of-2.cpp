class Solution {
public:
    vector<int> getv(int n) {
        vector<int> v;
        while(n) {
            v.push_back(n%10);
            n/=10;
        }
        sort(v.begin(), v.end(), greater<int>());
        return v;
    }
    
    bool reorderedPowerOf2(int n) {
        vector<int> v = getv(n);
        int mx = 0;
        for(int& i: v) mx = mx*10+i;
        for(int i=1;i<=mx;i*=2) {
            vector<int> v1 = getv(i);
            if (v1.size()==v.size()) {
                bool flag = true;
                for(int i=0;i<v.size();i++) {
                    if (v[i]!=v1[i]) {
                        flag = false;
                        break;
                    }
                }
                if (flag)
                return true;
            }
        }
        return false;
    }
};
