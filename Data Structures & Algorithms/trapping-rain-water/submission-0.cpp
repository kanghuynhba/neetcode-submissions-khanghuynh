
class Solution {
public:
    int trap(vector<int>& height) {
        int size=height.size();
        vector<int> maxPrefix(size, 0);
        vector<int> maxSuffix(size, 0);
        maxPrefix[0]=height[0];
        maxSuffix[size-1]=height[size-1];
        for(int i=1; i<size; i++) {
            maxPrefix[i]=max(maxPrefix[i-1], height[i]);
            maxSuffix[size-i-1]=max(maxSuffix[size-i], height[size-i-1]);
        }
        int total=0;
        for(int i=0; i<size; i++) {
            total+=min(maxPrefix[i], maxSuffix[i])-height[i];
        }
        return total;
    }
};

/*
Ex: [3,1,4,2,5] -> total rain water = 4
Question:
    Can this array be empty? if yes => total=0
    Can the nums be negative? no
    
               2 0 2 -> 4
            [3,1,4,2,5]
 maxPrefix = 3 3 4 4 5
 maxSuffix = 5 5 5 5 5

             0 0 0 0 0
            [1,2,3,2,1] -> total=0
             1 2 3 3 3
             3 3 3 2 1
            
             0 1 2 0 0
            [5,3,2,4,2] -> total=3
             5 5 5 5 5
             5 4 4 4 2
        Can we know how height the water would be at each element?

*/
