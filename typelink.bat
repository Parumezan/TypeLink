@echo off

if not exist build (
    mkdir build
)

set cores=%NUMBER_OF_PROCESSORS%

cmake -S . -B build
cmake --build build -j %cores%