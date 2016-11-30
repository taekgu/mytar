HEAP = heap_Pop.cpp
HUFF = huffNode.cpp
TREE = tree_loadHuff.cpp
WRT = writeData.cpp
MAIN = tmain.cpp

FUNCS = $(HEAP).o $(HUFF).o $(TREE).o $(WRT).o
HEAD = head.h
LIB = libdecodingfuncs.a
HPWD = /home/rok/mytar/untar/head
HEAD = $(HPWD)/head.h

$(LIB) : $(HEAD) $(FUNCS)
	ar rv $(LIB) $(FUNCS)

$(HEAP).o : $(HEAD) $(HEAP)
	gcc -c $(ATH).c -I$(HPWD)

$(HUFF).o : $(HEAD) $(HUFF)
	gcc -c $(DFH).c -I$(HPWD)

$(TREE).o : $(HEAD) $(TREE)
	gcc -c $(CNC).c -I$(HPWD)

$(WRT).o : $(HEAD) $(WRT)
	gcc -c $(SCF).c -I$(HPWD)

clean : 
	rm $(LIB) $(FUNCS)
