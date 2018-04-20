./bin/test_c$(EXEEXT): CFLAGS += $(SANITIZERS)
./bin/test_c$(EXEEXT): $(OBJ_TEST_C)
	$(CC) -o $@ $^ $(LDFLAGS_C) $(LIBS_C) $(SANITIZERS)

./bin/test_cpp$(EXEEXT): CFLAGS += $(SANITIZERS)
./bin/test_cpp$(EXEEXT): CC = $(CXX)
./bin/test_cpp$(EXEEXT): WARNINGS_C_ONLY = $(WARNINGS_FORCE_CXX)
./bin/test_cpp$(EXEEXT): CSTANDARD = $(CXXSTANDARD)
./bin/test_cpp$(EXEEXT): $(OBJ_TEST_C)
	$(CC) -o $@ $^ $(LDFLAGS_C) $(LIBS_C) $(SANITIZERS)


clean_details:
	find .  -name "*.o" -type f -delete
	find .  -name "*.d" -type f -delete
	find .  -name "*.orig" -type f -delete
	rm -f "bin/test_c$(EXEEXT)"
	rm -f "bin/test_cpp$(EXEEXT)"

help_details:
	@echo "The following are some of the valid targets for this makefile:"
	@echo "    all (the default if no target is provided)"
	@echo "    force_cpp"
	@echo "    clean"
	@echo "    help"

.PHONY: all help help_details clean clean_details force_cpp

include $(wildcard $(patsubst %, %.d,$(basename $(OBJS))))
