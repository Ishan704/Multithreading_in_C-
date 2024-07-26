
# Specify the minimum version required for CMake
cmake_minimum_required(VERSION 3.10)

# Define the project name
project(mutex)

# Add an executable target

add_executable(output_used program_where_mutex_is_required.cpp)
add_executable(output_mutex_resolved program_where_mutex_is_used.cpp)
add_executable(output_example3 example3.cpp)


target_link_libraries(output_used pthread)
target_link_libraries(output_mutex_resolved pthread)
target_link_libraries(output_example3 pthread)

