#!/bin/sh

cd /home/divan/myos

echo "Clean Start"

./clean.sh

echo "Clean Stop"

echo "Headers Start"

./headers.sh

echo "Headers Stop"

echo "iso Start"

./iso.sh

echo "iso Stop"

echo "qemu Start"

./qemu.sh

echo "qemu Stop"
