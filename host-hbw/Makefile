CXXFLAGS=-fno-discard-value-names -flegacy-pass-manager -g -Xclang -load -Xclang /home/raihan/LogPasses-new/FAVCIGVT\*/instrument.so -pthread -lpaho-mqttpp3  -lpaho-mqtt3c -lpaho-mqtt3a -lmosquitto 
#CXXFLAGS=-fno-discard-value-names -flegacy-pass-manager -g -xclang -load -xclang  -lpaho-mqttpp3  -lpaho-mqtt3c -lpaho-mqtt3a -lmosquitto
INCLUDE=-I ~/vcpkg/installed/x64-linux/include/
CLANG=clang++-14

CPP_FILES=TxtHighBayWarehouseRun.cpp TxtHighBayWarehouseStorage.cpp
#EXE=hbw-exe
#EXE=client_sub
EXE=TxtFactoryHBW-hostExe

OBJECTS=$(EXE)

all: $(EXE)

$(EXE): $(CPP_FILES)
	$(CLANG) $(CXXFLAGS) $(INCLUDE) $^ -o $@

.PHONY:clean
clean:
	rm $(OBJECTS)


#### with clang
#```
#clang++-14 -fno-discard-value-names -flegacy-pass-manager -g -Xclang -load -Xclang /home/raihan/LogPasses-new/FAVCIGVT\*/instrument.so TxtHighBayWarehouseRun.cpp TxtHighBayWarehouseStorage.cpp
#```
