class Solution {
public:
    string countAndSay(int n) {
        if (n==1) return "1";
        string str = countAndSay(n-1);
        int i=0,j=0;
        string say = "";
        int sz = str.size();
        while(i<sz&&j<sz) {
            while(j<sz && str[j]==str[i]) {
                j++;
            }
            say+='0'+(j-i); // adding the count as string
            say+=+str[i];
            i=j;
        }
        return say;
    }
};
