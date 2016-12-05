DIRS = incoding untar/lib main
LPWD = /home/sb/mytar/incoding

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
