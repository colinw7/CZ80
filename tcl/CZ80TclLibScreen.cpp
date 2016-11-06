#include <std_c++.h>
#include <CTclCanvas/CTclCanvas.h>
#include <CZ80TclLib/CZ80TclLib.h>
#include <CZ80TclLib/CZ80TclLibScreen.h>

CZ80TclLibScreenCanvasCmd::
CZ80TclLibScreenCanvasCmd(CZ80TclLib *z80) :
 CTclAppCanvasCmd(z80), z80_(z80), canvas_(NULL)
{
  init();
}

CZ80TclLibScreenCanvasCmd::
~CZ80TclLibScreenCanvasCmd()
{
  delete canvas_;
}

CTclAppCanvas *
CZ80TclLibScreenCanvasCmd::
createInstance(CTclApp *)
{
  canvas_ = new CZ80TclLibScreenCanvas(z80_);

  canvas_->setForeground(CRGB(0.0));
  canvas_->setBackground(CRGB(1.0));

  z80_->setScreenCanvas(canvas_);

  return (CTclAppCanvas *) canvas_->getCanvasWidget();
}

CZ80TclLibScreenCanvas::
CZ80TclLibScreenCanvas(CZ80TclLib *z80) :
 CTclCanvas(z80), z80_(z80)
{
}

bool
CZ80TclLibScreenCanvas::
instanceCommand(int, const char **)
{
  return false;
}

bool
CZ80TclLibScreenCanvas::
instanceConfigure(int, const char **)
{
  return false;
}

void
CZ80TclLibScreenCanvas::
draw()
{
  startDoubleBuffer();

  z80_->drawScreen();

  endDoubleBuffer();
}

void
CZ80TclLibScreenCanvas::
mousePress()
{
}

void
CZ80TclLibScreenCanvas::
mouseMotion()
{
}

void
CZ80TclLibScreenCanvas::
mouseRelease()
{
}

void
CZ80TclLibScreenCanvas::
keyPress()
{
  z80_->keyPress(getKeyEvent());
}

void
CZ80TclLibScreenCanvas::
keyRelease()
{
  z80_->keyRelease(getKeyEvent());
}
