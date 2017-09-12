PROGRAMS = mexplore ubexplore.noopt ubexplore.opt \
	ubexplore2.opt ubexplore2.noopt ubexplore2.wrapv \
	badmem badmem2 badmem3
all: $(PROGRAMS)

O = 3
ALLPROGRAMS = $(PROGRAMS)

include ../common/rules.mk

%.o: %.c $(BUILDSTAMP)
	$(CC) $(DEPCFLAGS) $(CPPFLAGS) $(CFLAGS) $(O) -o $@ -c $<

%.opt.o: %.c $(BUILDSTAMP)
	$(CC) $(DEPCFLAGS) $(CPPFLAGS) $(CFLAGS) -O3 -o $@ -c $<

%.noopt.o: %.c $(BUILDSTAMP)
	$(CC) $(DEPCFLAGS) $(CPPFLAGS) $(CFLAGS) -O0 -o $@ -c $<

%.wrapv.o: %.c $(BUILDSTAMP)
	$(CC) $(DEPCFLAGS) $(CPPFLAGS) $(CFLAGS) -fwrapv $(O) -o $@ -c $<

mexplore ubexplore ubexplore2 \
badmem badmem2 badmem3: \
%: %.o allowexec.o hexdump.o
	$(CC) $(CFLAGS) -O0 -o $@ $^

ubexplore.noopt ubexplore2.noopt: \
%.noopt: %.noopt.o allowexec.o hexdump.o
	$(CC) $(CFLAGS) -O0 -o $@ $^

ubexplore.opt ubexplore2.opt: \
%.opt: %.opt.o allowexec.o hexdump.o
	$(CC) $(CFLAGS) -O3 -o $@ $^

ubexplore2.wrapv: \
%.wrapv: %.wrapv.o allowexec.o hexdump.o
	$(CC) $(CFLAGS) $(O) -o $@ $^

clean:
	rm -f $(ALLPROGRAMS) *.o *.wrapv *.noopt *.opt

.PHONY: all clean
