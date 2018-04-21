include mk/vala_gen.mk

./bin/test_vala$(EXEEXT) : CFLAGS += $(SANITIZERS) $(VALA_C_FLAGS)
./bin/test_vala$(EXEEXT) : LIBS_C += $(VALA_C_LIBS)
./bin/test_vala$(EXEEXT) : $(SRC_C_TEST_VALA) $(OBJ_TEST_VALA)
	$(CC) -o $@ $(OBJ_TEST_VALA) $(LDFLAGS_C) $(LIBS_C) $(SANITIZERS) 

clean_details:
	rm -f $(SRC_C_TEST_VALA)
	find .  -name "*.o"    ! -path "./.git/*" ! -path "./msvc_2017/*" -type f -delete
	find .  -name "*.d"    ! -path "./.git/*" ! -path "./msvc_2017/*" -type f -delete
	find .  -name "*.orig" ! -path "./.git/*" ! -path "./msvc_2017/*" -type f -delete
	rm -f "bin/test_vala$(EXEEXT)"

help_details:
	@echo "The following are some of the valid targets for this makefile:"
	@echo "    all (the default if no target is provided)(=debug)"
	@echo "    clean"
	@echo "    help"

.PHONY: all help help_details clean clean_details

include $(wildcard $(patsubst %, %.d,$(basename $(OBJS))))
