class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if (!mp.count(key)) return "";
        if (mp[key][0].first > timestamp) return "";
        int l=0, r = mp[key].size();
        while(l<r) {
            // cout<<l<<" "<<r<<endl;
            int m = (l+r)/2;
            if (mp[key][m].first <= timestamp) {
                l = m+1;
            } else {
                r = m;
            }
        }
        if (r==0) return "";
        return mp[key][r-1].second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
