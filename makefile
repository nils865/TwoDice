compile:
	gcc -o .\build\TwoDice .\src\main.c -Os -pthread

run:
	make compile-windows
	echo ---------------------------
	build/TwoDice