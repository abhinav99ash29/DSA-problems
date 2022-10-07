class MyCalendarThree {
    map<int, int> mp;
public:
    MyCalendarThree() {
        
    }

    int book(int start, int end) {
        mp[start]+=1;
        mp[end]-=1;
        int curr = 0, sol = 0;
        for(auto& it: mp) {
            curr+=it.second;
            sol = max(sol, curr);
        }
        return sol;
    }
};
