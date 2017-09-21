TESTGC_PROGRAMS = $(patsubst gc61%.c,testgc%,$(wildcard gc61*.c))

ASMS := $(patsubst %.c,%.s,$(wildcard f[0-9][0-9].c))
ASM_OBJECTS := $(patsubst %.s,%.o,$(ASMS))
ASM_PROGRAMS := $(shell grep -l main $(wildcard f[0-9][0-9].[cs]) | sed 's,\.[cs],,' | sort -u)
DEFAULT_ASM_CFLAGS = -O1
DEFAULT_ASM_CFLAGS_DEBUG = -g $(DEFAULT_ASM_CFLAGS)

PROGRAMS = $(TESTGC_PROGRAMS) $(ASM_PROGRAMS)

all: $(ASMS) $(PROGRAMS)

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

testgc: testgc.noopt.o gc61.o
	$(CC) $(CFLAGS) $(O) -o $@ $^

testgc-class: testgc-class.noopt.o gc61-class.o
	$(CC) $(CFLAGS) $(O) -o $@ $^

.SECONDEXPANSION:
find_testgc_o = $(patsubst %.c,%.noopt.o,$(wordlist 1,1,$(wildcard echo $(1) testgc.c)))
testgc-%: $$(call find_testgc_o,testgc-$$*.c) gc61-%.c
	$(CC) $(CFLAGS) $(O) -o $@ $^


$(ASM_OBJECTS): %.o: %.s $(BUILDSTAMP)
	$(call run,$(CC) -o $@ -c,ASSEMBLE,$<)

%.s: %.c GNUmakefile
	@ARGS=$$(grep '^//!' $< | sed 's/.*! *//'); \
	  CFLAGS="`echo "$(CFLAGS)" | sed 's/ *-g */ /'`"; \
	  if test -z "$$ARGS"; then ARGS="$(DEFAULT_ASM_CFLAGS)"; fi; \
	  $(call xrun,$(CC) $$CFLAGS $$ARGS -o $@ -S $<,COMPILE -S $$ARGS $<) && { $(call cleanasm,$@); }

$(ASM_PROGRAMS): %: %.s
	@ARGS=$$(grep '^//!' $< | sed 's/.*! *//'); \
	  CFLAGS="`echo "$(CFLAGS)" | sed 's/ *-g */ /'`"; \
	  if test -z "$$ARGS"; then ARGS="$(DEFAULT_ASM_CFLAGS)"; fi; \
	  $(call xrun,$(CC) $$CFLAGS $$ARGS -o $@ $<,ASSEMBLE $@)


clean:
	rm -f $(ALLPROGRAMS) *.o

.PHONY: all clean
