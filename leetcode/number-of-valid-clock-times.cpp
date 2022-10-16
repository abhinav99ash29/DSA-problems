class Solution {
public:
    int countTime(string time) {
        int sol = 1;
        if (time[0]=='?' && time[1]!='?') {
            if (time[1]<='3') sol*=3;
            else sol*=2;
        }
        if (time[0]=='?' && time[1]=='?') {
            sol*=24;
        }
        if (time[0]!='?' && time[1]=='?') {
            if (time[0]<='1') sol*=10;
            else sol*=4;
        }
        if (time[3]=='?' && time[4]!='?') {
            sol*=6; 
        }
        if (time[3]=='?' && time[4]=='?') {
            sol*=60;
        }
        if (time[3]!='?' && time[4]=='?') {
            sol*=10;
        }
        return sol;
    }
};
