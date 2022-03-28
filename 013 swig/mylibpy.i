%module mylibpy
%{
#define SWIG_FILE_WITH_INIT
#include "mylib/add.h"
#include "mylib/subtract.h"
%}

%include "cpointer.i"
%include "carrays.i"
%include "cmalloc.i"
%array_functions(int, int_p)
%array_functions(int*, int_p_p)

%include "inc/mylib/add.h"
