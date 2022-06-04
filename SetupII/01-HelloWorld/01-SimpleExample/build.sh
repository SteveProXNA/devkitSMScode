#!/bin/sh
## echo off
## Compile
sdcc --debug -c -mz80 --std-sdcc99 main.c


## Link
sdcc --debug -mz80 --no-std-crt0 --data-loc 0xC000 -o output.ihx crt0_sms.rel main.rel SMSlib.lib


## Execute
ihx2sms output.ihx output.sms

## Delete
rm -f *.asm 2> /dev/null && rm -f *.ihx 2> /dev/null; rm -f *.lk 2> /dev/null
rm -f *.lst 2> /dev/null && rm -f *.sym 2> /dev/null;
## rm -f *.noi 2> /dev/null

## Run
java -jar ~/Sega/Emulicious/Emulicious.jar output.sms
##output.sms
