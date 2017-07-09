#!/bin/csh -f

if ($#argv == 0) then
  echo "Usage: z80asm [-stream] <file>"
  exit 1
endif

set opts = ""
set args = ""

while ($#argv > 0)
  if      ("$1" =~ -*) then
    set opts = ($opts $1:q)
    shift
  else
    set args = ($args $1:q)
    shift
  endif
end

set ifile = $args[1]
set ofile = temp.asm
set tfile = temp.asc

if (! -e $ifile) then
  set ifile1 = ${ifile}.asc

  if (! -e $ifile1) then
    echo "Can't find file $ifile"
    exit 1
  endif

  set ofile = ${ifile}.asm
  set ifile = $ifile1
endif

CPrePro -no_blank_lines $ifile >! $tfile

CZ80Test $opts -a $tfile >! $ofile

if ($status != 0) then
  exit 1
endif

exit 0
