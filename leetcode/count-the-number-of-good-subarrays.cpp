class Solution {
public:
    long long countGood(vector<int>& A, int k) {
        long long res = 0;
        unordered_map<int, int> count;
        for (int i = 0, j = 0; j < A.size(); ++j) {
            k -= count[A[j]];
            count[A[j]]+=1;
            while (k <= 0) {
                count[A[i]]-=1;
                k+=count[A[i]];
                i++;
            }
            res += i;
        }
        return res;
    }
};
