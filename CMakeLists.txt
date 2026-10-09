cmake_minimum_required(VERSION 3.20)

project(testing-running)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib")
add_subdirectory(test/googletest)

add_executable(runAllTests
  test/test.cpp
  test/attackTest.cpp
  src/Attack.cpp
  test/defendTest.cpp
  src/Defend.cpp
  test/healthTest.cpp
  src/Health.cpp
  test/screenTest.cpp
  src/Screen.cpp
  test/animalTest.cpp
  src/Animal.cpp
)

target_link_libraries(runAllTests gmock gtest gtest_main)


add_executable(runProgram
  src/main.cpp
  src/Animal.cpp
  src/Attack.cpp
  src/Defend.cpp
  src/Health.cpp
  src/PlayGame.cpp
  src/Screen.cpp
)

