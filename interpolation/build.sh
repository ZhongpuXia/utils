#!/bin/bash

build() {
    if [ ! -e "./build" ]; then
        echo "mkdir build"
        mkdir build
    fi
    cd build
    echo "build path: $(pwd)"
    cmake ../src
    make
    cd -
}

clean() {
    rm -rf build
    rm ./results.txt
}

unittest() {
    for f in ./build/*_test
    do
        echo "exec test: $f"
        $f
    done
}

run() {
    ./build/main
    python script/plot.py ./results.txt
}


case $1 in
clean)
    clean
    ;;
build)
    build
    ;;
unittest)
    unittest
    ;;
run)
    run
    ;;
help)
    echo "$0 [build|clean|unittest|run]"
    ;;
*)
    build
    ;;
esac


