@echo off
::gfx		Commonly used gfx	not banked

cd ..
cd content
cd gfx

:: Tiles
bmp2tile.exe raw/hockey.png -savetiles "hockey (tiles).psgcompr" -noremovedupes -planar -tileoffset 0  -savetilemap "hockey (tilemap).bin" -savepalette "hockey (palette).bin" -fullpalette -exit

cd ..
folder2c gfx gfx

sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 gfx.c

if exist "*.asm" del "*.asm" > nul; if exist "*.lst" del "*.lst" > null if exist "*.sym" del "*.sym" > nul


cd ..
cd scripts