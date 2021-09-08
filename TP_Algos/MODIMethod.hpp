#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

void calcUV(int s, int d, vector< vector<int> > costs, vector< vector<int> > row, vector< vector<int> > col, 
            int r, int c, vector<bool> visRow, vector<bool> visCol, 
            vector<int> &u, vector<int> &v){

    if(r != -1 and visRow[r] == false){
        // row
        visRow[r] = true;
        for(int i=0; i<row[r].size(); i++){
            v[row[r][i]] = costs[r][row[r][i]] - u[r];
            calcUV(s, d, costs, row, col, -1, row[r][i], visRow, visCol, u, v);
        }        
    }else if(c != -1 and visCol[c] == false){
        // col
        visCol[c] = true;
        for(int i=0; i<col[c].size(); i++){
            u[col[c][i]] = costs[col[c][i]][c] - v[c];
            calcUV(s, d, costs, row, col, col[c][i], -1, visRow, visCol, u, v);
        }
    }
    return;
}

Ans MODIMethod(vector< vector<int> > costs, vector<int> supply, vector<int> demand){
    int s = costs.size();
    int d = costs[0].size();
    Ans ans = VogelApproximationMethod(costs, supply, demand); 

    vector<int> u(s,0);
    vector<int> v(d,0);
    
    vector< vector<int> > row(s);
    vector< vector<int> > col(d);
    vector< vector<int> > c(s, vector<int> (d, 0)); // contains sum and diff values for both allocated and not allocated
  
    int mind = 0, minr = 0, minc = 0; // min difference, row and col corresponding to this difference
    vector< vector<int> > visAllotted(s, vector<int> (d, -1)); // ever changing?
    while(true){
        mind = 0;
        
        vector<bool> visRow(s, false);
        vector<bool> visCol(d, false);
        initRowCol(ans, row, col, s, d);
        calcUV(s, d, costs, row, col, 0, -1, visRow, visCol, u, v);

        for(int i=0; i<s; i++){
            for(int j=0; j<d; j++){
                if(!ans.allocated[i][j]){
                    c[i][j] = costs[i][j] - (u[i] + v[j]); 
                    if(c[i][j] < mind){
                        mind = c[i][j];
                        minr = i;
                        minc = j;
                    }   
                } 
            }
        }
        
        if (mind < 0){
            initVisAllotted(ans, s, d, visAllotted); // can be made easy with pCost values
            // modifying row and col in both
            pathCost pCost;
            pCost.ind[0] = minr;
            pCost.ind[3] = minc;
            pCost.cost = costs[minr][minc];
            bool check = false;
            visAllotted[minr][minc] = 1;
            findClosedPath(ans, costs, s, d, row, col, visAllotted, minr, 1, check, pCost);
            updateAnsForNegativeCostClosedPath(ans, pCost);
        }else{
            break;
        }
            // printAns(ans, s, d);
    }
           
    return ans;
}
