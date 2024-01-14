
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

typedef struct {
    type x;
} vector1;

typedef struct {
    type x;
    type y;
} vector2;

typedef struct {
    type x;
    type y;
    type z;
} vector3;

typedef struct {
    type x;
    type y;
    type z;
    type w;
} vector4;

static inline vector1 make_vector1(type x){
    vector1 out;
    out.x = x;
    return out;
}

static inline vector2 make_vector2(type x, type y){
    vector2 out;
    out.x = x;
    out.y = y;
    return out;
}

static inline vector3 make_vector3(type x, type y, type z){
    vector3 out;
    out.x = x;
    out.y = y;
    out.z = z;
    return out;
}

static inline vector4 make_vector4(type x, type y, type z){
    vector4 out;
    out.x = x;
    out.y = y;
    out.z = z;
    return out;
}

#undef vector1
#undef vector2
#undef vector3
#undef vector4
#undef make_vector1
#undef make_vector2
#undef make_vector3
#undef make_vector4
#undef _combine
#undef _COMBINE
#undef typename
#undef type