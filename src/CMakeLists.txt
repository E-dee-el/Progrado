set(sources User.cpp
	db/Course.cpp
	db/DBConnector.cpp
	ui/Ui.cpp
	ui/login.cpp
	ui/init.cpp
	ui/add_course.cpp
	ui/create_account.cpp
	ui/delete_acct.cpp
	ui/modify_course.cpp
	ui/view_course.cpp
	ui/home.cpp
	ui/remove_course.cpp
	ui/view_user_details.cpp
	ui/search_course.cpp
	ui/retrieve_user_details.cpp
	ui/modify_user_details.cpp
	)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

include_directories(${CMAKE_SOURCE_DIR}/include)	

add_subdirectory(sqlite)

add_library(progrado_lib ${sources})	

target_link_libraries(progrado_lib sqlite3)	
	
	
