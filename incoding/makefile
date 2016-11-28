ATH = addToHeap
DFH = deleteFromHeap
CNC = countNonZeroCharacters
SCF = showCharFrequency
PE = performEncoding
TV = traverse

FUNCS = $(ATH).o $(DFH).o $(CNC).o $(SCF).o $(PE).o $(TV).o
HEAD = head.h
LIB = libincodingfuncs.a
HPWD = /home/sb/mytar
HEAD = $(HPWD)/head.h

$(LIB) : $(HEAD) $(FUNCS)
	ar rv $(LIB) $(FUNCS)

$(ATH).o : $(HEAD) $(ATH).c
	gcc -c $(ATH).c -I$(HPWD)

$(DFH).o : $(HEAD) $(DFH).c
	gcc -c $(DFH).c -I$(HPWD)

$(CNC).o : $(HEAD) $(CNC).c
	gcc -c $(CNC).c -I$(HPWD)

$(SCF).o : $(HEAD) $(SCF).c
	gcc -c $(SCF).c -I$(HPWD)

$(PE).o : $(HEAD) $(PE).c
	gcc -c $(PE).c -I$(HPWD)

$(TV).o : $(HEAD) $(TV).c
	gcc -c $(TV).c -I$(HPWD)

clean : 
	rm $(LIB) $(FUNCS)
