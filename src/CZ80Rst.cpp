#include <CZ80Rst.h>

void
CZ80StdRstData::
rst(ushort id)
{
  switch (id) {
    case 0x18: { // SCAL
      ushort pc = z80.pop();

      uchar id1 = z80.getByte(pc++);

      switch (id1) {
        case 0x80: { // PRINT_A
          std::cout << "A = " << CStrUtil::toHexString(z80.getA(), 2);
          if (newline_) std::cout << std::endl;
          break;
        }
        case 0x81: { // PRINT_B
          std::cout << "B = " << CStrUtil::toHexString(z80.getB(), 2);
          if (newline_) std::cout << std::endl;
          break;
        }
        case 0x82: { // PRINT_C
          std::cout << "C = " << CStrUtil::toHexString(z80.getC(), 2);
          if (newline_) std::cout << std::endl;
          break;
        }
        case 0x83: { // PRINT_D
          std::cout << "D = " << CStrUtil::toHexString(z80.getD(), 2);
          if (newline_) std::cout << std::endl;
          break;
        }
        case 0x84: { // PRINT_E
          std::cout << "E = " << CStrUtil::toHexString(z80.getE(), 2);
          if (newline_) std::cout << std::endl;
          break;
        }
        case 0x85: { // PRINT_H
          std::cout << "H = " << CStrUtil::toHexString(z80.getH(), 2);
          if (newline_) std::cout << std::endl;
          break;
        }
        case 0x86: { // PRINT_L
          std::cout << "L = " << CStrUtil::toHexString(z80.getL(), 2);
          if (newline_) std::cout << std::endl;
          break;
        }
        case 0x87: { // PRINT_FLAGS
          std::cout << "Flags = " << z80.getFlagsString();
          if (newline_) std::cout << std::endl;
          break;
        }
        case 0x88: { // PRINT_F
          std::cout << "F = " << CStrUtil::toHexString(z80.getF(), 2);
          if (newline_) std::cout << std::endl;
          break;
        }
        case 0x89: { // PRINT_FZ
          std::cout << "Z = " << (int) z80.tstZFlag();
          if (newline_) std::cout << std::endl;
          break;
        }

        case 0x90: { // PRINT_AF
          std::cout << "AF = " << CStrUtil::toHexString(z80.getAF(), 4);
          if (newline_) std::cout << std::endl;
          break;
        }
        case 0x91: { // PRINT_BC
          std::cout << "BC = " << CStrUtil::toHexString(z80.getBC(), 4);
          if (newline_) std::cout << std::endl;
          break;
        }
        case 0x92: { // PRINT_DE
          std::cout << "DE = " << CStrUtil::toHexString(z80.getDE(), 4);
          if (newline_) std::cout << std::endl;
          break;
        }
        case 0x93: { // PRINT_HL
          std::cout << "HL = " << CStrUtil::toHexString(z80.getHL(), 4);
          if (newline_) std::cout << std::endl;
          break;
        }
        case 0x94: { // PRINT_IX
          std::cout << "IX = " << CStrUtil::toHexString(z80.getIX(), 4);
          if (newline_) std::cout << std::endl;
          break;
        }
        case 0x95: { // PRINT_IY
          std::cout << "IY = " << CStrUtil::toHexString(z80.getIY(), 4);
          if (newline_) std::cout << std::endl;
          break;
        }
        case 0x96: { // PRINT_SP
          std::cout << "SP = " << CStrUtil::toHexString(z80.getSP(), 4);
          if (newline_) std::cout << std::endl;
          break;
        }
        case 0x97: { // PRINT_PC
          std::cout << "PC = " << CStrUtil::toHexString(z80.getPC(), 4);
          if (newline_) std::cout << std::endl;
          break;
        }
        case 0x98: { // PRINT_PHL
          std::cout << "(HL) = " << CStrUtil::toHexString(z80.getPHL(), 2);
          if (newline_) std::cout << std::endl;
          break;
        }
        case 0x99: { // PRINT_PO_IX
          short o = (short) z80.getByte(pc); pc += 1;

          std::cout << "(IX+" << o << ") = " << CStrUtil::toHexString(z80.getPOIX(o), 2);
          if (newline_) std::cout << std::endl;

          break;
        }
        case 0x9A: { // PRINT_PO_IY
          short o = (short) z80.getByte(pc); pc += 1;

          std::cout << "(IY+" << o << ") = " << CStrUtil::toHexString(z80.getPOIY(o), 2);
          if (newline_) std::cout << std::endl;

          break;
        }

        case 0xA0: { // PRINT_BYTE
          ushort a = z80.getWord(pc); pc += 2;
          uchar  d = z80.getByte(a );

          std::cout << CStrUtil::toHexString(a, 4) << " = " << CStrUtil::toHexString(d, 2);
          if (newline_) std::cout << std::endl;

          break;
        }
        case 0xA1: { // PRINT_WORD
          ushort a = z80.getWord(pc); pc += 2;
          ushort d = z80.getWord(a );

          std::cout << CStrUtil::toHexString(a, 4) << " = " << CStrUtil::toHexString(d, 4);
          if (newline_) std::cout << std::endl;

          break;
        }
        case 0xA2: { // PRINT_N_BYTE
          ushort a = z80.getWord(pc); pc += 2;
          ushort n = z80.getWord(pc); pc += 2;

          std::cout << CStrUtil::toHexString(a, 4) << " =";

          for (uint i = 0; i < n; ++i) {
            uchar d = z80.getByte(a + i);

            std::cout << " " << CStrUtil::toHexString(d, 2);
          }

          if (newline_) std::cout << std::endl;

          break;
        }
        case 0xA3: { // PRINT_N_WORD
          ushort a = z80.getWord(pc); pc += 2;
          ushort n = z80.getWord(pc); pc += 2;

          std::cout << CStrUtil::toHexString(a, 4) << " =";

          for (uint i = 0; i < n; ++i) {
            ushort d = z80.getWord(a + 2*i);

            std::cout << " " << CStrUtil::toHexString(d, 4);
          }

          if (newline_) std::cout << std::endl;

          break;
        }
        case 0xA4: { // PRINT_VALUE
          ushort a = z80.getWord(pc); pc += 2;

          std::cout << CStrUtil::toHexString(a, 4);

          if (newline_) std::cout << std::endl;

          break;
        }

        case 0xA5: { // PRINT_STRING
          uchar c = z80.getByte(pc++);

          while (c != '\0') {
            std::cout << c;

            c = z80.getByte(pc++);
          }

          if (newline_) std::cout << std::endl;

          break;
        }

        case 0xA6: { // PRINT_A_CHAR
          std::cout << (char) z80.getA();

          std::cout.flush();

          break;
        }

        case 0xB0: { // CMP_A
          ushort a1 = z80.getByte(pc); pc += 1;
          ushort a2 = z80.getA();

          if (a1 != a2)
            std::cerr << "Error " << CStrUtil::toHexString(a1, 2) << " != " <<
                                     CStrUtil::toHexString(a2, 2) << std::endl;

          break;
        }
        case 0xB1: { // CMP_B
          ushort b1 = z80.getByte(pc); pc += 1;
          ushort b2 = z80.getB();

          if (b1 != b2)
            std::cerr << "Error " << CStrUtil::toHexString(b1, 2) << " != " <<
                                     CStrUtil::toHexString(b2, 2) << std::endl;

          break;
        }
        case 0xB2: { // CMP_C
          ushort c1 = z80.getByte(pc); pc += 1;
          ushort c2 = z80.getC();

          if (c1 != c2)
            std::cerr << "Error " << CStrUtil::toHexString(c1, 2) << " != " <<
                                     CStrUtil::toHexString(c2, 2) << std::endl;

          break;
        }
        case 0xB3: { // CMP_D
          ushort d1 = z80.getByte(pc); pc += 1;
          ushort d2 = z80.getD();

          if (d1 != d2)
            std::cerr << "Error " << CStrUtil::toHexString(d1, 2) << " != " <<
                                     CStrUtil::toHexString(d2, 2) << std::endl;

          break;
        }
        case 0xB4: { // CMP_E
          ushort e1 = z80.getByte(pc); pc += 1;
          ushort e2 = z80.getE();

          if (e1 != e2)
            std::cerr << "Error " << CStrUtil::toHexString(e1, 2) << " != " <<
                                     CStrUtil::toHexString(e2, 2) << std::endl;

          break;
        }
        case 0xB5: { // CMP_H
          ushort h1 = z80.getByte(pc); pc += 1;
          ushort h2 = z80.getH();

          if (h1 != h2)
            std::cerr << "Error " << CStrUtil::toHexString(h1, 2) << " != " <<
                                     CStrUtil::toHexString(h2, 2) << std::endl;

          break;
        }
        case 0xB6: { // CMP_L
          ushort l1 = z80.getByte(pc); pc += 1;
          ushort l2 = z80.getL();

          if (l1 != l2)
            std::cerr << "Error " << CStrUtil::toHexString(l1, 2) << " != " <<
                                     CStrUtil::toHexString(l2, 2) << std::endl;

          break;
        }

        case 0xC0: { // CMP_AF
          ushort af1 = z80.getWord(pc); pc += 2;
          ushort af2 = z80.getAF();

          if (af2 != af1)
            std::cerr << "Error " << CStrUtil::toHexString(af1, 4) << " != " <<
                                     CStrUtil::toHexString(af2, 4) << std::endl;

          break;
        }
        case 0xC1: { // CMP_BC
          ushort bc1 = z80.getWord(pc); pc += 2;
          ushort bc2 = z80.getBC();

          if (bc2 != bc1)
            std::cerr << "Error " << CStrUtil::toHexString(bc1, 4) << " != " <<
                                     CStrUtil::toHexString(bc2, 4) << std::endl;

          break;
        }
        case 0xC2: { // CMP_DE
          ushort de1 = z80.getWord(pc); pc += 2;
          ushort de2 = z80.getDE();

          if (de2 != de1)
            std::cerr << "Error " << CStrUtil::toHexString(de1, 4) << " != " <<
                                     CStrUtil::toHexString(de2, 4) << std::endl;

          break;
        }
        case 0xC3: { // CMP_HL
          ushort hl1 = z80.getWord(pc); pc += 2;
          ushort hl2 = z80.getHL();

          if (hl2 != hl1)
            std::cerr << "Error " << CStrUtil::toHexString(hl1, 4) << " != " <<
                                     CStrUtil::toHexString(hl2, 4) << std::endl;

          break;
        }
        case 0xC4: { // CMP_IX
          ushort ix1 = z80.getWord(pc); pc += 2;
          ushort ix2 = z80.getIX();

          if (ix2 != ix1)
            std::cerr << "Error " << CStrUtil::toHexString(ix1, 4) << " != " <<
                                     CStrUtil::toHexString(ix2, 4) << std::endl;

          break;
        }
        case 0xC5: { // CMP_IY
          ushort iy1 = z80.getWord(pc); pc += 2;
          ushort iy2 = z80.getIY();

          if (iy2 != iy1)
            std::cerr << "Error " << CStrUtil::toHexString(iy1, 4) << " != " <<
                                     CStrUtil::toHexString(iy2, 4) << std::endl;

          break;
        }
        case 0xC6: { // CMP_SP
          ushort a = z80.getWord(pc); pc += 2;
          ushort d = z80.getWord(a );

          if (z80.getSP() != d) std::cerr << "Error" << std::endl;

          break;
        }

        case 0xD0: { // CMP_PBYTE
          ushort pw = z80.getWord(pc); pc += 2;
          uchar  b1 = z80.getByte(pw);
          uchar  b2 = z80.getByte(pc); pc += 1;

          if (b1 != b2)
            std::cerr << "Error " << CStrUtil::toHexString(b1, 2) << " != " <<
                                     CStrUtil::toHexString(b2, 2) << std::endl;

          break;
        }
        case 0xD1: { // CMP_PWORD
          ushort pw = z80.getWord(pc); pc += 2;
          uchar  w1 = z80.getWord(pw);
          uchar  w2 = z80.getWord(pc); pc += 2;

          if (w1 != w2)
            std::cerr << "Error " << CStrUtil::toHexString(w1, 4) << " != " <<
                                     CStrUtil::toHexString(w2, 4) << std::endl;

          break;
        }

        case 0xFF: { // CONFIG
          std::string str;

          uchar c = z80.getByte(pc++);

          while (c != '\0') {
            str += c;

            c = z80.getByte(pc++);
          }

          if      (CStrUtil::casecmp(str, "nonewline") == 0)
            newline_ = false;
          else if (CStrUtil::casecmp(str, "nonewline") == 0)
            newline_ = true;

          break;
        }

        default: {
          pc--;

          z80.push(pc);

          rstFwd(id);

          break;
        }
      }

      z80.push(pc);

      break;
    }
    default: {
      rstFwd(id);

      break;
    }
  }
}
