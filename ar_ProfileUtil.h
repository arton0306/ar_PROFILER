#ifndef _ar_ProfileUtil_h_
#define _ar_ProfileUtil_h_

#include <sys/time.h>

#define ar_AVOID_LOCK_NUM 1000

#define ar_PROFILE_EXPORT(TITLE)                                      \
static long long ar_##TITLE##_TimeCost[ar_AVOID_LOCK_NUM] = {0}; \
long long ar_##TITLE##_getTimeCostUs() {                         \
    long long ret = 0;                                          \
    for ( int i = 0; i < ar_AVOID_LOCK_NUM; ++i )      \
        ret+=ar_##TITLE##_TimeCost[i];                           \
    return ret;                                                 \
}                                                               \
void ar_##TITLE##_resetTimeCost() {                              \
    for ( int i = 0; i < ar_AVOID_LOCK_NUM; ++i )      \
        ar_##TITLE##_TimeCost[i]=0;                              \
}

// #define ar_DUMP
#ifdef ar_DUMP
    #define ar_PROFILE_START(TITLE) \
        struct timeval ar_##TITLE##_tp; \
        gettimeofday(&ar_##TITLE##_tp,0); \
        long long ar_##TITLE##_t1 = ar_##TITLE##_tp.tv_sec * (long long)1000000 + ar_##TITLE##_tp.tv_usec; \
        cout << "start at: " << ar_##TITLE##_t1 << endl;
    
    #define ar_PROFILE_STOP(TITLE) \
        int randint = ar_##TITLE##_tp.tv_usec % ar_AVOID_LOCK_NUM; \
        gettimeofday(&ar_##TITLE##_tp,0); \
        long long ar_##TITLE##_t2 = ar_##TITLE##_tp.tv_sec * (long long)1000000 + ar_##TITLE##_tp.tv_usec; \
        cout << "stop at: " << ar_##TITLE##_t2 << endl; \
        ar_##TITLE##_TimeCost[randint] += ar_##TITLE##_t2 - ar_##TITLE##_t1;
#else
    #define ar_PROFILE_START(TITLE) \
        struct timeval ar_##TITLE##_tp; \
        gettimeofday(&ar_##TITLE##_tp,0); \
        long long ar_##TITLE##_t1 = ar_##TITLE##_tp.tv_sec * (long long)1000000 + ar_##TITLE##_tp.tv_usec;
    
    #define ar_PROFILE_STOP(TITLE) \
        int randint = ar_##TITLE##_tp.tv_usec % ar_AVOID_LOCK_NUM; \
        gettimeofday(&ar_##TITLE##_tp,0); \
        long long ar_##TITLE##_t2 = ar_##TITLE##_tp.tv_sec * (long long)1000000 + ar_##TITLE##_tp.tv_usec; \
        ar_##TITLE##_TimeCost[randint] += ar_##TITLE##_t2 - ar_##TITLE##_t1;
#endif

#endif // _ar_ProfileUtil_h_

/*

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
        struct timeval ar_tp; \
        gettimeofday(&ar_tp,NULL); \
        long long ar_t1 = ar_tp.tv_sec * (long long)1000000 + ar_tp.tv_usec; \
        cout << "start at: " << ar_t1 << endl;

    #define ar_PROFILE_STOP \
        int randint = ar_tp.tv_usec % ar_AVOID_LOCK_NUM; \
        gettimeofday(&ar_tp,NULL); \
        long long ar_t2 = ar_tp.tv_sec * (long long)1000000 + ar_tp.tv_usec; \
        cout << "stop at: " << ar_t2 << endl; \
        ar_TimeCost[randint] += ar_t2 - ar_t1;
#else
    #define ar_PROFILE_START \
        struct timeval ar_tp; \
        gettimeofday(&ar_tp,NULL); \
        long long ar_t1 = ar_tp.tv_sec * (long long)1000000 + ar_tp.tv_usec; \

    #define ar_PROFILE_STOP \
        int randint = ar_tp.tv_usec % ar_AVOID_LOCK_NUM; \
        gettimeofday(&ar_tp,NULL); \
        long long ar_t2 = ar_tp.tv_sec * (long long)1000000 + ar_tp.tv_usec; \
        ar_TimeCost[randint] += ar_t2 - ar_t1;
#endif

*/
