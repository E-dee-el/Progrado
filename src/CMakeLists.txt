set(sources User.cpp
	UserInterface.cpp
	db/Course.cpp
	db/DBConnector.cpp
	ui/AddCourseScreen.cpp
	ui/CreateAccountScreen.cpp
	ui/ListAllCoursesScreen.cpp
	ui/LoginErrorScreen.cpp
	ui/MainMenuScreen.cpp
	ui/RemoveCourseScreen.cpp
	ui/ScheduleSummaryScreen.cpp
	ui/UpdateCourseScreen.cpp
	)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

include_directories(${CMAKE_SOURCE_DIR}/include)	

add_subdirectory(sqlite)

add_library(progrado_lib ${sources})	

target_link_libraries(progrado_lib sqlite3)	
	
	
