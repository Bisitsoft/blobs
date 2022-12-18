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
all-files=$(dist-files) $(cache-files)
dist-files=$(shared-target) $(example-win-target) $(example-lnx-target)
cache-files=$(example-win-obj) $(example-lnx-obj) $(shared-obj)

example-win-target=cslprgbar-win
example-win-obj=ConsoleProgressBar.Example.win.o
example-lnx-target=cslprgbar-lnx
example-lnx-obj=ConsoleProgressBar.Example.lnx.o

shared-target=libcslprgbar.so
shared-obj=$(lib-obj)

lib-obj=ConsoleProgressBar.o
# <<< Target And Object Files <<<

# >>> Makes >>>
example-windows: cslprgbar-win
example-linux: cslprgbar-lnx
shared-library: $(shared-target)
# <<< Makes <<<

# >>> Dependencies >>>
#	Example:
cslprgbar-win: $(example-win-obj)
	make install-shared-libcslprgbar
	$(CC) $(flags) -L/usr/lib/ -lcslprgbar -o $@ $(example-win-obj)
cslprgbar-lnx: $(example-lnx-obj)
	make install-shared-libcslprgbar
	$(CC) $(flags) -L/usr/lib/ -lcslprgbar -o $@ $(example-lnx-obj)
ConsoleProgressBar.Example.win.o: ConsoleProgressBar.Example.c
	$(CC) $(flags) -D__WINDOWS__ -c $< -o $@
ConsoleProgressBar.Example.lnx.o: ConsoleProgressBar.Example.c
	$(CC) $(flags) -D__linux__ -c $< -o $@

#   Libraries:
libcslprgbar.so: $(shared-obj)
	$(CC) $(flags) -shared -fPIC -o $@ $^
ConsoleProgressBar.o: ConsoleProgressBar.c
	$(CC) $(flags) -fPIC -c $< -o $@
# <<< Dependencies <<<

# >>> Install >>>
lib-dir=/usr/lib
include-dir=/usr/include

install-shared-libcslprgbar:
	make shared-library
	cp $(shared-target) $(lib-dir)/
	cp ConsoleProgressBar.h $(include-dir)

uninstall-shared-libcslprgbar:
	rm $(lib-dir)/$(shared-target)
	rm $(include-dir)/ConsoleProgressBar.h
# <<< Install <<<

# >>> Clean >>>
clean:
	rm -f $(all-files)
clean-cache:
	rm -f $(cache-files)
clean-dist:
	rm -f $(dist-files)
# <<< Clean <<<

# 之前一直提示：`make: Circular example <- example dependency dropped.`
# 直到我发现我把编译依赖和最终二进制文件都叫做`example`，然后就把二进制改名为`cslprgbar`了。
