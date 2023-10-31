CXXFLAGS=-fno-discard-value-names -flegacy-pass-manager -g -Xclang -load -Xclang /home/raihan/LogPasses-new/FAVCIGVT\*/instrument.so -pthread -lpaho-mqttpp3  -lpaho-mqtt3c -lpaho-mqtt3a -lmosquitto
#CXXFLAGS=-fno-discard-value-names -flegacy-pass-manager -g -xclang -load -xclang  -lpaho-mqttpp3  -lpaho-mqtt3c -lpaho-mqtt3a -lmosquitto
CLANG=clang++-14

CPP_FILES=TxtHighBayWarehouseRun.cpp TxtHighBayWarehouseStorage.cpp
#EXE=hbw-exe
EXE=client_sub

OBJECTS=$(EXE)

all: $(EXE)

$(EXE): $(CPP_FILES)
	$(CLANG) $(CXXFLAGS) $^ -o $@

.PHONY:clean
clean:
	rm $(OBJECTS)


#### with clang
#```
#clang++-14 -fno-discard-value-names -flegacy-pass-manager -g -Xclang -load -Xclang /home/raihan/LogPasses-new/FAVCIGVT\*/instrument.so TxtHighBayWarehouseRun.cpp TxtHighBayWarehouseStorage.cpp
#```
