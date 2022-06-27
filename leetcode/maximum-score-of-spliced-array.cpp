class Solution {
public:
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int sum1 = 0, sum2 = 0;
        for(int i=0;i<n;i++) {
            sum1+=nums1[i];
            sum2+=nums2[i];
        }
        int first=0,second=0,max1=0,max2=0;
        for(int i=0;i<n;i++) {
            first+=nums1[i]-nums2[i];
            second+=nums2[i]-nums1[i];
            max1 = max(max1, first);
            max2 = max(max2, second);
            if (first<0)
                first = 0;
            if (second<0)
                second = 0;
        }
        return max(sum2+max1, sum1+max2);
    }
};
