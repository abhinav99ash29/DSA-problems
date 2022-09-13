class Solution {
public:
    
    bool check(vector<int>& data, int i, int n) {
        if (i+n >= data.size()) return false;
        for(int k=i+1;k<=i+n;k++) {
            if (data[k]&(1<<7) && (data[k]&(1<<6))==0) continue;
            else return false;
        }
        return true;
    }
    
    bool validUtf8(vector<int>& data, int i=0) {
        if (i>=data.size()) return true;
        if ((data[i] & 1<<7) == 0) {
            return validUtf8(data,i+1);
        } else if (data[i]&(1<<7) && data[i]&(1<<6) && (data[i]&(1<<5))==0) {
            return check(data,i,1) && validUtf8(data,i+2);
        } else if (data[i]&(1<<7) && data[i]&(1<<6) && data[i]&(1<<5) && (data[i]&(1<<4))==0) {
            return check(data,i,2) && validUtf8(data,i+3);
        } else if (data[i]&(1<<7) && data[i]&(1<<6) && data[i]&(1<<5) && data[i]&(1<<4) && (data[i]&(1<<3))==0) {
            return check(data,i,2) && validUtf8(data,i+4);
        } else {
            return false;
        }
    }
};
