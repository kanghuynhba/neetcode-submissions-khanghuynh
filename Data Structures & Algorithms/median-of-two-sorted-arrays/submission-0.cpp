
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i=0, j=0, k=0;
        int size=nums1.size()+nums2.size();       
        int size1=nums1.size(), size2=nums2.size();
        int medianId=size/2;
        double m1, m2;
        /*
        n1: [1]
        n2: [2,3,4,5,6]
        we need to know whether we need 2 nums or 1 num
        */
        while(i<nums1.size() && j<nums2.size()) {
            if(nums1[i]<nums2[j]) {
                m2=m1;
                m1=nums1[i];
                i++;
            } else {
                m2=m1;
                m1=nums2[j];
                j++;
            }
            k++;
            if(k==size/2+1) {
                if(size%2==0) {
                    return (m2+m1)/2; 
                } else {
                    return m1;
                }
            }
        }
        while(i<size1) {
            m2=m1;
            m1=nums1[i++];
            k++;
            if(k==size/2+1) {
                if(size%2==0) {
                    return (m2+m1)/2;
                } else {
                    return m1;
                }
            }
        }
        while(j<size2) {
            m2=m1;
            m1=nums2[j++];
            k++;
            if(k==size/2+1) {
                if(size%2==0) {
                    return (m2+m1)/2;
                } else {
                    return m1;
                }
            }
        }
        return -1;
    }
};
