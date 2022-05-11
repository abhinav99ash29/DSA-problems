class Solution {
public:
    int countVowelStrings(int n) {
        if (n==1) return 5;
        int a=1,e=1,i=1,o=1,u=1;
        
        for(int k=2;k<=n;k++) {
            o+=u;
            i+=o;
            e+=i;
            a+=e;
            // cout<<a<<" "<<e<<" "<<i<<" "<<o<<" "<<u<<endl;
        }
        return a+e+i+o+u;
    }
};
