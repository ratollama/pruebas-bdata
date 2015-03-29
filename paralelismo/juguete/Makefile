CC=g++
NUMBER=250000
CFLAGS=-D NUMBER=$(NUMBER) -O2
NTHREADS := $(shell grep -c ^processor /proc/cpuinfo)
TARGS=-D NTHREADS=$(NTHREADS)

make:
	$(CC) $(CFLAGS) unhilo.cpp -o singleThread
	$(CC) $(CFLAGS) $(TARGS) -pthread  nhilos.cpp -o multiThread
	$(CC) $(CFLAGS) -fopenmp nhilosb.cpp -o multiThread_openmp

.PHONY: test
test:
	/usr/bin/time --format="#### TOTAL TIME: %E ####" ./singleThread
	/usr/bin/time --format="#### TOTAL TIME: %E ####" ./multiThread
	/usr/bin/time --format="#### TOTAL TIME: %E ####" ./multiThread_openmp