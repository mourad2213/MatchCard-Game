cmake_minimum_required(VERSION 3.29)
project(programmingend)

set(CMAKE_CXX_STANDARD 14)

include_directories(Headers)

add_executable(programmingend
    Headers/BonusCard.h
    Headers/Card.h
    Headers/Deck.h
    Headers/Game.h
    Headers/PenaltyCard.h
    Headers/Player.h
    Headers/Source.cpp
    Headers/StandardCard.h
        Headers/Main.cpp
        Headers/Main.cpp
)
