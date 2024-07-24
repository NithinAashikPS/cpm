find_package(Curses REQUIRED)

target_include_directories(${PROJECT_NAME} PRIVATE ${CURSES_INCLUDE_DIRS})
target_compile_options(${PROJECT_NAME} PRIVATE ${CURSES_CFLAGS})
target_link_libraries(${PROJECT_NAME} PRIVATE ${CURSES_LIBRARIES})