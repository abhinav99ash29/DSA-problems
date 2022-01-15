/*
A combo is defined as a subset of the given n terms. The total popularity is the sum of the individual items of the combo. design an algorithmn that can find the k combos with the highest popularity.
two combos are considered different if they have different subset of items. return the array of k integers where the ith term denotes the popularity of ith best combo. Combos should be returned arranged best to worst.

Example
n = 3
array = [3,5,-2]
k = 3
All possible populatrity of combos are 0,3,5,-2,8,3,1,6 .
The best 3 are 8,6,5.
hence , answer is [8,6,5].

Constraints -
1 <= n <= 10^5
-10^9 <= array[i] <= 10^9
1 <= k <= min(2000,2^n)
*/


#include <bits/stdc++.h>
using namespace std;

void subsetKSum(priority_queue<int, vector<int>, greater<int>>& result, int k, int sum, vector<int> nums, int current) {

    for (int i = current; i < nums.size(); i++) {
        int nextSum = sum + nums[i];
        result.push(nextSum);   
        if (result.size() > k) {
            result.pop();
        }
        subsetKSum(result, k, nextSum, nums, i+1);

    }
}

vector<int> topKSum(vector<int> nums, int k) {
    priority_queue<int, vector<int>, greater<int>> pq;

    subsetKSum(pq, k, 0, nums, 0);

    vector<int> result(k);
    for (int i = 0; i < k; i++) {
        result[i] = pq.top(); pq.pop();
    }
    reverse(result.begin(), result.end());
    return result;
}




int main() {
	vector<int> nums = {3, 5, -2};
	int k = 3;
	vector<int> res = topKSum(nums, k);
	for(int i=0;i<res.size();i++) {
	    cout<<res[i]<<" ";
	}
	return 0;
}

