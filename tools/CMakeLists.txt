project( waves-sign-tools )

set(CMAKE_CXX_FLAGS ${CMAKE_C_FLAGS} "-msse2 -m64 -fPIC")

add_definitions(-Wall -O0 -Wextra -Wno-format -std=c++11)

add_executable( waves_tool1 tool1.cpp argvparser.cpp )
target_link_libraries(waves_tool1 pthread waves_c)
install(TARGETS waves_tool1 DESTINATION bin)
