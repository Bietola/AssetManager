# initialize project
cmake_minimum_required(VERSION 3.9.0)
project(Proj)

# compiler flags
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# export compile commands for YCM
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# load packages
set(CMAKE_LIBRARY_PATH /usr/local/lib/SFML)
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake_modules)
find_package(SFML REQUIRED COMPONENTS graphics window system)

# headers directories
include_directories(${SFML_INCLUDE_DIR})

# project directories
include_directories(headers)

# project sources
file(GLOB SRC src/**/**/*.cpp src/**/*.cpp src/*.cpp)

# create exectuables
add_executable(Proj ${SRC}) 

# link libraries
target_link_libraries(Proj ${SFML_LIBRARIES} ${SFML_DPENDENCIES})

# copy resources from resource directories into build directory
set(source "${CMAKE_SOURCE_DIR}/assets")
set(destination "${CMAKE_CURRENT_BINARY_DIR}/assets")
add_custom_command(
    TARGET Proj POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E create_symlink ${source} ${destination} 
    DEPENDS ${destination}
	COMMENT "Created symbolic link to assets folder at ${source} to ${destination}"
)

# copy compile commands into root directory for YCM
set(source "${CMAKE_CURRENT_BINARY_DIR}/compile_commands.json")
set(destination "${CMAKE_SOURCE_DIR}/")
add_custom_command(
	TARGET Proj POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy ${source} ${destination}
	DEPENDS ${destination}
	COMMENT "Copied compilation database from ${source} to ${destination}"
)
