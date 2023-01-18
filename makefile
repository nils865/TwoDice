compile:
	gcc -o .\build\TwoDice .\src\main.c -Os -pthread -static

run:
	make compile
	echo ---------------------------
	build/TwoDice