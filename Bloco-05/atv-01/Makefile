CC=g++
CFLAGS=-g -Wall
TARGET=vpl_execution

BUILD_DIR=./build
INCLUDE_DIR=./include
SRC_DIR=./src

${TARGET}: ${BUILD_DIR}/Funcionario.o ${BUILD_DIR}/Pessoa.o ${BUILD_DIR}/Professor.o ${BUILD_DIR}/main.o
	${CC} ${CFLAGS} -o $@ $^

${BUILD_DIR}/Funcionario.o: ${SRC_DIR}/entidades/Funcionario.cpp ${INCLUDE_DIR}/Funcionario.hpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/entidades/Funcionario.cpp -o ${BUILD_DIR}/Funcionario.o

${BUILD_DIR}/Pessoa.o: ${SRC_DIR}/entidades/Pessoa.cpp ${INCLUDE_DIR}/Pessoa.hpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/entidades/Pessoa.cpp -o ${BUILD_DIR}/Pessoa.o

${BUILD_DIR}/Professor.o: ${SRC_DIR}/entidades/Professor.cpp ${INCLUDE_DIR}/Professor.hpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/entidades/Professor.cpp -o ${BUILD_DIR}/Professor.o

${BUILD_DIR}/main.o: ${SRC_DIR}/main.cpp ${INCLUDE_DIR}/Funcionario.hpp ${INCLUDE_DIR}/Professor.hpp ${INCLUDE_DIR}/Pessoa.hpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/main.cpp -o ${BUILD_DIR}/main.o