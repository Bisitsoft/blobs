# Makefile of Console Progress Bar
# Author: Orange233 (https://github.com/Orange23333)

# >>> Compiler >>>
#   C Compiler:
CC=gcc

#   C Compiler Flags:
flags=\
	-finput-charset=UTF-8\
	-std=gnu17\
#	-std=c17\
#	-v\
#	-Wfatal-errors \
#	-Wextra \
#	-Wshadow \
#	-Wsign-compare \
#	-Wundef \
#	-Wwrite-strings \
#	-Wredundant-decls \
#	-Wdisabled-optimization \
#	-Wdouble-promotion \
#	-Wmissing-declarations \
##	-Wall
#   !!! v remain 2 empty line below v !!!


#   !!! ^ remain 2 empty line above ^ !!!
# <<< Compiler <<<

# >>> Target And Object Files >>>
all-files=$(dist-files) $(cache-files)
dist-files=$(shared-target) $(example-target) #$(static-target)
cache-files=$(shared-obj) $(example-obj) #$(static-obj)

export-include-files=ConsoleProgressBar.h

example-target=cslprgbar
example-obj=ConsoleProgressBar.Example.o

shared-target=libcslprgbar.so
shared-obj=ConsoleProgressBar.shared.o
#static-target=libcslprgbar.a
#static-obj=ConsoleProgressBar.static.o
# <<< Target And Object Files <<<

# >>> Makes >>>
example: $(example-target)
shared-library: $(shared-target)
#static-library: $(static-target)
# <<< Makes <<<

# >>> Dependencies >>>
#	Example:
cslprgbar: $(example-obj) $(shared-target)
	$(CC) $(flags) -L. -lcslprgbar -o $@ $^
ConsoleProgressBar.Example.o: ConsoleProgressBar.Example.c
	$(CC) $(flags) -c $< -o $@

#   Libraries:
libcslprgbar.so: $(shared-obj)
	$(CC) $(flags) -shared -fPIC -o $@ $^
#libcslprgbar.a: $(static-obj)
#	ar -rcs $@ $^
ConsoleProgressBar.shared.o: ConsoleProgressBar.c
	$(CC) $(flags) -fPIC -c $< -o $@
#ConsoleProgressBar.static.o: ConsoleProgressBar.c
#	$(CC) $(flags) -c $< -o $@
# <<< Dependencies <<<

# >>> Install >>>
lib-dir=/usr/lib
include-dir=/usr/include

install-shared-libcslprgbar:
	make shared-library
	cp $(shared-target) $(lib-dir)/
	cp $(export-include-files) $(include-dir)
uninstall-shared-libcslprgbar:
	rm $(lib-dir)/$(shared-target)
	rm $(include-dir)/$(export-include-files)

#install-static-libcslprgbar:
#	make static-library
#	cp $(static-target) $(lib-dir)/
#	cp $(export-include-files) $(include-dir)
#uninstall-static-libcslprgbar:
#	rm $(lib-dir)/$(static-target)
#	rm $(include-dir)/$(export-include-files)
# <<< Install <<<

# >>> Clean >>>
clean:
	rm -f $(all-files)
clean-cache:
	rm -f $(cache-files)
clean-dist:
	rm -f $(dist-files)
# <<< Clean <<<

# ?????????????????????`make: Circular example <- example dependency dropped.`
# ??????????????????????????????????????????????????????????????????`example`?????????????????????????????????`cslprgbar`??????

# Windows???example??????????????????????????????????????????Linux??????
# ??????????????????????????????????????????
