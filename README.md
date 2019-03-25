# myos
My operating system project. I did this on Ubuntu 18.04.2 LTS.

This is based on the tutorial on osdev.org, https://wiki.osdev.org/Meaty_Skeleton

Please note that you will have to make a cross compiler, in order to compile the OS. The reason that the cross-compiler was not added to the repo, is because some files are over 100mb.

Follow the below steps to set up a cross-compiler on Linux.

********************************
***How to make cross compiler***
********************************

Default for $PATH is:/usr/lib/lightdm/lightdm:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games

Make sure the below packages are installed (Debian/Ubuntu)

build-essential
bison
flex
libgmp3-dev
libmpc-dev
libmpfr-dev
texinfo
libcloog-isl-dev
libisl-dev

Download the source code for Binutils and GCC. I downloaded Binutils 2.30 and GCC 7.3.0. The reason is because they have a similar release date. Make a folder named "src" and place both in there. 

https://ftp.gnu.org/gnu/binutils/
https://ftp.gnu.org/gnu/gcc/

Note, I had to do the below to be able to compile Binutils and GCC:
Double check that I've installed ALL the above packages.
sudo dpkg-reconfigure libdvd-pkg
sudo apt-get update
sudo apt-get upgrade

****cross compiler****

1. Env variables

export PREFIX="$HOME/cross"
export TARGET=i686-elf
export PATH="$PREFIX/bin:$PATH"

2. Make binutils

cd $HOME/src
mkdir build-binutils
cd build-binutils
../binutils-x.xx/configure --target=$TARGET --prefix="$PREFIX" --with-sysroot --disable-nls
make
sudo make install

3. Make gcc

cd $HOME/src
 
mkdir build-gcc
cd build-gcc
../gcc-x.x.x/configure --target=$TARGET --prefix="$PREFIX" --disable-nls --enable-languages=c,c++ --without-headers
make all-gcc
make all-target-libgcc
make install-gcc
make install-target-libgcc

4. Test

$HOME/cross/bin/$TARGET-gcc --version


