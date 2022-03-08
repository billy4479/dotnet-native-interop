#!/bin/sh

set -e

cmake -S native -B build -G Ninja -DCMAKE_BUILD_TYPE=Release
cmake --build build
dotnet publish --use-current-runtime -p:PublishSingleFile=true --sc -c Release
cp ./build/libnative.so ./bin/Release/net6.0/arch-x64/publish/