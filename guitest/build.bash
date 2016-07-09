#!/bin/bash

echo "cleaning build.."

cd build
rm -r *
cmake ../
make
