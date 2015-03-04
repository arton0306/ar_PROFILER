#include <sys/time.h>
#include <iostream>

#define ar_AVOID_LOCK_NUM 1000
static long long ar_TimeCost[ar_AVOID_LOCK_NUM] = {0}; // avoid lock
static long long ar_getTimeCostUs() { 
    long long ret = 0;
    for ( int i = 0; i < ar_AVOID_LOCK_NUM; ++i )
        ret+=ar_TimeCost[i];
    return ret;
}
static void ar_resetTimeCost() {
    for ( int i = 0; i < ar_AVOID_LOCK_NUM; ++i )
        ar_TimeCost[i]=0;
}

// #define ar_DUMP
#ifdef ar_DUMP
    #define ar_PROFILE_START \
        struct timeval tp; \
        gettimeofday(&tp,NULL); \
        long long t1 = tp.tv_sec * (long long)1000000 + tp.tv_usec; \
        cout << "start at: " << t1 << endl;
    
    #define ar_PROFILE_STOP \
        int randint = tp.tv_usec % ar_AVOID_LOCK_NUM; \
        gettimeofday(&tp,NULL); \
        long long t2 = tp.tv_sec * (long long)1000000 + tp.tv_usec; \
        cout << "stop at: " << t2 << endl; \
        ar_TimeCost[randint] += t2 - t1;
#else
    #define ar_PROFILE_START \
        struct timeval tp; \
        gettimeofday(&tp,NULL); \
        long long t1 = tp.tv_sec * (long long)1000000 + tp.tv_usec; \
    
    #define ar_PROFILE_STOP \
        int randint = tp.tv_usec % ar_AVOID_LOCK_NUM; \
        gettimeofday(&tp,NULL); \
        long long t2 = tp.tv_sec * (long long)1000000 + tp.tv_usec; \
        ar_TimeCost[randint] += t2 - t1;
#endif

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
