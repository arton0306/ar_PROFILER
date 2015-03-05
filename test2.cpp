#include "ar_ProfileUtil.h"

ar_PROFILE_EXPORT(SUM)
ar_PROFILE_EXPORT(COUNT)

int mySum( int x )
{
    ar_PROFILE_START(SUM);
    if ( x < 0 ) return 0;
    int sum = 0;
    for ( int i = 0; i < x; ++i )
    {
        sum += i;
    }
    ar_PROFILE_STOP(SUM);
    return sum;
}

int myCount( int x )
{
    ar_PROFILE_START(COUNT);
    if ( x < 0 ) return 0;
    int count = 0;
    for ( int i = 0; i < x; ++i )
    {
        count += 1;
    }
    ar_PROFILE_STOP(COUNT);
    return count;
}

