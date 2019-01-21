CC = g++
AR = ar
RM = rm

CDEBUG = -g
LDEBUG = -g

INC_DIR = ../include
OBJ_DIR = ../obj
LIB_DIR = ../lib

all: $(LIB_DIR)/libCZ80.a

SRC = \
CZ80Assemble.cpp \
CZ80.cpp \
CZ80DebugData.cpp \
CZ80Disassemble.cpp \
CZ80Execute.cpp \
CZ80Fn.cpp \
CZ80LabelData.cpp \
CZ80Load.cpp \
CZ80MemData.cpp \
CZ80Op.cpp \
CZ80OpData.cpp \
CZ80Rst.cpp \
CZ80Snapshot.cpp \
CZ80SpeedData.cpp \

OBJS = $(patsubst %.cpp,$(OBJ_DIR)/%.o,$(SRC))

CPPFLAGS = \
-std=c++14 \
-I$(INC_DIR) \
-I../../CFile/include \
-I../../CStrUtil/include \
-I../../COS/include \
-I../../CUtil/include \
-I.

clean:
	$(RM) -f $(OBJ_DIR)/*.o
	$(RM) -f $(LIB_DIR)/libCZ80.a

.SUFFIXES: .cpp

$(OBJS): $(OBJ_DIR)/%.o: %.cpp
	$(CC) -c $< -o $(OBJ_DIR)/$*.o $(CPPFLAGS)

$(LIB_DIR)/libCZ80.a: $(OBJS)
	$(AR) crv $(LIB_DIR)/libCZ80.a $(OBJ_DIR)/*.o
