#!/usr/bin/env python3
import os, sys, re
from typing import List

def CPP(filename: str, fileNameWithoutExt: str,myListDir: List) -> None:
    # filename == the file name with extention
    if(fileNameWithoutExt in myListDir):
        print(f"[*] {fileNameWithoutExt} is in current directory --> remove")
        os.system(f"rm {fileNameWithoutExt}")
    os.system(f"g++ {filename} -o bin/{fileNameWithoutExt}")
    print(f"[*] {fileNameWithoutExt} created!")

def main() -> None:
    # list all files of the current directory.
    myListDir: List = os.listdir()

    # if there is no file named "bin", then create a it.
    if("bin" not in myListDir):
        print("[*] bin directory not detected --> create")
        cwd: str = os.getcwd() + "/bin"
        os.mkdir(cwd)
    
    try:
        myFile: str = sys.argv[1]
    except IndexError:
        raise SystemExit(f"Usage: {sys.argv[0]} <file>")

    # split the file into 2 elements which are the file name (idx 0) the extention (idx 1)
    splitTheFile = re.split("\.",myFile)
    
    if(splitTheFile[1]=="cpp"):
        CPP(myFile,splitTheFile[0],myListDir)

if __name__ == "__main__":
    main()