class RandomizedSet {
    unordered_map<int, int> mp;
    vector<int> arr;
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if (mp.count(val)) return false;
        mp[val] = arr.size();
        arr.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if (mp.count(val)) {
            arr[mp[val]] = arr[arr.size()-1];
            mp[arr[mp[val]]] = mp[val];
            arr.pop_back();
            mp.erase(val);
            return true;
        } 
        return false;
    }
    
    int getRandom() {
        int sz = arr.size();
        int idx = rand()%sz;
        return arr[idx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
