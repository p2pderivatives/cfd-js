#!/bin/bash

function search_lint() {
    cd $1
    for file in `\find . -maxdepth 1 -name '*.h'`; do
        python $2/tools/cpplint/cpplint.py --quiet $file > /dev/null
    done
    for file in `\find . -maxdepth 1 -name '*.cpp'`; do
        python $2/tools/cpplint/cpplint.py --quiet $file > /dev/null
    done
    cd $2
}


cd `git rev-parse --show-toplevel`
search_lint src ..
