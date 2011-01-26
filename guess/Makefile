CFLAGS  = -Wall

all:
	@echo "Which language?"

c: guess.c
	gcc $(CFLAGS) $^ -o guess

haskell: guess.hs
	ghc $(CFLAGS) --make guess

python: guess.py
	cp $^ guess
	chmod 755 guess

make clean:
	rm -f *.o *.hi guess
