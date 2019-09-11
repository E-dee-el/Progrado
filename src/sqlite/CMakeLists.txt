add_library(sqlite3 libsqlite3.a)
target_link_libraries (sqlite3 LINK_PUBLIC dl pthread)
set(CMAKE_CXX_FLAGS " -pthread -ldl " )
