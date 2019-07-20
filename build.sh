#!/bin/bash
clear
mkdir -p build
cd build
cmake ..
make
cd ..
./build/run_test
