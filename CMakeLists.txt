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
        TextField.h
        Date.c
        Date.h
        ProgramState.c
        ProgramState.h
        CalendarState.c
        CalendarState.h
        SettingsState.c
        SettingsState.h
        TodayDisplay.c
        TodayDisplay.h
        Event.c
        Event.h
        ColorTheme.c
        ColorTheme.h
        TextureButton.c
        TextureButton.h
        TextFieldButton.c
        TextFieldButton.h
        ToggleButton.c
        ToggleButton.h
        AboutTheProgramState.c
        AboutTheProgramState.h)

target_link_libraries(Calendar PRIVATE raylib)