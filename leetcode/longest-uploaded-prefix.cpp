class LUPrefix {
    vector<bool> v;
    int i;
public:
    LUPrefix(int n) {
        i=0;
        v.resize(n+1,0);
    }
    
    void upload(int video) {
        v[video-1] = true;
        while(v[i]) i++;
    }
    
    int longest() {
        return i;
    }
};
