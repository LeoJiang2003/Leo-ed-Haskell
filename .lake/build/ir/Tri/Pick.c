// Lean compiler output
// Module: Tri.Pick
// Imports: public import Init public meta import Init public import Mathlib
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
lean_object* lean_nat_add(lean_object*, lean_object*);
lean_object* l_List_lengthTR___redArg(lean_object*);
lean_object* lp_mathlib_Int_cast___at___00Int_cast___at___00Int_cast___at___00Int_cast___at___00Zsqrtd_lift___at___00GaussianInt_toComplex_spec__0_spec__0_spec__1_spec__4_spec__5(lean_object*);
lean_object* lean_nat_sub(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_tri_Pick_LatticePoint_toReal(lean_object*);
LEAN_EXPORT lean_object* lp_tri_Pick_SimplePolygon_interiorLatticePoints(lean_object*);
LEAN_EXPORT lean_object* lp_tri_Pick_SimplePolygon_interiorLatticePoints___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_tri_Pick_SimplePolygon_boundaryLatticePoints(lean_object*);
LEAN_EXPORT lean_object* lp_tri_Pick_SimplePolygon_boundaryLatticePoints___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_tri_Pick_Triangulation_numVertices___redArg(lean_object*);
LEAN_EXPORT lean_object* lp_tri_Pick_Triangulation_numVertices___redArg___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_tri_Pick_Triangulation_numVertices(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_tri_Pick_Triangulation_numVertices___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_tri_Pick_Triangulation_numFaces___redArg(lean_object*);
LEAN_EXPORT lean_object* lp_tri_Pick_Triangulation_numFaces___redArg___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_tri_Pick_Triangulation_numFaces(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_tri_Pick_Triangulation_numFaces___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_tri_Pick_Triangulation_numEdges(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_tri_Pick_Triangulation_numEdges___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_tri_Pick_Triangulation_numBoundaryEdges___redArg(lean_object*);
LEAN_EXPORT lean_object* lp_tri_Pick_Triangulation_numBoundaryEdges___redArg___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_tri_Pick_Triangulation_numBoundaryEdges(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_tri_Pick_Triangulation_numBoundaryEdges___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_tri_Pick_LatticePoint_toReal(lean_object* v_p_1_){
_start:
{
lean_object* v_fst_2_; lean_object* v_snd_3_; lean_object* v___x_5_; uint8_t v_isShared_6_; uint8_t v_isSharedCheck_12_; 
v_fst_2_ = lean_ctor_get(v_p_1_, 0);
v_snd_3_ = lean_ctor_get(v_p_1_, 1);
v_isSharedCheck_12_ = !lean_is_exclusive(v_p_1_);
if (v_isSharedCheck_12_ == 0)
{
v___x_5_ = v_p_1_;
v_isShared_6_ = v_isSharedCheck_12_;
goto v_resetjp_4_;
}
else
{
lean_inc(v_snd_3_);
lean_inc(v_fst_2_);
lean_dec(v_p_1_);
v___x_5_ = lean_box(0);
v_isShared_6_ = v_isSharedCheck_12_;
goto v_resetjp_4_;
}
v_resetjp_4_:
{
lean_object* v___x_7_; lean_object* v___x_8_; lean_object* v___x_10_; 
v___x_7_ = lp_mathlib_Int_cast___at___00Int_cast___at___00Int_cast___at___00Int_cast___at___00Zsqrtd_lift___at___00GaussianInt_toComplex_spec__0_spec__0_spec__1_spec__4_spec__5(v_fst_2_);
v___x_8_ = lp_mathlib_Int_cast___at___00Int_cast___at___00Int_cast___at___00Int_cast___at___00Zsqrtd_lift___at___00GaussianInt_toComplex_spec__0_spec__0_spec__1_spec__4_spec__5(v_snd_3_);
if (v_isShared_6_ == 0)
{
lean_ctor_set(v___x_5_, 1, v___x_8_);
lean_ctor_set(v___x_5_, 0, v___x_7_);
v___x_10_ = v___x_5_;
goto v_reusejp_9_;
}
else
{
lean_object* v_reuseFailAlloc_11_; 
v_reuseFailAlloc_11_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_11_, 0, v___x_7_);
lean_ctor_set(v_reuseFailAlloc_11_, 1, v___x_8_);
v___x_10_ = v_reuseFailAlloc_11_;
goto v_reusejp_9_;
}
v_reusejp_9_:
{
return v___x_10_;
}
}
}
}
LEAN_EXPORT lean_object* lp_tri_Pick_SimplePolygon_interiorLatticePoints(lean_object* v_P_13_){
_start:
{
lean_object* v_interiorCount_14_; 
v_interiorCount_14_ = lean_ctor_get(v_P_13_, 1);
lean_inc(v_interiorCount_14_);
return v_interiorCount_14_;
}
}
LEAN_EXPORT lean_object* lp_tri_Pick_SimplePolygon_interiorLatticePoints___boxed(lean_object* v_P_15_){
_start:
{
lean_object* v_res_16_; 
v_res_16_ = lp_tri_Pick_SimplePolygon_interiorLatticePoints(v_P_15_);
lean_dec_ref(v_P_15_);
return v_res_16_;
}
}
LEAN_EXPORT lean_object* lp_tri_Pick_SimplePolygon_boundaryLatticePoints(lean_object* v_P_17_){
_start:
{
lean_object* v_boundaryCount_18_; 
v_boundaryCount_18_ = lean_ctor_get(v_P_17_, 2);
lean_inc(v_boundaryCount_18_);
return v_boundaryCount_18_;
}
}
LEAN_EXPORT lean_object* lp_tri_Pick_SimplePolygon_boundaryLatticePoints___boxed(lean_object* v_P_19_){
_start:
{
lean_object* v_res_20_; 
v_res_20_ = lp_tri_Pick_SimplePolygon_boundaryLatticePoints(v_P_19_);
lean_dec_ref(v_P_19_);
return v_res_20_;
}
}
LEAN_EXPORT lean_object* lp_tri_Pick_Triangulation_numVertices___redArg(lean_object* v_P_21_){
_start:
{
lean_object* v_interiorCount_22_; lean_object* v_boundaryCount_23_; lean_object* v___x_24_; 
v_interiorCount_22_ = lean_ctor_get(v_P_21_, 1);
v_boundaryCount_23_ = lean_ctor_get(v_P_21_, 2);
v___x_24_ = lean_nat_add(v_interiorCount_22_, v_boundaryCount_23_);
return v___x_24_;
}
}
LEAN_EXPORT lean_object* lp_tri_Pick_Triangulation_numVertices___redArg___boxed(lean_object* v_P_25_){
_start:
{
lean_object* v_res_26_; 
v_res_26_ = lp_tri_Pick_Triangulation_numVertices___redArg(v_P_25_);
lean_dec_ref(v_P_25_);
return v_res_26_;
}
}
LEAN_EXPORT lean_object* lp_tri_Pick_Triangulation_numVertices(lean_object* v_P_27_, lean_object* v_00___U0001d4af_28_){
_start:
{
lean_object* v___x_29_; 
v___x_29_ = lp_tri_Pick_Triangulation_numVertices___redArg(v_P_27_);
return v___x_29_;
}
}
LEAN_EXPORT lean_object* lp_tri_Pick_Triangulation_numVertices___boxed(lean_object* v_P_30_, lean_object* v_00___U0001d4af_31_){
_start:
{
lean_object* v_res_32_; 
v_res_32_ = lp_tri_Pick_Triangulation_numVertices(v_P_30_, v_00___U0001d4af_31_);
lean_dec(v_00___U0001d4af_31_);
lean_dec_ref(v_P_30_);
return v_res_32_;
}
}
LEAN_EXPORT lean_object* lp_tri_Pick_Triangulation_numFaces___redArg(lean_object* v_00_U0001d4af_33_){
_start:
{
lean_object* v___x_34_; lean_object* v___x_35_; lean_object* v___x_36_; 
v___x_34_ = l_List_lengthTR___redArg(v_00_U0001d4af_33_);
v___x_35_ = lean_unsigned_to_nat(1u);
v___x_36_ = lean_nat_add(v___x_34_, v___x_35_);
lean_dec(v___x_34_);
return v___x_36_;
}
}
LEAN_EXPORT lean_object* lp_tri_Pick_Triangulation_numFaces___redArg___boxed(lean_object* v_00_U0001d4af_37_){
_start:
{
lean_object* v_res_38_; 
v_res_38_ = lp_tri_Pick_Triangulation_numFaces___redArg(v_00_U0001d4af_37_);
lean_dec(v_00_U0001d4af_37_);
return v_res_38_;
}
}
LEAN_EXPORT lean_object* lp_tri_Pick_Triangulation_numFaces(lean_object* v_P_39_, lean_object* v_00_U0001d4af_40_){
_start:
{
lean_object* v___x_41_; 
v___x_41_ = lp_tri_Pick_Triangulation_numFaces___redArg(v_00_U0001d4af_40_);
return v___x_41_;
}
}
LEAN_EXPORT lean_object* lp_tri_Pick_Triangulation_numFaces___boxed(lean_object* v_P_42_, lean_object* v_00_U0001d4af_43_){
_start:
{
lean_object* v_res_44_; 
v_res_44_ = lp_tri_Pick_Triangulation_numFaces(v_P_42_, v_00_U0001d4af_43_);
lean_dec(v_00_U0001d4af_43_);
lean_dec_ref(v_P_42_);
return v_res_44_;
}
}
LEAN_EXPORT lean_object* lp_tri_Pick_Triangulation_numEdges(lean_object* v_P_45_, lean_object* v_00_U0001d4af_46_){
_start:
{
lean_object* v___x_47_; lean_object* v___x_48_; lean_object* v___x_49_; lean_object* v___x_50_; lean_object* v___x_51_; 
v___x_47_ = lp_tri_Pick_Triangulation_numVertices___redArg(v_P_45_);
v___x_48_ = lp_tri_Pick_Triangulation_numFaces___redArg(v_00_U0001d4af_46_);
v___x_49_ = lean_nat_add(v___x_47_, v___x_48_);
lean_dec(v___x_48_);
lean_dec(v___x_47_);
v___x_50_ = lean_unsigned_to_nat(2u);
v___x_51_ = lean_nat_sub(v___x_49_, v___x_50_);
lean_dec(v___x_49_);
return v___x_51_;
}
}
LEAN_EXPORT lean_object* lp_tri_Pick_Triangulation_numEdges___boxed(lean_object* v_P_52_, lean_object* v_00_U0001d4af_53_){
_start:
{
lean_object* v_res_54_; 
v_res_54_ = lp_tri_Pick_Triangulation_numEdges(v_P_52_, v_00_U0001d4af_53_);
lean_dec(v_00_U0001d4af_53_);
lean_dec_ref(v_P_52_);
return v_res_54_;
}
}
LEAN_EXPORT lean_object* lp_tri_Pick_Triangulation_numBoundaryEdges___redArg(lean_object* v_P_55_){
_start:
{
lean_object* v_boundaryCount_56_; 
v_boundaryCount_56_ = lean_ctor_get(v_P_55_, 2);
lean_inc(v_boundaryCount_56_);
return v_boundaryCount_56_;
}
}
LEAN_EXPORT lean_object* lp_tri_Pick_Triangulation_numBoundaryEdges___redArg___boxed(lean_object* v_P_57_){
_start:
{
lean_object* v_res_58_; 
v_res_58_ = lp_tri_Pick_Triangulation_numBoundaryEdges___redArg(v_P_57_);
lean_dec_ref(v_P_57_);
return v_res_58_;
}
}
LEAN_EXPORT lean_object* lp_tri_Pick_Triangulation_numBoundaryEdges(lean_object* v_P_59_, lean_object* v_00___U0001d4af_60_){
_start:
{
lean_object* v_boundaryCount_61_; 
v_boundaryCount_61_ = lean_ctor_get(v_P_59_, 2);
lean_inc(v_boundaryCount_61_);
return v_boundaryCount_61_;
}
}
LEAN_EXPORT lean_object* lp_tri_Pick_Triangulation_numBoundaryEdges___boxed(lean_object* v_P_62_, lean_object* v_00___U0001d4af_63_){
_start:
{
lean_object* v_res_64_; 
v_res_64_ = lp_tri_Pick_Triangulation_numBoundaryEdges(v_P_62_, v_00___U0001d4af_63_);
lean_dec(v_00___U0001d4af_63_);
lean_dec_ref(v_P_62_);
return v_res_64_;
}
}
lean_object* initialize_Init(uint8_t builtin);
lean_object* initialize_Init(uint8_t builtin);
lean_object* initialize_mathlib_Mathlib(uint8_t builtin);
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
res = initialize_mathlib_Mathlib(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
return lean_io_result_mk_ok(lean_box(0));
}
#ifdef __cplusplus
}
#endif
