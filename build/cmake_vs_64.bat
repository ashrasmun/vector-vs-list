@echo off

:: This script invokes CMake with Ninja for Visual Studio, 64bit target

setlocal
  :: Enabling Microsoft's cl.exe compiler
  :: One of the key environment variables for cl.exe is INCLUDE.
  :: It's a dumb check, but works.
  if not defined INCLUDE (
      @call "c:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Auxiliary\Build\vcvars64.bat"
  )

  :: In CMake, this is known as CMAKE_BINARY_DIR, but in fact it's
  :: a directory for intermediate files, as far as I understand.
  set CMAKE_INTERMEDIATE_DIR="../../build/64/cmake"

  :: Prepare the build
  if not exist %CMAKE_INTERMEDIATE_DIR%\CMakeCache.txt (
    @call cmake -G Ninja -S .. -B %CMAKE_INTERMEDIATE_DIR%
  )

  @pushd %CMAKE_INTERMEDIATE_DIR%
  @call ninja
  @popd
endlocal

:: TODO: This script doesn't take into account different configurations, i.e.
::       DEBUG, RELASE, RELWITHDEBINFO and MINSIZEREL. This should be adressed.