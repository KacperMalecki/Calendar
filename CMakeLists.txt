cmake_minimum_required(VERSION 4.3)
project(Calendar C)

set(CMAKE_C_STANDARD 23)

include(FetchContent)
FetchContent_Declare(
        raylib
        GIT_REPOSITORY  https://github.com/raysan5/raylib.git
        GIT_TAG         6.2
)
set(BUILD_SHARED_LIBS  OFF CACHE BOOL "" FORCE)
set(CPR_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(CPR_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(raylib)

add_executable(Calendar WIN32
        main.c
        resources.rc
        Calendar.h
        Calendar.c
        Tile.c
        Tile.h
        Settings.c
        Settings.h
        RaylibExtension.c
        RaylibExtension.h
        Button.c
        Button.h
        LanguageTable.c
        LanguageTable.h
        Utilities.c
        Utilities.h
        TextField.c
        TextField.h)

target_link_libraries(Calendar PRIVATE raylib)