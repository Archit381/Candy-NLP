cmake_minimum_required(VERSION 3.8)

# Adding Source to this project's executables'

file(GLOB SRCS "src/*.cpp")
file(GLOB_RECURSE HDRS "include/*.h")

add_library(Candy-NLP
	${SRCS}
	${HDRS}
)

target_include_directories(Candy-NLP PUBLIC "${CMAKE_SOURCE_DIR}/Foundation/include/Candy-NLP")

if(CMAKE_VERSION VERSION_GREATER 3.12)
	set_property(TARGET Candy-NLP PROPERTY CXX_STANDARD 20)
endif()

add_subdirectory(tests)