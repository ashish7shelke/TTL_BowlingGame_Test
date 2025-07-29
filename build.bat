
REM Run this script in X64 Native Tools Command Prompt for Visual Studio on Windows OS

cl -c /EHsc Bowling_Game.cpp Bowling_Frame.cpp main.cpp

link Bowling_Game.obj Bowling_Frame.obj main.obj /out:Bowling.exe

Bowling.exe

