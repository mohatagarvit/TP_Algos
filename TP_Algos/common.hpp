#include <iostream>
#include <vector>
using namespace std;

struct Ans {
    Ans(const int m, const int n) : totalCost(0), allocated(m, vector<int>(n,0)){}
    
    int totalCost;
    vector< vector <int> > allocated;
};
