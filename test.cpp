#include <iostream>
#include "ar_ProfileUtil.h"

using namespace std;
int main() {
    ar_PROFILE_START;
    int x = 0;
    cin >> x;
    int sum = 0;
    for ( int i = 0; i < x && x > 0; ++i )
        sum += i;
    cout << sum << endl;
    ar_PROFILE_STOP;

    cout << ar_getTimeCostUs() << endl;
    
    return 0;
}
