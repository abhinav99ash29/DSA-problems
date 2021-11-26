// https://leetcode.com/problems/robot-bounded-in-circle/
class Solution {
public:
    int dx[4] = {0,1,0,-1};
    int dy[4] = {1,0,-1,0};
    
    int turnLeft (int d) {
        if (d==0) return 3;
        if (d==1) return 0;
        if (d==2) return 1;
        return 2;
    }
    
    int turnRight (int d) {
        if (d==0) return 1;
        if (d==1) return 2;
        if (d==2) return 3;
        return 0;
    }
    bool isRobotBounded(string instructions) {
        int x=0,y=0,direction=0;
        instructions+=instructions+instructions+instructions;
        for(auto c:instructions) {
            if(c=='L') direction=turnLeft(direction);
            else if(c=='R') direction=turnRight(direction);
            else {
                x+=dx[direction];
                y+=dy[direction];
            }
        }
        if(x==0&&y==0) return true;
        return false;
    }
};
