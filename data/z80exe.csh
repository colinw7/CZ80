#!/bin/csh -f

if ($#argv == 0) then
  echo "Usage: z80exe [-stream] [-icount] <file>"
  exit 1
endif

set aopts = ""
set eopts = ""
set args  = ""

while ($#argv > 0)
  if      ("$1" =~ -*) then
    if      ("$1" == "-stream") then
      set aopts = ($aopts $1:q)
    else if ("$1" == "-icount") then
      set eopts = ($eopts $1:q)
    else
      echo "Unexpected option $1"
      set aopts = ($aopts $1:q)
    endif

    shift
  else
    set args = ($args $1:q)
    shift
  endif
end

set file = $args[1]

CPrePro -no_blank_lines $file >! temp.asc

CZ80Test $aopts -a temp.asc >! temp.asm

if ($status != 0) then
  exit 1
endif

CZ80Test $eopts -e temp.asm

exit 0
