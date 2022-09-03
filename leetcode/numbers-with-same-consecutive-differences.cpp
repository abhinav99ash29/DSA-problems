class Solution {
    vector<int> sol;
public:
    void rec(int n, int prev, int k, int sofar) {
        if (n==0) {
            sol.push_back(sofar);
            return;
        }
        for(int i=0;i<10;i++) {
            if (prev==-1) {
                if (i!=0)
                rec(n-1,i,k,sofar*10+i);
            } else {
                if(i == (prev+k) || i == (prev-k)) {
                    rec(n-1,i,k,sofar*10+i);
                }
            }
        }
    }
    
    vector<int> numsSameConsecDiff(int n, int k) {
        rec(n,-1,k,0);
        return sol;
    }
};
