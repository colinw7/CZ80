#include <CZ80.h>
#include <CZ80Trace.h>
#include <CZ80OpData.h>
#include <CZ80PortData.h>
#include <CZ80RstData.h>

#include <CArgs.h>
#include <CTempFile.h>
#include <CAtExit.h>
#include <CStrUtil.h>

struct CZ80TestTrace : public CZ80Trace {
  bool verbose;

  CZ80TestTrace(CZ80 &z80_, bool verbose_) :
    CZ80Trace(z80_), verbose(verbose_) {
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

      op_data.printStr(z80.getPC(), std::cout);

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

class CPMPortData : public CZ80PortData {
 public:
  CPMPortData(CZ80 &z80_) :
   CZ80PortData(z80_) {
  }

  uchar in(uchar port, uchar qual) override {
    if (port == 0) {
      uchar c = z80.getC();

      if      (c == 2) {
        uchar e = z80.getE();

        std::cerr << char(e);
      }
      else if (c == 9) {
        ushort de = z80.getDE();

        for (int i = 0; ; ++i) {
          char c1 = z80.getByte(ushort(de + i));

          if (c1 == '$')
            break;

          std::cerr << c1;
        }
      }
    }
    else
      std::cerr << std::hex << int(port) << " " << std::hex << int(qual) << std::endl;

    return 0;
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
              "-cpm:f    (run as cpm) "
              );

  cargs.parse(&argc, argv);

  auto A_flag      = cargs.getBooleanArg   ("-A");
  auto a_flag      = cargs.getBooleanArg   ("-a");
  auto d_flag      = cargs.getBooleanArg   ("-d");
  auto e_flag      = cargs.getBooleanArg   ("-e");
  auto v_flag      = cargs.getBooleanArg   ("-v");
  auto ofilename   = cargs.getStringArg    ("-o");
  auto labels      = cargs.getStringListArg("-L");
  auto org         = uint(cargs.getIntegerArg("-org"));
  auto dump_flag   = cargs.getBooleanArg   ("-dump");
  auto undump_flag = cargs.getBooleanArg   ("-undump");
  auto bin_flag    = cargs.getBooleanArg   ("-bin");
  auto stream_flag = cargs.getBooleanArg   ("-stream");
  auto icount_flag = cargs.getBooleanArg   ("-icount");
  auto dsym_flag   = cargs.getBooleanArg   ("-dsym");
  auto cpm_flag    = cargs.getBooleanArg   ("-cpm");

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

  for (const auto &label : labels) {
    auto pos = label.find('=');

    if (pos == std::string::npos) {
      std::cerr << "Invalid Label Define " << label << "\n";
      continue;
    }

    auto lhs = label.substr(0, pos);
    auto rhs = label.substr(pos + 1);

    uint i;

    if (rhs.size() > 2 &&
        (rhs.substr(0, 2) == "0x" || rhs.substr(0, 2) == "0X")) {
      if (! CStrUtil::decodeHexString(rhs.substr(2), &i)) {
        std::cerr << "Invalid Label Define " << label << "\n";
        continue;
      }
    }
    else {
      if (! CStrUtil::toInteger(rhs, &i)) {
        std::cerr << "Invalid Label Define " << label << "\n";
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
      std::cerr << "Invalid File: " << argv[i] << "\n";
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
      ushort pos = ushort(org);
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
    else if (cpm_flag) {
      z80.setLoadPos(0x100);

      z80.loadBin(&file);

      z80.setByte(0, 0xd3);
      z80.setByte(1, 0x00);

      z80.setByte(5, 0xdb);
      z80.setByte(6, 0x00);
      z80.setByte(7, 0xc9);

      z80.setAllowInterrupts(false);

      CPMPortData cpm_data(z80);

      z80.setPortData(&cpm_data);

      z80.execute();
    }
  }

  return 0;
}
