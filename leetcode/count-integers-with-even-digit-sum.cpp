class Solution {
public:
    
    int sum(int n) {
        int c = 0;
        while(n>0) {
            int d = n%10;
            c+=c*10 + d;
            n/=10;
        }
        return c;
    }
    
    int countEven(int num) {
        int cnt = 0;
        for(int i=2;i<=num;i++) {
            if (sum(i)%2==0) cnt++;
        }
        return cnt;
    }
};
