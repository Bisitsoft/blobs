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

# 之前一直提示：`make: Circular example <- example dependency dropped.`
# 直到我发现我把编译依赖和最终二进制文件都叫做`example`，然后就把二进制改名为`cslprgbar`了。

# Windows上example一致编译不通过，就干脆只支持Linux了。
# 静态库也有点问题，先注释掉。
