ATH = addToHeap
DFH = deleteFromHeap
CNC = countNonZeroCharacters
SCF = showCharFrequency
PE = performEncoding
PEN = performEncoding_n
TV = traverse
TVN = traverse_n

FUNCS = $(ATH).o $(DFH).o $(CNC).o $(SCF).o $(PE).o $(PEN).o $(TV).o $(TVN).o
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

$(PEN).o : $(HEAD) $(PEN).c
	gcc -c $(PEN).c -I$(HPWD)

$(TV).o : $(HEAD) $(TV).c
	gcc -c $(TV).c -I$(HPWD)

$(TVN).o : $(HEAD) $(TVN).c
	gcc -c $(TVN).c -I$(HPWD)

clean : 
	rm $(LIB) $(FUNCS)
