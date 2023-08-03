#include "knapHeader.hpp"

int main()
{
    int n, W;
    cout << "enter the value of index: ";
    cin >> n;

    vector<int> profit(n, -1),
        weight(n, -1);
    enterArray("profit", n, profit);
    enterArray("weight", n, weight);

    cout << " enter the value of sack wight: ";
    cin >> W;
    
    cout << knapSack(W, weight, profit, n);
    return 0;
}