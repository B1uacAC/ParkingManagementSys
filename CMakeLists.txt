cmake_minimum_required(VERSION 3.21)
project(ParkSysDesign)

set(CMAKE_CXX_STANDARD 14)
set(EasyX_DIR D:/programming_related/ParkSysDesign/easyx)
include_directories(${EasyX_DIR}/include)
link_directories(${EasyX_DIR}/lib64)
link_libraries(libEasyX.a libgdi32.a libole32.a) # Á´½ÓEasyX¿â

add_executable(ParkSysDesign main.cpp management.h management.cpp Window.cpp Window.h basic.cpp basic.h btn.cpp btn.h config.h table.cpp table.h AVLtree.h user.h user.h AVLtree.h user.cpp)
