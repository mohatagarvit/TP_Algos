#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>
using namespace std;


void resetVisited(vector< vector<int> > &visAllotted, vector< vector<int> > row){
    for(int i=0; i<row.size(); i++){
        for(int j=0; j<row[i].size(); j++){
            visAllotted[i][row[i][j]] = 0;
        }
    }
}


int findLeastPathCostIndex(vector<pathCost> pathCostVector){
    int low = 0;
    int ind = 0;
    for(int i=0; i<pathCostVector.size(); i++){
        if(pathCostVector[i].cost < low){
            low = pathCostVector[i].cost;
            ind = i;
        }
    }
    return ind;
}


Ans SteppingStoneMethod(vector< vector<int> > costs, vector<int> supply, vector<int> demand){
    int s = costs.size();
    int d = costs[0].size();
    Ans ans = VogelApproximationMethod(costs, supply, demand);

    vector< vector<int> > row(s);
    vector< vector<int> > col(d);
    vector< vector<int> > visAllotted(s, vector<int> (d, -1));
    
    int iter = 0;
    vector<pathCost> pathCostVector;
    while(pathCostVector.size() > 0 or iter == 0){
    
        pathCostVector.clear();
        iter++;
        initVisAllotted(ans, s, d, visAllotted);  // optimize?
        initRowCol(ans, row, col, s, d);
        int temp =0;
        
        for(int i=0; i<s; i++){    
            for(int j=0; j<d; j++){
                if(ans.allocated[i][j]==0){ 
                    // reset to init state
                    resetVisited(visAllotted, row);
                    pathCost pCost;
                    pCost.ind[0] = i;
                    pCost.ind[3] = j;
                    pCost.cost = costs[i][j];
                    
                    bool check = false;
                    visAllotted[i][j] = 1;
                    findClosedPath(ans, costs, s, d, row, col, visAllotted, i, 1, check, pCost);
                    visAllotted[i][j] = -1;
                    
                    // only store negative costs
                    temp++;
                    if(pCost.cost < 0){ 
                        pathCostVector.push_back(pCost);
                    }
                }
            }
        }
        
        if (!pathCostVector.empty()){
            int ind = findLeastPathCostIndex(pathCostVector);
            updateAnsForNegativeCostClosedPath(ans, pathCostVector[ind]);
        }
    }
    return ans;
}
