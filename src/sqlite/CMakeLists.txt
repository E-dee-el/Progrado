add_library(sqlite3 sqlite3.c)
target_link_libraries (sqlite3 LINK_PUBLIC dl pthread)
set(CMAKE_CXX_FLAGS " -pthread -ldl " )
