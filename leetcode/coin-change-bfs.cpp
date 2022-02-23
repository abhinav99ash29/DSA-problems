class Solution {
public:
int coinChange(vector<int>& coins, int amount) {
  // sort(coins.begin(), coins.end(), greater<int>());

  queue<pair<int, int>>Q;
  pair<int, int> P;
  Q.push({amount, 0});
  vector<bool> visited(amount+1, false);
  visited[amount] = true;
  while(!Q.empty()){
    P = Q.front();
    Q.pop();
    if(P.first == 0)
    return P.second;
    for(int i = 0; i < coins.size(); i++){
      if((P.first-coins[i]) >= 0 && visited[P.first - coins[i]] == false){
      Q.push({(P.first - coins[i]), P.second+1});
      visited[(P.first - coins[i])] = true;
    }
    else
      continue;
    }
  }
  return -1;
}
};
