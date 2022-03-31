fullbuild:
	cmake -B build; cmake --build build

clean:
	rm -rf build

build:
	cmake --build build

rebuild:
	make clean && make fullbuild

run:
	build/main

test:
	build/tests/test