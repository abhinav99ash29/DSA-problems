#include <bits/stdc++.h>
using namespace std;

bool isNeg(vector<int> wt, vector<int> dist, vector<vector<int>> ed) {
    for(int i=0;i<ed.size();i++) {
        if(dist[ed[i][1]] > dist[ed[i][0]] + wt[i])
        {
            return true;
        }
    }
    return false;
}

vector<int> bellman(int v, vector<vector<int>> edg, vector<vetor<int>> wt) {
    vector<int> dist = vector<int>(v);
    fill(dist.begin(), dist.end(), INT_MAX);
    dist[0] = 0;
    
    for(int i=0;i<v-1;i++) {
        for(int j=0;j<edg.size();j++) {
            dist[edg[j][1]] = min(dist[edg[j][1]], dist[edg[j][0]] + wt[j]); 
        }
    }
    return dist;
}

int main() {
	// your code goes here
	return 0;
}
