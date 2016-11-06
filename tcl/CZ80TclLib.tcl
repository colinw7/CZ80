proc CZ80TclLibCreateDebug { } {
  gset cz80_tcl_pc_row -1
  gset cz80_tcl_sp_row -1
  gset cz80_tcl_trace   1

  set norm_font *adobe*courier*medium-r-normal*12*
  set bold_font *adobe*courier*bold-r-normal*12*

  #---

  global cz80_tcl_debug_dialog

  set cz80_tcl_debug_dialog "."

  set parent ""

  #---

  wm title $cz80_tcl_debug_dialog "Z80 Emulator (Debug)"

  wm protocol $cz80_tcl_debug_dialog WM_DELETE_WINDOW CZ80TclLibExit

  #---

  set top_frame [frame $parent.top_frame]

  pack $top_frame -side top -fill both -expand true

  set bottom_frame [frame $parent.bottom_frame]

  pack $bottom_frame -side bottom -fill x

  #---

  set left_frame [frame $top_frame.left_frame]

  pack $left_frame -side left -fill y

  set right_frame [frame $top_frame.right_frame]

  pack $right_frame -side right -fill y

  #---

  createFrame $left_frame.memory "Memory"

  set memory_frame [$left_frame.memory subwidget frame]

  tixScrolledText $memory_frame.text -width 450 -height 350

  global cz80_tcl_memory_text

  set cz80_tcl_memory_text [$memory_frame.text subwidget text]

  $cz80_tcl_memory_text config -state disabled

  $cz80_tcl_memory_text tag configure norm -font $norm_font
  $cz80_tcl_memory_text tag configure addr -font $bold_font

  $cz80_tcl_memory_text tag bind addr <Double-1> CZ80TclLibSelectAddrMemoryText

  pack $memory_frame.text

  pack $left_frame.memory -side top

  #---

  createFrame $left_frame.instructions "Instructions"

  set instructions_frame [$left_frame.instructions subwidget frame]

  tixScrolledText $instructions_frame.text -width 450 -height 350

  global cz80_tcl_instructions_text

  set cz80_tcl_instructions_text [$instructions_frame.text subwidget text]

  $cz80_tcl_instructions_text config -state disabled

  $cz80_tcl_instructions_text tag configure curr -font $bold_font -foreground red
  $cz80_tcl_instructions_text tag configure brk  -font $bold_font -foreground green
  $cz80_tcl_instructions_text tag configure norm -font $norm_font
  $cz80_tcl_instructions_text tag configure addr -font $bold_font
  $cz80_tcl_instructions_text tag configure code -font $norm_font -foreground blue

  $cz80_tcl_instructions_text tag bind addr <Double-1> \
    CZ80TclLibSelectAddrInstructionsText

  pack $instructions_frame.text -side top -fill both -expand true

  entry $instructions_frame.op_data -textvariable cz80_tcl_op_data

  pack $instructions_frame.op_data -side top -fill x

  pack $left_frame.instructions -side top

  #---

  createFrame $right_frame.registers "Registers"

  set registers_frame [$right_frame.registers subwidget frame]

  set rl_frame [frame $registers_frame.left]
  set rr_frame [frame $registers_frame.right]

  set af_frame   [createRegisterPrompt $rl_frame "AF"  cz80_tcl_af]
  set bc_frame   [createRegisterPrompt $rl_frame "BC"  cz80_tcl_bc]
  set de_frame   [createRegisterPrompt $rl_frame "DE"  cz80_tcl_de]
  set hl_frame   [createRegisterPrompt $rl_frame "HL"  cz80_tcl_hl]
  set ix_frame   [createRegisterPrompt $rl_frame "IX"  cz80_tcl_ix]
  set iy_frame   [createRegisterPrompt $rl_frame "IY"  cz80_tcl_iy]
  set sp_frame   [createRegisterPrompt $rl_frame "SP"  cz80_tcl_sp]
  set pc_frame   [createRegisterPrompt $rl_frame "PC"  cz80_tcl_pc]

  set af_1_frame [createRegisterPrompt $rr_frame "AF'" cz80_tcl_af_1]
  set bc_1_frame [createRegisterPrompt $rr_frame "BC'" cz80_tcl_bc_1]
  set de_1_frame [createRegisterPrompt $rr_frame "DE'" cz80_tcl_de_1]
  set hl_1_frame [createRegisterPrompt $rr_frame "HL'" cz80_tcl_hl_1]
  set i_frame    [createRegisterPrompt $rr_frame "I"   cz80_tcl_i]
  set r_frame    [createRegisterPrompt $rr_frame "R"   cz80_tcl_r]
  set iff_frame  [createRegisterPrompt $rr_frame "IFF" cz80_tcl_iff]

  bind $pc_frame.cz80_tcl_pc_entry <Return> CZ80TclLibPCChanged

  pack $af_frame -side top
  pack $bc_frame -side top
  pack $de_frame -side top
  pack $hl_frame -side top
  pack $ix_frame -side top
  pack $iy_frame -side top
  pack $sp_frame -side top
  pack $pc_frame -side top

  pack $af_1_frame -side top
  pack $bc_1_frame -side top
  pack $de_1_frame -side top
  pack $hl_1_frame -side top
  pack $i_frame    -side top
  pack $r_frame    -side top
  pack $iff_frame  -side top

  pack $rl_frame -side left  -anchor n
  pack $rr_frame -side right -anchor n

  pack $right_frame.registers -side top -anchor w

  #---

  createFrame $right_frame.flags "Flags"

  set flags_frame [$right_frame.flags subwidget frame]

  set s_frame [createFlagPrompt $flags_frame "S" cz80_tcl_s_flag]
  set z_frame [createFlagPrompt $flags_frame "Z" cz80_tcl_z_flag]
  set y_frame [createFlagPrompt $flags_frame "Y" cz80_tcl_y_flag]
  set h_frame [createFlagPrompt $flags_frame "H" cz80_tcl_h_flag]
  set x_frame [createFlagPrompt $flags_frame "X" cz80_tcl_x_flag]
  set p_frame [createFlagPrompt $flags_frame "P" cz80_tcl_p_flag]
  set n_frame [createFlagPrompt $flags_frame "N" cz80_tcl_n_flag]
  set c_frame [createFlagPrompt $flags_frame "C" cz80_tcl_c_flag]

  pack $s_frame -side left
  pack $z_frame -side left
  pack $y_frame -side left
  pack $h_frame -side left
  pack $x_frame -side left
  pack $p_frame -side left
  pack $n_frame -side left
  pack $c_frame -side left

  pack $right_frame.flags -side top -anchor w

  #---

  createFrame $right_frame.stack "Stack"

  set stack_frame [$right_frame.stack subwidget frame]

  text $stack_frame.text -width 20 -height 15

  global cz80_tcl_stack_text

  set cz80_tcl_stack_text $stack_frame.text

  $cz80_tcl_stack_text config -state disabled

  $cz80_tcl_stack_text tag configure curr -font $bold_font -foreground red
  $cz80_tcl_stack_text tag configure norm -font $norm_font
  $cz80_tcl_stack_text tag configure addr -font $bold_font

  pack $stack_frame.text

  pack $right_frame.stack -side top -anchor w

  #---

  createFrame $right_frame.breakpoints "Breakpoints"

  set breakpoints_frame [$right_frame.breakpoints subwidget frame]

  tixScrolledText $breakpoints_frame.text -width 150 -height 200

  global cz80_tcl_breakpoints_text

  set cz80_tcl_breakpoints_text [$breakpoints_frame.text subwidget text]

  $cz80_tcl_breakpoints_text config -state disabled

  $cz80_tcl_breakpoints_text tag configure norm -font $norm_font
  $cz80_tcl_breakpoints_text tag configure addr -font $bold_font

  pack $breakpoints_frame.text

  button $breakpoints_frame.add -text "Add"    -command CZ80TclLibAddBreakpoint
  button $breakpoints_frame.del -text "Delete" -command CZ80TclLibDelBreakpoint
  button $breakpoints_frame.all -text "Clear"  -command CZ80TclLibClrBreakpoint

  pack $breakpoints_frame.add $breakpoints_frame.del -side left -anchor w

  pack $right_frame.breakpoints -side top -anchor w

  #----

  set toggle_frame [frame $bottom_frame.toggles]

  set trace_frame [frame $toggle_frame.trace]

  label       $trace_frame.label -text "Trace"
  checkbutton $trace_frame.check -variable cz80_tcl_trace \
              -onvalue 1 -offvalue 0 -command CZ80TclTraceProc

  pack $trace_frame.label $trace_frame.check -side left -anchor w

  pack $trace_frame -side left -anchor w

  pack $toggle_frame -side top -anchor w -fill x

  #----

  set button_frame [frame $bottom_frame.buttons]

  button $button_frame.run -text "Run" -command CZ80TclLibExecute

  pack $button_frame.run -side left

  button $button_frame.next -text "Next" -command CZ80TclLibNext

  pack $button_frame.next -side left

  button $button_frame.step -text "Step" -command CZ80TclLibStep

  pack $button_frame.step -side left

  button $button_frame.continue -text "Continue" -command CZ80TclLibContinue

  pack $button_frame.continue -side left

  button $button_frame.stop -text "Stop" -command CZ80TclLibStop

  pack $button_frame.stop -side left

  button $button_frame.restart -text "Restart" -command CZ80TclLibRestart

  pack $button_frame.restart -side left

  button $button_frame.exit -text "Exit" -command CZ80TclLibExit

  pack $button_frame.exit -side left

  pack $button_frame -side top -anchor w -fill x
}

proc CZ80TclLibPCChanged { } {
  global cz80_tcl_pc

  CZ80TclLibSetAddr $cz80_tcl_pc
}

proc CZ80TclTraceProc { } {
  global cz80_tcl_trace

  CZ80TclLibSetTrace $cz80_tcl_trace
}

proc CZ80TclLibCreateScreenWidget { } {
  global cz80_tcl_debug_dialog
  global cz80_tcl_screen_dialog

  if {[ info exists  cz80_tcl_debug_dialog] &&
      [winfo exists $cz80_tcl_debug_dialog]} {
    set cz80_tcl_screen_dialog .screen

    set parent $cz80_tcl_screen_dialog

    toplevel $cz80_tcl_screen_dialog
  } else {
    set cz80_tcl_screen_dialog .

    set parent ""
  }

  wm title $cz80_tcl_screen_dialog "Z80 Emulator (Screen)"

  wm protocol $cz80_tcl_screen_dialog WM_DELETE_WINDOW CZ80TclLibExit

  global cz80_tcl_screen_canvas
  global cz80_tcl_screen_width
  global cz80_tcl_screen_height

  set cz80_tcl_screen_canvas $parent.canvas

  CZ80TclLibScreenCanvas $cz80_tcl_screen_canvas \
    -width $cz80_tcl_screen_width -height $cz80_tcl_screen_height

  pack $cz80_tcl_screen_canvas -side top -expand true -fill both

  bind $cz80_tcl_screen_canvas <Enter> {focus %W}
}

proc CZ80TclLibAddScreenRefresh { } {
  after 100 CZ80TclLibAddScreenRefreshCB
}

proc CZ80TclLibAddScreenRefreshCB { } {
  update

  CZ80TclLibRedrawScreen

  CZ80TclLibAddScreenRefresh
}

#--------

proc CZ80TclLibClearMemoryText { } {
  global cz80_tcl_memory_text

  $cz80_tcl_memory_text config -state normal

  $cz80_tcl_memory_text delete 1.0 end

  $cz80_tcl_memory_text config -state disabled
}

proc CZ80TclLibAddNormalMemoryText { str } {
  global cz80_tcl_memory_text

  $cz80_tcl_memory_text config -state normal

  $cz80_tcl_memory_text insert end $str norm

  $cz80_tcl_memory_text config -state disabled
}

proc CZ80TclLibAddAddrMemoryText { str } {
  global cz80_tcl_memory_text

  $cz80_tcl_memory_text config -state normal

  $cz80_tcl_memory_text insert end $str addr

  $cz80_tcl_memory_text config -state disabled
}

proc CZ80TclLibSelectAddrMemoryText { } {
}

#--------

proc CZ80TclLibClearInstructionsText { } {
  global cz80_tcl_instructions_text

  $cz80_tcl_instructions_text config -state normal

  $cz80_tcl_instructions_text delete 1.0 end

  $cz80_tcl_instructions_text config -state disabled
}

proc CZ80TclLibAddCurrInstructionsText { str } {
  global cz80_tcl_instructions_text

  $cz80_tcl_instructions_text config -state normal

  $cz80_tcl_instructions_text insert end $str curr

  $cz80_tcl_instructions_text config -state disabled
}

proc CZ80TclLibAddBreakInstructionsText { str } {
  global cz80_tcl_instructions_text

  $cz80_tcl_instructions_text config -state normal

  $cz80_tcl_instructions_text insert end $str brk

  $cz80_tcl_instructions_text config -state disabled
}

proc CZ80TclLibAddNormalInstructionsText { str } {
  global cz80_tcl_instructions_text

  $cz80_tcl_instructions_text config -state normal

  $cz80_tcl_instructions_text insert end $str norm

  $cz80_tcl_instructions_text config -state disabled
}

proc CZ80TclLibAddAddrInstructionsText { str } {
  global cz80_tcl_instructions_text

  $cz80_tcl_instructions_text config -state normal

  $cz80_tcl_instructions_text insert end $str addr

  $cz80_tcl_instructions_text config -state disabled
}

proc CZ80TclLibAddCodeInstructionsText { str } {
  global cz80_tcl_instructions_text

  $cz80_tcl_instructions_text config -state normal

  $cz80_tcl_instructions_text insert end $str code

  $cz80_tcl_instructions_text config -state disabled
}

proc CZ80TclLibSelectAddrInstructionsText { } {
  global cz80_tcl_instructions_text

  set px [winfo pointerx $cz80_tcl_instructions_text]
  set py [winfo pointery $cz80_tcl_instructions_text]

  set wx [winfo rootx $cz80_tcl_instructions_text]
  set wy [winfo rooty $cz80_tcl_instructions_text]

  set x [expr $px - $wx]
  set y [expr $py - $wy]

  set text_pos [$cz80_tcl_instructions_text index @$x,$y]

  set row 0
  set col 0

  CZ80TclLibDecodeTextPos $text_pos row col

  set addr [$cz80_tcl_instructions_text get $row.2 $row.6]

  CZ80TclLibSetAddr $addr
}

#--------

proc CZ80TclLibClearStackText { } {
  global cz80_tcl_stack_text

  $cz80_tcl_stack_text config -state normal

  $cz80_tcl_stack_text delete 1.0 end

  $cz80_tcl_stack_text config -state disabled
}

proc CZ80TclLibAddCurrStackText { str } {
  global cz80_tcl_stack_text

  $cz80_tcl_stack_text config -state normal

  $cz80_tcl_stack_text insert end $str curr

  $cz80_tcl_stack_text config -state disabled
}

proc CZ80TclLibAddNormalStackText { str } {
  global cz80_tcl_stack_text

  $cz80_tcl_stack_text config -state normal

  $cz80_tcl_stack_text insert end $str norm

  $cz80_tcl_stack_text config -state disabled
}

proc CZ80TclLibAddAddrStackText { str } {
  global cz80_tcl_stack_text

  $cz80_tcl_stack_text config -state normal

  $cz80_tcl_stack_text insert end $str addr

  $cz80_tcl_stack_text config -state disabled
}

#--------

proc CZ80TclLibClearBreakpointText { } {
  global cz80_tcl_breakpoints_text

  $cz80_tcl_breakpoints_text config -state normal

  $cz80_tcl_breakpoints_text delete 1.0 end

  $cz80_tcl_breakpoints_text config -state disabled
}

proc CZ80TclLibAddNormalBreakpointText { str } {
  global cz80_tcl_breakpoints_text

  $cz80_tcl_breakpoints_text config -state normal

  $cz80_tcl_breakpoints_text insert end $str norm

  $cz80_tcl_breakpoints_text config -state disabled
}

#--------

proc CZ80TclLibMarkPC { row } {
  global cz80_tcl_instructions_text

  $cz80_tcl_instructions_text config -state normal

  global cz80_tcl_pc_row

  if {$cz80_tcl_pc_row >= 0} {
    $cz80_tcl_instructions_text delete $cz80_tcl_pc_row.0 $cz80_tcl_pc_row.1

    $cz80_tcl_instructions_text insert $cz80_tcl_pc_row.0 " " curr
  }

  if {$row > 0} {
    set cz80_tcl_pc_row $row

    $cz80_tcl_instructions_text delete $cz80_tcl_pc_row.0 $cz80_tcl_pc_row.1

    $cz80_tcl_instructions_text insert $cz80_tcl_pc_row.0 ">" curr

    $cz80_tcl_instructions_text see $cz80_tcl_pc_row.0
  } else {
    set cz80_tcl_pc_row -1
  }

  $cz80_tcl_instructions_text config -state disabled
}

proc CZ80TclLibMarkBreakpoint { row } {
  global cz80_tcl_instructions_text

  $cz80_tcl_instructions_text config -state normal

  if {$row > 0} {
    $cz80_tcl_instructions_text delete $row.1 $row.2

    $cz80_tcl_instructions_text insert $row.1 "*" curr

    $cz80_tcl_instructions_text see $row.0
  }

  $cz80_tcl_instructions_text config -state disabled
}

proc CZ80TclLibUnmarkBreakpoint { row } {
  global cz80_tcl_instructions_text

  $cz80_tcl_instructions_text config -state normal

  if {$row > 0} {
    $cz80_tcl_instructions_text delete $row.1 $row.2

    $cz80_tcl_instructions_text insert $row.1 " " curr

    $cz80_tcl_instructions_text see $row.0
  }

  $cz80_tcl_instructions_text config -state disabled
}

proc CZ80TclLibSetMem { row col value c } {
  global cz80_tcl_memory_text

  $cz80_tcl_memory_text config -state normal

  set col1 [expr $col*3 + 6]
  set col2 [expr $col1 + 2]

  $cz80_tcl_memory_text delete $row.$col1 $row.$col2

  $cz80_tcl_memory_text insert $row.$col1 "$value" norm

  set col1 [expr $col + 32]
  set col2 [expr $col1 + 1]

  $cz80_tcl_memory_text delete $row.$col1 $row.$col2

  $cz80_tcl_memory_text insert $row.$col1 "$c" norm

  $cz80_tcl_memory_text see $row.0

  $cz80_tcl_memory_text config -state disabled
}

proc CZ80TclLibDecodeTextPos { text_pos row col } {
  upvar $row row_up
  upvar $col col_up

  set pos [string first "." $text_pos]

  set row_up [string range $text_pos 0 [expr $pos - 1]]
  set col_up [string range $text_pos [expr $pos + 1] end]
}

proc createFrame { widget title } {
  tixLabelFrame $widget -label $title

  set label [$widget subwidget label]

  $label configure -foreground blue

  set frame [$widget subwidget frame]

  return $frame
}

proc createRegisterPrompt { parent name var } {
  set frame [frame $parent.$var]

  set    label_widget $frame.$var
  append label_widget _label

  set    entry_widget $frame.$var
  append entry_widget _entry

  label $label_widget -text $name -width 3 -anchor w
  entry $entry_widget -textvariable $var -width 5

  pack $label_widget $entry_widget -side left

  return $frame
}

proc createFlagPrompt { parent name var } {
  set frame [frame $parent.$var]

  set    label_widget $frame.$var
  append label_widget _label

  set    entry_widget $frame.$var
  append entry_widget _entry

  label       $label_widget -text $name
  checkbutton $entry_widget -variable $var -onvalue 1 -offvalue 0

  pack $label_widget $entry_widget -side top -anchor w

  return $frame
}
