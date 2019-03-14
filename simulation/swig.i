%module AirSimulation

%{
#include "Board_Class.h"
#include <vector>
#include <iostream>
#include <random>
%}

%include "Board_Class.h"


gcc -c Board_Class.h swig_wrap.cxx  -I/Users/samschickler/anaconda/bin
        cc -bundle `python-config --ldflags` swig_wrap.o