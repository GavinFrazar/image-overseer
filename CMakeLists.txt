project(overseer C CXX)
cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(OpenCV REQUIRED)

set(INCLUDES
${INCLUDE}
include/
${OpenCV_INCLUDE_DIRS}
)

set(LIBRARIES
${LIBRARIES}
${OpenCV_LIBS}
)

set(HEADERS
include/overseer/File.hpp
include/overseer/Hashtable.hpp
include/overseer/Manager.hpp
)

set(SOURCES
${SOURCES}
src/main.cpp
src/Manager.cpp
src/Hashtable.cpp
)

source_group("Header files" FILES ${HEADERS})
source_group("Source files" FILES ${SOURCES})

add_executable(overseer ${SOURCES} ${HEADERS})
target_include_directories(overseer PRIVATE ${INCLUDES})
target_link_libraries(overseer PRIVATE ${LIBRARIES})

if (UNIX)
    target_link_libraries(main stdc++fs)
endif(UNIX)