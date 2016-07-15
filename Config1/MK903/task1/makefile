.SILENT:
.SUFFIXES: .o .cpp

SRC= task1.cpp globals.cpp uclasses.cpp uobjects.cpp shu903.cpp 

CXX="C:\wingw\bin\mingw32-g++.exe"

TARGET=task1
TARGETEXT=.exe
LOGFILE=Compile.log
LINK_FLAGS=
CXXFLAGS=-I"c:/Progs/Sintar2007/System/lib32"

OBJ=$(SRC:.cpp=.o)

all: prepare $(TARGET)

prepare:
	rm -f $(LOGFILE)

$(TARGET): $(OBJ)
	$(CXX) -o $(TARGET) $(OBJ) $(LINK_FLAGS)

clean:
	rm -f $(OBJ)
	rm -f $(DEP)
	rm -f $(LOGFILE)

remove_all: clean
	rm -f $(TARGET)$(TARGETEXT)

rebuild: remove_all $(TARGET)

.cpp.o:
	$(CXX) -Wno-deprecated -c $(CXXFLAGS) -o$@ $< 2>> $(LOGFILE)
