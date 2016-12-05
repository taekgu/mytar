HEAP = heap_Pop
HUFF = huffNode
TREE = tree_loadHuff
WRT = writeData
MAIN = tmain

FUNCS = $(HUFF).o $(WRT).o $(TREE).o
LIB = libdecodingfuncs.a
HPWD = /home/sb/mytar
HEAD = $(HPWD)/head.h

$(LIB) : $(HEAD) $(FUNCS)
	ar rv $(LIB) $(FUNCS)

$(HUFF).o : $(HEAD) $(HUFF).c
	gcc -c $(HUFF).c -I$(HPWD)

$(WRT).o : $(HEAD) $(WRT).c
	gcc -c $(WRT).c -I$(HPWD)

$(TREE).o : $(HEAD) $(TREE).c
	gcc -c $(TREE).c -I$(HPWD)

clean : 
	rm $(LIB) $(FUNCS)
