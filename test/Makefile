CC = g++
RM = rm

CDEBUG = -g
LDEBUG = -g

INC_DIR = ../include
OBJ_DIR = .
LIB_DIR = ../lib
BIN_DIR = ../bin

all: $(BIN_DIR)/CZ80Test

SRC = \
CZ80Test.cpp \

OBJS = $(patsubst %.cpp,$(OBJ_DIR)/%.o,$(SRC))

LIBS = -lCZ80 -lCArgs -lCFile -lCOS -lCStrUtil

CPPFLAGS = \
-std=c++11 \
-I$(INC_DIR) \
-I../../CZ80/include \
-I../../CArgs/include \
-I../../CFile/include \
-I../../COS/include \
-I../../CStrUtil/include \
-I../../CUtil/include \
-I.

LFLAGS = \
-L$(LIB_DIR) \
-L../../CZ80/lib \
-L../../CArgs/lib \
-L../../CFile/lib \
-L../../COS/lib \
-L../../CStrUtil/lib \

clean:
	$(RM) -f $(OBJ_DIR)/*.o
	$(RM) -f $(BIN_DIR)/CZ80Test

.SUFFIXES: .cpp

.cpp.o:
	$(CC) -c $< -o $(OBJ_DIR)/$*.o $(CPPFLAGS)

$(BIN_DIR)/CZ80Test: $(OBJS) $(LIB_DIR)/libCZ80.a
	$(CC) $(LDEBUG) -o $(BIN_DIR)/CZ80Test $(OBJS) $(LFLAGS) $(LIBS)
