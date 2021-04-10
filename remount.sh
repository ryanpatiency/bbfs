#!/bin/bash
cd "$(dirname "$0")"
mnt='./example/mountdir/'
root='./example/rootdir/'
fusermount -u $mnt
make && ./src/bbfs -s $root $mnt
