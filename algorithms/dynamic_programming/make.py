#!/usr/bin/env python3
import os, sys, re

try:
    myFile = sys.argv[1]
except IndexError:
    raise SystemExit(f"Usage: {sys.argv[0]} <file>")

rm_extention = re.split(".cpp", myFile)
os.system(f"g++ {myFile} -o bin/{rm_extention[0]}")

# x = "hello.cpp"
# print(x)

# rm_ext = re.split(".cpp",x)
# print(rm_ext[0], type(rm_ext[0]))
