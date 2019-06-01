cmake_minimum_required(VERSION 3.14)
project(ft_gkrellm)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(ft_gkrellm
        imonitordisplay.hpp
        imonitormodule.hpp
        main.cpp
        main_ncurse.cpp
        Makefile
        Monitor.cpp
        Monitor.hpp
        OsInfo.cpp
        OsInfo.hpp
        OsInfo.ncurses.cpp
        OsInfo.ncurses.hpp
        Time.cpp
        Time.hpp
        Time.ncurses.cpp
        Time.ncurses.hpp
        Gui.cpp
        Gui.hpp
        NCurses.cpp
        NCurses.hpp)
