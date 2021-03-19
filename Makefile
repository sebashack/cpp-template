DIST_DIR:=${CURDIR}/dist
BIN_NAME:=main
INCLUDES_DIR:=${CURDIR}/include
SOURCE_DIR:=${CURDIR}/src

SOURCES:=${SOURCE_DIR}/Person.cpp ${SOURCE_DIR}/Bar.cpp ${SOURCE_DIR}/Main.cpp
OBJECTS:=$(patsubst %.cpp,%.o,$(SOURCES))

${OBJECTS}:
	rm -rf ${DIST_DIR}
	mkdir -p ${DIST_DIR}
	cd ${SOURCE_DIR} && g++ -std=c++17 -I${INCLUDES_DIR} -c ${SOURCES}

.PHONY: build
build: ${OBJECTS}
	cd ${SOURCE_DIR} && g++ -std=c++17 -I${INCLUDES_DIR} ${OBJECTS} -o ${BIN_NAME}
	cd ${SOURCE_DIR} && mv *.o ${BIN_NAME} ${DIST_DIR}

.PHONY: restyle
restyle:
	astyle --mode=c -n --style=allman ${CURDIR}/src/*.cpp
	astyle --mode=c -n --style=allman ${CURDIR}/include/*.h

.PHONY: clean
clean:
	rm -rf ${DIST_DIR}
	rm -rf ${SOURCE_DIR}/*.o
