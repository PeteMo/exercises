CFLAGS  = -Wall

all:
	@echo "Which language?"

c: rot.c
	gcc $(CFLAGS) $^ -o rot

haskell: rot.hs
	ghc $(CFLAGS) --make rot

python: rot.py
	cp $^ rot
	chmod 755 rot

make clean:
	rm -f *.o *.hi rot
