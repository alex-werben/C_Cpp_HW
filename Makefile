fullbuild:
	cmake -B build; cmake --build build

clean:
	rm -rf build

build:
	cmake --build build

rebuild:
	make clean && make fullbuild

run:
	./build/main

check:
	./linters/run.sh

test:
	./build/tests/test