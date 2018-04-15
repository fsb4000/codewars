CCACHE = ccache
CC = $(CCACHE) gcc
CPPFLAGS = -MT $@ -MMD -MP
TARGET_ARCH ?=

LTO = -flto-partition=none -flto -ffat-lto-objects
INCLUDE =
SECURITY = -fPIC -fstack-protector-all --param ssp-buffer-size=4 -fstack-check\
    -mindirect-branch=thunk
DEFINES =
DEBUG = -g3
OPENMP = -fopenmp
OPTIMIZE = -Os -fstrict-aliasing -funsafe-math-optimizations -ftracer
CSTANDARD = -std=c11

SANITIZERS =
THREAD_SANITIZER =

LD_LTO = -flto-partition=none -flto -ffat-lto-objects
LD_INCLUDE =
LD_SECURITY = -Wl,--dynamicbase -Wl,--nxcompat
ifeq ($(findstring 64,$(BITS)),64)
	LD_SECURITY += -Wl,--high-entropy-va
endif
LD_SYSTEM = -Wl,-subsystem,console -Wl,-O1

LIBS_OPENMP = -fopenmp
LIBS_SYSTEM_C = -lm -lssp
LIBS_THREAD =  -pthread -Wl,--no-as-needed -lpthread
LIBS_3RD_C =

FLAGS = $(OPTIMIZE) $(INCLUDE) $(LTO) $(DEFINES) $(OPENMP) $(SECURITY) $(DEBUG)
CFLAGS = $(CSTANDARD) $(FLAGS) $(WARNINGS_C_ONLY)
LDFLAGS_C = $(LD_INCLUDE) $(LD_SECURITY) $(LD_LTO) $(LD_SYSTEM) $(DEBUG)
LIBS_C = $(LIBS_3RD_C) $(LIBS_OPENMP) $(LIBS_SYSTEM_C) $(LIBS_THREAD)
