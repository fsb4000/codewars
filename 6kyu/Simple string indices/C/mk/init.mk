VALGRIND ?= 0
EXEEXT = 

OBJ_UNITY_C = 3rd/unity/unity.o 3rd/unity/unity_fixture.o


OBJ_TEST_C = $(OBJ_UNITY_C)
                                                                                       

OBJS = $(OBJ_TEST_C)

include mk/detect_os.mk
include mk/optional_ccache.mk
include mk/disable_sanitizers_if_enabled_valgrind.mk

COMPILE.c = $(CC) $(CFLAGS) $(CPPFLAGS) $(TARGET_ARCH) -c

%.o : %.c
%.o : %.c %.d
	$(COMPILE.c) $(OUTPUT_OPTION) $<

%.d: ;
.PRECIOUS: %.d

