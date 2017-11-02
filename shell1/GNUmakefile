PROGRAMS = fork1 fork2 fork2b forkmix forkmix2 manyfork \
	myecho runmyecho \
	pipedemo pipesizer \
	filtermultiples primesieve

all: $(PROGRAMS)

O = 2
include ../common/rules.mk

%.o: %.c $(BUILDSTAMP)
	$(CC) $(CPPFLAGS) $(CFLAGS) $(DEPCFLAGS) $(O) -o $@ -c $<

$(PROGRAMS): %: %.o
	$(CC) $(CFLAGS) $(O) -o $@ $^


clean:
	rm -f *.o $(PROGRAMS) data
	rm -rf $(DEPSDIR) *.dSYM

.PHONY: all clean
