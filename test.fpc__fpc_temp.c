#include "_cpu_launch.h"
typedef struct 
{
  char x;
} char1;
typedef struct 
{
  char x;
  char y;
} char2;
typedef struct 
{
  char x;
  char y;
  char z;
} char3;
typedef struct 
{
  char x;
  char y;
  char z;
  char w;
} char4;
inline static char1 make_char1(char x)
{
  char1 out;
  out.x = x;
  return out;
}

inline static char2 make_char2(char x, char y)
{
  char2 out;
  out.x = x;
  out.y = y;
  return out;
}

inline static char3 make_char3(char x, char y, char z)
{
  char3 out;
  out.x = x;
  out.y = y;
  out.z = z;
  return out;
}

inline static char4 make_char4(char x, char y, char z)
{
  char4 out;
  out.x = x;
  out.y = y;
  out.z = z;
  return out;
}

typedef struct 
{
  unsigned char x;
} uchar1;
typedef struct 
{
  unsigned char x;
  unsigned char y;
} uchar2;
typedef struct 
{
  unsigned char x;
  unsigned char y;
  unsigned char z;
} uchar3;
typedef struct 
{
  unsigned char x;
  unsigned char y;
  unsigned char z;
  unsigned char w;
} uchar4;
inline static uchar1 make_uchar1(unsigned char x)
{
  uchar1 out;
  out.x = x;
  return out;
}

inline static uchar2 make_uchar2(unsigned char x, unsigned char y)
{
  uchar2 out;
  out.x = x;
  out.y = y;
  return out;
}

inline static uchar3 make_uchar3(unsigned char x, unsigned char y, unsigned char z)
{
  uchar3 out;
  out.x = x;
  out.y = y;
  out.z = z;
  return out;
}

inline static uchar4 make_uchar4(unsigned char x, unsigned char y, unsigned char z)
{
  uchar4 out;
  out.x = x;
  out.y = y;
  out.z = z;
  return out;
}

typedef struct 
{
  short x;
} short1;
typedef struct 
{
  short x;
  short y;
} short2;
typedef struct 
{
  short x;
  short y;
  short z;
} short3;
typedef struct 
{
  short x;
  short y;
  short z;
  short w;
} short4;
inline static short1 make_short1(short x)
{
  short1 out;
  out.x = x;
  return out;
}

inline static short2 make_short2(short x, short y)
{
  short2 out;
  out.x = x;
  out.y = y;
  return out;
}

inline static short3 make_short3(short x, short y, short z)
{
  short3 out;
  out.x = x;
  out.y = y;
  out.z = z;
  return out;
}

inline static short4 make_short4(short x, short y, short z)
{
  short4 out;
  out.x = x;
  out.y = y;
  out.z = z;
  return out;
}

typedef struct 
{
  unsigned short x;
} ushort1;
typedef struct 
{
  unsigned short x;
  unsigned short y;
} ushort2;
typedef struct 
{
  unsigned short x;
  unsigned short y;
  unsigned short z;
} ushort3;
typedef struct 
{
  unsigned short x;
  unsigned short y;
  unsigned short z;
  unsigned short w;
} ushort4;
inline static ushort1 make_ushort1(unsigned short x)
{
  ushort1 out;
  out.x = x;
  return out;
}

inline static ushort2 make_ushort2(unsigned short x, unsigned short y)
{
  ushort2 out;
  out.x = x;
  out.y = y;
  return out;
}

inline static ushort3 make_ushort3(unsigned short x, unsigned short y, unsigned short z)
{
  ushort3 out;
  out.x = x;
  out.y = y;
  out.z = z;
  return out;
}

inline static ushort4 make_ushort4(unsigned short x, unsigned short y, unsigned short z)
{
  ushort4 out;
  out.x = x;
  out.y = y;
  out.z = z;
  return out;
}

typedef struct 
{
  int x;
} int1;
typedef struct 
{
  int x;
  int y;
} int2;
typedef struct 
{
  int x;
  int y;
  int z;
} int3;
typedef struct 
{
  int x;
  int y;
  int z;
  int w;
} int4;
inline static int1 make_int1(int x)
{
  int1 out;
  out.x = x;
  return out;
}

inline static int2 make_int2(int x, int y)
{
  int2 out;
  out.x = x;
  out.y = y;
  return out;
}

inline static int3 make_int3(int x, int y, int z)
{
  int3 out;
  out.x = x;
  out.y = y;
  out.z = z;
  return out;
}

inline static int4 make_int4(int x, int y, int z)
{
  int4 out;
  out.x = x;
  out.y = y;
  out.z = z;
  return out;
}

typedef struct 
{
  unsigned int x;
} uint1;
typedef struct 
{
  unsigned int x;
  unsigned int y;
} uint2;
typedef struct 
{
  unsigned int x;
  unsigned int y;
  unsigned int z;
} uint3;
typedef struct 
{
  unsigned int x;
  unsigned int y;
  unsigned int z;
  unsigned int w;
} uint4;
inline static uint1 make_uint1(unsigned int x)
{
  uint1 out;
  out.x = x;
  return out;
}

inline static uint2 make_uint2(unsigned int x, unsigned int y)
{
  uint2 out;
  out.x = x;
  out.y = y;
  return out;
}

inline static uint3 make_uint3(unsigned int x, unsigned int y, unsigned int z)
{
  uint3 out;
  out.x = x;
  out.y = y;
  out.z = z;
  return out;
}

inline static uint4 make_uint4(unsigned int x, unsigned int y, unsigned int z)
{
  uint4 out;
  out.x = x;
  out.y = y;
  out.z = z;
  return out;
}

typedef struct 
{
  long x;
} long1;
typedef struct 
{
  long x;
  long y;
} long2;
typedef struct 
{
  long x;
  long y;
  long z;
} long3;
typedef struct 
{
  long x;
  long y;
  long z;
  long w;
} long4;
inline static long1 make_long1(long x)
{
  long1 out;
  out.x = x;
  return out;
}

inline static long2 make_long2(long x, long y)
{
  long2 out;
  out.x = x;
  out.y = y;
  return out;
}

inline static long3 make_long3(long x, long y, long z)
{
  long3 out;
  out.x = x;
  out.y = y;
  out.z = z;
  return out;
}

inline static long4 make_long4(long x, long y, long z)
{
  long4 out;
  out.x = x;
  out.y = y;
  out.z = z;
  return out;
}

typedef struct 
{
  unsigned long x;
} ulong1;
typedef struct 
{
  unsigned long x;
  unsigned long y;
} ulong2;
typedef struct 
{
  unsigned long x;
  unsigned long y;
  unsigned long z;
} ulong3;
typedef struct 
{
  unsigned long x;
  unsigned long y;
  unsigned long z;
  unsigned long w;
} ulong4;
inline static ulong1 make_ulong1(unsigned long x)
{
  ulong1 out;
  out.x = x;
  return out;
}

inline static ulong2 make_ulong2(unsigned long x, unsigned long y)
{
  ulong2 out;
  out.x = x;
  out.y = y;
  return out;
}

inline static ulong3 make_ulong3(unsigned long x, unsigned long y, unsigned long z)
{
  ulong3 out;
  out.x = x;
  out.y = y;
  out.z = z;
  return out;
}

inline static ulong4 make_ulong4(unsigned long x, unsigned long y, unsigned long z)
{
  ulong4 out;
  out.x = x;
  out.y = y;
  out.z = z;
  return out;
}

typedef struct 
{
  long long x;
} longlong1;
typedef struct 
{
  long long x;
  long long y;
} longlong2;
typedef struct 
{
  long long x;
  long long y;
  long long z;
} longlong3;
typedef struct 
{
  long long x;
  long long y;
  long long z;
  long long w;
} longlong4;
inline static longlong1 make_longlong1(long long x)
{
  longlong1 out;
  out.x = x;
  return out;
}

inline static longlong2 make_longlong2(long long x, long long y)
{
  longlong2 out;
  out.x = x;
  out.y = y;
  return out;
}

inline static longlong3 make_longlong3(long long x, long long y, long long z)
{
  longlong3 out;
  out.x = x;
  out.y = y;
  out.z = z;
  return out;
}

inline static longlong4 make_longlong4(long long x, long long y, long long z)
{
  longlong4 out;
  out.x = x;
  out.y = y;
  out.z = z;
  return out;
}

typedef struct 
{
  unsigned long long x;
} ulonglong1;
typedef struct 
{
  unsigned long long x;
  unsigned long long y;
} ulonglong2;
typedef struct 
{
  unsigned long long x;
  unsigned long long y;
  unsigned long long z;
} ulonglong3;
typedef struct 
{
  unsigned long long x;
  unsigned long long y;
  unsigned long long z;
  unsigned long long w;
} ulonglong4;
inline static ulonglong1 make_ulonglong1(unsigned long long x)
{
  ulonglong1 out;
  out.x = x;
  return out;
}

inline static ulonglong2 make_ulonglong2(unsigned long long x, unsigned long long y)
{
  ulonglong2 out;
  out.x = x;
  out.y = y;
  return out;
}

inline static ulonglong3 make_ulonglong3(unsigned long long x, unsigned long long y, unsigned long long z)
{
  ulonglong3 out;
  out.x = x;
  out.y = y;
  out.z = z;
  return out;
}

inline static ulonglong4 make_ulonglong4(unsigned long long x, unsigned long long y, unsigned long long z)
{
  ulonglong4 out;
  out.x = x;
  out.y = y;
  out.z = z;
  return out;
}

typedef struct 
{
  float x;
} float1;
typedef struct 
{
  float x;
  float y;
} float2;
typedef struct 
{
  float x;
  float y;
  float z;
} float3;
typedef struct 
{
  float x;
  float y;
  float z;
  float w;
} float4;
inline static float1 make_float1(float x)
{
  float1 out;
  out.x = x;
  return out;
}

inline static float2 make_float2(float x, float y)
{
  float2 out;
  out.x = x;
  out.y = y;
  return out;
}

inline static float3 make_float3(float x, float y, float z)
{
  float3 out;
  out.x = x;
  out.y = y;
  out.z = z;
  return out;
}

inline static float4 make_float4(float x, float y, float z)
{
  float4 out;
  out.x = x;
  out.y = y;
  out.z = z;
  return out;
}

typedef struct 
{
  double x;
} double1;
typedef struct 
{
  double x;
  double y;
} double2;
typedef struct 
{
  double x;
  double y;
  double z;
} double3;
typedef struct 
{
  double x;
  double y;
  double z;
  double w;
} double4;
inline static double1 make_double1(double x)
{
  double1 out;
  out.x = x;
  return out;
}

inline static double2 make_double2(double x, double y)
{
  double2 out;
  out.x = x;
  out.y = y;
  return out;
}

inline static double3 make_double3(double x, double y, double z)
{
  double3 out;
  out.x = x;
  out.y = y;
  out.z = z;
  return out;
}

inline static double4 make_double4(double x, double y, double z)
{
  double4 out;
  out.x = x;
  out.y = y;
  out.z = z;
  return out;
}

typedef uint3 dim3;
inline static dim3 _make_dim_3(int in[], int n)
{
  if (n == 1)
  {
    return make_uint3(in[0], 1, 1);
  }
  if (n == 2)
  {
    return make_uint3(in[0], in[1], 1);
  }
  if (n == 3)
  {
    return make_uint3(in[0], in[1], in[2]);
  }
  return make_uint3(1, 1, 1);
}

typedef enum 
{
  fpcSuccess = 0,
  fpcError = 1
} fpcError_t;
typedef enum 
{
  fpcMemcpyHostToHost = 0,
  fpcMemcpyHostToDevice = 1,
  fpcMemcpyDeviceToHost = 2,
  fpcMemcpyDeviceToDevice = 3,
  fpcMemcpyDefault = 4
} fpcMemcpyKind;
typedef unsigned long size_t;
void *memcpy(void *dest, const void *src, size_t n);
void *malloc(long unsigned int);
void free(void *);
int rand(void);
inline static fpcError_t fpcMalloc(void **in, size_t sz)
{
  *in = malloc(sz);
  if ((*in) == ((void *) 0))
    return fpcError;
  return fpcSuccess;
}

inline static fpcError_t fpcFree(void *in)
{
  free(in);
  return fpcSuccess;
}

inline static fpcError_t fpcMemcpy(void *dst, const void *src, size_t count, fpcMemcpyKind kind)
{
  memcpy(dst, src, count);
  return fpcSuccess;
}

int printf(const char *, ...);
typedef unsigned long clock_t;
typedef long time_t;
struct tm
{
  int tm_sec;
  int tm_min;
  int tm_hour;
  int tm_mday;
  int tm_mon;
  int tm_year;
  int tm_wday;
  int tm_yday;
  int tm_isdst;
  long tm_gmtoff;
  char *tm_zone;
};
char *asctime(const struct tm *);
clock_t clock(void);
char *ctime(const time_t *);
double difftime(time_t, time_t);
struct tm *getdate(const char *);
struct tm *gmtime(const time_t *);
struct tm *localtime(const time_t *);
time_t mktime(struct tm *);
size_t strftime(char * restrict, size_t, const char * restrict, const struct tm * restrict);
char *strptime(const char * restrict, const char * restrict, struct tm * restrict);
time_t time(time_t *);
int main()
{
  return 0;
}

