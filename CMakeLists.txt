cmake_minimum_required(VERSION 3.20.2)
project(Link)

find_package(OpenSSL 3 REQUIRED)

# Versioning
set(LINK_VERSION 2)
set(LINK_VERSION_MINOR 0)
set(LINK_VERSION_PATCH 0)
set(LINK_VERSION_EXTRA "")

set(VERSION ${LINK_VERSION}.${LINK_VERSION_MINOR}.${LINK_VERSION_PATCH})

if(CMAKE_CXX_COMPILER_VERSION VERSION_LESS_EQUAL 8.0)
	message(STATUS "GCC version is <= 8.0. -DFS_EXPERIMENTAL")
endif()

# Library
file(GLOB_RECURSE SOURCES Source/*.cpp)
file(GLOB_RECURSE INCLUDES Include/*)

include_directories(Include)

add_library(link SHARED ${SOURCES})
set_target_properties(link PROPERTIES
    PUBLIC_HEADER ${INCLUDES})

set_target_properties(link PROPERTIES
		VERSION ${VERSION}
		SOVERSION ${LINK_VERSION})

target_compile_features(link PUBLIC cxx_std_17)
set (CMAKE_CXX_FLAGS "-std=c++17")

target_include_directories(link PUBLIC Include)
target_link_libraries(link PUBLIC OpenSSL::SSL z)

if(CMAKE_CXX_COMPILER_VERSION VERSION_LESS_EQUAL 8.0)
	target_link_libraries(link PUBLIC stdc++fs)
	set (CMAKE_CXX_FLAGS "-DFS_EXPERIMENTAL")
endif()

# install
install(TARGETS link
    LIBRARY DESTINATION ${CMAKE_INSTALL_PREFIX}/lib
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_PREFIX}/include)

# Test
file(GLOB_RECURSE TEST_SOURCES Test/*.cpp)

if (BUILD_LINKTEST)
	add_executable(linktest ${TEST_SOURCES})
	target_link_libraries(linktest PRIVATE link)

	enable_testing()

	add_test(NAME test COMMAND $<TARGET_FILE:linktest>)
endif()
