check:
	./linters/run.sh

clean:
	rm -rf build

build:
	cmake -B build; cmake --build build

rebuild:
	rm -rf build; cmake -B build; cmake --build build

run:
	./build/main

test:
	./build/tests/test

CI_test:
	build/tests/test

search:
	find ./ -type f -iname '*.gcda'

gcovr:
	rm -rf gcovr_report; mkdir gcovr_report; gcovr -r . --html --html-details -o gcovr_report/coverage.html

lcov:
	lcov -t "build/tests/test" -o coverage.info -c -d build/string_io; genhtml -o lcov_report coverage.info

format:
	clang-format 

message:
	mkdir build && cd build && cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_CXX_FLAGS="-Werror" ..