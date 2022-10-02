#include <CZ80Fn.h>
#include <CZ80OpData.h>
#include <cassert>

//#define OP_DEBUG 1

void
CZ80::
f_adc_a_a(CZ80OpData *opData)
{
  opData->z80->adcA(opData->z80->getA());
}

void
CZ80::
f_adc_a_b(CZ80OpData *opData)
{
  opData->z80->adcA(opData->z80->getB());
}

void
CZ80::
f_adc_a_c(CZ80OpData *opData)
{
  opData->z80->adcA(opData->z80->getC());
}

void
CZ80::
f_adc_a_d(CZ80OpData *opData)
{
  opData->z80->adcA(opData->z80->getD());
}

void
CZ80::
f_adc_a_e(CZ80OpData *opData)
{
  opData->z80->adcA(opData->z80->getE());
}

void
CZ80::
f_adc_a_h(CZ80OpData *opData)
{
  opData->z80->adcA(opData->z80->getH());
}

void
CZ80::
f_adc_a_l(CZ80OpData *opData)
{
  opData->z80->adcA(opData->z80->getL());
}

void
CZ80::
f_adc_a_ixh(CZ80OpData *opData)
{
  opData->z80->adcA(opData->z80->getIXH());
}

void
CZ80::
f_adc_a_ixl(CZ80OpData *opData)
{
  opData->z80->adcA(opData->z80->getIXL());
}

void
CZ80::
f_adc_a_iyh(CZ80OpData *opData)
{
  opData->z80->adcA(opData->z80->getIYH());
}

void
CZ80::
f_adc_a_iyl(CZ80OpData *opData)
{
  opData->z80->adcA(opData->z80->getIYL());
}

void
CZ80::
f_adc_a_p_hl(CZ80OpData *opData)
{
  opData->z80->adcA(opData->z80->getPHL());
}

void
CZ80::
f_adc_a_n(CZ80OpData *opData)
{
  opData->z80->adcA(opData->getUByte2());
}

void
CZ80::
f_adc_a_po_ix(CZ80OpData *opData)
{
  opData->z80->adcA(opData->getPOIX2());
}

void
CZ80::
f_adc_a_po_iy(CZ80OpData *opData)
{
  opData->z80->adcA(opData->getPOIY2());
}

void
CZ80::
f_adc_hl_bc(CZ80OpData *opData)
{
  opData->z80->adcHL(opData->z80->getBC());
}

void
CZ80::
f_adc_hl_de(CZ80OpData *opData)
{
  opData->z80->adcHL(opData->z80->getDE());
}

void
CZ80::
f_adc_hl_hl(CZ80OpData *opData)
{
  opData->z80->adcHL(opData->z80->getHL());
}

void
CZ80::
f_adc_hl_sp(CZ80OpData *opData)
{
  opData->z80->adcHL(opData->z80->getSP());
}

void
CZ80::
f_add_a_a(CZ80OpData *opData)
{
  opData->z80->addA(opData->z80->getA());
}

void
CZ80::
f_add_a_b(CZ80OpData *opData)
{
  opData->z80->addA(opData->z80->getB());
}

void
CZ80::
f_add_a_c(CZ80OpData *opData)
{
  opData->z80->addA(opData->z80->getC());
}

void
CZ80::
f_add_a_d(CZ80OpData *opData)
{
  opData->z80->addA(opData->z80->getD());
}

void
CZ80::
f_add_a_e(CZ80OpData *opData)
{
  opData->z80->addA(opData->z80->getE());
}

void
CZ80::
f_add_a_h(CZ80OpData *opData)
{
  opData->z80->addA(opData->z80->getH());
}

void
CZ80::
f_add_a_l(CZ80OpData *opData)
{
  opData->z80->addA(opData->z80->getL());
}

void
CZ80::
f_add_a_ixh(CZ80OpData *opData)
{
  opData->z80->addA(opData->z80->getIXH());
}

void
CZ80::
f_add_a_ixl(CZ80OpData *opData)
{
  opData->z80->addA(opData->z80->getIXL());
}

void
CZ80::
f_add_a_iyh(CZ80OpData *opData)
{
  opData->z80->addA(opData->z80->getIYH());
}

void
CZ80::
f_add_a_iyl(CZ80OpData *opData)
{
  opData->z80->addA(opData->z80->getIYL());
}

void
CZ80::
f_add_a_p_hl(CZ80OpData *opData)
{
  opData->z80->addA(opData->z80->getPHL());
}

void
CZ80::
f_add_a_n(CZ80OpData *opData)
{
  opData->z80->addA(opData->getUByte2());
}

void
CZ80::
f_add_a_po_ix(CZ80OpData *opData)
{
  opData->z80->addA(opData->getPOIX2());
}

void
CZ80::
f_add_a_po_iy(CZ80OpData *opData)
{
  opData->z80->addA(opData->getPOIY2());
}

void
CZ80::
f_add_hl_bc(CZ80OpData *opData)
{
  opData->z80->addHL(opData->z80->getBC());
}

void
CZ80::
f_add_hl_de(CZ80OpData *opData)
{
  opData->z80->addHL(opData->z80->getDE());
}

void
CZ80::
f_add_hl_hl(CZ80OpData *opData)
{
  opData->z80->addHL(opData->z80->getHL());
}

void
CZ80::
f_add_hl_sp(CZ80OpData *opData)
{
  opData->z80->addHL(opData->z80->getSP());
}

void
CZ80::
f_add_ix_bc(CZ80OpData *opData)
{
  opData->z80->addIX(opData->z80->getBC());
}

void
CZ80::
f_add_ix_de(CZ80OpData *opData)
{
  opData->z80->addIX(opData->z80->getDE());
}

void
CZ80::
f_add_ix_ix(CZ80OpData *opData)
{
  opData->z80->addIX(opData->z80->getIX());
}

void
CZ80::
f_add_ix_sp(CZ80OpData *opData)
{
  opData->z80->addIX(opData->z80->getSP());
}

void
CZ80::
f_add_iy_bc(CZ80OpData *opData)
{
  opData->z80->addIY(opData->z80->getBC());
}

void
CZ80::
f_add_iy_de(CZ80OpData *opData)
{
  opData->z80->addIY(opData->z80->getDE());
}

void
CZ80::
f_add_iy_iy(CZ80OpData *opData)
{
  opData->z80->addIY(opData->z80->getIY());
}

void
CZ80::
f_add_iy_sp(CZ80OpData *opData)
{
  opData->z80->addIY(opData->z80->getSP());
}

void
CZ80::
f_and_a(CZ80OpData *opData)
{
  opData->z80->andA(opData->z80->getA());
}

void
CZ80::
f_and_b(CZ80OpData *opData)
{
  opData->z80->andA(opData->z80->getB());
}

void
CZ80::
f_and_c(CZ80OpData *opData)
{
  opData->z80->andA(opData->z80->getC());
}

void
CZ80::
f_and_d(CZ80OpData *opData)
{
  opData->z80->andA(opData->z80->getD());
}

void
CZ80::
f_and_e(CZ80OpData *opData)
{
  opData->z80->andA(opData->z80->getE());
}

void
CZ80::
f_and_h(CZ80OpData *opData)
{
  opData->z80->andA(opData->z80->getH());
}

void
CZ80::
f_and_l(CZ80OpData *opData)
{
  opData->z80->andA(opData->z80->getL());
}

void
CZ80::
f_and_ixh(CZ80OpData *opData)
{
  opData->z80->andA(opData->z80->getIXH());
}

void
CZ80::
f_and_ixl(CZ80OpData *opData)
{
  opData->z80->andA(opData->z80->getIXL());
}

void
CZ80::
f_and_iyh(CZ80OpData *opData)
{
  opData->z80->andA(opData->z80->getIYH());
}

void
CZ80::
f_and_iyl(CZ80OpData *opData)
{
  opData->z80->andA(opData->z80->getIYL());
}

void
CZ80::
f_and_p_hl(CZ80OpData *opData)
{
  opData->z80->andA(opData->z80->getPHL());
}

void
CZ80::
f_and_n(CZ80OpData *opData)
{
  opData->z80->andA(opData->getUByte1());
}

void
CZ80::
f_and_po_ix(CZ80OpData *opData)
{
  opData->z80->andA(opData->getPOIX1());
}

void
CZ80::
f_and_po_iy(CZ80OpData *opData)
{
  opData->z80->andA(opData->getPOIY1());
}

void
CZ80::
f_bit_a_n(CZ80OpData *opData)
{
  opData->z80->tstBitA(uchar(opData->op->arg1));
}

void
CZ80::
f_bit_b_n(CZ80OpData *opData)
{
  opData->z80->tstBitB(uchar(opData->op->arg1));
}

void
CZ80::
f_bit_c_n(CZ80OpData *opData)
{
  opData->z80->tstBitC(uchar(opData->op->arg1));
}

void
CZ80::
f_bit_d_n(CZ80OpData *opData)
{
  opData->z80->tstBitD(uchar(opData->op->arg1));
}

void
CZ80::
f_bit_e_n(CZ80OpData *opData)
{
  opData->z80->tstBitE(uchar(opData->op->arg1));
}

void
CZ80::
f_bit_h_n(CZ80OpData *opData)
{
  opData->z80->tstBitH(uchar(opData->op->arg1));
}

void
CZ80::
f_bit_l_n(CZ80OpData *opData)
{
  opData->z80->tstBitL(uchar(opData->op->arg1));
}

void
CZ80::
f_bit_p_hl_n(CZ80OpData *opData)
{
  opData->z80->tstBitPHL(uchar(opData->op->arg1));
}

void
CZ80::
f_bit_po_ix_n(CZ80OpData *opData)
{
  opData->z80->tstBitPOIX(opData->getSByte2(), uchar(opData->op->arg1), false);
}

void
CZ80::
f_bit_po_ix_ns(CZ80OpData *opData)
{
  opData->z80->tstBitPOIX(opData->getSByte2(), uchar(opData->op->arg1), true);
}

void
CZ80::
f_bit_po_iy_n(CZ80OpData *opData)
{
  opData->z80->tstBitPOIY(opData->getSByte2(), uchar(opData->op->arg1), false);
}

void
CZ80::
f_bit_po_iy_ns(CZ80OpData *opData)
{
  opData->z80->tstBitPOIY(opData->getSByte2(), uchar(opData->op->arg1), true);
}

void
CZ80::
f_call(CZ80OpData *opData)
{
  opData->tracePC(opData->getUWord1());

  opData->z80->call(opData->getUWord1());
}

void
CZ80::
f_call_z(CZ80OpData *opData)
{
  if (opData->z80->tstZFlag()) {
    opData->tracePC(opData->getUWord2());

    opData->z80->call(opData->getUWord2());

    opData->z80->incT(7);
  }
}

void
CZ80::
f_call_nz(CZ80OpData *opData)
{
  if (! opData->z80->tstZFlag()) {
    opData->tracePC(opData->getUWord2());

    opData->z80->call(opData->getUWord2());

    opData->z80->incT(7);
  }
}

void
CZ80::
f_call_c(CZ80OpData *opData)
{
  if (opData->z80->tstCFlag()) {
    opData->tracePC(opData->getUWord2());

    opData->z80->call(opData->getUWord2());

    opData->z80->incT(7);
  }
}

void
CZ80::
f_call_nc(CZ80OpData *opData)
{
  if (! opData->z80->tstCFlag()) {
    opData->tracePC(opData->getUWord2());

    opData->z80->call(opData->getUWord2());

    opData->z80->incT(7);
  }
}

void
CZ80::
f_call_pe(CZ80OpData *opData)
{
  if (opData->z80->tstPFlag()) {
    opData->tracePC(opData->getUWord2());

    opData->z80->call(opData->getUWord2());

    opData->z80->incT(7);
  }
}

void
CZ80::
f_call_po(CZ80OpData *opData)
{
  if (! opData->z80->tstPFlag()) {
    opData->tracePC(opData->getUWord2());

    opData->z80->call(opData->getUWord2());

    opData->z80->incT(7);
  }
}

void
CZ80::
f_call_p(CZ80OpData *opData)
{
  if (! opData->z80->tstSFlag()) {
    opData->tracePC(opData->getUWord2());

    opData->z80->call(opData->getUWord2());

    opData->z80->incT(7);
  }
}

void
CZ80::
f_call_m(CZ80OpData *opData)
{
  if (opData->z80->tstSFlag()) {
    opData->tracePC(opData->getUWord2());

    opData->z80->call(opData->getUWord2());

    opData->z80->incT(7);
  }
}

void
CZ80::
f_ccf(CZ80OpData *opData)
{
  opData->z80->ccf();
}

void
CZ80::
f_cp_a(CZ80OpData *opData)
{
  opData->z80->cpA(opData->z80->getA());
}

void
CZ80::
f_cp_b(CZ80OpData *opData)
{
  opData->z80->cpA(opData->z80->getB());
}

void
CZ80::
f_cp_c(CZ80OpData *opData)
{
  opData->z80->cpA(opData->z80->getC());
}

void
CZ80::
f_cp_d(CZ80OpData *opData)
{
  opData->z80->cpA(opData->z80->getD());
}

void
CZ80::
f_cp_e(CZ80OpData *opData)
{
  opData->z80->cpA(opData->z80->getE());
}

void
CZ80::
f_cp_h(CZ80OpData *opData)
{
  opData->z80->cpA(opData->z80->getH());
}

void
CZ80::
f_cp_l(CZ80OpData *opData)
{
  opData->z80->cpA(opData->z80->getL());
}

void
CZ80::
f_cp_ixh(CZ80OpData *opData)
{
  opData->z80->cpA(opData->z80->getIXH());
}

void
CZ80::
f_cp_ixl(CZ80OpData *opData)
{
  opData->z80->cpA(opData->z80->getIXL());
}

void
CZ80::
f_cp_iyh(CZ80OpData *opData)
{
  opData->z80->cpA(opData->z80->getIYH());
}

void
CZ80::
f_cp_iyl(CZ80OpData *opData)
{
  opData->z80->cpA(opData->z80->getIYL());
}

void
CZ80::
f_cp_p_hl(CZ80OpData *opData)
{
  opData->z80->cpA(opData->z80->getPHL());
}

void
CZ80::
f_cp_n(CZ80OpData *opData)
{
  opData->z80->cpA(opData->getUByte1());
}

void
CZ80::
f_cp_po_ix(CZ80OpData *opData)
{
  opData->z80->cpA(opData->getPOIX1());
}

void
CZ80::
f_cp_po_iy(CZ80OpData *opData)
{
  opData->z80->cpA(opData->getPOIY1());
}

void
CZ80::
f_cpd(CZ80OpData *opData)
{
  opData->z80->cpd();
}

void
CZ80::
f_cpdr(CZ80OpData *opData)
{
  opData->z80->cpdr();
}

void
CZ80::
f_cpi(CZ80OpData *opData)
{
  opData->z80->cpi();
}

void
CZ80::
f_cpir(CZ80OpData *opData)
{
  opData->z80->cpir();
}

void
CZ80::
f_cpl(CZ80OpData *opData)
{
  opData->z80->cpl();
}

void
CZ80::
f_daa(CZ80OpData *opData)
{
  opData->z80->daa();
}

void
CZ80::
f_dec_a(CZ80OpData *opData)
{
  opData->z80->decA();
}

void
CZ80::
f_dec_b(CZ80OpData *opData)
{
  opData->z80->decB();
}

void
CZ80::
f_dec_c(CZ80OpData *opData)
{
  opData->z80->decC();
}

void
CZ80::
f_dec_d(CZ80OpData *opData)
{
  opData->z80->decD();
}

void
CZ80::
f_dec_e(CZ80OpData *opData)
{
  opData->z80->decE();
}

void
CZ80::
f_dec_h(CZ80OpData *opData)
{
  opData->z80->decH();
}

void
CZ80::
f_dec_l(CZ80OpData *opData)
{
  opData->z80->decL();
}

void
CZ80::
f_dec_p_hl(CZ80OpData *opData)
{
  opData->z80->decPHL();
}

void
CZ80::
f_dec_po_ix(CZ80OpData *opData)
{
  opData->z80->decPOIX(opData->getSByte1());
}

void
CZ80::
f_dec_po_iy(CZ80OpData *opData)
{
  opData->z80->decPOIY(opData->getSByte1());
}

void
CZ80::
f_dec_bc(CZ80OpData *opData)
{
  opData->z80->decBC();
}

void
CZ80::
f_dec_de(CZ80OpData *opData)
{
  opData->z80->decDE();
}

void
CZ80::
f_dec_hl(CZ80OpData *opData)
{
  opData->z80->decHL();
}

void
CZ80::
f_dec_sp(CZ80OpData *opData)
{
  opData->z80->decSP();
}

void
CZ80::
f_dec_ix(CZ80OpData *opData)
{
  opData->z80->decIX();
}

void
CZ80::
f_dec_iy(CZ80OpData *opData)
{
  opData->z80->decIY();
}

void
CZ80::
f_dec_ixh(CZ80OpData *opData)
{
  opData->z80->decIXH();
}

void
CZ80::
f_dec_ixl(CZ80OpData *opData)
{
  opData->z80->decIXL();
}

void
CZ80::
f_dec_iyh(CZ80OpData *opData)
{
  opData->z80->decIYH();
}

void
CZ80::
f_dec_iyl(CZ80OpData *opData)
{
  opData->z80->decIYL();
}

void
CZ80::
f_di(CZ80OpData *opData)
{
  opData->z80->di();
}

void
CZ80::
f_djnz(CZ80OpData *opData)
{
  opData->z80->decB();

  if (! opData->z80->tstZFlag()) {
    opData->tracePC(opData->getRPC1());

    opData->z80->setPC(opData->getRPC1());

    opData->z80->incT(5);
  }
}

void
CZ80::
f_ei(CZ80OpData *opData)
{
  opData->z80->ei();
}

void
CZ80::
f_ex_de_hl(CZ80OpData *opData)
{
  opData->z80->ex_de_hl();
}

void
CZ80::
f_ex_af_af1(CZ80OpData *opData)
{
  opData->z80->ex_af_af1();
}

void
CZ80::
f_ex_p_sp_hl(CZ80OpData *opData)
{
  opData->z80->ex_p_sp_hl();
}

void
CZ80::
f_ex_p_sp_ix(CZ80OpData *opData)
{
  opData->z80->ex_p_sp_ix();
}

void
CZ80::
f_ex_p_sp_iy(CZ80OpData *opData)
{
  opData->z80->ex_p_sp_iy();
}

void
CZ80::
f_exx(CZ80OpData *opData)
{
  opData->z80->exx();
}

void
CZ80::
f_halt(CZ80OpData *opData)
{
  opData->z80->halt();
}

void
CZ80::
f_im_n(CZ80OpData *opData)
{
  opData->z80->setIM(uchar(opData->op->arg1));
}

//-----------

void
CZ80::
f_in_a_p_n(CZ80OpData *opData)
{
  opData->z80->setA(opData->z80->in(opData->getUByte2(), 0));
}

void
CZ80::
f_in_a_p_c(CZ80OpData *opData)
{
  opData->z80->setA(opData->z80->inC());
}

void
CZ80::
f_in_b_p_c(CZ80OpData *opData)
{
  opData->z80->setB(opData->z80->inC());
}

void
CZ80::
f_in_c_p_c(CZ80OpData *opData)
{
  opData->z80->setC(opData->z80->inC());
}

void
CZ80::
f_in_d_p_c(CZ80OpData *opData)
{
  opData->z80->setD(opData->z80->inC());
}

void
CZ80::
f_in_e_p_c(CZ80OpData *opData)
{
  opData->z80->setE(opData->z80->inC());
}

void
CZ80::
f_in_h_p_c(CZ80OpData *opData)
{
  opData->z80->setH(opData->z80->inC());
}

void
CZ80::
f_in_l_p_c(CZ80OpData *opData)
{
  opData->z80->setL(opData->z80->inC());
}

void
CZ80::
f_in_n_p_c(CZ80OpData *opData)
{
  opData->z80->inC();
}

//-----------

void
CZ80::
f_inc_a(CZ80OpData *opData)
{
  opData->z80->incA();
}

void
CZ80::
f_inc_b(CZ80OpData *opData)
{
  opData->z80->incB();
}

void
CZ80::
f_inc_c(CZ80OpData *opData)
{
  opData->z80->incC();
}

void
CZ80::
f_inc_d(CZ80OpData *opData)
{
  opData->z80->incD();
}

void
CZ80::
f_inc_e(CZ80OpData *opData)
{
  opData->z80->incE();
}

void
CZ80::
f_inc_h(CZ80OpData *opData)
{
  opData->z80->incH();
}

void
CZ80::
f_inc_l(CZ80OpData *opData)
{
  opData->z80->incL();
}

void
CZ80::
f_inc_p_hl(CZ80OpData *opData)
{
  opData->z80->incPHL();
}

void
CZ80::
f_inc_po_ix(CZ80OpData *opData)
{
  opData->z80->incPOIX(opData->getSByte1());
}

void
CZ80::
f_inc_po_iy(CZ80OpData *opData)
{
  opData->z80->incPOIY(opData->getSByte1());
}

void
CZ80::
f_inc_bc(CZ80OpData *opData)
{
  opData->z80->incBC();
}

void
CZ80::
f_inc_de(CZ80OpData *opData)
{
  opData->z80->incDE();
}

void
CZ80::
f_inc_hl(CZ80OpData *opData)
{
  opData->z80->incHL();
}

void
CZ80::
f_inc_sp(CZ80OpData *opData)
{
  opData->z80->incSP();
}

void
CZ80::
f_inc_ix(CZ80OpData *opData)
{
  opData->z80->incIX();
}

void
CZ80::
f_inc_iy(CZ80OpData *opData)
{
  opData->z80->incIY();
}

void
CZ80::
f_inc_ixh(CZ80OpData *opData)
{
  opData->z80->incIXH();
}

void
CZ80::
f_inc_ixl(CZ80OpData *opData)
{
  opData->z80->incIXL();
}

void
CZ80::
f_inc_iyh(CZ80OpData *opData)
{
  opData->z80->incIYH();
}

void
CZ80::
f_inc_iyl(CZ80OpData *opData)
{
  opData->z80->incIYL();
}

void
CZ80::
f_ind(CZ80OpData *opData)
{
  opData->z80->setPHL(opData->z80->inC());

  opData->z80->decHL();
  opData->z80->decB();
}

void
CZ80::
f_indr(CZ80OpData *opData)
{
  do {
    f_ind(opData);

    opData->z80->incT(21);
  }
  while (opData->z80->getB() != 0);

  opData->z80->decT(5);
}

void
CZ80::
f_ini(CZ80OpData *opData)
{
  opData->z80->setPHL(opData->z80->inC());

  opData->z80->incHL();
  opData->z80->decB();
}

void
CZ80::
f_inir(CZ80OpData *opData)
{
  do {
    f_ini(opData);

    opData->z80->incT(21);
  }
  while (opData->z80->getB() != 0);

  opData->z80->decT(5);
}

void
CZ80::
f_jp(CZ80OpData *opData)
{
  opData->tracePC(opData->getUWord1());

  opData->z80->setPC(opData->getUWord1());
}

void
CZ80::
f_jp_z(CZ80OpData *opData)
{
  if (opData->z80->tstZFlag()) {
    opData->tracePC(opData->getUWord2());

    opData->z80->setPC(opData->getUWord2());
  }
}

void
CZ80::
f_jp_nz(CZ80OpData *opData)
{
  if (! opData->z80->tstZFlag()) {
    opData->tracePC(opData->getUWord2());

    opData->z80->setPC(opData->getUWord2());
  }
}

void
CZ80::
f_jp_c(CZ80OpData *opData)
{
  if (opData->z80->tstCFlag()) {
    opData->tracePC(opData->getUWord2());

    opData->z80->setPC(opData->getUWord2());
  }
}

void
CZ80::
f_jp_nc(CZ80OpData *opData)
{
  if (! opData->z80->tstCFlag()) {
    opData->tracePC(opData->getUWord2());

    opData->z80->setPC(opData->getUWord2());
  }
}

void
CZ80::
f_jp_pe(CZ80OpData *opData)
{
  if (opData->z80->tstPFlag()) {
    opData->tracePC(opData->getUWord2());

    opData->z80->setPC(opData->getUWord2());
  }
}

void
CZ80::
f_jp_po(CZ80OpData *opData)
{
  if (! opData->z80->tstPFlag()) {
    opData->tracePC(opData->getUWord2());

    opData->z80->setPC(opData->getUWord2());
  }
}

void
CZ80::
f_jp_p(CZ80OpData *opData)
{
  if (! opData->z80->tstSFlag()) {
    opData->tracePC(opData->getUWord2());

    opData->z80->setPC(opData->getUWord2());
  }
}

void
CZ80::
f_jp_m(CZ80OpData *opData)
{
  if (opData->z80->tstSFlag()) {
    opData->tracePC(opData->getUWord2());

    opData->z80->setPC(opData->getUWord2());
  }
}

void
CZ80::
f_jp_hl(CZ80OpData *opData)
{
  opData->tracePC(opData->z80->getHL());

  opData->z80->setPC(opData->z80->getHL());
}

void
CZ80::
f_jp_ix(CZ80OpData *opData)
{
  opData->tracePC(opData->z80->getIX());

  opData->z80->setPC(opData->z80->getIX());
}

void
CZ80::
f_jp_iy(CZ80OpData *opData)
{
  opData->tracePC(opData->z80->getIY());

  opData->z80->setPC(opData->z80->getIY());
}

void
CZ80::
f_jr(CZ80OpData *opData)
{
  opData->tracePC(opData->getRPC1());

  opData->z80->setPC(opData->getRPC1());
}

void
CZ80::
f_jr_z(CZ80OpData *opData)
{
  if (opData->z80->tstZFlag()) {
    opData->tracePC(opData->getRPC2());

    opData->z80->setPC(opData->getRPC2());

    opData->z80->incT(5);
  }
}

void
CZ80::
f_jr_nz(CZ80OpData *opData)
{
  if (! opData->z80->tstZFlag()) {
    opData->tracePC(opData->getRPC2());

    opData->z80->setPC(opData->getRPC2());

    opData->z80->incT(5);
  }
}

void
CZ80::
f_jr_c(CZ80OpData *opData)
{
  if (opData->z80->tstCFlag()) {
    opData->tracePC(opData->getRPC2());

    opData->z80->setPC(opData->getRPC2());

    opData->z80->incT(5);
  }
}

void
CZ80::
f_jr_nc(CZ80OpData *opData)
{
  if (! opData->z80->tstCFlag()) {
    opData->tracePC(opData->getRPC2());

    opData->z80->setPC(opData->getRPC2());

    opData->z80->incT(5);
  }
}

void
CZ80::
f_ld_a_n(CZ80OpData *opData)
{
  opData->z80->setA(opData->getUByte2());
}

void
CZ80::
f_ld_b_n(CZ80OpData *opData)
{
  opData->z80->setB(opData->getUByte2());
}

void
CZ80::
f_ld_c_n(CZ80OpData *opData)
{
  opData->z80->setC(opData->getUByte2());
}

void
CZ80::
f_ld_d_n(CZ80OpData *opData)
{
  opData->z80->setD(opData->getUByte2());
}

void
CZ80::
f_ld_e_n(CZ80OpData *opData)
{
  opData->z80->setE(opData->getUByte2());
}

void
CZ80::
f_ld_h_n(CZ80OpData *opData)
{
  opData->z80->setH(opData->getUByte2());
}

void
CZ80::
f_ld_l_n(CZ80OpData *opData)
{
  opData->z80->setL(opData->getUByte2());
}

void
CZ80::
f_ld_bc_nn(CZ80OpData *opData)
{
  opData->z80->setBC(opData->getUWord2());
}

void
CZ80::
f_ld_de_nn(CZ80OpData *opData)
{
  opData->z80->setDE(opData->getUWord2());
}

void
CZ80::
f_ld_hl_nn(CZ80OpData *opData)
{
  opData->z80->setHL(opData->getUWord2());
}

void
CZ80::
f_ld_sp_nn(CZ80OpData *opData)
{
  opData->z80->setSP(opData->getUWord2());
}

void
CZ80::
f_ld_ix_nn(CZ80OpData *opData)
{
  opData->z80->setIX(opData->getUWord2());
}

void
CZ80::
f_ld_iy_nn(CZ80OpData *opData)
{
  opData->z80->setIY(opData->getUWord2());
}

void
CZ80::
f_ld_ixh_n(CZ80OpData *opData)
{
  opData->z80->setIXH(opData->getUByte2());
}

void
CZ80::
f_ld_ixl_n(CZ80OpData *opData)
{
  opData->z80->setIXL(opData->getUByte2());
}

void
CZ80::
f_ld_iyh_n(CZ80OpData *opData)
{
  opData->z80->setIYH(opData->getUByte2());
}

void
CZ80::
f_ld_iyl_n(CZ80OpData *opData)
{
  opData->z80->setIYL(opData->getUByte2());
}

void
CZ80::
f_ld_a_a(CZ80OpData *opData)
{
  opData->z80->setA(opData->z80->getA());
}

void
CZ80::
f_ld_a_b(CZ80OpData *opData)
{
  opData->z80->setA(opData->z80->getB());
}

void
CZ80::
f_ld_a_c(CZ80OpData *opData)
{
  opData->z80->setA(opData->z80->getC());
}

void
CZ80::
f_ld_a_d(CZ80OpData *opData)
{
  opData->z80->setA(opData->z80->getD());
}

void
CZ80::
f_ld_a_e(CZ80OpData *opData)
{
  opData->z80->setA(opData->z80->getE());
}

void
CZ80::
f_ld_a_h(CZ80OpData *opData)
{
  opData->z80->setA(opData->z80->getH());
}

void
CZ80::
f_ld_a_l(CZ80OpData *opData)
{
  opData->z80->setA(opData->z80->getL());
}

void
CZ80::
f_ld_a_i(CZ80OpData *opData)
{
  opData->z80->setA(opData->z80->getI());

  opData->z80->setRFlags(opData->z80->getI());

  opData->z80->resHFlag();
  opData->z80->resNFlag();

  opData->z80->setPFlag(opData->z80->getIFF2());
}

void
CZ80::
f_ld_a_r(CZ80OpData *opData)
{
  opData->z80->setA(opData->z80->getR());

  opData->z80->setRFlags(opData->z80->getI());

  opData->z80->resHFlag();
  opData->z80->resNFlag();

  opData->z80->setPFlag(opData->z80->getIFF2());
}

void
CZ80::
f_ld_a_ixh(CZ80OpData *opData)
{
  opData->z80->setA(opData->z80->getIXH());
}

void
CZ80::
f_ld_a_ixl(CZ80OpData *opData)
{
  opData->z80->setA(opData->z80->getIXL());
}

void
CZ80::
f_ld_a_iyh(CZ80OpData *opData)
{
  opData->z80->setA(opData->z80->getIYH());
}

void
CZ80::
f_ld_a_iyl(CZ80OpData *opData)
{
  opData->z80->setA(opData->z80->getIYL());
}

void
CZ80::
f_ld_b_a(CZ80OpData *opData)
{
  opData->z80->setB(opData->z80->getA());
}

void
CZ80::
f_ld_b_b(CZ80OpData *opData)
{
  opData->z80->setB(opData->z80->getB());
}

void
CZ80::
f_ld_b_c(CZ80OpData *opData)
{
  opData->z80->setB(opData->z80->getC());
}

void
CZ80::
f_ld_b_d(CZ80OpData *opData)
{
  opData->z80->setB(opData->z80->getD());
}

void
CZ80::
f_ld_b_e(CZ80OpData *opData)
{
  opData->z80->setB(opData->z80->getE());
}

void
CZ80::
f_ld_b_h(CZ80OpData *opData)
{
  opData->z80->setB(opData->z80->getH());
}

void
CZ80::
f_ld_b_l(CZ80OpData *opData)
{
  opData->z80->setB(opData->z80->getL());
}

void
CZ80::
f_ld_b_ixh(CZ80OpData *opData)
{
  opData->z80->setB(opData->z80->getIXH());
}

void
CZ80::
f_ld_b_ixl(CZ80OpData *opData)
{
  opData->z80->setB(opData->z80->getIXL());
}

void
CZ80::
f_ld_b_iyh(CZ80OpData *opData)
{
  opData->z80->setB(opData->z80->getIYH());
}

void
CZ80::
f_ld_b_iyl(CZ80OpData *opData)
{
  opData->z80->setB(opData->z80->getIYL());
}

void
CZ80::
f_ld_c_a(CZ80OpData *opData)
{
  opData->z80->setC(opData->z80->getA());
}

void
CZ80::
f_ld_c_b(CZ80OpData *opData)
{
  opData->z80->setC(opData->z80->getB());
}

void
CZ80::
f_ld_c_c(CZ80OpData *opData)
{
  opData->z80->setC(opData->z80->getC());
}

void
CZ80::
f_ld_c_d(CZ80OpData *opData)
{
  opData->z80->setC(opData->z80->getD());
}

void
CZ80::
f_ld_c_e(CZ80OpData *opData)
{
  opData->z80->setC(opData->z80->getE());
}

void
CZ80::
f_ld_c_h(CZ80OpData *opData)
{
  opData->z80->setC(opData->z80->getH());
}

void
CZ80::
f_ld_c_l(CZ80OpData *opData)
{
  opData->z80->setC(opData->z80->getL());
}

void
CZ80::
f_ld_c_ixh(CZ80OpData *opData)
{
  opData->z80->setC(opData->z80->getIXH());
}

void
CZ80::
f_ld_c_ixl(CZ80OpData *opData)
{
  opData->z80->setC(opData->z80->getIXL());
}

void
CZ80::
f_ld_c_iyh(CZ80OpData *opData)
{
  opData->z80->setC(opData->z80->getIYH());
}

void
CZ80::
f_ld_c_iyl(CZ80OpData *opData)
{
  opData->z80->setC(opData->z80->getIYL());
}

void
CZ80::
f_ld_d_a(CZ80OpData *opData)
{
  opData->z80->setD(opData->z80->getA());
}

void
CZ80::
f_ld_d_b(CZ80OpData *opData)
{
  opData->z80->setD(opData->z80->getB());
}

void
CZ80::
f_ld_d_c(CZ80OpData *opData)
{
  opData->z80->setD(opData->z80->getC());
}

void
CZ80::
f_ld_d_d(CZ80OpData *opData)
{
  opData->z80->setD(opData->z80->getD());
}

void
CZ80::
f_ld_d_e(CZ80OpData *opData)
{
  opData->z80->setD(opData->z80->getE());
}

void
CZ80::
f_ld_d_h(CZ80OpData *opData)
{
  opData->z80->setD(opData->z80->getH());
}

void
CZ80::
f_ld_d_l(CZ80OpData *opData)
{
  opData->z80->setD(opData->z80->getL());
}

void
CZ80::
f_ld_d_ixh(CZ80OpData *opData)
{
  opData->z80->setD(opData->z80->getIXH());
}

void
CZ80::
f_ld_d_ixl(CZ80OpData *opData)
{
  opData->z80->setD(opData->z80->getIXL());
}

void
CZ80::
f_ld_d_iyh(CZ80OpData *opData)
{
  opData->z80->setD(opData->z80->getIYH());
}

void
CZ80::
f_ld_d_iyl(CZ80OpData *opData)
{
  opData->z80->setD(opData->z80->getIYL());
}

void
CZ80::
f_ld_e_a(CZ80OpData *opData)
{
  opData->z80->setE(opData->z80->getA());
}

void
CZ80::
f_ld_e_b(CZ80OpData *opData)
{
  opData->z80->setE(opData->z80->getB());
}

void
CZ80::
f_ld_e_c(CZ80OpData *opData)
{
  opData->z80->setE(opData->z80->getC());
}

void
CZ80::
f_ld_e_d(CZ80OpData *opData)
{
  opData->z80->setE(opData->z80->getD());
}

void
CZ80::
f_ld_e_e(CZ80OpData *opData)
{
  opData->z80->setE(opData->z80->getE());
}

void
CZ80::
f_ld_e_h(CZ80OpData *opData)
{
  opData->z80->setE(opData->z80->getH());
}

void
CZ80::
f_ld_e_l(CZ80OpData *opData)
{
  opData->z80->setE(opData->z80->getL());
}

void
CZ80::
f_ld_e_ixh(CZ80OpData *opData)
{
  opData->z80->setE(opData->z80->getIXH());
}

void
CZ80::
f_ld_e_ixl(CZ80OpData *opData)
{
  opData->z80->setE(opData->z80->getIXL());
}

void
CZ80::
f_ld_e_iyh(CZ80OpData *opData)
{
  opData->z80->setE(opData->z80->getIYH());
}

void
CZ80::
f_ld_e_iyl(CZ80OpData *opData)
{
  opData->z80->setE(opData->z80->getIYL());
}

void
CZ80::
f_ld_h_a(CZ80OpData *opData)
{
  opData->z80->setH(opData->z80->getA());
}

void
CZ80::
f_ld_h_b(CZ80OpData *opData)
{
  opData->z80->setH(opData->z80->getB());
}

void
CZ80::
f_ld_h_c(CZ80OpData *opData)
{
  opData->z80->setH(opData->z80->getC());
}

void
CZ80::
f_ld_h_d(CZ80OpData *opData)
{
  opData->z80->setH(opData->z80->getD());
}

void
CZ80::
f_ld_h_e(CZ80OpData *opData)
{
  opData->z80->setH(opData->z80->getE());
}

void
CZ80::
f_ld_h_h(CZ80OpData *opData)
{
  opData->z80->setH(opData->z80->getH());
}

void
CZ80::
f_ld_h_l(CZ80OpData *opData)
{
  opData->z80->setH(opData->z80->getL());
}

void
CZ80::
f_ld_l_a(CZ80OpData *opData)
{
  opData->z80->setL(opData->z80->getA());
}

void
CZ80::
f_ld_l_b(CZ80OpData *opData)
{
  opData->z80->setL(opData->z80->getB());
}

void
CZ80::
f_ld_l_c(CZ80OpData *opData)
{
  opData->z80->setL(opData->z80->getC());
}

void
CZ80::
f_ld_l_d(CZ80OpData *opData)
{
  opData->z80->setL(opData->z80->getD());
}

void
CZ80::
f_ld_l_e(CZ80OpData *opData)
{
  opData->z80->setL(opData->z80->getE());
}

void
CZ80::
f_ld_l_h(CZ80OpData *opData)
{
  opData->z80->setL(opData->z80->getH());
}

void
CZ80::
f_ld_l_l(CZ80OpData *opData)
{
  opData->z80->setL(opData->z80->getL());
}

void
CZ80::
f_ld_ixh_a(CZ80OpData *opData)
{
  opData->z80->setIXH(opData->z80->getA());
}

void
CZ80::
f_ld_ixh_b(CZ80OpData *opData)
{
  opData->z80->setIXH(opData->z80->getB());
}

void
CZ80::
f_ld_ixh_c(CZ80OpData *opData)
{
  opData->z80->setIXH(opData->z80->getC());
}

void
CZ80::
f_ld_ixh_d(CZ80OpData *opData)
{
  opData->z80->setIXH(opData->z80->getD());
}

void
CZ80::
f_ld_ixh_e(CZ80OpData *opData)
{
  opData->z80->setIXH(opData->z80->getE());
}

void
CZ80::
f_ld_ixh_ixh(CZ80OpData *opData)
{
  opData->z80->setIXH(opData->z80->getIXH());
}

void
CZ80::
f_ld_ixh_ixl(CZ80OpData *opData)
{
  opData->z80->setIXH(opData->z80->getIXL());
}

void
CZ80::
f_ld_ixl_a(CZ80OpData *opData)
{
  opData->z80->setIXL(opData->z80->getA());
}

void
CZ80::
f_ld_ixl_b(CZ80OpData *opData)
{
  opData->z80->setIXL(opData->z80->getB());
}

void
CZ80::
f_ld_ixl_c(CZ80OpData *opData)
{
  opData->z80->setIXL(opData->z80->getC());
}

void
CZ80::
f_ld_ixl_d(CZ80OpData *opData)
{
  opData->z80->setIXL(opData->z80->getD());
}

void
CZ80::
f_ld_ixl_e(CZ80OpData *opData)
{
  opData->z80->setIXL(opData->z80->getE());
}

void
CZ80::
f_ld_ixl_ixh(CZ80OpData *opData)
{
  opData->z80->setIXL(opData->z80->getIXH());
}

void
CZ80::
f_ld_ixl_ixl(CZ80OpData *opData)
{
  opData->z80->setIXL(opData->z80->getIXL());
}

void
CZ80::
f_ld_iyh_a(CZ80OpData *opData)
{
  opData->z80->setIYH(opData->z80->getA());
}

void
CZ80::
f_ld_iyh_b(CZ80OpData *opData)
{
  opData->z80->setIYH(opData->z80->getB());
}

void
CZ80::
f_ld_iyh_c(CZ80OpData *opData)
{
  opData->z80->setIYH(opData->z80->getC());
}

void
CZ80::
f_ld_iyh_d(CZ80OpData *opData)
{
  opData->z80->setIYH(opData->z80->getD());
}

void
CZ80::
f_ld_iyh_e(CZ80OpData *opData)
{
  opData->z80->setIYH(opData->z80->getE());
}

void
CZ80::
f_ld_iyh_iyh(CZ80OpData *opData)
{
  opData->z80->setIYH(opData->z80->getIYH());
}

void
CZ80::
f_ld_iyh_iyl(CZ80OpData *opData)
{
  opData->z80->setIYH(opData->z80->getIYL());
}

void
CZ80::
f_ld_iyl_a(CZ80OpData *opData)
{
  opData->z80->setIYL(opData->z80->getA());
}

void
CZ80::
f_ld_iyl_b(CZ80OpData *opData)
{
  opData->z80->setIYL(opData->z80->getB());
}

void
CZ80::
f_ld_iyl_c(CZ80OpData *opData)
{
  opData->z80->setIYL(opData->z80->getC());
}

void
CZ80::
f_ld_iyl_d(CZ80OpData *opData)
{
  opData->z80->setIYL(opData->z80->getD());
}

void
CZ80::
f_ld_iyl_e(CZ80OpData *opData)
{
  opData->z80->setIYL(opData->z80->getE());
}

void
CZ80::
f_ld_iyl_iyh(CZ80OpData *opData)
{
  opData->z80->setIYL(opData->z80->getIYH());
}

void
CZ80::
f_ld_iyl_iyl(CZ80OpData *opData)
{
  opData->z80->setIYL(opData->z80->getIYL());
}

void
CZ80::
f_ld_i_a(CZ80OpData *opData)
{
  opData->z80->setI(opData->z80->getA());
}

void
CZ80::
f_ld_r_a(CZ80OpData *opData)
{
  opData->z80->setR(opData->z80->getA());
}

void
CZ80::
f_ld_a_p_bc(CZ80OpData *opData)
{
  opData->z80->setA(opData->z80->getPBC());
}

void
CZ80::
f_ld_a_p_de(CZ80OpData *opData)
{
  opData->z80->setA(opData->z80->getPDE());
}

void
CZ80::
f_ld_a_p_hl(CZ80OpData *opData)
{
  opData->z80->setA(opData->z80->getPHL());
}

void
CZ80::
f_ld_b_p_hl(CZ80OpData *opData)
{
  opData->z80->setB(opData->z80->getPHL());
}

void
CZ80::
f_ld_c_p_hl(CZ80OpData *opData)
{
  opData->z80->setC(opData->z80->getPHL());
}

void
CZ80::
f_ld_d_p_hl(CZ80OpData *opData)
{
  opData->z80->setD(opData->z80->getPHL());
}

void
CZ80::
f_ld_e_p_hl(CZ80OpData *opData)
{
  opData->z80->setE(opData->z80->getPHL());
}

void
CZ80::
f_ld_h_p_hl(CZ80OpData *opData)
{
  opData->z80->setH(opData->z80->getPHL());
}

void
CZ80::
f_ld_l_p_hl(CZ80OpData *opData)
{
  opData->z80->setL(opData->z80->getPHL());
}

void
CZ80::
f_ld_p_bc_a(CZ80OpData *opData)
{
  opData->z80->setPBC(opData->z80->getA());
}

void
CZ80::
f_ld_p_de_a(CZ80OpData *opData)
{
  opData->z80->setPDE(opData->z80->getA());
}

void
CZ80::
f_ld_p_hl_a(CZ80OpData *opData)
{
  opData->z80->setPHL(opData->z80->getA());
}

void
CZ80::
f_ld_p_hl_b(CZ80OpData *opData)
{
  opData->z80->setPHL(opData->z80->getB());
}

void
CZ80::
f_ld_p_hl_c(CZ80OpData *opData)
{
  opData->z80->setPHL(opData->z80->getC());
}

void
CZ80::
f_ld_p_hl_d(CZ80OpData *opData)
{
  opData->z80->setPHL(opData->z80->getD());
}

void
CZ80::
f_ld_p_hl_e(CZ80OpData *opData)
{
  opData->z80->setPHL(opData->z80->getE());
}

void
CZ80::
f_ld_p_hl_h(CZ80OpData *opData)
{
  opData->z80->setPHL(opData->z80->getH());
}

void
CZ80::
f_ld_p_hl_l(CZ80OpData *opData)
{
  opData->z80->setPHL(opData->z80->getL());
}

void
CZ80::
f_ld_p_hl_n(CZ80OpData *opData)
{
  opData->z80->setPHL(opData->getUByte2());
}

void
CZ80::
f_ld_a_p_nn(CZ80OpData *opData)
{
  opData->z80->setA(opData->getPByte2());
}

void
CZ80::
f_ld_bc_p_nn(CZ80OpData *opData)
{
  opData->z80->setBC(opData->getPWord2());
}

void
CZ80::
f_ld_de_p_nn(CZ80OpData *opData)
{
  opData->z80->setDE(opData->getPWord2());
}

void
CZ80::
f_ld_hl_p_nn(CZ80OpData *opData)
{
  opData->z80->setHL(opData->getPWord2());
}

void
CZ80::
f_ld_sp_p_nn(CZ80OpData *opData)
{
  opData->z80->setSP(opData->getPWord2());
}

void
CZ80::
f_ld_ix_p_nn(CZ80OpData *opData)
{
  opData->z80->setIX(opData->getPWord2());
}

void
CZ80::
f_ld_iy_p_nn(CZ80OpData *opData)
{
  opData->z80->setIY(opData->getPWord2());
}

void
CZ80::
f_ld_p_nn_a(CZ80OpData *opData)
{
  opData->setPByte1(opData->z80->getA());
}

void
CZ80::
f_ld_p_nn_bc(CZ80OpData *opData)
{
  opData->setPWord1(opData->z80->getBC());
}

void
CZ80::
f_ld_p_nn_de(CZ80OpData *opData)
{
  opData->setPWord1(opData->z80->getDE());
}

void
CZ80::
f_ld_p_nn_hl(CZ80OpData *opData)
{
  opData->setPWord1(opData->z80->getHL());
}

void
CZ80::
f_ld_p_nn_sp(CZ80OpData *opData)
{
  opData->setPWord1(opData->z80->getSP());
}

void
CZ80::
f_ld_p_nn_ix(CZ80OpData *opData)
{
  opData->setPWord1(opData->z80->getIX());
}

void
CZ80::
f_ld_p_nn_iy(CZ80OpData *opData)
{
  opData->setPWord1(opData->z80->getIY());
}

void
CZ80::
f_ld_sp_hl(CZ80OpData *opData)
{
  opData->z80->setSP(opData->z80->getHL());
}

void
CZ80::
f_ld_sp_ix(CZ80OpData *opData)
{
  opData->z80->setSP(opData->z80->getIX());
}

void
CZ80::
f_ld_sp_iy(CZ80OpData *opData)
{
  opData->z80->setSP(opData->z80->getIY());
}

void
CZ80::
f_ld_a_po_ix(CZ80OpData *opData)
{
  opData->z80->setA(opData->getPOIX2());
}

void
CZ80::
f_ld_b_po_ix(CZ80OpData *opData)
{
  opData->z80->setB(opData->getPOIX2());
}

void
CZ80::
f_ld_c_po_ix(CZ80OpData *opData)
{
  opData->z80->setC(opData->getPOIX2());
}

void
CZ80::
f_ld_d_po_ix(CZ80OpData *opData)
{
  opData->z80->setD(opData->getPOIX2());
}

void
CZ80::
f_ld_e_po_ix(CZ80OpData *opData)
{
  opData->z80->setE(opData->getPOIX2());
}

void
CZ80::
f_ld_h_po_ix(CZ80OpData *opData)
{
  opData->z80->setH(opData->getPOIX2());
}

void
CZ80::
f_ld_l_po_ix(CZ80OpData *opData)
{
  opData->z80->setL(opData->getPOIX2());
}

void
CZ80::
f_ld_a_po_iy(CZ80OpData *opData)
{
  opData->z80->setA(opData->getPOIY2());
}

void
CZ80::
f_ld_b_po_iy(CZ80OpData *opData)
{
  opData->z80->setB(opData->getPOIY2());
}

void
CZ80::
f_ld_c_po_iy(CZ80OpData *opData)
{
  opData->z80->setC(opData->getPOIY2());
}

void
CZ80::
f_ld_d_po_iy(CZ80OpData *opData)
{
  opData->z80->setD(opData->getPOIY2());
}

void
CZ80::
f_ld_e_po_iy(CZ80OpData *opData)
{
  opData->z80->setE(opData->getPOIY2());
}

void
CZ80::
f_ld_h_po_iy(CZ80OpData *opData)
{
  opData->z80->setH(opData->getPOIY2());
}

void
CZ80::
f_ld_l_po_iy(CZ80OpData *opData)
{
  opData->z80->setL(opData->getPOIY2());
}

void
CZ80::
f_ld_po_ix_a(CZ80OpData *opData)
{
  opData->setPOIX1(opData->z80->getA());
}

void
CZ80::
f_ld_po_ix_b(CZ80OpData *opData)
{
  opData->setPOIX1(opData->z80->getB());
}

void
CZ80::
f_ld_po_ix_c(CZ80OpData *opData)
{
  opData->setPOIX1(opData->z80->getC());
}

void
CZ80::
f_ld_po_ix_d(CZ80OpData *opData)
{
  opData->setPOIX1(opData->z80->getD());
}

void
CZ80::
f_ld_po_ix_e(CZ80OpData *opData)
{
  opData->setPOIX1(opData->z80->getE());
}

void
CZ80::
f_ld_po_ix_h(CZ80OpData *opData)
{
  opData->setPOIX1(opData->z80->getH());
}

void
CZ80::
f_ld_po_ix_l(CZ80OpData *opData)
{
  opData->setPOIX1(opData->z80->getL());
}

void
CZ80::
f_ld_po_ix_n(CZ80OpData *opData)
{
  opData->setPOIX1(opData->getUByte2());
}

void
CZ80::
f_ld_po_iy_a(CZ80OpData *opData)
{
  opData->setPOIY1(opData->z80->getA());
}

void
CZ80::
f_ld_po_iy_b(CZ80OpData *opData)
{
  opData->setPOIY1(opData->z80->getB());
}

void
CZ80::
f_ld_po_iy_c(CZ80OpData *opData)
{
  opData->setPOIY1(opData->z80->getC());
}

void
CZ80::
f_ld_po_iy_d(CZ80OpData *opData)
{
  opData->setPOIY1(opData->z80->getD());
}

void
CZ80::
f_ld_po_iy_e(CZ80OpData *opData)
{
  opData->setPOIY1(opData->z80->getE());
}

void
CZ80::
f_ld_po_iy_h(CZ80OpData *opData)
{
  opData->setPOIY1(opData->z80->getH());
}

void
CZ80::
f_ld_po_iy_l(CZ80OpData *opData)
{
  opData->setPOIY1(opData->z80->getL());
}

void
CZ80::
f_ld_po_iy_n(CZ80OpData *opData)
{
  opData->setPOIY1(opData->getUByte2());
}

void
CZ80::
f_ldd(CZ80OpData *opData)
{
  opData->z80->ldd();
}

void
CZ80::
f_lddr(CZ80OpData *opData)
{
  opData->z80->lddr();
}

void
CZ80::
f_ldi(CZ80OpData *opData)
{
  opData->z80->ldi();
}

void
CZ80::
f_ldir(CZ80OpData *opData)
{
  opData->z80->ldir();
}

void
CZ80::
f_neg(CZ80OpData *opData)
{
  opData->z80->neg();
}

void
CZ80::
f_nop(CZ80OpData *)
{
}

void
CZ80::
f_or_a(CZ80OpData *opData)
{
  opData->z80->orA(opData->z80->getA());
}

void
CZ80::
f_or_b(CZ80OpData *opData)
{
  opData->z80->orA(opData->z80->getB());
}

void
CZ80::
f_or_c(CZ80OpData *opData)
{
  opData->z80->orA(opData->z80->getC());
}

void
CZ80::
f_or_d(CZ80OpData *opData)
{
  opData->z80->orA(opData->z80->getD());
}

void
CZ80::
f_or_e(CZ80OpData *opData)
{
  opData->z80->orA(opData->z80->getE());
}

void
CZ80::
f_or_h(CZ80OpData *opData)
{
  opData->z80->orA(opData->z80->getH());
}

void
CZ80::
f_or_l(CZ80OpData *opData)
{
  opData->z80->orA(opData->z80->getL());
}

void
CZ80::
f_or_ixh(CZ80OpData *opData)
{
  opData->z80->orA(opData->z80->getIXH());
}

void
CZ80::
f_or_ixl(CZ80OpData *opData)
{
  opData->z80->orA(opData->z80->getIXL());
}

void
CZ80::
f_or_iyh(CZ80OpData *opData)
{
  opData->z80->orA(opData->z80->getIYH());
}

void
CZ80::
f_or_iyl(CZ80OpData *opData)
{
  opData->z80->orA(opData->z80->getIYL());
}

void
CZ80::
f_or_p_hl(CZ80OpData *opData)
{
  opData->z80->orA(opData->z80->getPHL());
}

void
CZ80::
f_or_n(CZ80OpData *opData)
{
  opData->z80->orA(opData->getUByte1());
}

void
CZ80::
f_or_po_ix(CZ80OpData *opData)
{
  opData->z80->orA(opData->getPOIX1());
}

void
CZ80::
f_or_po_iy(CZ80OpData *opData)
{
  opData->z80->orA(opData->getPOIY1());
}

void
CZ80::
f_out_p_n_a(CZ80OpData *opData)
{
  opData->z80->out(opData->getUByte1(), opData->z80->getA());
}

void
CZ80::
f_out_p_c_a(CZ80OpData *opData)
{
  opData->z80->outC(opData->z80->getA());
}

void
CZ80::
f_out_p_c_b(CZ80OpData *opData)
{
  opData->z80->outC(opData->z80->getB());
}

void
CZ80::
f_out_p_c_c(CZ80OpData *opData)
{
  opData->z80->outC(opData->z80->getC());
}

void
CZ80::
f_out_p_c_d(CZ80OpData *opData)
{
  opData->z80->outC(opData->z80->getD());
}

void
CZ80::
f_out_p_c_e(CZ80OpData *opData)
{
  opData->z80->outC(opData->z80->getE());
}

void
CZ80::
f_out_p_c_h(CZ80OpData *opData)
{
  opData->z80->outC(opData->z80->getH());
}

void
CZ80::
f_out_p_c_l(CZ80OpData *opData)
{
  opData->z80->outC(opData->z80->getL());
}

void
CZ80::
f_out_p_c_n(CZ80OpData *opData)
{
  opData->z80->outC(uchar(opData->op->arg2));
}

void
CZ80::
f_outd(CZ80OpData *opData)
{
  opData->z80->outC(opData->z80->getPHL());

  opData->z80->decHL();
  opData->z80->decB();
}

void
CZ80::
f_outi(CZ80OpData *opData)
{
  opData->z80->outC(opData->z80->getPHL());

  opData->z80->incHL();
  opData->z80->decB();
}

void
CZ80::
f_otdr(CZ80OpData *opData)
{
  do {
    f_outd(opData);

    opData->z80->incT(21);
  }
  while (opData->z80->getB() != 0);

  opData->z80->decT(5);
}

void
CZ80::
f_otir(CZ80OpData *opData)
{
  do {
    f_outi(opData);

    opData->z80->incT(21);
  }
  while (opData->z80->getB() != 0);

  opData->z80->decT(5);
}

void
CZ80::
f_pop_af(CZ80OpData *opData)
{
  opData->z80->popAF();
}

void
CZ80::
f_pop_bc(CZ80OpData *opData)
{
  opData->z80->popBC();
}

void
CZ80::
f_pop_de(CZ80OpData *opData)
{
  opData->z80->popDE();
}

void
CZ80::
f_pop_hl(CZ80OpData *opData)
{
  opData->z80->popHL();
}

void
CZ80::
f_pop_ix(CZ80OpData *opData)
{
  opData->z80->popIX();
}

void
CZ80::
f_pop_iy(CZ80OpData *opData)
{
  opData->z80->popIY();
}

void
CZ80::
f_push_af(CZ80OpData *opData)
{
  opData->z80->pushAF();
}

void
CZ80::
f_push_bc(CZ80OpData *opData)
{
  opData->z80->pushBC();
}

void
CZ80::
f_push_de(CZ80OpData *opData)
{
  opData->z80->pushDE();
}

void
CZ80::
f_push_hl(CZ80OpData *opData)
{
  opData->z80->pushHL();
}

void
CZ80::
f_push_ix(CZ80OpData *opData)
{
  opData->z80->pushIX();
}

void
CZ80::
f_push_iy(CZ80OpData *opData)
{
  opData->z80->pushIY();
}

void
CZ80::
f_res_po_ix_n(CZ80OpData *opData)
{
  opData->z80->resBitPOIX(opData->getSByte2(), uchar(opData->op->arg1));
}

void
CZ80::
f_res_po_iy_n(CZ80OpData *opData)
{
  opData->z80->resBitPOIY(opData->getSByte2(), uchar(opData->op->arg1));
}

void
CZ80::
f_res_a_n(CZ80OpData *opData)
{
  opData->z80->resBitA(uchar(opData->op->arg1));
}

void
CZ80::
f_res_b_n(CZ80OpData *opData)
{
  opData->z80->resBitB(uchar(opData->op->arg1));
}

void
CZ80::
f_res_c_n(CZ80OpData *opData)
{
  opData->z80->resBitC(uchar(opData->op->arg1));
}

void
CZ80::
f_res_d_n(CZ80OpData *opData)
{
  opData->z80->resBitD(uchar(opData->op->arg1));
}

void
CZ80::
f_res_e_n(CZ80OpData *opData)
{
  opData->z80->resBitE(uchar(opData->op->arg1));
}

void
CZ80::
f_res_h_n(CZ80OpData *opData)
{
  opData->z80->resBitH(uchar(opData->op->arg1));
}

void
CZ80::
f_res_l_n(CZ80OpData *opData)
{
  opData->z80->resBitL(uchar(opData->op->arg1));
}

void
CZ80::
f_res_p_hl_n(CZ80OpData *opData)
{
  opData->z80->resBitPHL(uchar(opData->op->arg1));
}

void
CZ80::
f_res_po_ix_a_n(CZ80OpData *opData)
{
  f_res_po_ix_a_n(opData, uchar(opData->op->arg1));
}

void
CZ80::
f_res_po_ix_b_n(CZ80OpData *opData)
{
  f_res_po_ix_b_n(opData, uchar(opData->op->arg1));
}

void
CZ80::
f_res_po_ix_c_n(CZ80OpData *opData)
{
  f_res_po_ix_c_n(opData, uchar(opData->op->arg1));
}

void
CZ80::
f_res_po_ix_d_n(CZ80OpData *opData)
{
  f_res_po_ix_d_n(opData, uchar(opData->op->arg1));
}

void
CZ80::
f_res_po_ix_e_n(CZ80OpData *opData)
{
  f_res_po_ix_e_n(opData, uchar(opData->op->arg1));
}

void
CZ80::
f_res_po_ix_h_n(CZ80OpData *opData)
{
  f_res_po_ix_h_n(opData, uchar(opData->op->arg1));
}

void
CZ80::
f_res_po_ix_l_n(CZ80OpData *opData)
{
  f_res_po_ix_l_n(opData, uchar(opData->op->arg1));
}

void
CZ80::
f_res_po_iy_a_n(CZ80OpData *opData)
{
  f_res_po_iy_a_n(opData, uchar(opData->op->arg1));
}

void
CZ80::
f_res_po_iy_b_n(CZ80OpData *opData)
{
  f_res_po_iy_b_n(opData, uchar(opData->op->arg1));
}

void
CZ80::
f_res_po_iy_c_n(CZ80OpData *opData)
{
  f_res_po_iy_c_n(opData, uchar(opData->op->arg1));
}

void
CZ80::
f_res_po_iy_d_n(CZ80OpData *opData)
{
  f_res_po_iy_d_n(opData, uchar(opData->op->arg1));
}

void
CZ80::
f_res_po_iy_e_n(CZ80OpData *opData)
{
  f_res_po_iy_e_n(opData, uchar(opData->op->arg1));
}

void
CZ80::
f_res_po_iy_h_n(CZ80OpData *opData)
{
  f_res_po_iy_h_n(opData, uchar(opData->op->arg1));
}

void
CZ80::
f_res_po_iy_l_n(CZ80OpData *opData)
{
  f_res_po_iy_l_n(opData, uchar(opData->op->arg1));
}

void
CZ80::
f_res_po_ix_a_n(CZ80OpData *opData, uchar n)
{
  schar o = opData->getSByte2();

  opData->z80->setA(opData->z80->getPOIX(o));

  opData->z80->resBitA(n);

  opData->z80->setPOIX(o, opData->z80->getA());
}

void
CZ80::
f_res_po_ix_b_n(CZ80OpData *opData, uchar n)
{
  schar o = opData->getSByte2();

  opData->z80->setB(opData->z80->getPOIX(o));

  opData->z80->resBitB(n);

  opData->z80->setPOIX(o, opData->z80->getB());
}

void
CZ80::
f_res_po_ix_c_n(CZ80OpData *opData, uchar n)
{
  schar o = opData->getSByte2();

  opData->z80->setC(opData->z80->getPOIX(o));

  opData->z80->resBitC(n);

  opData->z80->setPOIX(o, opData->z80->getC());
}

void
CZ80::
f_res_po_ix_d_n(CZ80OpData *opData, uchar n)
{
  schar o = opData->getSByte2();

  opData->z80->setD(opData->z80->getPOIX(o));

  opData->z80->resBitD(n);

  opData->z80->setPOIX(o, opData->z80->getD());
}

void
CZ80::
f_res_po_ix_e_n(CZ80OpData *opData, uchar n)
{
  schar o = opData->getSByte2();

  opData->z80->setE(opData->z80->getPOIX(o));

  opData->z80->resBitE(n);

  opData->z80->setPOIX(o, opData->z80->getE());
}

void
CZ80::
f_res_po_ix_h_n(CZ80OpData *opData, uchar n)
{
  schar o = opData->getSByte2();

  opData->z80->setH(opData->z80->getPOIX(o));

  opData->z80->resBitH(n);

  opData->z80->setPOIX(o, opData->z80->getH());
}

void
CZ80::
f_res_po_ix_l_n(CZ80OpData *opData, uchar n)
{
  schar o = opData->getSByte2();

  opData->z80->setL(opData->z80->getPOIX(o));

  opData->z80->resBitL(n);

  opData->z80->setPOIX(o, opData->z80->getL());
}

void
CZ80::
f_res_po_iy_a_n(CZ80OpData *opData, uchar n)
{
  schar o = opData->getSByte2();

  opData->z80->setA(opData->z80->getPOIY(o));

  opData->z80->resBitA(n);

  opData->z80->setPOIY(o, opData->z80->getA());
}

void
CZ80::
f_res_po_iy_b_n(CZ80OpData *opData, uchar n)
{
  schar o = opData->getSByte2();

  opData->z80->setB(opData->z80->getPOIY(o));

  opData->z80->resBitB(n);

  opData->z80->setPOIY(o, opData->z80->getB());
}

void
CZ80::
f_res_po_iy_c_n(CZ80OpData *opData, uchar n)
{
  schar o = opData->getSByte2();

  opData->z80->setC(opData->z80->getPOIY(o));

  opData->z80->resBitC(n);

  opData->z80->setPOIY(o, opData->z80->getC());
}

void
CZ80::
f_res_po_iy_d_n(CZ80OpData *opData, uchar n)
{
  schar o = opData->getSByte2();

  opData->z80->setD(opData->z80->getPOIY(o));

  opData->z80->resBitD(n);

  opData->z80->setPOIY(o, opData->z80->getD());
}

void
CZ80::
f_res_po_iy_e_n(CZ80OpData *opData, uchar n)
{
  schar o = opData->getSByte2();

  opData->z80->setE(opData->z80->getPOIY(o));

  opData->z80->resBitE(n);

  opData->z80->setPOIY(o, opData->z80->getE());
}

void
CZ80::
f_res_po_iy_h_n(CZ80OpData *opData, uchar n)
{
  schar o = opData->getSByte2();

  opData->z80->setH(opData->z80->getPOIY(o));

  opData->z80->resBitH(n);

  opData->z80->setPOIY(o, opData->z80->getH());
}

void
CZ80::
f_res_po_iy_l_n(CZ80OpData *opData, uchar n)
{
  schar o = opData->getSByte2();

  opData->z80->setL(opData->z80->getPOIY(o));

  opData->z80->resBitL(n);

  opData->z80->setPOIY(o, opData->z80->getL());
}

void
CZ80::
f_ret(CZ80OpData *opData)
{
  opData->tracePC(opData->z80->peek());

  opData->z80->popPC();
}

void
CZ80::
f_ret_z(CZ80OpData *opData)
{
  if (opData->z80->tstZFlag()) {
    opData->tracePC(opData->z80->peek());

    opData->z80->popPC();
  }
}

void
CZ80::
f_ret_nz(CZ80OpData *opData)
{
  if (! opData->z80->tstZFlag()) {
    opData->tracePC(opData->z80->peek());

    opData->z80->popPC();

    opData->z80->incT(6);
  }
}

void
CZ80::
f_ret_c(CZ80OpData *opData)
{
  if (opData->z80->tstCFlag()) {
    opData->tracePC(opData->z80->peek());

    opData->z80->popPC();

    opData->z80->incT(6);
  }
}

void
CZ80::
f_ret_nc(CZ80OpData *opData)
{
  if (! opData->z80->tstCFlag()) {
    opData->tracePC(opData->z80->peek());

    opData->z80->popPC();

    opData->z80->incT(6);
  }
}

void
CZ80::
f_ret_pe(CZ80OpData *opData)
{
  if (opData->z80->tstPFlag()) {
    opData->tracePC(opData->z80->peek());

    opData->z80->popPC();

    opData->z80->incT(6);
  }
}

void
CZ80::
f_ret_po(CZ80OpData *opData)
{
  if (! opData->z80->tstPFlag()) {
    opData->tracePC(opData->z80->peek());

    opData->z80->popPC();

    opData->z80->incT(6);
  }
}

void
CZ80::
f_ret_p(CZ80OpData *opData)
{
  if (! opData->z80->tstSFlag()) {
    opData->tracePC(opData->z80->peek());

    opData->z80->popPC();

    opData->z80->incT(6);
  }
}

void
CZ80::
f_ret_m(CZ80OpData *opData)
{
  if (opData->z80->tstSFlag()) {
    opData->tracePC(opData->z80->peek());

    opData->z80->popPC();

    opData->z80->incT(6);
  }
}

void
CZ80::
f_reti(CZ80OpData *opData)
{
  opData->z80->reti();
}

void
CZ80::
f_retn(CZ80OpData *opData)
{
  opData->z80->retn();
}

void
CZ80::
f_rl_a(CZ80OpData *opData)
{
  opData->z80->rlA();
}

void
CZ80::
f_rl_b(CZ80OpData *opData)
{
  opData->z80->rlB();
}

void
CZ80::
f_rl_c(CZ80OpData *opData)
{
  opData->z80->rlC();
}

void
CZ80::
f_rl_d(CZ80OpData *opData)
{
  opData->z80->rlD();
}

void
CZ80::
f_rl_e(CZ80OpData *opData)
{
  opData->z80->rlE();
}

void
CZ80::
f_rl_h(CZ80OpData *opData)
{
  opData->z80->rlH();
}

void
CZ80::
f_rl_l(CZ80OpData *opData)
{
  opData->z80->rlL();
}

void
CZ80::
f_rl_p_hl(CZ80OpData *opData)
{
  opData->z80->rlPHL();
}

void
CZ80::
f_rl_po_ix(CZ80OpData *opData)
{
  opData->z80->rlPOIX(opData->getSByte1());
}

void
CZ80::
f_rl_po_ix_a(CZ80OpData *opData)
{
  schar o = opData->getSByte1();

  opData->z80->setA(opData->z80->getPOIX(o));

  opData->z80->rlA();

  opData->z80->setPOIX(o, opData->z80->getA());
}

void
CZ80::
f_rl_po_ix_b(CZ80OpData *opData)
{
  schar o = opData->getSByte1();

  opData->z80->setB(opData->z80->getPOIX(o));

  opData->z80->rlB();

  opData->z80->setPOIX(o, opData->z80->getB());
}

void
CZ80::
f_rl_po_ix_c(CZ80OpData *opData)
{
  schar o = opData->getSByte1();

  opData->z80->setC(opData->z80->getPOIX(o));

  opData->z80->rlC();

  opData->z80->setPOIX(o, opData->z80->getC());
}

void
CZ80::
f_rl_po_ix_d(CZ80OpData *opData)
{
  schar o = opData->getSByte1();

  opData->z80->setD(opData->z80->getPOIX(o));

  opData->z80->rlD();

  opData->z80->setPOIX(o, opData->z80->getD());
}

void
CZ80::
f_rl_po_ix_e(CZ80OpData *opData)
{
  schar o = opData->getSByte1();

  opData->z80->setE(opData->z80->getPOIX(o));

  opData->z80->rlE();

  opData->z80->setPOIX(o, opData->z80->getE());
}

void
CZ80::
f_rl_po_ix_h(CZ80OpData *opData)
{
  schar o = opData->getSByte1();

  opData->z80->setH(opData->z80->getPOIX(o));

  opData->z80->rlH();

  opData->z80->setPOIX(o, opData->z80->getH());
}

void
CZ80::
f_rl_po_ix_l(CZ80OpData *opData)
{
  schar o = opData->getSByte1();

  opData->z80->setL(opData->z80->getPOIX(o));

  opData->z80->rlL();

  opData->z80->setPOIX(o, opData->z80->getL());
}

void
CZ80::
f_rl_po_iy(CZ80OpData *opData)
{
  opData->z80->rlPOIY(opData->getSByte1());
}

void
CZ80::
f_rl_po_iy_a(CZ80OpData *opData)
{
  schar o = opData->getSByte1();

  opData->z80->setA(opData->z80->getPOIY(o));

  opData->z80->rlA();

  opData->z80->setPOIY(o, opData->z80->getA());
}

void
CZ80::
f_rl_po_iy_b(CZ80OpData *opData)
{
  schar o = opData->getSByte1();

  opData->z80->setB(opData->z80->getPOIY(o));

  opData->z80->rlB();

  opData->z80->setPOIY(o, opData->z80->getB());
}

void
CZ80::
f_rl_po_iy_c(CZ80OpData *opData)
{
  schar o = opData->getSByte1();

  opData->z80->setC(opData->z80->getPOIY(o));

  opData->z80->rlC();

  opData->z80->setPOIY(o, opData->z80->getC());
}

void
CZ80::
f_rl_po_iy_d(CZ80OpData *opData)
{
  schar o = opData->getSByte1();

  opData->z80->setD(opData->z80->getPOIY(o));

  opData->z80->rlD();

  opData->z80->setPOIY(o, opData->z80->getD());
}

void
CZ80::
f_rl_po_iy_e(CZ80OpData *opData)
{
  schar o = opData->getSByte1();

  opData->z80->setE(opData->z80->getPOIY(o));

  opData->z80->rlE();

  opData->z80->setPOIY(o, opData->z80->getE());
}

void
CZ80::
f_rl_po_iy_h(CZ80OpData *opData)
{
  schar o = opData->getSByte1();

  opData->z80->setH(opData->z80->getPOIY(o));

  opData->z80->rlH();

  opData->z80->setPOIY(o, opData->z80->getH());
}

void
CZ80::
f_rl_po_iy_l(CZ80OpData *opData)
{
  schar o = opData->getSByte1();

  opData->z80->setL(opData->z80->getPOIY(o));

  opData->z80->rlL();

  opData->z80->setPOIY(o, opData->z80->getL());
}

void
CZ80::
f_rla(CZ80OpData *opData)
{
  opData->z80->rla();
}

void
CZ80::
f_rlc_a(CZ80OpData *opData)
{
  opData->z80->rlcA();
}

void
CZ80::
f_rlc_b(CZ80OpData *opData)
{
  opData->z80->rlcB();
}

void
CZ80::
f_rlc_c(CZ80OpData *opData)
{
  opData->z80->rlcC();
}

void
CZ80::
f_rlc_d(CZ80OpData *opData)
{
  opData->z80->rlcD();
}

void
CZ80::
f_rlc_e(CZ80OpData *opData)
{
  opData->z80->rlcE();
}

void
CZ80::
f_rlc_h(CZ80OpData *opData)
{
  opData->z80->rlcH();
}

void
CZ80::
f_rlc_l(CZ80OpData *opData)
{
  opData->z80->rlcL();
}

void
CZ80::
f_rlc_p_hl(CZ80OpData *opData)
{
  opData->z80->rlcPHL();
}

void
CZ80::
f_rlc_po_ix(CZ80OpData *opData)
{
  opData->z80->rlcPOIX(opData->getSByte1());
}

void
CZ80::
f_rlc_po_ix_a(CZ80OpData *opData)
{
  schar o = opData->getSByte1();

  opData->z80->setA(opData->z80->getPOIX(o));

  opData->z80->rlcA();

  opData->z80->setPOIX(o, opData->z80->getA());
}

void
CZ80::
f_rlc_po_ix_b(CZ80OpData *opData)
{
  schar o = opData->getSByte1();

  opData->z80->setB(opData->z80->getPOIX(o));

  opData->z80->rlcB();

  opData->z80->setPOIX(o, opData->z80->getB());
}

void
CZ80::
f_rlc_po_ix_c(CZ80OpData *opData)
{
  schar o = opData->getSByte1();

  opData->z80->setC(opData->z80->getPOIX(o));

  opData->z80->rlcC();

  opData->z80->setPOIX(o, opData->z80->getC());
}

void
CZ80::
f_rlc_po_ix_d(CZ80OpData *opData)
{
  schar o = opData->getSByte1();

  opData->z80->setD(opData->z80->getPOIX(o));

  opData->z80->rlcD();

  opData->z80->setPOIX(o, opData->z80->getD());
}

void
CZ80::
f_rlc_po_ix_e(CZ80OpData *opData)
{
  schar o = opData->getSByte1();

  opData->z80->setE(opData->z80->getPOIX(o));

  opData->z80->rlcE();

  opData->z80->setPOIX(o, opData->z80->getE());
}

void
CZ80::
f_rlc_po_ix_h(CZ80OpData *opData)
{
  schar o = opData->getSByte1();

  opData->z80->setH(opData->z80->getPOIX(o));

  opData->z80->rlcH();

  opData->z80->setPOIX(o, opData->z80->getH());
}

void
CZ80::
f_rlc_po_ix_l(CZ80OpData *opData)
{
  schar o = opData->getSByte1();

  opData->z80->setL(opData->z80->getPOIX(o));

  opData->z80->rlcL();

  opData->z80->setPOIX(o, opData->z80->getL());
}

void
CZ80::
f_rlc_po_iy(CZ80OpData *opData)
{
  opData->z80->rlcPOIY(opData->getSByte1());
}

void
CZ80::
f_rlc_po_iy_a(CZ80OpData *opData)
{
  schar o = opData->getSByte1();

  opData->z80->setA(opData->z80->getPOIY(o));

  opData->z80->rlcA();

  opData->z80->setPOIY(o, opData->z80->getA());
}

void
CZ80::
f_rlc_po_iy_b(CZ80OpData *opData)
{
  schar o = opData->getSByte1();

  opData->z80->setB(opData->z80->getPOIY(o));

  opData->z80->rlcB();

  opData->z80->setPOIY(o, opData->z80->getB());
}

void
CZ80::
f_rlc_po_iy_c(CZ80OpData *opData)
{
  schar o = opData->getSByte1();

  opData->z80->setC(opData->z80->getPOIY(o));

  opData->z80->rlcC();

  opData->z80->setPOIY(o, opData->z80->getC());
}

void
CZ80::
f_rlc_po_iy_d(CZ80OpData *opData)
{
  schar o = opData->getSByte1();

  opData->z80->setD(opData->z80->getPOIY(o));

  opData->z80->rlcD();

  opData->z80->setPOIY(o, opData->z80->getD());
}

void
CZ80::
f_rlc_po_iy_e(CZ80OpData *opData)
{
  schar o = opData->getSByte1();

  opData->z80->setE(opData->z80->getPOIY(o));

  opData->z80->rlcE();

  opData->z80->setPOIY(o, opData->z80->getE());
}

void
CZ80::
f_rlc_po_iy_h(CZ80OpData *opData)
{
  schar o = opData->getSByte1();

  opData->z80->setH(opData->z80->getPOIY(o));

  opData->z80->rlcH();

  opData->z80->setPOIY(o, opData->z80->getH());
}

void
CZ80::
f_rlc_po_iy_l(CZ80OpData *opData)
{
  schar o = opData->getSByte1();

  opData->z80->setL(opData->z80->getPOIY(o));

  opData->z80->rlcL();

  opData->z80->setPOIY(o, opData->z80->getL());
}

void
CZ80::
f_rlca(CZ80OpData *opData)
{
  opData->z80->rlca();
}

void
CZ80::
f_rld(CZ80OpData *opData)
{
  opData->z80->rld();
}

void
CZ80::
f_rr_a(CZ80OpData *opData)
{
  opData->z80->rrA();
}

void
CZ80::
f_rr_b(CZ80OpData *opData)
{
  opData->z80->rrB();
}

void
CZ80::
f_rr_c(CZ80OpData *opData)
{
  opData->z80->rrC();
}

void
CZ80::
f_rr_d(CZ80OpData *opData)
{
  opData->z80->rrD();
}

void
CZ80::
f_rr_e(CZ80OpData *opData)
{
  opData->z80->rrE();
}

void
CZ80::
f_rr_h(CZ80OpData *opData)
{
  opData->z80->rrH();
}

void
CZ80::
f_rr_l(CZ80OpData *opData)
{
  opData->z80->rrL();
}

void
CZ80::
f_rr_p_hl(CZ80OpData *opData)
{
  opData->z80->rrPHL();
}

void
CZ80::
f_rr_po_ix(CZ80OpData *opData)
{
  opData->z80->rrPOIX(opData->getSByte1());
}

void
CZ80::
f_rr_po_ix_a(CZ80OpData *opData)
{
  schar o = opData->getSByte1();

  opData->z80->setA(opData->z80->getPOIX(o));

  opData->z80->rrA();

  opData->z80->setPOIX(o, opData->z80->getA());
}

void
CZ80::
f_rr_po_ix_b(CZ80OpData *opData)
{
  schar o = opData->getSByte1();

  opData->z80->setB(opData->z80->getPOIX(o));

  opData->z80->rrB();

  opData->z80->setPOIX(o, opData->z80->getB());
}

void
CZ80::
f_rr_po_ix_c(CZ80OpData *opData)
{
  schar o = opData->getSByte1();

  opData->z80->setC(opData->z80->getPOIX(o));

  opData->z80->rrC();

  opData->z80->setPOIX(o, opData->z80->getC());
}

void
CZ80::
f_rr_po_ix_d(CZ80OpData *opData)
{
  schar o = opData->getSByte1();

  opData->z80->setD(opData->z80->getPOIX(o));

  opData->z80->rrD();

  opData->z80->setPOIX(o, opData->z80->getD());
}

void
CZ80::
f_rr_po_ix_e(CZ80OpData *opData)
{
  schar o = opData->getSByte1();

  opData->z80->setE(opData->z80->getPOIX(o));

  opData->z80->rrE();

  opData->z80->setPOIX(o, opData->z80->getE());
}

void
CZ80::
f_rr_po_ix_h(CZ80OpData *opData)
{
  schar o = opData->getSByte1();

  opData->z80->setH(opData->z80->getPOIX(o));

  opData->z80->rrH();

  opData->z80->setPOIX(o, opData->z80->getH());
}

void
CZ80::
f_rr_po_ix_l(CZ80OpData *opData)
{
  schar o = opData->getSByte1();

  opData->z80->setL(opData->z80->getPOIX(o));

  opData->z80->rrL();

  opData->z80->setPOIX(o, opData->z80->getL());
}

void
CZ80::
f_rr_po_iy(CZ80OpData *opData)
{
  opData->z80->rrPOIY(opData->getSByte1());
}

void
CZ80::
f_rr_po_iy_a(CZ80OpData *opData)
{
  schar o = opData->getSByte1();

  opData->z80->setA(opData->z80->getPOIY(o));

  opData->z80->rrA();

  opData->z80->setPOIY(o, opData->z80->getA());
}

void
CZ80::
f_rr_po_iy_b(CZ80OpData *opData)
{
  schar o = opData->getSByte1();

  opData->z80->setB(opData->z80->getPOIY(o));

  opData->z80->rrB();

  opData->z80->setPOIY(o, opData->z80->getB());
}

void
CZ80::
f_rr_po_iy_c(CZ80OpData *opData)
{
  schar o = opData->getSByte1();

  opData->z80->setC(opData->z80->getPOIY(o));

  opData->z80->rrC();

  opData->z80->setPOIY(o, opData->z80->getC());
}

void
CZ80::
f_rr_po_iy_d(CZ80OpData *opData)
{
  schar o = opData->getSByte1();

  opData->z80->setD(opData->z80->getPOIY(o));

  opData->z80->rrD();

  opData->z80->setPOIY(o, opData->z80->getD());
}

void
CZ80::
f_rr_po_iy_e(CZ80OpData *opData)
{
  schar o = opData->getSByte1();

  opData->z80->setE(opData->z80->getPOIY(o));

  opData->z80->rrE();

  opData->z80->setPOIY(o, opData->z80->getE());
}

void
CZ80::
f_rr_po_iy_h(CZ80OpData *opData)
{
  schar o = opData->getSByte1();

  opData->z80->setH(opData->z80->getPOIY(o));

  opData->z80->rrH();

  opData->z80->setPOIY(o, opData->z80->getH());
}

void
CZ80::
f_rr_po_iy_l(CZ80OpData *opData)
{
  schar o = opData->getSByte1();

  opData->z80->setL(opData->z80->getPOIY(o));

  opData->z80->rrL();

  opData->z80->setPOIY(o, opData->z80->getL());
}

void
CZ80::
f_rra(CZ80OpData *opData)
{
  opData->z80->rra();
}

void
CZ80::
f_rrc_a(CZ80OpData *opData)
{
  opData->z80->rrcA();
}

void
CZ80::
f_rrc_b(CZ80OpData *opData)
{
  opData->z80->rrcB();
}

void
CZ80::
f_rrc_c(CZ80OpData *opData)
{
  opData->z80->rrcC();
}

void
CZ80::
f_rrc_d(CZ80OpData *opData)
{
  opData->z80->rrcD();
}

void
CZ80::
f_rrc_e(CZ80OpData *opData)
{
  opData->z80->rrcE();
}

void
CZ80::
f_rrc_h(CZ80OpData *opData)
{
  opData->z80->rrcH();
}

void
CZ80::
f_rrc_l(CZ80OpData *opData)
{
  opData->z80->rrcL();
}

void
CZ80::
f_rrc_p_hl(CZ80OpData *opData)
{
  opData->z80->rrcPHL();
}

void
CZ80::
f_rrc_po_ix(CZ80OpData *opData)
{
  opData->z80->rrcPOIX(opData->getSByte1());
}

void
CZ80::
f_rrc_po_ix_a(CZ80OpData *opData)
{
  schar o = opData->getSByte1();

  opData->z80->setA(opData->z80->getPOIX(o));

  opData->z80->rrcA();

  opData->z80->setPOIX(o, opData->z80->getA());
}

void
CZ80::
f_rrc_po_ix_b(CZ80OpData *opData)
{
  schar o = opData->getSByte1();

  opData->z80->setB(opData->z80->getPOIX(o));

  opData->z80->rrcB();

  opData->z80->setPOIX(o, opData->z80->getB());
}

void
CZ80::
f_rrc_po_ix_c(CZ80OpData *opData)
{
  schar o = opData->getSByte1();

  opData->z80->setC(opData->z80->getPOIX(o));

  opData->z80->rrcC();

  opData->z80->setPOIX(o, opData->z80->getC());
}

void
CZ80::
f_rrc_po_ix_d(CZ80OpData *opData)
{
  schar o = opData->getSByte1();

  opData->z80->setD(opData->z80->getPOIX(o));

  opData->z80->rrcD();

  opData->z80->setPOIX(o, opData->z80->getD());
}

void
CZ80::
f_rrc_po_ix_e(CZ80OpData *opData)
{
  schar o = opData->getSByte1();

  opData->z80->setE(opData->z80->getPOIX(o));

  opData->z80->rrcE();

  opData->z80->setPOIX(o, opData->z80->getE());
}

void
CZ80::
f_rrc_po_ix_h(CZ80OpData *opData)
{
  schar o = opData->getSByte1();

  opData->z80->setH(opData->z80->getPOIX(o));

  opData->z80->rrcH();

  opData->z80->setPOIX(o, opData->z80->getH());
}

void
CZ80::
f_rrc_po_ix_l(CZ80OpData *opData)
{
  schar o = opData->getSByte1();

  opData->z80->setL(opData->z80->getPOIX(o));

  opData->z80->rrcL();

  opData->z80->setPOIX(o, opData->z80->getL());
}

void
CZ80::
f_rrc_po_iy(CZ80OpData *opData)
{
  opData->z80->rrcPOIY(opData->getSByte1());
}

void
CZ80::
f_rrc_po_iy_a(CZ80OpData *opData)
{
  schar o = opData->getSByte1();

  opData->z80->setA(opData->z80->getPOIY(o));

  opData->z80->rrcA();

  opData->z80->setPOIY(o, opData->z80->getA());
}

void
CZ80::
f_rrc_po_iy_b(CZ80OpData *opData)
{
  schar o = opData->getSByte1();

  opData->z80->setB(opData->z80->getPOIY(o));

  opData->z80->rrcB();

  opData->z80->setPOIY(o, opData->z80->getB());
}

void
CZ80::
f_rrc_po_iy_c(CZ80OpData *opData)
{
  schar o = opData->getSByte1();

  opData->z80->setC(opData->z80->getPOIY(o));

  opData->z80->rrcC();

  opData->z80->setPOIY(o, opData->z80->getC());
}

void
CZ80::
f_rrc_po_iy_d(CZ80OpData *opData)
{
  schar o = opData->getSByte1();

  opData->z80->setD(opData->z80->getPOIY(o));

  opData->z80->rrcD();

  opData->z80->setPOIY(o, opData->z80->getD());
}

void
CZ80::
f_rrc_po_iy_e(CZ80OpData *opData)
{
  schar o = opData->getSByte1();

  opData->z80->setE(opData->z80->getPOIY(o));

  opData->z80->rrcE();

  opData->z80->setPOIY(o, opData->z80->getE());
}

void
CZ80::
f_rrc_po_iy_h(CZ80OpData *opData)
{
  schar o = opData->getSByte1();

  opData->z80->setH(opData->z80->getPOIY(o));

  opData->z80->rrcH();

  opData->z80->setPOIY(o, opData->z80->getH());
}

void
CZ80::
f_rrc_po_iy_l(CZ80OpData *opData)
{
  schar o = opData->getSByte1();

  opData->z80->setL(opData->z80->getPOIY(o));

  opData->z80->rrcL();

  opData->z80->setPOIY(o, opData->z80->getL());
}

void
CZ80::
f_rrca(CZ80OpData *opData)
{
  opData->z80->rrca();
}

void
CZ80::
f_rrd(CZ80OpData *opData)
{
  opData->z80->rrd();
}

void
CZ80::
f_rst_n(CZ80OpData *opData)
{
  opData->z80->rst(opData->op->arg1);
}

void
CZ80::
f_sbc_a_a(CZ80OpData *opData)
{
  opData->z80->sbcA(opData->z80->getA());
}

void
CZ80::
f_sbc_a_b(CZ80OpData *opData)
{
  opData->z80->sbcA(opData->z80->getB());
}

void
CZ80::
f_sbc_a_c(CZ80OpData *opData)
{
  opData->z80->sbcA(opData->z80->getC());
}

void
CZ80::
f_sbc_a_d(CZ80OpData *opData)
{
  opData->z80->sbcA(opData->z80->getD());
}

void
CZ80::
f_sbc_a_e(CZ80OpData *opData)
{
  opData->z80->sbcA(opData->z80->getE());
}

void
CZ80::
f_sbc_a_h(CZ80OpData *opData)
{
  opData->z80->sbcA(opData->z80->getH());
}

void
CZ80::
f_sbc_a_l(CZ80OpData *opData)
{
  opData->z80->sbcA(opData->z80->getL());
}

void
CZ80::
f_sbc_a_ixh(CZ80OpData *opData)
{
  opData->z80->sbcA(opData->z80->getIXH());
}

void
CZ80::
f_sbc_a_ixl(CZ80OpData *opData)
{
  opData->z80->sbcA(opData->z80->getIXL());
}

void
CZ80::
f_sbc_a_iyh(CZ80OpData *opData)
{
  opData->z80->sbcA(opData->z80->getIYH());
}

void
CZ80::
f_sbc_a_iyl(CZ80OpData *opData)
{
  opData->z80->sbcA(opData->z80->getIYL());
}

void
CZ80::
f_sbc_a_p_hl(CZ80OpData *opData)
{
  opData->z80->sbcA(opData->z80->getPHL());
}

void
CZ80::
f_sbc_a_n(CZ80OpData *opData)
{
  opData->z80->sbcA(opData->getUByte2());
}

void
CZ80::
f_sbc_po_ix(CZ80OpData *opData)
{
  opData->z80->sbcA(opData->getPOIX1());
}

void
CZ80::
f_sbc_po_iy(CZ80OpData *opData)
{
  opData->z80->sbcA(opData->getPOIY1());
}

void
CZ80::
f_sbc_hl_bc(CZ80OpData *opData)
{
  opData->z80->sbcHL(opData->z80->getBC());
}

void
CZ80::
f_sbc_hl_de(CZ80OpData *opData)
{
  opData->z80->sbcHL(opData->z80->getDE());
}

void
CZ80::
f_sbc_hl_hl(CZ80OpData *opData)
{
  opData->z80->sbcHL(opData->z80->getHL());
}

void
CZ80::
f_sbc_hl_sp(CZ80OpData *opData)
{
  opData->z80->sbcHL(opData->z80->getSP());
}

void
CZ80::
f_scf(CZ80OpData *opData)
{
  opData->z80->scf();
}

void
CZ80::
f_set_po_ix_n(CZ80OpData *opData)
{
  opData->z80->setBitPOIX(opData->getSByte2(), uchar(opData->op->arg1));
}

void
CZ80::
f_set_po_iy_n(CZ80OpData *opData)
{
  opData->z80->setBitPOIY(opData->getSByte2(), uchar(opData->op->arg1));
}

void
CZ80::
f_set_a_n(CZ80OpData *opData)
{
  opData->z80->setBitA(uchar(opData->op->arg1));
}

void
CZ80::
f_set_b_n(CZ80OpData *opData)
{
  opData->z80->setBitB(uchar(opData->op->arg1));
}

void
CZ80::
f_set_c_n(CZ80OpData *opData)
{
  opData->z80->setBitC(uchar(opData->op->arg1));
}

void
CZ80::
f_set_d_n(CZ80OpData *opData)
{
  opData->z80->setBitD(uchar(opData->op->arg1));
}

void
CZ80::
f_set_e_n(CZ80OpData *opData)
{
  opData->z80->setBitE(uchar(opData->op->arg1));
}

void
CZ80::
f_set_h_n(CZ80OpData *opData)
{
  opData->z80->setBitH(uchar(opData->op->arg1));
}

void
CZ80::
f_set_l_n(CZ80OpData *opData)
{
  opData->z80->setBitL(uchar(opData->op->arg1));
}

void
CZ80::
f_set_p_hl_n(CZ80OpData *opData)
{
  opData->z80->setBitPHL(uchar(opData->op->arg1));
}

void
CZ80::
f_set_po_ix_a_n(CZ80OpData *opData)
{
  f_set_po_ix_a_n(opData, uchar(opData->op->arg1));
}

void
CZ80::
f_set_po_ix_b_n(CZ80OpData *opData)
{
  f_set_po_ix_b_n(opData, uchar(opData->op->arg1));
}

void
CZ80::
f_set_po_ix_c_n(CZ80OpData *opData)
{
  f_set_po_ix_c_n(opData, uchar(opData->op->arg1));
}

void
CZ80::
f_set_po_ix_d_n(CZ80OpData *opData)
{
  f_set_po_ix_d_n(opData, uchar(opData->op->arg1));
}

void
CZ80::
f_set_po_ix_e_n(CZ80OpData *opData)
{
  f_set_po_ix_e_n(opData, uchar(opData->op->arg1));
}

void
CZ80::
f_set_po_ix_h_n(CZ80OpData *opData)
{
  f_set_po_ix_h_n(opData, uchar(opData->op->arg1));
}

void
CZ80::
f_set_po_ix_l_n(CZ80OpData *opData)
{
  f_set_po_ix_l_n(opData, uchar(opData->op->arg1));
}

void
CZ80::
f_set_po_iy_a_n(CZ80OpData *opData)
{
  f_set_po_iy_a_n(opData, uchar(opData->op->arg1));
}

void
CZ80::
f_set_po_iy_b_n(CZ80OpData *opData)
{
  f_set_po_iy_b_n(opData, uchar(opData->op->arg1));
}

void
CZ80::
f_set_po_iy_c_n(CZ80OpData *opData)
{
  f_set_po_iy_c_n(opData, uchar(opData->op->arg1));
}

void
CZ80::
f_set_po_iy_d_n(CZ80OpData *opData)
{
  f_set_po_iy_d_n(opData, uchar(opData->op->arg1));
}

void
CZ80::
f_set_po_iy_e_n(CZ80OpData *opData)
{
  f_set_po_iy_e_n(opData, uchar(opData->op->arg1));
}

void
CZ80::
f_set_po_iy_h_n(CZ80OpData *opData)
{
  f_set_po_iy_h_n(opData, uchar(opData->op->arg1));
}

void
CZ80::
f_set_po_iy_l_n(CZ80OpData *opData)
{
  f_set_po_iy_l_n(opData, uchar(opData->op->arg1));
}

void
CZ80::
f_set_po_ix_a_n(CZ80OpData *opData, uchar n)
{
  schar o = opData->getSByte2();

  opData->z80->setA(opData->z80->getPOIX(o));

  opData->z80->setBitA(n);

  opData->z80->setPOIX(o, opData->z80->getA());
}

void
CZ80::
f_set_po_ix_b_n(CZ80OpData *opData, uchar n)
{
  schar o = opData->getSByte2();

  opData->z80->setB(opData->z80->getPOIX(o));

  opData->z80->setBitB(n);

  opData->z80->setPOIX(o, opData->z80->getB());
}

void
CZ80::
f_set_po_ix_c_n(CZ80OpData *opData, uchar n)
{
  schar o = opData->getSByte2();

  opData->z80->setC(opData->z80->getPOIX(o));

  opData->z80->setBitC(n);

  opData->z80->setPOIX(o, opData->z80->getC());
}

void
CZ80::
f_set_po_ix_d_n(CZ80OpData *opData, uchar n)
{
  schar o = opData->getSByte2();

  opData->z80->setD(opData->z80->getPOIX(o));

  opData->z80->setBitD(n);

  opData->z80->setPOIX(o, opData->z80->getD());
}

void
CZ80::
f_set_po_ix_e_n(CZ80OpData *opData, uchar n)
{
  schar o = opData->getSByte2();

  opData->z80->setE(opData->z80->getPOIX(o));

  opData->z80->setBitE(n);

  opData->z80->setPOIX(o, opData->z80->getE());
}

void
CZ80::
f_set_po_ix_h_n(CZ80OpData *opData, uchar n)
{
  schar o = opData->getSByte2();

  opData->z80->setH(opData->z80->getPOIX(o));

  opData->z80->setBitH(n);

  opData->z80->setPOIX(o, opData->z80->getH());
}

void
CZ80::
f_set_po_ix_l_n(CZ80OpData *opData, uchar n)
{
  schar o = opData->getSByte2();

  opData->z80->setL(opData->z80->getPOIX(o));

  opData->z80->setBitL(n);

  opData->z80->setPOIX(o, opData->z80->getL());
}

void
CZ80::
f_set_po_iy_a_n(CZ80OpData *opData, uchar n)
{
  schar o = opData->getSByte2();

  opData->z80->setA(opData->z80->getPOIY(o));

  opData->z80->setBitA(n);

  opData->z80->setPOIY(o, opData->z80->getA());
}

void
CZ80::
f_set_po_iy_b_n(CZ80OpData *opData, uchar n)
{
  schar o = opData->getSByte2();

  opData->z80->setB(opData->z80->getPOIY(o));

  opData->z80->setBitB(n);

  opData->z80->setPOIY(o, opData->z80->getB());
}

void
CZ80::
f_set_po_iy_c_n(CZ80OpData *opData, uchar n)
{
  schar o = opData->getSByte2();

  opData->z80->setC(opData->z80->getPOIY(o));

  opData->z80->setBitC(n);

  opData->z80->setPOIY(o, opData->z80->getC());
}

void
CZ80::
f_set_po_iy_d_n(CZ80OpData *opData, uchar n)
{
  schar o = opData->getSByte2();

  opData->z80->setD(opData->z80->getPOIY(o));

  opData->z80->setBitD(n);

  opData->z80->setPOIY(o, opData->z80->getD());
}

void
CZ80::
f_set_po_iy_e_n(CZ80OpData *opData, uchar n)
{
  schar o = opData->getSByte2();

  opData->z80->setE(opData->z80->getPOIY(o));

  opData->z80->setBitE(n);

  opData->z80->setPOIY(o, opData->z80->getE());
}

void
CZ80::
f_set_po_iy_h_n(CZ80OpData *opData, uchar n)
{
  schar o = opData->getSByte2();

  opData->z80->setH(opData->z80->getPOIY(o));

  opData->z80->setBitH(n);

  opData->z80->setPOIY(o, opData->z80->getH());
}

void
CZ80::
f_set_po_iy_l_n(CZ80OpData *opData, uchar n)
{
  schar o = opData->getSByte2();

  opData->z80->setL(opData->z80->getPOIY(o));

  opData->z80->setBitL(n);

  opData->z80->setPOIY(o, opData->z80->getL());
}

void
CZ80::
f_sla_a(CZ80OpData *opData)
{
  opData->z80->slaA();
}

void
CZ80::
f_sla_b(CZ80OpData *opData)
{
  opData->z80->slaB();
}

void
CZ80::
f_sla_c(CZ80OpData *opData)
{
  opData->z80->slaC();
}

void
CZ80::
f_sla_d(CZ80OpData *opData)
{
  opData->z80->slaD();
}

void
CZ80::
f_sla_e(CZ80OpData *opData)
{
  opData->z80->slaE();
}

void
CZ80::
f_sla_h(CZ80OpData *opData)
{
  opData->z80->slaH();
}

void
CZ80::
f_sla_l(CZ80OpData *opData)
{
  opData->z80->slaL();
}

void
CZ80::
f_sla_p_hl(CZ80OpData *opData)
{
  opData->z80->slaPHL();
}

void
CZ80::
f_sla_po_ix(CZ80OpData *opData)
{
  opData->z80->slaPOIX(opData->getSByte1());
}

void
CZ80::
f_sla_po_ix_a(CZ80OpData *opData)
{
  schar o = opData->getSByte1();

  opData->z80->setA(opData->z80->getPOIX(o));

  opData->z80->slaA();

  opData->z80->setPOIX(o, opData->z80->getA());
}

void
CZ80::
f_sla_po_ix_b(CZ80OpData *opData)
{
  schar o = opData->getSByte1();

  opData->z80->setB(opData->z80->getPOIX(o));

  opData->z80->slaB();

  opData->z80->setPOIX(o, opData->z80->getB());
}

void
CZ80::
f_sla_po_ix_c(CZ80OpData *opData)
{
  schar o = opData->getSByte1();

  opData->z80->setC(opData->z80->getPOIX(o));

  opData->z80->slaC();

  opData->z80->setPOIX(o, opData->z80->getC());
}

void
CZ80::
f_sla_po_ix_d(CZ80OpData *opData)
{
  schar o = opData->getSByte1();

  opData->z80->setD(opData->z80->getPOIX(o));

  opData->z80->slaD();

  opData->z80->setPOIX(o, opData->z80->getD());
}

void
CZ80::
f_sla_po_ix_e(CZ80OpData *opData)
{
  schar o = opData->getSByte1();

  opData->z80->setE(opData->z80->getPOIX(o));

  opData->z80->slaE();

  opData->z80->setPOIX(o, opData->z80->getE());
}

void
CZ80::
f_sla_po_ix_h(CZ80OpData *opData)
{
  schar o = opData->getSByte1();

  opData->z80->setH(opData->z80->getPOIX(o));

  opData->z80->slaH();

  opData->z80->setPOIX(o, opData->z80->getH());
}

void
CZ80::
f_sla_po_ix_l(CZ80OpData *opData)
{
  schar o = opData->getSByte1();

  opData->z80->setL(opData->z80->getPOIX(o));

  opData->z80->slaL();

  opData->z80->setPOIX(o, opData->z80->getL());
}

void
CZ80::
f_sla_po_iy(CZ80OpData *opData)
{
  opData->z80->slaPOIY(opData->getSByte1());
}

void
CZ80::
f_sla_po_iy_a(CZ80OpData *opData)
{
  schar o = opData->getSByte1();

  opData->z80->setA(opData->z80->getPOIY(o));

  opData->z80->slaA();

  opData->z80->setPOIY(o, opData->z80->getA());
}

void
CZ80::
f_sla_po_iy_b(CZ80OpData *opData)
{
  schar o = opData->getSByte1();

  opData->z80->setB(opData->z80->getPOIY(o));

  opData->z80->slaB();

  opData->z80->setPOIY(o, opData->z80->getB());
}

void
CZ80::
f_sla_po_iy_c(CZ80OpData *opData)
{
  schar o = opData->getSByte1();

  opData->z80->setC(opData->z80->getPOIY(o));

  opData->z80->slaC();

  opData->z80->setPOIY(o, opData->z80->getC());
}

void
CZ80::
f_sla_po_iy_d(CZ80OpData *opData)
{
  schar o = opData->getSByte1();

  opData->z80->setD(opData->z80->getPOIY(o));

  opData->z80->slaD();

  opData->z80->setPOIY(o, opData->z80->getD());
}

void
CZ80::
f_sla_po_iy_e(CZ80OpData *opData)
{
  schar o = opData->getSByte1();

  opData->z80->setE(opData->z80->getPOIY(o));

  opData->z80->slaE();

  opData->z80->setPOIY(o, opData->z80->getE());
}

void
CZ80::
f_sla_po_iy_h(CZ80OpData *opData)
{
  schar o = opData->getSByte1();

  opData->z80->setH(opData->z80->getPOIY(o));

  opData->z80->slaH();

  opData->z80->setPOIY(o, opData->z80->getH());
}

void
CZ80::
f_sla_po_iy_l(CZ80OpData *opData)
{
  schar o = opData->getSByte1();

  opData->z80->setL(opData->z80->getPOIY(o));

  opData->z80->slaL();

  opData->z80->setPOIY(o, opData->z80->getL());
}

void
CZ80::
f_sll_a(CZ80OpData *opData)
{
  opData->z80->sllA();
}

void
CZ80::
f_sll_b(CZ80OpData *opData)
{
  opData->z80->sllB();
}

void
CZ80::
f_sll_c(CZ80OpData *opData)
{
  opData->z80->sllC();
}

void
CZ80::
f_sll_d(CZ80OpData *opData)
{
  opData->z80->sllD();
}

void
CZ80::
f_sll_e(CZ80OpData *opData)
{
  opData->z80->sllE();
}

void
CZ80::
f_sll_h(CZ80OpData *opData)
{
  opData->z80->sllH();
}

void
CZ80::
f_sll_l(CZ80OpData *opData)
{
  opData->z80->sllL();
}

void
CZ80::
f_sll_p_hl(CZ80OpData *opData)
{
  opData->z80->sllPHL();
}

void
CZ80::
f_sll_po_ix(CZ80OpData *opData)
{
  opData->z80->sllPOIX(opData->getSByte1());
}

void
CZ80::
f_sll_po_ix_a(CZ80OpData *opData)
{
  schar o = opData->getSByte1();

  opData->z80->setA(opData->z80->getPOIX(o));

  opData->z80->sllA();

  opData->z80->setPOIX(o, opData->z80->getA());
}

void
CZ80::
f_sll_po_ix_b(CZ80OpData *opData)
{
  schar o = opData->getSByte1();

  opData->z80->setB(opData->z80->getPOIX(o));

  opData->z80->sllB();

  opData->z80->setPOIX(o, opData->z80->getB());
}

void
CZ80::
f_sll_po_ix_c(CZ80OpData *opData)
{
  schar o = opData->getSByte1();

  opData->z80->setC(opData->z80->getPOIX(o));

  opData->z80->sllC();

  opData->z80->setPOIX(o, opData->z80->getC());
}

void
CZ80::
f_sll_po_ix_d(CZ80OpData *opData)
{
  schar o = opData->getSByte1();

  opData->z80->setD(opData->z80->getPOIX(o));

  opData->z80->sllD();

  opData->z80->setPOIX(o, opData->z80->getD());
}

void
CZ80::
f_sll_po_ix_e(CZ80OpData *opData)
{
  schar o = opData->getSByte1();

  opData->z80->setE(opData->z80->getPOIX(o));

  opData->z80->sllE();

  opData->z80->setPOIX(o, opData->z80->getE());
}

void
CZ80::
f_sll_po_ix_h(CZ80OpData *opData)
{
  schar o = opData->getSByte1();

  opData->z80->setH(opData->z80->getPOIX(o));

  opData->z80->sllH();

  opData->z80->setPOIX(o, opData->z80->getH());
}

void
CZ80::
f_sll_po_ix_l(CZ80OpData *opData)
{
  schar o = opData->getSByte1();

  opData->z80->setL(opData->z80->getPOIX(o));

  opData->z80->sllL();

  opData->z80->setPOIX(o, opData->z80->getL());
}

void
CZ80::
f_sll_po_iy(CZ80OpData *opData)
{
  opData->z80->sllPOIY(opData->getSByte1());
}

void
CZ80::
f_sll_po_iy_a(CZ80OpData *opData)
{
  schar o = opData->getSByte1();

  opData->z80->setA(opData->z80->getPOIY(o));

  opData->z80->sllA();

  opData->z80->setPOIY(o, opData->z80->getA());
}

void
CZ80::
f_sll_po_iy_b(CZ80OpData *opData)
{
  schar o = opData->getSByte1();

  opData->z80->setB(opData->z80->getPOIY(o));

  opData->z80->sllB();

  opData->z80->setPOIY(o, opData->z80->getB());
}

void
CZ80::
f_sll_po_iy_c(CZ80OpData *opData)
{
  schar o = opData->getSByte1();

  opData->z80->setC(opData->z80->getPOIY(o));

  opData->z80->sllC();

  opData->z80->setPOIY(o, opData->z80->getC());
}

void
CZ80::
f_sll_po_iy_d(CZ80OpData *opData)
{
  schar o = opData->getSByte1();

  opData->z80->setD(opData->z80->getPOIY(o));

  opData->z80->sllD();

  opData->z80->setPOIY(o, opData->z80->getD());
}

void
CZ80::
f_sll_po_iy_e(CZ80OpData *opData)
{
  schar o = opData->getSByte1();

  opData->z80->setE(opData->z80->getPOIY(o));

  opData->z80->sllE();

  opData->z80->setPOIY(o, opData->z80->getE());
}

void
CZ80::
f_sll_po_iy_h(CZ80OpData *opData)
{
  schar o = opData->getSByte1();

  opData->z80->setH(opData->z80->getPOIY(o));

  opData->z80->sllH();

  opData->z80->setPOIY(o, opData->z80->getH());
}

void
CZ80::
f_sll_po_iy_l(CZ80OpData *opData)
{
  schar o = opData->getSByte1();

  opData->z80->setL(opData->z80->getPOIY(o));

  opData->z80->sllL();

  opData->z80->setPOIY(o, opData->z80->getL());
}

void
CZ80::
f_sra_a(CZ80OpData *opData)
{
  opData->z80->sraA();
}

void
CZ80::
f_sra_b(CZ80OpData *opData)
{
  opData->z80->sraB();
}

void
CZ80::
f_sra_c(CZ80OpData *opData)
{
  opData->z80->sraC();
}

void
CZ80::
f_sra_d(CZ80OpData *opData)
{
  opData->z80->sraD();
}

void
CZ80::
f_sra_e(CZ80OpData *opData)
{
  opData->z80->sraE();
}

void
CZ80::
f_sra_h(CZ80OpData *opData)
{
  opData->z80->sraH();
}

void
CZ80::
f_sra_l(CZ80OpData *opData)
{
  opData->z80->sraL();
}

void
CZ80::
f_sra_p_hl(CZ80OpData *opData)
{
  opData->z80->sraPHL();
}

void
CZ80::
f_sra_po_ix(CZ80OpData *opData)
{
  opData->z80->sraPOIX(opData->getSByte1());
}

void
CZ80::
f_sra_po_ix_a(CZ80OpData *opData)
{
  schar o = opData->getSByte1();

  opData->z80->setA(opData->z80->getPOIX(o));

  opData->z80->sraA();

  opData->z80->setPOIX(o, opData->z80->getA());
}

void
CZ80::
f_sra_po_ix_b(CZ80OpData *opData)
{
  schar o = opData->getSByte1();

  opData->z80->setB(opData->z80->getPOIX(o));

  opData->z80->sraB();

  opData->z80->setPOIX(o, opData->z80->getB());
}

void
CZ80::
f_sra_po_ix_c(CZ80OpData *opData)
{
  schar o = opData->getSByte1();

  opData->z80->setC(opData->z80->getPOIX(o));

  opData->z80->sraC();

  opData->z80->setPOIX(o, opData->z80->getC());
}

void
CZ80::
f_sra_po_ix_d(CZ80OpData *opData)
{
  schar o = opData->getSByte1();

  opData->z80->setD(opData->z80->getPOIX(o));

  opData->z80->sraD();

  opData->z80->setPOIX(o, opData->z80->getD());
}

void
CZ80::
f_sra_po_ix_e(CZ80OpData *opData)
{
  schar o = opData->getSByte1();

  opData->z80->setE(opData->z80->getPOIX(o));

  opData->z80->sraE();

  opData->z80->setPOIX(o, opData->z80->getE());
}

void
CZ80::
f_sra_po_ix_h(CZ80OpData *opData)
{
  schar o = opData->getSByte1();

  opData->z80->setH(opData->z80->getPOIX(o));

  opData->z80->sraH();

  opData->z80->setPOIX(o, opData->z80->getH());
}

void
CZ80::
f_sra_po_ix_l(CZ80OpData *opData)
{
  schar o = opData->getSByte1();

  opData->z80->setL(opData->z80->getPOIX(o));

  opData->z80->sraL();

  opData->z80->setPOIX(o, opData->z80->getL());
}

void
CZ80::
f_sra_po_iy(CZ80OpData *opData)
{
  opData->z80->sraPOIY(opData->getSByte1());
}

void
CZ80::
f_sra_po_iy_a(CZ80OpData *opData)
{
  schar o = opData->getSByte1();

  opData->z80->setA(opData->z80->getPOIY(o));

  opData->z80->sraA();

  opData->z80->setPOIY(o, opData->z80->getA());
}

void
CZ80::
f_sra_po_iy_b(CZ80OpData *opData)
{
  schar o = opData->getSByte1();

  opData->z80->setB(opData->z80->getPOIY(o));

  opData->z80->sraB();

  opData->z80->setPOIY(o, opData->z80->getB());
}

void
CZ80::
f_sra_po_iy_c(CZ80OpData *opData)
{
  schar o = opData->getSByte1();

  opData->z80->setC(opData->z80->getPOIY(o));

  opData->z80->sraC();

  opData->z80->setPOIY(o, opData->z80->getC());
}

void
CZ80::
f_sra_po_iy_d(CZ80OpData *opData)
{
  schar o = opData->getSByte1();

  opData->z80->setD(opData->z80->getPOIY(o));

  opData->z80->sraD();

  opData->z80->setPOIY(o, opData->z80->getD());
}

void
CZ80::
f_sra_po_iy_e(CZ80OpData *opData)
{
  schar o = opData->getSByte1();

  opData->z80->setE(opData->z80->getPOIY(o));

  opData->z80->sraE();

  opData->z80->setPOIY(o, opData->z80->getE());
}

void
CZ80::
f_sra_po_iy_h(CZ80OpData *opData)
{
  schar o = opData->getSByte1();

  opData->z80->setH(opData->z80->getPOIY(o));

  opData->z80->sraH();

  opData->z80->setPOIY(o, opData->z80->getH());
}

void
CZ80::
f_sra_po_iy_l(CZ80OpData *opData)
{
  schar o = opData->getSByte1();

  opData->z80->setL(opData->z80->getPOIY(o));

  opData->z80->sraL();

  opData->z80->setPOIY(o, opData->z80->getL());
}

void
CZ80::
f_srl_a(CZ80OpData *opData)
{
  opData->z80->srlA();
}

void
CZ80::
f_srl_b(CZ80OpData *opData)
{
  opData->z80->srlB();
}

void
CZ80::
f_srl_c(CZ80OpData *opData)
{
  opData->z80->srlC();
}

void
CZ80::
f_srl_d(CZ80OpData *opData)
{
  opData->z80->srlD();
}

void
CZ80::
f_srl_e(CZ80OpData *opData)
{
  opData->z80->srlE();
}

void
CZ80::
f_srl_h(CZ80OpData *opData)
{
  opData->z80->srlH();
}

void
CZ80::
f_srl_l(CZ80OpData *opData)
{
  opData->z80->srlL();
}

void
CZ80::
f_srl_p_hl(CZ80OpData *opData)
{
  opData->z80->srlPHL();
}

void
CZ80::
f_srl_po_ix(CZ80OpData *opData)
{
  opData->z80->srlPOIX(opData->getSByte1());
}

void
CZ80::
f_srl_po_ix_a(CZ80OpData *opData)
{
  schar o = opData->getSByte1();

  opData->z80->setA(opData->z80->getPOIX(o));

  opData->z80->srlA();

  opData->z80->setPOIX(o, opData->z80->getA());
}

void
CZ80::
f_srl_po_ix_b(CZ80OpData *opData)
{
  schar o = opData->getSByte1();

  opData->z80->setB(opData->z80->getPOIX(o));

  opData->z80->srlB();

  opData->z80->setPOIX(o, opData->z80->getB());
}

void
CZ80::
f_srl_po_ix_c(CZ80OpData *opData)
{
  schar o = opData->getSByte1();

  opData->z80->setC(opData->z80->getPOIX(o));

  opData->z80->srlC();

  opData->z80->setPOIX(o, opData->z80->getC());
}

void
CZ80::
f_srl_po_ix_d(CZ80OpData *opData)
{
  schar o = opData->getSByte1();

  opData->z80->setD(opData->z80->getPOIX(o));

  opData->z80->srlD();

  opData->z80->setPOIX(o, opData->z80->getD());
}

void
CZ80::
f_srl_po_ix_e(CZ80OpData *opData)
{
  schar o = opData->getSByte1();

  opData->z80->setE(opData->z80->getPOIX(o));

  opData->z80->srlE();

  opData->z80->setPOIX(o, opData->z80->getE());
}

void
CZ80::
f_srl_po_ix_h(CZ80OpData *opData)
{
  schar o = opData->getSByte1();

  opData->z80->setH(opData->z80->getPOIX(o));

  opData->z80->srlH();

  opData->z80->setPOIX(o, opData->z80->getH());
}

void
CZ80::
f_srl_po_ix_l(CZ80OpData *opData)
{
  schar o = opData->getSByte1();

  opData->z80->setL(opData->z80->getPOIX(o));

  opData->z80->srlL();

  opData->z80->setPOIX(o, opData->z80->getL());
}

void
CZ80::
f_srl_po_iy(CZ80OpData *opData)
{
  opData->z80->srlPOIY(opData->getSByte1());
}

void
CZ80::
f_srl_po_iy_a(CZ80OpData *opData)
{
  schar o = opData->getSByte1();

  opData->z80->setA(opData->z80->getPOIY(o));

  opData->z80->srlA();

  opData->z80->setPOIY(o, opData->z80->getA());
}

void
CZ80::
f_srl_po_iy_b(CZ80OpData *opData)
{
  schar o = opData->getSByte1();

  opData->z80->setB(opData->z80->getPOIY(o));

  opData->z80->srlB();

  opData->z80->setPOIY(o, opData->z80->getB());
}

void
CZ80::
f_srl_po_iy_c(CZ80OpData *opData)
{
  schar o = opData->getSByte1();

  opData->z80->setC(opData->z80->getPOIY(o));

  opData->z80->srlC();

  opData->z80->setPOIY(o, opData->z80->getC());
}

void
CZ80::
f_srl_po_iy_d(CZ80OpData *opData)
{
  schar o = opData->getSByte1();

  opData->z80->setD(opData->z80->getPOIY(o));

  opData->z80->srlD();

  opData->z80->setPOIY(o, opData->z80->getD());
}

void
CZ80::
f_srl_po_iy_e(CZ80OpData *opData)
{
  schar o = opData->getSByte1();

  opData->z80->setE(opData->z80->getPOIY(o));

  opData->z80->srlE();

  opData->z80->setPOIY(o, opData->z80->getE());
}

void
CZ80::
f_srl_po_iy_h(CZ80OpData *opData)
{
  schar o = opData->getSByte1();

  opData->z80->setH(opData->z80->getPOIY(o));

  opData->z80->srlH();

  opData->z80->setPOIY(o, opData->z80->getH());
}

void
CZ80::
f_srl_po_iy_l(CZ80OpData *opData)
{
  schar o = opData->getSByte1();

  opData->z80->setL(opData->z80->getPOIY(o));

  opData->z80->srlL();

  opData->z80->setPOIY(o, opData->z80->getL());
}

void
CZ80::
f_sub_a(CZ80OpData *opData)
{
  opData->z80->subA(opData->z80->getA());
}

void
CZ80::
f_sub_b(CZ80OpData *opData)
{
  opData->z80->subA(opData->z80->getB());
}

void
CZ80::
f_sub_c(CZ80OpData *opData)
{
  opData->z80->subA(opData->z80->getC());
}

void
CZ80::
f_sub_d(CZ80OpData *opData)
{
  opData->z80->subA(opData->z80->getD());
}

void
CZ80::
f_sub_e(CZ80OpData *opData)
{
  opData->z80->subA(opData->z80->getE());
}

void
CZ80::
f_sub_h(CZ80OpData *opData)
{
  opData->z80->subA(opData->z80->getH());
}

void
CZ80::
f_sub_l(CZ80OpData *opData)
{
  opData->z80->subA(opData->z80->getL());
}

void
CZ80::
f_sub_ixh(CZ80OpData *opData)
{
  opData->z80->subA(opData->z80->getIXH());
}

void
CZ80::
f_sub_ixl(CZ80OpData *opData)
{
  opData->z80->subA(opData->z80->getIXL());
}

void
CZ80::
f_sub_iyh(CZ80OpData *opData)
{
  opData->z80->subA(opData->z80->getIYH());
}

void
CZ80::
f_sub_iyl(CZ80OpData *opData)
{
  opData->z80->subA(opData->z80->getIYL());
}

void
CZ80::
f_sub_p_hl(CZ80OpData *opData)
{
  opData->z80->subA(opData->z80->getPHL());
}

void
CZ80::
f_sub_n(CZ80OpData *opData)
{
  opData->z80->subA(opData->getUByte1());
}

void
CZ80::
f_sub_po_ix(CZ80OpData *opData)
{
  opData->z80->subA(opData->getPOIX1());
}

void
CZ80::
f_sub_po_iy(CZ80OpData *opData)
{
  opData->z80->subA(opData->getPOIY1());
}

void
CZ80::
f_xor_a(CZ80OpData *opData)
{
  opData->z80->xorA(opData->z80->getA());
}

void
CZ80::
f_xor_b(CZ80OpData *opData)
{
  opData->z80->xorA(opData->z80->getB());
}

void
CZ80::
f_xor_c(CZ80OpData *opData)
{
  opData->z80->xorA(opData->z80->getC());
}

void
CZ80::
f_xor_d(CZ80OpData *opData)
{
  opData->z80->xorA(opData->z80->getD());
}

void
CZ80::
f_xor_e(CZ80OpData *opData)
{
  opData->z80->xorA(opData->z80->getE());
}

void
CZ80::
f_xor_h(CZ80OpData *opData)
{
  opData->z80->xorA(opData->z80->getH());
}

void
CZ80::
f_xor_l(CZ80OpData *opData)
{
  opData->z80->xorA(opData->z80->getL());
}

void
CZ80::
f_xor_ixh(CZ80OpData *opData)
{
  opData->z80->xorA(opData->z80->getIXH());
}

void
CZ80::
f_xor_ixl(CZ80OpData *opData)
{
  opData->z80->xorA(opData->z80->getIXL());
}

void
CZ80::
f_xor_iyh(CZ80OpData *opData)
{
  opData->z80->xorA(opData->z80->getIYH());
}

void
CZ80::
f_xor_iyl(CZ80OpData *opData)
{
  opData->z80->xorA(opData->z80->getIYL());
}

void
CZ80::
f_xor_p_hl(CZ80OpData *opData)
{
  opData->z80->xorA(opData->z80->getPHL());
}

void
CZ80::
f_xor_n(CZ80OpData *opData)
{
  opData->z80->xorA(opData->getUByte1());
}

void
CZ80::
f_xor_po_ix(CZ80OpData *opData)
{
  opData->z80->xorA(opData->getPOIX1());
}

void
CZ80::
f_xor_po_iy(CZ80OpData *opData)
{
  opData->z80->xorA(opData->getPOIY1());
}

void
CZ80::
f_err(CZ80OpData *opData)
{
  std::cerr << "unimplemented " << opData->getName() << std::endl;

  f_halt(opData);
}
