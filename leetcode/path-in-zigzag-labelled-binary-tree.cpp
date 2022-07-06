class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        int lev = floor(log2(label))+1;
        vector<int> ans;
        while(lev>0) {
            // cout<<label<<" "<<lev<<endl;
            ans.push_back(label);
            if (lev%2==0) {
                int prev = pow(2,lev) - label - 1; // differece with the leftmost node and divided by 2 to get the position pos
                prev/=2;
                lev--; // level decreased to parent's level
                label = pow(2,lev-1)+prev;
            } else {
                int prev = label - pow(2,lev-1);
                prev/=2;
                lev--;
                label = pow(2,lev)-prev-1;
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
