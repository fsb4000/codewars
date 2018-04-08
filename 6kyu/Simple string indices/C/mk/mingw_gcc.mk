CCACHE = ccache
CC = $(CCACHE) gcc
CXX = $(CCACHE) g++
CPPFLAGS = -MT $@ -MMD -MP
TARGET_ARCH ?=

WARNINGS = -Wall -Wextra -pedantic -Wstrict-aliasing=2 -Wformat-security      \
    -Wstrict-overflow=5 -Wfloat-equal -Wformat-extra-args -Wshadow -Winit-self\
    -Wswitch-default -Wformat-nonliteral -Wdouble-promotion -Wnull-dereference\
    -Walloca -Wdouble-promotion -Wduplicated-branches -Wduplicated-cond -Wchkp\
    -Wconversion -Wlogical-not-parentheses -Walloc-zero -Wcast-qual -Wrestrict\
    -Wformat-y2k -Wcast-align -Wlogical-op -Wwrite-strings -Wsign-conversion  \
    -Wredundant-decls -Wmissing-include-dirs -Wswitch-enum -Wstack-protector  \
    -Wunused-const-variable=2 -Wdangling-else -Wnonnull -Werror
    
WARNINGS_C_ONLY = -Wbad-function-cast -Winit-self -fno-common
WARNINGS_FORCE_CXX = -Wno-old-style-cast

LTO = -flto-partition=none -flto -ffat-lto-objects
INCLUDE = -I"include" -isystem"3rd"
SECURITY = -fPIC -fstack-protector-all --param ssp-buffer-size=4 -fstack-check\
    -mindirect-branch=thunk
DEFINES = -D__STDC_WANT_LIB_EXT1__=1 -D__STDC_WANT_LIB_EXT2__=1               \
    -DDEFINE_CONSOLEV2_PROPERTIES -DWIN32_LEAN_AND_MEAN                       \
    -DCEXCEPTION_USE_CONFIG_FILE  -D__USE_MINGW_ANSI_STDIO=1
TEST_DEFINES_C = #-DUNITY_OUTPUT_COLOR -DUNITY_INCLUDE_DOUBLE
DEBUG = -g3
OPENMP = -fopenmp
OPTIMIZE = -Os -fstrict-aliasing -funsafe-math-optimizations -ftracer
CSTANDARD = -std=c11
CXXSTANDARD = -std=c++1z

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

FLAGS = $(OPTIMIZE) $(WARNINGS) $(INCLUDE) $(LTO) $(DEFINES) $(OPENMP)         \
    $(SECURITY) $(DEBUG)
CFLAGS = $(CSTANDARD) $(FLAGS) $(WARNINGS_C_ONLY)
LDFLAGS_C = $(LD_INCLUDE) $(LD_SECURITY) $(LD_LTO) $(LD_SYSTEM) $(DEBUG)
LIBS_C = $(LIBS_3RD_C) $(LIBS_OPENMP) $(LIBS_SYSTEM_C) $(LIBS_THREAD)
