cmake_minimum_required(VERSION 3.11)
set(CONAN_DISABLE_CHECK_COMPILER True)

# проект и версия
project(examples CXX)
# поддержкa стандарта С++ 20
set(CMAKE_CXX_STANDARD 20)

# сгенерированный скрипт conanbuildinfo.cmake, созданный Conan
include(env/conanbuildinfo.cmake)
# настраиваем СMake на работу с библиотеками, установленными Conan
conan_basic_setup()

# подключение boost
find_package(Boost 1.78.0 REQUIRED)
if(Boost_FOUND)
  include_directories(${Boost_INCLUDE_DIRS})
endif()

set(CMAKE_CXX_COMPILER_FORCED True)


# подключение библиотеки pthread для кроссплатформенности //linux
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

# темы
add_executable(temp src/temp.cpp)
add_executable(patterns src/patterns.cpp)
add_executable(threads src/threads.cpp)

# библиотека для поддержки потоков
target_link_libraries(temp PRIVATE Threads::Threads dl)
target_link_libraries(patterns PRIVATE Threads::Threads dl)
target_link_libraries(threads PRIVATE Threads::Threads dl)


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
