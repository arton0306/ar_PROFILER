#include <sys/time.h>
#include <iostream>

#define GU_AVOID_LOCK_NUM 1000
static long long guTimecost[GU_AVOID_LOCK_NUM] = {0}; // avoid lock

#define PROFILE_START \
    struct timeval tp; \
    gettimeofday(&tp,NULL); \
    long long watchTimestamp = tp.tv_sec * 1000 + tp.tv_usec / 1000; \
    cout << "start at: " << watchTimestamp << endl;

#define PROFILE_STOP \
    int randint = tp.tv_usec % GU_AVOID_LOCK_NUM; \
    gettimeofday(&tp,NULL); \
    long long watchTimestamp2 = tp.tv_sec * 1000 + tp.tv_usec / 1000; \
    cout << "stop at: " << watchTimestamp2 << endl; \
    guTimecost[randint] += watchTimestamp2 - watchTimestamp;

long long getGuTimeCost() {
    long long ret = 0;
    for ( int i = 0; i < GU_AVOID_LOCK_NUM; ++i )
        ret+=guTimecost[i];
    return ret;
}
void resetGuTimeCost() {
    for ( int i = 0; i < GU_AVOID_LOCK_NUM; ++i )
        guTimecost[i]=0;
}
 
using namespace std;
int main() {
    PROFILE_START;
    int x = 0;
    cin >> x;
    int sum = 0;
    for ( int i = 0; i < x && x > 0; ++i )
        sum += i;
    cout << sum << endl;
    PROFILE_STOP;

    cout << getGuTimeCost() << endl;
    
    return 0;
}
