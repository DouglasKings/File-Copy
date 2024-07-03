@echo off
setlocal enabledelayedexpansion

REM Define your directory path within your project directory
set DIRECTORY_PATH=C:\Douglas Kings\Douglas\Software Development\GitHub\C\File-Copy\YourNewDirectory

REM Check if the directory exists, else create it
IF NOT EXIST "%DIRECTORY_PATH%" (
    MKDIR "%DIRECTORY_PATH%"
)
