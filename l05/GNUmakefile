TESTGC_PROGRAMS = $(patsubst gc61%.c,testgc%,$(wildcard gc61*.c))
PROGRAMS = mallocbench mallocbench-01 mallocbench-02 mallocbench-03 \
	$(TESTGC_PROGRAMS)

all: $(PROGRAMS)

ALLPROGRAMS = $(PROGRAMS)

O = 1
include ../common/rules.mk

UNSAFE_CFLAGS := $(CFLAGS) -U_FORTIFY_SOURCE -fno-stack-protector

%.o: %.c $(BUILDSTAMP)
	$(CC) $(CFLAGS) $(DEPCFLAGS) $(O) -o $@ -c $<

%.noopt.o: %.c $(BUILDSTAMP)
	$(CC) $(CFLAGS) $(DEPCFLAGS) -O0 -o $@ -c $<

%.unsafe.o: %.c $(BUILDSTAMP)
	$(CC) $(UNSAFE_CFLAGS) $(DEPCFLAGS) $(O) -o $@ -c $<

mallocbench mallocbench-01 mallocbench-02 mallocbench-03: \
%: %.o
	$(CC) $(CFLAGS) $(O) -o $@ $^

testgc: testgc.noopt.o gc61.o
	$(CC) $(CFLAGS) $(O) -o $@ $^

.SECONDEXPANSION:
find_testgc_o = $(patsubst %.c,%.noopt.o,$(wordlist 1,1,$(wildcard echo $(1) testgc.c)))
testgc-%: $$(call find_testgc_o,testgc-$$*.c) gc61-%.c
	$(CC) $(CFLAGS) $(O) -o $@ $^


clean:
	rm -f $(ALLPROGRAMS) *.o

.PHONY: all clean
