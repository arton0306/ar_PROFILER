#ifndef _ar_ProfileNsEx_h_
#define _ar_ProfileNsEx_h_

#define ar_DECR_PROFILER(TITLE)        \
    long long ar_##TITLE##_getTimeCostNs();  \
    void ar_##TITLE##_resetTimeCost();

#define ar_getTimeCostNs(TITLE) ar_##TITLE##_getTimeCostNs()
#define ar_resetTimeCost(TITLE) ar_##TITLE##_resetTimeCost()

#endif // _ar_ProfileNsEx_h_
