#include "my_statistics_float.h"
#include "my_statistics_double.h"

#define BASE_FLOAT
#include "templates_on.h"
#include "max_source.c"
#include "templates_off.h"
#undef BASE_FLOAT

#define BASE_DOUBLE
#include "templates_on.h"
#include "max_source.c"
#include "templates_off.h"
#undef BASE_DOUBLE
