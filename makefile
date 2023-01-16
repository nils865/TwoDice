compile:
	rm -rf build/TwoDice
	gcc -o ./build/TwoDice ./src/main.c

run:
	make compile
	echo
	build/TwoDice

compile-windows:
	del .\build\TwoDice
	gcc -o .\build\TwoDice .\src\main.c -Os

run-windows:
	make compile-windows
	echo ---------------------------
	build/TwoDice