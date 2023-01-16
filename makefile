compile:
	gcc -o .\build\TwoDice .\src\main.c -Os -pthread

run:
	make compile
	echo ---------------------------
	build/TwoDice