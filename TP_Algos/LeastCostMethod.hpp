#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// using struct in place of complicated pairs
struct LeastCostMethodCompare {
    bool operator()(pair< pair<int, int>, int> a, pair< pair<int, int>, int> b){
        if(a.second == b.second){
           if(a.first.first == b.first.first){
                return a.first.second > b.first.second;
            }else{
                return a.first.first > b.first.first;
            }
        }else{
            return a.second > b.second;
        }
    }
};

Ans LeastCostMethod(vector< vector<int> > costs, vector<int> supply, vector<int> demand){
    int i = 0,j = 0;
    int s = costs.size();
    int d = costs[0].size();
    Ans ans(s,d);
    vector <bool> visRow (s,0), visCol (d,0);
    priority_queue< pair< pair<int, int>, int>, vector< pair< pair<int, int>, int> >, LeastCostMethodCompare > pq;
    for(i=0; i<s; i++){
        for(j=0; j<d; j++){
            pq.push( make_pair( make_pair(i,j), costs[i][j] ));
        }
    }

    while(!pq.empty()){
        auto a = pq.top();
        pq.pop();
        i = a.first.first;
        j = a.first.second;
        if( !visRow[i] && !visCol[j] ){  // check && or ||
            if(supply[i] <= demand[j]){
                ans.totalCost += costs[i][j] * supply[i];
                ans.allocated[i][j] = supply[i];
                demand[j] -= supply[i];
                supply[i] = 0;
                visRow[i] = 1;
                // i++;
            }else{
                ans.totalCost += costs[i][j] * demand[j];
                ans.allocated[i][j] = demand[j];
                supply[i] -= demand[j];
                demand[j] = 0;
                visCol[j] = 1;
                // j++;
            }    
        }
    }
    return ans;
}
