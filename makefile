<<<<<<< HEAD
DIRS = incoding untar/lib main
LPWD = /home/rok/mytar/incoding
=======

DIRS = incoding untar main
>>>>>>> 336210ecd83dc95d41192bc530c65fe16273c031

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
