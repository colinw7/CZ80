#include <CZ80.h>
#include <CArgs.h>
#include <CTempFile.h>
#include <CAtExit.h>
#include <CStrUtil.h>

struct CZ80TestTrace : public CZ80Trace {
  bool verbose;

  CZ80TestTrace(CZ80 &z80, bool verbose_1) :
    CZ80Trace(z80), verbose(verbose_1) {
  }

  void initProc() {
  }

  void termProc() {
    if (! verbose)
      z80.printState(std::cout);
  }

  void preStepProc() {
    if (verbose) {
      CZ80OpData op_data;

      z80.getOpData(&op_data);

      op_data.printStr(std::cout);

      std::cout << std::endl;
    }
  }

  void postStepProc() {
    if (verbose)
      z80.printState(std::cout);
  }
};

struct CZ80AtExit : public CAtExit {
  CZ80 *z80;

  CZ80AtExit(CZ80 *z801) :
   z80(z801) {
  }

  void operator()() {
    z80->dumpOpCounts(std::cout);
  }
};

int
main(int argc, char **argv)
{
  CZ80 z80;

  CArgs cargs("-a:f      (assemble) "
              "-A:f      (assembleAll) "
              "-d:f      (disassemble) "
              "-e:f      (execute) "
              "-v:f      (verbose) "
              "-o:s      (output filename) "
              "-L:Sm     (define label) "
              "-org:i    (origin address) "
              "-dump:f   (enable dump) "
              "-undump:f (print dump file) "
              "-bin:f    (input file is binary) "
              "-stream:f (stream assembly 8 chars per line) "
              "-icount:f (display instruction count on exit) "
              "-dsym:f   (display symbol table) "
              );

  cargs.parse(&argc, argv);

  bool                     A_flag      = cargs.getBooleanArg   ("-A");
  bool                     a_flag      = cargs.getBooleanArg   ("-a");
  bool                     d_flag      = cargs.getBooleanArg   ("-d");
  bool                     e_flag      = cargs.getBooleanArg   ("-e");
  bool                     v_flag      = cargs.getBooleanArg   ("-v");
  std::string              ofilename   = cargs.getStringArg    ("-o");
  std::vector<std::string> labels      = cargs.getStringListArg("-L");
  uint                     org         = cargs.getIntegerArg   ("-org");
  bool                     dump_flag   = cargs.getBooleanArg   ("-dump");
  bool                     undump_flag = cargs.getBooleanArg   ("-undump");
  bool                     bin_flag    = cargs.getBooleanArg   ("-bin");
  bool                     stream_flag = cargs.getBooleanArg   ("-stream");
  bool                     icount_flag = cargs.getBooleanArg   ("-icount");
  bool                     dsym_flag   = cargs.getBooleanArg   ("-dsym");

  if (dump_flag)
    z80.setDump(true);

  CZ80TestTrace trace(z80, v_flag);

  z80.setVerbose(v_flag);

  z80.addTrace(&trace);

  CZ80StdRstData rst_data(z80);

  z80.setRstData(&rst_data);

  if (A_flag) {
    z80.assembleAll(0x1000);
    return 0;
  }

  std::vector<std::string>::iterator p1 = labels.begin();
  std::vector<std::string>::iterator p2 = labels.end  ();

  for ( ; p1 != p2; ++p1) {
    std::string::size_type pos = (*p1).find('=');

    if (pos == std::string::npos) {
      std::cerr << "Invalid Label Define " << *p1 << std::endl;
      continue;
    }

    std::string lhs = (*p1).substr(0, pos);
    std::string rhs = (*p1).substr(pos + 1);

    uint i;

    if (rhs.size() > 2 &&
        (rhs.substr(0, 2) == "0x" || rhs.substr(0, 2) == "0X")) {
      if (! CStrUtil::decodeHexString(rhs.substr(2), &i)) {
        std::cerr << "Invalid Label Define " << *p1 << std::endl;
        continue;
      }
    }
    else {
      if (! CStrUtil::toInteger(rhs, &i)) {
        std::cerr << "Invalid Label Define " << *p1 << std::endl;
        continue;
      }
    }

    z80.setLabelValue(lhs, i);
  }

  if (icount_flag)
    new CZ80AtExit(&z80);

  for (int i = 1; i < argc; ++i) {
    CFile file(argv[i]);

    if (! file.exists() && ! file.isRegular()) {
      std::cerr << "Invalid File: " << argv[i] << std::endl;
      continue;
    }

    if      (undump_flag)
      z80.undump(&file);
    else if (a_flag && e_flag) {
      CTempFile tfile;

      if (! z80.assemble(&file, tfile.getFile()))
        exit(1);

      z80.load(tfile.getFile());

      z80.execute();
    }
    else if (a_flag) {
      z80.setAssembleStream(stream_flag);

      if (ofilename != "") {
        CFile ofile(ofilename);

        if (! z80.assemble(&file, &ofile))
          exit(1);
      }
      else {
        if (! z80.assemble(&file))
          exit(1);
      }

      if (dsym_flag)
        z80.assembleDumpSymbols();
    }
    else if (d_flag) {
      ushort pos = org;
      ushort len = 0;

      if (bin_flag) {
        z80.loadBin(&file, &pos, &len);

        z80.disassemble(pos, len);
      }
      else {
        z80.load(&file);

        z80.disassemble();
      }
    }
    else if (e_flag) {
      if (bin_flag)
        z80.loadBin(&file);
      else
        z80.load(&file);

      z80.execute();
    }
  }

  return 0;
}
