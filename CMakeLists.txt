cmake_minimum_required(VERSION 3.28)
project(SudokuGame)

set(CMAKE_CXX_STANDARD 23)

add_executable(SudokuGame main.cpp
        game.cpp
        game.h
        consoleFunctions.cpp
        consoleFunctions.h
        sudokuGrid.cpp
        sudokuGrid.h
        sudokuGenerator.cpp
        sudokuGenerator.h
        menu.cpp
        menu.h
        globalVariables.h
        displayFunctions.cpp
        displayFunctions.h
        MyVector.h
        node.cpp
        node.h
        linkedList.cpp
        linkedList.h
        greetings.cpp
        greetings.h
)
