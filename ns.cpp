#include <iostream>
#include "ar_ProfileNsEx.h"

using namespace std;

ar_DECR_PROFILER(SUM)
ar_DECR_PROFILER(COUNT)

int mySum( int x );
int myCount( int x );

int main() {
    int x,y;
    cin >> x;
    cout << mySum(x) << endl;
    cout << myCount(x) << endl;

    cout << "sum time cost: " << ar_getTimeCostNs(SUM) << endl;
    cout << "count time cost: " << ar_getTimeCostNs(COUNT) << endl;
    
    return 0;
}
