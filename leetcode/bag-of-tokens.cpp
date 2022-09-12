class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int n = tokens.size();
        int i=0,j=n-1;
        int score = 0, sol = 0;
        while(i<=j) {
            if (power>=tokens[i]) {
                power-=tokens[i];
                score++;
                sol = max(score,sol);
            } else if (score>0 && (power+tokens[j])>=tokens[i]) {
                power+=tokens[j]-tokens[i];
                j--;
            }
            i++;
        }
        return sol;
    }
};
