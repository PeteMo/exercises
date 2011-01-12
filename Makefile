CFLAGS  = -Wall
CLEANUP = rot hot.hi rot.o

haskell: rot.hs
	ghc $(CFLAGS) $^ -o rot
	
c: rot.c
	gcc $(CFLAGS) $^ -o rot

python:
	ln -sf rot.py rot
    
make clean:
	rm -f *.o *.hi rot
