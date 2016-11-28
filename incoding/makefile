ATH = addToHeap
DFH = deleteFromHeap
CNC = countNonZeroCharacters
SCF = showCharFrequency
PE = performEncoding

FUNCS = $(ATH).o $(DFH).o $(CNC).o $(SCF).o $(PE).o
HEAD = head.h
LIB = libincofigfuncs.a

$(LIB) : $(HEAD) $(FUNCS)
	ar rv $(LIB) $(FUNCS)

$(ATH).o : $(HEAD) $(ATH).c
	gcc -c $(ATH).c -I.

$(DFH).o : $(HEAD) $(DFH).c
	gcc -c $(DFH).c -I.

$(CNC).o : $(HEAD) $(CNC).c
	gcc -c $(CNC).c -I.

$(SCF).o : $(HEAD) $(SCF).c
	gcc -c $(SCF).c -I. 

$(PE).o : $(HEAD) $(PE).c
	gcc -c $(PE).c -I.

clean : 
	rm $(LIB) $(FUNCS)
