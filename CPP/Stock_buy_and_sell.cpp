#include<vector>
#include<iostream>
using namespace std;
#include<algorithm>
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int l=0,r=1;   // two pointer approach
        int maxP=0;    // taking an ref to slide the window
        while(r!=prices.size()){
            if(prices[l]<prices[r]){
                int profit=prices[r]-prices[l];   // calc profit
                maxP=max(maxP,profit);          // maimum profit 
            }
            else
                l=r;   // sliding the window
            r+=1;
        }
        return maxP;
    }
};