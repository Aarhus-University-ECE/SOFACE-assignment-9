project(tests)
include_directories(include)


add_executable(test_cars src/test_cars.cpp)

target_link_libraries(test_cars cars)

add_test(test_cars test_cars)