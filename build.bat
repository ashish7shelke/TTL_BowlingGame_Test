
REM Run this script in X64 Native Tools Command Prompt for Visual Studio on Windows OS

cl -c /EHsc Bowling_Roll.cpp  Bowling_Game.cpp main.cpp

link Bowling_Game.obj Bowling_Roll.obj main.obj /out:Bowling.exe

Bowling.exe

