cmake_minimum_required(VERSION 3.20)
project(ZooWars LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin")

add_library(zoo_wars
  src/Animal.cpp
  src/Attack.cpp
  src/Defend.cpp
  src/Health.cpp
  src/PlayGame.cpp
  src/Screen.cpp
)
target_compile_features(zoo_wars PUBLIC cxx_std_14)
target_include_directories(zoo_wars PUBLIC "${PROJECT_SOURCE_DIR}/Headers")

add_executable(runProgram src/main.cpp)
target_link_libraries(runProgram PRIVATE zoo_wars)

include(CTest)
if(BUILD_TESTING)
  include(FetchContent)
  # Use a fixed release; dependencies stay in the build directory.
  FetchContent_Declare(googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.14.0
    GIT_SHALLOW TRUE
  )
  set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
  set(INSTALL_GTEST OFF CACHE BOOL "" FORCE)
  FetchContent_MakeAvailable(googletest)

  add_executable(runAllTests
    test/test.cpp
    test/attackTest.cpp
    test/defendTest.cpp
    test/healthTest.cpp
    test/screenTest.cpp
    test/animalTest.cpp
  )
  target_link_libraries(runAllTests PRIVATE zoo_wars GTest::gtest)
  include(GoogleTest)
  gtest_discover_tests(runAllTests)
endif()
