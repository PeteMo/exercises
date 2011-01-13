CFLAGS  = -Wall

all:
	@echo "Which language?"

c: rot.c
	gcc $(CFLAGS) $^ -o rot

haskell: rot.hs
	ghc $(CFLAGS) $^ -o rot

python:
	ln -sf rot.py rot
	chmod 755 rot

shell:
	ln -sf rot.sh rot
	chmod 755 rot
    
make clean:
	rm -f *.o *.hi rot
