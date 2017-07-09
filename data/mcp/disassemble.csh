#!/bin/csh -f

foreach file (*.asm)
  set asc = $file:r.asc

  CZ80Test -d $file > $asc
end

exit 0
