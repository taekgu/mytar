DIRS = incoding untar/lib main
<<<<<<< HEAD
LPWD = /home/rok/mytar/incoding
=======
LPWD = /home/sb/mytar/incoding
>>>>>>> 01830edae84c347629342c844d96a5d3abaea891

all:
	@for d in $(DIRS); \
	do \
		$(MAKE) -C $$d;\
	done

clean:
	@for d in $(DIRS); \
	do \
		$(MAKE) -C $$d clean; \
	done
