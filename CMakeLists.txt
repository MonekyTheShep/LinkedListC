cmake_minimum_required(VERSION 3.15)

project(LinkedList LANGUAGES C)

# Explicitly set the include directory
set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Use CONFIGURE_DEPENDS to automatically reconfigure when files are added/removed
file(GLOB SRC_FILES CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/src/*.c)

add_executable(${PROJECT_NAME} ${SRC_FILES})

# Add include directory with absolute path
target_include_directories(${PROJECT_NAME} PRIVATE ${INCLUDE_DIR})

target_compile_options(${PROJECT_NAME} PRIVATE
    -Wall
    -Wextra
    -Wpedantic
)