cmake_minimum_required(VERSION 3.10)

project(scenic_graph_adjacency_matrix C)

set(CMAKE_C_STANDARD 99)

add_executable(scenic_graph_adjacency_matrix
    main.c
    graph.c
)

target_include_directories(scenic_graph_adjacency_matrix PRIVATE ${PROJECT_SOURCE_DIR})
