#ifdef _WIN32
//add definition of struct timeval in Windows
#include <time.h>
#include <winsock.h>
#else
#include <sys/time.h>
#endif

#include "simpletools.h"

int main(void)
{
  struct timeval tv;
  pause(250);
  int ret = gettimeofday(&tv, NULL);
  printi("%d\n", ret);
  printi("%ld %d\n", tv.tv_sec, tv.tv_usec);
  
  tv.tv_usec = 0;
  printi("CNT=%llu\n", CNT);
  ret = settimeofday(&tv, NULL);
  pause(250);
  printi("ret=%d; CNT=%llu\n", ret, CNT);
  ret = gettimeofday(&tv, NULL);
  printi("%ld %d\n", tv.tv_sec, tv.tv_usec);
  
  return 0;
}
