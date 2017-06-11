#include <CZ80Fn.h>

//#define OP_DEBUG 1

void
CZ80::
f_adc_a_a(CZ80OpData *op_data)
{
  op_data->z80->adcA(op_data->z80->getA());
}

void
CZ80::
f_adc_a_b(CZ80OpData *op_data)
{
  op_data->z80->adcA(op_data->z80->getB());
}

void
CZ80::
f_adc_a_c(CZ80OpData *op_data)
{
  op_data->z80->adcA(op_data->z80->getC());
}

void
CZ80::
f_adc_a_d(CZ80OpData *op_data)
{
  op_data->z80->adcA(op_data->z80->getD());
}

void
CZ80::
f_adc_a_e(CZ80OpData *op_data)
{
  op_data->z80->adcA(op_data->z80->getE());
}

void
CZ80::
f_adc_a_h(CZ80OpData *op_data)
{
  op_data->z80->adcA(op_data->z80->getH());
}

void
CZ80::
f_adc_a_l(CZ80OpData *op_data)
{
  op_data->z80->adcA(op_data->z80->getL());
}

void
CZ80::
f_adc_a_ixh(CZ80OpData *op_data)
{
  op_data->z80->adcA(op_data->z80->getIXH());
}

void
CZ80::
f_adc_a_ixl(CZ80OpData *op_data)
{
  op_data->z80->adcA(op_data->z80->getIXL());
}

void
CZ80::
f_adc_a_iyh(CZ80OpData *op_data)
{
  op_data->z80->adcA(op_data->z80->getIYH());
}

void
CZ80::
f_adc_a_iyl(CZ80OpData *op_data)
{
  op_data->z80->adcA(op_data->z80->getIYL());
}

void
CZ80::
f_adc_a_p_hl(CZ80OpData *op_data)
{
  op_data->z80->adcA(op_data->z80->getPHL());
}

void
CZ80::
f_adc_a_n(CZ80OpData *op_data)
{
  op_data->z80->adcA(op_data->getUByte2());
}

void
CZ80::
f_adc_a_po_ix(CZ80OpData *op_data)
{
  op_data->z80->adcA(op_data->getPOIX2());
}

void
CZ80::
f_adc_a_po_iy(CZ80OpData *op_data)
{
  op_data->z80->adcA(op_data->getPOIY2());
}

void
CZ80::
f_adc_hl_bc(CZ80OpData *op_data)
{
  op_data->z80->adcHL(op_data->z80->getBC());
}

void
CZ80::
f_adc_hl_de(CZ80OpData *op_data)
{
  op_data->z80->adcHL(op_data->z80->getDE());
}

void
CZ80::
f_adc_hl_hl(CZ80OpData *op_data)
{
  op_data->z80->adcHL(op_data->z80->getHL());
}

void
CZ80::
f_adc_hl_sp(CZ80OpData *op_data)
{
  op_data->z80->adcHL(op_data->z80->getSP());
}

void
CZ80::
f_add_a_a(CZ80OpData *op_data)
{
  op_data->z80->addA(op_data->z80->getA());
}

void
CZ80::
f_add_a_b(CZ80OpData *op_data)
{
  op_data->z80->addA(op_data->z80->getB());
}

void
CZ80::
f_add_a_c(CZ80OpData *op_data)
{
  op_data->z80->addA(op_data->z80->getC());
}

void
CZ80::
f_add_a_d(CZ80OpData *op_data)
{
  op_data->z80->addA(op_data->z80->getD());
}

void
CZ80::
f_add_a_e(CZ80OpData *op_data)
{
  op_data->z80->addA(op_data->z80->getE());
}

void
CZ80::
f_add_a_h(CZ80OpData *op_data)
{
  op_data->z80->addA(op_data->z80->getH());
}

void
CZ80::
f_add_a_l(CZ80OpData *op_data)
{
  op_data->z80->addA(op_data->z80->getL());
}

void
CZ80::
f_add_a_ixh(CZ80OpData *op_data)
{
  op_data->z80->addA(op_data->z80->getIXH());
}

void
CZ80::
f_add_a_ixl(CZ80OpData *op_data)
{
  op_data->z80->addA(op_data->z80->getIXL());
}

void
CZ80::
f_add_a_iyh(CZ80OpData *op_data)
{
  op_data->z80->addA(op_data->z80->getIYH());
}

void
CZ80::
f_add_a_iyl(CZ80OpData *op_data)
{
  op_data->z80->addA(op_data->z80->getIYL());
}

void
CZ80::
f_add_a_p_hl(CZ80OpData *op_data)
{
  op_data->z80->addA(op_data->z80->getPHL());
}

void
CZ80::
f_add_a_n(CZ80OpData *op_data)
{
  op_data->z80->addA(op_data->getUByte2());
}

void
CZ80::
f_add_a_po_ix(CZ80OpData *op_data)
{
  op_data->z80->addA(op_data->getPOIX2());
}

void
CZ80::
f_add_a_po_iy(CZ80OpData *op_data)
{
  op_data->z80->addA(op_data->getPOIY2());
}

void
CZ80::
f_add_hl_bc(CZ80OpData *op_data)
{
  op_data->z80->addHL(op_data->z80->getBC());
}

void
CZ80::
f_add_hl_de(CZ80OpData *op_data)
{
  op_data->z80->addHL(op_data->z80->getDE());
}

void
CZ80::
f_add_hl_hl(CZ80OpData *op_data)
{
  op_data->z80->addHL(op_data->z80->getHL());
}

void
CZ80::
f_add_hl_sp(CZ80OpData *op_data)
{
  op_data->z80->addHL(op_data->z80->getSP());
}

void
CZ80::
f_add_ix_bc(CZ80OpData *op_data)
{
  op_data->z80->addIX(op_data->z80->getBC());
}

void
CZ80::
f_add_ix_de(CZ80OpData *op_data)
{
  op_data->z80->addIX(op_data->z80->getDE());
}

void
CZ80::
f_add_ix_ix(CZ80OpData *op_data)
{
  op_data->z80->addIX(op_data->z80->getIX());
}

void
CZ80::
f_add_ix_sp(CZ80OpData *op_data)
{
  op_data->z80->addIX(op_data->z80->getSP());
}

void
CZ80::
f_add_iy_bc(CZ80OpData *op_data)
{
  op_data->z80->addIY(op_data->z80->getBC());
}

void
CZ80::
f_add_iy_de(CZ80OpData *op_data)
{
  op_data->z80->addIY(op_data->z80->getDE());
}

void
CZ80::
f_add_iy_iy(CZ80OpData *op_data)
{
  op_data->z80->addIY(op_data->z80->getIY());
}

void
CZ80::
f_add_iy_sp(CZ80OpData *op_data)
{
  op_data->z80->addIY(op_data->z80->getSP());
}

void
CZ80::
f_and_a(CZ80OpData *op_data)
{
  op_data->z80->andA(op_data->z80->getA());
}

void
CZ80::
f_and_b(CZ80OpData *op_data)
{
  op_data->z80->andA(op_data->z80->getB());
}

void
CZ80::
f_and_c(CZ80OpData *op_data)
{
  op_data->z80->andA(op_data->z80->getC());
}

void
CZ80::
f_and_d(CZ80OpData *op_data)
{
  op_data->z80->andA(op_data->z80->getD());
}

void
CZ80::
f_and_e(CZ80OpData *op_data)
{
  op_data->z80->andA(op_data->z80->getE());
}

void
CZ80::
f_and_h(CZ80OpData *op_data)
{
  op_data->z80->andA(op_data->z80->getH());
}

void
CZ80::
f_and_l(CZ80OpData *op_data)
{
  op_data->z80->andA(op_data->z80->getL());
}

void
CZ80::
f_and_ixh(CZ80OpData *op_data)
{
  op_data->z80->andA(op_data->z80->getIXH());
}

void
CZ80::
f_and_ixl(CZ80OpData *op_data)
{
  op_data->z80->andA(op_data->z80->getIXL());
}

void
CZ80::
f_and_iyh(CZ80OpData *op_data)
{
  op_data->z80->andA(op_data->z80->getIYH());
}

void
CZ80::
f_and_iyl(CZ80OpData *op_data)
{
  op_data->z80->andA(op_data->z80->getIYL());
}

void
CZ80::
f_and_p_hl(CZ80OpData *op_data)
{
  op_data->z80->andA(op_data->z80->getPHL());
}

void
CZ80::
f_and_n(CZ80OpData *op_data)
{
  op_data->z80->andA(op_data->getUByte1());
}

void
CZ80::
f_and_po_ix(CZ80OpData *op_data)
{
  op_data->z80->andA(op_data->getPOIX1());
}

void
CZ80::
f_and_po_iy(CZ80OpData *op_data)
{
  op_data->z80->andA(op_data->getPOIY1());
}

void
CZ80::
f_bit_a_n(CZ80OpData *op_data)
{
  op_data->z80->tstBitA(op_data->op->arg1);
}

void
CZ80::
f_bit_b_n(CZ80OpData *op_data)
{
  op_data->z80->tstBitB(op_data->op->arg1);
}

void
CZ80::
f_bit_c_n(CZ80OpData *op_data)
{
  op_data->z80->tstBitC(op_data->op->arg1);
}

void
CZ80::
f_bit_d_n(CZ80OpData *op_data)
{
  op_data->z80->tstBitD(op_data->op->arg1);
}

void
CZ80::
f_bit_e_n(CZ80OpData *op_data)
{
  op_data->z80->tstBitE(op_data->op->arg1);
}

void
CZ80::
f_bit_h_n(CZ80OpData *op_data)
{
  op_data->z80->tstBitH(op_data->op->arg1);
}

void
CZ80::
f_bit_l_n(CZ80OpData *op_data)
{
  op_data->z80->tstBitL(op_data->op->arg1);
}

void
CZ80::
f_bit_p_hl_n(CZ80OpData *op_data)
{
  op_data->z80->tstBitPHL(op_data->op->arg1);
}

void
CZ80::
f_bit_po_ix_n(CZ80OpData *op_data)
{
  op_data->z80->tstBitPOIX(op_data->getSByte2(), op_data->op->arg1, false);
}

void
CZ80::
f_bit_po_ix_ns(CZ80OpData *op_data)
{
  op_data->z80->tstBitPOIX(op_data->getSByte2(), op_data->op->arg1, true);
}

void
CZ80::
f_bit_po_iy_n(CZ80OpData *op_data)
{
  op_data->z80->tstBitPOIY(op_data->getSByte2(), op_data->op->arg1, false);
}

void
CZ80::
f_bit_po_iy_ns(CZ80OpData *op_data)
{
  op_data->z80->tstBitPOIY(op_data->getSByte2(), op_data->op->arg1, true);
}

void
CZ80::
f_call(CZ80OpData *op_data)
{
  op_data->z80->call(op_data->getUWord1());
}

void
CZ80::
f_call_z(CZ80OpData *op_data)
{
  if (op_data->z80->tstZFlag()) {
    op_data->z80->call(op_data->getUWord2());

    op_data->z80->incT(7);
  }
}

void
CZ80::
f_call_nz(CZ80OpData *op_data)
{
  if (! op_data->z80->tstZFlag()) {
    op_data->z80->call(op_data->getUWord2());

    op_data->z80->incT(7);
  }
}

void
CZ80::
f_call_c(CZ80OpData *op_data)
{
  if (op_data->z80->tstCFlag()) {
    op_data->z80->call(op_data->getUWord2());

    op_data->z80->incT(7);
  }
}

void
CZ80::
f_call_nc(CZ80OpData *op_data)
{
  if (! op_data->z80->tstCFlag()) {
    op_data->z80->call(op_data->getUWord2());

    op_data->z80->incT(7);
  }
}

void
CZ80::
f_call_pe(CZ80OpData *op_data)
{
  if (op_data->z80->tstPFlag()) {
    op_data->z80->call(op_data->getUWord2());

    op_data->z80->incT(7);
  }
}

void
CZ80::
f_call_po(CZ80OpData *op_data)
{
  if (! op_data->z80->tstPFlag()) {
    op_data->z80->call(op_data->getUWord2());

    op_data->z80->incT(7);
  }
}

void
CZ80::
f_call_p(CZ80OpData *op_data)
{
  if (! op_data->z80->tstSFlag()) {
    op_data->z80->call(op_data->getUWord2());

    op_data->z80->incT(7);
  }
}

void
CZ80::
f_call_m(CZ80OpData *op_data)
{
  if (op_data->z80->tstSFlag()) {
    op_data->z80->call(op_data->getUWord2());

    op_data->z80->incT(7);
  }
}

void
CZ80::
f_ccf(CZ80OpData *op_data)
{
  op_data->z80->ccf();
}

void
CZ80::
f_cp_a(CZ80OpData *op_data)
{
  op_data->z80->cpA(op_data->z80->getA());
}

void
CZ80::
f_cp_b(CZ80OpData *op_data)
{
  op_data->z80->cpA(op_data->z80->getB());
}

void
CZ80::
f_cp_c(CZ80OpData *op_data)
{
  op_data->z80->cpA(op_data->z80->getC());
}

void
CZ80::
f_cp_d(CZ80OpData *op_data)
{
  op_data->z80->cpA(op_data->z80->getD());
}

void
CZ80::
f_cp_e(CZ80OpData *op_data)
{
  op_data->z80->cpA(op_data->z80->getE());
}

void
CZ80::
f_cp_h(CZ80OpData *op_data)
{
  op_data->z80->cpA(op_data->z80->getH());
}

void
CZ80::
f_cp_l(CZ80OpData *op_data)
{
  op_data->z80->cpA(op_data->z80->getL());
}

void
CZ80::
f_cp_ixh(CZ80OpData *op_data)
{
  op_data->z80->cpA(op_data->z80->getIXH());
}

void
CZ80::
f_cp_ixl(CZ80OpData *op_data)
{
  op_data->z80->cpA(op_data->z80->getIXL());
}

void
CZ80::
f_cp_iyh(CZ80OpData *op_data)
{
  op_data->z80->cpA(op_data->z80->getIYH());
}

void
CZ80::
f_cp_iyl(CZ80OpData *op_data)
{
  op_data->z80->cpA(op_data->z80->getIYL());
}

void
CZ80::
f_cp_p_hl(CZ80OpData *op_data)
{
  op_data->z80->cpA(op_data->z80->getPHL());
}

void
CZ80::
f_cp_n(CZ80OpData *op_data)
{
  op_data->z80->cpA(op_data->getUByte1());
}

void
CZ80::
f_cp_po_ix(CZ80OpData *op_data)
{
  op_data->z80->cpA(op_data->getPOIX1());
}

void
CZ80::
f_cp_po_iy(CZ80OpData *op_data)
{
  op_data->z80->cpA(op_data->getPOIY1());
}

void
CZ80::
f_cpd(CZ80OpData *op_data)
{
  op_data->z80->cpd();
}

void
CZ80::
f_cpdr(CZ80OpData *op_data)
{
  op_data->z80->cpdr();
}

void
CZ80::
f_cpi(CZ80OpData *op_data)
{
  op_data->z80->cpi();
}

void
CZ80::
f_cpir(CZ80OpData *op_data)
{
  op_data->z80->cpir();
}

void
CZ80::
f_cpl(CZ80OpData *op_data)
{
  op_data->z80->cpl();
}

void
CZ80::
f_daa(CZ80OpData *op_data)
{
  op_data->z80->daa();
}

void
CZ80::
f_dec_a(CZ80OpData *op_data)
{
  op_data->z80->decA();
}

void
CZ80::
f_dec_b(CZ80OpData *op_data)
{
  op_data->z80->decB();
}

void
CZ80::
f_dec_c(CZ80OpData *op_data)
{
  op_data->z80->decC();
}

void
CZ80::
f_dec_d(CZ80OpData *op_data)
{
  op_data->z80->decD();
}

void
CZ80::
f_dec_e(CZ80OpData *op_data)
{
  op_data->z80->decE();
}

void
CZ80::
f_dec_h(CZ80OpData *op_data)
{
  op_data->z80->decH();
}

void
CZ80::
f_dec_l(CZ80OpData *op_data)
{
  op_data->z80->decL();
}

void
CZ80::
f_dec_p_hl(CZ80OpData *op_data)
{
  op_data->z80->decPHL();
}

void
CZ80::
f_dec_po_ix(CZ80OpData *op_data)
{
  op_data->z80->decPOIX(op_data->getSByte1());
}

void
CZ80::
f_dec_po_iy(CZ80OpData *op_data)
{
  op_data->z80->decPOIY(op_data->getSByte1());
}

void
CZ80::
f_dec_bc(CZ80OpData *op_data)
{
  op_data->z80->decBC();
}

void
CZ80::
f_dec_de(CZ80OpData *op_data)
{
  op_data->z80->decDE();
}

void
CZ80::
f_dec_hl(CZ80OpData *op_data)
{
  op_data->z80->decHL();
}

void
CZ80::
f_dec_sp(CZ80OpData *op_data)
{
  op_data->z80->decSP();
}

void
CZ80::
f_dec_ix(CZ80OpData *op_data)
{
  op_data->z80->decIX();
}

void
CZ80::
f_dec_iy(CZ80OpData *op_data)
{
  op_data->z80->decIY();
}

void
CZ80::
f_dec_ixh(CZ80OpData *op_data)
{
  op_data->z80->decIXH();
}

void
CZ80::
f_dec_ixl(CZ80OpData *op_data)
{
  op_data->z80->decIXL();
}

void
CZ80::
f_dec_iyh(CZ80OpData *op_data)
{
  op_data->z80->decIYH();
}

void
CZ80::
f_dec_iyl(CZ80OpData *op_data)
{
  op_data->z80->decIYL();
}

void
CZ80::
f_di(CZ80OpData *op_data)
{
  op_data->z80->di();
}

void
CZ80::
f_djnz(CZ80OpData *op_data)
{
  op_data->z80->decB();

  if (! op_data->z80->tstZFlag()) {
    op_data->z80->tracePC();

    op_data->z80->setPC(op_data->getRPC1());

    op_data->z80->incT(5);
  }
}

void
CZ80::
f_ei(CZ80OpData *op_data)
{
  op_data->z80->ei();
}

void
CZ80::
f_ex_de_hl(CZ80OpData *op_data)
{
  op_data->z80->ex_de_hl();
}

void
CZ80::
f_ex_af_af1(CZ80OpData *op_data)
{
  op_data->z80->ex_af_af1();
}

void
CZ80::
f_ex_p_sp_hl(CZ80OpData *op_data)
{
  op_data->z80->ex_p_sp_hl();
}

void
CZ80::
f_ex_p_sp_ix(CZ80OpData *op_data)
{
  op_data->z80->ex_p_sp_ix();
}

void
CZ80::
f_ex_p_sp_iy(CZ80OpData *op_data)
{
  op_data->z80->ex_p_sp_iy();
}

void
CZ80::
f_exx(CZ80OpData *op_data)
{
  op_data->z80->exx();
}

void
CZ80::
f_halt(CZ80OpData *op_data)
{
  op_data->z80->halt();
}

void
CZ80::
f_im_n(CZ80OpData *op_data)
{
  op_data->z80->setIM(op_data->op->arg1);
}

//-----------

void
CZ80::
f_in_a_p_n(CZ80OpData *op_data)
{
  op_data->z80->setA(op_data->z80->in(op_data->getUByte2(), 0));
}

void
CZ80::
f_in_a_p_c(CZ80OpData *op_data)
{
  op_data->z80->setA(op_data->z80->inC());
}

void
CZ80::
f_in_b_p_c(CZ80OpData *op_data)
{
  op_data->z80->setB(op_data->z80->inC());
}

void
CZ80::
f_in_c_p_c(CZ80OpData *op_data)
{
  op_data->z80->setC(op_data->z80->inC());
}

void
CZ80::
f_in_d_p_c(CZ80OpData *op_data)
{
  op_data->z80->setD(op_data->z80->inC());
}

void
CZ80::
f_in_e_p_c(CZ80OpData *op_data)
{
  op_data->z80->setE(op_data->z80->inC());
}

void
CZ80::
f_in_h_p_c(CZ80OpData *op_data)
{
  op_data->z80->setH(op_data->z80->inC());
}

void
CZ80::
f_in_l_p_c(CZ80OpData *op_data)
{
  op_data->z80->setL(op_data->z80->inC());
}

void
CZ80::
f_in_n_p_c(CZ80OpData *op_data)
{
  op_data->z80->inC();
}

//-----------

void
CZ80::
f_inc_a(CZ80OpData *op_data)
{
  op_data->z80->incA();
}

void
CZ80::
f_inc_b(CZ80OpData *op_data)
{
  op_data->z80->incB();
}

void
CZ80::
f_inc_c(CZ80OpData *op_data)
{
  op_data->z80->incC();
}

void
CZ80::
f_inc_d(CZ80OpData *op_data)
{
  op_data->z80->incD();
}

void
CZ80::
f_inc_e(CZ80OpData *op_data)
{
  op_data->z80->incE();
}

void
CZ80::
f_inc_h(CZ80OpData *op_data)
{
  op_data->z80->incH();
}

void
CZ80::
f_inc_l(CZ80OpData *op_data)
{
  op_data->z80->incL();
}

void
CZ80::
f_inc_p_hl(CZ80OpData *op_data)
{
  op_data->z80->incPHL();
}

void
CZ80::
f_inc_po_ix(CZ80OpData *op_data)
{
  op_data->z80->incPOIX(op_data->getSByte1());
}

void
CZ80::
f_inc_po_iy(CZ80OpData *op_data)
{
  op_data->z80->incPOIY(op_data->getSByte1());
}

void
CZ80::
f_inc_bc(CZ80OpData *op_data)
{
  op_data->z80->incBC();
}

void
CZ80::
f_inc_de(CZ80OpData *op_data)
{
  op_data->z80->incDE();
}

void
CZ80::
f_inc_hl(CZ80OpData *op_data)
{
  op_data->z80->incHL();
}

void
CZ80::
f_inc_sp(CZ80OpData *op_data)
{
  op_data->z80->incSP();
}

void
CZ80::
f_inc_ix(CZ80OpData *op_data)
{
  op_data->z80->incIX();
}

void
CZ80::
f_inc_iy(CZ80OpData *op_data)
{
  op_data->z80->incIY();
}

void
CZ80::
f_inc_ixh(CZ80OpData *op_data)
{
  op_data->z80->incIXH();
}

void
CZ80::
f_inc_ixl(CZ80OpData *op_data)
{
  op_data->z80->incIXL();
}

void
CZ80::
f_inc_iyh(CZ80OpData *op_data)
{
  op_data->z80->incIYH();
}

void
CZ80::
f_inc_iyl(CZ80OpData *op_data)
{
  op_data->z80->incIYL();
}

void
CZ80::
f_ind(CZ80OpData *op_data)
{
  op_data->z80->setPHL(op_data->z80->inC());

  op_data->z80->decHL();
  op_data->z80->decB();
}

void
CZ80::
f_indr(CZ80OpData *op_data)
{
  do {
    f_ind(op_data);

    op_data->z80->incT(21);
  }
  while (op_data->z80->getB() != 0);

  op_data->z80->decT(5);
}

void
CZ80::
f_ini(CZ80OpData *op_data)
{
  op_data->z80->setPHL(op_data->z80->inC());

  op_data->z80->incHL();
  op_data->z80->decB();
}

void
CZ80::
f_inir(CZ80OpData *op_data)
{
  do {
    f_ini(op_data);

    op_data->z80->incT(21);
  }
  while (op_data->z80->getB() != 0);

  op_data->z80->decT(5);
}

void
CZ80::
f_jp(CZ80OpData *op_data)
{
  op_data->z80->tracePC();

  op_data->z80->setPC(op_data->getUWord1());
}

void
CZ80::
f_jp_z(CZ80OpData *op_data)
{
  if (op_data->z80->tstZFlag()) {
    op_data->z80->tracePC();

    op_data->z80->setPC(op_data->getUWord2());
  }
}

void
CZ80::
f_jp_nz(CZ80OpData *op_data)
{
  if (! op_data->z80->tstZFlag()) {
    op_data->z80->tracePC();

    op_data->z80->setPC(op_data->getUWord2());
  }
}

void
CZ80::
f_jp_c(CZ80OpData *op_data)
{
  if (op_data->z80->tstCFlag()) {
    op_data->z80->tracePC();

    op_data->z80->setPC(op_data->getUWord2());
  }
}

void
CZ80::
f_jp_nc(CZ80OpData *op_data)
{
  if (! op_data->z80->tstCFlag()) {
    op_data->z80->tracePC();

    op_data->z80->setPC(op_data->getUWord2());
  }
}

void
CZ80::
f_jp_pe(CZ80OpData *op_data)
{
  if (op_data->z80->tstPFlag()) {
    op_data->z80->tracePC();

    op_data->z80->setPC(op_data->getUWord2());
  }
}

void
CZ80::
f_jp_po(CZ80OpData *op_data)
{
  if (! op_data->z80->tstPFlag()) {
    op_data->z80->tracePC();

    op_data->z80->setPC(op_data->getUWord2());
  }
}

void
CZ80::
f_jp_p(CZ80OpData *op_data)
{
  if (! op_data->z80->tstSFlag()) {
    op_data->z80->tracePC();

    op_data->z80->setPC(op_data->getUWord2());
  }
}

void
CZ80::
f_jp_m(CZ80OpData *op_data)
{
  if (op_data->z80->tstSFlag()) {
    op_data->z80->tracePC();

    op_data->z80->setPC(op_data->getUWord2());
  }
}

void
CZ80::
f_jp_hl(CZ80OpData *op_data)
{
  op_data->z80->tracePC();

  op_data->z80->setPC(op_data->z80->getHL());
}

void
CZ80::
f_jp_ix(CZ80OpData *op_data)
{
  op_data->z80->tracePC();

  op_data->z80->setPC(op_data->z80->getIX());
}

void
CZ80::
f_jp_iy(CZ80OpData *op_data)
{
  op_data->z80->tracePC();

  op_data->z80->setPC(op_data->z80->getIY());
}

void
CZ80::
f_jr(CZ80OpData *op_data)
{
  op_data->z80->tracePC();

  op_data->z80->setPC(op_data->getRPC1());
}

void
CZ80::
f_jr_z(CZ80OpData *op_data)
{
  if (op_data->z80->tstZFlag()) {
    op_data->z80->tracePC();

    op_data->z80->setPC(op_data->getRPC2());

    op_data->z80->incT(5);
  }
}

void
CZ80::
f_jr_nz(CZ80OpData *op_data)
{
  if (! op_data->z80->tstZFlag()) {
    op_data->z80->tracePC();

    op_data->z80->setPC(op_data->getRPC2());

    op_data->z80->incT(5);
  }
}

void
CZ80::
f_jr_c(CZ80OpData *op_data)
{
  if (op_data->z80->tstCFlag()) {
    op_data->z80->tracePC();

    op_data->z80->setPC(op_data->getRPC2());

    op_data->z80->incT(5);
  }
}

void
CZ80::
f_jr_nc(CZ80OpData *op_data)
{
  if (! op_data->z80->tstCFlag()) {
    op_data->z80->tracePC();

    op_data->z80->setPC(op_data->getRPC2());

    op_data->z80->incT(5);
  }
}

void
CZ80::
f_ld_a_n(CZ80OpData *op_data)
{
  op_data->z80->setA(op_data->getUByte2());
}

void
CZ80::
f_ld_b_n(CZ80OpData *op_data)
{
  op_data->z80->setB(op_data->getUByte2());
}

void
CZ80::
f_ld_c_n(CZ80OpData *op_data)
{
  op_data->z80->setC(op_data->getUByte2());
}

void
CZ80::
f_ld_d_n(CZ80OpData *op_data)
{
  op_data->z80->setD(op_data->getUByte2());
}

void
CZ80::
f_ld_e_n(CZ80OpData *op_data)
{
  op_data->z80->setE(op_data->getUByte2());
}

void
CZ80::
f_ld_h_n(CZ80OpData *op_data)
{
  op_data->z80->setH(op_data->getUByte2());
}

void
CZ80::
f_ld_l_n(CZ80OpData *op_data)
{
  op_data->z80->setL(op_data->getUByte2());
}

void
CZ80::
f_ld_bc_nn(CZ80OpData *op_data)
{
  op_data->z80->setBC(op_data->getUWord2());
}

void
CZ80::
f_ld_de_nn(CZ80OpData *op_data)
{
  op_data->z80->setDE(op_data->getUWord2());
}

void
CZ80::
f_ld_hl_nn(CZ80OpData *op_data)
{
  op_data->z80->setHL(op_data->getUWord2());
}

void
CZ80::
f_ld_sp_nn(CZ80OpData *op_data)
{
  op_data->z80->setSP(op_data->getUWord2());
}

void
CZ80::
f_ld_ix_nn(CZ80OpData *op_data)
{
  op_data->z80->setIX(op_data->getUWord2());
}

void
CZ80::
f_ld_iy_nn(CZ80OpData *op_data)
{
  op_data->z80->setIY(op_data->getUWord2());
}

void
CZ80::
f_ld_ixh_n(CZ80OpData *op_data)
{
  op_data->z80->setIXH(op_data->getUByte2());
}

void
CZ80::
f_ld_ixl_n(CZ80OpData *op_data)
{
  op_data->z80->setIXL(op_data->getUByte2());
}

void
CZ80::
f_ld_iyh_n(CZ80OpData *op_data)
{
  op_data->z80->setIYH(op_data->getUByte2());
}

void
CZ80::
f_ld_iyl_n(CZ80OpData *op_data)
{
  op_data->z80->setIYL(op_data->getUByte2());
}

void
CZ80::
f_ld_a_a(CZ80OpData *op_data)
{
  op_data->z80->setA(op_data->z80->getA());
}

void
CZ80::
f_ld_a_b(CZ80OpData *op_data)
{
  op_data->z80->setA(op_data->z80->getB());
}

void
CZ80::
f_ld_a_c(CZ80OpData *op_data)
{
  op_data->z80->setA(op_data->z80->getC());
}

void
CZ80::
f_ld_a_d(CZ80OpData *op_data)
{
  op_data->z80->setA(op_data->z80->getD());
}

void
CZ80::
f_ld_a_e(CZ80OpData *op_data)
{
  op_data->z80->setA(op_data->z80->getE());
}

void
CZ80::
f_ld_a_h(CZ80OpData *op_data)
{
  op_data->z80->setA(op_data->z80->getH());
}

void
CZ80::
f_ld_a_l(CZ80OpData *op_data)
{
  op_data->z80->setA(op_data->z80->getL());
}

void
CZ80::
f_ld_a_i(CZ80OpData *op_data)
{
  op_data->z80->setA(op_data->z80->getI());

  op_data->z80->setRFlags(op_data->z80->getI());

  op_data->z80->resHFlag();
  op_data->z80->resNFlag();

  op_data->z80->setPFlag(op_data->z80->getIFF2());
}

void
CZ80::
f_ld_a_r(CZ80OpData *op_data)
{
  op_data->z80->setA(op_data->z80->getR());

  op_data->z80->setRFlags(op_data->z80->getI());

  op_data->z80->resHFlag();
  op_data->z80->resNFlag();

  op_data->z80->setPFlag(op_data->z80->getIFF2());
}

void
CZ80::
f_ld_a_ixh(CZ80OpData *op_data)
{
  op_data->z80->setA(op_data->z80->getIXH());
}

void
CZ80::
f_ld_a_ixl(CZ80OpData *op_data)
{
  op_data->z80->setA(op_data->z80->getIXL());
}

void
CZ80::
f_ld_a_iyh(CZ80OpData *op_data)
{
  op_data->z80->setA(op_data->z80->getIYH());
}

void
CZ80::
f_ld_a_iyl(CZ80OpData *op_data)
{
  op_data->z80->setA(op_data->z80->getIYL());
}

void
CZ80::
f_ld_b_a(CZ80OpData *op_data)
{
  op_data->z80->setB(op_data->z80->getA());
}

void
CZ80::
f_ld_b_b(CZ80OpData *op_data)
{
  op_data->z80->setB(op_data->z80->getB());
}

void
CZ80::
f_ld_b_c(CZ80OpData *op_data)
{
  op_data->z80->setB(op_data->z80->getC());
}

void
CZ80::
f_ld_b_d(CZ80OpData *op_data)
{
  op_data->z80->setB(op_data->z80->getD());
}

void
CZ80::
f_ld_b_e(CZ80OpData *op_data)
{
  op_data->z80->setB(op_data->z80->getE());
}

void
CZ80::
f_ld_b_h(CZ80OpData *op_data)
{
  op_data->z80->setB(op_data->z80->getH());
}

void
CZ80::
f_ld_b_l(CZ80OpData *op_data)
{
  op_data->z80->setB(op_data->z80->getL());
}

void
CZ80::
f_ld_b_ixh(CZ80OpData *op_data)
{
  op_data->z80->setB(op_data->z80->getIXH());
}

void
CZ80::
f_ld_b_ixl(CZ80OpData *op_data)
{
  op_data->z80->setB(op_data->z80->getIXL());
}

void
CZ80::
f_ld_b_iyh(CZ80OpData *op_data)
{
  op_data->z80->setB(op_data->z80->getIYH());
}

void
CZ80::
f_ld_b_iyl(CZ80OpData *op_data)
{
  op_data->z80->setB(op_data->z80->getIYL());
}

void
CZ80::
f_ld_c_a(CZ80OpData *op_data)
{
  op_data->z80->setC(op_data->z80->getA());
}

void
CZ80::
f_ld_c_b(CZ80OpData *op_data)
{
  op_data->z80->setC(op_data->z80->getB());
}

void
CZ80::
f_ld_c_c(CZ80OpData *op_data)
{
  op_data->z80->setC(op_data->z80->getC());
}

void
CZ80::
f_ld_c_d(CZ80OpData *op_data)
{
  op_data->z80->setC(op_data->z80->getD());
}

void
CZ80::
f_ld_c_e(CZ80OpData *op_data)
{
  op_data->z80->setC(op_data->z80->getE());
}

void
CZ80::
f_ld_c_h(CZ80OpData *op_data)
{
  op_data->z80->setC(op_data->z80->getH());
}

void
CZ80::
f_ld_c_l(CZ80OpData *op_data)
{
  op_data->z80->setC(op_data->z80->getL());
}

void
CZ80::
f_ld_c_ixh(CZ80OpData *op_data)
{
  op_data->z80->setC(op_data->z80->getIXH());
}

void
CZ80::
f_ld_c_ixl(CZ80OpData *op_data)
{
  op_data->z80->setC(op_data->z80->getIXL());
}

void
CZ80::
f_ld_c_iyh(CZ80OpData *op_data)
{
  op_data->z80->setC(op_data->z80->getIYH());
}

void
CZ80::
f_ld_c_iyl(CZ80OpData *op_data)
{
  op_data->z80->setC(op_data->z80->getIYL());
}

void
CZ80::
f_ld_d_a(CZ80OpData *op_data)
{
  op_data->z80->setD(op_data->z80->getA());
}

void
CZ80::
f_ld_d_b(CZ80OpData *op_data)
{
  op_data->z80->setD(op_data->z80->getB());
}

void
CZ80::
f_ld_d_c(CZ80OpData *op_data)
{
  op_data->z80->setD(op_data->z80->getC());
}

void
CZ80::
f_ld_d_d(CZ80OpData *op_data)
{
  op_data->z80->setD(op_data->z80->getD());
}

void
CZ80::
f_ld_d_e(CZ80OpData *op_data)
{
  op_data->z80->setD(op_data->z80->getE());
}

void
CZ80::
f_ld_d_h(CZ80OpData *op_data)
{
  op_data->z80->setD(op_data->z80->getH());
}

void
CZ80::
f_ld_d_l(CZ80OpData *op_data)
{
  op_data->z80->setD(op_data->z80->getL());
}

void
CZ80::
f_ld_d_ixh(CZ80OpData *op_data)
{
  op_data->z80->setD(op_data->z80->getIXH());
}

void
CZ80::
f_ld_d_ixl(CZ80OpData *op_data)
{
  op_data->z80->setD(op_data->z80->getIXL());
}

void
CZ80::
f_ld_d_iyh(CZ80OpData *op_data)
{
  op_data->z80->setD(op_data->z80->getIYH());
}

void
CZ80::
f_ld_d_iyl(CZ80OpData *op_data)
{
  op_data->z80->setD(op_data->z80->getIYL());
}

void
CZ80::
f_ld_e_a(CZ80OpData *op_data)
{
  op_data->z80->setE(op_data->z80->getA());
}

void
CZ80::
f_ld_e_b(CZ80OpData *op_data)
{
  op_data->z80->setE(op_data->z80->getB());
}

void
CZ80::
f_ld_e_c(CZ80OpData *op_data)
{
  op_data->z80->setE(op_data->z80->getC());
}

void
CZ80::
f_ld_e_d(CZ80OpData *op_data)
{
  op_data->z80->setE(op_data->z80->getD());
}

void
CZ80::
f_ld_e_e(CZ80OpData *op_data)
{
  op_data->z80->setE(op_data->z80->getE());
}

void
CZ80::
f_ld_e_h(CZ80OpData *op_data)
{
  op_data->z80->setE(op_data->z80->getH());
}

void
CZ80::
f_ld_e_l(CZ80OpData *op_data)
{
  op_data->z80->setE(op_data->z80->getL());
}

void
CZ80::
f_ld_e_ixh(CZ80OpData *op_data)
{
  op_data->z80->setE(op_data->z80->getIXH());
}

void
CZ80::
f_ld_e_ixl(CZ80OpData *op_data)
{
  op_data->z80->setE(op_data->z80->getIXL());
}

void
CZ80::
f_ld_e_iyh(CZ80OpData *op_data)
{
  op_data->z80->setE(op_data->z80->getIYH());
}

void
CZ80::
f_ld_e_iyl(CZ80OpData *op_data)
{
  op_data->z80->setE(op_data->z80->getIYL());
}

void
CZ80::
f_ld_h_a(CZ80OpData *op_data)
{
  op_data->z80->setH(op_data->z80->getA());
}

void
CZ80::
f_ld_h_b(CZ80OpData *op_data)
{
  op_data->z80->setH(op_data->z80->getB());
}

void
CZ80::
f_ld_h_c(CZ80OpData *op_data)
{
  op_data->z80->setH(op_data->z80->getC());
}

void
CZ80::
f_ld_h_d(CZ80OpData *op_data)
{
  op_data->z80->setH(op_data->z80->getD());
}

void
CZ80::
f_ld_h_e(CZ80OpData *op_data)
{
  op_data->z80->setH(op_data->z80->getE());
}

void
CZ80::
f_ld_h_h(CZ80OpData *op_data)
{
  op_data->z80->setH(op_data->z80->getH());
}

void
CZ80::
f_ld_h_l(CZ80OpData *op_data)
{
  op_data->z80->setH(op_data->z80->getL());
}

void
CZ80::
f_ld_l_a(CZ80OpData *op_data)
{
  op_data->z80->setL(op_data->z80->getA());
}

void
CZ80::
f_ld_l_b(CZ80OpData *op_data)
{
  op_data->z80->setL(op_data->z80->getB());
}

void
CZ80::
f_ld_l_c(CZ80OpData *op_data)
{
  op_data->z80->setL(op_data->z80->getC());
}

void
CZ80::
f_ld_l_d(CZ80OpData *op_data)
{
  op_data->z80->setL(op_data->z80->getD());
}

void
CZ80::
f_ld_l_e(CZ80OpData *op_data)
{
  op_data->z80->setL(op_data->z80->getE());
}

void
CZ80::
f_ld_l_h(CZ80OpData *op_data)
{
  op_data->z80->setL(op_data->z80->getH());
}

void
CZ80::
f_ld_l_l(CZ80OpData *op_data)
{
  op_data->z80->setL(op_data->z80->getL());
}

void
CZ80::
f_ld_ixh_a(CZ80OpData *op_data)
{
  op_data->z80->setIXH(op_data->z80->getA());
}

void
CZ80::
f_ld_ixh_b(CZ80OpData *op_data)
{
  op_data->z80->setIXH(op_data->z80->getB());
}

void
CZ80::
f_ld_ixh_c(CZ80OpData *op_data)
{
  op_data->z80->setIXH(op_data->z80->getC());
}

void
CZ80::
f_ld_ixh_d(CZ80OpData *op_data)
{
  op_data->z80->setIXH(op_data->z80->getD());
}

void
CZ80::
f_ld_ixh_e(CZ80OpData *op_data)
{
  op_data->z80->setIXH(op_data->z80->getE());
}

void
CZ80::
f_ld_ixh_ixh(CZ80OpData *op_data)
{
  op_data->z80->setIXH(op_data->z80->getIXH());
}

void
CZ80::
f_ld_ixh_ixl(CZ80OpData *op_data)
{
  op_data->z80->setIXH(op_data->z80->getIXL());
}

void
CZ80::
f_ld_ixl_a(CZ80OpData *op_data)
{
  op_data->z80->setIXL(op_data->z80->getA());
}

void
CZ80::
f_ld_ixl_b(CZ80OpData *op_data)
{
  op_data->z80->setIXL(op_data->z80->getB());
}

void
CZ80::
f_ld_ixl_c(CZ80OpData *op_data)
{
  op_data->z80->setIXL(op_data->z80->getC());
}

void
CZ80::
f_ld_ixl_d(CZ80OpData *op_data)
{
  op_data->z80->setIXL(op_data->z80->getD());
}

void
CZ80::
f_ld_ixl_e(CZ80OpData *op_data)
{
  op_data->z80->setIXL(op_data->z80->getE());
}

void
CZ80::
f_ld_ixl_ixh(CZ80OpData *op_data)
{
  op_data->z80->setIXL(op_data->z80->getIXH());
}

void
CZ80::
f_ld_ixl_ixl(CZ80OpData *op_data)
{
  op_data->z80->setIXL(op_data->z80->getIXL());
}

void
CZ80::
f_ld_iyh_a(CZ80OpData *op_data)
{
  op_data->z80->setIYH(op_data->z80->getA());
}

void
CZ80::
f_ld_iyh_b(CZ80OpData *op_data)
{
  op_data->z80->setIYH(op_data->z80->getB());
}

void
CZ80::
f_ld_iyh_c(CZ80OpData *op_data)
{
  op_data->z80->setIYH(op_data->z80->getC());
}

void
CZ80::
f_ld_iyh_d(CZ80OpData *op_data)
{
  op_data->z80->setIYH(op_data->z80->getD());
}

void
CZ80::
f_ld_iyh_e(CZ80OpData *op_data)
{
  op_data->z80->setIYH(op_data->z80->getE());
}

void
CZ80::
f_ld_iyh_iyh(CZ80OpData *op_data)
{
  op_data->z80->setIYH(op_data->z80->getIYH());
}

void
CZ80::
f_ld_iyh_iyl(CZ80OpData *op_data)
{
  op_data->z80->setIYH(op_data->z80->getIYL());
}

void
CZ80::
f_ld_iyl_a(CZ80OpData *op_data)
{
  op_data->z80->setIYL(op_data->z80->getA());
}

void
CZ80::
f_ld_iyl_b(CZ80OpData *op_data)
{
  op_data->z80->setIYL(op_data->z80->getB());
}

void
CZ80::
f_ld_iyl_c(CZ80OpData *op_data)
{
  op_data->z80->setIYL(op_data->z80->getC());
}

void
CZ80::
f_ld_iyl_d(CZ80OpData *op_data)
{
  op_data->z80->setIYL(op_data->z80->getD());
}

void
CZ80::
f_ld_iyl_e(CZ80OpData *op_data)
{
  op_data->z80->setIYL(op_data->z80->getE());
}

void
CZ80::
f_ld_iyl_iyh(CZ80OpData *op_data)
{
  op_data->z80->setIYL(op_data->z80->getIYH());
}

void
CZ80::
f_ld_iyl_iyl(CZ80OpData *op_data)
{
  op_data->z80->setIYL(op_data->z80->getIYL());
}

void
CZ80::
f_ld_i_a(CZ80OpData *op_data)
{
  op_data->z80->setI(op_data->z80->getA());
}

void
CZ80::
f_ld_r_a(CZ80OpData *op_data)
{
  op_data->z80->setR(op_data->z80->getA());
}

void
CZ80::
f_ld_a_p_bc(CZ80OpData *op_data)
{
  op_data->z80->setA(op_data->z80->getPBC());
}

void
CZ80::
f_ld_a_p_de(CZ80OpData *op_data)
{
  op_data->z80->setA(op_data->z80->getPDE());
}

void
CZ80::
f_ld_a_p_hl(CZ80OpData *op_data)
{
  op_data->z80->setA(op_data->z80->getPHL());
}

void
CZ80::
f_ld_b_p_hl(CZ80OpData *op_data)
{
  op_data->z80->setB(op_data->z80->getPHL());
}

void
CZ80::
f_ld_c_p_hl(CZ80OpData *op_data)
{
  op_data->z80->setC(op_data->z80->getPHL());
}

void
CZ80::
f_ld_d_p_hl(CZ80OpData *op_data)
{
  op_data->z80->setD(op_data->z80->getPHL());
}

void
CZ80::
f_ld_e_p_hl(CZ80OpData *op_data)
{
  op_data->z80->setE(op_data->z80->getPHL());
}

void
CZ80::
f_ld_h_p_hl(CZ80OpData *op_data)
{
  op_data->z80->setH(op_data->z80->getPHL());
}

void
CZ80::
f_ld_l_p_hl(CZ80OpData *op_data)
{
  op_data->z80->setL(op_data->z80->getPHL());
}

void
CZ80::
f_ld_p_bc_a(CZ80OpData *op_data)
{
  op_data->z80->setPBC(op_data->z80->getA());
}

void
CZ80::
f_ld_p_de_a(CZ80OpData *op_data)
{
  op_data->z80->setPDE(op_data->z80->getA());
}

void
CZ80::
f_ld_p_hl_a(CZ80OpData *op_data)
{
  op_data->z80->setPHL(op_data->z80->getA());
}

void
CZ80::
f_ld_p_hl_b(CZ80OpData *op_data)
{
  op_data->z80->setPHL(op_data->z80->getB());
}

void
CZ80::
f_ld_p_hl_c(CZ80OpData *op_data)
{
  op_data->z80->setPHL(op_data->z80->getC());
}

void
CZ80::
f_ld_p_hl_d(CZ80OpData *op_data)
{
  op_data->z80->setPHL(op_data->z80->getD());
}

void
CZ80::
f_ld_p_hl_e(CZ80OpData *op_data)
{
  op_data->z80->setPHL(op_data->z80->getE());
}

void
CZ80::
f_ld_p_hl_h(CZ80OpData *op_data)
{
  op_data->z80->setPHL(op_data->z80->getH());
}

void
CZ80::
f_ld_p_hl_l(CZ80OpData *op_data)
{
  op_data->z80->setPHL(op_data->z80->getL());
}

void
CZ80::
f_ld_p_hl_n(CZ80OpData *op_data)
{
  op_data->z80->setPHL(op_data->getUByte2());
}

void
CZ80::
f_ld_a_p_nn(CZ80OpData *op_data)
{
  op_data->z80->setA(op_data->getPByte2());
}

void
CZ80::
f_ld_bc_p_nn(CZ80OpData *op_data)
{
  op_data->z80->setBC(op_data->getPWord2());
}

void
CZ80::
f_ld_de_p_nn(CZ80OpData *op_data)
{
  op_data->z80->setDE(op_data->getPWord2());
}

void
CZ80::
f_ld_hl_p_nn(CZ80OpData *op_data)
{
  op_data->z80->setHL(op_data->getPWord2());
}

void
CZ80::
f_ld_sp_p_nn(CZ80OpData *op_data)
{
  op_data->z80->setSP(op_data->getPWord2());
}

void
CZ80::
f_ld_ix_p_nn(CZ80OpData *op_data)
{
  op_data->z80->setIX(op_data->getPWord2());
}

void
CZ80::
f_ld_iy_p_nn(CZ80OpData *op_data)
{
  op_data->z80->setIY(op_data->getPWord2());
}

void
CZ80::
f_ld_p_nn_a(CZ80OpData *op_data)
{
  op_data->setPByte1(op_data->z80->getA());
}

void
CZ80::
f_ld_p_nn_bc(CZ80OpData *op_data)
{
  op_data->setPWord1(op_data->z80->getBC());
}

void
CZ80::
f_ld_p_nn_de(CZ80OpData *op_data)
{
  op_data->setPWord1(op_data->z80->getDE());
}

void
CZ80::
f_ld_p_nn_hl(CZ80OpData *op_data)
{
  op_data->setPWord1(op_data->z80->getHL());
}

void
CZ80::
f_ld_p_nn_sp(CZ80OpData *op_data)
{
  op_data->setPWord1(op_data->z80->getSP());
}

void
CZ80::
f_ld_p_nn_ix(CZ80OpData *op_data)
{
  op_data->setPWord1(op_data->z80->getIX());
}

void
CZ80::
f_ld_p_nn_iy(CZ80OpData *op_data)
{
  op_data->setPWord1(op_data->z80->getIY());
}

void
CZ80::
f_ld_sp_hl(CZ80OpData *op_data)
{
  op_data->z80->setSP(op_data->z80->getHL());
}

void
CZ80::
f_ld_sp_ix(CZ80OpData *op_data)
{
  op_data->z80->setSP(op_data->z80->getIX());
}

void
CZ80::
f_ld_sp_iy(CZ80OpData *op_data)
{
  op_data->z80->setSP(op_data->z80->getIY());
}

void
CZ80::
f_ld_a_po_ix(CZ80OpData *op_data)
{
  op_data->z80->setA(op_data->getPOIX2());
}

void
CZ80::
f_ld_b_po_ix(CZ80OpData *op_data)
{
  op_data->z80->setB(op_data->getPOIX2());
}

void
CZ80::
f_ld_c_po_ix(CZ80OpData *op_data)
{
  op_data->z80->setC(op_data->getPOIX2());
}

void
CZ80::
f_ld_d_po_ix(CZ80OpData *op_data)
{
  op_data->z80->setD(op_data->getPOIX2());
}

void
CZ80::
f_ld_e_po_ix(CZ80OpData *op_data)
{
  op_data->z80->setE(op_data->getPOIX2());
}

void
CZ80::
f_ld_h_po_ix(CZ80OpData *op_data)
{
  op_data->z80->setH(op_data->getPOIX2());
}

void
CZ80::
f_ld_l_po_ix(CZ80OpData *op_data)
{
  op_data->z80->setL(op_data->getPOIX2());
}

void
CZ80::
f_ld_a_po_iy(CZ80OpData *op_data)
{
  op_data->z80->setA(op_data->getPOIY2());
}

void
CZ80::
f_ld_b_po_iy(CZ80OpData *op_data)
{
  op_data->z80->setB(op_data->getPOIY2());
}

void
CZ80::
f_ld_c_po_iy(CZ80OpData *op_data)
{
  op_data->z80->setC(op_data->getPOIY2());
}

void
CZ80::
f_ld_d_po_iy(CZ80OpData *op_data)
{
  op_data->z80->setD(op_data->getPOIY2());
}

void
CZ80::
f_ld_e_po_iy(CZ80OpData *op_data)
{
  op_data->z80->setE(op_data->getPOIY2());
}

void
CZ80::
f_ld_h_po_iy(CZ80OpData *op_data)
{
  op_data->z80->setH(op_data->getPOIY2());
}

void
CZ80::
f_ld_l_po_iy(CZ80OpData *op_data)
{
  op_data->z80->setL(op_data->getPOIY2());
}

void
CZ80::
f_ld_po_ix_a(CZ80OpData *op_data)
{
  op_data->setPOIX1(op_data->z80->getA());
}

void
CZ80::
f_ld_po_ix_b(CZ80OpData *op_data)
{
  op_data->setPOIX1(op_data->z80->getB());
}

void
CZ80::
f_ld_po_ix_c(CZ80OpData *op_data)
{
  op_data->setPOIX1(op_data->z80->getC());
}

void
CZ80::
f_ld_po_ix_d(CZ80OpData *op_data)
{
  op_data->setPOIX1(op_data->z80->getD());
}

void
CZ80::
f_ld_po_ix_e(CZ80OpData *op_data)
{
  op_data->setPOIX1(op_data->z80->getE());
}

void
CZ80::
f_ld_po_ix_h(CZ80OpData *op_data)
{
  op_data->setPOIX1(op_data->z80->getH());
}

void
CZ80::
f_ld_po_ix_l(CZ80OpData *op_data)
{
  op_data->setPOIX1(op_data->z80->getL());
}

void
CZ80::
f_ld_po_ix_n(CZ80OpData *op_data)
{
  op_data->setPOIX1(op_data->getUByte2());
}

void
CZ80::
f_ld_po_iy_a(CZ80OpData *op_data)
{
  op_data->setPOIY1(op_data->z80->getA());
}

void
CZ80::
f_ld_po_iy_b(CZ80OpData *op_data)
{
  op_data->setPOIY1(op_data->z80->getB());
}

void
CZ80::
f_ld_po_iy_c(CZ80OpData *op_data)
{
  op_data->setPOIY1(op_data->z80->getC());
}

void
CZ80::
f_ld_po_iy_d(CZ80OpData *op_data)
{
  op_data->setPOIY1(op_data->z80->getD());
}

void
CZ80::
f_ld_po_iy_e(CZ80OpData *op_data)
{
  op_data->setPOIY1(op_data->z80->getE());
}

void
CZ80::
f_ld_po_iy_h(CZ80OpData *op_data)
{
  op_data->setPOIY1(op_data->z80->getH());
}

void
CZ80::
f_ld_po_iy_l(CZ80OpData *op_data)
{
  op_data->setPOIY1(op_data->z80->getL());
}

void
CZ80::
f_ld_po_iy_n(CZ80OpData *op_data)
{
  op_data->setPOIY1(op_data->getUByte2());
}

void
CZ80::
f_ldd(CZ80OpData *op_data)
{
  op_data->z80->ldd();
}

void
CZ80::
f_lddr(CZ80OpData *op_data)
{
  op_data->z80->lddr();
}

void
CZ80::
f_ldi(CZ80OpData *op_data)
{
  op_data->z80->ldi();
}

void
CZ80::
f_ldir(CZ80OpData *op_data)
{
  op_data->z80->ldir();
}

void
CZ80::
f_neg(CZ80OpData *op_data)
{
  op_data->z80->neg();
}

void
CZ80::
f_nop(CZ80OpData *)
{
}

void
CZ80::
f_or_a(CZ80OpData *op_data)
{
  op_data->z80->orA(op_data->z80->getA());
}

void
CZ80::
f_or_b(CZ80OpData *op_data)
{
  op_data->z80->orA(op_data->z80->getB());
}

void
CZ80::
f_or_c(CZ80OpData *op_data)
{
  op_data->z80->orA(op_data->z80->getC());
}

void
CZ80::
f_or_d(CZ80OpData *op_data)
{
  op_data->z80->orA(op_data->z80->getD());
}

void
CZ80::
f_or_e(CZ80OpData *op_data)
{
  op_data->z80->orA(op_data->z80->getE());
}

void
CZ80::
f_or_h(CZ80OpData *op_data)
{
  op_data->z80->orA(op_data->z80->getH());
}

void
CZ80::
f_or_l(CZ80OpData *op_data)
{
  op_data->z80->orA(op_data->z80->getL());
}

void
CZ80::
f_or_ixh(CZ80OpData *op_data)
{
  op_data->z80->orA(op_data->z80->getIXH());
}

void
CZ80::
f_or_ixl(CZ80OpData *op_data)
{
  op_data->z80->orA(op_data->z80->getIXL());
}

void
CZ80::
f_or_iyh(CZ80OpData *op_data)
{
  op_data->z80->orA(op_data->z80->getIYH());
}

void
CZ80::
f_or_iyl(CZ80OpData *op_data)
{
  op_data->z80->orA(op_data->z80->getIYL());
}

void
CZ80::
f_or_p_hl(CZ80OpData *op_data)
{
  op_data->z80->orA(op_data->z80->getPHL());
}

void
CZ80::
f_or_n(CZ80OpData *op_data)
{
  op_data->z80->orA(op_data->getUByte1());
}

void
CZ80::
f_or_po_ix(CZ80OpData *op_data)
{
  op_data->z80->orA(op_data->getPOIX1());
}

void
CZ80::
f_or_po_iy(CZ80OpData *op_data)
{
  op_data->z80->orA(op_data->getPOIY1());
}

void
CZ80::
f_out_p_n_a(CZ80OpData *op_data)
{
  op_data->z80->out(op_data->getUByte1(), op_data->z80->getA());
}

void
CZ80::
f_out_p_c_a(CZ80OpData *op_data)
{
  op_data->z80->outC(op_data->z80->getA());
}

void
CZ80::
f_out_p_c_b(CZ80OpData *op_data)
{
  op_data->z80->outC(op_data->z80->getB());
}

void
CZ80::
f_out_p_c_c(CZ80OpData *op_data)
{
  op_data->z80->outC(op_data->z80->getC());
}

void
CZ80::
f_out_p_c_d(CZ80OpData *op_data)
{
  op_data->z80->outC(op_data->z80->getD());
}

void
CZ80::
f_out_p_c_e(CZ80OpData *op_data)
{
  op_data->z80->outC(op_data->z80->getE());
}

void
CZ80::
f_out_p_c_h(CZ80OpData *op_data)
{
  op_data->z80->outC(op_data->z80->getH());
}

void
CZ80::
f_out_p_c_l(CZ80OpData *op_data)
{
  op_data->z80->outC(op_data->z80->getL());
}

void
CZ80::
f_out_p_c_n(CZ80OpData *op_data)
{
  op_data->z80->outC(op_data->op->arg2);
}

void
CZ80::
f_outd(CZ80OpData *op_data)
{
  op_data->z80->outC(op_data->z80->getPHL());

  op_data->z80->decHL();
  op_data->z80->decB();
}

void
CZ80::
f_outi(CZ80OpData *op_data)
{
  op_data->z80->outC(op_data->z80->getPHL());

  op_data->z80->incHL();
  op_data->z80->decB();
}

void
CZ80::
f_otdr(CZ80OpData *op_data)
{
  do {
    f_outd(op_data);

    op_data->z80->incT(21);
  }
  while (op_data->z80->getB() != 0);

  op_data->z80->decT(5);
}

void
CZ80::
f_otir(CZ80OpData *op_data)
{
  do {
    f_outi(op_data);

    op_data->z80->incT(21);
  }
  while (op_data->z80->getB() != 0);

  op_data->z80->decT(5);
}

void
CZ80::
f_pop_af(CZ80OpData *op_data)
{
  op_data->z80->popAF();
}

void
CZ80::
f_pop_bc(CZ80OpData *op_data)
{
  op_data->z80->popBC();
}

void
CZ80::
f_pop_de(CZ80OpData *op_data)
{
  op_data->z80->popDE();
}

void
CZ80::
f_pop_hl(CZ80OpData *op_data)
{
  op_data->z80->popHL();
}

void
CZ80::
f_pop_ix(CZ80OpData *op_data)
{
  op_data->z80->popIX();
}

void
CZ80::
f_pop_iy(CZ80OpData *op_data)
{
  op_data->z80->popIY();
}

void
CZ80::
f_push_af(CZ80OpData *op_data)
{
  op_data->z80->pushAF();
}

void
CZ80::
f_push_bc(CZ80OpData *op_data)
{
  op_data->z80->pushBC();
}

void
CZ80::
f_push_de(CZ80OpData *op_data)
{
  op_data->z80->pushDE();
}

void
CZ80::
f_push_hl(CZ80OpData *op_data)
{
  op_data->z80->pushHL();
}

void
CZ80::
f_push_ix(CZ80OpData *op_data)
{
  op_data->z80->pushIX();
}

void
CZ80::
f_push_iy(CZ80OpData *op_data)
{
  op_data->z80->pushIY();
}

void
CZ80::
f_res_po_ix_n(CZ80OpData *op_data)
{
  op_data->z80->resBitPOIX(op_data->getSByte2(), op_data->op->arg1);
}

void
CZ80::
f_res_po_iy_n(CZ80OpData *op_data)
{
  op_data->z80->resBitPOIY(op_data->getSByte2(), op_data->op->arg1);
}

void
CZ80::
f_res_a_n(CZ80OpData *op_data)
{
  op_data->z80->resBitA(op_data->op->arg1);
}

void
CZ80::
f_res_b_n(CZ80OpData *op_data)
{
  op_data->z80->resBitB(op_data->op->arg1);
}

void
CZ80::
f_res_c_n(CZ80OpData *op_data)
{
  op_data->z80->resBitC(op_data->op->arg1);
}

void
CZ80::
f_res_d_n(CZ80OpData *op_data)
{
  op_data->z80->resBitD(op_data->op->arg1);
}

void
CZ80::
f_res_e_n(CZ80OpData *op_data)
{
  op_data->z80->resBitE(op_data->op->arg1);
}

void
CZ80::
f_res_h_n(CZ80OpData *op_data)
{
  op_data->z80->resBitH(op_data->op->arg1);
}

void
CZ80::
f_res_l_n(CZ80OpData *op_data)
{
  op_data->z80->resBitL(op_data->op->arg1);
}

void
CZ80::
f_res_p_hl_n(CZ80OpData *op_data)
{
  op_data->z80->resBitPHL(op_data->op->arg1);
}

void
CZ80::
f_res_po_ix_a_n(CZ80OpData *op_data)
{
  f_res_po_ix_a_n(op_data, op_data->op->arg1);
}

void
CZ80::
f_res_po_ix_b_n(CZ80OpData *op_data)
{
  f_res_po_ix_b_n(op_data, op_data->op->arg1);
}

void
CZ80::
f_res_po_ix_c_n(CZ80OpData *op_data)
{
  f_res_po_ix_c_n(op_data, op_data->op->arg1);
}

void
CZ80::
f_res_po_ix_d_n(CZ80OpData *op_data)
{
  f_res_po_ix_d_n(op_data, op_data->op->arg1);
}

void
CZ80::
f_res_po_ix_e_n(CZ80OpData *op_data)
{
  f_res_po_ix_e_n(op_data, op_data->op->arg1);
}

void
CZ80::
f_res_po_ix_h_n(CZ80OpData *op_data)
{
  f_res_po_ix_h_n(op_data, op_data->op->arg1);
}

void
CZ80::
f_res_po_ix_l_n(CZ80OpData *op_data)
{
  f_res_po_ix_l_n(op_data, op_data->op->arg1);
}

void
CZ80::
f_res_po_iy_a_n(CZ80OpData *op_data)
{
  f_res_po_iy_a_n(op_data, op_data->op->arg1);
}

void
CZ80::
f_res_po_iy_b_n(CZ80OpData *op_data)
{
  f_res_po_iy_b_n(op_data, op_data->op->arg1);
}

void
CZ80::
f_res_po_iy_c_n(CZ80OpData *op_data)
{
  f_res_po_iy_c_n(op_data, op_data->op->arg1);
}

void
CZ80::
f_res_po_iy_d_n(CZ80OpData *op_data)
{
  f_res_po_iy_d_n(op_data, op_data->op->arg1);
}

void
CZ80::
f_res_po_iy_e_n(CZ80OpData *op_data)
{
  f_res_po_iy_e_n(op_data, op_data->op->arg1);
}

void
CZ80::
f_res_po_iy_h_n(CZ80OpData *op_data)
{
  f_res_po_iy_h_n(op_data, op_data->op->arg1);
}

void
CZ80::
f_res_po_iy_l_n(CZ80OpData *op_data)
{
  f_res_po_iy_l_n(op_data, op_data->op->arg1);
}

void
CZ80::
f_res_po_ix_a_n(CZ80OpData *op_data, uchar n)
{
  schar o = op_data->getSByte2();

  op_data->z80->setA(op_data->z80->getPOIX(o));

  op_data->z80->resBitA(n);

  op_data->z80->setPOIX(o, op_data->z80->getA());
}

void
CZ80::
f_res_po_ix_b_n(CZ80OpData *op_data, uchar n)
{
  schar o = op_data->getSByte2();

  op_data->z80->setB(op_data->z80->getPOIX(o));

  op_data->z80->resBitB(n);

  op_data->z80->setPOIX(o, op_data->z80->getB());
}

void
CZ80::
f_res_po_ix_c_n(CZ80OpData *op_data, uchar n)
{
  schar o = op_data->getSByte2();

  op_data->z80->setC(op_data->z80->getPOIX(o));

  op_data->z80->resBitC(n);

  op_data->z80->setPOIX(o, op_data->z80->getC());
}

void
CZ80::
f_res_po_ix_d_n(CZ80OpData *op_data, uchar n)
{
  schar o = op_data->getSByte2();

  op_data->z80->setD(op_data->z80->getPOIX(o));

  op_data->z80->resBitD(n);

  op_data->z80->setPOIX(o, op_data->z80->getD());
}

void
CZ80::
f_res_po_ix_e_n(CZ80OpData *op_data, uchar n)
{
  schar o = op_data->getSByte2();

  op_data->z80->setE(op_data->z80->getPOIX(o));

  op_data->z80->resBitE(n);

  op_data->z80->setPOIX(o, op_data->z80->getE());
}

void
CZ80::
f_res_po_ix_h_n(CZ80OpData *op_data, uchar n)
{
  schar o = op_data->getSByte2();

  op_data->z80->setH(op_data->z80->getPOIX(o));

  op_data->z80->resBitH(n);

  op_data->z80->setPOIX(o, op_data->z80->getH());
}

void
CZ80::
f_res_po_ix_l_n(CZ80OpData *op_data, uchar n)
{
  schar o = op_data->getSByte2();

  op_data->z80->setL(op_data->z80->getPOIX(o));

  op_data->z80->resBitL(n);

  op_data->z80->setPOIX(o, op_data->z80->getL());
}

void
CZ80::
f_res_po_iy_a_n(CZ80OpData *op_data, uchar n)
{
  schar o = op_data->getSByte2();

  op_data->z80->setA(op_data->z80->getPOIY(o));

  op_data->z80->resBitA(n);

  op_data->z80->setPOIY(o, op_data->z80->getA());
}

void
CZ80::
f_res_po_iy_b_n(CZ80OpData *op_data, uchar n)
{
  schar o = op_data->getSByte2();

  op_data->z80->setB(op_data->z80->getPOIY(o));

  op_data->z80->resBitB(n);

  op_data->z80->setPOIY(o, op_data->z80->getB());
}

void
CZ80::
f_res_po_iy_c_n(CZ80OpData *op_data, uchar n)
{
  schar o = op_data->getSByte2();

  op_data->z80->setC(op_data->z80->getPOIY(o));

  op_data->z80->resBitC(n);

  op_data->z80->setPOIY(o, op_data->z80->getC());
}

void
CZ80::
f_res_po_iy_d_n(CZ80OpData *op_data, uchar n)
{
  schar o = op_data->getSByte2();

  op_data->z80->setD(op_data->z80->getPOIY(o));

  op_data->z80->resBitD(n);

  op_data->z80->setPOIY(o, op_data->z80->getD());
}

void
CZ80::
f_res_po_iy_e_n(CZ80OpData *op_data, uchar n)
{
  schar o = op_data->getSByte2();

  op_data->z80->setE(op_data->z80->getPOIY(o));

  op_data->z80->resBitE(n);

  op_data->z80->setPOIY(o, op_data->z80->getE());
}

void
CZ80::
f_res_po_iy_h_n(CZ80OpData *op_data, uchar n)
{
  schar o = op_data->getSByte2();

  op_data->z80->setH(op_data->z80->getPOIY(o));

  op_data->z80->resBitH(n);

  op_data->z80->setPOIY(o, op_data->z80->getH());
}

void
CZ80::
f_res_po_iy_l_n(CZ80OpData *op_data, uchar n)
{
  schar o = op_data->getSByte2();

  op_data->z80->setL(op_data->z80->getPOIY(o));

  op_data->z80->resBitL(n);

  op_data->z80->setPOIY(o, op_data->z80->getL());
}

void
CZ80::
f_ret(CZ80OpData *op_data)
{
  op_data->z80->popPC();
}

void
CZ80::
f_ret_z(CZ80OpData *op_data)
{
  if (op_data->z80->tstZFlag())
    op_data->z80->popPC();
}

void
CZ80::
f_ret_nz(CZ80OpData *op_data)
{
  if (! op_data->z80->tstZFlag()) {
    op_data->z80->popPC();

    op_data->z80->incT(6);
  }
}

void
CZ80::
f_ret_c(CZ80OpData *op_data)
{
  if (op_data->z80->tstCFlag()) {
    op_data->z80->popPC();

    op_data->z80->incT(6);
  }
}

void
CZ80::
f_ret_nc(CZ80OpData *op_data)
{
  if (! op_data->z80->tstCFlag()) {
    op_data->z80->popPC();

    op_data->z80->incT(6);
  }
}

void
CZ80::
f_ret_pe(CZ80OpData *op_data)
{
  if (op_data->z80->tstPFlag()) {
    op_data->z80->popPC();

    op_data->z80->incT(6);
  }
}

void
CZ80::
f_ret_po(CZ80OpData *op_data)
{
  if (! op_data->z80->tstPFlag()) {
    op_data->z80->popPC();

    op_data->z80->incT(6);
  }
}

void
CZ80::
f_ret_p(CZ80OpData *op_data)
{
  if (! op_data->z80->tstSFlag()) {
    op_data->z80->popPC();

    op_data->z80->incT(6);
  }
}

void
CZ80::
f_ret_m(CZ80OpData *op_data)
{
  if (op_data->z80->tstSFlag()) {
    op_data->z80->popPC();

    op_data->z80->incT(6);
  }
}

void
CZ80::
f_reti(CZ80OpData *op_data)
{
  op_data->z80->reti();
}

void
CZ80::
f_retn(CZ80OpData *op_data)
{
  op_data->z80->retn();
}

void
CZ80::
f_rl_a(CZ80OpData *op_data)
{
  op_data->z80->rlA();
}

void
CZ80::
f_rl_b(CZ80OpData *op_data)
{
  op_data->z80->rlB();
}

void
CZ80::
f_rl_c(CZ80OpData *op_data)
{
  op_data->z80->rlC();
}

void
CZ80::
f_rl_d(CZ80OpData *op_data)
{
  op_data->z80->rlD();
}

void
CZ80::
f_rl_e(CZ80OpData *op_data)
{
  op_data->z80->rlE();
}

void
CZ80::
f_rl_h(CZ80OpData *op_data)
{
  op_data->z80->rlH();
}

void
CZ80::
f_rl_l(CZ80OpData *op_data)
{
  op_data->z80->rlL();
}

void
CZ80::
f_rl_p_hl(CZ80OpData *op_data)
{
  op_data->z80->rlPHL();
}

void
CZ80::
f_rl_po_ix(CZ80OpData *op_data)
{
  op_data->z80->rlPOIX(op_data->getSByte1());
}

void
CZ80::
f_rl_po_ix_a(CZ80OpData *op_data)
{
  schar o = op_data->getSByte1();

  op_data->z80->setA(op_data->z80->getPOIX(o));

  op_data->z80->rlA();

  op_data->z80->setPOIX(o, op_data->z80->getA());
}

void
CZ80::
f_rl_po_ix_b(CZ80OpData *op_data)
{
  schar o = op_data->getSByte1();

  op_data->z80->setB(op_data->z80->getPOIX(o));

  op_data->z80->rlB();

  op_data->z80->setPOIX(o, op_data->z80->getB());
}

void
CZ80::
f_rl_po_ix_c(CZ80OpData *op_data)
{
  schar o = op_data->getSByte1();

  op_data->z80->setC(op_data->z80->getPOIX(o));

  op_data->z80->rlC();

  op_data->z80->setPOIX(o, op_data->z80->getC());
}

void
CZ80::
f_rl_po_ix_d(CZ80OpData *op_data)
{
  schar o = op_data->getSByte1();

  op_data->z80->setD(op_data->z80->getPOIX(o));

  op_data->z80->rlD();

  op_data->z80->setPOIX(o, op_data->z80->getD());
}

void
CZ80::
f_rl_po_ix_e(CZ80OpData *op_data)
{
  schar o = op_data->getSByte1();

  op_data->z80->setE(op_data->z80->getPOIX(o));

  op_data->z80->rlE();

  op_data->z80->setPOIX(o, op_data->z80->getE());
}

void
CZ80::
f_rl_po_ix_h(CZ80OpData *op_data)
{
  schar o = op_data->getSByte1();

  op_data->z80->setH(op_data->z80->getPOIX(o));

  op_data->z80->rlH();

  op_data->z80->setPOIX(o, op_data->z80->getH());
}

void
CZ80::
f_rl_po_ix_l(CZ80OpData *op_data)
{
  schar o = op_data->getSByte1();

  op_data->z80->setL(op_data->z80->getPOIX(o));

  op_data->z80->rlL();

  op_data->z80->setPOIX(o, op_data->z80->getL());
}

void
CZ80::
f_rl_po_iy(CZ80OpData *op_data)
{
  op_data->z80->rlPOIY(op_data->getSByte1());
}

void
CZ80::
f_rl_po_iy_a(CZ80OpData *op_data)
{
  schar o = op_data->getSByte1();

  op_data->z80->setA(op_data->z80->getPOIY(o));

  op_data->z80->rlA();

  op_data->z80->setPOIY(o, op_data->z80->getA());
}

void
CZ80::
f_rl_po_iy_b(CZ80OpData *op_data)
{
  schar o = op_data->getSByte1();

  op_data->z80->setB(op_data->z80->getPOIY(o));

  op_data->z80->rlB();

  op_data->z80->setPOIY(o, op_data->z80->getB());
}

void
CZ80::
f_rl_po_iy_c(CZ80OpData *op_data)
{
  schar o = op_data->getSByte1();

  op_data->z80->setC(op_data->z80->getPOIY(o));

  op_data->z80->rlC();

  op_data->z80->setPOIY(o, op_data->z80->getC());
}

void
CZ80::
f_rl_po_iy_d(CZ80OpData *op_data)
{
  schar o = op_data->getSByte1();

  op_data->z80->setD(op_data->z80->getPOIY(o));

  op_data->z80->rlD();

  op_data->z80->setPOIY(o, op_data->z80->getD());
}

void
CZ80::
f_rl_po_iy_e(CZ80OpData *op_data)
{
  schar o = op_data->getSByte1();

  op_data->z80->setE(op_data->z80->getPOIY(o));

  op_data->z80->rlE();

  op_data->z80->setPOIY(o, op_data->z80->getE());
}

void
CZ80::
f_rl_po_iy_h(CZ80OpData *op_data)
{
  schar o = op_data->getSByte1();

  op_data->z80->setH(op_data->z80->getPOIY(o));

  op_data->z80->rlH();

  op_data->z80->setPOIY(o, op_data->z80->getH());
}

void
CZ80::
f_rl_po_iy_l(CZ80OpData *op_data)
{
  schar o = op_data->getSByte1();

  op_data->z80->setL(op_data->z80->getPOIY(o));

  op_data->z80->rlL();

  op_data->z80->setPOIY(o, op_data->z80->getL());
}

void
CZ80::
f_rla(CZ80OpData *op_data)
{
  op_data->z80->rla();
}

void
CZ80::
f_rlc_a(CZ80OpData *op_data)
{
  op_data->z80->rlcA();
}

void
CZ80::
f_rlc_b(CZ80OpData *op_data)
{
  op_data->z80->rlcB();
}

void
CZ80::
f_rlc_c(CZ80OpData *op_data)
{
  op_data->z80->rlcC();
}

void
CZ80::
f_rlc_d(CZ80OpData *op_data)
{
  op_data->z80->rlcD();
}

void
CZ80::
f_rlc_e(CZ80OpData *op_data)
{
  op_data->z80->rlcE();
}

void
CZ80::
f_rlc_h(CZ80OpData *op_data)
{
  op_data->z80->rlcH();
}

void
CZ80::
f_rlc_l(CZ80OpData *op_data)
{
  op_data->z80->rlcL();
}

void
CZ80::
f_rlc_p_hl(CZ80OpData *op_data)
{
  op_data->z80->rlcPHL();
}

void
CZ80::
f_rlc_po_ix(CZ80OpData *op_data)
{
  op_data->z80->rlcPOIX(op_data->getSByte1());
}

void
CZ80::
f_rlc_po_ix_a(CZ80OpData *op_data)
{
  schar o = op_data->getSByte1();

  op_data->z80->setA(op_data->z80->getPOIX(o));

  op_data->z80->rlcA();

  op_data->z80->setPOIX(o, op_data->z80->getA());
}

void
CZ80::
f_rlc_po_ix_b(CZ80OpData *op_data)
{
  schar o = op_data->getSByte1();

  op_data->z80->setB(op_data->z80->getPOIX(o));

  op_data->z80->rlcB();

  op_data->z80->setPOIX(o, op_data->z80->getB());
}

void
CZ80::
f_rlc_po_ix_c(CZ80OpData *op_data)
{
  schar o = op_data->getSByte1();

  op_data->z80->setC(op_data->z80->getPOIX(o));

  op_data->z80->rlcC();

  op_data->z80->setPOIX(o, op_data->z80->getC());
}

void
CZ80::
f_rlc_po_ix_d(CZ80OpData *op_data)
{
  schar o = op_data->getSByte1();

  op_data->z80->setD(op_data->z80->getPOIX(o));

  op_data->z80->rlcD();

  op_data->z80->setPOIX(o, op_data->z80->getD());
}

void
CZ80::
f_rlc_po_ix_e(CZ80OpData *op_data)
{
  schar o = op_data->getSByte1();

  op_data->z80->setE(op_data->z80->getPOIX(o));

  op_data->z80->rlcE();

  op_data->z80->setPOIX(o, op_data->z80->getE());
}

void
CZ80::
f_rlc_po_ix_h(CZ80OpData *op_data)
{
  schar o = op_data->getSByte1();

  op_data->z80->setH(op_data->z80->getPOIX(o));

  op_data->z80->rlcH();

  op_data->z80->setPOIX(o, op_data->z80->getH());
}

void
CZ80::
f_rlc_po_ix_l(CZ80OpData *op_data)
{
  schar o = op_data->getSByte1();

  op_data->z80->setL(op_data->z80->getPOIX(o));

  op_data->z80->rlcL();

  op_data->z80->setPOIX(o, op_data->z80->getL());
}

void
CZ80::
f_rlc_po_iy(CZ80OpData *op_data)
{
  op_data->z80->rlcPOIY(op_data->getSByte1());
}

void
CZ80::
f_rlc_po_iy_a(CZ80OpData *op_data)
{
  schar o = op_data->getSByte1();

  op_data->z80->setA(op_data->z80->getPOIY(o));

  op_data->z80->rlcA();

  op_data->z80->setPOIY(o, op_data->z80->getA());
}

void
CZ80::
f_rlc_po_iy_b(CZ80OpData *op_data)
{
  schar o = op_data->getSByte1();

  op_data->z80->setB(op_data->z80->getPOIY(o));

  op_data->z80->rlcB();

  op_data->z80->setPOIY(o, op_data->z80->getB());
}

void
CZ80::
f_rlc_po_iy_c(CZ80OpData *op_data)
{
  schar o = op_data->getSByte1();

  op_data->z80->setC(op_data->z80->getPOIY(o));

  op_data->z80->rlcC();

  op_data->z80->setPOIY(o, op_data->z80->getC());
}

void
CZ80::
f_rlc_po_iy_d(CZ80OpData *op_data)
{
  schar o = op_data->getSByte1();

  op_data->z80->setD(op_data->z80->getPOIY(o));

  op_data->z80->rlcD();

  op_data->z80->setPOIY(o, op_data->z80->getD());
}

void
CZ80::
f_rlc_po_iy_e(CZ80OpData *op_data)
{
  schar o = op_data->getSByte1();

  op_data->z80->setE(op_data->z80->getPOIY(o));

  op_data->z80->rlcE();

  op_data->z80->setPOIY(o, op_data->z80->getE());
}

void
CZ80::
f_rlc_po_iy_h(CZ80OpData *op_data)
{
  schar o = op_data->getSByte1();

  op_data->z80->setH(op_data->z80->getPOIY(o));

  op_data->z80->rlcH();

  op_data->z80->setPOIY(o, op_data->z80->getH());
}

void
CZ80::
f_rlc_po_iy_l(CZ80OpData *op_data)
{
  schar o = op_data->getSByte1();

  op_data->z80->setL(op_data->z80->getPOIY(o));

  op_data->z80->rlcL();

  op_data->z80->setPOIY(o, op_data->z80->getL());
}

void
CZ80::
f_rlca(CZ80OpData *op_data)
{
  op_data->z80->rlca();
}

void
CZ80::
f_rld(CZ80OpData *op_data)
{
  op_data->z80->rld();
}

void
CZ80::
f_rr_a(CZ80OpData *op_data)
{
  op_data->z80->rrA();
}

void
CZ80::
f_rr_b(CZ80OpData *op_data)
{
  op_data->z80->rrB();
}

void
CZ80::
f_rr_c(CZ80OpData *op_data)
{
  op_data->z80->rrC();
}

void
CZ80::
f_rr_d(CZ80OpData *op_data)
{
  op_data->z80->rrD();
}

void
CZ80::
f_rr_e(CZ80OpData *op_data)
{
  op_data->z80->rrE();
}

void
CZ80::
f_rr_h(CZ80OpData *op_data)
{
  op_data->z80->rrH();
}

void
CZ80::
f_rr_l(CZ80OpData *op_data)
{
  op_data->z80->rrL();
}

void
CZ80::
f_rr_p_hl(CZ80OpData *op_data)
{
  op_data->z80->rrPHL();
}

void
CZ80::
f_rr_po_ix(CZ80OpData *op_data)
{
  op_data->z80->rrPOIX(op_data->getSByte1());
}

void
CZ80::
f_rr_po_ix_a(CZ80OpData *op_data)
{
  schar o = op_data->getSByte1();

  op_data->z80->setA(op_data->z80->getPOIX(o));

  op_data->z80->rrA();

  op_data->z80->setPOIX(o, op_data->z80->getA());
}

void
CZ80::
f_rr_po_ix_b(CZ80OpData *op_data)
{
  schar o = op_data->getSByte1();

  op_data->z80->setB(op_data->z80->getPOIX(o));

  op_data->z80->rrB();

  op_data->z80->setPOIX(o, op_data->z80->getB());
}

void
CZ80::
f_rr_po_ix_c(CZ80OpData *op_data)
{
  schar o = op_data->getSByte1();

  op_data->z80->setC(op_data->z80->getPOIX(o));

  op_data->z80->rrC();

  op_data->z80->setPOIX(o, op_data->z80->getC());
}

void
CZ80::
f_rr_po_ix_d(CZ80OpData *op_data)
{
  schar o = op_data->getSByte1();

  op_data->z80->setD(op_data->z80->getPOIX(o));

  op_data->z80->rrD();

  op_data->z80->setPOIX(o, op_data->z80->getD());
}

void
CZ80::
f_rr_po_ix_e(CZ80OpData *op_data)
{
  schar o = op_data->getSByte1();

  op_data->z80->setE(op_data->z80->getPOIX(o));

  op_data->z80->rrE();

  op_data->z80->setPOIX(o, op_data->z80->getE());
}

void
CZ80::
f_rr_po_ix_h(CZ80OpData *op_data)
{
  schar o = op_data->getSByte1();

  op_data->z80->setH(op_data->z80->getPOIX(o));

  op_data->z80->rrH();

  op_data->z80->setPOIX(o, op_data->z80->getH());
}

void
CZ80::
f_rr_po_ix_l(CZ80OpData *op_data)
{
  schar o = op_data->getSByte1();

  op_data->z80->setL(op_data->z80->getPOIX(o));

  op_data->z80->rrL();

  op_data->z80->setPOIX(o, op_data->z80->getL());
}

void
CZ80::
f_rr_po_iy(CZ80OpData *op_data)
{
  op_data->z80->rrPOIY(op_data->getSByte1());
}

void
CZ80::
f_rr_po_iy_a(CZ80OpData *op_data)
{
  schar o = op_data->getSByte1();

  op_data->z80->setA(op_data->z80->getPOIY(o));

  op_data->z80->rrA();

  op_data->z80->setPOIY(o, op_data->z80->getA());
}

void
CZ80::
f_rr_po_iy_b(CZ80OpData *op_data)
{
  schar o = op_data->getSByte1();

  op_data->z80->setB(op_data->z80->getPOIY(o));

  op_data->z80->rrB();

  op_data->z80->setPOIY(o, op_data->z80->getB());
}

void
CZ80::
f_rr_po_iy_c(CZ80OpData *op_data)
{
  schar o = op_data->getSByte1();

  op_data->z80->setC(op_data->z80->getPOIY(o));

  op_data->z80->rrC();

  op_data->z80->setPOIY(o, op_data->z80->getC());
}

void
CZ80::
f_rr_po_iy_d(CZ80OpData *op_data)
{
  schar o = op_data->getSByte1();

  op_data->z80->setD(op_data->z80->getPOIY(o));

  op_data->z80->rrD();

  op_data->z80->setPOIY(o, op_data->z80->getD());
}

void
CZ80::
f_rr_po_iy_e(CZ80OpData *op_data)
{
  schar o = op_data->getSByte1();

  op_data->z80->setE(op_data->z80->getPOIY(o));

  op_data->z80->rrE();

  op_data->z80->setPOIY(o, op_data->z80->getE());
}

void
CZ80::
f_rr_po_iy_h(CZ80OpData *op_data)
{
  schar o = op_data->getSByte1();

  op_data->z80->setH(op_data->z80->getPOIY(o));

  op_data->z80->rrH();

  op_data->z80->setPOIY(o, op_data->z80->getH());
}

void
CZ80::
f_rr_po_iy_l(CZ80OpData *op_data)
{
  schar o = op_data->getSByte1();

  op_data->z80->setL(op_data->z80->getPOIY(o));

  op_data->z80->rrL();

  op_data->z80->setPOIY(o, op_data->z80->getL());
}

void
CZ80::
f_rra(CZ80OpData *op_data)
{
  op_data->z80->rra();
}

void
CZ80::
f_rrc_a(CZ80OpData *op_data)
{
  op_data->z80->rrcA();
}

void
CZ80::
f_rrc_b(CZ80OpData *op_data)
{
  op_data->z80->rrcB();
}

void
CZ80::
f_rrc_c(CZ80OpData *op_data)
{
  op_data->z80->rrcC();
}

void
CZ80::
f_rrc_d(CZ80OpData *op_data)
{
  op_data->z80->rrcD();
}

void
CZ80::
f_rrc_e(CZ80OpData *op_data)
{
  op_data->z80->rrcE();
}

void
CZ80::
f_rrc_h(CZ80OpData *op_data)
{
  op_data->z80->rrcH();
}

void
CZ80::
f_rrc_l(CZ80OpData *op_data)
{
  op_data->z80->rrcL();
}

void
CZ80::
f_rrc_p_hl(CZ80OpData *op_data)
{
  op_data->z80->rrcPHL();
}

void
CZ80::
f_rrc_po_ix(CZ80OpData *op_data)
{
  op_data->z80->rrcPOIX(op_data->getSByte1());
}

void
CZ80::
f_rrc_po_ix_a(CZ80OpData *op_data)
{
  schar o = op_data->getSByte1();

  op_data->z80->setA(op_data->z80->getPOIX(o));

  op_data->z80->rrcA();

  op_data->z80->setPOIX(o, op_data->z80->getA());
}

void
CZ80::
f_rrc_po_ix_b(CZ80OpData *op_data)
{
  schar o = op_data->getSByte1();

  op_data->z80->setB(op_data->z80->getPOIX(o));

  op_data->z80->rrcB();

  op_data->z80->setPOIX(o, op_data->z80->getB());
}

void
CZ80::
f_rrc_po_ix_c(CZ80OpData *op_data)
{
  schar o = op_data->getSByte1();

  op_data->z80->setC(op_data->z80->getPOIX(o));

  op_data->z80->rrcC();

  op_data->z80->setPOIX(o, op_data->z80->getC());
}

void
CZ80::
f_rrc_po_ix_d(CZ80OpData *op_data)
{
  schar o = op_data->getSByte1();

  op_data->z80->setD(op_data->z80->getPOIX(o));

  op_data->z80->rrcD();

  op_data->z80->setPOIX(o, op_data->z80->getD());
}

void
CZ80::
f_rrc_po_ix_e(CZ80OpData *op_data)
{
  schar o = op_data->getSByte1();

  op_data->z80->setE(op_data->z80->getPOIX(o));

  op_data->z80->rrcE();

  op_data->z80->setPOIX(o, op_data->z80->getE());
}

void
CZ80::
f_rrc_po_ix_h(CZ80OpData *op_data)
{
  schar o = op_data->getSByte1();

  op_data->z80->setH(op_data->z80->getPOIX(o));

  op_data->z80->rrcH();

  op_data->z80->setPOIX(o, op_data->z80->getH());
}

void
CZ80::
f_rrc_po_ix_l(CZ80OpData *op_data)
{
  schar o = op_data->getSByte1();

  op_data->z80->setL(op_data->z80->getPOIX(o));

  op_data->z80->rrcL();

  op_data->z80->setPOIX(o, op_data->z80->getL());
}

void
CZ80::
f_rrc_po_iy(CZ80OpData *op_data)
{
  op_data->z80->rrcPOIY(op_data->getSByte1());
}

void
CZ80::
f_rrc_po_iy_a(CZ80OpData *op_data)
{
  schar o = op_data->getSByte1();

  op_data->z80->setA(op_data->z80->getPOIY(o));

  op_data->z80->rrcA();

  op_data->z80->setPOIY(o, op_data->z80->getA());
}

void
CZ80::
f_rrc_po_iy_b(CZ80OpData *op_data)
{
  schar o = op_data->getSByte1();

  op_data->z80->setB(op_data->z80->getPOIY(o));

  op_data->z80->rrcB();

  op_data->z80->setPOIY(o, op_data->z80->getB());
}

void
CZ80::
f_rrc_po_iy_c(CZ80OpData *op_data)
{
  schar o = op_data->getSByte1();

  op_data->z80->setC(op_data->z80->getPOIY(o));

  op_data->z80->rrcC();

  op_data->z80->setPOIY(o, op_data->z80->getC());
}

void
CZ80::
f_rrc_po_iy_d(CZ80OpData *op_data)
{
  schar o = op_data->getSByte1();

  op_data->z80->setD(op_data->z80->getPOIY(o));

  op_data->z80->rrcD();

  op_data->z80->setPOIY(o, op_data->z80->getD());
}

void
CZ80::
f_rrc_po_iy_e(CZ80OpData *op_data)
{
  schar o = op_data->getSByte1();

  op_data->z80->setE(op_data->z80->getPOIY(o));

  op_data->z80->rrcE();

  op_data->z80->setPOIY(o, op_data->z80->getE());
}

void
CZ80::
f_rrc_po_iy_h(CZ80OpData *op_data)
{
  schar o = op_data->getSByte1();

  op_data->z80->setH(op_data->z80->getPOIY(o));

  op_data->z80->rrcH();

  op_data->z80->setPOIY(o, op_data->z80->getH());
}

void
CZ80::
f_rrc_po_iy_l(CZ80OpData *op_data)
{
  schar o = op_data->getSByte1();

  op_data->z80->setL(op_data->z80->getPOIY(o));

  op_data->z80->rrcL();

  op_data->z80->setPOIY(o, op_data->z80->getL());
}

void
CZ80::
f_rrca(CZ80OpData *op_data)
{
  op_data->z80->rrca();
}

void
CZ80::
f_rrd(CZ80OpData *op_data)
{
  op_data->z80->rrd();
}

void
CZ80::
f_rst_n(CZ80OpData *op_data)
{
  op_data->z80->rst(op_data->op->arg1);
}

void
CZ80::
f_sbc_a_a(CZ80OpData *op_data)
{
  op_data->z80->sbcA(op_data->z80->getA());
}

void
CZ80::
f_sbc_a_b(CZ80OpData *op_data)
{
  op_data->z80->sbcA(op_data->z80->getB());
}

void
CZ80::
f_sbc_a_c(CZ80OpData *op_data)
{
  op_data->z80->sbcA(op_data->z80->getC());
}

void
CZ80::
f_sbc_a_d(CZ80OpData *op_data)
{
  op_data->z80->sbcA(op_data->z80->getD());
}

void
CZ80::
f_sbc_a_e(CZ80OpData *op_data)
{
  op_data->z80->sbcA(op_data->z80->getE());
}

void
CZ80::
f_sbc_a_h(CZ80OpData *op_data)
{
  op_data->z80->sbcA(op_data->z80->getH());
}

void
CZ80::
f_sbc_a_l(CZ80OpData *op_data)
{
  op_data->z80->sbcA(op_data->z80->getL());
}

void
CZ80::
f_sbc_a_ixh(CZ80OpData *op_data)
{
  op_data->z80->sbcA(op_data->z80->getIXH());
}

void
CZ80::
f_sbc_a_ixl(CZ80OpData *op_data)
{
  op_data->z80->sbcA(op_data->z80->getIXL());
}

void
CZ80::
f_sbc_a_iyh(CZ80OpData *op_data)
{
  op_data->z80->sbcA(op_data->z80->getIYH());
}

void
CZ80::
f_sbc_a_iyl(CZ80OpData *op_data)
{
  op_data->z80->sbcA(op_data->z80->getIYL());
}

void
CZ80::
f_sbc_a_p_hl(CZ80OpData *op_data)
{
  op_data->z80->sbcA(op_data->z80->getPHL());
}

void
CZ80::
f_sbc_a_n(CZ80OpData *op_data)
{
  op_data->z80->sbcA(op_data->getUByte2());
}

void
CZ80::
f_sbc_po_ix(CZ80OpData *op_data)
{
  op_data->z80->sbcA(op_data->getPOIX1());
}

void
CZ80::
f_sbc_po_iy(CZ80OpData *op_data)
{
  op_data->z80->sbcA(op_data->getPOIY1());
}

void
CZ80::
f_sbc_hl_bc(CZ80OpData *op_data)
{
  op_data->z80->sbcHL(op_data->z80->getBC());
}

void
CZ80::
f_sbc_hl_de(CZ80OpData *op_data)
{
  op_data->z80->sbcHL(op_data->z80->getDE());
}

void
CZ80::
f_sbc_hl_hl(CZ80OpData *op_data)
{
  op_data->z80->sbcHL(op_data->z80->getHL());
}

void
CZ80::
f_sbc_hl_sp(CZ80OpData *op_data)
{
  op_data->z80->sbcHL(op_data->z80->getSP());
}

void
CZ80::
f_scf(CZ80OpData *op_data)
{
  op_data->z80->scf();
}

void
CZ80::
f_set_po_ix_n(CZ80OpData *op_data)
{
  op_data->z80->setBitPOIX(op_data->getSByte2(), op_data->op->arg1);
}

void
CZ80::
f_set_po_iy_n(CZ80OpData *op_data)
{
  op_data->z80->setBitPOIY(op_data->getSByte2(), op_data->op->arg1);
}

void
CZ80::
f_set_a_n(CZ80OpData *op_data)
{
  op_data->z80->setBitA(op_data->op->arg1);
}

void
CZ80::
f_set_b_n(CZ80OpData *op_data)
{
  op_data->z80->setBitB(op_data->op->arg1);
}

void
CZ80::
f_set_c_n(CZ80OpData *op_data)
{
  op_data->z80->setBitC(op_data->op->arg1);
}

void
CZ80::
f_set_d_n(CZ80OpData *op_data)
{
  op_data->z80->setBitD(op_data->op->arg1);
}

void
CZ80::
f_set_e_n(CZ80OpData *op_data)
{
  op_data->z80->setBitE(op_data->op->arg1);
}

void
CZ80::
f_set_h_n(CZ80OpData *op_data)
{
  op_data->z80->setBitH(op_data->op->arg1);
}

void
CZ80::
f_set_l_n(CZ80OpData *op_data)
{
  op_data->z80->setBitL(op_data->op->arg1);
}

void
CZ80::
f_set_p_hl_n(CZ80OpData *op_data)
{
  op_data->z80->setBitPHL(op_data->op->arg1);
}

void
CZ80::
f_set_po_ix_a_n(CZ80OpData *op_data)
{
  f_set_po_ix_a_n(op_data, op_data->op->arg1);
}

void
CZ80::
f_set_po_ix_b_n(CZ80OpData *op_data)
{
  f_set_po_ix_b_n(op_data, op_data->op->arg1);
}

void
CZ80::
f_set_po_ix_c_n(CZ80OpData *op_data)
{
  f_set_po_ix_c_n(op_data, op_data->op->arg1);
}

void
CZ80::
f_set_po_ix_d_n(CZ80OpData *op_data)
{
  f_set_po_ix_d_n(op_data, op_data->op->arg1);
}

void
CZ80::
f_set_po_ix_e_n(CZ80OpData *op_data)
{
  f_set_po_ix_e_n(op_data, op_data->op->arg1);
}

void
CZ80::
f_set_po_ix_h_n(CZ80OpData *op_data)
{
  f_set_po_ix_h_n(op_data, op_data->op->arg1);
}

void
CZ80::
f_set_po_ix_l_n(CZ80OpData *op_data)
{
  f_set_po_ix_l_n(op_data, op_data->op->arg1);
}

void
CZ80::
f_set_po_iy_a_n(CZ80OpData *op_data)
{
  f_set_po_iy_a_n(op_data, op_data->op->arg1);
}

void
CZ80::
f_set_po_iy_b_n(CZ80OpData *op_data)
{
  f_set_po_iy_b_n(op_data, op_data->op->arg1);
}

void
CZ80::
f_set_po_iy_c_n(CZ80OpData *op_data)
{
  f_set_po_iy_c_n(op_data, op_data->op->arg1);
}

void
CZ80::
f_set_po_iy_d_n(CZ80OpData *op_data)
{
  f_set_po_iy_d_n(op_data, op_data->op->arg1);
}

void
CZ80::
f_set_po_iy_e_n(CZ80OpData *op_data)
{
  f_set_po_iy_e_n(op_data, op_data->op->arg1);
}

void
CZ80::
f_set_po_iy_h_n(CZ80OpData *op_data)
{
  f_set_po_iy_h_n(op_data, op_data->op->arg1);
}

void
CZ80::
f_set_po_iy_l_n(CZ80OpData *op_data)
{
  f_set_po_iy_l_n(op_data, op_data->op->arg1);
}

void
CZ80::
f_set_po_ix_a_n(CZ80OpData *op_data, uchar n)
{
  schar o = op_data->getSByte2();

  op_data->z80->setA(op_data->z80->getPOIX(o));

  op_data->z80->setBitA(n);

  op_data->z80->setPOIX(o, op_data->z80->getA());
}

void
CZ80::
f_set_po_ix_b_n(CZ80OpData *op_data, uchar n)
{
  schar o = op_data->getSByte2();

  op_data->z80->setB(op_data->z80->getPOIX(o));

  op_data->z80->setBitB(n);

  op_data->z80->setPOIX(o, op_data->z80->getB());
}

void
CZ80::
f_set_po_ix_c_n(CZ80OpData *op_data, uchar n)
{
  schar o = op_data->getSByte2();

  op_data->z80->setC(op_data->z80->getPOIX(o));

  op_data->z80->setBitC(n);

  op_data->z80->setPOIX(o, op_data->z80->getC());
}

void
CZ80::
f_set_po_ix_d_n(CZ80OpData *op_data, uchar n)
{
  schar o = op_data->getSByte2();

  op_data->z80->setD(op_data->z80->getPOIX(o));

  op_data->z80->setBitD(n);

  op_data->z80->setPOIX(o, op_data->z80->getD());
}

void
CZ80::
f_set_po_ix_e_n(CZ80OpData *op_data, uchar n)
{
  schar o = op_data->getSByte2();

  op_data->z80->setE(op_data->z80->getPOIX(o));

  op_data->z80->setBitE(n);

  op_data->z80->setPOIX(o, op_data->z80->getE());
}

void
CZ80::
f_set_po_ix_h_n(CZ80OpData *op_data, uchar n)
{
  schar o = op_data->getSByte2();

  op_data->z80->setH(op_data->z80->getPOIX(o));

  op_data->z80->setBitH(n);

  op_data->z80->setPOIX(o, op_data->z80->getH());
}

void
CZ80::
f_set_po_ix_l_n(CZ80OpData *op_data, uchar n)
{
  schar o = op_data->getSByte2();

  op_data->z80->setL(op_data->z80->getPOIX(o));

  op_data->z80->setBitL(n);

  op_data->z80->setPOIX(o, op_data->z80->getL());
}

void
CZ80::
f_set_po_iy_a_n(CZ80OpData *op_data, uchar n)
{
  schar o = op_data->getSByte2();

  op_data->z80->setA(op_data->z80->getPOIY(o));

  op_data->z80->setBitA(n);

  op_data->z80->setPOIY(o, op_data->z80->getA());
}

void
CZ80::
f_set_po_iy_b_n(CZ80OpData *op_data, uchar n)
{
  schar o = op_data->getSByte2();

  op_data->z80->setB(op_data->z80->getPOIY(o));

  op_data->z80->setBitB(n);

  op_data->z80->setPOIY(o, op_data->z80->getB());
}

void
CZ80::
f_set_po_iy_c_n(CZ80OpData *op_data, uchar n)
{
  schar o = op_data->getSByte2();

  op_data->z80->setC(op_data->z80->getPOIY(o));

  op_data->z80->setBitC(n);

  op_data->z80->setPOIY(o, op_data->z80->getC());
}

void
CZ80::
f_set_po_iy_d_n(CZ80OpData *op_data, uchar n)
{
  schar o = op_data->getSByte2();

  op_data->z80->setD(op_data->z80->getPOIY(o));

  op_data->z80->setBitD(n);

  op_data->z80->setPOIY(o, op_data->z80->getD());
}

void
CZ80::
f_set_po_iy_e_n(CZ80OpData *op_data, uchar n)
{
  schar o = op_data->getSByte2();

  op_data->z80->setE(op_data->z80->getPOIY(o));

  op_data->z80->setBitE(n);

  op_data->z80->setPOIY(o, op_data->z80->getE());
}

void
CZ80::
f_set_po_iy_h_n(CZ80OpData *op_data, uchar n)
{
  schar o = op_data->getSByte2();

  op_data->z80->setH(op_data->z80->getPOIY(o));

  op_data->z80->setBitH(n);

  op_data->z80->setPOIY(o, op_data->z80->getH());
}

void
CZ80::
f_set_po_iy_l_n(CZ80OpData *op_data, uchar n)
{
  schar o = op_data->getSByte2();

  op_data->z80->setL(op_data->z80->getPOIY(o));

  op_data->z80->setBitL(n);

  op_data->z80->setPOIY(o, op_data->z80->getL());
}

void
CZ80::
f_sla_a(CZ80OpData *op_data)
{
  op_data->z80->slaA();
}

void
CZ80::
f_sla_b(CZ80OpData *op_data)
{
  op_data->z80->slaB();
}

void
CZ80::
f_sla_c(CZ80OpData *op_data)
{
  op_data->z80->slaC();
}

void
CZ80::
f_sla_d(CZ80OpData *op_data)
{
  op_data->z80->slaD();
}

void
CZ80::
f_sla_e(CZ80OpData *op_data)
{
  op_data->z80->slaE();
}

void
CZ80::
f_sla_h(CZ80OpData *op_data)
{
  op_data->z80->slaH();
}

void
CZ80::
f_sla_l(CZ80OpData *op_data)
{
  op_data->z80->slaL();
}

void
CZ80::
f_sla_p_hl(CZ80OpData *op_data)
{
  op_data->z80->slaPHL();
}

void
CZ80::
f_sla_po_ix(CZ80OpData *op_data)
{
  op_data->z80->slaPOIX(op_data->getSByte1());
}

void
CZ80::
f_sla_po_ix_a(CZ80OpData *op_data)
{
  schar o = op_data->getSByte1();

  op_data->z80->setA(op_data->z80->getPOIX(o));

  op_data->z80->slaA();

  op_data->z80->setPOIX(o, op_data->z80->getA());
}

void
CZ80::
f_sla_po_ix_b(CZ80OpData *op_data)
{
  schar o = op_data->getSByte1();

  op_data->z80->setB(op_data->z80->getPOIX(o));

  op_data->z80->slaB();

  op_data->z80->setPOIX(o, op_data->z80->getB());
}

void
CZ80::
f_sla_po_ix_c(CZ80OpData *op_data)
{
  schar o = op_data->getSByte1();

  op_data->z80->setC(op_data->z80->getPOIX(o));

  op_data->z80->slaC();

  op_data->z80->setPOIX(o, op_data->z80->getC());
}

void
CZ80::
f_sla_po_ix_d(CZ80OpData *op_data)
{
  schar o = op_data->getSByte1();

  op_data->z80->setD(op_data->z80->getPOIX(o));

  op_data->z80->slaD();

  op_data->z80->setPOIX(o, op_data->z80->getD());
}

void
CZ80::
f_sla_po_ix_e(CZ80OpData *op_data)
{
  schar o = op_data->getSByte1();

  op_data->z80->setE(op_data->z80->getPOIX(o));

  op_data->z80->slaE();

  op_data->z80->setPOIX(o, op_data->z80->getE());
}

void
CZ80::
f_sla_po_ix_h(CZ80OpData *op_data)
{
  schar o = op_data->getSByte1();

  op_data->z80->setH(op_data->z80->getPOIX(o));

  op_data->z80->slaH();

  op_data->z80->setPOIX(o, op_data->z80->getH());
}

void
CZ80::
f_sla_po_ix_l(CZ80OpData *op_data)
{
  schar o = op_data->getSByte1();

  op_data->z80->setL(op_data->z80->getPOIX(o));

  op_data->z80->slaL();

  op_data->z80->setPOIX(o, op_data->z80->getL());
}

void
CZ80::
f_sla_po_iy(CZ80OpData *op_data)
{
  op_data->z80->slaPOIY(op_data->getSByte1());
}

void
CZ80::
f_sla_po_iy_a(CZ80OpData *op_data)
{
  schar o = op_data->getSByte1();

  op_data->z80->setA(op_data->z80->getPOIY(o));

  op_data->z80->slaA();

  op_data->z80->setPOIY(o, op_data->z80->getA());
}

void
CZ80::
f_sla_po_iy_b(CZ80OpData *op_data)
{
  schar o = op_data->getSByte1();

  op_data->z80->setB(op_data->z80->getPOIY(o));

  op_data->z80->slaB();

  op_data->z80->setPOIY(o, op_data->z80->getB());
}

void
CZ80::
f_sla_po_iy_c(CZ80OpData *op_data)
{
  schar o = op_data->getSByte1();

  op_data->z80->setC(op_data->z80->getPOIY(o));

  op_data->z80->slaC();

  op_data->z80->setPOIY(o, op_data->z80->getC());
}

void
CZ80::
f_sla_po_iy_d(CZ80OpData *op_data)
{
  schar o = op_data->getSByte1();

  op_data->z80->setD(op_data->z80->getPOIY(o));

  op_data->z80->slaD();

  op_data->z80->setPOIY(o, op_data->z80->getD());
}

void
CZ80::
f_sla_po_iy_e(CZ80OpData *op_data)
{
  schar o = op_data->getSByte1();

  op_data->z80->setE(op_data->z80->getPOIY(o));

  op_data->z80->slaE();

  op_data->z80->setPOIY(o, op_data->z80->getE());
}

void
CZ80::
f_sla_po_iy_h(CZ80OpData *op_data)
{
  schar o = op_data->getSByte1();

  op_data->z80->setH(op_data->z80->getPOIY(o));

  op_data->z80->slaH();

  op_data->z80->setPOIY(o, op_data->z80->getH());
}

void
CZ80::
f_sla_po_iy_l(CZ80OpData *op_data)
{
  schar o = op_data->getSByte1();

  op_data->z80->setL(op_data->z80->getPOIY(o));

  op_data->z80->slaL();

  op_data->z80->setPOIY(o, op_data->z80->getL());
}

void
CZ80::
f_sll_a(CZ80OpData *op_data)
{
  op_data->z80->sllA();
}

void
CZ80::
f_sll_b(CZ80OpData *op_data)
{
  op_data->z80->sllB();
}

void
CZ80::
f_sll_c(CZ80OpData *op_data)
{
  op_data->z80->sllC();
}

void
CZ80::
f_sll_d(CZ80OpData *op_data)
{
  op_data->z80->sllD();
}

void
CZ80::
f_sll_e(CZ80OpData *op_data)
{
  op_data->z80->sllE();
}

void
CZ80::
f_sll_h(CZ80OpData *op_data)
{
  op_data->z80->sllH();
}

void
CZ80::
f_sll_l(CZ80OpData *op_data)
{
  op_data->z80->sllL();
}

void
CZ80::
f_sll_p_hl(CZ80OpData *op_data)
{
  op_data->z80->sllPHL();
}

void
CZ80::
f_sll_po_ix(CZ80OpData *op_data)
{
  op_data->z80->sllPOIX(op_data->getSByte1());
}

void
CZ80::
f_sll_po_ix_a(CZ80OpData *op_data)
{
  schar o = op_data->getSByte1();

  op_data->z80->setA(op_data->z80->getPOIX(o));

  op_data->z80->sllA();

  op_data->z80->setPOIX(o, op_data->z80->getA());
}

void
CZ80::
f_sll_po_ix_b(CZ80OpData *op_data)
{
  schar o = op_data->getSByte1();

  op_data->z80->setB(op_data->z80->getPOIX(o));

  op_data->z80->sllB();

  op_data->z80->setPOIX(o, op_data->z80->getB());
}

void
CZ80::
f_sll_po_ix_c(CZ80OpData *op_data)
{
  schar o = op_data->getSByte1();

  op_data->z80->setC(op_data->z80->getPOIX(o));

  op_data->z80->sllC();

  op_data->z80->setPOIX(o, op_data->z80->getC());
}

void
CZ80::
f_sll_po_ix_d(CZ80OpData *op_data)
{
  schar o = op_data->getSByte1();

  op_data->z80->setD(op_data->z80->getPOIX(o));

  op_data->z80->sllD();

  op_data->z80->setPOIX(o, op_data->z80->getD());
}

void
CZ80::
f_sll_po_ix_e(CZ80OpData *op_data)
{
  schar o = op_data->getSByte1();

  op_data->z80->setE(op_data->z80->getPOIX(o));

  op_data->z80->sllE();

  op_data->z80->setPOIX(o, op_data->z80->getE());
}

void
CZ80::
f_sll_po_ix_h(CZ80OpData *op_data)
{
  schar o = op_data->getSByte1();

  op_data->z80->setH(op_data->z80->getPOIX(o));

  op_data->z80->sllH();

  op_data->z80->setPOIX(o, op_data->z80->getH());
}

void
CZ80::
f_sll_po_ix_l(CZ80OpData *op_data)
{
  schar o = op_data->getSByte1();

  op_data->z80->setL(op_data->z80->getPOIX(o));

  op_data->z80->sllL();

  op_data->z80->setPOIX(o, op_data->z80->getL());
}

void
CZ80::
f_sll_po_iy(CZ80OpData *op_data)
{
  op_data->z80->sllPOIY(op_data->getSByte1());
}

void
CZ80::
f_sll_po_iy_a(CZ80OpData *op_data)
{
  schar o = op_data->getSByte1();

  op_data->z80->setA(op_data->z80->getPOIY(o));

  op_data->z80->sllA();

  op_data->z80->setPOIY(o, op_data->z80->getA());
}

void
CZ80::
f_sll_po_iy_b(CZ80OpData *op_data)
{
  schar o = op_data->getSByte1();

  op_data->z80->setB(op_data->z80->getPOIY(o));

  op_data->z80->sllB();

  op_data->z80->setPOIY(o, op_data->z80->getB());
}

void
CZ80::
f_sll_po_iy_c(CZ80OpData *op_data)
{
  schar o = op_data->getSByte1();

  op_data->z80->setC(op_data->z80->getPOIY(o));

  op_data->z80->sllC();

  op_data->z80->setPOIY(o, op_data->z80->getC());
}

void
CZ80::
f_sll_po_iy_d(CZ80OpData *op_data)
{
  schar o = op_data->getSByte1();

  op_data->z80->setD(op_data->z80->getPOIY(o));

  op_data->z80->sllD();

  op_data->z80->setPOIY(o, op_data->z80->getD());
}

void
CZ80::
f_sll_po_iy_e(CZ80OpData *op_data)
{
  schar o = op_data->getSByte1();

  op_data->z80->setE(op_data->z80->getPOIY(o));

  op_data->z80->sllE();

  op_data->z80->setPOIY(o, op_data->z80->getE());
}

void
CZ80::
f_sll_po_iy_h(CZ80OpData *op_data)
{
  schar o = op_data->getSByte1();

  op_data->z80->setH(op_data->z80->getPOIY(o));

  op_data->z80->sllH();

  op_data->z80->setPOIY(o, op_data->z80->getH());
}

void
CZ80::
f_sll_po_iy_l(CZ80OpData *op_data)
{
  schar o = op_data->getSByte1();

  op_data->z80->setL(op_data->z80->getPOIY(o));

  op_data->z80->sllL();

  op_data->z80->setPOIY(o, op_data->z80->getL());
}

void
CZ80::
f_sra_a(CZ80OpData *op_data)
{
  op_data->z80->sraA();
}

void
CZ80::
f_sra_b(CZ80OpData *op_data)
{
  op_data->z80->sraB();
}

void
CZ80::
f_sra_c(CZ80OpData *op_data)
{
  op_data->z80->sraC();
}

void
CZ80::
f_sra_d(CZ80OpData *op_data)
{
  op_data->z80->sraD();
}

void
CZ80::
f_sra_e(CZ80OpData *op_data)
{
  op_data->z80->sraE();
}

void
CZ80::
f_sra_h(CZ80OpData *op_data)
{
  op_data->z80->sraH();
}

void
CZ80::
f_sra_l(CZ80OpData *op_data)
{
  op_data->z80->sraL();
}

void
CZ80::
f_sra_p_hl(CZ80OpData *op_data)
{
  op_data->z80->sraPHL();
}

void
CZ80::
f_sra_po_ix(CZ80OpData *op_data)
{
  op_data->z80->sraPOIX(op_data->getSByte1());
}

void
CZ80::
f_sra_po_ix_a(CZ80OpData *op_data)
{
  schar o = op_data->getSByte1();

  op_data->z80->setA(op_data->z80->getPOIX(o));

  op_data->z80->sraA();

  op_data->z80->setPOIX(o, op_data->z80->getA());
}

void
CZ80::
f_sra_po_ix_b(CZ80OpData *op_data)
{
  schar o = op_data->getSByte1();

  op_data->z80->setB(op_data->z80->getPOIX(o));

  op_data->z80->sraB();

  op_data->z80->setPOIX(o, op_data->z80->getB());
}

void
CZ80::
f_sra_po_ix_c(CZ80OpData *op_data)
{
  schar o = op_data->getSByte1();

  op_data->z80->setC(op_data->z80->getPOIX(o));

  op_data->z80->sraC();

  op_data->z80->setPOIX(o, op_data->z80->getC());
}

void
CZ80::
f_sra_po_ix_d(CZ80OpData *op_data)
{
  schar o = op_data->getSByte1();

  op_data->z80->setD(op_data->z80->getPOIX(o));

  op_data->z80->sraD();

  op_data->z80->setPOIX(o, op_data->z80->getD());
}

void
CZ80::
f_sra_po_ix_e(CZ80OpData *op_data)
{
  schar o = op_data->getSByte1();

  op_data->z80->setE(op_data->z80->getPOIX(o));

  op_data->z80->sraE();

  op_data->z80->setPOIX(o, op_data->z80->getE());
}

void
CZ80::
f_sra_po_ix_h(CZ80OpData *op_data)
{
  schar o = op_data->getSByte1();

  op_data->z80->setH(op_data->z80->getPOIX(o));

  op_data->z80->sraH();

  op_data->z80->setPOIX(o, op_data->z80->getH());
}

void
CZ80::
f_sra_po_ix_l(CZ80OpData *op_data)
{
  schar o = op_data->getSByte1();

  op_data->z80->setL(op_data->z80->getPOIX(o));

  op_data->z80->sraL();

  op_data->z80->setPOIX(o, op_data->z80->getL());
}

void
CZ80::
f_sra_po_iy(CZ80OpData *op_data)
{
  op_data->z80->sraPOIY(op_data->getSByte1());
}

void
CZ80::
f_sra_po_iy_a(CZ80OpData *op_data)
{
  schar o = op_data->getSByte1();

  op_data->z80->setA(op_data->z80->getPOIY(o));

  op_data->z80->sraA();

  op_data->z80->setPOIY(o, op_data->z80->getA());
}

void
CZ80::
f_sra_po_iy_b(CZ80OpData *op_data)
{
  schar o = op_data->getSByte1();

  op_data->z80->setB(op_data->z80->getPOIY(o));

  op_data->z80->sraB();

  op_data->z80->setPOIY(o, op_data->z80->getB());
}

void
CZ80::
f_sra_po_iy_c(CZ80OpData *op_data)
{
  schar o = op_data->getSByte1();

  op_data->z80->setC(op_data->z80->getPOIY(o));

  op_data->z80->sraC();

  op_data->z80->setPOIY(o, op_data->z80->getC());
}

void
CZ80::
f_sra_po_iy_d(CZ80OpData *op_data)
{
  schar o = op_data->getSByte1();

  op_data->z80->setD(op_data->z80->getPOIY(o));

  op_data->z80->sraD();

  op_data->z80->setPOIY(o, op_data->z80->getD());
}

void
CZ80::
f_sra_po_iy_e(CZ80OpData *op_data)
{
  schar o = op_data->getSByte1();

  op_data->z80->setE(op_data->z80->getPOIY(o));

  op_data->z80->sraE();

  op_data->z80->setPOIY(o, op_data->z80->getE());
}

void
CZ80::
f_sra_po_iy_h(CZ80OpData *op_data)
{
  schar o = op_data->getSByte1();

  op_data->z80->setH(op_data->z80->getPOIY(o));

  op_data->z80->sraH();

  op_data->z80->setPOIY(o, op_data->z80->getH());
}

void
CZ80::
f_sra_po_iy_l(CZ80OpData *op_data)
{
  schar o = op_data->getSByte1();

  op_data->z80->setL(op_data->z80->getPOIY(o));

  op_data->z80->sraL();

  op_data->z80->setPOIY(o, op_data->z80->getL());
}

void
CZ80::
f_srl_a(CZ80OpData *op_data)
{
  op_data->z80->srlA();
}

void
CZ80::
f_srl_b(CZ80OpData *op_data)
{
  op_data->z80->srlB();
}

void
CZ80::
f_srl_c(CZ80OpData *op_data)
{
  op_data->z80->srlC();
}

void
CZ80::
f_srl_d(CZ80OpData *op_data)
{
  op_data->z80->srlD();
}

void
CZ80::
f_srl_e(CZ80OpData *op_data)
{
  op_data->z80->srlE();
}

void
CZ80::
f_srl_h(CZ80OpData *op_data)
{
  op_data->z80->srlH();
}

void
CZ80::
f_srl_l(CZ80OpData *op_data)
{
  op_data->z80->srlL();
}

void
CZ80::
f_srl_p_hl(CZ80OpData *op_data)
{
  op_data->z80->srlPHL();
}

void
CZ80::
f_srl_po_ix(CZ80OpData *op_data)
{
  op_data->z80->srlPOIX(op_data->getSByte1());
}

void
CZ80::
f_srl_po_ix_a(CZ80OpData *op_data)
{
  schar o = op_data->getSByte1();

  op_data->z80->setA(op_data->z80->getPOIX(o));

  op_data->z80->srlA();

  op_data->z80->setPOIX(o, op_data->z80->getA());
}

void
CZ80::
f_srl_po_ix_b(CZ80OpData *op_data)
{
  schar o = op_data->getSByte1();

  op_data->z80->setB(op_data->z80->getPOIX(o));

  op_data->z80->srlB();

  op_data->z80->setPOIX(o, op_data->z80->getB());
}

void
CZ80::
f_srl_po_ix_c(CZ80OpData *op_data)
{
  schar o = op_data->getSByte1();

  op_data->z80->setC(op_data->z80->getPOIX(o));

  op_data->z80->srlC();

  op_data->z80->setPOIX(o, op_data->z80->getC());
}

void
CZ80::
f_srl_po_ix_d(CZ80OpData *op_data)
{
  schar o = op_data->getSByte1();

  op_data->z80->setD(op_data->z80->getPOIX(o));

  op_data->z80->srlD();

  op_data->z80->setPOIX(o, op_data->z80->getD());
}

void
CZ80::
f_srl_po_ix_e(CZ80OpData *op_data)
{
  schar o = op_data->getSByte1();

  op_data->z80->setE(op_data->z80->getPOIX(o));

  op_data->z80->srlE();

  op_data->z80->setPOIX(o, op_data->z80->getE());
}

void
CZ80::
f_srl_po_ix_h(CZ80OpData *op_data)
{
  schar o = op_data->getSByte1();

  op_data->z80->setH(op_data->z80->getPOIX(o));

  op_data->z80->srlH();

  op_data->z80->setPOIX(o, op_data->z80->getH());
}

void
CZ80::
f_srl_po_ix_l(CZ80OpData *op_data)
{
  schar o = op_data->getSByte1();

  op_data->z80->setL(op_data->z80->getPOIX(o));

  op_data->z80->srlL();

  op_data->z80->setPOIX(o, op_data->z80->getL());
}

void
CZ80::
f_srl_po_iy(CZ80OpData *op_data)
{
  op_data->z80->srlPOIY(op_data->getSByte1());
}

void
CZ80::
f_srl_po_iy_a(CZ80OpData *op_data)
{
  schar o = op_data->getSByte1();

  op_data->z80->setA(op_data->z80->getPOIY(o));

  op_data->z80->srlA();

  op_data->z80->setPOIY(o, op_data->z80->getA());
}

void
CZ80::
f_srl_po_iy_b(CZ80OpData *op_data)
{
  schar o = op_data->getSByte1();

  op_data->z80->setB(op_data->z80->getPOIY(o));

  op_data->z80->srlB();

  op_data->z80->setPOIY(o, op_data->z80->getB());
}

void
CZ80::
f_srl_po_iy_c(CZ80OpData *op_data)
{
  schar o = op_data->getSByte1();

  op_data->z80->setC(op_data->z80->getPOIY(o));

  op_data->z80->srlC();

  op_data->z80->setPOIY(o, op_data->z80->getC());
}

void
CZ80::
f_srl_po_iy_d(CZ80OpData *op_data)
{
  schar o = op_data->getSByte1();

  op_data->z80->setD(op_data->z80->getPOIY(o));

  op_data->z80->srlD();

  op_data->z80->setPOIY(o, op_data->z80->getD());
}

void
CZ80::
f_srl_po_iy_e(CZ80OpData *op_data)
{
  schar o = op_data->getSByte1();

  op_data->z80->setE(op_data->z80->getPOIY(o));

  op_data->z80->srlE();

  op_data->z80->setPOIY(o, op_data->z80->getE());
}

void
CZ80::
f_srl_po_iy_h(CZ80OpData *op_data)
{
  schar o = op_data->getSByte1();

  op_data->z80->setH(op_data->z80->getPOIY(o));

  op_data->z80->srlH();

  op_data->z80->setPOIY(o, op_data->z80->getH());
}

void
CZ80::
f_srl_po_iy_l(CZ80OpData *op_data)
{
  schar o = op_data->getSByte1();

  op_data->z80->setL(op_data->z80->getPOIY(o));

  op_data->z80->srlL();

  op_data->z80->setPOIY(o, op_data->z80->getL());
}

void
CZ80::
f_sub_a(CZ80OpData *op_data)
{
  op_data->z80->subA(op_data->z80->getA());
}

void
CZ80::
f_sub_b(CZ80OpData *op_data)
{
  op_data->z80->subA(op_data->z80->getB());
}

void
CZ80::
f_sub_c(CZ80OpData *op_data)
{
  op_data->z80->subA(op_data->z80->getC());
}

void
CZ80::
f_sub_d(CZ80OpData *op_data)
{
  op_data->z80->subA(op_data->z80->getD());
}

void
CZ80::
f_sub_e(CZ80OpData *op_data)
{
  op_data->z80->subA(op_data->z80->getE());
}

void
CZ80::
f_sub_h(CZ80OpData *op_data)
{
  op_data->z80->subA(op_data->z80->getH());
}

void
CZ80::
f_sub_l(CZ80OpData *op_data)
{
  op_data->z80->subA(op_data->z80->getL());
}

void
CZ80::
f_sub_ixh(CZ80OpData *op_data)
{
  op_data->z80->subA(op_data->z80->getIXH());
}

void
CZ80::
f_sub_ixl(CZ80OpData *op_data)
{
  op_data->z80->subA(op_data->z80->getIXL());
}

void
CZ80::
f_sub_iyh(CZ80OpData *op_data)
{
  op_data->z80->subA(op_data->z80->getIYH());
}

void
CZ80::
f_sub_iyl(CZ80OpData *op_data)
{
  op_data->z80->subA(op_data->z80->getIYL());
}

void
CZ80::
f_sub_p_hl(CZ80OpData *op_data)
{
  op_data->z80->subA(op_data->z80->getPHL());
}

void
CZ80::
f_sub_n(CZ80OpData *op_data)
{
  op_data->z80->subA(op_data->getUByte1());
}

void
CZ80::
f_sub_po_ix(CZ80OpData *op_data)
{
  op_data->z80->subA(op_data->getPOIX1());
}

void
CZ80::
f_sub_po_iy(CZ80OpData *op_data)
{
  op_data->z80->subA(op_data->getPOIY1());
}

void
CZ80::
f_xor_a(CZ80OpData *op_data)
{
  op_data->z80->xorA(op_data->z80->getA());
}

void
CZ80::
f_xor_b(CZ80OpData *op_data)
{
  op_data->z80->xorA(op_data->z80->getB());
}

void
CZ80::
f_xor_c(CZ80OpData *op_data)
{
  op_data->z80->xorA(op_data->z80->getC());
}

void
CZ80::
f_xor_d(CZ80OpData *op_data)
{
  op_data->z80->xorA(op_data->z80->getD());
}

void
CZ80::
f_xor_e(CZ80OpData *op_data)
{
  op_data->z80->xorA(op_data->z80->getE());
}

void
CZ80::
f_xor_h(CZ80OpData *op_data)
{
  op_data->z80->xorA(op_data->z80->getH());
}

void
CZ80::
f_xor_l(CZ80OpData *op_data)
{
  op_data->z80->xorA(op_data->z80->getL());
}

void
CZ80::
f_xor_ixh(CZ80OpData *op_data)
{
  op_data->z80->xorA(op_data->z80->getIXH());
}

void
CZ80::
f_xor_ixl(CZ80OpData *op_data)
{
  op_data->z80->xorA(op_data->z80->getIXL());
}

void
CZ80::
f_xor_iyh(CZ80OpData *op_data)
{
  op_data->z80->xorA(op_data->z80->getIYH());
}

void
CZ80::
f_xor_iyl(CZ80OpData *op_data)
{
  op_data->z80->xorA(op_data->z80->getIYL());
}

void
CZ80::
f_xor_p_hl(CZ80OpData *op_data)
{
  op_data->z80->xorA(op_data->z80->getPHL());
}

void
CZ80::
f_xor_n(CZ80OpData *op_data)
{
  op_data->z80->xorA(op_data->getUByte1());
}

void
CZ80::
f_xor_po_ix(CZ80OpData *op_data)
{
  op_data->z80->xorA(op_data->getPOIX1());
}

void
CZ80::
f_xor_po_iy(CZ80OpData *op_data)
{
  op_data->z80->xorA(op_data->getPOIY1());
}

void
CZ80::
f_err(CZ80OpData *op_data)
{
  std::cerr << "unimplemented " << op_data->getName() << std::endl;

  f_halt(op_data);
}
