cmake_minimum_required(VERSION 3.14)
project(WOLD)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

#DPPの読み込み
include(FetchContent)
FetchContent_Declare(
  dpp
  GIT_REPOSITORY https://github.com/brainboxdotcc/DPP.git
  GIT_TAG master
)
FetchContent_MakeAvailable(dpp)

add_subdirectory(src)
