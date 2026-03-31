class Solution {
public:
    void recursion(vector<int>& coins, int i, int remain, int& minCoins, int count) {
        if(remain==0) {
            minCoins=min(minCoins, count);
            return;
        } 
        if(i<0) {
            return;
        }
        if(coins[i]<=remain) {
            recursion(coins, i, remain-coins[i], minCoins, count+1);
        }
        recursion(coins, i-1, remain, minCoins, count);
    }
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end());
        int minCoins=INT_MAX;
        recursion(coins, coins.size()-1, amount, minCoins, 0);
        if(minCoins==INT_MAX) {
            return -1;
        }
        return minCoins;        
    }
};