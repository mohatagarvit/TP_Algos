#include <iostream>
#include <vector>
using namespace std;

Ans NorthWestCorner(vector< vector<int> > costs, vector<int> supply, vector<int> demand){
    // costs assumed to be non-empty
    int s = costs.size();
    int d = costs[0].size();
    int i = 0, j = 0;
    Ans ans(s,d);
    while(i+j < s+d-1){
        if(supply[i] <= demand[j]){
            ans.totalCost += costs[i][j] * supply[i];
            ans.allocated[i][j] = supply[i];
            demand[j] -= supply[i];
            supply[i] = 0;
            i++;
        }else{
            ans.totalCost += costs[i][j] * demand[j];
            ans.allocated[i][j] = demand[j];
            supply[i] -= demand[j];
            demand[j] = 0;
            j++;
        }    
    }
    return ans;
}
