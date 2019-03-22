# myos
My operating system project.

This is based on the tutorial on osdev.org, https://wiki.osdev.org/Meaty_Skeleton

Please note that you will have to make a cross compiler, in order to compile the OS. The reason that the cross-compiler was not added to the repo, is because some files are over 100mb.

Follow the below steps to set up a cross-compiler on Linux.

********************************
***How to make cross compiler***
********************************

default for $PATH is:/usr/lib/lightdm/lightdm:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games

Make sure the below packages are installed (Debian).

build-essential
build-essential
bison
flex
libgmp3-dev
libmpc-dev
libmpfr-dev
texinfo
libcloog-isl-dev
libisl-dev

Download the source code for Binutils and GCC.

https://ftp.gnu.org/gnu/binutils/
https://ftp.gnu.org/gnu/gcc/

****cross compiler****

1. Env variables

export PREFIX="$HOME/cross"
export TARGET=i686-elf
export PATH="$PREFIX/bin:$PATH"

2. Make binutils

cd $HOME/src
mkdir build-binutils
cd build-binutils
../binutils-2.31/configure --target=$TARGET --prefix="$PREFIX" --with-sysroot --disable-nls --disable-werror
make
make install

3. Make gcc

cd $HOME/src
 
mkdir build-gcc
cd build-gcc
../gcc-7.3.0/configure --target=$TARGET --prefix="$PREFIX" --disable-nls --enable-languages=c,c++ --without-headers
make all-gcc
make all-target-libgcc
make install-gcc
make install-target-libgcc

4. Test

$HOME/cross/bin/$TARGET-gcc --version


