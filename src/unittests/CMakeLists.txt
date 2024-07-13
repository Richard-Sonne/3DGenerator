include_directories(${PROJECT_SOURCE_DIR})

file(GLOB unittests ${CMAKE_CURRENT_SOURCE_DIR}/*cpp)

foreach(unittest ${unittests})
    string(REGEX MATCH "[^/]+$" SRC ${unittest})
    string(REPLACE ".cpp" "" BIN ${SRC})
    add_executable(${BIN} ${SRC})
endforeach()
