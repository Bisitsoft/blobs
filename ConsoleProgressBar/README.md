# ConsoleProgressBar
A pure console progress bar C Library.

# Compile

Requirement:
* `gcc`
* `make` or `mingw32-make`

# Compile Library

Execute `make shared-library` to get `libcslprgbar.so`.

Execute `make static-library` to get `libcslprgbar.a`.

**Notice: C header file named `ConsoleProgressBar.h`.**

# Compile Example Program

Execute `make example-linux` to get `cslprgbar-lnx` on `Linux`.

**Notice: Becuase I don't know how to link shared library on `Windows`, `make example-windows` doesn't work. but it donesn't matter to compile `libcslprgbar` on `Windows`.**
