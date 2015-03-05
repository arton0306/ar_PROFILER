// https://starforcefield.wordpress.com/2012/08/06/c%E8%AA%9E%E8%A8%80%EF%BC%9A%E4%BD%BF%E7%94%A8clock_gettime%E8%A8%88%E7%AE%97%E7%A8%8B%E5%BC%8F%E7%A2%BC%E7%9A%84%E6%99%82%E9%96%93%E9%9C%80%E6%B1%82/

#include <time.h>
#include <stdio.h>

int main()
{
  struct timespec tt;
  clock_getres(CLOCK_REALTIME, &tt);
  printf("CLOCK_REALTIME resolution: %ld ns\n", tt.tv_nsec);
  return 0;
}
