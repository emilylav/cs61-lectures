PROGRAMS = testqs0 testqs1 testqs2 testqs3 \
	testqs4 testqs5 testqs6 testqs7 add addin
all: $(PROGRAMS)

ALLPROGRAMS = $(PROGRAMS)

include ../common/rules.mk

%.o: %.c $(BUILDSTAMP)
	$(CC) $(DEPCFLAGS) $(CPPFLAGS) $(CFLAGS) $(O) -o $@ -c $<

testqs0: qs0.o testqs-list.o allowexec.o hexdump.o
	$(CC) $(CFLAGS) $(O) -o $@ $^

testqs1: qs1.o testqs-list.o allowexec.o hexdump.o
	$(CC) $(CFLAGS) $(O) -o $@ $^

testqs2: qs2.o testqs-list.o allowexec.o hexdump.o
	$(CC) $(CFLAGS) $(O) -o $@ $^

testqs3: qs3.o testqs-list.o allowexec.o hexdump.o
	$(CC) $(CFLAGS) $(O) -o $@ $^

testqs4: qs4.o testqs-array.o allowexec.o hexdump.o
	$(CC) $(CFLAGS) $(O) -o $@ $^

testqs5: qs5.o testqs-array.o allowexec.o hexdump.o
	$(CC) $(CFLAGS) $(O) -o $@ $^

testqs6: qs6.o testqs-array.o allowexec.o hexdump.o
	$(CC) $(CFLAGS) $(O) -o $@ $^

testqs7: qs7.o testqs-array.o allowexec.o hexdump.o
	$(CC) $(CFLAGS) $(O) -o $@ $^

add: add.o addf.o hexdump.o
	$(CC) $(CFLAGS) $(O) -o $@ $^

addin: addin.o hexdump.o
	$(CC) $(CFLAGS) $(O) -o $@ $^

addf.o: addf.c $(BUILDSTAMP)
	$(CC) $(DEPCFLAGS) $(CPPFLAGS) $(CFLAGS) $(O) -fomit-frame-pointer -o $@ -c $<

clean:
	rm -f $(ALLPROGRAMS) *.o

.PHONY: all clean
