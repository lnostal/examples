set(CMAKE_SYSTEM_NAME Linux)
#set(CMAKE_SYSTEM_PROCESSOR x86_64)

set(CMAKE_CROSSCOMPILING TRUE)


set(tools /opt/homebrew/Cellar/x86_64-unknown-linux-gnu/11.2.0.reinstall/toolchain)
set(CMAKE_SYSROOT ${tools}/x86_64-unknown-linux-gnu/sysroot)
set(CMAKE_CXX_COMPILER ${tools}/bin/x86_64-unknown-linux-gnu-g++)
set(CMAKE_CXX_COMPILER_TARGET x86_64-unknown-linux-gnu)



set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
