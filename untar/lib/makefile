HEAP = heap_Pop
HUFF = huffNode
TREE = tree_loadHuff
WRT = writeData
NO = writeData_n

FUNCS = $(HUFF).o $(WRT).o $(NO).o $(TREE).o
LIB = libdecodingfuncs.a
HPWD = /home/rok/mytar
HEAD = $(HPWD)/head.h

$(LIB) : $(HEAD) $(FUNCS)
	ar rv $(LIB) $(FUNCS)

$(HUFF).o : $(HEAD) $(HUFF).c
	gcc -c $(HUFF).c -I$(HPWD)

$(WRT).o : $(HEAD) $(WRT).c
	gcc -c $(WRT).c -I$(HPWD)

$(NO).o : $(HEAD) $(NO).c
	gcc -c $(NO).c -I$(HPWD)

$(TREE).o : $(HEAD) $(TREE).c
	gcc -c $(TREE).c -I$(HPWD)

clean : 
	rm $(LIB) $(FUNCS)
