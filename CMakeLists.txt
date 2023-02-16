cmake_minimum_required(VERSION 3.0.0)

# проект и версия
project(examples VERSION 0.1.0)
# поддержкa стандарта С++ 20
set(CMAKE_CXX_STANDARD 20)

#include(CTest)
#enable_testing()

# сгенерированный скрипт conanbuildinfo.cmake, созданный Conan
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
# настраиваем СMake на работу с библиотеками, установленными Conan
conan_basic_setup()

# подключение boost
find_package(Boost 1.78.0 REQUIRED)
if(Boost_FOUND)
  include_directories(${Boost_INCLUDE_DIRS})
endif()

# подключение библиотеки pthread для кроссплатформенности //linux
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

# главный сорс
add_executable(examples src/main.cpp)

# библиотека для поддержки потоков
target_link_libraries(examples PRIVATE Threads::Threads dl)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
