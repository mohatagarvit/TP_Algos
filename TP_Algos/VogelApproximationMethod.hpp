#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct indexCost{
    int index; // for both supply or demand index
    int cost;
};

struct indexCostCompare {
    bool operator()(indexCost a, indexCost b){
        if(a.cost == b.cost){
            return a.index > b.index;
        }else{
            return a.cost > b.cost;
        }
    }
};

vector<int> calcDiff(int s, vector<bool> visRow, vector<bool> visCol, 
                     vector< priority_queue< indexCost, vector< indexCost >, indexCostCompare > > &pqRow){
    
    vector<int> rowDiff(s, 0);
    for(int i=0; i<s; i++){
        if(visRow[i] || pqRow[i].empty()){
            rowDiff[i] = -1;
            continue;
        }

        // get min cost cell in i th Row that still has unallocated supply
        indexCost t = pqRow[i].top();
        pqRow[i].pop();
        while(!pqRow[i].empty() && visCol[t.index]){
            t = pqRow[i].top();
            pqRow[i].pop();
        }
        
        // get 2nd min element
        while(!pqRow[i].empty() && visCol[pqRow[i].top().index]){
            pqRow[i].pop();
        }

        if(pqRow[i].empty()){
            // if there is no 2nd min element
            rowDiff[i] = t.cost;
            pqRow[i].push(t);    
        }else{
            rowDiff[i] = pqRow[i].top().cost - t.cost ; 
            pqRow[i].push(t);
        }
    }
    
    return rowDiff;
}
    
Ans VogelApproximationMethod(vector< vector<int> > costs, vector<int> supply, vector<int> demand){
    int s = costs.size();
    int d = costs[0].size();
    Ans ans(s,d);
    vector <bool> visRow (s,0), visCol (d,0);
    
    int i = 0,j = 0;
    vector< priority_queue< indexCost, vector< indexCost >, indexCostCompare > > pqRow(s);
    vector< priority_queue< indexCost, vector< indexCost >, indexCostCompare > > pqCol(d);
    for(i=0; i<s; i++){
        for(j=0; j<d; j++){
            pqRow[i].push( indexCost{j, costs[i][j]} );
            pqCol[j].push( indexCost{i, costs[i][j]} );
        }
    }
    
    vector<int> rowDiff = calcDiff(s, visRow, visCol, pqRow);
    vector<int> colDiff = calcDiff(d, visCol, visRow, pqCol);    

    int t1 = 0, t2 = 0;
    while(t1+t2 < s+d-1){
        
        // get max row difference
        int rowInd = 0, rowMax = 0;
        for(i=0; i<s; i++){
            if(rowDiff[i] > rowMax){
                rowInd = i; 
                rowMax = rowDiff[i];
            }
        }
        // get max col difference
        int colInd = 0, colMax = 0;
        for(i=0; i<d; i++){
            if(colDiff[i] > colMax){
                colInd = i; 
                colMax = colDiff[i];
            }
        }
        
        //update
        if(rowMax < colMax){
            i = pqCol[colInd].top().index;
            j = colInd;
            pqCol[colInd].pop();
        }else{
            i = rowInd;
            j = pqRow[rowInd].top().index;
            pqRow[rowInd].pop();
        }
        
        if(supply[i] <= demand[j]){
            ans.totalCost += costs[i][j] * supply[i];
            ans.allocated[i][j] = supply[i];
            demand[j] -= supply[i];
            supply[i] = 0;
            visRow[i] = 1;
            t1++;
            // update col difference for next iteration
            rowDiff[i] = -1;
            colDiff = calcDiff(d, visCol, visRow, pqCol);    
        }else{
            ans.totalCost += costs[i][j] * demand[j];
            ans.allocated[i][j] = demand[j];
            supply[i] -= demand[j];
            demand[j] = 0;
            visCol[j] = 1;
            t2++;
            // update row difference for next iteration
            colDiff[j] = -1;
            rowDiff = calcDiff(s, visRow, visCol, pqRow);      
        }
    }
    return ans;
}
 