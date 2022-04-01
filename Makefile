fullbuild:
	cmake -B build; cmake --build build

clean:
	rm -rf build

build:
	cmake --build build

rebuild:
	make clean && make fullbuild

run:	./build/main
	./build/main $(n)

check:
	./linters/run.sh

test:
	./build/tests/test

search:
	find ./ -type f -iname '*.gcno'

gcov:
	gcov -abcfu build/string_io/CMakeFiles/string_io.dir/string_io.c.gcno

gcovr:
	rm -rf gcovr_report; mkdir gcovr_report; gcovr -r . --html --html-details -o gcovr_report/coverage.html