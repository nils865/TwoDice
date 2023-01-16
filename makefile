compile:
	gcc -o ./build/TwoDice ./src/main.c -Os -pthread

run:
	make compile
	echo
	build/TwoDice

compile-windows:
	gcc -o .\build\TwoDice .\src\main.c -Os -pthread

run-windows:
	make compile-windows
	echo ---------------------------
	build/TwoDice