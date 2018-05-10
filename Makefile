all : parallelized

parallelized : parallelized.cpp
	g++ -std=c++11 -pthread parallelized.cpp -o parallelized

TESTS=$(sort $(wildcard *.test))
RUNS=$(patsubst %.test,%.result,$(TESTS))

test : $(RUNS)

$(RUNS) : %.result : %.test Makefile parallelized
	@echo -n "[$*] \n\nnaive: \n"
	@time ./naive < $*.test > n.out
	@echo -n "\nparallelized: \n"
	@time ./parallelized < $*.test > $*.out
	@echo -n "\n"
	@((diff -b $*.out $*.ok > /dev/null) && echo "pass") || (echo "fail" ; echo "--- expected ---"; cat $*.ok; echo "--- found ---" ; cat $*.out)
	@echo -n "\n"

clean :
	rm -f *.out
	rm -f *.d
	rm -f *.o
	rm -f parallelized

-include *.d
