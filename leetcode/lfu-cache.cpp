class LFUCache {
public:
    unordered_map<int, vector<int>> mp;
    int cap, orig;
    int t = 0;
    map<pair<int,int>, int> st;
    LFUCache(int capacity) {
        orig = capacity;
        cap = capacity;
    }
    
    int get(int key) {
        if (orig==0) return -1;
        if (mp.count(key)) {
            st.erase({mp[key][1], mp[key][2]});
            mp[key][1]++;
            mp[key][2] = ++t;
            st[{mp[key][1], mp[key][2]}] = key;
            return mp[key][0];
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (orig==0) return;
        if (mp.count(key)) {
            mp[key][0] = value;
            st.erase({mp[key][1], mp[key][2]});
            mp[key][1]++;
            mp[key][2] = ++t;
            st[{mp[key][1], mp[key][2]}] = key;
        } else {
            if (cap==0) {
                auto it = st.begin();
                mp.erase(it->second);
                st.erase(it);
                cap++;
            }
            mp[key] = {value, 1, ++t};
            st[{1,t}] = key;
            cap--;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
