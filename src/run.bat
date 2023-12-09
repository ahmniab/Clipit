SET RAYLIB_PATH=C:\raylib\raylib
SET COMPILER_PATH=C:\raylib\w64devkit\bin
@REM ENV_SET PATH=$(COMPILER_PATH)
@REM SET CC=gcc
SET CFLAGS=$(RAYLIB_PATH)\src\raylib.rc.data -s -static -Os -std=c99 -Wall -I$(RAYLIB_PATH)\src -Iexternal -DPLATFORM_DESKTOP
SET LDFLAGS=-lraylib -lopengl32 -lgdi32 -lwinmm
@REM cmd /c IF EXIST main.exe del /F main.exe
gcc -o main.exe main.c $(CFLAGS) $(LDFLAGS)
@REM ENV_UNSET PATH
@REM cmd /c IF EXIST main.exe main.exe