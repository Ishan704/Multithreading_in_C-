# Specify the minimum version required for CMake
cmake_minimum_required(VERSION 3.10)

# Define the project name
project(condition_variable)
add_executable(basic_condition_var_output  basic_conditionvariable_program.cpp)
add_executable(add_deduct_money_output  add_deduct_money_cv_program.cpp)



target_link_libraries(basic_condition_var_output pthread)
target_link_libraries(add_deduct_money_output pthread)
