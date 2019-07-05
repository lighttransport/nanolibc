#!/bin/bash

rm -rf build

CC=clang-8 meson build -Db_sanitize=address -Db_lundef=false
