project(overseer C CXX)
cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(INCLUDES
${INCLUDE}
include/
)

set(HEADERS
include/overseer/Overseer.hpp
)

set(SOURCES
${SOURCES}
src/main.cpp
src/Overseer.cpp
)

source_group("Header files" FILES ${HEADERS})
source_group("Source files" FILES ${SOURCES})

add_executable(overseer ${SOURCES} ${HEADERS})
target_include_directories(overseer PRIVATE ${INCLUDES})

if (UNIX)
    target_link_libraries(main stdc++fs)
endif(UNIX)