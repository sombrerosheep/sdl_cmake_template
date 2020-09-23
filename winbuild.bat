@echo off

SET CLEANBUILD=0
SET SETUPENV=0
SET REBUILD=0
SET NOTEST=0

SET CMAKEADDLARGS=""

:ARGS
IF "%1"=="" GOTO EXEC
IF "%1"=="CLEAN" SET CLEANBUILD=1
IF "%1"=="SETUP" SET SETUPENV=1
IF "%1"=="REBUILD" SET REBUILD=1
if "%1"=="NOTEST" SET NOTEST=1
SHIFT

GOTO ARGS


:EXEC

IF "%CLEANBUILD%"=="1" (
  echo "cleaning build dir"
  DEL /S .\build\* /q
  SET REBUILD=1
)

IF "%SETUPENV%"=="1" (
  ECHO "init vs env"
  @call "%vs150comntools%VsDevCmd.bat"
)

IF NOT EXIST .\build (
  mkdir build
)

pushd .\build

IF "%NOTEST%"=="1" (
  CMAKEADDLARGS="-DBUILD_TESTS=OFF"
)

IF "%REBUILD%"=="1" (
  echo "rebuilding cmake project"
  cmake ..\ -G "Visual Studio 15 2017 Win64 %CMAKEADDLARGS%"
)

devenv game.sln /build

popd
