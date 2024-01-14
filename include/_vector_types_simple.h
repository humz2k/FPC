
#ifndef type
#define type char
#endif

#ifndef typename
#define typename char
#endif

#define _COMBINE(x,y) x ## y
#define _combine(x,y) _COMBINE(x,y)

#define vector1 _combine(typename,1)
#define vector2 _combine(typename,2)
#define vector3 _combine(typename,3)
#define vector4 _combine(typename,4)
#define make_vector1 _combine(make_,vector1)
#define make_vector2 _combine(make_,vector2)
#define make_vector3 _combine(make_,vector3)
#define make_vector4 _combine(make_,vector4)

struct vector1;
typedef struct vector1 vector1;

struct vector2;
typedef struct vector2 vector2;

struct vector3;
typedef struct vector3 vector3;

struct vector4;
typedef struct vector4 vector4;

#undef vector1
#undef vector2
#undef vector3
#undef vector4
#undef _combine
#undef _COMBINE
#undef typename
#undef type