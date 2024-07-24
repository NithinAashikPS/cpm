find_package(ftxui CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE ftxui::dom ftxui::screen ftxui::component)