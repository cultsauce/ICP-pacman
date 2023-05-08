# Author: Jan Kalenda
# Used to build the project, create documentation and pack the project

.PHONY: all clean pacman doxygen run

all: pacman

default: pacman

pacman:
	mkdir -p build
	cd build && cmake ..
	cmake --build build --config Release
	cp build/pacman .

run: pacman
	./pacman

doxygen:
	cd src && doxygen Doxyfile

clean:
	rm -rf build
	rm -f pacman
	rm -rf doc

pack: clean
	mkdir doc
	zip -r xkubin27-xkalen07.zip src/ Resources/ doc/ Makefile CMakeLists.txt README.md
