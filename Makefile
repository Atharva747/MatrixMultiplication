all : test

nmultiply : nmultiply.cpp
	g++ nmultiply.cpp -o nmultiply

pmultiply : pmultiply.cpp
	g++ -std=c++11 -pthread pmultiply.cpp -o pmultiply

ndeterminant : ndeterminant.cpp
	g++ ndeterminant.cpp -o ndeterminant

pdeterminant : pdeterminant.cpp
	g++ -std=c++11 -pthread pdeterminant.cpp -o pdeterminant

MTESTS=$(sort $(wildcard *.mtest))
MRUNS=$(patsubst %.mtest,%.mresult,$(MTESTS))

DTESTS=$(sort $(wildcard *.dtest))
DRUNS=$(patsubst %.dtest,%.dresult,$(DTESTS))

test : $(MRUNS) $(DRUNS)

$(MRUNS) : %.mresult : %.mtest Makefile nmultiply pmultiply
	@echo -n "[$* (multiply)] \n\nnaive: \n"
	@time ./nmultiply < $*.mtest > $*n.mout
	@echo -n "\nparallelized: \n"
	@time ./pmultiply < $*.mtest > $*.mout
	@echo -n "\n"
	@((diff -b $*.mout $*.mok > /dev/null) && echo "pass") || (echo "fail" ; echo "--- expected ---"; cat $*.mok; echo "--- found ---" ; cat $*.mout)
	@echo -n "\n"

$(DRUNS) : %.dresult : %.dtest Makefile ndeterminant pdeterminant
	@echo -n "[$* (determinant)] \n\nnaive: \n"
	@time ./ndeterminant < $*.dtest > $*n.dout
	@echo -n "\nparallelized: \n"
	@time ./pdeterminant < $*.dtest > $*.dout
	@echo -n "\n"
	@((diff -b $*.dout $*.dok > /dev/null) && echo "pass") || (echo "fail" ; echo "--- expected ---"; cat $*.dok; echo "--- found ---" ; cat $*.dout)

clean :
	rm -f *.mout
	rm -f *.dout
	rm -f *.d
	rm -f *.o
	rm -f nmultiply
	rm -f pmultiply
	rm -f ndeterminant
	rm -f pdeterminant

-include *.d
