PROGRAMS = $(sort $(patsubst %.c,%,$(wildcard [rw][0-9]*.c))) coherence

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

DATASIZE := $(shell wc -c $(DATAFILE) | awk '{ print $$1 }')
DATADEP := $(shell if test $(DATASIZE) -lt 51200000; then echo always; fi)

$(DATAFILE): $(DATADEP)
	yes 77777777777777777777777777777777777777777 | tr -d '\n' | head -c 51200000 > $@

ifneq ($(DATAFILE),data)
data: $(DATAFILE)
.PHONY: data
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
