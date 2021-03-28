#!/bin/bash
cd "$(dirname "$0")"
fusermount -u ./example/mountdir
make && ./src/bbfs -s example/rootdir/ example/mountdir/
