#!/usr/bin/env bash
echo "Total lines of C code:"
find . -name "*.c" | xargs wc -l
