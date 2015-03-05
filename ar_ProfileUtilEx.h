#ifndef _ar_ProfileUtilEx_h_
#define _ar_ProfileUtilEx_h_

/*
#define ar_EX_DEFI_TITLE(TITLE)        \
    long long TITLE##_ar_getTimeCostUs() { \
        return ar_getTimeCostUs();         \
    }                                      \
    void TITLE##ar_resetTimeCost() {       \
        ar_resetTimeCost();                \
    }
*/

#define ar_DECR_PROFILER(TITLE)        \
    long long ar_##TITLE##_getTimeCostUs();  \
    void ar_##TITLE##_resetTimeCost();

#define ar_getTimeCostUs(TITLE) ar_##TITLE##_getTimeCostUs()
#define ar_resetTimeCost(TITLE) ar_##TITLE##_resetTimeCost()

#endif // _ar_ProfileUtilEx_h_
