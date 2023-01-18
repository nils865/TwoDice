compile:
	gcc -o .\build\TwoDice -lpthread -static -Os src/main.c

run:
	make compile
	echo ---------------------------
	build/TwoDice