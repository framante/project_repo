
CMAKE_MINIMUM_REQUIRED(VERSION 2.8.12)
set(DEAL_II_DIR "/u/sw/toolchains/gcc-glibc/11/pkgs/dealii/9.3.1/lib/cmake/deal.II")

FIND_PACKAGE(deal.II 9.1.0 REQUIRED
             HINTS ${DEAL_II_DIR} ../ ../../ $ENV{DEAL_II_DIR}
	     )
DEAL_II_INITIALIZE_CACHED_VARIABLES()

PROJECT(step37)

ADD_EXECUTABLE(main main.cpp)
DEAL_II_SETUP_TARGET(main)
