# Specify the minimum version required for CMake
cmake_minimum_required(VERSION 3.10)

# Define the project name
project(multithreading)
find_package(CURL REQUIRED)

# Add an executable target
add_executable(target_singlethreaded  src/Single_threaded.cpp)
add_executable(target_multithread src/Basic_Multithreading_Code.cpp)
add_executable(target_delay  src/Delays_to_thread.cpp )
add_executable(atomic_output  src/atomic_operation.cpp )


target_link_libraries(atomic_output pthread)
target_link_libraries(target_multithread  pthread)
target_link_libraries(target_delay  pthread)


