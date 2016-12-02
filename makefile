<<<<<<< HEAD
DIRS = incoding main untar
=======
DIRS = incoding main
>>>>>>> 1dc35f28296eba60c2208037c22a2920432a95ce
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
