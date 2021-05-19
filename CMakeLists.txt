cmake_minimum_required(VERSION 3.17)
project(L4)

set(CMAKE_CXX_STANDARD 11)

add_executable(L4 main.cpp Field.cpp Field.h
        Humanoids/Humanoid.cpp Humanoids/Humanoid.h
        Actions/Action.cpp Actions/Action.h
        Humanoids/Buffy.cpp Humanoids/Buffy.h
        Humanoids/Vampire.cpp Humanoids/Vampire.h
        Humanoids/Human.cpp Humanoids/Human.h
        Displayer/TerminalDisplay.cpp Displayer/TerminalDisplay.h
        Actions/Kill.cpp Actions/Kill.h Actions/Move.cpp Actions/Move.h Actions/Convert.cpp Actions/Convert.h)