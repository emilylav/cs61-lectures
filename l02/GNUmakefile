PROGRAMS = add mexplore.noopt mexplore.opt ubexplore.noopt ubexplore.opt
all: $(PROGRAMS)

ALLPROGRAMS = $(PROGRAMS)

include ../common/rules.mk

%.o: %.c $(BUILDSTAMP)
	$(CC) $(DEPCFLAGS) $(CPPFLAGS) $(CFLAGS) $(O) -o $@ -c $<

%.opt.o: %.c $(BUILDSTAMP)
	$(CC) $(DEPCFLAGS) $(CPPFLAGS) $(CFLAGS) -O3 -o $@ -c $<

%.noopt.o: %.c $(BUILDSTAMP)
	$(CC) $(DEPCFLAGS) $(CPPFLAGS) $(CFLAGS) -O0 -o $@ -c $<

mexplore.noopt ubexplore.noopt: %.noopt: %.noopt.o allowexec.o hexdump.o
	$(CC) $(CFLAGS) -O0 -o $@ $^

mexplore.opt ubexplore.opt: %.opt: %.opt.o allowexec.o hexdump.o
	$(CC) $(CFLAGS) -O3 -o $@ $^

add: add.o addf.o hexdump.o
	$(CC) $(CFLAGS) $(O) -o $@ $^

clean:
	rm -f $(ALLPROGRAMS) *.o

.PHONY: all clean
