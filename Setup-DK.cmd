@echo off
setlocal
rem Compatibility entry: Client.exe owns dependency checks, Global discovery and new-install setup.
if exist "%~dp0Client.exe" (
  start "" "%~dp0Client.exe" --setup
  exit /b 0
)
powershell.exe -NoProfile -ExecutionPolicy Bypass -STA -File "%~dp0tools\start-dedicated-client.ps1" -Setup
exit /b %errorlevel%
