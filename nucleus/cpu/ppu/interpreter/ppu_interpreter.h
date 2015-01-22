/**
 * (c) 2015 Nucleus project. All rights reserved.
 * Released under GPL v2 license. Read LICENSE for more details.
 */

#pragma once

#include "nucleus/common.h"
#include "nucleus/cpu/translator.h"
#include "nucleus/cpu/ppu/ppu_thread.h"
#include "nucleus/cpu/ppu/ppu_instruction.h"

namespace cpu {
namespace ppu {

class PPUInterpreter : public CellTranslator
{
    PPUThread& thread;

public:
    PPUInterpreter(PPUThread& thr);

    // Decode and execute one instruction
    void step();

    // Instruction callers
    static void callTable4  (Instruction code, PPUThread& thread);
    static void callTable4_ (Instruction code, PPUThread& thread);
    static void callTable19 (Instruction code, PPUThread& thread);
    static void callTable30 (Instruction code, PPUThread& thread);
    static void callTable31 (Instruction code, PPUThread& thread);
    static void callTable58 (Instruction code, PPUThread& thread);
    static void callTable59 (Instruction code, PPUThread& thread);
    static void callTable62 (Instruction code, PPUThread& thread);
    static void callTable63 (Instruction code, PPUThread& thread);
    static void callTable63_(Instruction code, PPUThread& thread);

    /**
     * Auxiliary functions
     */
    static inline bool isCarry(u64 a, u64 b);
    static inline bool isCarry(u64 a, u64 b, u64 c);
    static inline f32 CheckVSCR_NJ(PPUThread& thread, const f32 v);
    static inline bool CheckCondition(PPUThread& thread, u32 bo, u32 bi);
    static inline u64& GetRegBySPR(PPUThread& thread, u32 spr);

    static void add(Instruction code, PPUThread& thread);
    static void addc(Instruction code, PPUThread& thread);
    static void adde(Instruction code, PPUThread& thread);
    static void addi(Instruction code, PPUThread& thread);
    static void addic(Instruction code, PPUThread& thread);
    static void addic_(Instruction code, PPUThread& thread);
    static void addis(Instruction code, PPUThread& thread);
    static void addme(Instruction code, PPUThread& thread);
    static void addze(Instruction code, PPUThread& thread);
    static void andx(Instruction code, PPUThread& thread);
    static void andc(Instruction code, PPUThread& thread);
    static void andi_(Instruction code, PPUThread& thread);
    static void andis_(Instruction code, PPUThread& thread);
    static void b(Instruction code, PPUThread& thread);
    static void bc(Instruction code, PPUThread& thread);
    static void bcctr(Instruction code, PPUThread& thread);
    static void bclr(Instruction code, PPUThread& thread);
    static void cmp(Instruction code, PPUThread& thread);
    static void cmpi(Instruction code, PPUThread& thread);
    static void cmpl(Instruction code, PPUThread& thread);
    static void cmpli(Instruction code, PPUThread& thread);
    static void cntlzd(Instruction code, PPUThread& thread);
    static void cntlzw(Instruction code, PPUThread& thread);
    static void crand(Instruction code, PPUThread& thread);
    static void crandc(Instruction code, PPUThread& thread);
    static void creqv(Instruction code, PPUThread& thread);
    static void crnand(Instruction code, PPUThread& thread);
    static void crnor(Instruction code, PPUThread& thread);
    static void cror(Instruction code, PPUThread& thread);
    static void crorc(Instruction code, PPUThread& thread);
    static void crxor(Instruction code, PPUThread& thread);
    static void dcbf(Instruction code, PPUThread& thread);
    static void dcbst(Instruction code, PPUThread& thread);
    static void dcbt(Instruction code, PPUThread& thread);
    static void dcbtst(Instruction code, PPUThread& thread);
    static void dcbz(Instruction code, PPUThread& thread);
    static void divd(Instruction code, PPUThread& thread);
    static void divdu(Instruction code, PPUThread& thread);
    static void divw(Instruction code, PPUThread& thread);
    static void divwu(Instruction code, PPUThread& thread);
    static void dss(Instruction code, PPUThread& thread);
    static void dst(Instruction code, PPUThread& thread);
    static void dstst(Instruction code, PPUThread& thread);
    static void eciwx(Instruction code, PPUThread& thread);
    static void ecowx(Instruction code, PPUThread& thread);
    static void eieio(Instruction code, PPUThread& thread);
    static void eqv(Instruction code, PPUThread& thread);
    static void extsb(Instruction code, PPUThread& thread);
    static void extsh(Instruction code, PPUThread& thread);
    static void extsw(Instruction code, PPUThread& thread);
    static void icbi(Instruction code, PPUThread& thread);
    static void isync(Instruction code, PPUThread& thread);
    static void lbz(Instruction code, PPUThread& thread);
    static void lbzu(Instruction code, PPUThread& thread);
    static void lbzux(Instruction code, PPUThread& thread);
    static void lbzx(Instruction code, PPUThread& thread);
    static void ld(Instruction code, PPUThread& thread);
    static void ldarx(Instruction code, PPUThread& thread);
    static void ldbrx(Instruction code, PPUThread& thread);
    static void ldu(Instruction code, PPUThread& thread);
    static void ldux(Instruction code, PPUThread& thread);
    static void ldx(Instruction code, PPUThread& thread);
    static void lha(Instruction code, PPUThread& thread);
    static void lhau(Instruction code, PPUThread& thread);
    static void lhaux(Instruction code, PPUThread& thread);
    static void lhax(Instruction code, PPUThread& thread);
    static void lhbrx(Instruction code, PPUThread& thread);
    static void lhz(Instruction code, PPUThread& thread);
    static void lhzu(Instruction code, PPUThread& thread);
    static void lhzux(Instruction code, PPUThread& thread);
    static void lhzx(Instruction code, PPUThread& thread);
    static void lmw(Instruction code, PPUThread& thread);
    static void lswi(Instruction code, PPUThread& thread);
    static void lswx(Instruction code, PPUThread& thread);
    static void lwa(Instruction code, PPUThread& thread);
    static void lwarx(Instruction code, PPUThread& thread);
    static void lwaux(Instruction code, PPUThread& thread);
    static void lwax(Instruction code, PPUThread& thread);
    static void lwbrx(Instruction code, PPUThread& thread);
    static void lwz(Instruction code, PPUThread& thread);
    static void lwzu(Instruction code, PPUThread& thread);
    static void lwzux(Instruction code, PPUThread& thread);
    static void lwzx(Instruction code, PPUThread& thread);
    static void mcrf(Instruction code, PPUThread& thread);
    static void mcrfs(Instruction code, PPUThread& thread);
    static void mfocrf(Instruction code, PPUThread& thread);
    static void mfspr(Instruction code, PPUThread& thread);
    static void mftb(Instruction code, PPUThread& thread);
    static void mtfsb0(Instruction code, PPUThread& thread);
    static void mtfsb1(Instruction code, PPUThread& thread);
    static void mtfsfi(Instruction code, PPUThread& thread);
    static void mtocrf(Instruction code, PPUThread& thread);
    static void mtspr(Instruction code, PPUThread& thread);
    static void mulhd(Instruction code, PPUThread& thread);
    static void mulhdu(Instruction code, PPUThread& thread);
    static void mulhw(Instruction code, PPUThread& thread);
    static void mulhwu(Instruction code, PPUThread& thread);
    static void mulld(Instruction code, PPUThread& thread);
    static void mulli(Instruction code, PPUThread& thread);
    static void mullw(Instruction code, PPUThread& thread);
    static void nand(Instruction code, PPUThread& thread);
    static void neg(Instruction code, PPUThread& thread);
    static void nop(Instruction code, PPUThread& thread);
    static void nor(Instruction code, PPUThread& thread);
    static void orx(Instruction code, PPUThread& thread);
    static void orc(Instruction code, PPUThread& thread);
    static void ori(Instruction code, PPUThread& thread);
    static void oris(Instruction code, PPUThread& thread);
    static void rldc_lr(Instruction code, PPUThread& thread);
    static void rldicx(Instruction code, PPUThread& thread);
    static void rldiclx(Instruction code, PPUThread& thread);
    static void rldicrx(Instruction code, PPUThread& thread);
    static void rldimix(Instruction code, PPUThread& thread);
    static void rlwimix(Instruction code, PPUThread& thread);
    static void rlwinmx(Instruction code, PPUThread& thread);
    static void rlwnmx(Instruction code, PPUThread& thread);
    static void sc(Instruction code, PPUThread& thread_code);
    static void sld(Instruction code, PPUThread& thread);
    static void slw(Instruction code, PPUThread& thread);
    static void srad(Instruction code, PPUThread& thread);
    static void sradi(Instruction code, PPUThread& thread);
    static void sraw(Instruction code, PPUThread& thread);
    static void srawi(Instruction code, PPUThread& thread);
    static void srd(Instruction code, PPUThread& thread);
    static void srw(Instruction code, PPUThread& thread);
    static void stb(Instruction code, PPUThread& thread);
    static void stbu(Instruction code, PPUThread& thread);
    static void stbux(Instruction code, PPUThread& thread);
    static void stbx(Instruction code, PPUThread& thread);
    static void std(Instruction code, PPUThread& thread);
    static void stdcx_(Instruction code, PPUThread& thread);
    static void stdu(Instruction code, PPUThread& thread);
    static void stdux(Instruction code, PPUThread& thread);
    static void stdx(Instruction code, PPUThread& thread);
    static void sth(Instruction code, PPUThread& thread);
    static void sthbrx(Instruction code, PPUThread& thread);
    static void sthu(Instruction code, PPUThread& thread);
    static void sthux(Instruction code, PPUThread& thread);
    static void sthx(Instruction code, PPUThread& thread);
    static void stmw(Instruction code, PPUThread& thread);
    static void stswi(Instruction code, PPUThread& thread);
    static void stswx(Instruction code, PPUThread& thread);
    static void stvrxl(Instruction code, PPUThread& thread);
    static void stw(Instruction code, PPUThread& thread);
    static void stwbrx(Instruction code, PPUThread& thread);
    static void stwcx_(Instruction code, PPUThread& thread);
    static void stwu(Instruction code, PPUThread& thread);
    static void stwux(Instruction code, PPUThread& thread);
    static void stwx(Instruction code, PPUThread& thread);
    static void subf(Instruction code, PPUThread& thread);
    static void subfc(Instruction code, PPUThread& thread);
    static void subfe(Instruction code, PPUThread& thread);
    static void subfic(Instruction code, PPUThread& thread);
    static void subfme(Instruction code, PPUThread& thread);
    static void subfze(Instruction code, PPUThread& thread);
    static void sync(Instruction code, PPUThread& thread);
    static void td(Instruction code, PPUThread& thread);
    static void tdi(Instruction code, PPUThread& thread);
    static void tw(Instruction code, PPUThread& thread);
    static void twi(Instruction code, PPUThread& thread);
    static void xorx(Instruction code, PPUThread& thread);
    static void xori(Instruction code, PPUThread& thread);
    static void xoris(Instruction code, PPUThread& thread);

    // Floating-Point Unit instructions
    static void lfd(Instruction code, PPUThread& thread);
    static void lfdu(Instruction code, PPUThread& thread);
    static void lfdux(Instruction code, PPUThread& thread);
    static void lfdx(Instruction code, PPUThread& thread);
    static void lfs(Instruction code, PPUThread& thread);
    static void lfsu(Instruction code, PPUThread& thread);
    static void lfsux(Instruction code, PPUThread& thread);
    static void lfsx(Instruction code, PPUThread& thread);
    static void mffs(Instruction code, PPUThread& thread);
    static void mtfsf(Instruction code, PPUThread& thread);
    static void fabs(Instruction code, PPUThread& thread);
    static void fadd(Instruction code, PPUThread& thread);
    static void fadds(Instruction code, PPUThread& thread);
    static void fcfid(Instruction code, PPUThread& thread);
    static void fcmpo(Instruction code, PPUThread& thread);
    static void fcmpu(Instruction code, PPUThread& thread);
    static void fctid(Instruction code, PPUThread& thread);
    static void fctidz(Instruction code, PPUThread& thread);
    static void fctiw(Instruction code, PPUThread& thread);
    static void fctiwz(Instruction code, PPUThread& thread);
    static void fdiv(Instruction code, PPUThread& thread);
    static void fdivs(Instruction code, PPUThread& thread);
    static void fmadd(Instruction code, PPUThread& thread);
    static void fmadds(Instruction code, PPUThread& thread);
    static void fmr(Instruction code, PPUThread& thread);
    static void fmsub(Instruction code, PPUThread& thread);
    static void fmsubs(Instruction code, PPUThread& thread);
    static void fmul(Instruction code, PPUThread& thread);
    static void fmuls(Instruction code, PPUThread& thread);
    static void fnabs(Instruction code, PPUThread& thread);
    static void fneg(Instruction code, PPUThread& thread);
    static void fnmadd(Instruction code, PPUThread& thread);
    static void fnmadds(Instruction code, PPUThread& thread);
    static void fnmsub(Instruction code, PPUThread& thread);
    static void fnmsubs(Instruction code, PPUThread& thread);
    static void fres(Instruction code, PPUThread& thread);
    static void frsp(Instruction code, PPUThread& thread);
    static void frsqrte(Instruction code, PPUThread& thread);
    static void fsel(Instruction code, PPUThread& thread);
    static void fsqrt(Instruction code, PPUThread& thread);
    static void fsqrts(Instruction code, PPUThread& thread);
    static void fsub(Instruction code, PPUThread& thread);
    static void fsubs(Instruction code, PPUThread& thread);
    static void stfd(Instruction code, PPUThread& thread);
    static void stfdu(Instruction code, PPUThread& thread);
    static void stfdux(Instruction code, PPUThread& thread);
    static void stfdx(Instruction code, PPUThread& thread);
    static void stfiwx(Instruction code, PPUThread& thread);
    static void stfs(Instruction code, PPUThread& thread);
    static void stfsu(Instruction code, PPUThread& thread);
    static void stfsux(Instruction code, PPUThread& thread);
    static void stfsx(Instruction code, PPUThread& thread);

    // Vector/SIMD instructions
    static void lvebx(Instruction code, PPUThread& thread);
    static void lvehx(Instruction code, PPUThread& thread);
    static void lvewx(Instruction code, PPUThread& thread);
    static void lvlx(Instruction code, PPUThread& thread);
    static void lvlxl(Instruction code, PPUThread& thread);
    static void lvrx(Instruction code, PPUThread& thread);
    static void lvrxl(Instruction code, PPUThread& thread);
    static void lvsl(Instruction code, PPUThread& thread);
    static void lvsr(Instruction code, PPUThread& thread);
    static void lvx(Instruction code, PPUThread& thread);
    static void lvxl(Instruction code, PPUThread& thread);
    static void mfvscr(Instruction code, PPUThread& thread);
    static void mtvscr(Instruction code, PPUThread& thread);
    static void stvebx(Instruction code, PPUThread& thread);
    static void stvehx(Instruction code, PPUThread& thread);
    static void stvewx(Instruction code, PPUThread& thread);
    static void stvlx(Instruction code, PPUThread& thread);
    static void stvlxl(Instruction code, PPUThread& thread);
    static void stvrx(Instruction code, PPUThread& thread);
    static void stvx(Instruction code, PPUThread& thread);
    static void stvxl(Instruction code, PPUThread& thread);
    static void vaddcuw(Instruction code, PPUThread& thread);
    static void vaddfp(Instruction code, PPUThread& thread);
    static void vaddsbs(Instruction code, PPUThread& thread);
    static void vaddshs(Instruction code, PPUThread& thread);
    static void vaddsws(Instruction code, PPUThread& thread);
    static void vaddubm(Instruction code, PPUThread& thread);
    static void vaddubs(Instruction code, PPUThread& thread);
    static void vadduhm(Instruction code, PPUThread& thread);
    static void vadduhs(Instruction code, PPUThread& thread);
    static void vadduwm(Instruction code, PPUThread& thread);
    static void vadduws(Instruction code, PPUThread& thread);
    static void vand(Instruction code, PPUThread& thread);
    static void vandc(Instruction code, PPUThread& thread);
    static void vavgsb(Instruction code, PPUThread& thread);
    static void vavgsh(Instruction code, PPUThread& thread);
    static void vavgsw(Instruction code, PPUThread& thread);
    static void vavgub(Instruction code, PPUThread& thread);
    static void vavguh(Instruction code, PPUThread& thread);
    static void vavguw(Instruction code, PPUThread& thread);
    static void vcfsx(Instruction code, PPUThread& thread);
    static void vcfux(Instruction code, PPUThread& thread);
    static void vcmpbfp(Instruction code, PPUThread& thread);
    static void vcmpbfp_(Instruction code, PPUThread& thread);
    static void vcmpeqfp(Instruction code, PPUThread& thread);
    static void vcmpeqfp_(Instruction code, PPUThread& thread);
    static void vcmpequb(Instruction code, PPUThread& thread);
    static void vcmpequb_(Instruction code, PPUThread& thread);
    static void vcmpequh(Instruction code, PPUThread& thread);
    static void vcmpequh_(Instruction code, PPUThread& thread);
    static void vcmpequw(Instruction code, PPUThread& thread);
    static void vcmpequw_(Instruction code, PPUThread& thread);
    static void vcmpgefp(Instruction code, PPUThread& thread);
    static void vcmpgefp_(Instruction code, PPUThread& thread);
    static void vcmpgtfp(Instruction code, PPUThread& thread);
    static void vcmpgtfp_(Instruction code, PPUThread& thread);
    static void vcmpgtsb(Instruction code, PPUThread& thread);
    static void vcmpgtsb_(Instruction code, PPUThread& thread);
    static void vcmpgtsh(Instruction code, PPUThread& thread);
    static void vcmpgtsh_(Instruction code, PPUThread& thread);
    static void vcmpgtsw(Instruction code, PPUThread& thread);
    static void vcmpgtsw_(Instruction code, PPUThread& thread);
    static void vcmpgtub(Instruction code, PPUThread& thread);
    static void vcmpgtub_(Instruction code, PPUThread& thread);
    static void vcmpgtuh(Instruction code, PPUThread& thread);
    static void vcmpgtuh_(Instruction code, PPUThread& thread);
    static void vcmpgtuw(Instruction code, PPUThread& thread);
    static void vcmpgtuw_(Instruction code, PPUThread& thread);
    static void vctsxs(Instruction code, PPUThread& thread);
    static void vctuxs(Instruction code, PPUThread& thread);
    static void vexptefp(Instruction code, PPUThread& thread);
    static void vlogefp(Instruction code, PPUThread& thread);
    static void vmaddfp(Instruction code, PPUThread& thread);
    static void vmaxfp(Instruction code, PPUThread& thread);
    static void vmaxsb(Instruction code, PPUThread& thread);
    static void vmaxsh(Instruction code, PPUThread& thread);
    static void vmaxsw(Instruction code, PPUThread& thread);
    static void vmaxub(Instruction code, PPUThread& thread);
    static void vmaxuh(Instruction code, PPUThread& thread);
    static void vmaxuw(Instruction code, PPUThread& thread);
    static void vmhaddshs(Instruction code, PPUThread& thread);
    static void vmhraddshs(Instruction code, PPUThread& thread);
    static void vminfp(Instruction code, PPUThread& thread);
    static void vminsb(Instruction code, PPUThread& thread);
    static void vminsh(Instruction code, PPUThread& thread);
    static void vminsw(Instruction code, PPUThread& thread);
    static void vminub(Instruction code, PPUThread& thread);
    static void vminuh(Instruction code, PPUThread& thread);
    static void vminuw(Instruction code, PPUThread& thread);
    static void vmladduhm(Instruction code, PPUThread& thread);
    static void vmrghb(Instruction code, PPUThread& thread);
    static void vmrghh(Instruction code, PPUThread& thread);
    static void vmrghw(Instruction code, PPUThread& thread);
    static void vmrglb(Instruction code, PPUThread& thread);
    static void vmrglh(Instruction code, PPUThread& thread);
    static void vmrglw(Instruction code, PPUThread& thread);
    static void vmsummbm(Instruction code, PPUThread& thread);
    static void vmsumshm(Instruction code, PPUThread& thread);
    static void vmsumshs(Instruction code, PPUThread& thread);
    static void vmsumubm(Instruction code, PPUThread& thread);
    static void vmsumuhm(Instruction code, PPUThread& thread);
    static void vmsumuhs(Instruction code, PPUThread& thread);
    static void vmulesb(Instruction code, PPUThread& thread);
    static void vmulesh(Instruction code, PPUThread& thread);
    static void vmuleub(Instruction code, PPUThread& thread);
    static void vmuleuh(Instruction code, PPUThread& thread);
    static void vmulosb(Instruction code, PPUThread& thread);
    static void vmulosh(Instruction code, PPUThread& thread);
    static void vmuloub(Instruction code, PPUThread& thread);
    static void vmulouh(Instruction code, PPUThread& thread);
    static void vnmsubfp(Instruction code, PPUThread& thread);
    static void vnor(Instruction code, PPUThread& thread);
    static void vor(Instruction code, PPUThread& thread);
    static void vperm(Instruction code, PPUThread& thread);
    static void vpkpx(Instruction code, PPUThread& thread);
    static void vpkshss(Instruction code, PPUThread& thread);
    static void vpkshus(Instruction code, PPUThread& thread);
    static void vpkswss(Instruction code, PPUThread& thread);
    static void vpkswus(Instruction code, PPUThread& thread);
    static void vpkuhum(Instruction code, PPUThread& thread);
    static void vpkuhus(Instruction code, PPUThread& thread);
    static void vpkuwum(Instruction code, PPUThread& thread);
    static void vpkuwus(Instruction code, PPUThread& thread);
    static void vrefp(Instruction code, PPUThread& thread);
    static void vrfim(Instruction code, PPUThread& thread);
    static void vrfin(Instruction code, PPUThread& thread);
    static void vrfip(Instruction code, PPUThread& thread);
    static void vrfiz(Instruction code, PPUThread& thread);
    static void vrlb(Instruction code, PPUThread& thread);
    static void vrlh(Instruction code, PPUThread& thread);
    static void vrlw(Instruction code, PPUThread& thread);
    static void vrsqrtefp(Instruction code, PPUThread& thread);
    static void vsel(Instruction code, PPUThread& thread);
    static void vsl(Instruction code, PPUThread& thread);
    static void vslb(Instruction code, PPUThread& thread);
    static void vsldoi(Instruction code, PPUThread& thread);
    static void vslh(Instruction code, PPUThread& thread);
    static void vslo(Instruction code, PPUThread& thread);
    static void vslw(Instruction code, PPUThread& thread);
    static void vspltb(Instruction code, PPUThread& thread);
    static void vsplth(Instruction code, PPUThread& thread);
    static void vspltisb(Instruction code, PPUThread& thread);
    static void vspltish(Instruction code, PPUThread& thread);
    static void vspltisw(Instruction code, PPUThread& thread);
    static void vspltw(Instruction code, PPUThread& thread);
    static void vsr(Instruction code, PPUThread& thread);
    static void vsrab(Instruction code, PPUThread& thread);
    static void vsrah(Instruction code, PPUThread& thread);
    static void vsraw(Instruction code, PPUThread& thread);
    static void vsrb(Instruction code, PPUThread& thread);
    static void vsrh(Instruction code, PPUThread& thread);
    static void vsro(Instruction code, PPUThread& thread);
    static void vsrw(Instruction code, PPUThread& thread);
    static void vsubcuw(Instruction code, PPUThread& thread);
    static void vsubfp(Instruction code, PPUThread& thread);
    static void vsubsbs(Instruction code, PPUThread& thread);
    static void vsubshs(Instruction code, PPUThread& thread);
    static void vsubsws(Instruction code, PPUThread& thread);
    static void vsububm(Instruction code, PPUThread& thread);
    static void vsububs(Instruction code, PPUThread& thread);
    static void vsubuhm(Instruction code, PPUThread& thread);
    static void vsubuhs(Instruction code, PPUThread& thread);
    static void vsubuwm(Instruction code, PPUThread& thread);
    static void vsubuws(Instruction code, PPUThread& thread);
    static void vsum2sws(Instruction code, PPUThread& thread);
    static void vsum4sbs(Instruction code, PPUThread& thread);
    static void vsum4shs(Instruction code, PPUThread& thread);
    static void vsum4ubs(Instruction code, PPUThread& thread);
    static void vsumsws(Instruction code, PPUThread& thread);
    static void vupkhpx(Instruction code, PPUThread& thread);
    static void vupkhsb(Instruction code, PPUThread& thread);
    static void vupkhsh(Instruction code, PPUThread& thread);
    static void vupklpx(Instruction code, PPUThread& thread);
    static void vupklsb(Instruction code, PPUThread& thread);
    static void vupklsh(Instruction code, PPUThread& thread);
    static void vxor(Instruction code, PPUThread& thread);

    // Unknown instruction
    static void unknown(Instruction code, PPUThread& thread);
    static void unknown(const char* instruction);
};

}  // namespace ppu
}  // namespace cpu
