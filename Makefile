CFLAGS  = -Wall

all:
	@echo "Which language?"

c: rot.c
	gcc $(CFLAGS) $^ -o rot

haskell: rot.hs
	ghc $(CFLAGS) --make rot

python: rot.py
	ln -sf $^ rot
	chmod 755 rot

shell: rot.sh
	ln -sf $^ rot
	chmod 755 rot
    
make clean:
	rm -f *.o *.hi rot
