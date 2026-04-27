// Lean compiler output
// Module: Tri.Pick
// Imports: public import Init public meta import Init public import Mathlib.Data.Int.Basic public import Mathlib.Data.Real.Basic public import Mathlib.Data.List.GetD public import Mathlib.Data.Finset.Basic public import Mathlib.Data.Finset.Range public import Mathlib.Algebra.BigOperators.Group.Finset.Basic public import Lean.Elab.Tactic.Omega public import Mathlib.Tactic.Linarith public import Mathlib.Tactic.Push public import Mathlib.Tactic.Ring
#include <lean/lean.h>
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunused-parameter"
#pragma clang diagnostic ignored "-Wunused-label"
#elif defined(__GNUC__) && !defined(__CLANG__)
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wunused-label"
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
#endif
#ifdef __cplusplus
extern "C" {
#endif
lean_object* l_Rat_ofInt(lean_object*);
lean_object* l_List_lengthTR___redArg(lean_object*);
lean_object* lean_nat_add(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_tri_Int_cast___at___00Int_cast___at___00Int_cast___at___00Pick_LatticePoint_toReal_spec__0_spec__0_spec__1___lam__0(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_tri_Int_cast___at___00Int_cast___at___00Int_cast___at___00Pick_LatticePoint_toReal_spec__0_spec__0_spec__1___lam__0___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_tri_Int_cast___at___00Int_cast___at___00Int_cast___at___00Pick_LatticePoint_toReal_spec__0_spec__0_spec__1(lean_object*);
LEAN_EXPORT lean_object* lp_tri_Int_cast___at___00Int_cast___at___00Pick_LatticePoint_toReal_spec__0_spec__0(lean_object*);
LEAN_EXPORT lean_object* lp_tri_Int_cast___at___00Pick_LatticePoint_toReal_spec__0(lean_object*);
LEAN_EXPORT lean_object* lp_tri_Pick_LatticePoint_toReal(lean_object*);
LEAN_EXPORT lean_object* lp_tri_Int_cast___at___00Int_cast___at___00Int_cast___at___00Int_cast___at___00Pick_LatticePoint_toReal_spec__0_spec__0_spec__1_spec__2(lean_object*);
LEAN_EXPORT lean_object* lp_tri_CauSeq_const___at___00CauSeq_Completion_ofRat___at___00Real_definition_00___x40_Mathlib_Data_Real_Basic_1850581184____hygCtx___hyg_8__spec__2_spec__3___at___00Int_cast___at___00Int_cast___at___00Int_cast___at___00Pick_LatticePoint_toReal_spec__0_spec__0_spec__1_spec__4___redArg___lam__0(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_tri_CauSeq_const___at___00CauSeq_Completion_ofRat___at___00Real_definition_00___x40_Mathlib_Data_Real_Basic_1850581184____hygCtx___hyg_8__spec__2_spec__3___at___00Int_cast___at___00Int_cast___at___00Int_cast___at___00Pick_LatticePoint_toReal_spec__0_spec__0_spec__1_spec__4___redArg___lam__0___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_tri_CauSeq_const___at___00CauSeq_Completion_ofRat___at___00Real_definition_00___x40_Mathlib_Data_Real_Basic_1850581184____hygCtx___hyg_8__spec__2_spec__3___at___00Int_cast___at___00Int_cast___at___00Int_cast___at___00Pick_LatticePoint_toReal_spec__0_spec__0_spec__1_spec__4___redArg(lean_object*);
LEAN_EXPORT lean_object* lp_tri_CauSeq_const___at___00CauSeq_Completion_ofRat___at___00Real_definition_00___x40_Mathlib_Data_Real_Basic_1850581184____hygCtx___hyg_8__spec__2_spec__3___at___00Int_cast___at___00Int_cast___at___00Int_cast___at___00Pick_LatticePoint_toReal_spec__0_spec__0_spec__1_spec__4(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_tri_Pick_Triangulation_numFaces___redArg(lean_object*);
LEAN_EXPORT lean_object* lp_tri_Pick_Triangulation_numFaces___redArg___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_tri_Pick_Triangulation_numFaces(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_tri_Pick_Triangulation_numFaces___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_tri_Int_cast___at___00Int_cast___at___00Int_cast___at___00Pick_LatticePoint_toReal_spec__0_spec__0_spec__1___lam__0(lean_object* v___x_1_, lean_object* v_x_2_){
_start:
{
lean_inc_ref(v___x_1_);
return v___x_1_;
}
}
LEAN_EXPORT lean_object* lp_tri_Int_cast___at___00Int_cast___at___00Int_cast___at___00Pick_LatticePoint_toReal_spec__0_spec__0_spec__1___lam__0___boxed(lean_object* v___x_3_, lean_object* v_x_4_){
_start:
{
lean_object* v_res_5_; 
v_res_5_ = lp_tri_Int_cast___at___00Int_cast___at___00Int_cast___at___00Pick_LatticePoint_toReal_spec__0_spec__0_spec__1___lam__0(v___x_3_, v_x_4_);
lean_dec(v_x_4_);
lean_dec_ref(v___x_3_);
return v_res_5_;
}
}
LEAN_EXPORT lean_object* lp_tri_Int_cast___at___00Int_cast___at___00Int_cast___at___00Pick_LatticePoint_toReal_spec__0_spec__0_spec__1(lean_object* v_a_6_){
_start:
{
lean_object* v___x_7_; lean_object* v___f_8_; 
v___x_7_ = l_Rat_ofInt(v_a_6_);
v___f_8_ = lean_alloc_closure((void*)(lp_tri_Int_cast___at___00Int_cast___at___00Int_cast___at___00Pick_LatticePoint_toReal_spec__0_spec__0_spec__1___lam__0___boxed), 2, 1);
lean_closure_set(v___f_8_, 0, v___x_7_);
return v___f_8_;
}
}
LEAN_EXPORT lean_object* lp_tri_Int_cast___at___00Int_cast___at___00Pick_LatticePoint_toReal_spec__0_spec__0(lean_object* v_a_9_){
_start:
{
lean_object* v___x_10_; 
v___x_10_ = lp_tri_Int_cast___at___00Int_cast___at___00Int_cast___at___00Pick_LatticePoint_toReal_spec__0_spec__0_spec__1(v_a_9_);
return v___x_10_;
}
}
LEAN_EXPORT lean_object* lp_tri_Int_cast___at___00Pick_LatticePoint_toReal_spec__0(lean_object* v_a_11_){
_start:
{
lean_object* v___x_12_; 
v___x_12_ = lp_tri_Int_cast___at___00Int_cast___at___00Int_cast___at___00Pick_LatticePoint_toReal_spec__0_spec__0_spec__1(v_a_11_);
return v___x_12_;
}
}
LEAN_EXPORT lean_object* lp_tri_Pick_LatticePoint_toReal(lean_object* v_p_13_){
_start:
{
lean_object* v_fst_14_; lean_object* v_snd_15_; lean_object* v___x_17_; uint8_t v_isShared_18_; uint8_t v_isSharedCheck_24_; 
v_fst_14_ = lean_ctor_get(v_p_13_, 0);
v_snd_15_ = lean_ctor_get(v_p_13_, 1);
v_isSharedCheck_24_ = !lean_is_exclusive(v_p_13_);
if (v_isSharedCheck_24_ == 0)
{
v___x_17_ = v_p_13_;
v_isShared_18_ = v_isSharedCheck_24_;
goto v_resetjp_16_;
}
else
{
lean_inc(v_snd_15_);
lean_inc(v_fst_14_);
lean_dec(v_p_13_);
v___x_17_ = lean_box(0);
v_isShared_18_ = v_isSharedCheck_24_;
goto v_resetjp_16_;
}
v_resetjp_16_:
{
lean_object* v___x_19_; lean_object* v___x_20_; lean_object* v___x_22_; 
v___x_19_ = lp_tri_Int_cast___at___00Int_cast___at___00Int_cast___at___00Pick_LatticePoint_toReal_spec__0_spec__0_spec__1(v_fst_14_);
v___x_20_ = lp_tri_Int_cast___at___00Int_cast___at___00Int_cast___at___00Pick_LatticePoint_toReal_spec__0_spec__0_spec__1(v_snd_15_);
if (v_isShared_18_ == 0)
{
lean_ctor_set(v___x_17_, 1, v___x_20_);
lean_ctor_set(v___x_17_, 0, v___x_19_);
v___x_22_ = v___x_17_;
goto v_reusejp_21_;
}
else
{
lean_object* v_reuseFailAlloc_23_; 
v_reuseFailAlloc_23_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_23_, 0, v___x_19_);
lean_ctor_set(v_reuseFailAlloc_23_, 1, v___x_20_);
v___x_22_ = v_reuseFailAlloc_23_;
goto v_reusejp_21_;
}
v_reusejp_21_:
{
return v___x_22_;
}
}
}
}
LEAN_EXPORT lean_object* lp_tri_Int_cast___at___00Int_cast___at___00Int_cast___at___00Int_cast___at___00Pick_LatticePoint_toReal_spec__0_spec__0_spec__1_spec__2(lean_object* v_a_25_){
_start:
{
lean_object* v___x_26_; 
v___x_26_ = l_Rat_ofInt(v_a_25_);
return v___x_26_;
}
}
LEAN_EXPORT lean_object* lp_tri_CauSeq_const___at___00CauSeq_Completion_ofRat___at___00Real_definition_00___x40_Mathlib_Data_Real_Basic_1850581184____hygCtx___hyg_8__spec__2_spec__3___at___00Int_cast___at___00Int_cast___at___00Int_cast___at___00Pick_LatticePoint_toReal_spec__0_spec__0_spec__1_spec__4___redArg___lam__0(lean_object* v_x_27_, lean_object* v_x_28_){
_start:
{
lean_inc_ref(v_x_27_);
return v_x_27_;
}
}
LEAN_EXPORT lean_object* lp_tri_CauSeq_const___at___00CauSeq_Completion_ofRat___at___00Real_definition_00___x40_Mathlib_Data_Real_Basic_1850581184____hygCtx___hyg_8__spec__2_spec__3___at___00Int_cast___at___00Int_cast___at___00Int_cast___at___00Pick_LatticePoint_toReal_spec__0_spec__0_spec__1_spec__4___redArg___lam__0___boxed(lean_object* v_x_29_, lean_object* v_x_30_){
_start:
{
lean_object* v_res_31_; 
v_res_31_ = lp_tri_CauSeq_const___at___00CauSeq_Completion_ofRat___at___00Real_definition_00___x40_Mathlib_Data_Real_Basic_1850581184____hygCtx___hyg_8__spec__2_spec__3___at___00Int_cast___at___00Int_cast___at___00Int_cast___at___00Pick_LatticePoint_toReal_spec__0_spec__0_spec__1_spec__4___redArg___lam__0(v_x_29_, v_x_30_);
lean_dec(v_x_30_);
lean_dec_ref(v_x_29_);
return v_res_31_;
}
}
LEAN_EXPORT lean_object* lp_tri_CauSeq_const___at___00CauSeq_Completion_ofRat___at___00Real_definition_00___x40_Mathlib_Data_Real_Basic_1850581184____hygCtx___hyg_8__spec__2_spec__3___at___00Int_cast___at___00Int_cast___at___00Int_cast___at___00Pick_LatticePoint_toReal_spec__0_spec__0_spec__1_spec__4___redArg(lean_object* v_x_32_){
_start:
{
lean_object* v___f_33_; 
v___f_33_ = lean_alloc_closure((void*)(lp_tri_CauSeq_const___at___00CauSeq_Completion_ofRat___at___00Real_definition_00___x40_Mathlib_Data_Real_Basic_1850581184____hygCtx___hyg_8__spec__2_spec__3___at___00Int_cast___at___00Int_cast___at___00Int_cast___at___00Pick_LatticePoint_toReal_spec__0_spec__0_spec__1_spec__4___redArg___lam__0___boxed), 2, 1);
lean_closure_set(v___f_33_, 0, v_x_32_);
return v___f_33_;
}
}
LEAN_EXPORT lean_object* lp_tri_CauSeq_const___at___00CauSeq_Completion_ofRat___at___00Real_definition_00___x40_Mathlib_Data_Real_Basic_1850581184____hygCtx___hyg_8__spec__2_spec__3___at___00Int_cast___at___00Int_cast___at___00Int_cast___at___00Pick_LatticePoint_toReal_spec__0_spec__0_spec__1_spec__4(lean_object* v_inst_34_, lean_object* v_inst_35_, lean_object* v_x_36_){
_start:
{
lean_object* v___f_37_; 
v___f_37_ = lean_alloc_closure((void*)(lp_tri_CauSeq_const___at___00CauSeq_Completion_ofRat___at___00Real_definition_00___x40_Mathlib_Data_Real_Basic_1850581184____hygCtx___hyg_8__spec__2_spec__3___at___00Int_cast___at___00Int_cast___at___00Int_cast___at___00Pick_LatticePoint_toReal_spec__0_spec__0_spec__1_spec__4___redArg___lam__0___boxed), 2, 1);
lean_closure_set(v___f_37_, 0, v_x_36_);
return v___f_37_;
}
}
LEAN_EXPORT lean_object* lp_tri_Pick_Triangulation_numFaces___redArg(lean_object* v_00_U0001d4af_38_){
_start:
{
lean_object* v___x_39_; lean_object* v___x_40_; lean_object* v___x_41_; 
v___x_39_ = l_List_lengthTR___redArg(v_00_U0001d4af_38_);
v___x_40_ = lean_unsigned_to_nat(1u);
v___x_41_ = lean_nat_add(v___x_39_, v___x_40_);
lean_dec(v___x_39_);
return v___x_41_;
}
}
LEAN_EXPORT lean_object* lp_tri_Pick_Triangulation_numFaces___redArg___boxed(lean_object* v_00_U0001d4af_42_){
_start:
{
lean_object* v_res_43_; 
v_res_43_ = lp_tri_Pick_Triangulation_numFaces___redArg(v_00_U0001d4af_42_);
lean_dec(v_00_U0001d4af_42_);
return v_res_43_;
}
}
LEAN_EXPORT lean_object* lp_tri_Pick_Triangulation_numFaces(lean_object* v_P_44_, lean_object* v_00_U0001d4af_45_){
_start:
{
lean_object* v___x_46_; 
v___x_46_ = lp_tri_Pick_Triangulation_numFaces___redArg(v_00_U0001d4af_45_);
return v___x_46_;
}
}
LEAN_EXPORT lean_object* lp_tri_Pick_Triangulation_numFaces___boxed(lean_object* v_P_47_, lean_object* v_00_U0001d4af_48_){
_start:
{
lean_object* v_res_49_; 
v_res_49_ = lp_tri_Pick_Triangulation_numFaces(v_P_47_, v_00_U0001d4af_48_);
lean_dec(v_00_U0001d4af_48_);
lean_dec(v_P_47_);
return v_res_49_;
}
}
lean_object* initialize_Init(uint8_t builtin);
lean_object* initialize_Init(uint8_t builtin);
lean_object* initialize_mathlib_Mathlib_Data_Int_Basic(uint8_t builtin);
lean_object* initialize_mathlib_Mathlib_Data_Real_Basic(uint8_t builtin);
lean_object* initialize_mathlib_Mathlib_Data_List_GetD(uint8_t builtin);
lean_object* initialize_mathlib_Mathlib_Data_Finset_Basic(uint8_t builtin);
lean_object* initialize_mathlib_Mathlib_Data_Finset_Range(uint8_t builtin);
lean_object* initialize_mathlib_Mathlib_Algebra_BigOperators_Group_Finset_Basic(uint8_t builtin);
lean_object* initialize_Lean_Elab_Tactic_Omega(uint8_t builtin);
lean_object* initialize_mathlib_Mathlib_Tactic_Linarith(uint8_t builtin);
lean_object* initialize_mathlib_Mathlib_Tactic_Push(uint8_t builtin);
lean_object* initialize_mathlib_Mathlib_Tactic_Ring(uint8_t builtin);
static bool _G_initialized = false;
LEAN_EXPORT lean_object* initialize_tri_Tri_Pick(uint8_t builtin) {
lean_object * res;
if (_G_initialized) return lean_io_result_mk_ok(lean_box(0));
_G_initialized = true;
res = initialize_Init(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_Init(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_mathlib_Mathlib_Data_Int_Basic(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_mathlib_Mathlib_Data_Real_Basic(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_mathlib_Mathlib_Data_List_GetD(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_mathlib_Mathlib_Data_Finset_Basic(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_mathlib_Mathlib_Data_Finset_Range(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_mathlib_Mathlib_Algebra_BigOperators_Group_Finset_Basic(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_Lean_Elab_Tactic_Omega(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_mathlib_Mathlib_Tactic_Linarith(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_mathlib_Mathlib_Tactic_Push(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_mathlib_Mathlib_Tactic_Ring(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
return lean_io_result_mk_ok(lean_box(0));
}
#ifdef __cplusplus
}
#endif
