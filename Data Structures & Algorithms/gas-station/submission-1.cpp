class Solution {
public:
    bool check(vector<int>& diff, int id) {
        int size=diff.size();
        int total=0;
        int i=id;
        
        return true;
    }
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int size=gas.size();
        vector<int> diff(size);
        int total=0;
        for(int i=0; i<size; i++) {
            diff[i]=gas[i]-cost[i];
            total+=diff[i];
        }
        if(total<0) {
            return -1;
        }
        total=0;
        int i=0;
        int id=0;
        while(true) {
            if(total<0) {
                total=0;
                id=i;
            }
            total+=diff[i];
            i++;
            i%=size;
            if(i==id) {
                return i; 
            }
        }
        return -1;
    }
};

/*
Desc:
n gas station form a circular route
    gas[i] -> the amount of gas at ith 
    cost[i] -> the amount of gas needed to travel from ith -> (i+1)th (the last one connect to the first one)
    
output: return the starting gas station so that you can travel each gas station once 
        if impossible return -1

Ex: 
     0 1 2
    [2,4,1]         
                    travel 0 -> 1: have 2 needed 4
                    travel 1 -> 2: have 4 needed 2
                    travel 2 -> 0: have 1 needed 3

    [4,2,3] -> return 1


    [1,2,3,4] -> return 3
    [2,2,4,1]

    -1 0 -1 3
    calculate the sum of diff between each station gas[i]-cost[i]
    at each point we will have an initial amount of gas     
        it shouldn't be negative (diff[i]>0)
    &&  diff[i]+(sum-diff[i])>=0

    [5,0,9]
    [1,9,4]
    4, -9, 5, 4, -9
    -13 14 -1 -13

    -> check for every station that is >=0
        if it can travel to the next station until it get to its previous station (because of circular route)
        -> return that index
    cost O(n^2)
    there is an optimal solution with O(n)

*/
