project( waves-sign-tools )

set(CMAKE_CXX_FLAGS ${CMAKE_C_FLAGS} "-msse2 -m64 -fPIC")

add_definitions(-Wall -O0 -Werror -Wextra -Wno-format -fPIC)

add_executable( waves_tool1 tool1.cpp )
target_link_libraries(waves_tool1 pthread waves_c)
install(TARGETS waves_tool1 DESTINATION bin)
