#!/bin/sh
## echo off
## Time build START
## Reference: https://stackoverflow.com/questions/673523/how-do-i-measure-execution-time-of-a-command-on-the-windows-command-line
##set _time=%time: =0%
##set /a _hours=100%_time:~0,2%%%100,_min=100%_time:~3,2%%%100,_sec=100%_time:~6,2%%%100,_cs=%_time:~9,2%
##set /a _started=_hours*60*60*100+_min*60*100+_sec*100+_cs


## Compile
cd devkit
sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 _sms_manager.c
cd ..

cd engine
sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 asm_manager.c
sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 content_manager.c
sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 enum_manager.c
sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 input_manager.c
sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 screen_manager.c
sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 scroll_manager.c
cd ..

cd screen
sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 none_screen.c
sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 test_screen.c
cd ..

sdcc --debug -c -mz80 --opt-code-speed --peep-file peep-rules.txt --std-c99 main.c


## Time build -END-
##set _time=%time: =0%
##set /a _hours=100%_time:~0,2%%%100,_min=100%_time:~3,2%%%100,_sec=100%_time:~6,2%%%100,_cs=%_time:~9,2%
##set /a _duration=_hours*60*60*100+_min*60*100+_sec*100+_cs-_started
##set /a _hours=_duration/60/60/100,_min=100+_duration/60/100%%60,_sec=100+(_duration/100%%60%%60),_cs=100+_duration%%100
##echo.
##echo Time taken: %_sec:~-2%.%_cs:~-2% secs
##echo.


## Link
sdcc --debug -o output.ihx --Werror --opt-code-speed -mz80 --no-std-crt0 --data-loc 0xC000 \
../crt0/crt0_sms.rel main.rel \
../lib/SMSlib.lib \
devkit/_sms_manager.rel \
engine/asm_manager.rel \
engine/content_manager.rel \
engine/enum_manager.rel \
engine/input_manager.rel \
engine/screen_manager.rel \
engine/scroll_manager.rel \
screen/none_screen.rel \
screen/test_screen.rel \
content/gfx.rel


## Execute
ihx2sms output.ihx output.sms

## Delete
cd  devkit
rm -f *.asm 2> /dev/null; rm -f *.lst 2> /dev/null; rm -f *.sym 2> /dev/null
cd ..

cd  engine
rm -f *.asm 2> /dev/null; rm -f *.lst 2> /dev/null; rm -f *.sym 2> /dev/null
cd ..

cd  screen
rm -f *.asm 2> /dev/null; rm -f *.lst 2> /dev/null; rm -f *.sym 2> /dev/null
cd ..

rm -f *.asm 2> /dev/null && rm -f *.ihx 2> /dev/null; rm -f *.lk 2> /dev/null
rm -f *.lst 2> /dev/null && rm -f *.sym 2> /dev/null;
## rm -f *.noi 2> /dev/null

## Run
java -jar ~/Sega/Emulicious/Emulicious.jar output.sms
##output.sms
