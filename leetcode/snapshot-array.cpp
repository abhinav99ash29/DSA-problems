class SnapshotArray {
    map<int, map<int, int>> state;
    int snapid;
public:
    SnapshotArray(int length) {
        snapid = 0;
        for(int i=0;i<length;i++) {
            map<int, int> mp; mp[0] = 0;
            state[i] = mp;
        }
    }
    
    void set(int index, int val) {
        state[index][snapid] = val;
    }
    
    int snap() {
        return snapid++;
    }
    
    int get(int index, int snap_id) {
        auto it = state[index].upper_bound(snap_id);
        it--;
        return it->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
