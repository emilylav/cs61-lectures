PROGRAMS = $(sort $(patsubst %.c,%,$(wildcard [rw][0-9]*.c)))

-include conf.mk
ifndef DATAFILE
DATAFILE = data
endif

all: $(PROGRAMS) $(DATAFILE)

O = 2
include ../common/rules.mk
ifneq ($(DATAFILE),data)
CPPFLAGS += -DDATAFILE='"$(DATAFILE)"'
endif

%.o: %.c $(BUILDSTAMP)
	$(CC) $(CPPFLAGS) $(CFLAGS) $(DEPCFLAGS) $(O) -o $@ -c $<

r%: r%.o
	$(CC) $(CFLAGS) $(O) -o $@ $^

w%: w%.o
	$(CC) $(CFLAGS) $(O) -o $@ $^

coherence: coherence.o
	$(CC) $(CFLAGS) $(O) -o $@ $^

matrixmultiply: matrixmultiply.o
	$(CC) $(CFLAGS) $(O) -o $@ $^

base-matrixmultiply: base-matrixmultiply.o
	$(CC) $(CFLAGS) $(O) -o $@ $^

DATASIZE := $(shell cat $(DATAFILE) 2>/dev/null | wc -c | awk '{ print $$1 }')
DATADEP := $(shell if test $(DATASIZE) -lt 51200000; then echo always; fi)
DATADEP_LARGE := $(shell if test $(DATASIZE) -lt 5120000000; then echo always; fi)

$(DATAFILE): $(DATADEP)
	yes 77777777777777777777777777777777777777777 | tr -d '\n' | head -c 51200000 > $@

$(DATAFILE)-large: $(DATADEP_LARGE)
	yes 77777777777777777777777777777777777777777 | tr -d '\n' | head -c 5120000000 > $@

ifneq ($(DATAFILE),data)
data: $(DATAFILE)
data-large: $(DATAFILE)-large
.PHONY: data data-large
endif


clean:
	rm -f *.o $(PROGRAMS) data
	rm -rf $(DEPSDIR) *.dSYM
	for i in r[0-9][0-9]* w[0-9][0-9]*; do if file $$i | grep executable >/dev/null 2>&1; then rm -f $$i; fi; done

cold:
	sync
	echo 3 | sudo tee /proc/sys/vm/drop_caches > /dev/null
	sudo blockdev --flushbufs `df $(DATAFILE) | grep /dev | awk '{ print $$1 }'`

.PHONY: all always clean cold
.PRECIOUS: $(DATAFILE) $(DATAFILE)-large
