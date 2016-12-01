HEAP = heap_Pop
HUFF = huffNode
TREE = tree_loadHuff
WRT = writeData
MAIN = tmain

FUNCS = $(HUFF).o $(TREE).o $(WRT).o
HEAD = head.h
LIB = libdecodingfuncs.a
HPWD = /home/rok/mytar/untar/head
HEAD = $(HPWD)/head.h

$(LIB) : $(HEAD) $(FUNCS)
	ar rv $(LIB) $(FUNCS)

$(HUFF).o : $(HEAD) $(HUFF).cpp
	gcc -c $(HUFF).cpp -I$(HPWD)

$(TREE).o : $(HEAD) $(TREE).cpp
	gcc -c $(TREE).cpp -I$(HPWD)

$(WRT).o : $(HEAD) $(WRT).cpp
	gcc -c $(WRT).cpp -I$(HPWD)

clean : 
	rm $(LIB) $(FUNCS)
