## Executing order
1. Run the `TxtHighBayWarehouseRun.cpp` file
    - Get the headers needed
    - check if needed to use the mqtt

2. Then follow order whichever needed


### Cmd's:
```
g++ TxtHighBayWarehouseRun.cpp TxtHighBayWarehouseStorage.cpp
./a.out
```

### with clang
```
clang++-14 -fno-discard-value-names -flegacy-pass-manager -g -Xclang -load -Xclang /home/raihan/LogPasses-new/FAVCIGVT\*/instrument.so TxtHighBayWarehouseRun.cpp TxtHighBayWarehouseStorage.cpp
```

## Json data changed
```
g++ changeData.cpp -I ~/vcpkg/installed/x64-linux/include/
```
