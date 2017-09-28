ASMS := $(patsubst %.c,%.s,$(wildcard f[0-9][0-9].c))
ASM_OBJECTS := $(patsubst %.s,%.o,$(ASMS))
ASM_PROGRAMS := $(shell grep -l main $(wildcard f[0-9][0-9].[cs]) | sed 's,\.[cs],,' | sort -u)
DEFAULT_ASM_CFLAGS = -O1
DEFAULT_ASM_CFLAGS_DEBUG = -g $(DEFAULT_ASM_CFLAGS)

PROGRAMS = $(ASM_PROGRAMS) addin

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


addin: addin.o
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
	  CFLAGS="`echo "$(CFLAGS)" | sed 's/ *-g */ /;s/ *-std=[^ ]* */ /'`"; \
	  if test -z "$$ARGS"; then ARGS="$(DEFAULT_ASM_CFLAGS)"; fi; \
	  $(call xrun,$(CC) $$CFLAGS $$ARGS -o $@ $<,ASSEMBLE $@)

allfc.txt: $(wildcard f*.c) always
	for i in f*.c; do echo $$i; echo ========; cat $$i; echo; echo; done > allfc.txt

allfs.txt: $(patsubst %.c,%.s,$(wildcard f*.c)) always
	for i in f*.s; do echo $$i; echo ========; cat $$i; echo; echo; done > allfs.txt


again:
	rm -f *.s
	$(MAKE) all

clean:
	rm -f $(ALLPROGRAMS) *.o

.PHONY: all clean again
