#ifndef _ar_ProfileUsEx_h_
#define _ar_ProfileUsEx_h_

#define ar_DECR_PROFILER(TITLE)        \
    long long ar_##TITLE##_getTimeCostUs();  \
    void ar_##TITLE##_resetTimeCost();

#define ar_getTimeCostUs(TITLE) ar_##TITLE##_getTimeCostUs()
#define ar_resetTimeCost(TITLE) ar_##TITLE##_resetTimeCost()

#endif // _ar_ProfileUsEx_h_
