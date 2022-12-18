# Makefile of Console Progress Bar
# Author: Orange233 (https://github.com/Orange23333)

# >>> Compiler >>>
#   C Compiler:
CC=gcc

#   C Compiler Flags:
flags=\
	-finput-charset=UTF-8\
	-std=c17\
#	-v\
#	-g\
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
all-target=$(example-target) $(shared-target)
dist-files=$(shared-target) $(example-target)
cache-files=$(example-obj) $(shared-obj)

example-target=cslprgbar
example-obj=ConsoleProgressBar.Example.o

shared-target=libcslprgbar.so
shared-obj=$(lib-obj)

lib-obj=ConsoleProgressBar.o
# <<< Target And Object Files <<<

# >>> Makes >>>
all: $(all-target)

example: $(example-target)
shared-library: $(shared-target)
# <<< Makes <<<

# >>> Dependencies >>>
#	Example Targets:
cslprgbar: $(shared-target) $(example-obj)
#	export LD_LIBRARY_PATH=$(PWD):$(LD_LIBRARY_PATH)
	make install-shared-cslprgbar
	$(CC) $(flags) -L/usr/lib/ -lcslprgbar -o $@ $(example-obj)
ConsoleProgressBar.Example.o: ConsoleProgressBar.Example.c
	$(CC) $(flags) -c $< -o $@

#   Libraries Targets:
libcslprgbar.so: $(shared-obj)
	$(CC) $(flags) -shared -fPIC -o $@ $^

#   Libraries Objects:
ConsoleProgressBar.o: ConsoleProgressBar.c
	$(CC) $(flags) -c $< -o $@
# <<< Dependencies <<<

# >>> Install >>>
lib-dir=/usr/lib

install-shared-cslprgbar:
	make shared-library
	mkdir -p $(lib-dir)
	cp $(shared-target) $(lib-dir)/

uninstall-shared-cslprgbar:
	rm $(lib-dir)/$(shared-target)
# <<< Install <<<

# >>> Clean >>>
clean:
	rm -f $(cache-files)
clean-dist:
	rm -f $(dist-files)
# <<< Clean <<<

# 之前一直提示：`make: Circular example <- example dependency dropped.`
# 直到我发现我把编译依赖和最终二进制文件都叫做`example`，然后就把二进制改名为`cslprgbar`了。
