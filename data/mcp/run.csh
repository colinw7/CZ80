#!/bin/csh -f

if ($#argv == 0) then
  echo "Usage: nas_run <file>"
  exit 1
endif

set file = $1

CPrePro $file >! temp.asc

CZ80Test -a temp.asc >! temp.asm

if ($status != 0) then
  exit 1
endif

CZ80Test -e temp.asm

exit 0
