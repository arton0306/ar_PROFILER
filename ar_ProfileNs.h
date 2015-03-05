#ifndef _ar_ProfileNs_h_
#define _ar_ProfileNs_h_

#include <time.h>

#define ar_BIG_PRIME 9887
#define ar_BIG_PRIME2 5573
#define ar_AVOID_LOCK_NUM ar_BIG_PRIME2

#define ar_PROFILE_EXPORT(TITLE)                                      \
static long long ar_##TITLE##_TimeCost[ar_AVOID_LOCK_NUM] = {0}; \
long long ar_##TITLE##_getTimeCostNs() {                         \
    long long ret = 0;                                          \
    for ( int i = 0; i < ar_AVOID_LOCK_NUM; ++i )      \
        ret+=ar_##TITLE##_TimeCost[i];                           \
    return ret;                                                 \
}                                                               \
void ar_##TITLE##_resetTimeCost() {                              \
    for ( int i = 0; i < ar_AVOID_LOCK_NUM; ++i )      \
        ar_##TITLE##_TimeCost[i]=0;                              \
}

#define ar_PROFILE_START(TITLE)                           \
    struct timespec ar_##TITLE##_tpstart;                 \
    clock_gettime(CLOCK_REALTIME, &ar_##TITLE##_tpstart);

#define ar_PROFILE_STOP(TITLE)                                                              \
    struct timespec ar_##TITLE##_tpend;                                                     \
    clock_gettime(CLOCK_REALTIME, &ar_##TITLE##_tpend);                                     \
    int randint = ar_##TITLE##_tpend.tv_nsec * ar_BIG_PRIME % ar_AVOID_LOCK_NUM;               \
    ar_##TITLE##_TimeCost[randint] +=                                                       \
        ( ar_##TITLE##_tpend.tv_sec - ar_##TITLE##_tpstart.tv_sec ) * (long long)1000000000 \
      + ( ar_##TITLE##_tpend.tv_nsec - ar_##TITLE##_tpstart.tv_nsec );

#endif // _ar_ProfileNs_h_
