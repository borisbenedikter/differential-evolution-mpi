cmake_minimum_required (VERSION 3.5)

# project name
project (rosenbrock_DE)

# Sources
set (SRCS src/main.c src/rosenbrock.c)

# Include directories
find_package(MPI REQUIRED)
set (PATH_TO_DE_INC /home/boris/Documenti/Libraries/Optimization/include)
include_directories(include ${PATH_TO_DE_INC} ${MPI_INCLUDE_PATH})

# Compiler options
add_compile_options(-Wall -O3)

# add the executable
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ../bin)
set (EXE_NAME ${CMAKE_PROJECT_NAME})
add_executable (${EXE_NAME} ${SRCS})

# math.h library (must be after the target!)
target_link_libraries(${EXE_NAME} m)

# differential_evolution library
set (PATH_TO_DE_LIB /home/boris/Documenti/Libraries/Optimization/lib)
target_link_libraries(${EXE_NAME} ${PATH_TO_DE_LIB}/libmy_DE.a ${MPI_LIBRARIES})

if(MPI_COMPILE_FLAGS)
  set_target_properties(${EXE_NAME} PROPERTIES
    COMPILE_FLAGS "${MPI_COMPILE_FLAGS}")
endif()

if(MPI_LINK_FLAGS)
  set_target_properties(${EXE_NAME} PROPERTIES
    LINK_FLAGS "${MPI_LINK_FLAGS}")
endif()


