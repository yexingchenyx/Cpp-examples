#if defined(BASE_FLOAT)
#define BASE float
#define NAME float
#elif defined(BASE_DOUBLE)
#define BASE double
#define NAME double
#endif

#define CONCATE3x(a, b, c) a ## _ ## b ## _ ## c
#define CONCATE3(a, b, c) CONCATE3x(a, b, c)

#define FUNCTION(a, c) CONCATE3(a, NAME, c)