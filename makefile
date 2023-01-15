compile:
	rm -rf build/TwoDice
	gcc -o ./build/TwoDice ./src/main.c

run:
	make compile
	echo
	build/TwoDice