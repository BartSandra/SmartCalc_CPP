.PHONY : all test gcov_report install open uninstall dvi dist clean rebuild leaks style gost

CFLAGS=-Wall -Werror -Wextra
CPPFLAGS=-lstdc++ -std=c++17
LIBS=-lgtest -lgcov

all: test gcov_report install dvi

test: clean
	@gcc -Wall -Wextra -Werror -std=c++17 test.cc model/model.cc model/credit_calc.cc model/deposit_calc.cc controller/controller.cc -lgtest -lgtest_main --coverage $(CPPFLAGS) -o test -lstdc++
	@./test

gcov_report: test
	@lcov --ignore-errors mismatch -t "./gcov" -o report.info -c -d .
	@genhtml --ignore-errors mismatch -o report report.info
	@open ./report/index.html

install: uninstall
	mkdir -p build
	cd view && qmake && make && make clean && rm Makefile && cd ../ && mv view/calc.app build
	open build/calc.app

open:
	open build/calc.app

uninstall:
	rm -rf build*

dvi:
	open readme.md 

dist: install
	rm -rf SmartCalc_v2.0/
	mkdir SmartCalc_v2.0/
	mkdir SmartCalc_v2.0/src
	cp -r ./build/calc.app SmartCalc_v2.0/src/
	tar cvzf SmartCalc_v2.0.tgz SmartCalc_v2.0/
	rm -rf SmartCalc_v2.0/

clean:
	@rm -rf *.gcda
	@rm -rf *.gcno
	@rm -rf *.info
	@rm -rf test
	@rm -rf report
	@rm -rf gcov_report
	@rm -rf *.dSYM
	@rm -rf *.o
	
rebuild:
	@make clean
	@make all

leaks:
	leaks -atExit -- ./test

style:
	find . -name "*.h" -o -name "*.cc" -o -name "*.tpp" | xargs clang-format --style=google -n

gost:
	find . -name "*.h" -o -name "*.cc" -o -name "*.tpp" | xargs clang-format --style=google -i