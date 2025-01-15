#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "num.c"
#include <string.h>
#define _NCp1_Chash_table_size (64)
#define _NCp1_NFunc_Cnil (-1)
#define _NCp1_NBasicTypeId_Croot 0
#define _NCp1_NBasicTypeId_Crelative (_NCp1_NBasicTypeId_Croot + 1)
#define _NCp1_NBasicTypeId_Cref (_NCp1_NBasicTypeId_Crelative + 1)
#define _NCp1_NBasicTypeId_Cbool (_NCp1_NBasicTypeId_Cref + 1)
#define _NCp1_NBasicTypeId_Cchar (_NCp1_NBasicTypeId_Cbool + 1)
#define _NCp1_NBasicTypeId_Cintc (_NCp1_NBasicTypeId_Cchar + 1)
#define _NCp1_NBasicTypeId_Ci8 (_NCp1_NBasicTypeId_Cintc + 1)
#define _NCp1_NBasicTypeId_Cu8 (_NCp1_NBasicTypeId_Ci8 + 1)
#define _NCp1_NBasicTypeId_Ci16 (_NCp1_NBasicTypeId_Cu8 + 1)
#define _NCp1_NBasicTypeId_Cu16 (_NCp1_NBasicTypeId_Ci16 + 1)
#define _NCp1_NBasicTypeId_Ci32 (_NCp1_NBasicTypeId_Cu16 + 1)
#define _NCp1_NBasicTypeId_Cu32 (_NCp1_NBasicTypeId_Ci32 + 1)
#define _NCp1_NBasicTypeId_Ci64 (_NCp1_NBasicTypeId_Cu32 + 1)
#define _NCp1_NBasicTypeId_Cu64 (_NCp1_NBasicTypeId_Ci64 + 1)
#define _NCp1_NBasicTypeId_Cisz (_NCp1_NBasicTypeId_Cu64 + 1)
#define _NCp1_NBasicTypeId_Cusz (_NCp1_NBasicTypeId_Cisz + 1)
#define _NCp1_NBasicTypeId_Cf32 (_NCp1_NBasicTypeId_Cusz + 1)
#define _NCp1_NBasicTypeId_Cf64 (_NCp1_NBasicTypeId_Cf32 + 1)
#define _NCp1_NBasicTypeId_CCOUNT (_NCp1_NBasicTypeId_Cf64 + 1)
#define _NCp1_NNameType_Cmodule 0
#define _NCp1_NNameType_Cstruct_enum (_NCp1_NNameType_Cmodule + 1)
#define _NCp1_NNameType_Cbasic (_NCp1_NNameType_Cstruct_enum + 1)
#define _NCp1_NAt_Cnil (-1)
#define _NCp1_NAt_Croot (_NCp1_NAt_Cnil + 1)
#define _NCp1_Ctype_info_star_limit (8)
#define _NCp1_Cexpr_carg_group_limit (4)
#define _NCp1_NEnum_Cnil (-1)
#define _NStdc_NExit_Csuccess 0
#define _NStdc_NExit_Cfailure (_NStdc_NExit_Csuccess + 1)
#define _NCp1_NAtDef_Cundefined 0
#define _NCp1_NAtDef_Cmodule (_NCp1_NAtDef_Cundefined + 1)
#define _NCp1_NAtDef_Cstruct (_NCp1_NAtDef_Cmodule + 1)
#define _NCp1_NAtDef_Cenum (_NCp1_NAtDef_Cstruct + 1)
#define _NCp1_NFuncFlags_Creal_name (64)
#define _NCp1_NFuncFlags_Cno_decl (16)
#define _NCp1_NFuncFlags_C0 0
#define _NCp1_NFuncFlags_Cdecl (512)
#define _NCp1_NInclude_Cnil (-1)
#define _NCp1_NFuncFlags_Ccp1_name (256)
#define _NCp1_NCvarFlags_Cas_enum (2)
#define _NCp1_NCvarFlags_C0 0
#define _NCp1_NVarFlags_Cno_decl (4)
#define _NCp1_NVarFlags_C0 0
#define _NCp1_NCvarFlags_Cset_expr (1)
#define _NCp1_NCvar_Cnil (-1)
#define _NCp1_NStructFlags_Cunion (4)
#define _NCp1_NStructFlags_C0 0
#define _NCp1_NDeclVarType_Cgvar 0
#define _NCp1_NDeclVarType_Cfvar (_NCp1_NDeclVarType_Cgvar + 1)
#define _NCp1_NVarFlags_Cextern (2)
#define _NCp1_NFuncFlags_Cinline (2)
#define _NCp1_NStruct_Cnil (-1)
#define _NCp1_NEnumFlags_Creal_name (1)
#define _NCp1_NEnumFlags_C0 0
#define _NCp1_NId_Cnil (-1)
#define _NCp1_NStructFlags_Creal_name (1)
#define _NCp1_NLvar_Cnil (-1)
#define _NCp1_NLvar_C0 (_NCp1_NLvar_Cnil + 1)
#define _NCp1_NFuncFlags_Ccase (128)
#define _NCp1_NFuncFlags_Chas_body (1)
#define _NCp1_NFuncFlags_Cno_body (32)
#define _NCp1_NLvarFlags_Cprocessed (2)
#define _NCp1_NLvarFlags_C0 0
#define _NCp1_NLvarFlags_Cset_expr (1)
#define _NCp1_NVarFlags_Creal_name (1)
#define _NCp1_NExprType_Cnil 0
#define _NCp1_NExprType_Ccall_method (_NCp1_NExprType_Cnil + 1)
#define _NCp1_NExprType_Clvar (_NCp1_NExprType_Ccall_method + 1)
#define _NCp1_NExprType_Cgvar (_NCp1_NExprType_Clvar + 1)
#define _NCp1_NExprType_Cmath (_NCp1_NExprType_Cgvar + 1)
#define _NCp1_NExprType_Cassign (_NCp1_NExprType_Cmath + 1)
#define _NCp1_NExprType_Cbools (_NCp1_NExprType_Cassign + 1)
#define _NCp1_NExprType_Cfunc (_NCp1_NExprType_Cbools + 1)
#define _NCp1_NExprType_Cmethod (_NCp1_NExprType_Cfunc + 1)
#define _NCp1_NExprType_Cfvar (_NCp1_NExprType_Cmethod + 1)
#define _NCp1_NExprType_Ci32 (_NCp1_NExprType_Cfvar + 1)
#define _NCp1_NExprType_Ccvar (_NCp1_NExprType_Ci32 + 1)
#define _NCp1_NExprType_Cstr (_NCp1_NExprType_Ccvar + 1)
#define _NCp1_NExprType_Cindex (_NCp1_NExprType_Cstr + 1)
#define _NCp1_NExprType_Cunary (_NCp1_NExprType_Cindex + 1)
#define _NCp1_NExprType_Ccompare (_NCp1_NExprType_Cunary + 1)
#define _NCp1_NExprType_Cbool (_NCp1_NExprType_Ccompare + 1)
#define _NCp1_NExprType_Cnull (_NCp1_NExprType_Cbool + 1)
#define _NCp1_NExprType_Ccast_fast (_NCp1_NExprType_Cnull + 1)
#define _NCp1_NExprType_Cref (_NCp1_NExprType_Ccast_fast + 1)
#define _NCp1_NExprType_Cchar (_NCp1_NExprType_Cref + 1)
#define _NCp1_NExprType_Csize_of_type (_NCp1_NExprType_Cchar + 1)
#define _NCp1_Cdebug_rd_wr (true)
#define _NCp1_NExprI_Cnil (-1)
#define _NCp1_NFunc_C0 (_NCp1_NFunc_Cnil + 1)
#define _NCp1_NFunc_C1 (_NCp1_NFunc_C0 + 1)
#define _NCp1_NStmtType_Cnil (255)
#define _NCp1_NStmtType_Cspace 0
#define _NCp1_NStmtType_Cif (_NCp1_NStmtType_Cspace + 1)
#define _NCp1_NStmtType_Cif_elif (_NCp1_NStmtType_Cif + 1)
#define _NCp1_NStmtType_Cif_else (_NCp1_NStmtType_Cif_elif + 1)
#define _NCp1_NStmtType_Cif_end (_NCp1_NStmtType_Cif_else + 1)
#define _NCp1_NStmtType_Cdo (_NCp1_NStmtType_Cif_end + 1)
#define _NCp1_NStmtType_Cdo_end (_NCp1_NStmtType_Cdo + 1)
#define _NCp1_NStmtType_Cwhile (_NCp1_NStmtType_Cdo_end + 1)
#define _NCp1_NStmtType_Cwhile_end (_NCp1_NStmtType_Cwhile + 1)
#define _NCp1_NStmtType_Cexpr (_NCp1_NStmtType_Cwhile_end + 1)
#define _NCp1_NStmtType_Creturn (_NCp1_NStmtType_Cexpr + 1)
#define _NCp1_NStmtType_Ccontinue (_NCp1_NStmtType_Creturn + 1)
#define _NCp1_NStmtType_Cbreak (_NCp1_NStmtType_Ccontinue + 1)
#define _NCp1_NStmtType_Cswitch (_NCp1_NStmtType_Cbreak + 1)
#define _NCp1_NStmtType_Ccase (_NCp1_NStmtType_Cswitch + 1)
#define _NCp1_NStmtType_Cdefault (_NCp1_NStmtType_Ccase + 1)
#define _NCp1_NStmtType_Ccase_end (_NCp1_NStmtType_Cdefault + 1)
#define _NCp1_NStmtType_Cdefault_end (_NCp1_NStmtType_Ccase_end + 1)
#define _NCp1_NStmtType_Cswitch_end (_NCp1_NStmtType_Cdefault_end + 1)
#define _NCp1_NStructFlags_Cno_decl (2)
#define _NCp1_NExprI_C0 (_NCp1_NExprI_Cnil + 1)
#define _NCp1_NAssign_Ceq 0
#define _NCp1_NAssign_Cplus_eq (_NCp1_NAssign_Ceq + 1)
#define _NCp1_NAssign_Cminus_eq (_NCp1_NAssign_Cplus_eq + 1)
#define _NCp1_NAssign_Cmul_eq (_NCp1_NAssign_Cminus_eq + 1)
#define _NCp1_NAssign_Cdiv_eq (_NCp1_NAssign_Cmul_eq + 1)
#define _NCp1_NAssign_Clshift_eq (_NCp1_NAssign_Cdiv_eq + 1)
#define _NCp1_NAssign_Crshift_eq (_NCp1_NAssign_Clshift_eq + 1)
#define _NCp1_NAssign_Cand_eq (_NCp1_NAssign_Crshift_eq + 1)
#define _NCp1_NAssign_Cor_eq (_NCp1_NAssign_Cand_eq + 1)
#define _NCp1_NAssign_Cxor_eq (_NCp1_NAssign_Cor_eq + 1)
#define _NCp1_NCompare_Ceq 0
#define _NCp1_NCompare_Cnot_eq (_NCp1_NCompare_Ceq + 1)
#define _NCp1_NCompare_Clt (_NCp1_NCompare_Cnot_eq + 1)
#define _NCp1_NCompare_Cle (_NCp1_NCompare_Clt + 1)
#define _NCp1_NCompare_Cgt (_NCp1_NCompare_Cle + 1)
#define _NCp1_NCompare_Cge (_NCp1_NCompare_Cgt + 1)
#define _NCp1_NMath_Cadd 0
#define _NCp1_NMath_Csub (_NCp1_NMath_Cadd + 1)
#define _NCp1_NMath_Cmul (_NCp1_NMath_Csub + 1)
#define _NCp1_NMath_Cdiv (_NCp1_NMath_Cmul + 1)
#define _NCp1_NMath_Clshift (_NCp1_NMath_Cdiv + 1)
#define _NCp1_NMath_Crshift (_NCp1_NMath_Clshift + 1)
#define _NCp1_NMath_Cand (_NCp1_NMath_Crshift + 1)
#define _NCp1_NMath_Cor (_NCp1_NMath_Cand + 1)
#define _NCp1_NMath_Cxor (_NCp1_NMath_Cor + 1)
#define _NCp1_NUnary_Cneg 0
#define _NCp1_NUnary_Cinc (_NCp1_NUnary_Cneg + 1)
#define _NCp1_NUnary_Cdec (_NCp1_NUnary_Cinc + 1)
#define _NCp1_NUnary_Cnot (_NCp1_NUnary_Cdec + 1)
#define _NCp1_NBools_Cand 0
#define _NCp1_NBools_Cor (_NCp1_NBools_Cand + 1)
#define _NCp1_NFuncFlags_Cvar_args (8)
#define _NCp1_NGvarFlags_Cno_decl (1)
#define _NCp1_NGvarFlags_C0 0
typedef int32_t _NCp1_NFunc;
typedef uint8_t _NCp1_NBasicTypeId;
typedef int32_t _NCp1_NAt;
typedef uint8_t _NCp1_NNameType;
typedef int32_t _NCp1_NId;
typedef int32_t _NCp1_NGvar;
typedef int32_t _NCp1_NCvar;
typedef int32_t _NCp1_NStruct;
typedef int32_t _NCp1_NEnum;
typedef uint8_t _NCp1_NAtDef;
typedef int32_t _NCp1_NFile;
typedef int32_t _NCp1_NInclude;
typedef uint32_t _NCp1_NFuncFlags;
typedef uint32_t _NCp1_NVarFlags;
typedef int32_t _NCp1_NExprI;
typedef uint8_t _NCp1_NStmtType;
typedef uint8_t _NCp1_NStmtSpaceFlags;
typedef int32_t _NCp1_NLvar;
typedef uint8_t _NCp1_NLvarFlags;
typedef int _NStdc_NExit;
typedef uint8_t _NCp1_NStructFlags;
typedef uint8_t _NCp1_NEnumFlags;
typedef uint8_t _NCp1_NCvarFlags;
typedef uint8_t _NCp1_NDeclVarType;
typedef uint8_t _NCp1_NGvarFlags;
typedef int _NStdc_NFd;
typedef int _NStdc_NOpenFlags;
typedef int _NStdc_NSeek;
typedef uint8_t _NCp1_NExprType;
typedef uint8_t _NCp1_NExprFlags;
typedef uint8_t _NCp1_NAssign;
typedef uint8_t _NCp1_NCompare;
typedef uint8_t _NCp1_NMath;
typedef uint8_t _NCp1_NUnary;
typedef int32_t _NCp1_NFvar;
typedef uint8_t _NCp1_NBools;
typedef uint8_t _NCp1_NExprInt;
struct _NCp1_NMap;
struct _NCp1_NMap {
uint64_t _Fdata[(_NCp1_Chash_table_size + 7) >> 3];
};
struct _NCp1_NAtMap;
struct _NCp1_NAtMap {
uint64_t _Fdata[(_NCp1_Chash_table_size + 7) >> 3];
};
union _NCp1_NAtName;
union _NCp1_NAtName {
_NCp1_NId _Fid;
_NCp1_NBasicTypeId _Fbasic;
};
union _NCp1_NAtType;
union _NCp1_NAtType {
_NCp1_NStruct _Fstruct;
_NCp1_NEnum _Fenum;
};
struct _NCp1_NAtData;
struct _NCp1_NAtData {
_NCp1_NNameType _Ftype;
_NCp1_NAt _Fparent;
union _NCp1_NAtName _Fname;
int32_t _Ffunc_c;
int32_t _Ffunc_cap;
_NCp1_NFunc* _Ffunc_v;
int32_t _Fgvar_c;
int32_t _Fgvar_cap;
_NCp1_NGvar* _Fgvar_v;
int32_t _Fcvar_c;
int32_t _Fcvar_cap;
_NCp1_NCvar* _Fcvar_v;
union _NCp1_NAtType _Fdecl;
_NCp1_NAtDef _Fdef;
};
struct _NCp1_NTypeInfo;
struct _NCp1_NTypeInfo {
int8_t _Fref_v[_NCp1_Ctype_info_star_limit];
int8_t _Farray_c;
int8_t _Fstar_c;
bool _Fbuilt_in;
bool _Fconst;
};
struct _NCp1_NValue;
struct _NCp1_NValue {
int8_t _Freff;
bool _Fparen;
_NCp1_NAt _Ftype;
struct _NCp1_NTypeInfo _Finfo;
};
struct _NCp1_NDeclVarData;
struct _NCp1_NDeclVarData {
_NCp1_NId _Fname;
_NCp1_NAt _Ftype;
_NCp1_NVarFlags _Fflags;
_NCp1_NId _Freal_name;
struct _NCp1_NTypeInfo _Ftype_info;
uint8_t _Fsize_c;
_NCp1_NExprI* _Fsize_expr_v;
struct _NCp1_NValue* _Fsize_value_v;
};
struct _NCp1_NStmt;
struct _NCp1_NStmt {
int32_t _Fbegin_row;
int32_t _Fbegin_col;
int32_t _Fend_row;
int32_t _Fend_col;
_NCp1_NStmtType _Ftype;
struct _NCp1_NStmt* _Fstmt_next;
};
struct _NCp1_NStmtSpace;
struct _NCp1_NStmtSpace {
struct _NCp1_NStmt _Fbase;
struct _NCp1_NStmtSpace* _Fparent;
_NCp1_NStmtSpaceFlags _Fflags;
struct _NCp1_NStmt* _Fstmt_first;
struct _NCp1_NStmt* _Fstmt_last;
int32_t _Flvar_c;
int32_t _Flvar_cap;
_NCp1_NLvar* _Flvar_v;
};
struct _NCp1_NLvarData;
struct _NCp1_NLvarData {
int32_t _Frow;
int32_t _Fcol;
struct _NCp1_NDeclVarData _Fdecl;
_NCp1_NLvarFlags _Fflags;
_NCp1_NExprI _Fset_expr;
};
struct _NCp1_NFarg;
struct _NCp1_NFarg {
int32_t _Frow;
int32_t _Fcol;
struct _NCp1_NDeclVarData _Fdecl;
};
struct _NCp1_NDeclFunc;
struct _NCp1_NDeclFunc {
_NCp1_NFunc _Fprocess_next;
_NCp1_NFile _Ffile;
int32_t _Fbegin_row;
int32_t _Fbegin_col;
int32_t _Fend_row;
int32_t _Fend_col;
_NCp1_NInclude _Finclude;
_NCp1_NAt _Fat;
_NCp1_NFuncFlags _Fflags;
_NCp1_NId _Freal_name;
char* _Fdecl_str;
int32_t _Fdecl_len;
_NCp1_NId _Fcas;
struct _NCp1_NDeclVarData _Fdecl;
struct _NCp1_NStmtSpace _Fstmt_space;
_NCp1_NLvar _Flvar_c;
struct _NCp1_NLvarData* _Flvar_v;
uint32_t _Fbody_file_pos;
int8_t _Fthis_idx;
int8_t _Fthis_group;
int8_t _Fgroup_c;
int8_t _Fgroup_v[_NCp1_Cexpr_carg_group_limit];
uint8_t _Ffarg_c;
struct _NCp1_NFarg _Ffarg_v[0];
};
struct _NCp1_NFvarData;
struct _NCp1_NFvarData {
struct _NCp1_NDeclVarData _Fdecl;
};
struct _NCp1_NStructData;
struct _NCp1_NStructData {
_NCp1_NFile _Ffile;
int32_t _Fbegin_row;
int32_t _Fbegin_col;
int32_t _Fend_row;
int32_t _Fend_col;
_NCp1_NInclude _Finclude;
_NCp1_NAt _Fat;
_NCp1_NStructFlags _Fflags;
_NCp1_NId _Freal_name;
int32_t _Fmethod_c;
int32_t _Fmethod_cap;
_NCp1_NFunc* _Fmethod_v;
uint32_t _Ffvar_c;
struct _NCp1_NFvarData _Ffvar_v[0];
};
struct _NCp1_NEnumData;
struct _NCp1_NEnumData {
_NCp1_NFile _Ffile;
int32_t _Fbegin_row;
int32_t _Fbegin_col;
int32_t _Fend_row;
int32_t _Fend_col;
_NCp1_NInclude _Finclude;
_NCp1_NAt _Fat;
_NCp1_NAt _Fbase_type;
_NCp1_NEnumFlags _Fflags;
_NCp1_NId _Freal_name;
int32_t _Fmethod_c;
int32_t _Fmethod_cap;
_NCp1_NFunc* _Fmethod_v;
};
struct _NCp1_NBasicType;
struct _NCp1_NBasicType {
int32_t _Fmethod_c;
int32_t _Fmethod_cap;
_NCp1_NFunc* _Fmethod_v;
};
struct _NCp1_NCvarData;
struct _NCp1_NCvarData {
_NCp1_NFile _Ffile;
int32_t _Frow;
int32_t _Fcol;
_NCp1_NInclude _Finclude;
_NCp1_NAt _Fat;
_NCp1_NCvarFlags _Fflags;
struct _NCp1_NDeclVarData _Fdecl;
_NCp1_NExprI _Fexpr_set;
_NCp1_NCvar _Flast_cvar;
};
struct _NCp1_NDeclGvar;
struct _NCp1_NDeclGvar {
_NCp1_NFile _Ffile;
int32_t _Frow;
int32_t _Fcol;
_NCp1_NInclude _Finclude;
_NCp1_NAt _Fat;
_NCp1_NGvarFlags _Fflags;
struct _NCp1_NDeclVarData _Fdecl;
};
union _NCp1_NRdr;
union _NCp1_NRdr {
void* _Freff;
size_t _Fpos;
uint8_t* _Fp1;
char* _Fcharr;
uint32_t* _Fp4;
};
struct _NCp1_NFileData;
struct _NCp1_NFileData {
char* _Fpath;
void* _Fdata;
_NCp1_NId* _Fid_table;
_NCp1_NAt* _Fat_table;
_NCp1_NCvar* _Fcvar_table;
};
struct _NCp1_NExpr;
struct _NCp1_NExpr {
_NCp1_NExprType _Ftype;
_NCp1_NExprFlags _Fflags;
};
struct _NCp1_NExprAssign;
struct _NCp1_NExprAssign {
struct _NCp1_NExpr _Fbase;
_NCp1_NExprI _Fleft;
_NCp1_NExprI _Fright;
_NCp1_NAssign _Ftype;
struct _NCp1_NValue _Fleft_val;
struct _NCp1_NValue _Fright_val;
};
struct _NCp1_NExprCompare;
struct _NCp1_NExprCompare {
struct _NCp1_NExpr _Fbase;
_NCp1_NExprI _Fleft;
_NCp1_NExprI _Fright;
_NCp1_NCompare _Ftype;
struct _NCp1_NValue _Fleft_val;
struct _NCp1_NValue _Fright_val;
};
struct _NCp1_NExprBool;
struct _NCp1_NExprBool {
struct _NCp1_NExpr _Fbase;
bool _Fvalue;
};
struct _NCp1_NExprChar;
struct _NCp1_NExprChar {
struct _NCp1_NExpr _Fbase;
char _Fvalue;
};
struct _NCp1_NExprMathItem;
struct _NCp1_NExprMathItem {
_NCp1_NExprI _Fexpr;
struct _NCp1_NValue _Fval;
};
struct _NCp1_NExprMath;
struct _NCp1_NExprMath {
struct _NCp1_NExpr _Fbase;
_NCp1_NExprI _Fleft;
_NCp1_NExprI _Fright;
_NCp1_NMath _Ftype;
struct _NCp1_NValue _Fleft_val;
struct _NCp1_NValue _Fright_val;
uint8_t _Fitem_c;
struct _NCp1_NExprMathItem* _Fitem_v;
};
struct _NCp1_NExprUnary;
struct _NCp1_NExprUnary {
struct _NCp1_NExpr _Fbase;
_NCp1_NExprI _Fexpr;
_NCp1_NUnary _Ftype;
struct _NCp1_NValue _Fval;
};
struct _NCp1_NExprRef;
struct _NCp1_NExprRef {
struct _NCp1_NExpr _Fbase;
_NCp1_NExprI _Fexpr;
struct _NCp1_NValue _Fval;
};
struct _NCp1_NExprLvar;
struct _NCp1_NExprLvar {
struct _NCp1_NExpr _Fbase;
_NCp1_NLvar _Flvar;
};
struct _NCp1_NExprFvar;
struct _NCp1_NExprFvar {
struct _NCp1_NExpr _Fbase;
_NCp1_NExprI _Fexpr;
_NCp1_NId _Fmember;
_NCp1_NFvar _Ffvar;
struct _NCp1_NValue _Fval;
};
struct _NCp1_NExprGvar;
struct _NCp1_NExprGvar {
struct _NCp1_NExpr _Fbase;
_NCp1_NGvar _Fgvar;
};
struct _NCp1_NExprCvar;
struct _NCp1_NExprCvar {
struct _NCp1_NExpr _Fbase;
_NCp1_NAt _Fat;
_NCp1_NId _Fname;
_NCp1_NCvar _Fcvar;
_NCp1_NAt _Ftry;
};
struct _NCp1_NExprBoolsItem;
struct _NCp1_NExprBoolsItem {
_NCp1_NExprI _Fexpr;
struct _NCp1_NValue _Fval;
};
struct _NCp1_NExprBools;
struct _NCp1_NExprBools {
struct _NCp1_NExpr _Fbase;
_NCp1_NExprI _Fleft;
_NCp1_NExprI _Fright;
_NCp1_NBools _Ftype;
struct _NCp1_NValue _Fleft_val;
struct _NCp1_NValue _Fright_val;
uint8_t _Fitem_c;
struct _NCp1_NExprBoolsItem* _Fitem_v;
};
struct _NCp1_NCarg;
struct _NCp1_NCarg {
int8_t _Freff;
_NCp1_NExprI _Fexpr;
struct _NCp1_NValue _Fvalue;
};
struct _NCp1_NExprMethod;
struct _NCp1_NExprMethod {
struct _NCp1_NExpr _Fbase;
_NCp1_NExprI _Fthiss;
_NCp1_NId _Ffunc_name;
_NCp1_NFunc _Ffunc_idx;
struct _NCp1_NValue _Fthis_value;
uint8_t _Fgroup_c;
uint8_t _Fgroup_v[_NCp1_Cexpr_carg_group_limit];
uint8_t _Fcarg_c;
struct _NCp1_NCarg _Fcarg_v[0];
};
struct _NCp1_NExprFunc;
struct _NCp1_NExprFunc {
struct _NCp1_NExpr _Fbase;
_NCp1_NAt _Fat;
_NCp1_NId _Ffunc_name;
_NCp1_NFunc _Ffunc_idx;
uint8_t _Fgroup_c;
uint8_t _Fgroup_v[_NCp1_Cexpr_carg_group_limit];
uint8_t _Fcarg_c;
struct _NCp1_NCarg _Fcarg_v[0];
};
struct _NCp1_NExprStrNode;
struct _NCp1_NExprStrNode {
struct _NCp1_NExprStrNode* _Fnext;
int32_t _Flen;
char _Fbuf[0];
};
struct _NCp1_NExprStr;
struct _NCp1_NExprStr {
struct _NCp1_NExpr _Fbase;
int32_t _Fnode_c;
struct _NCp1_NExprStrNode* _Ffirst;
struct _NCp1_NExprStrNode* _Flast;
};
struct _NCp1_NExprIntData;
struct _NCp1_NExprIntData {
struct _NCp1_NExpr _Fbase;
int32_t _Fvalue;
_NCp1_NExprInt _Ftype;
};
struct _NCp1_NExprSizeOfType;
struct _NCp1_NExprSizeOfType {
struct _NCp1_NExpr _Fbase;
_NCp1_NAt _Ftype;
};
struct _NCp1_NExprNull;
struct _NCp1_NExprNull {
struct _NCp1_NExpr _Fbase;
};
struct _NCp1_NExprIndex;
struct _NCp1_NExprIndex {
struct _NCp1_NExpr _Fbase;
_NCp1_NExprI _Fleft;
_NCp1_NExprI _Fright;
struct _NCp1_NValue _Fleft_val;
struct _NCp1_NValue _Fright_val;
};
struct _NCp1_NExprCastFast;
struct _NCp1_NExprCastFast {
struct _NCp1_NExpr _Fbase;
_NCp1_NExprI _Fexpr;
_NCp1_NAt _Ftype;
struct _NCp1_NValue _Fval;
};
struct _NCp1_NStmtExpr;
struct _NCp1_NStmtExpr {
struct _NCp1_NStmt _Fbase;
_NCp1_NExprI _Fexpr;
};
struct _NCp1_NStmtIf;
struct _NCp1_NStmtIf {
struct _NCp1_NStmt _Fbase;
bool _Fnot;
_NCp1_NExprI _Fexpr;
struct _NCp1_NValue _Fval;
};
struct _NCp1_NStmtIfElif;
struct _NCp1_NStmtIfElif {
struct _NCp1_NStmt _Fbase;
bool _Fnot;
_NCp1_NExprI _Fexpr;
struct _NCp1_NValue _Fval;
};
struct _NCp1_NStmtIfElse;
struct _NCp1_NStmtIfElse {
struct _NCp1_NStmt _Fbase;
};
struct _NCp1_NStmtIfEnd;
struct _NCp1_NStmtIfEnd {
struct _NCp1_NStmt _Fbase;
};
struct _NCp1_NStmtSwitchCaseFunc;
struct _NCp1_NStmtSwitchCaseFunc {
_NCp1_NCvar _Fcvar;
_NCp1_NFunc _Ffunc;
};
struct _NCp1_NStmtSwitch;
struct _NCp1_NStmtSwitch {
struct _NCp1_NStmt _Fbase;
_NCp1_NExprI _Fexpr;
struct _NCp1_NValue _Fval;
_NCp1_NExprI _Fcases;
uint32_t _Fcase_func_c;
struct _NCp1_NStmtSwitchCaseFunc* _Fcase_func_v;
};
struct _NCp1_NStmtCaseItem;
struct _NCp1_NStmtCaseItem {
_NCp1_NExprI _Fexpr;
struct _NCp1_NValue _Fval;
};
struct _NCp1_NStmtCase;
struct _NCp1_NStmtCase {
struct _NCp1_NStmt _Fbase;
bool _Ffall_through;
uint32_t _Fexpr_c;
struct _NCp1_NStmtCaseItem _Fexpr_v[0];
};
struct _NCp1_NStmtCaseEnd;
struct _NCp1_NStmtCaseEnd {
struct _NCp1_NStmt _Fbase;
};
struct _NCp1_NStmtDefault;
struct _NCp1_NStmtDefault {
struct _NCp1_NStmt _Fbase;
bool _Ffall_through;
};
struct _NCp1_NStmtDefaultEnd;
struct _NCp1_NStmtDefaultEnd {
struct _NCp1_NStmt _Fbase;
};
struct _NCp1_NStmtSwitchEnd;
struct _NCp1_NStmtSwitchEnd {
struct _NCp1_NStmt _Fbase;
};
struct _NCp1_NStmtDoEnd;
struct _NCp1_NStmtDoEnd {
struct _NCp1_NStmt _Fbase;
struct _NCp1_NStmtDo* _Fdo;
};
struct _NCp1_NStmtDo;
struct _NCp1_NStmtDo {
struct _NCp1_NStmt _Fbase;
_NCp1_NExprI _Fexpr;
struct _NCp1_NStmtSpace* _Fcontinu;
struct _NCp1_NStmtDoEnd* _Fend;
};
struct _NCp1_NStmtWhileEnd;
struct _NCp1_NStmtWhileEnd {
struct _NCp1_NStmt _Fbase;
struct _NCp1_NStmtWhile* _Fwhil;
};
struct _NCp1_NStmtWhile;
struct _NCp1_NStmtWhile {
struct _NCp1_NStmt _Fbase;
_NCp1_NExprI _Fexpr;
struct _NCp1_NStmtSpace* _Fcontinu;
struct _NCp1_NStmtWhileEnd* _Fend;
};
union _NCp1_NNest;
union _NCp1_NNest {
struct _NCp1_NStmtDo* _Fdo;
struct _NCp1_NStmtWhile* _Fwhil;
void* _Freff;
};
struct _NCp1_NStmtContinue;
struct _NCp1_NStmtContinue {
struct _NCp1_NStmt _Fbase;
uint8_t _Fnest;
};
struct _NCp1_NStmtBreak;
struct _NCp1_NStmtBreak {
struct _NCp1_NStmt _Fbase;
uint8_t _Fnest;
};
struct _NCp1_NStmtReturn;
struct _NCp1_NStmtReturn {
struct _NCp1_NStmt _Fbase;
_NCp1_NExprI _Fexpr;
struct _NCp1_NValue _Fval;
};
union _NCp1_NCaseStack;
union _NCp1_NCaseStack {
struct _NCp1_NStmtCase* _Fcas;
struct _NCp1_NStmtDefault* _Fdefaul;
};
struct _NCp1_NMap _Gid_map;
struct _NCp1_NMap _Ginclude_map;
struct _NCp1_NAtMap _Gat_map;
_NCp1_NFunc _Gfunc_main;
_NCp1_NAt _Gat_c;
_NCp1_NAt _Gat_cap;
struct _NCp1_NAtData* _Gat_v;
_NCp1_NFunc _Gfunc_c;
struct _NCp1_NBasicType _Gbasic_type[_NCp1_NBasicTypeId_CCOUNT];
char** _Gid_c_name_v;
int32_t _Gid_c;
uint8_t* _Gfunc_in_process;
_NCp1_NFunc* _Gfunc_head_outputted_v;
_NCp1_NFunc* _Gfunc_body_outputted_v;
int32_t _Ginclude_c;
uint8_t* _Ginclude_is_outputted;
_NCp1_NInclude* _Ginclude_outputted_v;
_NCp1_NCvar _Gcvar_c;
uint8_t* _Gcvar_is_outputted;
_NCp1_NCvar* _Gcvar_outputted_v;
_NCp1_NGvar _Ggvar_c;
uint8_t* _Ggvar_is_outputted;
_NCp1_NGvar* _Ggvar_outputted_v;
_NCp1_NEnum _Genum_c;
uint8_t* _Genum_is_outputted;
_NCp1_NEnum* _Genum_outputted_v;
_NCp1_NStruct _Gstruct_c;
uint8_t* _Gstruct_is_outputted;
_NCp1_NStruct* _Gstruct_outputted_v;
_NCp1_NFunc _Gprocess_first;
_NCp1_NFunc _Gprocess_last;
int32_t _Gfunc_head_outputted_c;
struct _NCp1_NDeclFunc* _Gctx_func;
struct FILE* _Gout;
bool _Ginclude_stdint;
bool _Ginclude_stdbool;
bool _Ginclude_stddef;
int32_t _Ginclude_outputted_c;
int32_t _Gcvar_outputted_c;
int32_t _Genum_outputted_c;
int32_t _Gstruct_outputted_c;
int32_t _Ggvar_outputted_c;
int32_t _Gfunc_body_outputted_c;
int32_t _Gnest_id;
int32_t _Gquick_alloc_c;
int32_t _Gquick_alloc_cap;
void* _Gquick_alloc_v;
_NCp1_NFile _Gfile_c;
_NCp1_NFile _Gfile_cap;
struct _NCp1_NFileData* _Gfile_v;
_NCp1_NId* _Gid_table;
int32_t _Ginclude_table_cap;
_NCp1_NInclude* _Ginclude_table;
int32_t _Ginclude_cap;
uint8_t* _Ginclude_len_v;
char** _Ginclude_str_v;
_NCp1_NAt* _Gat_table;
_NCp1_NCvar* _Gcvar_table;
_NCp1_NCvar _Gcvar_cap;
struct _NCp1_NCvarData* _Gcvar_v;
_NCp1_NGvar _Ggvar_cap;
struct _NCp1_NDeclGvar* _Ggvar_v;
_NCp1_NEnum _Genum_cap;
struct _NCp1_NEnumData** _Genum_v;
_NCp1_NStruct _Gstruct_cap;
struct _NCp1_NStructData** _Gstruct_v;
_NCp1_NFunc _Gfunc_cap;
struct _NCp1_NDeclFunc** _Gfunc_v;
_NCp1_NFunc _Gctx_func_id;
char** _Gid_str_v;
int32_t _Gid_cap;
uint8_t* _Gid_len_v;
int32_t _Gctx_begin_row;
int32_t _Gctx_begin_col;
int32_t _Gctx_end_row;
int32_t _Gctx_end_col;
int32_t _Gexpr_c;
int32_t _Gexpr_cap;
struct _NCp1_NExpr** _Gexpr_v;
uint8_t* _Gexpr_is_processed;
int32_t _Gnest_stack_id_v[64];
uint8_t _Gnest_stack_c;
union _NCp1_NNest _Gnest_stack_ptr_v[64];
struct _NCp1_NStmtSwitch* _Gswitch_stack_v[64];
uint8_t _Gswitch_stack_c;
union _NCp1_NCaseStack _Gcase_stack_v[64];
uint8_t _Gcase_stack_c;
int main(int _Larg_c_0, char** _Larg_v_1);
void qalloc_undo(int32_t _Lsize_0);
void _NCp1_NMap_Pinit_1(struct _NCp1_NMap* _Lm_0);
void _NCp1_NAtMap_Pinit_1(struct _NCp1_NAtMap* _Lm_0);
void _NCp1_Pquick_alloc_init_0();
#define _NCp1_Pgrow_2(cap, c) cap = Fpow2gteq((c) + 8)
#define _NCp1_Prealloc_3(r, c, oldc) r = realloc(r, sizeof(r[0]) * (c)); memset(r + (oldc), 0, sizeof(r[0]) * ((c) - (oldc)))
void _NCp1_NAtData_Pinit_4(struct _NCp1_NAtData* _Lat_0, _NCp1_NNameType _Ltype_1, _NCp1_NAt _Lparent_2, _NCp1_NId _Lname_3);
void _NCp1_Pread_1(char* _Lin_path_0);
struct _NCp1_NDeclFunc* _NCp1_NFunc_Pptr_1(_NCp1_NFunc _Lf_0);
struct _NCp1_NAtData* _NCp1_NAt_Pptr_1(_NCp1_NAt _Li_0);
char* _NCp1_NFile_Ppath_1(_NCp1_NFile _Lf_0);
char* _NCp1_NId_Pstr_1(_NCp1_NId _Lid_0);
struct _NCp1_NStructData* _NCp1_NStruct_Pptr_1(_NCp1_NStruct _Ls_0);
struct _NCp1_NEnumData* _NCp1_NEnum_Pptr_1(_NCp1_NEnum _Lf_0);
_NCp1_NId _NCp1_Pid_add_2(uint8_t _Lid_len_0, char* _Lid_str_1);
#define _NCp1_Pquick_alloc_arr_2(r, c) r = qalloc(sizeof(r[0]) * (c))
void _NCp1_NFunc_Pprocess_later_1(_NCp1_NFunc _Lf_idx_0);
bool _NCp1_NFunc_Pprocess_now_1(_NCp1_NFunc _Lf_idx_0);
bool _NCp1_NLvar_Pprocess_1(_NCp1_NLvar _Ll_0);
void _NCp1_NAt_Poutput_4(_NCp1_NAt _Lat_i_0, _NCp1_NFile _Lfile_1, int32_t _Lrow_2, int32_t _Lcol_3);
void _NCp1_NInclude_Poutput_1(_NCp1_NInclude _Lthiss_0);
struct _NCp1_NCvarData* _NCp1_NCvar_Pptr_1(_NCp1_NCvar _Lc_0);
bool _NCp1_NCvar_Pprocess_1(_NCp1_NCvar _Lc_0);
char* _NCp1_NInclude_Pstr_1(_NCp1_NInclude _Li_0);
void _NCp1_NCvar_Pwrite_1(_NCp1_NCvar _Lc_0);
void _NCp1_NExprI_Pwrite_1(_NCp1_NExprI _Le_0);
void _NCp1_NAt_Pwrite_1(_NCp1_NAt _Lat_idx_0);
void _NCp1_NAt_Pwrite_space_1(_NCp1_NAt _Lat_idx_0);
void _NCp1_NDeclVarData_Pwrite_type_2(struct _NCp1_NDeclVarData* _Lvd_0, _NCp1_NDeclVarType _Lvar_type_1);
struct _NCp1_NDeclGvar* _NCp1_NGvar_Pptr_1(_NCp1_NGvar _Lg_0);
void _NCp1_NDeclFunc_Pwrite_1(struct _NCp1_NDeclFunc* _Lf_0);
bool _NCp1_NAt_Pwrite_type_info_3(_NCp1_NAt _Ltd_0, struct _NCp1_NTypeInfo* _Lti_1, int32_t _Ladd_2);
void _NCp1_NDeclVarData_Pwrite_lvar_type_2(struct _NCp1_NDeclVarData* _Lvd_0, _NCp1_NLvar _Llvar_1);
void _NCp1_NStmtSpace_Pwrite_1(struct _NCp1_NStmtSpace* _Lspace_0);
bool _NStdc_NFd_Popen_3(_NStdc_NFd* _Lfile_0, char* _Lpath_1, _NStdc_NOpenFlags _Lflags_2);
int _NStdc_NFd_Pclose_1(_NStdc_NFd _Lfile_0);
uint8_t _NCp1_NRdr_Pn1_1(union _NCp1_NRdr* _Lr_0);
int32_t _NCp1_NMap_Pget_or_insert_4(struct _NCp1_NMap* _Lm_0, char* _Lstr_1, uint8_t _Llen_2, int32_t _Lval_3);
void _NCp1_NNameType_Prd_2(_NCp1_NNameType* _Li_0, union _NCp1_NRdr* _Lr_1);
void _NCp1_NBasicTypeId_Prd_2(_NCp1_NBasicTypeId* _Le_0, union _NCp1_NRdr* _Lr_1);
_NCp1_NAt _NCp1_Pbasic_type_1(_NCp1_NBasicTypeId _Lt_0);
void _NCp1_NAt_Prd_2(_NCp1_NAt* _Li_0, union _NCp1_NRdr* _Lr_1);
void _NCp1_NId_Prd_2(_NCp1_NId* _Lid_0, union _NCp1_NRdr* _Lr_1);
int32_t _NCp1_NAtMap_Pget_or_insert_5(struct _NCp1_NAtMap* _Lm_0, _NCp1_NAt _Lparent_1, _NCp1_NNameType _Ltype_2, _NCp1_NId _Lname_3, int32_t _Lval_4);
void _NCp1_NInclude_Prd_2(_NCp1_NInclude* _Li_0, union _NCp1_NRdr* _Lr_1);
void _NCp1_NDeclVarData_Prd_2(struct _NCp1_NDeclVarData* _Lvd_0, union _NCp1_NRdr* _Lr_1);
void _NCp1_NCvarFlags_Prd_2(_NCp1_NCvarFlags* _Lf_0, union _NCp1_NRdr* _Lr_1);
void _NCp1_NExprI_Prd_2(_NCp1_NExprI* _Le_0, union _NCp1_NRdr* _Lr_1);
void _NCp1_NCvar_Prd_2(_NCp1_NCvar* _Lc_0, union _NCp1_NRdr* _Lr_1);
#define _NCp1_Pquick_alloc_one_1(r) r = qalloc(sizeof(r[0]))
void _NCp1_NEnumFlags_Prd_2(_NCp1_NEnumFlags* _Le_0, union _NCp1_NRdr* _Lr_1);
#define _NCp1_Pquick_alloc_plus_2(r, plus) r = qalloc(sizeof(r[0]) + plus)
void _NCp1_NStructFlags_Prd_2(_NCp1_NStructFlags* _Lf_0, union _NCp1_NRdr* _Lr_1);
void _NCp1_NFarg_Prd_2(struct _NCp1_NFarg* _Lf_0, union _NCp1_NRdr* _Lr_1);
void _NCp1_NFuncFlags_Prd_2(_NCp1_NFuncFlags* _Le_0, union _NCp1_NRdr* _Lr_1);
void* qalloc(int32_t _Lsize_0);
void _NCp1_NFunc_Prd_2(_NCp1_NFunc* _Lf_0, union _NCp1_NRdr* _Lr_1);
uint32_t _NCp1_NRdr_Pn4_1(union _NCp1_NRdr* _Lr_0);
struct _NCp1_NFileData* _NCp1_NFile_Pptr_1(_NCp1_NFile _Lf_0);
_NCp1_NAt _NCp1_Pat_validate_5(_NCp1_NAt _Lvd_type_0, _NCp1_NAt _Lat_i_1, _NCp1_NFile _Lfile_2, uint32_t _Lrow_3, uint32_t _Lcol_4);
bool _NCp1_NAt_Pfinalize_4(_NCp1_NAt _Lat_i_0, struct _NCp1_NTypeInfo* _Lti_1, int32_t _Lrow_2, int32_t _Lcol_3);
void _NCp1_NDeclFunc_Plvars_rd_2(struct _NCp1_NDeclFunc* _Lf_0, union _NCp1_NRdr* _Lr_1);
void _NCp1_NStmtSpace_Prd_3(struct _NCp1_NStmtSpace* _Lspace_0, union _NCp1_NRdr* _Lr_1, struct _NCp1_NStmtSpace* _Lparent_2);
bool _NCp1_NStmt_Pprocess_1(struct _NCp1_NStmt* _Ls_0);
struct _NCp1_NLvarData* _NCp1_NLvar_Pptr_1(_NCp1_NLvar _Ll_0);
bool _NCp1_NExprI_Pvalue_4(_NCp1_NExprI _Le_0, int32_t _Lreff_1, bool _Lparen_2, struct _NCp1_NValue* _Lv_3);
void _NCp1_NTypeInfo_Pinit_1(struct _NCp1_NTypeInfo* _Lti_0);
void _NCp1_NTypeInfo_Pcopy_from_2(struct _NCp1_NTypeInfo* _Lti_0, struct _NCp1_NTypeInfo* _Lti2_1);
bool _NCp1_NDeclVarData_Pprocess_5(struct _NCp1_NDeclVarData* _Lvd_0, _NCp1_NFile _Lfile_1, int32_t _Lrow_2, int32_t _Lcol_3, _NCp1_NAt _Lbase_at_4);
void _NCp1_NStruct_Poutput_1(_NCp1_NStruct _Ls_i_0);
void _NCp1_NEnum_Poutput_1(_NCp1_NEnum _Le_i_0);
bool _NCp1_NExprI_Pprocess_1(_NCp1_NExprI _Le_0);
char* _NCp1_NId_Pc_name_1(_NCp1_NId _Lid_0);
struct _NCp1_NExpr* _NCp1_NExprI_Pptr_1(_NCp1_NExprI _Le_0);
void _NCp1_NExprI_Pwrite_assign_1(struct _NCp1_NExpr* _Lexpr_0);
void _NCp1_NExprI_Pwrite_compare_1(struct _NCp1_NExpr* _Lexpr_0);
void _NCp1_NExprI_Pwrite_bool_1(struct _NCp1_NExpr* _Lexpr_0);
void _NCp1_NExprI_Pwrite_char_1(struct _NCp1_NExpr* _Lexpr_0);
void _NCp1_NExprI_Pwrite_math_1(struct _NCp1_NExpr* _Lexpr_0);
void _NCp1_NExprI_Pwrite_unary_1(struct _NCp1_NExpr* _Lexpr_0);
void _NCp1_NExprI_Pwrite_ref_1(struct _NCp1_NExpr* _Lexpr_0);
void _NCp1_NExprI_Pwrite_lvar_1(struct _NCp1_NExpr* _Lexpr_0);
void _NCp1_NExprI_Pwrite_fvar_1(struct _NCp1_NExpr* _Lexpr_0);
void _NCp1_NExprI_Pwrite_gvar_1(struct _NCp1_NExpr* _Lexpr_0);
void _NCp1_NExprI_Pwrite_cvar_1(struct _NCp1_NExpr* _Lexpr_0);
void _NCp1_NExprI_Pwrite_bools_1(struct _NCp1_NExpr* _Lexpr_0);
void _NCp1_NExprI_Pwrite_method_1(struct _NCp1_NExpr* _Lexpr_0);
void _NCp1_NExprI_Pwrite_func_1(struct _NCp1_NExpr* _Lexpr_0);
void _NCp1_NExprI_Pwrite_str_1(struct _NCp1_NExpr* _Lexpr_0);
void _NCp1_NExprI_Pwrite_i32_1(struct _NCp1_NExpr* _Lexpr_0);
void _NCp1_NExprI_Pwrite_size_of_type_1(struct _NCp1_NExpr* _Lexpr_0);
void _NCp1_NExprI_Pwrite_null_1(struct _NCp1_NExpr* _Lexpr_0);
void _NCp1_NExprI_Pwrite_index_1(struct _NCp1_NExpr* _Lexpr_0);
char* _NCp1_NExprType_Pcp1_name_1(_NCp1_NExprType _Le_0) {
switch(_Le_0) {
case _NCp1_NExprType_Cnil: return "nil";
case _NCp1_NExprType_Ccall_method: return "call-method";
case _NCp1_NExprType_Clvar: return "lvar";
case _NCp1_NExprType_Cgvar: return "gvar";
case _NCp1_NExprType_Cmath: return "math";
case _NCp1_NExprType_Cassign: return "assign";
case _NCp1_NExprType_Cbools: return "bools";
case _NCp1_NExprType_Cfunc: return "func";
case _NCp1_NExprType_Cmethod: return "method";
case _NCp1_NExprType_Cfvar: return "fvar";
case _NCp1_NExprType_Ci32: return "i32";
case _NCp1_NExprType_Ccvar: return "cvar";
case _NCp1_NExprType_Cstr: return "str";
case _NCp1_NExprType_Cindex: return "index";
case _NCp1_NExprType_Cunary: return "unary";
case _NCp1_NExprType_Ccompare: return "compare";
case _NCp1_NExprType_Cbool: return "bool";
case _NCp1_NExprType_Cnull: return "null";
case _NCp1_NExprType_Ccast_fast: return "cast-fast";
case _NCp1_NExprType_Cref: return "ref";
case _NCp1_NExprType_Cchar: return "char";
case _NCp1_NExprType_Csize_of_type: return "size-of-type";
}
return "(ERROR)";
}
void _NCp1_NDeclVarData_Pwrite_2(struct _NCp1_NDeclVarData* _Lvd_0, _NCp1_NDeclVarType _Lvar_type_1);
bool _NCp1_NExprI_Pwrite_value_2(_NCp1_NExprI _Le_0, struct _NCp1_NValue* _Lv_1);
void _NCp1_NTypeInfo_Pcount_1(struct _NCp1_NTypeInfo* _Lti_0);
bool _NCp1_NAt_Pwrite_type_1(_NCp1_NAt _Ltd_0);
int32_t _NCp1_NAt_Pcount_stars0_2(_NCp1_NAt _Ltd_0, struct _NCp1_NTypeInfo* _Lti_1);
size_t _NStdc_NFile_Pwrite_3(struct FILE* _Lf_0, void* _Lbuf_1, size_t _Lsize_2);
void _NCp1_NDeclVarData_Pwrite_lvar_2(struct _NCp1_NDeclVarData* _Lvd_0, _NCp1_NLvar _Llvar_1);
void _NCp1_NStmt_Pwrite_1(struct _NCp1_NStmt* _Ls_0);
void _NCp1_NVarFlags_Prd_2(_NCp1_NVarFlags* _Lf_0, union _NCp1_NRdr* _Lr_1);
void _NCp1_NTypeInfo_Prd_2(struct _NCp1_NTypeInfo* _Lti_0, union _NCp1_NRdr* _Lr_1);
void _NCp1_NExprType_Prd_2(_NCp1_NExprType* _Le_0, union _NCp1_NRdr* _Lr_1);
void _NCp1_NExprI_Prd_assign_2(_NCp1_NExprI _Le_idx_0, union _NCp1_NRdr* _Lr_1);
void _NCp1_NExprI_Prd_compare_2(_NCp1_NExprI _Le_idx_0, union _NCp1_NRdr* _Lr_1);
void _NCp1_NExprI_Prd_bool_2(_NCp1_NExprI _Le_idx_0, union _NCp1_NRdr* _Lr_1);
void _NCp1_NExprI_Prd_char_2(_NCp1_NExprI _Le_idx_0, union _NCp1_NRdr* _Lr_1);
void _NCp1_NExprI_Prd_math_2(_NCp1_NExprI _Le_idx_0, union _NCp1_NRdr* _Lr_1);
void _NCp1_NExprI_Prd_unary_2(_NCp1_NExprI _Le_idx_0, union _NCp1_NRdr* _Lr_1);
void _NCp1_NExprI_Prd_ref_2(_NCp1_NExprI _Le_idx_0, union _NCp1_NRdr* _Lr_1);
void _NCp1_NExprI_Prd_cast_fast_2(_NCp1_NExprI _Le_idx_0, union _NCp1_NRdr* _Lr_1);
void _NCp1_NExprI_Prd_lvar_2(_NCp1_NExprI _Le_idx_0, union _NCp1_NRdr* _Lr_1);
void _NCp1_NExprI_Prd_fvar_2(_NCp1_NExprI _Le_idx_0, union _NCp1_NRdr* _Lr_1);
void _NCp1_NExprI_Prd_gvar_2(_NCp1_NExprI _Le_idx_0, union _NCp1_NRdr* _Lr_1);
void _NCp1_NExprI_Prd_cvar_2(_NCp1_NExprI _Le_idx_0, union _NCp1_NRdr* _Lr_1);
void _NCp1_NExprI_Prd_bools_2(_NCp1_NExprI _Le_idx_0, union _NCp1_NRdr* _Lr_1);
void _NCp1_NExprI_Prd_method_2(_NCp1_NExprI _Le_idx_0, union _NCp1_NRdr* _Lr_1);
void _NCp1_NExprI_Prd_func_2(_NCp1_NExprI _Le_idx_0, union _NCp1_NRdr* _Lr_1);
void _NCp1_NExprI_Prd_str_2(_NCp1_NExprI _Le_idx_0, union _NCp1_NRdr* _Lr_1);
void _NCp1_NExprI_Prd_i32_2(_NCp1_NExprI _Le_idx_0, union _NCp1_NRdr* _Lr_1);
void _NCp1_NExprI_Prd_size_of_type_2(_NCp1_NExprI _Le_idx_0, union _NCp1_NRdr* _Lr_1);
void _NCp1_NExprI_Prd_null_2(_NCp1_NExprI _Le_idx_0, union _NCp1_NRdr* _Lr_1);
void _NCp1_NExprI_Prd_index_2(_NCp1_NExprI _Le_idx_0, union _NCp1_NRdr* _Lr_1);
void _NCp1_NLvarFlags_Prd_2(_NCp1_NLvarFlags* _Lf_0, union _NCp1_NRdr* _Lr_1);
void _NCp1_NLvar_Prd_2(_NCp1_NLvar* _Ll_0, union _NCp1_NRdr* _Lr_1);
void _NCp1_NStmtType_Prd_2(_NCp1_NStmtType* _Ls_0, union _NCp1_NRdr* _Lr_1);
void _NCp1_NStmtSpace_Prd_expr_2(struct _NCp1_NStmtSpace* _Lspace_0, union _NCp1_NRdr* _Lr_1);
void _NCp1_NStmtSpace_Prd_if_2(struct _NCp1_NStmtSpace* _Lspace_0, union _NCp1_NRdr* _Lr_1);
void _NCp1_NStmtSpace_Prd_if_elif_2(struct _NCp1_NStmtSpace* _Lspace_0, union _NCp1_NRdr* _Lr_1);
void _NCp1_NStmtSpace_Prd_if_else_2(struct _NCp1_NStmtSpace* _Lspace_0, union _NCp1_NRdr* _Lr_1);
void _NCp1_NStmtSpace_Prd_if_end_2(struct _NCp1_NStmtSpace* _Lspace_0, union _NCp1_NRdr* _Lr_1);
void _NCp1_NStmtSpace_Prd_switch_2(struct _NCp1_NStmtSpace* _Lspace_0, union _NCp1_NRdr* _Lr_1);
void _NCp1_NStmtSpace_Prd_case_2(struct _NCp1_NStmtSpace* _Lspace_0, union _NCp1_NRdr* _Lr_1);
void _NCp1_NStmtSpace_Prd_case_end_2(struct _NCp1_NStmtSpace* _Lspace_0, union _NCp1_NRdr* _Lr_1);
void _NCp1_NStmtSpace_Prd_default_2(struct _NCp1_NStmtSpace* _Lspace_0, union _NCp1_NRdr* _Lr_1);
void _NCp1_NStmtSpace_Prd_default_end_2(struct _NCp1_NStmtSpace* _Lspace_0, union _NCp1_NRdr* _Lr_1);
void _NCp1_NStmtSpace_Prd_switch_end_2(struct _NCp1_NStmtSpace* _Lspace_0, union _NCp1_NRdr* _Lr_1);
void _NCp1_NStmtSpace_Prd_do_2(struct _NCp1_NStmtSpace* _Lspace_0, union _NCp1_NRdr* _Lr_1);
void _NCp1_NStmtSpace_Prd_do_end_2(struct _NCp1_NStmtSpace* _Lspace_0, union _NCp1_NRdr* _Lr_1);
void _NCp1_NStmtSpace_Prd_while_2(struct _NCp1_NStmtSpace* _Lspace_0, union _NCp1_NRdr* _Lr_1);
void _NCp1_NStmtSpace_Prd_while_end_2(struct _NCp1_NStmtSpace* _Lspace_0, union _NCp1_NRdr* _Lr_1);
void _NCp1_NStmtSpace_Prd_continue_2(struct _NCp1_NStmtSpace* _Lspace_0, union _NCp1_NRdr* _Lr_1);
void _NCp1_NStmtSpace_Prd_break_2(struct _NCp1_NStmtSpace* _Lspace_0, union _NCp1_NRdr* _Lr_1);
void _NCp1_NStmtSpace_Prd_return_2(struct _NCp1_NStmtSpace* _Lspace_0, union _NCp1_NRdr* _Lr_1);
void _NCp1_NStmtSpace_Prd_space_2(struct _NCp1_NStmtSpace* _Lspace_0, union _NCp1_NRdr* _Lr_1);
char* _NCp1_NStmtType_Pcp1_name_1(_NCp1_NStmtType _Le_0) {
switch(_Le_0) {
case _NCp1_NStmtType_Cspace: return "space";
case _NCp1_NStmtType_Cif: return "if";
case _NCp1_NStmtType_Cif_elif: return "if-elif";
case _NCp1_NStmtType_Cif_else: return "if-else";
case _NCp1_NStmtType_Cif_end: return "if-end";
case _NCp1_NStmtType_Cdo: return "do";
case _NCp1_NStmtType_Cdo_end: return "do-end";
case _NCp1_NStmtType_Cwhile: return "while";
case _NCp1_NStmtType_Cwhile_end: return "while-end";
case _NCp1_NStmtType_Cexpr: return "expr";
case _NCp1_NStmtType_Creturn: return "return";
case _NCp1_NStmtType_Ccontinue: return "continue";
case _NCp1_NStmtType_Cbreak: return "break";
case _NCp1_NStmtType_Cswitch: return "switch";
case _NCp1_NStmtType_Ccase: return "case";
case _NCp1_NStmtType_Cdefault: return "default";
case _NCp1_NStmtType_Ccase_end: return "case-end";
case _NCp1_NStmtType_Cdefault_end: return "default-end";
case _NCp1_NStmtType_Cswitch_end: return "switch-end";
case _NCp1_NStmtType_Cnil: return "nil";
}
return "(ERROR)";
}
void _NCp1_NStmt_Pprocess_expr_2(struct _NCp1_NStmt* _Lstmt_0, bool* _Lok_1);
void _NCp1_NStmt_Pprocess_if_2(struct _NCp1_NStmt* _Lstmt_0, bool* _Lok_1);
void _NCp1_NStmt_Pprocess_if_elif_2(struct _NCp1_NStmt* _Lstmt_0, bool* _Lok_1);
void _NCp1_NStmt_Pprocess_if_else_2(struct _NCp1_NStmt* _Lstmt_0, bool* _Lok_1);
void _NCp1_NStmt_Pprocess_if_end_2(struct _NCp1_NStmt* _Lstmt_0, bool* _Lok_1);
void _NCp1_NStmt_Pprocess_switch_2(struct _NCp1_NStmt* _Lstmt_0, bool* _Lok_1);
void _NCp1_NStmt_Pprocess_case_2(struct _NCp1_NStmt* _Lstmt_0, bool* _Lok_1);
void _NCp1_NStmt_Pprocess_case_end_2(struct _NCp1_NStmt* _Lstmt_0, bool* _Lok_1);
void _NCp1_NStmt_Pprocess_default_2(struct _NCp1_NStmt* _Lstmt_0, bool* _Lok_1);
void _NCp1_NStmt_Pprocess_default_end_2(struct _NCp1_NStmt* _Lstmt_0, bool* _Lok_1);
void _NCp1_NStmt_Pprocess_switch_end_2(struct _NCp1_NStmt* _Lstmt_0, bool* _Lok_1);
void _NCp1_NStmt_Pprocess_do_2(struct _NCp1_NStmt* _Lstmt_0, bool* _Lok_1);
void _NCp1_NStmt_Pprocess_do_end_2(struct _NCp1_NStmt* _Lstmt_0, bool* _Lok_1);
void _NCp1_NStmt_Pprocess_while_2(struct _NCp1_NStmt* _Lstmt_0, bool* _Lok_1);
void _NCp1_NStmt_Pprocess_while_end_2(struct _NCp1_NStmt* _Lstmt_0, bool* _Lok_1);
void _NCp1_NStmt_Pprocess_continue_2(struct _NCp1_NStmt* _Lstmt_0, bool* _Lok_1);
void _NCp1_NStmt_Pprocess_break_2(struct _NCp1_NStmt* _Lstmt_0, bool* _Lok_1);
void _NCp1_NStmt_Pprocess_return_2(struct _NCp1_NStmt* _Lstmt_0, bool* _Lok_1);
void _NCp1_NStmt_Pprocess_space_2(struct _NCp1_NStmt* _Lstmt_0, bool* _Lok_1);
void _NCp1_NExprI_Pvalue_assign_5(_NCp1_NExprI _Le_0, int8_t _Lreff_1, bool _Lparen_2, struct _NCp1_NValue* _Lv_3, bool* _Lok_4);
void _NCp1_NExprI_Pvalue_compare_5(_NCp1_NExprI _Le_0, int8_t _Lreff_1, bool _Lparen_2, struct _NCp1_NValue* _Lv_3, bool* _Lok_4);
void _NCp1_NExprI_Pvalue_bool_5(_NCp1_NExprI _Lle_0, int32_t _Lreff_1, bool _Lparen_2, struct _NCp1_NValue* _Lv_3, bool* _Lok_4);
void _NCp1_NExprI_Pvalue_char_5(_NCp1_NExprI _Lle_0, int32_t _Lreff_1, bool _Lparen_2, struct _NCp1_NValue* _Lv_3, bool* _Lok_4);
void _NCp1_NExprI_Pvalue_math_5(_NCp1_NExprI _Le_0, int8_t _Lreff_1, bool _Lparen_2, struct _NCp1_NValue* _Lv_3, bool* _Lok_4);
void _NCp1_NExprI_Pvalue_unary_5(_NCp1_NExprI _Le_0, int8_t _Lreff_1, bool _Lparen_2, struct _NCp1_NValue* _Lv_3, bool* _Lok_4);
void _NCp1_NExprI_Pvalue_ref_5(_NCp1_NExprI _Le_0, int8_t _Lreff_1, bool _Lparen_2, struct _NCp1_NValue* _Lv_3, bool* _Lok_4);
void _NCp1_NExprI_Pvalue_cast_fast_5(_NCp1_NExprI _Le_0, int8_t _Lreff_1, bool _Lparen_2, struct _NCp1_NValue* _Lv_3, bool* _Lok_4);
void _NCp1_NExprI_Pvalue_lvar_5(_NCp1_NExprI _Le_0, int8_t _Lreff_1, bool _Lparen_2, struct _NCp1_NValue* _Lv_3, bool* _Lok_4);
void _NCp1_NExprI_Pvalue_fvar_5(_NCp1_NExprI _Lexpr_0, int8_t _Lreff_1, bool _Lparen_2, struct _NCp1_NValue* _Lv_3, bool* _Lok_4);
void _NCp1_NExprI_Pvalue_gvar_5(_NCp1_NExprI _Lg_0, int32_t _Lreff_1, bool _Lparen_2, struct _NCp1_NValue* _Lv_3, bool* _Lok_4);
void _NCp1_NExprI_Pvalue_cvar_5(_NCp1_NExprI _Le_0, int8_t _Lreff_1, bool _Lparen_2, struct _NCp1_NValue* _Lv_3, bool* _Lok_4);
void _NCp1_NExprI_Pvalue_bools_5(_NCp1_NExprI _Le_0, int32_t _Lreff_1, bool _Lparen_2, struct _NCp1_NValue* _Lv_3, bool* _Lok_4);
void _NCp1_NExprI_Pvalue_func_5(_NCp1_NExprI _Le_0, int32_t _Lreff_1, bool _Lparen_2, struct _NCp1_NValue* _Lv_3, bool* _Lok_4);
void _NCp1_NExprI_Pvalue_method_5(_NCp1_NExprI _Le_0, int32_t _Lreff_1, bool _Lparen_2, struct _NCp1_NValue* _Lv_3, bool* _Lok_4);
void _NCp1_NExprI_Pvalue_str_5(_NCp1_NExprI _Ls_0, int32_t _Lreff_1, bool _Lparen_2, struct _NCp1_NValue* _Lv_3, bool* _Lok_4);
void _NCp1_NExprI_Pvalue_i32_5(_NCp1_NExprI _Lle_0, int32_t _Lreff_1, bool _Lparen_2, struct _NCp1_NValue* _Lv_3, bool* _Lok_4);
void _NCp1_NExprI_Pvalue_size_of_type_5(_NCp1_NExprI _Lle_0, int32_t _Lreff_1, bool _Lparen_2, struct _NCp1_NValue* _Lv_3, bool* _Lok_4);
void _NCp1_NExprI_Pvalue_null_5(_NCp1_NExprI _Lle_0, int32_t _Lreff_1, bool _Lparen_2, struct _NCp1_NValue* _Lv_3, bool* _Lok_4);
void _NCp1_NExprI_Pvalue_index_5(_NCp1_NExprI _Le_0, int8_t _Lreff_1, bool _Lparen_2, struct _NCp1_NValue* _Lv_3, bool* _Lok_4);
void _NCp1_NExprI_Pprocess_assign_2(struct _NCp1_NExpr* _Lexpr_0, bool* _Lok_1);
void _NCp1_NExprI_Pprocess_compare_2(struct _NCp1_NExpr* _Lexpr_0, bool* _Lok_1);
void _NCp1_NExprI_Pprocess_bool_2(struct _NCp1_NExpr* _Lexpr_0, bool* _Lok_1);
void _NCp1_NExprI_Pprocess_char_2(struct _NCp1_NExpr* _Lexpr_0, bool* _Lok_1);
void _NCp1_NExprI_Pprocess_math_2(struct _NCp1_NExpr* _Lexpr_0, bool* _Lok_1);
void _NCp1_NExprI_Pprocess_unary_2(struct _NCp1_NExpr* _Lexpr_0, bool* _Lok_1);
void _NCp1_NExprI_Pprocess_ref_2(struct _NCp1_NExpr* _Lexpr_0, bool* _Lok_1);
void _NCp1_NExprI_Pprocess_cast_fast_2(struct _NCp1_NExpr* _Lexpr_0, bool* _Lok_1);
void _NCp1_NExprI_Pprocess_lvar_2(struct _NCp1_NExpr* _Lexpr_0, bool* _Lok_1);
void _NCp1_NExprI_Pprocess_fvar_2(struct _NCp1_NExpr* _Lexpr_0, bool* _Lok_1);
void _NCp1_NExprI_Pprocess_gvar_2(struct _NCp1_NExpr* _Lexpr_0, bool* _Lok_1);
void _NCp1_NExprI_Pprocess_cvar_2(struct _NCp1_NExpr* _Lexpr_0, bool* _Lok_1);
void _NCp1_NExprI_Pprocess_bools_2(struct _NCp1_NExpr* _Lexpr_0, bool* _Lok_1);
void _NCp1_NExprI_Pprocess_method_2(struct _NCp1_NExpr* _Lexpr_0, bool* _Lok_1);
void _NCp1_NExprI_Pprocess_func_2(struct _NCp1_NExpr* _Lexpr_0, bool* _Lok_1);
void _NCp1_NExprI_Pprocess_str_2(struct _NCp1_NExpr* _Lexpr_0, bool* _Lok_1);
void _NCp1_NExprI_Pprocess_i32_2(struct _NCp1_NExpr* _Lexpr_0, bool* _Lok_1);
void _NCp1_NExprI_Pprocess_size_of_type_2(struct _NCp1_NExpr* _Lexpr_0, bool* _Lok_1);
void _NCp1_NExprI_Pprocess_null_2(struct _NCp1_NExpr* _Lexpr_0, bool* _Lok_1);
void _NCp1_NExprI_Pprocess_index_2(struct _NCp1_NExpr* _Lexpr_0, bool* _Lok_1);
void _NCp1_Pwrite_char_1(char _Lc_0);
void _NCp1_NGvar_Pwrite_1(_NCp1_NGvar _Lg_0);
void _NCp1_Pwrite_str_node_2(int32_t _Llen_0, void* _Lptr_1);
void _NCp1_NExprCastFast_Pwrite_value_2(struct _NCp1_NExprCastFast* _Le_0, struct _NCp1_NValue* _Lv_1);
int32_t _NCp1_NAt_Ppointer_1(_NCp1_NAt _Ltd_0);
void _NCp1_NStmt_Pwrite_expr_1(struct _NCp1_NStmt* _Lstmt_0);
void _NCp1_NStmt_Pwrite_if_1(struct _NCp1_NStmt* _Lstmt_0);
void _NCp1_NStmt_Pwrite_if_elif_1(struct _NCp1_NStmt* _Lstmt_0);
void _NCp1_NStmt_Pwrite_if_else_1(struct _NCp1_NStmt* _Lstmt_0);
void _NCp1_NStmt_Pwrite_if_end_1(struct _NCp1_NStmt* _Lstmt_0);
void _NCp1_NStmt_Pwrite_switch_1(struct _NCp1_NStmt* _Lstmt_0);
void _NCp1_NStmt_Pwrite_case_1(struct _NCp1_NStmt* _Lstmt_0);
void _NCp1_NStmt_Pwrite_case_end_1(struct _NCp1_NStmt* _Lstmt_0);
void _NCp1_NStmt_Pwrite_default_1(struct _NCp1_NStmt* _Lstmt_0);
void _NCp1_NStmt_Pwrite_default_end_1(struct _NCp1_NStmt* _Lstmt_0);
void _NCp1_NStmt_Pwrite_switch_end_1(struct _NCp1_NStmt* _Lstmt_0);
void _NCp1_NStmt_Pwrite_do_1(struct _NCp1_NStmt* _Lstmt_0);
void _NCp1_NStmt_Pwrite_do_end_1(struct _NCp1_NStmt* _Lstmt_0);
void _NCp1_NStmt_Pwrite_while_1(struct _NCp1_NStmt* _Lstmt_0);
void _NCp1_NStmt_Pwrite_while_end_1(struct _NCp1_NStmt* _Lstmt_0);
void _NCp1_NStmt_Pwrite_continue_1(struct _NCp1_NStmt* _Lstmt_0);
void _NCp1_NStmt_Pwrite_break_1(struct _NCp1_NStmt* _Lstmt_0);
void _NCp1_NStmt_Pwrite_return_1(struct _NCp1_NStmt* _Lstmt_0);
void _NCp1_NStmt_Pwrite_space_1(struct _NCp1_NStmt* _Lstmt_0);
void _NCp1_NExprI_Pset_3(_NCp1_NExprI _Le_0, struct _NCp1_NExpr* _Lexpr_1, _NCp1_NExprType _Ltype_2);
void _NCp1_NAssign_Prd_2(_NCp1_NAssign* _Ls_0, union _NCp1_NRdr* _Lr_1);
void _NCp1_NCompare_Prd_2(_NCp1_NCompare* _Le_0, union _NCp1_NRdr* _Lr_1);
bool _NCp1_NRdr_Pb_1(union _NCp1_NRdr* _Lr_0);
void _NCp1_NMath_Prd_2(_NCp1_NMath* _Le_0, union _NCp1_NRdr* _Lr_1);
void _NCp1_NUnary_Prd_2(_NCp1_NUnary* _Lu_0, union _NCp1_NRdr* _Lr_1);
void _NCp1_NBools_Prd_2(_NCp1_NBools* _Le_0, union _NCp1_NRdr* _Lr_1);
void _NCp1_NRdr_Pcopy_3(union _NCp1_NRdr* _Lr_0, void* _Ldata_1, int32_t _Lsize_2);
void _NCp1_NStmtSpace_Pstmt_push_7(struct _NCp1_NStmtSpace* _Ls_0, struct _NCp1_NStmt* _Ls2_1, int32_t _Lbegin_row_2, int32_t _Lbegin_col_3, int32_t _Lend_row_4, int32_t _Lend_col_5, _NCp1_NStmtType _Ltype_6);
bool _NCp1_NExprI_Pprocess_case_func_2(struct _NCp1_NExpr* _Lexpr_0, _NCp1_NFunc _Lf_idx_1);
uint8_t _NCp1_NId_Plen_1(_NCp1_NId _Lid_0);
bool _NCp1_NStmtSpace_Pprocess_1(struct _NCp1_NStmtSpace* _Lspace_0);
void _NCp1_NExprI_Ptry_deduce_2(_NCp1_NExprI _Le_idx_0, _NCp1_NAt _Lat_1);
_NCp1_NAt _NCp1_NExprI_Ptype_1(_NCp1_NExprI _Le_0);
void _NCp1_NValue_Pset_5(struct _NCp1_NValue* _Lv_0, int8_t _Lreff_1, bool _Lparen_2, _NCp1_NAt _Ltype_3, struct _NCp1_NTypeInfo* _Linfo_4);
bool _NCp1_NGvar_Pprocess_1(_NCp1_NGvar _Lg_0);
bool _NCp1_Pfarg_process_5(_NCp1_NExprI _Le_0, int8_t _Lca_ref_1, struct _NCp1_NValue* _Lca_value_2, struct _NCp1_NDeclVarData* _Lfd_arg_3, _NCp1_NAt _Lbase_at_4);
void _NCp1_NExprI_Ptry_deduce_math_2(struct _NCp1_NExpr* _Lexpr_0, _NCp1_NAt _Lat_1);
void _NCp1_NExprI_Ptry_deduce_cvar_2(struct _NCp1_NExpr* _Lexpr_0, _NCp1_NAt _Lat_1);
void _NCp1_NExprI_Ptype_assign_2(struct _NCp1_NExpr* _Lexpr_0, _NCp1_NAt* _Lat_1);
void _NCp1_NExprI_Ptype_compare_2(struct _NCp1_NExpr* _Lexpr_0, _NCp1_NAt* _Lat_1);
void _NCp1_NExprI_Ptype_bool_2(struct _NCp1_NExpr* _Lexpr_0, _NCp1_NAt* _Lat_1);
void _NCp1_NExprI_Ptype_char_2(struct _NCp1_NExpr* _Lexpr_0, _NCp1_NAt* _Lat_1);
void _NCp1_NExprI_Ptype_math_2(struct _NCp1_NExpr* _Lexpr_0, _NCp1_NAt* _Lat_1);
void _NCp1_NExprI_Ptype_unary_2(struct _NCp1_NExpr* _Lexpr_0, _NCp1_NAt* _Lat_1);
void _NCp1_NExprI_Ptype_ref_2(struct _NCp1_NExpr* _Lexpr_0, _NCp1_NAt* _Lat_1);
void _NCp1_NExprI_Ptype_cast_fast_2(struct _NCp1_NExpr* _Lexpr_0, _NCp1_NAt* _Lat_1);
void _NCp1_NExprI_Ptype_lvar_2(struct _NCp1_NExpr* _Lexpr_0, _NCp1_NAt* _Lat_1);
void _NCp1_NExprI_Ptype_fvar_2(struct _NCp1_NExpr* _Lexpr_0, _NCp1_NAt* _Lat_1);
void _NCp1_NExprI_Ptype_gvar_2(struct _NCp1_NExpr* _Lexpr_0, _NCp1_NAt* _Lat_1);
void _NCp1_NExprI_Ptype_cvar_2(struct _NCp1_NExpr* _Lexpr_0, _NCp1_NAt* _Lat_1);
void _NCp1_NExprI_Ptype_bools_2(struct _NCp1_NExpr* _Lexpr_0, _NCp1_NAt* _Lat_1);
void _NCp1_NExprI_Ptype_func_2(struct _NCp1_NExpr* _Lexpr_0, _NCp1_NAt* _Lat_1);
void _NCp1_NExprI_Ptype_method_2(struct _NCp1_NExpr* _Lexpr_0, _NCp1_NAt* _Lat_1);
void _NCp1_NExprI_Ptype_i32_2(struct _NCp1_NExpr* _Lexpr_0, _NCp1_NAt* _Lat_1);
void _NCp1_NExprI_Ptype_size_of_type_2(struct _NCp1_NExpr* _Lexpr_0, _NCp1_NAt* _Lat_1);
void _NCp1_NExprI_Ptype_null_2(struct _NCp1_NExpr* _Lexpr_0, _NCp1_NAt* _Lat_1);
void _NCp1_NExprI_Ptype_index_2(struct _NCp1_NExpr* _Lexpr_0, _NCp1_NAt* _Lat_1);
int main(int _Larg_c_0, char** _Larg_v_1) {
if(_Larg_c_0 < 3) {
fprintf(stdout, "usage: %s file.cp1-b file.c\n", _Larg_v_1[0]);
return 0;
}
if(false) {
qalloc_undo(0);
}
_NCp1_NMap_Pinit_1(&_Gid_map);
_NCp1_NMap_Pinit_1(&_Ginclude_map);
_NCp1_NAtMap_Pinit_1(&_Gat_map);
_NCp1_Pquick_alloc_init_0();
_Gfunc_main = _NCp1_NFunc_Cnil;
_NCp1_NBasicTypeId _Ltype_2;
_Ltype_2 = (_NCp1_NBasicTypeId)(0);
for(int i = _NCp1_NBasicTypeId_CCOUNT; i > 0; ) {
i --;
_NCp1_NAt _Lat_idx_3;
struct _NCp1_NAtData* _Lat_5;
_Lat_idx_3 = _Gat_c++;
if(_Gat_cap <= _Gat_c) {
_NCp1_NAt _Lold_cap_4;
_Lold_cap_4 = _Gat_cap;
_NCp1_Pgrow_2(_Gat_cap, _Gat_c);
_NCp1_Prealloc_3(_Gat_v, _Gat_cap, _Lold_cap_4);
}
_Lat_5 = (&_Gat_v[_Lat_idx_3]);
_NCp1_NAtData_Pinit_4(_Lat_5, _NCp1_NNameType_Cbasic, _NCp1_NAt_Croot, (_NCp1_NId)(_Ltype_2));
continue_0:;
_Ltype_2++;
}
break_0:;
int32_t _Li_6;
_Li_6 = 1;
for(int i = _Larg_c_0 - 2; i > 0; ) {
i --;
char* _Lin_path_7;
_Lin_path_7 = _Larg_v_1[_Li_6];
_NCp1_Pread_1(_Lin_path_7);
continue_1:;
_Li_6++;
}
break_1:;
_NCp1_NFunc _Lf_idx_8;
_Lf_idx_8 = (_NCp1_NFunc)(0);
for(int i = _Gfunc_c; i > 0; ) {
i --;
struct _NCp1_NDeclFunc* _Lf_9;
_Lf_9 = _NCp1_NFunc_Pptr_1(_Lf_idx_8);
if((*_Lf_9)._Fthis_idx != -1) {
struct _NCp1_NAtData* _Lat_10;
_Lat_10 = _NCp1_NAt_Pptr_1((*_Lf_9)._Fat);
if((*_Lat_10)._Ftype == _NCp1_NNameType_Cstruct_enum) {
if((*_Lat_10)._Fdecl._Fenum == _NCp1_NEnum_Cnil) {
fprintf(stdout, "%s:%u:%u: function using ':this' was declared on :%s which is not defined\n", _NCp1_NFile_Ppath_1((*_Lf_9)._Ffile), (*_Lf_9)._Fbegin_row, (*_Lf_9)._Fbegin_col, _NCp1_NId_Pstr_1((*_Lat_10)._Fname._Fid));
exit(_NStdc_NExit_Cfailure);
}
if((*_Lat_10)._Fdef == _NCp1_NAtDef_Cstruct) {
struct _NCp1_NStructData* _Lt_11;
int32_t _Lt_method_idx_12;
_Lt_11 = _NCp1_NStruct_Pptr_1((*_Lat_10)._Fdecl._Fstruct);
_Lt_method_idx_12 = (*_Lt_11)._Fmethod_c++;
if((*_Lt_11)._Fmethod_cap <= (*_Lt_11)._Fmethod_c) {
int32_t _Lold_cap_13;
_Lold_cap_13 = (*_Lt_11)._Fmethod_cap;
_NCp1_Pgrow_2((*_Lt_11)._Fmethod_cap, (*_Lt_11)._Fmethod_c);
_NCp1_Prealloc_3((*_Lt_11)._Fmethod_v, (*_Lt_11)._Fmethod_cap, _Lold_cap_13);
}
(*_Lt_11)._Fmethod_v[_Lt_method_idx_12] = _Lf_idx_8;
} else if((*_Lat_10)._Fdef == _NCp1_NAtDef_Cenum) {
struct _NCp1_NEnumData* _Lt_14;
int32_t _Lt_method_idx_15;
_Lt_14 = _NCp1_NEnum_Pptr_1((*_Lat_10)._Fdecl._Fenum);
_Lt_method_idx_15 = (*_Lt_14)._Fmethod_c++;
if((*_Lt_14)._Fmethod_cap <= (*_Lt_14)._Fmethod_c) {
int32_t _Lold_cap_16;
_Lold_cap_16 = (*_Lt_14)._Fmethod_cap;
_NCp1_Pgrow_2((*_Lt_14)._Fmethod_cap, (*_Lt_14)._Fmethod_c);
_NCp1_Prealloc_3((*_Lt_14)._Fmethod_v, (*_Lt_14)._Fmethod_cap, _Lold_cap_16);
}
(*_Lt_14)._Fmethod_v[_Lt_method_idx_15] = _Lf_idx_8;
} else {
fprintf(stdout, "%s:%u:%u: function using ':this' was declared on :%s which is not a struct or enum\n", _NCp1_NFile_Ppath_1((*_Lf_9)._Ffile), (*_Lf_9)._Fbegin_row, (*_Lf_9)._Fbegin_col, _NCp1_NId_Pstr_1((*_Lat_10)._Fname._Fid));
exit(_NStdc_NExit_Cfailure);
}
} else if((*_Lat_10)._Ftype == _NCp1_NNameType_Cbasic) {
struct _NCp1_NBasicType* _Lt_17;
int32_t _Lt_method_idx_18;
_Lt_17 = (&_Gbasic_type[(*_Lat_10)._Fname._Fbasic]);
_Lt_method_idx_18 = (*_Lt_17)._Fmethod_c++;
if((*_Lt_17)._Fmethod_cap <= (*_Lt_17)._Fmethod_c) {
int32_t _Lold_cap_19;
_Lold_cap_19 = (*_Lt_17)._Fmethod_cap;
_NCp1_Pgrow_2((*_Lt_17)._Fmethod_cap, (*_Lt_17)._Fmethod_c);
_NCp1_Prealloc_3((*_Lt_17)._Fmethod_v, (*_Lt_17)._Fmethod_cap, _Lold_cap_19);
}
(*_Lt_17)._Fmethod_v[_Lt_method_idx_18] = _Lf_idx_8;
} else {
fprintf(stdout, "%s:%u:%u: function using ':this' was declared on a type that:S not a struct or enum\n", _NCp1_NFile_Ppath_1((*_Lf_9)._Ffile), (*_Lf_9)._Fbegin_row, (*_Lf_9)._Fbegin_col);
exit(_NStdc_NExit_Cfailure);
}
}
continue_2:;
_Lf_idx_8++;
}
break_2:;
if(_Gfunc_main != _NCp1_NFunc_Cnil) {
struct _NCp1_NDeclFunc* _Lf_20;
_Lf_20 = _NCp1_NFunc_Pptr_1(_Gfunc_main);
(*_Lf_20)._Freal_name = _NCp1_Pid_add_2(4, "main");
(*_Lf_20)._Fflags |= _NCp1_NFuncFlags_Creal_name;
}
_NCp1_Pquick_alloc_arr_2(_Gid_c_name_v, _Gid_c);
if(true) {
_NCp1_NFunc _Lfunc_c8_21;
_Lfunc_c8_21 = ((_Gfunc_c + 7) >> 3);
_NCp1_Pquick_alloc_arr_2(_Gfunc_in_process, _Lfunc_c8_21);
_NCp1_Pquick_alloc_arr_2(_Gfunc_head_outputted_v, _Gfunc_c);
_NCp1_Pquick_alloc_arr_2(_Gfunc_body_outputted_v, _Gfunc_c);
}
if(true) {
int32_t _Linclude_c8_22;
_Linclude_c8_22 = ((_Ginclude_c + 7) >> 3);
_NCp1_Pquick_alloc_arr_2(_Ginclude_is_outputted, _Linclude_c8_22);
_NCp1_Pquick_alloc_arr_2(_Ginclude_outputted_v, _Ginclude_c);
}
if(true) {
_NCp1_NCvar _Lcvar_c8_23;
_Lcvar_c8_23 = ((_Gcvar_c + 7) >> 3);
_NCp1_Pquick_alloc_arr_2(_Gcvar_is_outputted, _Lcvar_c8_23);
_NCp1_Pquick_alloc_arr_2(_Gcvar_outputted_v, _Gcvar_c);
}
if(true) {
_NCp1_NGvar _Lgvar_c8_24;
_Lgvar_c8_24 = ((_Ggvar_c + 7) >> 3);
_NCp1_Pquick_alloc_arr_2(_Ggvar_is_outputted, _Lgvar_c8_24);
_NCp1_Pquick_alloc_arr_2(_Ggvar_outputted_v, _Ggvar_c);
}
if(true) {
_NCp1_NEnum _Lenum_c8_25;
_Lenum_c8_25 = ((_Genum_c + 7) >> 3);
_NCp1_Pquick_alloc_arr_2(_Genum_is_outputted, _Lenum_c8_25);
_NCp1_Pquick_alloc_arr_2(_Genum_outputted_v, _Genum_c);
}
if(true) {
_NCp1_NStruct _Lstruct_c8_26;
_Lstruct_c8_26 = ((_Gstruct_c + 7) >> 3);
_NCp1_Pquick_alloc_arr_2(_Gstruct_is_outputted, _Lstruct_c8_26);
_NCp1_Pquick_alloc_arr_2(_Gstruct_outputted_v, _Gstruct_c);
}
_Gprocess_first = _NCp1_NFunc_Cnil;
_Gprocess_last = _NCp1_NFunc_Cnil;
if(_Gfunc_main != _NCp1_NFunc_Cnil) {
_NCp1_NFunc_Pprocess_later_1(_Gfunc_main);
}
while(_Gprocess_first != _NCp1_NFunc_Cnil) {
_NCp1_NFunc _Lf_i_27;
_Lf_i_27 = _Gprocess_first;
_Gprocess_first = _NCp1_NFunc_Cnil;
_Gprocess_last = _NCp1_NFunc_Cnil;
while(1) {
struct _NCp1_NDeclFunc* _Lf_28;
if(!(_NCp1_NFunc_Pprocess_now_1(_Lf_i_27))) {
return -1;
}
_Lf_28 = _NCp1_NFunc_Pptr_1(_Lf_i_27);
_Lf_i_27 = (*_Lf_28)._Fprocess_next;
if(_Lf_i_27 == _NCp1_NFunc_Cnil) {
goto break_4;
}
continue_4:;
}
break_4:;
continue_3:;
}
break_3:;
int32_t _Li_29;
_Li_29 = 0;
for(int i = _Gfunc_head_outputted_c; i > 0; ) {
i --;
_NCp1_NFunc _Lf_idx_30;
struct _NCp1_NDeclFunc* _Lf_31;
_Lf_idx_30 = _Gfunc_head_outputted_v[_Li_29];
_Lf_31 = _NCp1_NFunc_Pptr_1(_Lf_idx_30);
if(((*_Lf_31)._Fflags & _NCp1_NFuncFlags_Cno_decl) != _NCp1_NFuncFlags_C0) {
goto continue_5;
}
if(((*_Lf_31)._Fflags & _NCp1_NFuncFlags_Cdecl) != _NCp1_NFuncFlags_C0) {
goto continue_5;
}
_Gctx_func = _Lf_31;
_NCp1_NLvar _Ll_32;
_Ll_32 = (_NCp1_NLvar)(0);
for(int i = (*_Lf_31)._Flvar_c; i > 0; ) {
i --;
if(!(_NCp1_NLvar_Pprocess_1(_Ll_32))) {
exit(_NStdc_NExit_Cfailure);
}
continue_6:;
_Ll_32++;
}
break_6:;
continue_5:;
_Li_29++;
}
break_5:;
_Gout = fopen(_Larg_v_1[(_Larg_c_0 - 1)], "w");
int32_t _Li_33;
_Li_33 = 0;
for(int i = _Gfunc_head_outputted_c; i > 0; ) {
i --;
_NCp1_NFunc _Lf_idx_34;
struct _NCp1_NDeclFunc* _Lf_35;
int32_t _Lrow_36;
int32_t _Lcol_37;
_Lf_idx_34 = _Gfunc_head_outputted_v[_Li_33];
_Lf_35 = _NCp1_NFunc_Pptr_1(_Lf_idx_34);
_Lrow_36 = (*_Lf_35)._Fbegin_row;
_Lcol_37 = (*_Lf_35)._Fbegin_col;
if((*_Lf_35)._Fdecl._Ftype != _NCp1_NAt_Cnil) {
_NCp1_NAt_Poutput_4((*_Lf_35)._Fdecl._Ftype, (*_Lf_35)._Ffile, _Lrow_36, _Lcol_37);
}
int32_t _Li_38;
_Li_38 = 0;
for(int i = (*_Lf_35)._Ffarg_c; i > 0; ) {
i --;
_NCp1_NAt_Poutput_4((*_Lf_35)._Ffarg_v[_Li_38]._Fdecl._Ftype, (*_Lf_35)._Ffile, _Lrow_36, _Lcol_37);
continue_8:;
_Li_38++;
}
break_8:;
if((*_Lf_35)._Finclude != _NCp1_NInclude_Cnil) {
_NCp1_NInclude_Poutput_1((*_Lf_35)._Finclude);
}
if(((*_Lf_35)._Fflags & _NCp1_NFuncFlags_Ccp1_name) != _NCp1_NFuncFlags_C0) {
struct _NCp1_NAtData* _Lat_39;
_Lat_39 = _NCp1_NAt_Pptr_1((*_Lf_35)._Fat);
int32_t _Li_40;
_NCp1_NCvar* _Lv_41;
_Li_40 = 0;
_Lv_41 = (*_Lat_39)._Fcvar_v;
for(int i = (*_Lat_39)._Fcvar_c; i > 0; ) {
i --;
_NCp1_NCvar _Lcvar_42;
_Lcvar_42 = _Lv_41[_Li_40];
if(((*_NCp1_NCvar_Pptr_1(_Lcvar_42))._Fflags & _NCp1_NCvarFlags_Cas_enum) != _NCp1_NCvarFlags_C0) {
_NCp1_NCvar_Pprocess_1(_Lcvar_42);
}
continue_9:;
_Li_40++;
}
break_9:;
}
continue_7:;
_Li_33++;
}
break_7:;
if(_Ginclude_stdint) {
fprintf(_Gout, "#include <stdint.h>\n");
}
if(_Ginclude_stdbool) {
fprintf(_Gout, "#include <stdbool.h>\n");
}
if(_Ginclude_stddef) {
fprintf(_Gout, "#include <stddef.h>\n");
}
int32_t _Li_43;
_Li_43 = 0;
for(int i = _Ginclude_outputted_c; i > 0; ) {
i --;
_NCp1_NInclude _Linc_44;
_Linc_44 = _Ginclude_outputted_v[_Li_43];
fprintf(_Gout, "#include %s\n", _NCp1_NInclude_Pstr_1(_Linc_44));
continue_10:;
_Li_43++;
}
break_10:;
int32_t _Li_45;
_Li_45 = 0;
for(int i = _Gcvar_outputted_c; i > 0; ) {
i --;
_NCp1_NCvar _Lc_i_46;
struct _NCp1_NCvarData* _Lc_47;
_Lc_i_46 = _Gcvar_outputted_v[_Li_45];
_Lc_47 = _NCp1_NCvar_Pptr_1(_Lc_i_46);
if(((*_Lc_47)._Fdecl._Fflags & _NCp1_NVarFlags_Cno_decl) != _NCp1_NVarFlags_C0) {
goto continue_11;
}
fprintf(_Gout, "#define ");
_NCp1_NCvar_Pwrite_1(_Lc_i_46);
fprintf(_Gout, " ");
if(((*_Lc_47)._Fflags & _NCp1_NCvarFlags_Cset_expr) != _NCp1_NCvarFlags_C0) {
fprintf(_Gout, "(");
_NCp1_NExprI_Pwrite_1((*_Lc_47)._Fexpr_set);
fprintf(_Gout, ")");
} else if((*_Lc_47)._Flast_cvar != _NCp1_NCvar_Cnil) {
fprintf(_Gout, "(");
_NCp1_NCvar_Pwrite_1((*_Lc_47)._Flast_cvar);
fprintf(_Gout, " + 1)");
} else {
fprintf(_Gout, "0");
}
fprintf(_Gout, "\n");
continue_11:;
_Li_45++;
}
break_11:;
int32_t _Li_48;
_Li_48 = 0;
for(int i = _Genum_outputted_c; i > 0; ) {
i --;
_NCp1_NEnum _Le_i_49;
struct _NCp1_NEnumData* _Le_50;
_Le_i_49 = _Genum_outputted_v[_Li_48];
_Le_50 = _NCp1_NEnum_Pptr_1(_Le_i_49);
fprintf(_Gout, "typedef ");
_NCp1_NAt_Pwrite_1((*_Le_50)._Fbase_type);
fprintf(_Gout, " ");
_NCp1_NAt_Pwrite_1((*_Le_50)._Fat);
fprintf(_Gout, ";\n");
continue_12:;
_Li_48++;
}
break_12:;
int32_t _Li_51;
_Li_51 = 0;
for(int i = _Gstruct_outputted_c; i > 0; ) {
i --;
_NCp1_NStruct _Ls_i_52;
struct _NCp1_NStructData* _Ls_53;
_Ls_i_52 = _Gstruct_outputted_v[_Li_51];
_Ls_53 = _NCp1_NStruct_Pptr_1(_Ls_i_52);
if(((*_Ls_53)._Fflags & _NCp1_NStructFlags_Cunion) != _NCp1_NStructFlags_C0) {
fprintf(_Gout, "union ");
} else {
fprintf(_Gout, "struct ");
}
_NCp1_NAt_Pwrite_space_1((*_Ls_53)._Fat);
if(((*_Ls_53)._Fflags & _NCp1_NStructFlags_Cunion) != _NCp1_NStructFlags_C0) {
fprintf(_Gout, ";\nunion ");
} else {
fprintf(_Gout, ";\nstruct ");
}
_NCp1_NAt_Pwrite_space_1((*_Ls_53)._Fat);
fprintf(_Gout, " {\n");
int32_t _Lj_54;
_Lj_54 = 0;
for(int i = (*_Ls_53)._Ffvar_c; i > 0; ) {
i --;
struct _NCp1_NFvarData* _Lfvar_55;
_Lfvar_55 = (&(*_Ls_53)._Ffvar_v[_Lj_54]);
_NCp1_NDeclVarData_Pwrite_type_2(&(*_Lfvar_55)._Fdecl, _NCp1_NDeclVarType_Cfvar);
fprintf(_Gout, ";\n");
continue_14:;
_Lj_54++;
}
break_14:;
fprintf(_Gout, "};\n");
continue_13:;
_Li_51++;
}
break_13:;
int32_t _Li_56;
_Li_56 = 0;
for(int i = _Ggvar_outputted_c; i > 0; ) {
i --;
_NCp1_NGvar _Lg_i_57;
struct _NCp1_NDeclGvar* _Lg_58;
_Lg_i_57 = _Ggvar_outputted_v[_Li_56];
_Lg_58 = _NCp1_NGvar_Pptr_1(_Lg_i_57);
if(((*_Lg_58)._Fdecl._Fflags & _NCp1_NVarFlags_Cno_decl) != _NCp1_NVarFlags_C0) {
goto continue_15;
}
if(((*_Lg_58)._Fdecl._Fflags & _NCp1_NVarFlags_Cextern) != _NCp1_NVarFlags_C0) {
fprintf(_Gout, "extern ");
}
_NCp1_NDeclVarData_Pwrite_type_2(&(*_Lg_58)._Fdecl, _NCp1_NDeclVarType_Cgvar);
fprintf(_Gout, ";\n");
continue_15:;
_Li_56++;
}
break_15:;
int32_t _Li_59;
_Li_59 = 0;
for(int i = _Gfunc_head_outputted_c; i > 0; ) {
i --;
_NCp1_NFunc _Lf_idx_60;
struct _NCp1_NDeclFunc* _Lf_61;
_Lf_idx_60 = _Gfunc_head_outputted_v[_Li_59];
_Lf_61 = _NCp1_NFunc_Pptr_1(_Lf_idx_60);
if(((*_Lf_61)._Fflags & _NCp1_NFuncFlags_Cno_decl) != _NCp1_NFuncFlags_C0) {
goto continue_16;
}
if(((*_Lf_61)._Fflags & _NCp1_NFuncFlags_Cdecl) != _NCp1_NFuncFlags_C0) {
if((((*_Lf_61)._Fdecl_str[0] == '#') && ((*_Lf_61)._Fdecl_str[1] == ' '))) {
fprintf(_Gout, "#define ");
_NCp1_NDeclFunc_Pwrite_1(_Lf_61);
fprintf(_Gout, "(");
int32_t _Lj_62;
_Lj_62 = 0;
for(int i = (*_Lf_61)._Ffarg_c; i > 0; ) {
i --;
if(_Lj_62 != 0) {
fprintf(_Gout, ", ");
}
fprintf(_Gout, "%s", _NCp1_NId_Pstr_1((*_Lf_61)._Ffarg_v[_Lj_62]._Fdecl._Fname));
continue_17:;
_Lj_62++;
}
break_17:;
fprintf(_Gout, ") ");
fprintf(_Gout, "%.*s\n", (*_Lf_61)._Fdecl_len - 2, &(*_Lf_61)._Fdecl_str[2]);
} else {
fprintf(_Gout, "%.*s\n", (*_Lf_61)._Fdecl_len, (*_Lf_61)._Fdecl_str);
}
goto continue_16;
}
_Gctx_func = _Lf_61;
if((*_Lf_61)._Fdecl._Ftype == _NCp1_NAt_Cnil) {
fprintf(_Gout, "void");
} else {
_NCp1_NAt_Pwrite_type_info_3((*_Lf_61)._Fdecl._Ftype, &(*_Lf_61)._Fdecl._Ftype_info, 0);
}
fprintf(_Gout, " ");
_NCp1_NDeclFunc_Pwrite_1(_Lf_61);
fprintf(_Gout, "(");
int32_t _Lj_63;
_Lj_63 = 0;
for(int i = (*_Lf_61)._Ffarg_c; i > 0; ) {
i --;
if(_Lj_63 != 0) {
fprintf(_Gout, ", ");
}
_NCp1_NDeclVarData_Pwrite_lvar_type_2(&(*_Lf_61)._Ffarg_v[_Lj_63]._Fdecl, (_NCp1_NLvar)(_Lj_63));
continue_18:;
_Lj_63++;
}
break_18:;
if(((*_Lf_61)._Fflags & _NCp1_NFuncFlags_Ccp1_name) != _NCp1_NFuncFlags_C0) {
struct _NCp1_NAtData* _Lat_64;
fprintf(_Gout, ") {\nswitch(_Le_0) {\n");
_Lat_64 = _NCp1_NAt_Pptr_1((*_Lf_61)._Fat);
int32_t _Li_65;
_NCp1_NCvar* _Lv_66;
_Li_65 = 0;
_Lv_66 = (*_Lat_64)._Fcvar_v;
for(int i = (*_Lat_64)._Fcvar_c; i > 0; ) {
i --;
_NCp1_NCvar _Lcvar_i_67;
struct _NCp1_NCvarData* _Lcvar_68;
_Lcvar_i_67 = _Lv_66[_Li_65];
_Lcvar_68 = _NCp1_NCvar_Pptr_1(_Lcvar_i_67);
if(((*_Lcvar_68)._Fflags & _NCp1_NCvarFlags_Cas_enum) == _NCp1_NCvarFlags_C0) {
goto continue_19;
}
fprintf(_Gout, "case ");
_NCp1_NCvar_Pwrite_1(_Lcvar_i_67);
fprintf(_Gout, ": return \"%s\";\n", _NCp1_NId_Pstr_1((*_Lcvar_68)._Fdecl._Fname));
continue_19:;
_Li_65++;
}
break_19:;
fprintf(_Gout, "}\nreturn \"(ERROR)\";\n}\n");
} else {
fprintf(_Gout, ");\n");
}
continue_16:;
_Li_59++;
}
break_16:;
int32_t _Li_69;
_Li_69 = 0;
for(int i = _Gfunc_body_outputted_c; i > 0; ) {
i --;
_NCp1_NFunc _Lf_idx_70;
struct _NCp1_NDeclFunc* _Lf_71;
_Lf_idx_70 = _Gfunc_body_outputted_v[_Li_69];
_Lf_71 = _NCp1_NFunc_Pptr_1(_Lf_idx_70);
_Gctx_func = _Lf_71;
_Gnest_id = 0;
if((*_Lf_71)._Fflags & _NCp1_NFuncFlags_Cinline) {
fprintf(_Gout, "inline ");
}
if((*_Lf_71)._Fdecl._Ftype == _NCp1_NAt_Cnil) {
fprintf(_Gout, "void");
} else {
_NCp1_NAt_Pwrite_type_info_3((*_Lf_71)._Fdecl._Ftype, &(*_Lf_71)._Fdecl._Ftype_info, 0);
}
fprintf(_Gout, " ");
_NCp1_NDeclFunc_Pwrite_1(_Lf_71);
fprintf(_Gout, "(");
int32_t _Lj_72;
_Lj_72 = 0;
for(int i = (*_Lf_71)._Ffarg_c; i > 0; ) {
i --;
if(_Lj_72 != 0) {
fprintf(_Gout, ", ");
}
_NCp1_NDeclVarData_Pwrite_lvar_type_2(&(*_Lf_71)._Ffarg_v[_Lj_72]._Fdecl, (_NCp1_NLvar)(_Lj_72));
continue_21:;
_Lj_72++;
}
break_21:;
fprintf(_Gout, ") {\n");
_NCp1_NStmtSpace_Pwrite_1(&(*_Lf_71)._Fstmt_space);
fprintf(_Gout, "}\n");
continue_20:;
_Li_69++;
}
break_20:;
return 0;
}
void qalloc_undo(int32_t _Lsize_0) {
if(sizeof(void*) == 8) {
_Lsize_0 = ((_Lsize_0 + 7) & (-1 ^ 7));
} else {
_Lsize_0 = ((_Lsize_0 + 3) & (-1 ^ 3));
}
_Gquick_alloc_c -= _Lsize_0;
}
void _NCp1_Pquick_alloc_init_0() {
_Gquick_alloc_cap = (16 * 1024);
_Gquick_alloc_v = malloc(_Gquick_alloc_cap);
memset(_Gquick_alloc_v, 0, _Gquick_alloc_cap);
}
void _NCp1_NAtData_Pinit_4(struct _NCp1_NAtData* _Lat_0, _NCp1_NNameType _Ltype_1, _NCp1_NAt _Lparent_2, _NCp1_NId _Lname_3) {
(*_Lat_0)._Ftype = _Ltype_1;
(*_Lat_0)._Fparent = _Lparent_2;
(*_Lat_0)._Fname._Fid = _Lname_3;
(*_Lat_0)._Ffunc_c = 0;
(*_Lat_0)._Ffunc_cap = 0;
(*_Lat_0)._Ffunc_v = NULL;
(*_Lat_0)._Fgvar_c = 0;
(*_Lat_0)._Fgvar_cap = 0;
(*_Lat_0)._Fgvar_v = NULL;
(*_Lat_0)._Fdecl._Fstruct = _NCp1_NStruct_Cnil;
(*_Lat_0)._Fdef = _NCp1_NAtDef_Cundefined;
}
void _NCp1_Pread_1(char* _Lin_path_0) {
_NStdc_NFd _Lin_fd_1;
size_t _Lin_size_2;
union _NCp1_NRdr _Lr_begin_3;
_NCp1_NFile _Lfile_idx_4;
struct _NCp1_NFileData* _Lfile_6;
union _NCp1_NRdr _Lr_7;
_NCp1_NEnum _Lenum_c_48;
_NCp1_NEnum _Le_idx_begin_49;
_NCp1_NStruct _Lstruct_c_55;
_NCp1_NStruct _Ls_idx_begin_56;
_NCp1_NFunc _Lfunc_c_65;
_NCp1_NFunc _Lf_idx_begin_66;
_NCp1_NFunc _Lfunc_main_82;
if(!(_NStdc_NFd_Popen_3(&_Lin_fd_1, _Lin_path_0, O_RDONLY))) {
fprintf(stdout, "Cannot open file for reading: %s\n", _Lin_path_0);
exit(_NStdc_NExit_Cfailure);
}
_Lin_size_2 = lseek(_Lin_fd_1, 0, SEEK_END);
if(_Lin_size_2 == 0) {
sleep(1);
_Lin_size_2 = lseek(_Lin_fd_1, 0, SEEK_END);
if(_Lin_size_2 == 0) {
fprintf(stdout, "Error, file is blank (zero bytes): %s\n", _Lin_path_0);
exit(_NStdc_NExit_Cfailure);
}
}
_Lr_begin_3._Freff = malloc(_Lin_size_2);
lseek(_Lin_fd_1, 0, SEEK_SET);
read(_Lin_fd_1, _Lr_begin_3._Freff, _Lin_size_2);
_NStdc_NFd_Pclose_1(_Lin_fd_1);
_Lfile_idx_4 = _Gfile_c++;
if(_Gfile_cap <= _Gfile_c) {
_NCp1_NFile _Lold_cap_5;
_Lold_cap_5 = _Gfile_cap;
_NCp1_Pgrow_2(_Gfile_cap, _Gfile_c);
_NCp1_Prealloc_3(_Gfile_v, _Gfile_cap, _Lold_cap_5);
}
_Lfile_6 = (&_Gfile_v[_Lfile_idx_4]);
(*_Lfile_6)._Fpath = _Lin_path_0;
(*_Lfile_6)._Fdata = _Lr_begin_3._Freff;
_Lr_7._Freff = _Lr_begin_3._Freff;
if(true) {
uint32_t _Lid_c_8;
_Lid_c_8 = Fgetnum(&_Lr_7);
_NCp1_Pquick_alloc_arr_2(_Gid_table, _Lid_c_8);
(*_Lfile_6)._Fid_table = _Gid_table;
int32_t _Li_9;
_Li_9 = 0;
for(int i = _Lid_c_8; i > 0; ) {
i --;
uint8_t _Lid_len_10;
char* _Lid_str_11;
_Lid_len_10 = _NCp1_NRdr_Pn1_1(&_Lr_7);
_Lid_str_11 = _Lr_7._Fcharr;
_Lr_7._Fpos += (_Lid_len_10 + 1);
_Gid_table[_Li_9] = _NCp1_Pid_add_2(_Lid_len_10, _Lid_str_11);
continue_0:;
_Li_9++;
}
break_0:;
}
if(true) {
uint32_t _Linclude_c_12;
_Linclude_c_12 = Fgetnum(&_Lr_7);
if(_Ginclude_table_cap <= _Linclude_c_12) {
int32_t _Lold_cap_13;
_Lold_cap_13 = _Ginclude_table_cap;
_NCp1_Pgrow_2(_Ginclude_table_cap, _Linclude_c_12);
_NCp1_Prealloc_3(_Ginclude_table, _Ginclude_table_cap, _Lold_cap_13);
}
int32_t _Li_14;
_Li_14 = 0;
for(int i = _Linclude_c_12; i > 0; ) {
i --;
uint8_t _Linclude_len_15;
void* _Linclude_str_16;
int32_t _Lfound_17;
_Linclude_len_15 = _NCp1_NRdr_Pn1_1(&_Lr_7);
_Linclude_str_16 = _Lr_7._Freff;
_Lr_7._Fpos += (_Linclude_len_15 + 1);
_Lfound_17 = _NCp1_NMap_Pget_or_insert_4(&_Ginclude_map, _Linclude_str_16, _Linclude_len_15, _Ginclude_c);
if(_Lfound_17 == -1) {
int32_t _Linclude_idx_18;
_Linclude_idx_18 = _Ginclude_c++;
if(_Ginclude_cap <= _Ginclude_c) {
int32_t _Lold_cap_19;
_Lold_cap_19 = _Ginclude_cap;
_NCp1_Pgrow_2(_Ginclude_cap, _Ginclude_c);
_NCp1_Prealloc_3(_Ginclude_len_v, _Ginclude_cap, _Lold_cap_19);
_NCp1_Prealloc_3(_Ginclude_str_v, _Ginclude_cap, _Lold_cap_19);
}
_Ginclude_len_v[_Linclude_idx_18] = _Linclude_len_15;
_Ginclude_str_v[_Linclude_idx_18] = _Linclude_str_16;
_Ginclude_table[_Li_14] = (_NCp1_NInclude)(_Linclude_idx_18);
} else {
_Ginclude_table[_Li_14] = (_NCp1_NInclude)(_Lfound_17);
}
continue_1:;
_Li_14++;
}
break_1:;
}
if(true) {
uint32_t _Lat_c_20;
_NCp1_NNameType _Lat_type_21;
_Lat_c_20 = Fgetnum(&_Lr_7);
_NCp1_Pquick_alloc_arr_2(_Gat_table, _Lat_c_20);
(*_Lfile_6)._Fat_table = _Gat_table;
int32_t _Li_22;
_Li_22 = 0;
for(int i = _Lat_c_20; i > 0; ) {
i --;
_NCp1_NNameType_Prd_2(&_Lat_type_21, &_Lr_7);
if(_Lat_type_21 == _NCp1_NNameType_Cbasic) {
_NCp1_NBasicTypeId _Lbasic_23;
_NCp1_NBasicTypeId_Prd_2(&_Lbasic_23, &_Lr_7);
_Gat_table[_Li_22] = _NCp1_Pbasic_type_1(_Lbasic_23);
} else {
_NCp1_NAt _Lat_parent_24;
_NCp1_NId _Lat_name_25;
int32_t _Lfound_26;
_NCp1_NAt_Prd_2(&_Lat_parent_24, &_Lr_7);
_NCp1_NId_Prd_2(&_Lat_name_25, &_Lr_7);
_Lfound_26 = _NCp1_NAtMap_Pget_or_insert_5(&_Gat_map, _Lat_parent_24, _Lat_type_21, _Lat_name_25, _Gat_c);
if(_Lfound_26 == -1) {
_NCp1_NAt _Lat_idx_27;
struct _NCp1_NAtData* _Lat_29;
_Lat_idx_27 = _Gat_c++;
if(_Gat_cap <= _Gat_c) {
_NCp1_NAt _Lold_cap_28;
_Lold_cap_28 = _Gat_cap;
_NCp1_Pgrow_2(_Gat_cap, _Gat_c);
_NCp1_Prealloc_3(_Gat_v, _Gat_cap, _Lold_cap_28);
}
_Lat_29 = (&_Gat_v[_Lat_idx_27]);
_NCp1_NAtData_Pinit_4(_Lat_29, _Lat_type_21, _Lat_parent_24, _Lat_name_25);
_Gat_table[_Li_22] = (_NCp1_NAt)(_Lat_idx_27);
} else {
_Gat_table[_Li_22] = (_NCp1_NAt)(_Lfound_26);
}
}
continue_2:;
_Li_22++;
}
break_2:;
}
if(true) {
_NCp1_NCvar _Lcvar_c_30;
_NCp1_NCvar _Lcvar_begin_31;
_Lcvar_c_30 = (_NCp1_NCvar)(Fgetnum(&_Lr_7));
_NCp1_Pquick_alloc_arr_2(_Gcvar_table, _Lcvar_c_30);
(*_Lfile_6)._Fcvar_table = _Gcvar_table;
fflush(stdout);
_Lcvar_begin_31 = _Gcvar_c;
_Gcvar_c += _Lcvar_c_30;
if(_Gcvar_cap <= _Gcvar_c) {
_NCp1_NCvar _Lold_cap_32;
_Lold_cap_32 = _Gcvar_cap;
_NCp1_Pgrow_2(_Gcvar_cap, _Gcvar_c);
_NCp1_Prealloc_3(_Gcvar_v, _Gcvar_cap, _Lold_cap_32);
}
_NCp1_NCvar _Lcvar_idx_33;
int32_t _Li_34;
_Lcvar_idx_33 = _Lcvar_begin_31;
_Li_34 = 0;
for(int i = _Lcvar_c_30; i > 0; ) {
i --;
struct _NCp1_NCvarData* _Lcvar_35;
struct _NCp1_NAtData* _Lat_36;
int32_t _Lat_cvar_idx_37;
_Lcvar_35 = (&_Gcvar_v[_Lcvar_idx_33]);
(*_Lcvar_35)._Ffile = _Lfile_idx_4;
_NCp1_NInclude_Prd_2(&(*_Lcvar_35)._Finclude, &_Lr_7);
_NCp1_NAt_Prd_2(&(*_Lcvar_35)._Fat, &_Lr_7);
_NCp1_NDeclVarData_Prd_2(&(*_Lcvar_35)._Fdecl, &_Lr_7);
_NCp1_NCvarFlags_Prd_2(&(*_Lcvar_35)._Fflags, &_Lr_7);
_Lat_36 = _NCp1_NAt_Pptr_1((*_Lcvar_35)._Fat);
_Lat_cvar_idx_37 = (*_Lat_36)._Fcvar_c++;
if((*_Lat_36)._Fcvar_cap <= (*_Lat_36)._Fcvar_c) {
int32_t _Lold_cap_38;
_Lold_cap_38 = (*_Lat_36)._Fcvar_cap;
_NCp1_Pgrow_2((*_Lat_36)._Fcvar_cap, (*_Lat_36)._Fcvar_c);
_NCp1_Prealloc_3((*_Lat_36)._Fcvar_v, (*_Lat_36)._Fcvar_cap, _Lold_cap_38);
}
(*_Lat_36)._Fcvar_v[_Lat_cvar_idx_37] = _Lcvar_idx_33;
if(((*_Lcvar_35)._Fflags & _NCp1_NCvarFlags_Cset_expr) != _NCp1_NCvarFlags_C0) {
_NCp1_NExprI_Prd_2(&(*_Lcvar_35)._Fexpr_set, &_Lr_7);
} else {
_NCp1_NCvar_Prd_2(&(*_Lcvar_35)._Flast_cvar, &_Lr_7);
}
_Gcvar_table[_Li_34] = _Lcvar_idx_33;
continue_3:;
_Lcvar_idx_33++;
_Li_34++;
}
break_3:;
}
if(true) {
_NCp1_NGvar _Lgvar_c_39;
_NCp1_NGvar _Lgvar_begin_40;
_Lgvar_c_39 = (_NCp1_NGvar)(Fgetnum(&_Lr_7));
fflush(stdout);
_Lgvar_begin_40 = _Ggvar_c;
_Ggvar_c += _Lgvar_c_39;
if(_Ggvar_cap <= _Ggvar_c) {
_NCp1_NGvar _Lold_cap_41;
_Lold_cap_41 = _Ggvar_cap;
_NCp1_Pgrow_2(_Ggvar_cap, _Ggvar_c);
_NCp1_Prealloc_3(_Ggvar_v, _Ggvar_cap, _Lold_cap_41);
}
_NCp1_NGvar _Lgvar_idx_42;
int32_t _Li_43;
_Lgvar_idx_42 = _Lgvar_begin_40;
_Li_43 = 0;
for(int i = _Lgvar_c_39; i > 0; ) {
i --;
struct _NCp1_NDeclGvar* _Lgvar_44;
struct _NCp1_NAtData* _Lat_45;
int32_t _Lat_gvar_idx_46;
_Lgvar_44 = (&_Ggvar_v[_Lgvar_idx_42]);
_NCp1_NInclude_Prd_2(&(*_Lgvar_44)._Finclude, &_Lr_7);
_NCp1_NAt_Prd_2(&(*_Lgvar_44)._Fat, &_Lr_7);
_NCp1_NDeclVarData_Prd_2(&(*_Lgvar_44)._Fdecl, &_Lr_7);
_Lat_45 = _NCp1_NAt_Pptr_1((*_Lgvar_44)._Fat);
_Lat_gvar_idx_46 = (*_Lat_45)._Fgvar_c++;
if((*_Lat_45)._Fgvar_cap <= (*_Lat_45)._Fgvar_c) {
int32_t _Lold_cap_47;
_Lold_cap_47 = (*_Lat_45)._Fgvar_cap;
_NCp1_Pgrow_2((*_Lat_45)._Fgvar_cap, (*_Lat_45)._Fgvar_c);
_NCp1_Prealloc_3((*_Lat_45)._Fgvar_v, (*_Lat_45)._Fgvar_cap, _Lold_cap_47);
}
(*_Lat_45)._Fgvar_v[_Lat_gvar_idx_46] = _Lgvar_idx_42;
continue_4:;
_Lgvar_idx_42++;
_Li_43++;
}
break_4:;
}
_Lenum_c_48 = (_NCp1_NEnum)(Fgetnum(&_Lr_7));
fflush(stdout);
_Le_idx_begin_49 = _Genum_c;
_Genum_c += _Lenum_c_48;
if(_Genum_cap <= _Genum_c) {
_NCp1_NEnum _Lold_cap_50;
_Lold_cap_50 = _Genum_cap;
_NCp1_Pgrow_2(_Genum_cap, _Genum_c);
_NCp1_Prealloc_3(_Genum_v, _Genum_cap, _Lold_cap_50);
}
_NCp1_NEnum _Le_idx_51;
_Le_idx_51 = _Le_idx_begin_49;
for(int i = _Lenum_c_48; i > 0; ) {
i --;
struct _NCp1_NEnumData* _Le_52;
_NCp1_NAt _Lat_i_53;
struct _NCp1_NAtData* _Lat_54;
_NCp1_Pquick_alloc_one_1(_Le_52);
_Genum_v[_Le_idx_51] = _Le_52;
(*_Le_52)._Ffile = _Lfile_idx_4;
(*_Le_52)._Fbegin_row = Fgetnum(&_Lr_7);
(*_Le_52)._Fbegin_col = Fgetnum(&_Lr_7);
(*_Le_52)._Fend_row = Fgetnum(&_Lr_7);
(*_Le_52)._Fend_col = Fgetnum(&_Lr_7);
_NCp1_NInclude_Prd_2(&(*_Le_52)._Finclude, &_Lr_7);
_NCp1_NAt_Prd_2(&(*_Le_52)._Fat, &_Lr_7);
_NCp1_NAt_Prd_2(&(*_Le_52)._Fbase_type, &_Lr_7);
_NCp1_NEnumFlags_Prd_2(&(*_Le_52)._Fflags, &_Lr_7);
_Lat_i_53 = (*_Le_52)._Fat;
_Lat_54 = _NCp1_NAt_Pptr_1(_Lat_i_53);
if((*_Lat_54)._Fdef != _NCp1_NAtDef_Cundefined) {
fprintf(stdout, "Cannot define struct :%s because it was already defined as ", _NCp1_NId_Pstr_1((*_Lat_54)._Fname._Fid));
if((*_Lat_54)._Fdef == _NCp1_NAtDef_Cstruct) {
fprintf(stdout, "struct\n");
}
}
(*_Lat_54)._Fdecl._Fenum = _Le_idx_51;
(*_Lat_54)._Fdef = _NCp1_NAtDef_Cenum;
if(((*_Le_52)._Fflags & _NCp1_NEnumFlags_Creal_name) != _NCp1_NEnumFlags_C0) {
_NCp1_NId_Prd_2(&(*_Le_52)._Freal_name, &_Lr_7);
} else {
(*_Le_52)._Freal_name = _NCp1_NId_Cnil;
}
continue_5:;
_Le_idx_51++;
}
break_5:;
_Lstruct_c_55 = (_NCp1_NStruct)(Fgetnum(&_Lr_7));
_Ls_idx_begin_56 = _Gstruct_c;
_Gstruct_c += _Lstruct_c_55;
if(_Gstruct_cap <= _Gstruct_c) {
_NCp1_NStruct _Lold_cap_57;
_Lold_cap_57 = _Gstruct_cap;
_NCp1_Pgrow_2(_Gstruct_cap, _Gstruct_c);
_NCp1_Prealloc_3(_Gstruct_v, _Gstruct_cap, _Lold_cap_57);
}
_NCp1_NStruct _Ls_idx_58;
_Ls_idx_58 = _Ls_idx_begin_56;
for(int i = _Lstruct_c_55; i > 0; ) {
i --;
uint8_t _Lfvar_c_59;
struct _NCp1_NStructData* _Ls_60;
_NCp1_NAt _Lat_i_61;
struct _NCp1_NAtData* _Lat_62;
_Lfvar_c_59 = _NCp1_NRdr_Pn1_1(&_Lr_7);
_NCp1_Pquick_alloc_plus_2(_Ls_60, sizeof(struct _NCp1_NFvarData) * _Lfvar_c_59);
_Gstruct_v[_Ls_idx_58] = _Ls_60;
(*_Ls_60)._Ffile = _Lfile_idx_4;
(*_Ls_60)._Ffvar_c = _Lfvar_c_59;
(*_Ls_60)._Fbegin_row = Fgetnum(&_Lr_7);
(*_Ls_60)._Fbegin_col = Fgetnum(&_Lr_7);
(*_Ls_60)._Fend_row = Fgetnum(&_Lr_7);
(*_Ls_60)._Fend_col = Fgetnum(&_Lr_7);
_NCp1_NInclude_Prd_2(&(*_Ls_60)._Finclude, &_Lr_7);
_NCp1_NAt_Prd_2(&(*_Ls_60)._Fat, &_Lr_7);
_NCp1_NStructFlags_Prd_2(&(*_Ls_60)._Fflags, &_Lr_7);
_Lat_i_61 = (*_Ls_60)._Fat;
_Lat_62 = _NCp1_NAt_Pptr_1(_Lat_i_61);
if((*_Lat_62)._Fdef != _NCp1_NAtDef_Cundefined) {
fprintf(stdout, "Cannot define struct :%s because it was already defined as ", _NCp1_NId_Pstr_1((*_Lat_62)._Fname._Fid));
if((*_Lat_62)._Fdef == _NCp1_NAtDef_Cenum) {
fprintf(stdout, "enum\n");
}
}
(*_Lat_62)._Fdecl._Fstruct = _Ls_idx_58;
(*_Lat_62)._Fdef = _NCp1_NAtDef_Cstruct;
int32_t _Lj_63;
_Lj_63 = 0;
for(int i = _Lfvar_c_59; i > 0; ) {
i --;
struct _NCp1_NFvarData* _Lfvar_64;
_Lfvar_64 = (&(*_Ls_60)._Ffvar_v[_Lj_63]);
_NCp1_NDeclVarData_Prd_2(&(*_Lfvar_64)._Fdecl, &_Lr_7);
continue_7:;
_Lj_63++;
}
break_7:;
if(((*_Ls_60)._Fflags & _NCp1_NStructFlags_Creal_name) != _NCp1_NStructFlags_C0) {
_NCp1_NId_Prd_2(&(*_Ls_60)._Freal_name, &_Lr_7);
} else {
(*_Ls_60)._Freal_name = _NCp1_NId_Cnil;
}
continue_6:;
_Ls_idx_58++;
}
break_6:;
_Lfunc_c_65 = (_NCp1_NFunc)(Fgetnum(&_Lr_7));
fflush(stdout);
_Lf_idx_begin_66 = _Gfunc_c;
_Gfunc_c += _Lfunc_c_65;
if(_Gfunc_cap <= _Gfunc_c) {
_NCp1_NFunc _Lold_cap_67;
_Lold_cap_67 = _Gfunc_cap;
_NCp1_Pgrow_2(_Gfunc_cap, _Gfunc_c);
_NCp1_Prealloc_3(_Gfunc_v, _Gfunc_cap, _Lold_cap_67);
}
_NCp1_NFunc _Lf_idx_68;
_Lf_idx_68 = _Lf_idx_begin_66;
for(int i = _Lfunc_c_65; i > 0; ) {
i --;
uint8_t _Lfarg_c_69;
struct _NCp1_NDeclFunc* _Lf_70;
_NCp1_NAt _Lat_i_71;
union _NCp1_NRdr _Lr0_72;
int8_t _Lthis_idx_75;
uint8_t _Lgroup_c_76;
struct _NCp1_NAtData* _Lat_79;
int32_t _Lat_func_idx_80;
_Lfarg_c_69 = _NCp1_NRdr_Pn1_1(&_Lr_7);
_NCp1_Pquick_alloc_plus_2(_Lf_70, sizeof(struct _NCp1_NFarg) * _Lfarg_c_69);
_Gfunc_v[_Lf_idx_68] = _Lf_70;
(*_Lf_70)._Ffarg_c = _Lfarg_c_69;
(*_Lf_70)._Ffile = _Lfile_idx_4;
(*_Lf_70)._Fbegin_row = Fgetnum(&_Lr_7);
(*_Lf_70)._Fbegin_col = Fgetnum(&_Lr_7);
(*_Lf_70)._Fend_row = Fgetnum(&_Lr_7);
(*_Lf_70)._Fend_col = Fgetnum(&_Lr_7);
_NCp1_NInclude_Prd_2(&(*_Lf_70)._Finclude, &_Lr_7);
_NCp1_NAt_Prd_2(&(*_Lf_70)._Fat, &_Lr_7);
_Lat_i_71 = (*_Lf_70)._Fat;
_NCp1_NDeclVarData_Prd_2(&(*_Lf_70)._Fdecl, &_Lr_7);
_Lr0_72._Freff = _Lf_70;
(*_Lf_70)._Flvar_c = _NCp1_NLvar_C0;
_Gctx_func = _Lf_70;
_Gctx_func_id = _Lf_idx_68;
int32_t _Lj_73;
_Lj_73 = 0;
for(int i = _Lfarg_c_69; i > 0; ) {
i --;
struct _NCp1_NFarg* _Lfarg_74;
_Lfarg_74 = (&(*_Lf_70)._Ffarg_v[_Lj_73]);
_NCp1_NFarg_Prd_2(_Lfarg_74, &_Lr_7);
continue_9:;
_Lj_73++;
}
break_9:;
_Lthis_idx_75 = (int8_t)(_NCp1_NRdr_Pn1_1(&_Lr_7));
(*_Lf_70)._Fthis_idx = _Lthis_idx_75;
if(_Lthis_idx_75 != -1) {
(*_Lf_70)._Fthis_group = _NCp1_NRdr_Pn1_1(&_Lr_7);
}
_Lgroup_c_76 = _NCp1_NRdr_Pn1_1(&_Lr_7);
(*_Lf_70)._Fgroup_c = _Lgroup_c_76;
int32_t _Li_77;
_Li_77 = 0;
for(int i = _Lgroup_c_76; i > 0; ) {
i --;
(*_Lf_70)._Fgroup_v[_Li_77] = _NCp1_NRdr_Pn1_1(&_Lr_7);
continue_10:;
_Li_77++;
}
break_10:;
_NCp1_NFuncFlags_Prd_2(&(*_Lf_70)._Fflags, &_Lr_7);
if(((*_Lf_70)._Fflags & _NCp1_NFuncFlags_Creal_name) != _NCp1_NFuncFlags_C0) {
_NCp1_NId_Prd_2(&(*_Lf_70)._Freal_name, &_Lr_7);
}
if(((*_Lf_70)._Fflags & _NCp1_NFuncFlags_Ccase) != _NCp1_NFuncFlags_C0) {
_NCp1_NId_Prd_2(&(*_Lf_70)._Fcas, &_Lr_7);
}
if(((*_Lf_70)._Fflags & _NCp1_NFuncFlags_Cdecl) != _NCp1_NFuncFlags_C0) {
uint32_t _Llen_78;
_Llen_78 = Fgetnum(&_Lr_7);
(*_Lf_70)._Fdecl_len = _Llen_78;
(*_Lf_70)._Fdecl_str = qalloc(_Llen_78 + 1);
memcpy((*_Lf_70)._Fdecl_str, _Lr_7._Freff, _Llen_78);
(*_Lf_70)._Fdecl_str[_Llen_78] = 0;
_Lr_7._Fpos += _Llen_78;
}
_Lat_79 = _NCp1_NAt_Pptr_1(_Lat_i_71);
_Lat_func_idx_80 = (*_Lat_79)._Ffunc_c++;
if((*_Lat_79)._Ffunc_cap <= (*_Lat_79)._Ffunc_c) {
int32_t _Lold_cap_81;
_Lold_cap_81 = (*_Lat_79)._Ffunc_cap;
_NCp1_Pgrow_2((*_Lat_79)._Ffunc_cap, (*_Lat_79)._Ffunc_c);
_NCp1_Prealloc_3((*_Lat_79)._Ffunc_v, (*_Lat_79)._Ffunc_cap, _Lold_cap_81);
}
(*_Lat_79)._Ffunc_v[_Lat_func_idx_80] = _Lf_idx_68;
continue_8:;
_Lf_idx_68++;
}
break_8:;
_NCp1_NFunc_Prd_2(&_Lfunc_main_82, &_Lr_7);
if(_Lfunc_main_82 != _NCp1_NFunc_Cnil) {
if(_Gfunc_main != _NCp1_NFunc_Cnil) {
struct _NCp1_NDeclFunc* _Lfirst_83;
struct _NCp1_NDeclFunc* _Lsecond_84;
_Lfirst_83 = _NCp1_NFunc_Pptr_1(_Gfunc_main);
_Lsecond_84 = _NCp1_NFunc_Pptr_1(_Lfunc_main_82);
fprintf(stdout, "There are more than one function with @main attribute, first is %u:%u and second is %u:%u\n", (*_Lfirst_83)._Fbegin_row, (*_Lfirst_83)._Fbegin_col, (*_Lsecond_84)._Fbegin_row, (*_Lsecond_84)._Fbegin_col);
exit(_NStdc_NExit_Cfailure);
}
_Gfunc_main = _Lfunc_main_82;
}
_NCp1_NFunc _Lf_idx_85;
_Lf_idx_85 = _Lf_idx_begin_66;
for(int i = _Lfunc_c_65; i > 0; ) {
i --;
struct _NCp1_NDeclFunc* _Lf_86;
uint32_t _Lsize_87;
_Lf_86 = _Gfunc_v[_Lf_idx_85];
if(((*_Lf_86)._Fflags & _NCp1_NFuncFlags_Chas_body) == _NCp1_NFuncFlags_C0) {
goto continue_11;
}
_Lsize_87 = _NCp1_NRdr_Pn4_1(&_Lr_7);
(*_Lf_86)._Fbody_file_pos = (_Lr_7._Fpos - _Lr_begin_3._Fpos);
_Lr_7._Fpos += _Lsize_87;
continue_11:;
_Lf_idx_85++;
}
break_11:;
}
inline struct _NCp1_NDeclFunc* _NCp1_NFunc_Pptr_1(_NCp1_NFunc _Lf_0) {
return _Gfunc_v[_Lf_0];
}
inline struct _NCp1_NAtData* _NCp1_NAt_Pptr_1(_NCp1_NAt _Li_0) {
return &_Gat_v[_Li_0];
}
inline char* _NCp1_NFile_Ppath_1(_NCp1_NFile _Lf_0) {
return (*_NCp1_NFile_Pptr_1(_Lf_0))._Fpath;
}
inline char* _NCp1_NId_Pstr_1(_NCp1_NId _Lid_0) {
return _Gid_str_v[_Lid_0];
}
inline struct _NCp1_NStructData* _NCp1_NStruct_Pptr_1(_NCp1_NStruct _Ls_0) {
return _Gstruct_v[_Ls_0];
}
inline struct _NCp1_NEnumData* _NCp1_NEnum_Pptr_1(_NCp1_NEnum _Lf_0) {
return _Genum_v[_Lf_0];
}
_NCp1_NId _NCp1_Pid_add_2(uint8_t _Lid_len_0, char* _Lid_str_1) {
int32_t _Lfound_2;
int32_t _Lid_idx_3;
_Lfound_2 = _NCp1_NMap_Pget_or_insert_4(&_Gid_map, _Lid_str_1, _Lid_len_0, _Gid_c);
if(_Lfound_2 != -1) {
return _Lfound_2;
}
_Lid_idx_3 = _Gid_c++;
if(_Gid_cap <= _Gid_c) {
int32_t _Lold_cap_4;
_Lold_cap_4 = _Gid_cap;
_NCp1_Pgrow_2(_Gid_cap, _Gid_c);
_NCp1_Prealloc_3(_Gid_len_v, _Gid_cap, _Lold_cap_4);
_NCp1_Prealloc_3(_Gid_str_v, _Gid_cap, _Lold_cap_4);
}
_Gid_len_v[_Lid_idx_3] = _Lid_len_0;
_Gid_str_v[_Lid_idx_3] = _Lid_str_1;
return _Lid_idx_3;
}
void _NCp1_NFunc_Pprocess_later_1(_NCp1_NFunc _Lf_idx_0) {
uint32_t _Lnum_1;
uint32_t _Ln3_2;
int32_t _Ln17_3;
struct _NCp1_NDeclFunc* _Lf_4;
_NCp1_NAt _Lf_at_5;
_NCp1_NFile _Lf_file_6;
int32_t _Lf_row_7;
int32_t _Lf_col_8;
_Lnum_1 = (uint32_t)(_Lf_idx_0);
_Ln3_2 = (_Lnum_1 >> 3);
_Ln17_3 = (1 << (_Lnum_1 & 7));
if((_Gfunc_in_process[_Ln3_2] & _Ln17_3) != 0) {
return;
}
_Gfunc_in_process[_Ln3_2] |= _Ln17_3;
_Lf_4 = _NCp1_NFunc_Pptr_1(_Lf_idx_0);
_Lf_at_5 = (*_Lf_4)._Fat;
_Lf_file_6 = (*_Lf_4)._Ffile;
_Lf_row_7 = (*_Lf_4)._Fbegin_row;
_Lf_col_8 = (*_Lf_4)._Fbegin_col;
int32_t _Lj_9;
_Lj_9 = 0;
for(int i = (*_Lf_4)._Ffarg_c; i > 0; ) {
i --;
(*_Lf_4)._Ffarg_v[_Lj_9]._Fdecl._Ftype = _NCp1_Pat_validate_5((*_Lf_4)._Ffarg_v[_Lj_9]._Fdecl._Ftype, _Lf_at_5, _Lf_file_6, (*_Lf_4)._Ffarg_v[_Lj_9]._Frow, (*_Lf_4)._Ffarg_v[_Lj_9]._Fcol);
continue_0:;
_Lj_9++;
}
break_0:;
if((*_Lf_4)._Fdecl._Ftype != _NCp1_NAt_Cnil) {
(*_Lf_4)._Fdecl._Ftype = _NCp1_Pat_validate_5((*_Lf_4)._Fdecl._Ftype, _Lf_at_5, _Lf_file_6, _Lf_row_7, _Lf_col_8);
_NCp1_NAt_Pfinalize_4((*_Lf_4)._Fdecl._Ftype, &(*_Lf_4)._Fdecl._Ftype_info, _Lf_row_7, _Lf_col_8);
}
_Gfunc_head_outputted_v[_Gfunc_head_outputted_c++] = _Lf_idx_0;
if(((*_Lf_4)._Fflags & _NCp1_NFuncFlags_Chas_body) != _NCp1_NFuncFlags_C0) {
(*_Lf_4)._Fprocess_next = _NCp1_NFunc_Cnil;
if(_Gprocess_first == _NCp1_NFunc_Cnil) {
_Gprocess_first = _Lf_idx_0;
_Gprocess_last = _Lf_idx_0;
} else {
struct _NCp1_NDeclFunc* _Lf_last_10;
_Lf_last_10 = _NCp1_NFunc_Pptr_1(_Gprocess_last);
(*_Lf_last_10)._Fprocess_next = _Lf_idx_0;
_Gprocess_last = _Lf_idx_0;
}
}
}
bool _NCp1_NFunc_Pprocess_now_1(_NCp1_NFunc _Lf_idx_0) {
struct _NCp1_NDeclFunc* _Lf_1;
union _NCp1_NRdr _Lr_2;
struct _NCp1_NFileData* _Lfile_3;
struct _NCp1_NStmt* _Ls_4;
_Lf_1 = _NCp1_NFunc_Pptr_1(_Lf_idx_0);
_Gctx_func = _Lf_1;
_Lfile_3 = _NCp1_NFile_Pptr_1((*_Lf_1)._Ffile);
_Lr_2._Freff = (*_Lfile_3)._Fdata;
_Gid_table = (*_Lfile_3)._Fid_table;
_Gat_table = (*_Lfile_3)._Fat_table;
_Gcvar_table = (*_Lfile_3)._Fcvar_table;
_Lr_2._Fpos += (*_Lf_1)._Fbody_file_pos;
_NCp1_NDeclFunc_Plvars_rd_2(_Lf_1, &_Lr_2);
_NCp1_NStmtSpace_Prd_3(&(*_Lf_1)._Fstmt_space, &_Lr_2, NULL);
_Ls_4 = (*_Lf_1)._Fstmt_space._Fstmt_first;
while(_Ls_4 != NULL) {
_Gctx_begin_row = (*_Ls_4)._Fbegin_row;
_Gctx_begin_col = (*_Ls_4)._Fbegin_col;
_Gctx_end_row = (*_Ls_4)._Fend_row;
_Gctx_end_col = (*_Ls_4)._Fend_col;
if(!(_NCp1_NStmt_Pprocess_1(_Ls_4))) {
return false;
}
_Ls_4 = (*_Ls_4)._Fstmt_next;
continue_0:;
}
break_0:;
if(((*_Lf_1)._Fflags & _NCp1_NFuncFlags_Cno_body) == _NCp1_NFuncFlags_C0) {
_Gfunc_body_outputted_v[_Gfunc_body_outputted_c++] = _Lf_idx_0;
}
return true;
}
inline bool _NCp1_NLvar_Pprocess_1(_NCp1_NLvar _Ll_0) {
struct _NCp1_NLvarData* _Llvar_1;
_NCp1_NAt _Lat_i_2;
_Llvar_1 = _NCp1_NLvar_Pptr_1(_Ll_0);
if(((*_Llvar_1)._Fflags & _NCp1_NLvarFlags_Cprocessed) != _NCp1_NLvarFlags_C0) {
return true;
}
(*_Llvar_1)._Fflags |= _NCp1_NLvarFlags_Cprocessed;
_Lat_i_2 = (*_Llvar_1)._Fdecl._Ftype;
if(_Lat_i_2 == _NCp1_NAt_Cnil) {
if(((*_Llvar_1)._Fflags & _NCp1_NLvarFlags_Cset_expr) != _NCp1_NLvarFlags_C0) {
struct _NCp1_NValue _Lv_3;
if(!(_NCp1_NExprI_Pvalue_4((*_Llvar_1)._Fset_expr, 1, false, &_Lv_3))) {
return false;
}
(*_Llvar_1)._Fdecl._Ftype = _Lv_3._Ftype;
_NCp1_NTypeInfo_Pinit_1(&(*_Llvar_1)._Fdecl._Ftype_info);
_NCp1_NTypeInfo_Pcopy_from_2(&(*_Llvar_1)._Fdecl._Ftype_info, &_Lv_3._Finfo);
} else {
fprintf(stdout, "%s:%u:%u: local variable '%s' doesn:T have a type or a value\n", _NCp1_NFile_Ppath_1((*_Gctx_func)._Ffile), (*_Llvar_1)._Frow, (*_Llvar_1)._Fcol, _NCp1_NId_Pstr_1((*_Llvar_1)._Fdecl._Fname));
return false;
}
return true;
}
return _NCp1_NDeclVarData_Pprocess_5(&(*_Llvar_1)._Fdecl, (*_Gctx_func)._Ffile, (*_Llvar_1)._Frow, (*_Llvar_1)._Fcol, (*_Gctx_func)._Fat);
}
void _NCp1_NAt_Poutput_4(_NCp1_NAt _Lat_i_0, _NCp1_NFile _Lfile_1, int32_t _Lrow_2, int32_t _Lcol_3) {
struct _NCp1_NAtData* _Lat_4;
_Lat_4 = _NCp1_NAt_Pptr_1(_Lat_i_0);
switch((*_Lat_4)._Ftype) {
case _NCp1_NNameType_Cstruct_enum:;
if((*_Lat_4)._Fdef == _NCp1_NAtDef_Cstruct) {
if((*_Lat_4)._Fdecl._Fstruct == _NCp1_NStruct_Cnil) {
fprintf(stdout, "%s:%u:%u: Error, struct '/%s' was not defined\n", _NCp1_NFile_Ppath_1(_Lfile_1), _Lrow_2, _Lcol_3, _NCp1_NId_Pstr_1((*_Lat_4)._Fname._Fid));
exit(_NStdc_NExit_Cfailure);
}
_NCp1_NStruct_Poutput_1((*_Lat_4)._Fdecl._Fstruct);
} else if((*_Lat_4)._Fdef == _NCp1_NAtDef_Cenum) {
if((*_Lat_4)._Fdecl._Fenum == _NCp1_NEnum_Cnil) {
fprintf(stdout, "%s:%u:%u: Error, enum '\\%s' was not defined\n", _NCp1_NFile_Ppath_1(_Lfile_1), _Lrow_2, _Lcol_3, _NCp1_NId_Pstr_1((*_Lat_4)._Fname._Fid));
exit(_NStdc_NExit_Cfailure);
}
_NCp1_NEnum_Poutput_1((*_Lat_4)._Fdecl._Fenum);
}
break;
case _NCp1_NNameType_Cbasic:;
switch((*_Lat_4)._Fname._Fbasic) {
case _NCp1_NBasicTypeId_Cbool:;
_Ginclude_stdbool = true;
break;
case _NCp1_NBasicTypeId_Cusz:;
_Ginclude_stddef = true;
break;
case _NCp1_NBasicTypeId_Ci8:;
_Ginclude_stdint = true;
break;
case _NCp1_NBasicTypeId_Cu8:;
_Ginclude_stdint = true;
break;
case _NCp1_NBasicTypeId_Ci16:;
_Ginclude_stdint = true;
break;
case _NCp1_NBasicTypeId_Cu16:;
_Ginclude_stdint = true;
break;
case _NCp1_NBasicTypeId_Ci32:;
_Ginclude_stdint = true;
break;
case _NCp1_NBasicTypeId_Cu32:;
_Ginclude_stdint = true;
break;
case _NCp1_NBasicTypeId_Ci64:;
_Ginclude_stdint = true;
break;
case _NCp1_NBasicTypeId_Cu64:;
_Ginclude_stdint = true;
break;
}
break;
}
}
inline void _NCp1_NInclude_Poutput_1(_NCp1_NInclude _Lthiss_0) {
uint32_t _Lnum_1;
uint32_t _Ln3_2;
int32_t _Ln17_3;
_Lnum_1 = (uint32_t)(_Lthiss_0);
_Ln3_2 = (_Lnum_1 >> 3);
_Ln17_3 = (1 << (_Lnum_1 & 7));
if((_Ginclude_is_outputted[_Ln3_2] & _Ln17_3) != 0) {
return;
}
_Ginclude_is_outputted[_Ln3_2] |= _Ln17_3;
_Ginclude_outputted_v[_Ginclude_outputted_c++] = _Lthiss_0;
}
inline struct _NCp1_NCvarData* _NCp1_NCvar_Pptr_1(_NCp1_NCvar _Lc_0) {
return &_Gcvar_v[_Lc_0];
}
bool _NCp1_NCvar_Pprocess_1(_NCp1_NCvar _Lc_0) {
uint32_t _Lnum_1;
uint32_t _Ln3_2;
int32_t _Ln17_3;
struct _NCp1_NCvarData* _Lcvar_4;
_NCp1_NAt _Lat_i_5;
_Lnum_1 = (uint32_t)(_Lc_0);
_Ln3_2 = (_Lnum_1 >> 3);
_Ln17_3 = (1 << (_Lnum_1 & 7));
if((_Gcvar_is_outputted[_Ln3_2] & _Ln17_3) != 0) {
return true;
}
_Gcvar_is_outputted[_Ln3_2] |= _Ln17_3;
_Lcvar_4 = _NCp1_NCvar_Pptr_1(_Lc_0);
if(((*_Lcvar_4)._Fflags & _NCp1_NCvarFlags_Cset_expr) != _NCp1_NCvarFlags_C0) {
if(!(_NCp1_NExprI_Pprocess_1((*_Lcvar_4)._Fexpr_set))) {
return false;
}
} else if((*_Lcvar_4)._Flast_cvar != _NCp1_NCvar_Cnil) {
if(!(_NCp1_NCvar_Pprocess_1((*_Lcvar_4)._Flast_cvar))) {
return false;
}
}
_Lat_i_5 = (*_Lcvar_4)._Fdecl._Ftype;
if(_Lat_i_5 != _NCp1_NAt_Cnil) {
struct _NCp1_NAtData* _Lat_6;
_Lat_6 = _NCp1_NAt_Pptr_1(_Lat_i_5);
if((((*_Lat_6)._Ftype != _NCp1_NNameType_Cbasic) && ((*_Lat_6)._Fdecl._Fstruct == _NCp1_NStruct_Cnil))) {
fprintf(stdout, "Error, the type '%s' used in cvar '.%s' was not defined\n", _NCp1_NId_Pstr_1((*_Lat_6)._Fname._Fid), _NCp1_NId_Pstr_1((*_Lcvar_4)._Fdecl._Fname));
return false;
}
_NCp1_NAt_Poutput_4(_Lat_i_5, (*_Lcvar_4)._Ffile, (*_Lcvar_4)._Frow, (*_Lcvar_4)._Fcol);
}
_Gcvar_outputted_v[_Gcvar_outputted_c++] = _Lc_0;
return true;
}
inline char* _NCp1_NInclude_Pstr_1(_NCp1_NInclude _Li_0) {
return _Ginclude_str_v[_Li_0];
}
inline void _NCp1_NCvar_Pwrite_1(_NCp1_NCvar _Lc_0) {
struct _NCp1_NCvarData* _Lcvar_1;
_Lcvar_1 = _NCp1_NCvar_Pptr_1(_Lc_0);
if(((*_Lcvar_1)._Fdecl._Fflags & _NCp1_NVarFlags_Creal_name) != _NCp1_NVarFlags_C0) {
fprintf(_Gout, "%s", _NCp1_NId_Pstr_1((*_Lcvar_1)._Fdecl._Freal_name));
} else {
_NCp1_NAt_Pwrite_space_1((*_Lcvar_1)._Fat);
fprintf(_Gout, "_C%s", _NCp1_NId_Pc_name_1((*_Lcvar_1)._Fdecl._Fname));
}
}
void _NCp1_NExprI_Pwrite_1(_NCp1_NExprI _Le_0) {
struct _NCp1_NExpr* _Lexpr_1;
_Lexpr_1 = _NCp1_NExprI_Pptr_1(_Le_0);
switch((*_Lexpr_1)._Ftype) {
case _NCp1_NExprType_Cassign:;
_NCp1_NExprI_Pwrite_assign_1(_Lexpr_1);
break;
case _NCp1_NExprType_Ccompare:;
_NCp1_NExprI_Pwrite_compare_1(_Lexpr_1);
break;
case _NCp1_NExprType_Cbool:;
_NCp1_NExprI_Pwrite_bool_1(_Lexpr_1);
break;
case _NCp1_NExprType_Cchar:;
_NCp1_NExprI_Pwrite_char_1(_Lexpr_1);
break;
case _NCp1_NExprType_Cmath:;
_NCp1_NExprI_Pwrite_math_1(_Lexpr_1);
break;
case _NCp1_NExprType_Cunary:;
_NCp1_NExprI_Pwrite_unary_1(_Lexpr_1);
break;
case _NCp1_NExprType_Cref:;
_NCp1_NExprI_Pwrite_ref_1(_Lexpr_1);
break;
case _NCp1_NExprType_Clvar:;
_NCp1_NExprI_Pwrite_lvar_1(_Lexpr_1);
break;
case _NCp1_NExprType_Cfvar:;
_NCp1_NExprI_Pwrite_fvar_1(_Lexpr_1);
break;
case _NCp1_NExprType_Cgvar:;
_NCp1_NExprI_Pwrite_gvar_1(_Lexpr_1);
break;
case _NCp1_NExprType_Ccvar:;
_NCp1_NExprI_Pwrite_cvar_1(_Lexpr_1);
break;
case _NCp1_NExprType_Cbools:;
_NCp1_NExprI_Pwrite_bools_1(_Lexpr_1);
break;
case _NCp1_NExprType_Cmethod:;
_NCp1_NExprI_Pwrite_method_1(_Lexpr_1);
break;
case _NCp1_NExprType_Cfunc:;
_NCp1_NExprI_Pwrite_func_1(_Lexpr_1);
break;
case _NCp1_NExprType_Cstr:;
_NCp1_NExprI_Pwrite_str_1(_Lexpr_1);
break;
case _NCp1_NExprType_Ci32:;
_NCp1_NExprI_Pwrite_i32_1(_Lexpr_1);
break;
case _NCp1_NExprType_Csize_of_type:;
_NCp1_NExprI_Pwrite_size_of_type_1(_Lexpr_1);
break;
case _NCp1_NExprType_Cnull:;
_NCp1_NExprI_Pwrite_null_1(_Lexpr_1);
break;
case _NCp1_NExprType_Cindex:;
_NCp1_NExprI_Pwrite_index_1(_Lexpr_1);
break;
default:;
fprintf(stdout, "%s:%u:%u - %u:%u: write() not implemented in expression #%s\n", _NCp1_NFile_Ppath_1((*_Gctx_func)._Ffile), _Gctx_begin_row, _Gctx_begin_col, _Gctx_end_row, _Gctx_end_col, _NCp1_NExprType_Pcp1_name_1((*_Lexpr_1)._Ftype));
break;
}
}
void _NCp1_NAt_Pwrite_1(_NCp1_NAt _Lat_idx_0) {
struct _NCp1_NAtData* _Lat_1;
_Lat_1 = _NCp1_NAt_Pptr_1(_Lat_idx_0);
switch((*_Lat_1)._Ftype) {
case _NCp1_NNameType_Cmodule:;
if((*_Lat_1)._Fparent != _NCp1_NAt_Croot) {
_NCp1_NAt_Pwrite_space_1((*_Lat_1)._Fparent);
}
fprintf(_Gout, "_M%s", _NCp1_NId_Pc_name_1((*_Lat_1)._Fname._Fid));
break;
case _NCp1_NNameType_Cstruct_enum:;
if((*_Lat_1)._Fdef == _NCp1_NAtDef_Cstruct) {
_NCp1_NStruct _Lt_idx_2;
struct _NCp1_NStructData* _Lt_3;
_Lt_idx_2 = (*_Lat_1)._Fdecl._Fstruct;
_Lt_3 = _NCp1_NStruct_Pptr_1(_Lt_idx_2);
if(_Lt_idx_2 != _NCp1_NStruct_Cnil) {
if(((*_Lt_3)._Fflags & _NCp1_NStructFlags_Creal_name) != _NCp1_NStructFlags_C0) {
if((*_Lt_3)._Freal_name == _NCp1_NId_Cnil) {
if(((*_Lt_3)._Fflags & _NCp1_NStructFlags_Cunion) != _NCp1_NStructFlags_C0) {
fprintf(_Gout, "union %s", _NCp1_NId_Pc_name_1((*_Lat_1)._Fname._Fid));
} else {
fprintf(_Gout, "struct %s", _NCp1_NId_Pc_name_1((*_Lat_1)._Fname._Fid));
}
} else {
if(((*_Lt_3)._Fflags & _NCp1_NStructFlags_Cunion) != _NCp1_NStructFlags_C0) {
fprintf(_Gout, "union %s", _NCp1_NId_Pstr_1((*_Lt_3)._Freal_name));
} else {
fprintf(_Gout, "struct %s", _NCp1_NId_Pstr_1((*_Lt_3)._Freal_name));
}
}
return;
}
}
if(((*_Lt_3)._Fflags & _NCp1_NStructFlags_Cunion) != _NCp1_NStructFlags_C0) {
fprintf(_Gout, "union ");
} else {
fprintf(_Gout, "struct ");
}
if((*_Lat_1)._Fparent != _NCp1_NAt_Croot) {
_NCp1_NAt_Pwrite_space_1((*_Lat_1)._Fparent);
}
fprintf(_Gout, "_N%s", _NCp1_NId_Pc_name_1((*_Lat_1)._Fname._Fid));
} else if((*_Lat_1)._Fdef == _NCp1_NAtDef_Cenum) {
_NCp1_NEnum _Lt_idx_4;
_Lt_idx_4 = (*_Lat_1)._Fdecl._Fenum;
if(_Lt_idx_4 != _NCp1_NEnum_Cnil) {
struct _NCp1_NEnumData* _Lt_5;
_Lt_5 = _NCp1_NEnum_Pptr_1(_Lt_idx_4);
if(((*_Lt_5)._Fflags & _NCp1_NEnumFlags_Creal_name) != _NCp1_NEnumFlags_C0) {
fprintf(_Gout, "%s", _NCp1_NId_Pstr_1((*_Lt_5)._Freal_name));
return;
}
}
if((*_Lat_1)._Fparent != _NCp1_NAt_Croot) {
_NCp1_NAt_Pwrite_space_1((*_Lat_1)._Fparent);
}
fprintf(_Gout, "_N%s", _NCp1_NId_Pc_name_1((*_Lat_1)._Fname._Fid));
}
break;
case _NCp1_NNameType_Cbasic:;
switch((*_Lat_1)._Fname._Fbasic) {
case _NCp1_NBasicTypeId_Cref:;
fprintf(_Gout, "void*");
break;
case _NCp1_NBasicTypeId_Cbool:;
fprintf(_Gout, "bool");
break;
case _NCp1_NBasicTypeId_Cchar:;
fprintf(_Gout, "char");
break;
case _NCp1_NBasicTypeId_Cintc:;
fprintf(_Gout, "int");
break;
case _NCp1_NBasicTypeId_Ci8:;
fprintf(_Gout, "int8_t");
break;
case _NCp1_NBasicTypeId_Cu8:;
fprintf(_Gout, "uint8_t");
break;
case _NCp1_NBasicTypeId_Ci16:;
fprintf(_Gout, "int16_t");
break;
case _NCp1_NBasicTypeId_Cu16:;
fprintf(_Gout, "uint16_t");
break;
case _NCp1_NBasicTypeId_Ci32:;
fprintf(_Gout, "int32_t");
break;
case _NCp1_NBasicTypeId_Cu32:;
fprintf(_Gout, "uint32_t");
break;
case _NCp1_NBasicTypeId_Ci64:;
fprintf(_Gout, "int64_t");
break;
case _NCp1_NBasicTypeId_Cu64:;
fprintf(_Gout, "uint64_t");
break;
case _NCp1_NBasicTypeId_Cisz:;
fprintf(_Gout, "ssize_t");
break;
case _NCp1_NBasicTypeId_Cusz:;
fprintf(_Gout, "size_t");
break;
case _NCp1_NBasicTypeId_Cf32:;
fprintf(_Gout, "float");
break;
case _NCp1_NBasicTypeId_Cf64:;
fprintf(_Gout, "double");
break;
}
break;
}
}
void _NCp1_NAt_Pwrite_space_1(_NCp1_NAt _Lat_idx_0) {
struct _NCp1_NAtData* _Lat_1;
_Lat_1 = _NCp1_NAt_Pptr_1(_Lat_idx_0);
switch((*_Lat_1)._Ftype) {
case _NCp1_NNameType_Cmodule:;
if((*_Lat_1)._Fparent != _NCp1_NAt_Croot) {
_NCp1_NAt_Pwrite_space_1((*_Lat_1)._Fparent);
}
fprintf(_Gout, "_M%s", _NCp1_NId_Pc_name_1((*_Lat_1)._Fname._Fid));
break;
case _NCp1_NNameType_Cstruct_enum:;
if((*_Lat_1)._Fparent != _NCp1_NAt_Croot) {
_NCp1_NAt_Pwrite_space_1((*_Lat_1)._Fparent);
}
fprintf(_Gout, "_N%s", _NCp1_NId_Pc_name_1((*_Lat_1)._Fname._Fid));
break;
case _NCp1_NNameType_Cbasic:;
switch((*_Lat_1)._Fname._Fbasic) {
case _NCp1_NBasicTypeId_Cref:;
fprintf(_Gout, "_Tref");
break;
case _NCp1_NBasicTypeId_Cbool:;
fprintf(_Gout, "_Tbool");
break;
case _NCp1_NBasicTypeId_Cchar:;
fprintf(_Gout, "_Tchar");
break;
case _NCp1_NBasicTypeId_Cintc:;
fprintf(_Gout, "_Tintc");
break;
case _NCp1_NBasicTypeId_Ci8:;
fprintf(_Gout, "_Ti8");
break;
case _NCp1_NBasicTypeId_Cu8:;
fprintf(_Gout, "_Tu8");
break;
case _NCp1_NBasicTypeId_Ci16:;
fprintf(_Gout, "_Ti16");
break;
case _NCp1_NBasicTypeId_Cu16:;
fprintf(_Gout, "_Tu16");
break;
case _NCp1_NBasicTypeId_Ci32:;
fprintf(_Gout, "_Ti32");
break;
case _NCp1_NBasicTypeId_Cu32:;
fprintf(_Gout, "_Tu32");
break;
case _NCp1_NBasicTypeId_Ci64:;
fprintf(_Gout, "_Ti64");
break;
case _NCp1_NBasicTypeId_Cu64:;
fprintf(_Gout, "_Tu64");
break;
case _NCp1_NBasicTypeId_Cisz:;
fprintf(_Gout, "_Tisz");
break;
case _NCp1_NBasicTypeId_Cusz:;
fprintf(_Gout, "_Tusz");
break;
case _NCp1_NBasicTypeId_Cf32:;
fprintf(_Gout, "_Tf32");
break;
case _NCp1_NBasicTypeId_Cf64:;
fprintf(_Gout, "_Tf64");
break;
}
break;
}
}
void _NCp1_NDeclVarData_Pwrite_type_2(struct _NCp1_NDeclVarData* _Lvd_0, _NCp1_NDeclVarType _Lvar_type_1) {
if((*_Lvd_0)._Ftype_info._Fconst) {
fprintf(_Gout, "const ");
}
_NCp1_NAt_Pwrite_type_info_3((*_Lvd_0)._Ftype, &(*_Lvd_0)._Ftype_info, 0 - (*_Lvd_0)._Fsize_c);
fprintf(_Gout, " ");
_NCp1_NDeclVarData_Pwrite_2(_Lvd_0, _Lvar_type_1);
int32_t _Li_2;
_Li_2 = 0;
for(int i = (*_Lvd_0)._Fsize_c; i > 0; ) {
i --;
fprintf(_Gout, "[");
_NCp1_NExprI_Pwrite_value_2((*_Lvd_0)._Fsize_expr_v[_Li_2], &(*_Lvd_0)._Fsize_value_v[_Li_2]);
fprintf(_Gout, "]");
continue_0:;
_Li_2++;
}
break_0:;
}
inline struct _NCp1_NDeclGvar* _NCp1_NGvar_Pptr_1(_NCp1_NGvar _Lg_0) {
return &_Ggvar_v[_Lg_0];
}
void _NCp1_NDeclFunc_Pwrite_1(struct _NCp1_NDeclFunc* _Lf_0) {
if(((*_Lf_0)._Fflags & _NCp1_NFuncFlags_Creal_name) != _NCp1_NFuncFlags_C0) {
fprintf(_Gout, "%s", _NCp1_NId_Pstr_1((*_Lf_0)._Freal_name));
} else {
_NCp1_NAt_Pwrite_space_1((*_Lf_0)._Fat);
fprintf(_Gout, "_P%s", _NCp1_NId_Pc_name_1((*_Lf_0)._Fdecl._Fname));
int32_t _Li_1;
_Li_1 = 0;
for(int i = (*_Lf_0)._Fgroup_c; i > 0; ) {
i --;
fprintf(_Gout, "_%u", (*_Lf_0)._Fgroup_v[_Li_1]);
continue_0:;
_Li_1++;
}
break_0:;
}
}
bool _NCp1_NAt_Pwrite_type_info_3(_NCp1_NAt _Ltd_0, struct _NCp1_NTypeInfo* _Lti_1, int32_t _Ladd_2) {
int32_t _Ls_3;
_NCp1_NTypeInfo_Pcount_1(_Lti_1);
_NCp1_NAt_Pwrite_type_1(_Ltd_0);
_Ls_3 = (_NCp1_NAt_Pcount_stars0_2(_Ltd_0, _Lti_1) + _Ladd_2);
if(_Ls_3 > 0) {
_NStdc_NFile_Pwrite_3(_Gout, "********************************", _Ls_3);
}
return true;
}
void _NCp1_NDeclVarData_Pwrite_lvar_type_2(struct _NCp1_NDeclVarData* _Lvd_0, _NCp1_NLvar _Llvar_1) {
if((*_Lvd_0)._Ftype_info._Fconst) {
fprintf(_Gout, "const ");
}
_NCp1_NAt_Pwrite_type_info_3((*_Lvd_0)._Ftype, &(*_Lvd_0)._Ftype_info, 0 - (*_Lvd_0)._Fsize_c);
fprintf(_Gout, " ");
_NCp1_NDeclVarData_Pwrite_lvar_2(_Lvd_0, _Llvar_1);
int32_t _Li_2;
_Li_2 = 0;
for(int i = (*_Lvd_0)._Fsize_c; i > 0; ) {
i --;
fprintf(_Gout, "[");
_NCp1_NExprI_Pwrite_value_2((*_Lvd_0)._Fsize_expr_v[_Li_2], &(*_Lvd_0)._Fsize_value_v[_Li_2]);
fprintf(_Gout, "]");
continue_0:;
_Li_2++;
}
break_0:;
}
void _NCp1_NStmtSpace_Pwrite_1(struct _NCp1_NStmtSpace* _Lspace_0) {
uint8_t _Li_1;
int32_t _Llvar_c_2;
struct _NCp1_NStmt* _Ls_5;
if((*_Lspace_0)._Fparent == NULL) {
_Li_1 = (*_Gctx_func)._Ffarg_c;
_Llvar_c_2 = ((*_Lspace_0)._Flvar_c - (*_Gctx_func)._Ffarg_c);
} else {
_Li_1 = 0;
_Llvar_c_2 = (*_Lspace_0)._Flvar_c;
}
for(int i = _Llvar_c_2; i > 0; ) {
i --;
_NCp1_NLvar _Llvar_i_3;
struct _NCp1_NLvarData* _Llvar_4;
_Llvar_i_3 = (*_Lspace_0)._Flvar_v[_Li_1];
_Llvar_4 = _NCp1_NLvar_Pptr_1(_Llvar_i_3);
_NCp1_NDeclVarData_Pwrite_lvar_type_2(&(*_Llvar_4)._Fdecl, _Llvar_i_3);
if(((*_Llvar_4)._Fflags & _NCp1_NLvarFlags_Cset_expr) != _NCp1_NLvarFlags_C0) {
fprintf(_Gout, " = ");
_NCp1_NExprI_Pwrite_1((*_Llvar_4)._Fset_expr);
}
fprintf(_Gout, ";\n");
continue_0:;
_Li_1++;
}
break_0:;
_Ls_5 = (*_Lspace_0)._Fstmt_first;
while(_Ls_5 != NULL) {
_NCp1_NStmt_Pwrite_1(_Ls_5);
_Ls_5 = (*_Ls_5)._Fstmt_next;
continue_1:;
}
break_1:;
}
inline bool _NStdc_NFd_Popen_3(_NStdc_NFd* _Lfile_0, char* _Lpath_1, _NStdc_NOpenFlags _Lflags_2) {
_NStdc_NFd _Lfd_3;
_Lfd_3 = open(_Lpath_1, _Lflags_2);
if(_Lfd_3 != -1) {
(*_Lfile_0) = _Lfd_3;
return true;
} else {
return false;
}
}
inline int _NStdc_NFd_Pclose_1(_NStdc_NFd _Lfile_0) {
return close(_Lfile_0);
}
inline uint8_t _NCp1_NRdr_Pn1_1(union _NCp1_NRdr* _Lr_0) {
uint8_t _Lval_1;
_Lval_1 = (*_Lr_0)._Fp1[0];
(*_Lr_0)._Fpos++;
return _Lval_1;
}
inline void _NCp1_NNameType_Prd_2(_NCp1_NNameType* _Li_0, union _NCp1_NRdr* _Lr_1) {
(*_Li_0) = (_NCp1_NNameType)(_NCp1_NRdr_Pn1_1(_Lr_1));
}
inline void _NCp1_NBasicTypeId_Prd_2(_NCp1_NBasicTypeId* _Le_0, union _NCp1_NRdr* _Lr_1) {
(*_Le_0) = (_NCp1_NBasicTypeId)(_NCp1_NRdr_Pn1_1(_Lr_1));
}
inline _NCp1_NAt _NCp1_Pbasic_type_1(_NCp1_NBasicTypeId _Lt_0) {
return _Lt_0;
}
inline void _NCp1_NAt_Prd_2(_NCp1_NAt* _Li_0, union _NCp1_NRdr* _Lr_1) {
_NCp1_NAt _Lidx_2;
_Lidx_2 = ((_NCp1_NAt)(Fgetnum(_Lr_1) - 1));
if(_Lidx_2 == _NCp1_NAt_Cnil) {
(*_Li_0) = _NCp1_NAt_Cnil;
} else {
(*_Li_0) = _Gat_table[_Lidx_2];
}
}
inline void _NCp1_NId_Prd_2(_NCp1_NId* _Lid_0, union _NCp1_NRdr* _Lr_1) {
_NCp1_NId _Lidx_2;
_Lidx_2 = ((_NCp1_NId)(Fgetnum(_Lr_1) - 1));
if(_Lidx_2 == _NCp1_NId_Cnil) {
(*_Lid_0) = _NCp1_NId_Cnil;
} else {
(*_Lid_0) = _Gid_table[_Lidx_2];
}
}
inline void _NCp1_NInclude_Prd_2(_NCp1_NInclude* _Li_0, union _NCp1_NRdr* _Lr_1) {
_NCp1_NInclude _Lidx_2;
_Lidx_2 = ((_NCp1_NInclude)(Fgetnum(_Lr_1) - 1));
if(_Lidx_2 == _NCp1_NInclude_Cnil) {
(*_Li_0) = _NCp1_NInclude_Cnil;
} else {
(*_Li_0) = _Ginclude_table[_Lidx_2];
}
}
void _NCp1_NDeclVarData_Prd_2(struct _NCp1_NDeclVarData* _Lvd_0, union _NCp1_NRdr* _Lr_1) {
_NCp1_NId_Prd_2(&(*_Lvd_0)._Fname, _Lr_1);
_NCp1_NAt_Prd_2(&(*_Lvd_0)._Ftype, _Lr_1);
_NCp1_NVarFlags_Prd_2(&(*_Lvd_0)._Fflags, _Lr_1);
if(((*_Lvd_0)._Fflags & _NCp1_NVarFlags_Creal_name) != _NCp1_NVarFlags_C0) {
_NCp1_NId_Prd_2(&(*_Lvd_0)._Freal_name, _Lr_1);
}
_NCp1_NTypeInfo_Prd_2(&(*_Lvd_0)._Ftype_info, _Lr_1);
(*_Lvd_0)._Fsize_c = _NCp1_NRdr_Pn1_1(_Lr_1);
if((*_Lvd_0)._Fsize_c > 0) {
_NCp1_Pquick_alloc_arr_2((*_Lvd_0)._Fsize_expr_v, (*_Lvd_0)._Fsize_c);
_NCp1_Pquick_alloc_arr_2((*_Lvd_0)._Fsize_value_v, (*_Lvd_0)._Fsize_c);
int32_t _Li_2;
_Li_2 = 0;
for(int i = (*_Lvd_0)._Fsize_c; i > 0; ) {
i --;
_NCp1_NExprI_Prd_2(&(*_Lvd_0)._Fsize_expr_v[_Li_2], _Lr_1);
continue_0:;
_Li_2++;
}
break_0:;
}
}
inline void _NCp1_NCvarFlags_Prd_2(_NCp1_NCvarFlags* _Lf_0, union _NCp1_NRdr* _Lr_1) {
(*_Lf_0) = (_NCp1_NCvarFlags)(_NCp1_NRdr_Pn1_1(_Lr_1));
}
void _NCp1_NExprI_Prd_2(_NCp1_NExprI* _Le_0, union _NCp1_NRdr* _Lr_1) {
_NCp1_NExprType _Ltype_2;
if(_NCp1_Cdebug_rd_wr) {
if(_NCp1_NRdr_Pn1_1(_Lr_1) != 255) {
fprintf(stdout, "Error reading expr\n");
fflush(stdout);
exit(_NStdc_NExit_Cfailure);
}
}
_NCp1_NExprType_Prd_2(&_Ltype_2, _Lr_1);
if(_Ltype_2 == _NCp1_NExprType_Cnil) {
(*_Le_0) = _NCp1_NExprI_Cnil;
} else {
_NCp1_NExprI _Le_idx_3;
_Le_idx_3 = (_NCp1_NExprI)(_Gexpr_c++);
if(_Gexpr_cap <= _Gexpr_c) {
int32_t _Lold_cap_4;
_Lold_cap_4 = _Gexpr_cap;
_NCp1_Pgrow_2(_Gexpr_cap, _Gexpr_c);
_NCp1_Prealloc_3(_Gexpr_v, _Gexpr_cap, _Lold_cap_4);
_NCp1_Prealloc_3(_Gexpr_is_processed, (_Gexpr_cap + 7) >> 3, (_Lold_cap_4 + 7) >> 3);
}
(*_Le_0) = _Le_idx_3;
switch(_Ltype_2) {
case _NCp1_NExprType_Cassign:;
_NCp1_NExprI_Prd_assign_2(_Le_idx_3, _Lr_1);
break;
case _NCp1_NExprType_Ccompare:;
_NCp1_NExprI_Prd_compare_2(_Le_idx_3, _Lr_1);
break;
case _NCp1_NExprType_Cbool:;
_NCp1_NExprI_Prd_bool_2(_Le_idx_3, _Lr_1);
break;
case _NCp1_NExprType_Cchar:;
_NCp1_NExprI_Prd_char_2(_Le_idx_3, _Lr_1);
break;
case _NCp1_NExprType_Cmath:;
_NCp1_NExprI_Prd_math_2(_Le_idx_3, _Lr_1);
break;
case _NCp1_NExprType_Cunary:;
_NCp1_NExprI_Prd_unary_2(_Le_idx_3, _Lr_1);
break;
case _NCp1_NExprType_Cref:;
_NCp1_NExprI_Prd_ref_2(_Le_idx_3, _Lr_1);
break;
case _NCp1_NExprType_Ccast_fast:;
_NCp1_NExprI_Prd_cast_fast_2(_Le_idx_3, _Lr_1);
break;
case _NCp1_NExprType_Clvar:;
_NCp1_NExprI_Prd_lvar_2(_Le_idx_3, _Lr_1);
break;
case _NCp1_NExprType_Cfvar:;
_NCp1_NExprI_Prd_fvar_2(_Le_idx_3, _Lr_1);
break;
case _NCp1_NExprType_Cgvar:;
_NCp1_NExprI_Prd_gvar_2(_Le_idx_3, _Lr_1);
break;
case _NCp1_NExprType_Ccvar:;
_NCp1_NExprI_Prd_cvar_2(_Le_idx_3, _Lr_1);
break;
case _NCp1_NExprType_Cbools:;
_NCp1_NExprI_Prd_bools_2(_Le_idx_3, _Lr_1);
break;
case _NCp1_NExprType_Cmethod:;
_NCp1_NExprI_Prd_method_2(_Le_idx_3, _Lr_1);
break;
case _NCp1_NExprType_Cfunc:;
_NCp1_NExprI_Prd_func_2(_Le_idx_3, _Lr_1);
break;
case _NCp1_NExprType_Cstr:;
_NCp1_NExprI_Prd_str_2(_Le_idx_3, _Lr_1);
break;
case _NCp1_NExprType_Ci32:;
_NCp1_NExprI_Prd_i32_2(_Le_idx_3, _Lr_1);
break;
case _NCp1_NExprType_Csize_of_type:;
_NCp1_NExprI_Prd_size_of_type_2(_Le_idx_3, _Lr_1);
break;
case _NCp1_NExprType_Cnull:;
_NCp1_NExprI_Prd_null_2(_Le_idx_3, _Lr_1);
break;
case _NCp1_NExprType_Cindex:;
_NCp1_NExprI_Prd_index_2(_Le_idx_3, _Lr_1);
break;
default:;
fprintf(stdout, "rd() was not implemented in expression #%s\n", _NCp1_NExprType_Pcp1_name_1(_Ltype_2));
exit(_NStdc_NExit_Cfailure);
break;
}
}
if(_NCp1_Cdebug_rd_wr) {
if(_NCp1_NRdr_Pn1_1(_Lr_1) != 255) {
fprintf(stdout, "Error reading expr\n");
fflush(stdout);
exit(_NStdc_NExit_Cfailure);
}
}
}
inline void _NCp1_NCvar_Prd_2(_NCp1_NCvar* _Lc_0, union _NCp1_NRdr* _Lr_1) {
_NCp1_NCvar _Lidx_2;
_Lidx_2 = ((_NCp1_NCvar)(Fgetnum(_Lr_1) - 1));
if(_Lidx_2 == _NCp1_NCvar_Cnil) {
(*_Lc_0) = _NCp1_NCvar_Cnil;
} else {
(*_Lc_0) = _Gcvar_table[_Lidx_2];
}
}
inline void _NCp1_NEnumFlags_Prd_2(_NCp1_NEnumFlags* _Le_0, union _NCp1_NRdr* _Lr_1) {
(*_Le_0) = (_NCp1_NEnumFlags)(_NCp1_NRdr_Pn1_1(_Lr_1));
}
inline void _NCp1_NStructFlags_Prd_2(_NCp1_NStructFlags* _Lf_0, union _NCp1_NRdr* _Lr_1) {
(*_Lf_0) = (_NCp1_NStructFlags)(_NCp1_NRdr_Pn1_1(_Lr_1));
}
void _NCp1_NFarg_Prd_2(struct _NCp1_NFarg* _Lf_0, union _NCp1_NRdr* _Lr_1) {
_NCp1_NDeclVarData_Prd_2(&(*_Lf_0)._Fdecl, _Lr_1);
}
inline void _NCp1_NFuncFlags_Prd_2(_NCp1_NFuncFlags* _Le_0, union _NCp1_NRdr* _Lr_1) {
(*_Le_0) = (_NCp1_NFuncFlags)(Fgetnum(_Lr_1));
}
void* qalloc(int32_t _Lsize_0) {
if(sizeof(void*) == 8) {
_Lsize_0 = ((_Lsize_0 + 7) & (-1 ^ 7));
} else {
_Lsize_0 = ((_Lsize_0 + 3) & (-1 ^ 3));
}
if(_Lsize_0 <= (_Gquick_alloc_cap - _Gquick_alloc_c)) {
union _NCp1_NRdr _Lr_1;
_Lr_1._Freff = _Gquick_alloc_v;
_Lr_1._Fpos += _Gquick_alloc_c;
_Gquick_alloc_c += _Lsize_0;
return _Lr_1._Freff;
}
_NCp1_Pgrow_2(_Gquick_alloc_cap, _Gquick_alloc_c + _Lsize_0);
_Gquick_alloc_v = malloc(_Gquick_alloc_cap);
memset(_Gquick_alloc_v, 0, _Gquick_alloc_cap);
_Gquick_alloc_c = _Lsize_0;
return _Gquick_alloc_v;
}
inline void _NCp1_NFunc_Prd_2(_NCp1_NFunc* _Lf_0, union _NCp1_NRdr* _Lr_1) {
(*_Lf_0) = ((_NCp1_NFunc)(Fgetnum(_Lr_1) - _NCp1_NFunc_C1));
}
inline uint32_t _NCp1_NRdr_Pn4_1(union _NCp1_NRdr* _Lr_0) {
uint32_t _Lval_1;
_Lval_1 = (uint32_t)((*_Lr_0)._Fp1[0]);
_Lval_1 |= ((*_Lr_0)._Fp1[1] << 8);
_Lval_1 |= ((*_Lr_0)._Fp1[2] << 16);
_Lval_1 |= ((*_Lr_0)._Fp1[3] << 24);
(*_Lr_0)._Fpos += 4;
return _Lval_1;
}
inline struct _NCp1_NFileData* _NCp1_NFile_Pptr_1(_NCp1_NFile _Lf_0) {
return &_Gfile_v[_Lf_0];
}
_NCp1_NAt _NCp1_Pat_validate_5(_NCp1_NAt _Lvd_type_0, _NCp1_NAt _Lat_i_1, _NCp1_NFile _Lfile_2, uint32_t _Lrow_3, uint32_t _Lcol_4) {
struct _NCp1_NAtData* _Ltype_5;
struct _NCp1_NAtData* _Lparent_6;
_Ltype_5 = _NCp1_NAt_Pptr_1(_Lvd_type_0);
_Lparent_6 = _NCp1_NAt_Pptr_1((*_Ltype_5)._Fparent);
if((((*_Lparent_6)._Ftype == _NCp1_NNameType_Cbasic) && ((*_Lparent_6)._Fname._Fbasic == _NCp1_NBasicTypeId_Crelative))) {
union _NCp1_NAtName* _Lname_7;
_Lname_7 = (&(*_Ltype_5)._Fname);
while(1) {
_NCp1_NAt _Li_8;
_Li_8 = (_NCp1_NAt)(0);
for(int i = _Gat_c; i > 0; ) {
i --;
if(((_Gat_v[_Li_8]._Fparent == _Lat_i_1) && (_Gat_v[_Li_8]._Ftype != _NCp1_NNameType_Cbasic))) {
if(_Gat_v[_Li_8]._Fname._Fid == (*_Lname_7)._Fid) {
return _Li_8;
}
}
continue_1:;
_Li_8++;
}
break_1:;
if(_Lat_i_1 == _NCp1_NAt_Croot) {
goto break_0;
}
_Lat_i_1 = (*_NCp1_NAt_Pptr_1(_Lat_i_1))._Fparent;
continue_0:;
}
break_0:;
fprintf(stdout, "%s:%u:%u: Type :%s was not found\n", _NCp1_NFile_Ppath_1(_Lfile_2), _Lrow_3, _Lcol_4, _NCp1_NId_Pstr_1((*_Lname_7)._Fid));
exit(_NStdc_NExit_Cfailure);
}
return _Lvd_type_0;
}
bool _NCp1_NAt_Pfinalize_4(_NCp1_NAt _Lat_i_0, struct _NCp1_NTypeInfo* _Lti_1, int32_t _Lrow_2, int32_t _Lcol_3) {
struct _NCp1_NAtData* _Lat_4;
_Lat_4 = _NCp1_NAt_Pptr_1(_Lat_i_0);
if((*_Lat_4)._Fdef == _NCp1_NAtDef_Cstruct) {
if((*_Lti_1)._Fbuilt_in) {
if((*_Lti_1)._Fref_v[0] != 0) {
fprintf(stdout, "%s:%d:%d: Can:T use plus symbol (+) because type '/%s' has reference\n", _NCp1_NFile_Ppath_1((*_Gctx_func)._Ffile), _Lrow_2, _Lcol_3, _NCp1_NId_Pstr_1((*_Lat_4)._Fname._Fid));
return false;
}
(*_Lti_1)._Fref_v[0] = -1;
}
} else {
if((*_Lti_1)._Fbuilt_in) {
fprintf(stdout, "%s:%d:%d: Can:T use plus symbol (+) because type is not a struct\n", _NCp1_NFile_Ppath_1((*_Gctx_func)._Ffile), _Lrow_2, _Lcol_3);
return false;
}
}
return true;
}
void _NCp1_NDeclFunc_Plvars_rd_2(struct _NCp1_NDeclFunc* _Lf_0, union _NCp1_NRdr* _Lr_1) {
_NCp1_NLvar _Llvar_c_2;
_Llvar_c_2 = (_NCp1_NLvar)(Fgetnum(_Lr_1));
(*_Lf_0)._Flvar_c = _Llvar_c_2;
_NCp1_Pquick_alloc_arr_2((*_Lf_0)._Flvar_v, _Llvar_c_2);
int32_t _Li_3;
_Li_3 = 0;
for(int i = (*_Lf_0)._Flvar_c; i > 0; ) {
i --;
struct _NCp1_NLvarData* _Ll_4;
_Ll_4 = (&(*_Lf_0)._Flvar_v[_Li_3]);
(*_Ll_4)._Frow = Fgetnum(_Lr_1);
(*_Ll_4)._Fcol = Fgetnum(_Lr_1);
_NCp1_NDeclVarData_Prd_2(&(*_Ll_4)._Fdecl, _Lr_1);
_NCp1_NLvarFlags_Prd_2(&(*_Ll_4)._Fflags, _Lr_1);
if(((*_Ll_4)._Fflags & _NCp1_NLvarFlags_Cset_expr) != _NCp1_NLvarFlags_C0) {
_NCp1_NExprI_Prd_2(&(*_Ll_4)._Fset_expr, _Lr_1);
}
continue_0:;
_Li_3++;
}
break_0:;
}
void _NCp1_NStmtSpace_Prd_3(struct _NCp1_NStmtSpace* _Lspace_0, union _NCp1_NRdr* _Lr_1, struct _NCp1_NStmtSpace* _Lparent_2) {
uint32_t _Llvar_c_3;
(*_Lspace_0)._Fparent = _Lparent_2;
(*_Lspace_0)._Fstmt_first = NULL;
(*_Lspace_0)._Fstmt_last = NULL;
_Llvar_c_3 = Fgetnum(_Lr_1);
(*_Lspace_0)._Flvar_c = _Llvar_c_3;
_NCp1_Pquick_alloc_arr_2((*_Lspace_0)._Flvar_v, _Llvar_c_3);
int32_t _Li_4;
_Li_4 = 0;
for(int i = _Llvar_c_3; i > 0; ) {
i --;
_NCp1_NLvar_Prd_2(&(*_Lspace_0)._Flvar_v[_Li_4], _Lr_1);
continue_0:;
_Li_4++;
}
break_0:;
while(1) {
_NCp1_NStmtType _Ltype_5;
uint32_t _Lbegin_row_6;
uint32_t _Lbegin_col_7;
uint32_t _Lend_row_8;
uint32_t _Lend_col_9;
_NCp1_NStmtType_Prd_2(&_Ltype_5, _Lr_1);
if(_Ltype_5 == _NCp1_NStmtType_Cnil) {
goto break_1;
}
if(_NCp1_Cdebug_rd_wr) {
if(_NCp1_NRdr_Pn1_1(_Lr_1) != 255) {
fprintf(stdout, "Error reading stmt\n");
fflush(stdout);
exit(_NStdc_NExit_Cfailure);
}
}
_Lbegin_row_6 = Fgetnum(_Lr_1);
_Lbegin_col_7 = Fgetnum(_Lr_1);
_Lend_row_8 = Fgetnum(_Lr_1);
_Lend_col_9 = Fgetnum(_Lr_1);
_Gctx_begin_row = _Lbegin_row_6;
_Gctx_begin_col = _Lbegin_col_7;
_Gctx_end_row = _Lend_row_8;
_Gctx_end_col = _Lend_col_9;
switch(_Ltype_5) {
case _NCp1_NStmtType_Cexpr:;
_NCp1_NStmtSpace_Prd_expr_2(_Lspace_0, _Lr_1);
break;
case _NCp1_NStmtType_Cif:;
_NCp1_NStmtSpace_Prd_if_2(_Lspace_0, _Lr_1);
break;
case _NCp1_NStmtType_Cif_elif:;
_NCp1_NStmtSpace_Prd_if_elif_2(_Lspace_0, _Lr_1);
break;
case _NCp1_NStmtType_Cif_else:;
_NCp1_NStmtSpace_Prd_if_else_2(_Lspace_0, _Lr_1);
break;
case _NCp1_NStmtType_Cif_end:;
_NCp1_NStmtSpace_Prd_if_end_2(_Lspace_0, _Lr_1);
break;
case _NCp1_NStmtType_Cswitch:;
_NCp1_NStmtSpace_Prd_switch_2(_Lspace_0, _Lr_1);
break;
case _NCp1_NStmtType_Ccase:;
_NCp1_NStmtSpace_Prd_case_2(_Lspace_0, _Lr_1);
break;
case _NCp1_NStmtType_Ccase_end:;
_NCp1_NStmtSpace_Prd_case_end_2(_Lspace_0, _Lr_1);
break;
case _NCp1_NStmtType_Cdefault:;
_NCp1_NStmtSpace_Prd_default_2(_Lspace_0, _Lr_1);
break;
case _NCp1_NStmtType_Cdefault_end:;
_NCp1_NStmtSpace_Prd_default_end_2(_Lspace_0, _Lr_1);
break;
case _NCp1_NStmtType_Cswitch_end:;
_NCp1_NStmtSpace_Prd_switch_end_2(_Lspace_0, _Lr_1);
break;
case _NCp1_NStmtType_Cdo:;
_NCp1_NStmtSpace_Prd_do_2(_Lspace_0, _Lr_1);
break;
case _NCp1_NStmtType_Cdo_end:;
_NCp1_NStmtSpace_Prd_do_end_2(_Lspace_0, _Lr_1);
break;
case _NCp1_NStmtType_Cwhile:;
_NCp1_NStmtSpace_Prd_while_2(_Lspace_0, _Lr_1);
break;
case _NCp1_NStmtType_Cwhile_end:;
_NCp1_NStmtSpace_Prd_while_end_2(_Lspace_0, _Lr_1);
break;
case _NCp1_NStmtType_Ccontinue:;
_NCp1_NStmtSpace_Prd_continue_2(_Lspace_0, _Lr_1);
break;
case _NCp1_NStmtType_Cbreak:;
_NCp1_NStmtSpace_Prd_break_2(_Lspace_0, _Lr_1);
break;
case _NCp1_NStmtType_Creturn:;
_NCp1_NStmtSpace_Prd_return_2(_Lspace_0, _Lr_1);
break;
case _NCp1_NStmtType_Cspace:;
_NCp1_NStmtSpace_Prd_space_2(_Lspace_0, _Lr_1);
break;
default:;
fprintf(stdout, "rd() not yet implemented in stmt #%s\n", _NCp1_NStmtType_Pcp1_name_1(_Ltype_5));
exit(_NStdc_NExit_Cfailure);
break;
}
if(_NCp1_Cdebug_rd_wr) {
if(_NCp1_NRdr_Pn1_1(_Lr_1) != 255) {
fprintf(stdout, "Error reading stmt\n");
fflush(stdout);
exit(_NStdc_NExit_Cfailure);
}
}
continue_1:;
}
break_1:;
}
bool _NCp1_NStmt_Pprocess_1(struct _NCp1_NStmt* _Ls_0) {
bool _Lok_1;
_Lok_1 = false;
_Gctx_begin_row = (*_Ls_0)._Fbegin_row;
_Gctx_begin_col = (*_Ls_0)._Fbegin_col;
_Gctx_end_row = (*_Ls_0)._Fend_row;
_Gctx_end_col = (*_Ls_0)._Fend_col;
switch((*_Ls_0)._Ftype) {
case _NCp1_NStmtType_Cexpr:;
_NCp1_NStmt_Pprocess_expr_2(_Ls_0, &_Lok_1);
break;
case _NCp1_NStmtType_Cif:;
_NCp1_NStmt_Pprocess_if_2(_Ls_0, &_Lok_1);
break;
case _NCp1_NStmtType_Cif_elif:;
_NCp1_NStmt_Pprocess_if_elif_2(_Ls_0, &_Lok_1);
break;
case _NCp1_NStmtType_Cif_else:;
_NCp1_NStmt_Pprocess_if_else_2(_Ls_0, &_Lok_1);
break;
case _NCp1_NStmtType_Cif_end:;
_NCp1_NStmt_Pprocess_if_end_2(_Ls_0, &_Lok_1);
break;
case _NCp1_NStmtType_Cswitch:;
_NCp1_NStmt_Pprocess_switch_2(_Ls_0, &_Lok_1);
break;
case _NCp1_NStmtType_Ccase:;
_NCp1_NStmt_Pprocess_case_2(_Ls_0, &_Lok_1);
break;
case _NCp1_NStmtType_Ccase_end:;
_NCp1_NStmt_Pprocess_case_end_2(_Ls_0, &_Lok_1);
break;
case _NCp1_NStmtType_Cdefault:;
_NCp1_NStmt_Pprocess_default_2(_Ls_0, &_Lok_1);
break;
case _NCp1_NStmtType_Cdefault_end:;
_NCp1_NStmt_Pprocess_default_end_2(_Ls_0, &_Lok_1);
break;
case _NCp1_NStmtType_Cswitch_end:;
_NCp1_NStmt_Pprocess_switch_end_2(_Ls_0, &_Lok_1);
break;
case _NCp1_NStmtType_Cdo:;
_NCp1_NStmt_Pprocess_do_2(_Ls_0, &_Lok_1);
break;
case _NCp1_NStmtType_Cdo_end:;
_NCp1_NStmt_Pprocess_do_end_2(_Ls_0, &_Lok_1);
break;
case _NCp1_NStmtType_Cwhile:;
_NCp1_NStmt_Pprocess_while_2(_Ls_0, &_Lok_1);
break;
case _NCp1_NStmtType_Cwhile_end:;
_NCp1_NStmt_Pprocess_while_end_2(_Ls_0, &_Lok_1);
break;
case _NCp1_NStmtType_Ccontinue:;
_NCp1_NStmt_Pprocess_continue_2(_Ls_0, &_Lok_1);
break;
case _NCp1_NStmtType_Cbreak:;
_NCp1_NStmt_Pprocess_break_2(_Ls_0, &_Lok_1);
break;
case _NCp1_NStmtType_Creturn:;
_NCp1_NStmt_Pprocess_return_2(_Ls_0, &_Lok_1);
break;
case _NCp1_NStmtType_Cspace:;
_NCp1_NStmt_Pprocess_space_2(_Ls_0, &_Lok_1);
break;
default:;
fprintf(stdout, "%s:%u:%u - %u:%u: process() is not implemented in statement #%s\n", _NCp1_NFile_Ppath_1((*_Gctx_func)._Ffile), (*_Ls_0)._Fbegin_row, (*_Ls_0)._Fbegin_col, (*_Ls_0)._Fend_row, (*_Ls_0)._Fend_col, _NCp1_NStmtType_Pcp1_name_1((*_Ls_0)._Ftype));
break;
}
if(!(_Lok_1)) {
fprintf(stdout, "%s:%u:%u - %u:%u: Processing of statement #%s failed\n", _NCp1_NFile_Ppath_1((*_Gctx_func)._Ffile), (*_Ls_0)._Fbegin_row, (*_Ls_0)._Fbegin_col, (*_Ls_0)._Fend_row, (*_Ls_0)._Fend_col, _NCp1_NStmtType_Pcp1_name_1((*_Ls_0)._Ftype));
}
return _Lok_1;
}
inline struct _NCp1_NLvarData* _NCp1_NLvar_Pptr_1(_NCp1_NLvar _Ll_0) {
return &(*_Gctx_func)._Flvar_v[_Ll_0];
}
bool _NCp1_NExprI_Pvalue_4(_NCp1_NExprI _Le_0, int32_t _Lreff_1, bool _Lparen_2, struct _NCp1_NValue* _Lv_3) {
struct _NCp1_NExpr* _Lexpr_4;
bool _Lok_5;
if(!(_NCp1_NExprI_Pprocess_1(_Le_0))) {
return false;
}
_Lexpr_4 = _NCp1_NExprI_Pptr_1(_Le_0);
_Lok_5 = false;
switch((*_Lexpr_4)._Ftype) {
case _NCp1_NExprType_Cassign:;
_NCp1_NExprI_Pvalue_assign_5(_Le_0, _Lreff_1, _Lparen_2, _Lv_3, &_Lok_5);
break;
case _NCp1_NExprType_Ccompare:;
_NCp1_NExprI_Pvalue_compare_5(_Le_0, _Lreff_1, _Lparen_2, _Lv_3, &_Lok_5);
break;
case _NCp1_NExprType_Cbool:;
_NCp1_NExprI_Pvalue_bool_5(_Le_0, _Lreff_1, _Lparen_2, _Lv_3, &_Lok_5);
break;
case _NCp1_NExprType_Cchar:;
_NCp1_NExprI_Pvalue_char_5(_Le_0, _Lreff_1, _Lparen_2, _Lv_3, &_Lok_5);
break;
case _NCp1_NExprType_Cmath:;
_NCp1_NExprI_Pvalue_math_5(_Le_0, _Lreff_1, _Lparen_2, _Lv_3, &_Lok_5);
break;
case _NCp1_NExprType_Cunary:;
_NCp1_NExprI_Pvalue_unary_5(_Le_0, _Lreff_1, _Lparen_2, _Lv_3, &_Lok_5);
break;
case _NCp1_NExprType_Cref:;
_NCp1_NExprI_Pvalue_ref_5(_Le_0, _Lreff_1, _Lparen_2, _Lv_3, &_Lok_5);
break;
case _NCp1_NExprType_Ccast_fast:;
_NCp1_NExprI_Pvalue_cast_fast_5(_Le_0, _Lreff_1, _Lparen_2, _Lv_3, &_Lok_5);
break;
case _NCp1_NExprType_Clvar:;
_NCp1_NExprI_Pvalue_lvar_5(_Le_0, _Lreff_1, _Lparen_2, _Lv_3, &_Lok_5);
break;
case _NCp1_NExprType_Cfvar:;
_NCp1_NExprI_Pvalue_fvar_5(_Le_0, _Lreff_1, _Lparen_2, _Lv_3, &_Lok_5);
break;
case _NCp1_NExprType_Cgvar:;
_NCp1_NExprI_Pvalue_gvar_5(_Le_0, _Lreff_1, _Lparen_2, _Lv_3, &_Lok_5);
break;
case _NCp1_NExprType_Ccvar:;
_NCp1_NExprI_Pvalue_cvar_5(_Le_0, _Lreff_1, _Lparen_2, _Lv_3, &_Lok_5);
break;
case _NCp1_NExprType_Cbools:;
_NCp1_NExprI_Pvalue_bools_5(_Le_0, _Lreff_1, _Lparen_2, _Lv_3, &_Lok_5);
break;
case _NCp1_NExprType_Cfunc:;
_NCp1_NExprI_Pvalue_func_5(_Le_0, _Lreff_1, _Lparen_2, _Lv_3, &_Lok_5);
break;
case _NCp1_NExprType_Cmethod:;
_NCp1_NExprI_Pvalue_method_5(_Le_0, _Lreff_1, _Lparen_2, _Lv_3, &_Lok_5);
break;
case _NCp1_NExprType_Cstr:;
_NCp1_NExprI_Pvalue_str_5(_Le_0, _Lreff_1, _Lparen_2, _Lv_3, &_Lok_5);
break;
case _NCp1_NExprType_Ci32:;
_NCp1_NExprI_Pvalue_i32_5(_Le_0, _Lreff_1, _Lparen_2, _Lv_3, &_Lok_5);
break;
case _NCp1_NExprType_Csize_of_type:;
_NCp1_NExprI_Pvalue_size_of_type_5(_Le_0, _Lreff_1, _Lparen_2, _Lv_3, &_Lok_5);
break;
case _NCp1_NExprType_Cnull:;
_NCp1_NExprI_Pvalue_null_5(_Le_0, _Lreff_1, _Lparen_2, _Lv_3, &_Lok_5);
break;
case _NCp1_NExprType_Cindex:;
_NCp1_NExprI_Pvalue_index_5(_Le_0, _Lreff_1, _Lparen_2, _Lv_3, &_Lok_5);
break;
default:;
fprintf(stdout, "%u:%u - %u:%u: value() not implemented for #%s\n", _Gctx_begin_row, _Gctx_begin_col, _Gctx_end_row, _Gctx_end_col, _NCp1_NExprType_Pcp1_name_1((*_Lexpr_4)._Ftype));
break;
}
return _Lok_5;
}
void _NCp1_NTypeInfo_Pinit_1(struct _NCp1_NTypeInfo* _Lti_0) {
(*_Lti_0)._Fref_v[0] = 0;
(*_Lti_0)._Farray_c = 0;
(*_Lti_0)._Fstar_c = 0;
(*_Lti_0)._Fbuilt_in = false;
(*_Lti_0)._Fconst = false;
}
void _NCp1_NTypeInfo_Pcopy_from_2(struct _NCp1_NTypeInfo* _Lti_0, struct _NCp1_NTypeInfo* _Lti2_1) {
memcpy((*_Lti_0)._Fref_v, (*_Lti2_1)._Fref_v, _NCp1_Ctype_info_star_limit);
(*_Lti_0)._Farray_c = (*_Lti2_1)._Farray_c;
(*_Lti_0)._Fstar_c = (*_Lti2_1)._Fstar_c;
(*_Lti_0)._Fconst = (*_Lti2_1)._Fconst;
}
bool _NCp1_NDeclVarData_Pprocess_5(struct _NCp1_NDeclVarData* _Lvd_0, _NCp1_NFile _Lfile_1, int32_t _Lrow_2, int32_t _Lcol_3, _NCp1_NAt _Lbase_at_4) {
_NCp1_NAt _Lat_i_5;
struct _NCp1_NAtData* _Lat_6;
_Lat_i_5 = _NCp1_Pat_validate_5((*_Lvd_0)._Ftype, _Lbase_at_4, _Lfile_1, _Lrow_2, _Lcol_3);
(*_Lvd_0)._Ftype = _Lat_i_5;
_Lat_6 = _NCp1_NAt_Pptr_1(_Lat_i_5);
if((((*_Lat_6)._Ftype != _NCp1_NNameType_Cbasic) && ((*_Lat_6)._Fdecl._Fstruct == _NCp1_NStruct_Cnil))) {
fprintf(stdout, "%s:%u:%u: Error, the type '%s' used in '%s' was not defined\n", _NCp1_NFile_Ppath_1((*_Gctx_func)._Ffile), _Lrow_2, _Lcol_3, _NCp1_NId_Pstr_1((*_Lat_6)._Fname._Fid), _NCp1_NId_Pstr_1((*_Lvd_0)._Fname));
return false;
}
_NCp1_NAt_Poutput_4(_Lat_i_5, (*_Gctx_func)._Ffile, _Lrow_2, _Lcol_3);
if(!(_NCp1_NAt_Pfinalize_4(_Lat_i_5, &(*_Lvd_0)._Ftype_info, _Lrow_2, _Lcol_3))) {
return false;
}
int32_t _Li_7;
_Li_7 = 0;
for(int i = (*_Lvd_0)._Fsize_c; i > 0; ) {
i --;
if(!(_NCp1_NExprI_Pvalue_4((*_Lvd_0)._Fsize_expr_v[_Li_7], 1, false, &(*_Lvd_0)._Fsize_value_v[_Li_7]))) {
return false;
}
continue_0:;
_Li_7++;
}
break_0:;
return true;
}
void _NCp1_NStruct_Poutput_1(_NCp1_NStruct _Ls_i_0) {
uint32_t _Lnum_1;
uint32_t _Ln3_2;
int32_t _Ln17_3;
struct _NCp1_NStructData* _Ls_4;
_NCp1_NAt _Ls_at_5;
_NCp1_NFile _Ls_file_6;
int32_t _Ls_row_7;
int32_t _Ls_col_8;
_Lnum_1 = (uint32_t)(_Ls_i_0);
_Ln3_2 = (_Lnum_1 >> 3);
_Ln17_3 = (1 << (_Lnum_1 & 7));
if((_Gstruct_is_outputted[_Ln3_2] & _Ln17_3) != 0) {
return;
}
_Gstruct_is_outputted[_Ln3_2] |= _Ln17_3;
_Ls_4 = _NCp1_NStruct_Pptr_1(_Ls_i_0);
_Ls_at_5 = (*_Ls_4)._Fat;
_Ls_file_6 = (*_Ls_4)._Ffile;
_Ls_row_7 = (*_Ls_4)._Fbegin_row;
_Ls_col_8 = (*_Ls_4)._Fbegin_col;
int32_t _Li_9;
_Li_9 = 0;
for(int i = (*_Ls_4)._Ffvar_c; i > 0; ) {
i --;
(*_Ls_4)._Ffvar_v[_Li_9]._Fdecl._Ftype = _NCp1_Pat_validate_5((*_Ls_4)._Ffvar_v[_Li_9]._Fdecl._Ftype, _Ls_at_5, _Ls_file_6, _Ls_row_7, _Ls_col_8);
if(!(_NCp1_NDeclVarData_Pprocess_5(&(*_Ls_4)._Ffvar_v[_Li_9]._Fdecl, _Ls_file_6, _Ls_row_7, _Ls_col_8, _Ls_at_5))) {
fprintf(stdout, "err\n");
exit(_NStdc_NExit_Cfailure);
return;
}
continue_0:;
_Li_9++;
}
break_0:;
if((*_Ls_4)._Finclude != _NCp1_NInclude_Cnil) {
_NCp1_NInclude_Poutput_1((*_Ls_4)._Finclude);
}
if(((*_Ls_4)._Fflags & _NCp1_NStructFlags_Cno_decl) == _NCp1_NStructFlags_C0) {
_Gstruct_outputted_v[_Gstruct_outputted_c++] = _Ls_i_0;
}
}
void _NCp1_NEnum_Poutput_1(_NCp1_NEnum _Le_i_0) {
uint32_t _Lnum_1;
uint32_t _Ln3_2;
int32_t _Ln17_3;
struct _NCp1_NEnumData* _Le_4;
_Lnum_1 = (uint32_t)(_Le_i_0);
_Ln3_2 = (_Lnum_1 >> 3);
_Ln17_3 = (1 << (_Lnum_1 & 7));
if((_Genum_is_outputted[_Ln3_2] & _Ln17_3) != 0) {
return;
}
_Genum_is_outputted[_Ln3_2] |= _Ln17_3;
_Le_4 = _NCp1_NEnum_Pptr_1(_Le_i_0);
_NCp1_NAt_Poutput_4((*_Le_4)._Fbase_type, (*_Le_4)._Ffile, (*_Le_4)._Fbegin_row, (*_Le_4)._Fbegin_col);
if((*_Le_4)._Finclude != _NCp1_NInclude_Cnil) {
_NCp1_NInclude_Poutput_1((*_Le_4)._Finclude);
}
_Genum_outputted_v[_Genum_outputted_c++] = _Le_i_0;
}
bool _NCp1_NExprI_Pprocess_1(_NCp1_NExprI _Le_0) {
uint32_t _Lnum_1;
uint32_t _Ln3_2;
int32_t _Ln17_3;
struct _NCp1_NExpr* _Lexpr_4;
bool _Lok_5;
if(_Le_0 == _NCp1_NExprI_Cnil) {
fprintf(stdout, "%s:%u:%u - %u:%u: Processed a nil expression\n", _NCp1_NFile_Ppath_1((*_Gctx_func)._Ffile), _Gctx_begin_row, _Gctx_begin_col, _Gctx_end_row, _Gctx_end_col);
return false;
}
_Lnum_1 = (uint32_t)(_Le_0);
_Ln3_2 = (_Lnum_1 >> 3);
_Ln17_3 = (1 << (_Lnum_1 & 7));
if((_Gexpr_is_processed[_Ln3_2] & _Ln17_3) != _NCp1_NExprI_C0) {
return true;
}
_Gexpr_is_processed[_Ln3_2] |= _Ln17_3;
_Lexpr_4 = _NCp1_NExprI_Pptr_1(_Le_0);
_Lok_5 = false;
switch((*_Lexpr_4)._Ftype) {
case _NCp1_NExprType_Cassign:;
_NCp1_NExprI_Pprocess_assign_2(_Lexpr_4, &_Lok_5);
break;
case _NCp1_NExprType_Ccompare:;
_NCp1_NExprI_Pprocess_compare_2(_Lexpr_4, &_Lok_5);
break;
case _NCp1_NExprType_Cbool:;
_NCp1_NExprI_Pprocess_bool_2(_Lexpr_4, &_Lok_5);
break;
case _NCp1_NExprType_Cchar:;
_NCp1_NExprI_Pprocess_char_2(_Lexpr_4, &_Lok_5);
break;
case _NCp1_NExprType_Cmath:;
_NCp1_NExprI_Pprocess_math_2(_Lexpr_4, &_Lok_5);
break;
case _NCp1_NExprType_Cunary:;
_NCp1_NExprI_Pprocess_unary_2(_Lexpr_4, &_Lok_5);
break;
case _NCp1_NExprType_Cref:;
_NCp1_NExprI_Pprocess_ref_2(_Lexpr_4, &_Lok_5);
break;
case _NCp1_NExprType_Ccast_fast:;
_NCp1_NExprI_Pprocess_cast_fast_2(_Lexpr_4, &_Lok_5);
break;
case _NCp1_NExprType_Clvar:;
_NCp1_NExprI_Pprocess_lvar_2(_Lexpr_4, &_Lok_5);
break;
case _NCp1_NExprType_Cfvar:;
_NCp1_NExprI_Pprocess_fvar_2(_Lexpr_4, &_Lok_5);
break;
case _NCp1_NExprType_Cgvar:;
_NCp1_NExprI_Pprocess_gvar_2(_Lexpr_4, &_Lok_5);
break;
case _NCp1_NExprType_Ccvar:;
_NCp1_NExprI_Pprocess_cvar_2(_Lexpr_4, &_Lok_5);
break;
case _NCp1_NExprType_Cbools:;
_NCp1_NExprI_Pprocess_bools_2(_Lexpr_4, &_Lok_5);
break;
case _NCp1_NExprType_Cmethod:;
_NCp1_NExprI_Pprocess_method_2(_Lexpr_4, &_Lok_5);
break;
case _NCp1_NExprType_Cfunc:;
_NCp1_NExprI_Pprocess_func_2(_Lexpr_4, &_Lok_5);
break;
case _NCp1_NExprType_Cstr:;
_NCp1_NExprI_Pprocess_str_2(_Lexpr_4, &_Lok_5);
break;
case _NCp1_NExprType_Ci32:;
_NCp1_NExprI_Pprocess_i32_2(_Lexpr_4, &_Lok_5);
break;
case _NCp1_NExprType_Csize_of_type:;
_NCp1_NExprI_Pprocess_size_of_type_2(_Lexpr_4, &_Lok_5);
break;
case _NCp1_NExprType_Cnull:;
_NCp1_NExprI_Pprocess_null_2(_Lexpr_4, &_Lok_5);
break;
case _NCp1_NExprType_Cindex:;
_NCp1_NExprI_Pprocess_index_2(_Lexpr_4, &_Lok_5);
break;
default:;
fprintf(stdout, "%s:%u:%u - %u:%u: process() not implemented for expression #%s\n", _NCp1_NFile_Ppath_1((*_Gctx_func)._Ffile), _Gctx_begin_row, _Gctx_begin_col, _Gctx_end_row, _Gctx_end_col, _NCp1_NExprType_Pcp1_name_1((*_Lexpr_4)._Ftype));
return false;
break;
}
if(!(_Lok_5)) {
fprintf(stdout, "%s:%u:%u - %u:%u: Processing of expression #%s failed\n", _NCp1_NFile_Ppath_1((*_Gctx_func)._Ffile), _Gctx_begin_row, _Gctx_begin_col, _Gctx_end_row, _Gctx_end_col, _NCp1_NExprType_Pcp1_name_1((*_Lexpr_4)._Ftype));
}
return _Lok_5;
}
char* _NCp1_NId_Pc_name_1(_NCp1_NId _Lid_0) {
char* _Lc_name_1;
uint8_t _Llen_2;
char* _Lstr_3;
_Lc_name_1 = _Gid_c_name_v[_Lid_0];
if(_Lc_name_1 != NULL) {
return _Lc_name_1;
}
_Llen_2 = _Gid_len_v[_Lid_0];
_Lstr_3 = _Gid_str_v[_Lid_0];
_Lc_name_1 = qalloc(_Llen_2 + 1);
_Gid_c_name_v[_Lid_0] = _Lc_name_1;
int32_t _Li_4;
_Li_4 = 0;
for(int i = _Llen_2; i > 0; ) {
i --;
if(_Lstr_3[_Li_4] == '-') {
_Lc_name_1[_Li_4] = '_';
} else {
_Lc_name_1[_Li_4] = _Lstr_3[_Li_4];
}
continue_0:;
_Li_4++;
}
break_0:;
_Lc_name_1[_Llen_2] = '\0';
return _Lc_name_1;
}
inline struct _NCp1_NExpr* _NCp1_NExprI_Pptr_1(_NCp1_NExprI _Le_0) {
return _Gexpr_v[_Le_0];
}
inline void _NCp1_NExprI_Pwrite_assign_1(struct _NCp1_NExpr* _Lexpr_0) {
struct _NCp1_NExprAssign* _Le_1;
_Le_1 = _Lexpr_0;
_NCp1_NExprI_Pwrite_value_2((*_Le_1)._Fleft, &(*_Le_1)._Fleft_val);
switch((*_Le_1)._Ftype) {
case _NCp1_NAssign_Ceq:;
fprintf(_Gout, " = ");
break;
case _NCp1_NAssign_Cplus_eq:;
fprintf(_Gout, " += ");
break;
case _NCp1_NAssign_Cminus_eq:;
fprintf(_Gout, " -= ");
break;
case _NCp1_NAssign_Cmul_eq:;
fprintf(_Gout, " *= ");
break;
case _NCp1_NAssign_Cdiv_eq:;
fprintf(_Gout, " /= ");
break;
case _NCp1_NAssign_Clshift_eq:;
fprintf(_Gout, " <<= ");
break;
case _NCp1_NAssign_Crshift_eq:;
fprintf(_Gout, " >>= ");
break;
case _NCp1_NAssign_Cand_eq:;
fprintf(_Gout, " &= ");
break;
case _NCp1_NAssign_Cor_eq:;
fprintf(_Gout, " |= ");
break;
case _NCp1_NAssign_Cxor_eq:;
fprintf(_Gout, " ^= ");
break;
}
_NCp1_NExprI_Pwrite_value_2((*_Le_1)._Fright, &(*_Le_1)._Fright_val);
}
inline void _NCp1_NExprI_Pwrite_compare_1(struct _NCp1_NExpr* _Lexpr_0) {
struct _NCp1_NExprCompare* _Le_1;
_Le_1 = _Lexpr_0;
_NCp1_NExprI_Pwrite_value_2((*_Le_1)._Fleft, &(*_Le_1)._Fleft_val);
switch((*_Le_1)._Ftype) {
case _NCp1_NCompare_Ceq:;
fprintf(_Gout, " == ");
break;
case _NCp1_NCompare_Cnot_eq:;
fprintf(_Gout, " != ");
break;
case _NCp1_NCompare_Clt:;
fprintf(_Gout, " < ");
break;
case _NCp1_NCompare_Cle:;
fprintf(_Gout, " <= ");
break;
case _NCp1_NCompare_Cgt:;
fprintf(_Gout, " > ");
break;
case _NCp1_NCompare_Cge:;
fprintf(_Gout, " >= ");
break;
}
_NCp1_NExprI_Pwrite_value_2((*_Le_1)._Fright, &(*_Le_1)._Fright_val);
}
inline void _NCp1_NExprI_Pwrite_bool_1(struct _NCp1_NExpr* _Lexpr_0) {
struct _NCp1_NExprBool* _Le_1;
_Le_1 = _Lexpr_0;
if((*_Le_1)._Fvalue) {
fprintf(_Gout, "true");
} else {
fprintf(_Gout, "false");
}
}
inline void _NCp1_NExprI_Pwrite_char_1(struct _NCp1_NExpr* _Lexpr_0) {
struct _NCp1_NExprChar* _Le_1;
_Le_1 = _Lexpr_0;
_NCp1_Pwrite_char_1((*_Le_1)._Fvalue);
}
inline void _NCp1_NExprI_Pwrite_math_1(struct _NCp1_NExpr* _Lexpr_0) {
struct _NCp1_NExprMath* _Le_1;
_Le_1 = _Lexpr_0;
switch((*_Le_1)._Ftype) {
case _NCp1_NMath_Cadd:;
_NCp1_NExprI_Pwrite_value_2((*_Le_1)._Fleft, &(*_Le_1)._Fleft_val);
fprintf(_Gout, " + ");
_NCp1_NExprI_Pwrite_value_2((*_Le_1)._Fright, &(*_Le_1)._Fright_val);
int32_t _Li_2;
_Li_2 = 0;
for(int i = (*_Le_1)._Fitem_c; i > 0; ) {
i --;
fprintf(_Gout, " + ");
_NCp1_NExprI_Pwrite_value_2((*_Le_1)._Fitem_v[_Li_2]._Fexpr, &(*_Le_1)._Fitem_v[_Li_2]._Fval);
continue_0:;
_Li_2++;
}
break_0:;
break;
case _NCp1_NMath_Csub:;
_NCp1_NExprI_Pwrite_value_2((*_Le_1)._Fleft, &(*_Le_1)._Fleft_val);
fprintf(_Gout, " - ");
_NCp1_NExprI_Pwrite_value_2((*_Le_1)._Fright, &(*_Le_1)._Fright_val);
int32_t _Li_3;
_Li_3 = 0;
for(int i = (*_Le_1)._Fitem_c; i > 0; ) {
i --;
fprintf(_Gout, " - ");
_NCp1_NExprI_Pwrite_value_2((*_Le_1)._Fitem_v[_Li_3]._Fexpr, &(*_Le_1)._Fitem_v[_Li_3]._Fval);
continue_1:;
_Li_3++;
}
break_1:;
break;
case _NCp1_NMath_Cmul:;
_NCp1_NExprI_Pwrite_value_2((*_Le_1)._Fleft, &(*_Le_1)._Fleft_val);
fprintf(_Gout, " * ");
_NCp1_NExprI_Pwrite_value_2((*_Le_1)._Fright, &(*_Le_1)._Fright_val);
int32_t _Li_4;
_Li_4 = 0;
for(int i = (*_Le_1)._Fitem_c; i > 0; ) {
i --;
fprintf(_Gout, " * ");
_NCp1_NExprI_Pwrite_value_2((*_Le_1)._Fitem_v[_Li_4]._Fexpr, &(*_Le_1)._Fitem_v[_Li_4]._Fval);
continue_2:;
_Li_4++;
}
break_2:;
break;
case _NCp1_NMath_Cdiv:;
_NCp1_NExprI_Pwrite_value_2((*_Le_1)._Fleft, &(*_Le_1)._Fleft_val);
fprintf(_Gout, " / ");
_NCp1_NExprI_Pwrite_value_2((*_Le_1)._Fright, &(*_Le_1)._Fright_val);
int32_t _Li_5;
_Li_5 = 0;
for(int i = (*_Le_1)._Fitem_c; i > 0; ) {
i --;
fprintf(_Gout, " / ");
_NCp1_NExprI_Pwrite_value_2((*_Le_1)._Fitem_v[_Li_5]._Fexpr, &(*_Le_1)._Fitem_v[_Li_5]._Fval);
continue_3:;
_Li_5++;
}
break_3:;
break;
case _NCp1_NMath_Clshift:;
_NCp1_NExprI_Pwrite_value_2((*_Le_1)._Fleft, &(*_Le_1)._Fleft_val);
fprintf(_Gout, " << ");
_NCp1_NExprI_Pwrite_value_2((*_Le_1)._Fright, &(*_Le_1)._Fright_val);
break;
case _NCp1_NMath_Crshift:;
_NCp1_NExprI_Pwrite_value_2((*_Le_1)._Fleft, &(*_Le_1)._Fleft_val);
fprintf(_Gout, " >> ");
_NCp1_NExprI_Pwrite_value_2((*_Le_1)._Fright, &(*_Le_1)._Fright_val);
break;
case _NCp1_NMath_Cand:;
_NCp1_NExprI_Pwrite_value_2((*_Le_1)._Fleft, &(*_Le_1)._Fleft_val);
fprintf(_Gout, " & ");
_NCp1_NExprI_Pwrite_value_2((*_Le_1)._Fright, &(*_Le_1)._Fright_val);
int32_t _Li_6;
_Li_6 = 0;
for(int i = (*_Le_1)._Fitem_c; i > 0; ) {
i --;
fprintf(_Gout, " & ");
_NCp1_NExprI_Pwrite_value_2((*_Le_1)._Fitem_v[_Li_6]._Fexpr, &(*_Le_1)._Fitem_v[_Li_6]._Fval);
continue_4:;
_Li_6++;
}
break_4:;
break;
case _NCp1_NMath_Cor:;
_NCp1_NExprI_Pwrite_value_2((*_Le_1)._Fleft, &(*_Le_1)._Fleft_val);
fprintf(_Gout, " | ");
_NCp1_NExprI_Pwrite_value_2((*_Le_1)._Fright, &(*_Le_1)._Fright_val);
int32_t _Li_7;
_Li_7 = 0;
for(int i = (*_Le_1)._Fitem_c; i > 0; ) {
i --;
fprintf(_Gout, " | ");
_NCp1_NExprI_Pwrite_value_2((*_Le_1)._Fitem_v[_Li_7]._Fexpr, &(*_Le_1)._Fitem_v[_Li_7]._Fval);
continue_5:;
_Li_7++;
}
break_5:;
break;
case _NCp1_NMath_Cxor:;
_NCp1_NExprI_Pwrite_value_2((*_Le_1)._Fleft, &(*_Le_1)._Fleft_val);
fprintf(_Gout, " ^ ");
_NCp1_NExprI_Pwrite_value_2((*_Le_1)._Fright, &(*_Le_1)._Fright_val);
int32_t _Li_8;
_Li_8 = 0;
for(int i = (*_Le_1)._Fitem_c; i > 0; ) {
i --;
fprintf(_Gout, " ^ ");
_NCp1_NExprI_Pwrite_value_2((*_Le_1)._Fitem_v[_Li_8]._Fexpr, &(*_Le_1)._Fitem_v[_Li_8]._Fval);
continue_6:;
_Li_8++;
}
break_6:;
break;
}
}
inline void _NCp1_NExprI_Pwrite_unary_1(struct _NCp1_NExpr* _Lexpr_0) {
struct _NCp1_NExprUnary* _Le_1;
_Le_1 = _Lexpr_0;
switch((*_Le_1)._Ftype) {
case _NCp1_NUnary_Cneg:;
fprintf(_Gout, "-");
_NCp1_NExprI_Pwrite_value_2((*_Le_1)._Fexpr, &(*_Le_1)._Fval);
break;
case _NCp1_NUnary_Cinc:;
_NCp1_NExprI_Pwrite_value_2((*_Le_1)._Fexpr, &(*_Le_1)._Fval);
fprintf(_Gout, "++");
break;
case _NCp1_NUnary_Cdec:;
_NCp1_NExprI_Pwrite_value_2((*_Le_1)._Fexpr, &(*_Le_1)._Fval);
fprintf(_Gout, "--");
break;
case _NCp1_NUnary_Cnot:;
fprintf(_Gout, "!");
_NCp1_NExprI_Pwrite_value_2((*_Le_1)._Fexpr, &(*_Le_1)._Fval);
break;
}
}
inline void _NCp1_NExprI_Pwrite_ref_1(struct _NCp1_NExpr* _Lexpr_0) {
struct _NCp1_NExprRef* _Le_1;
_Le_1 = _Lexpr_0;
_NCp1_NExprI_Pwrite_value_2((*_Le_1)._Fexpr, &(*_Le_1)._Fval);
}
inline void _NCp1_NExprI_Pwrite_lvar_1(struct _NCp1_NExpr* _Lexpr_0) {
struct _NCp1_NExprLvar* _Le_1;
_Le_1 = _Lexpr_0;
_NCp1_NDeclVarData_Pwrite_lvar_2(&(*_NCp1_NLvar_Pptr_1((*_Le_1)._Flvar))._Fdecl, (*_Le_1)._Flvar);
}
inline void _NCp1_NExprI_Pwrite_fvar_1(struct _NCp1_NExpr* _Lexpr_0) {
struct _NCp1_NExprFvar* _Le_1;
_Le_1 = _Lexpr_0;
_NCp1_NExprI_Pwrite_value_2((*_Le_1)._Fexpr, &(*_Le_1)._Fval);
fprintf(_Gout, ".");
_NCp1_NDeclVarData_Pwrite_2(&(*_NCp1_NStruct_Pptr_1((*_NCp1_NAt_Pptr_1((*_Le_1)._Fval._Ftype))._Fdecl._Fstruct))._Ffvar_v[(*_Le_1)._Ffvar]._Fdecl, _NCp1_NDeclVarType_Cfvar);
}
inline void _NCp1_NExprI_Pwrite_gvar_1(struct _NCp1_NExpr* _Lexpr_0) {
struct _NCp1_NExprGvar* _Le_1;
_Le_1 = _Lexpr_0;
_NCp1_NGvar_Pwrite_1((*_Le_1)._Fgvar);
}
inline void _NCp1_NExprI_Pwrite_cvar_1(struct _NCp1_NExpr* _Lexpr_0) {
struct _NCp1_NExprCvar* _Le_1;
_Le_1 = _Lexpr_0;
_NCp1_NCvar_Pwrite_1((*_Le_1)._Fcvar);
}
inline void _NCp1_NExprI_Pwrite_bools_1(struct _NCp1_NExpr* _Lexpr_0) {
struct _NCp1_NExprBools* _Le_1;
_Le_1 = _Lexpr_0;
switch((*_Le_1)._Ftype) {
case _NCp1_NBools_Cand:;
fprintf(_Gout, "(");
_NCp1_NExprI_Pwrite_value_2((*_Le_1)._Fleft, &(*_Le_1)._Fleft_val);
fprintf(_Gout, " && ");
_NCp1_NExprI_Pwrite_value_2((*_Le_1)._Fright, &(*_Le_1)._Fright_val);
int32_t _Li_2;
_Li_2 = 0;
for(int i = (*_Le_1)._Fitem_c; i > 0; ) {
i --;
struct _NCp1_NExprBoolsItem* _Litem_3;
fprintf(_Gout, " && ");
_Litem_3 = (&(*_Le_1)._Fitem_v[_Li_2]);
_NCp1_NExprI_Pwrite_value_2((*_Litem_3)._Fexpr, &(*_Litem_3)._Fval);
continue_0:;
_Li_2++;
}
break_0:;
fprintf(_Gout, ")");
break;
case _NCp1_NBools_Cor:;
fprintf(_Gout, "(");
_NCp1_NExprI_Pwrite_value_2((*_Le_1)._Fleft, &(*_Le_1)._Fleft_val);
fprintf(_Gout, " || ");
_NCp1_NExprI_Pwrite_value_2((*_Le_1)._Fright, &(*_Le_1)._Fright_val);
int32_t _Li_4;
_Li_4 = 0;
for(int i = (*_Le_1)._Fitem_c; i > 0; ) {
i --;
struct _NCp1_NExprBoolsItem* _Litem_5;
fprintf(_Gout, " || ");
_Litem_5 = (&(*_Le_1)._Fitem_v[_Li_4]);
_NCp1_NExprI_Pwrite_value_2((*_Litem_5)._Fexpr, &(*_Litem_5)._Fval);
continue_1:;
_Li_4++;
}
break_1:;
fprintf(_Gout, ")");
break;
}
}
inline void _NCp1_NExprI_Pwrite_method_1(struct _NCp1_NExpr* _Lexpr_0) {
struct _NCp1_NExprMethod* _Le_1;
struct _NCp1_NDeclFunc* _Lf_2;
bool _Lfirst_3;
int32_t _Li_4;
_Le_1 = _Lexpr_0;
_Lf_2 = _NCp1_NFunc_Pptr_1((*_Le_1)._Ffunc_idx);
_NCp1_NDeclFunc_Pwrite_1(_Lf_2);
fprintf(_Gout, "(");
_Lfirst_3 = true;
_Li_4 = 0;
for(int i = (*_Lf_2)._Fthis_idx; i > 0; ) {
i --;
struct _NCp1_NCarg* _Lca_5;
if(_Lfirst_3) {
_Lfirst_3 = false;
} else {
fprintf(_Gout, ", ");
}
_Lca_5 = (&(*_Le_1)._Fcarg_v[_Li_4]);
_NCp1_NExprI_Pwrite_value_2((*_Lca_5)._Fexpr, &(*_Lca_5)._Fvalue);
continue_0:;
_Li_4++;
}
break_0:;
if(_Lfirst_3) {
_Lfirst_3 = false;
} else {
fprintf(_Gout, ", ");
}
_NCp1_NExprI_Pwrite_value_2((*_Le_1)._Fthiss, &(*_Le_1)._Fthis_value);
for(int i = (*_Le_1)._Fcarg_c - (*_Lf_2)._Fthis_idx; i > 0; ) {
i --;
struct _NCp1_NCarg* _Lca_6;
fprintf(_Gout, ", ");
_Lca_6 = (&(*_Le_1)._Fcarg_v[_Li_4]);
_NCp1_NExprI_Pwrite_value_2((*_Lca_6)._Fexpr, &(*_Lca_6)._Fvalue);
continue_1:;
_Li_4++;
}
break_1:;
fprintf(_Gout, ")");
}
inline void _NCp1_NExprI_Pwrite_func_1(struct _NCp1_NExpr* _Lexpr_0) {
struct _NCp1_NExprFunc* _Le_1;
struct _NCp1_NDeclFunc* _Lf_2;
_Le_1 = _Lexpr_0;
_Lf_2 = _NCp1_NFunc_Pptr_1((*_Le_1)._Ffunc_idx);
_NCp1_NDeclFunc_Pwrite_1(_Lf_2);
fprintf(_Gout, "(");
int32_t _Li_3;
_Li_3 = 0;
for(int i = (*_Le_1)._Fcarg_c; i > 0; ) {
i --;
if(_Li_3 != 0) {
fprintf(_Gout, ", ");
}
_NCp1_NExprI_Pwrite_value_2((*_Le_1)._Fcarg_v[_Li_3]._Fexpr, &(*_Le_1)._Fcarg_v[_Li_3]._Fvalue);
continue_0:;
_Li_3++;
}
break_0:;
fprintf(_Gout, ")");
}
inline void _NCp1_NExprI_Pwrite_str_1(struct _NCp1_NExpr* _Lexpr_0) {
struct _NCp1_NExprStr* _Le_1;
struct _NCp1_NExprStrNode* _Ln_2;
_Le_1 = _Lexpr_0;
_Ln_2 = (*_Le_1)._Ffirst;
while(1) {
_NCp1_Pwrite_str_node_2((*_Ln_2)._Flen, (*_Ln_2)._Fbuf);
_Ln_2 = (*_Ln_2)._Fnext;
if(_Ln_2 == NULL) {
goto break_0;
}
fputc('\n', _Gout);
continue_0:;
}
break_0:;
}
inline void _NCp1_NExprI_Pwrite_i32_1(struct _NCp1_NExpr* _Lexpr_0) {
struct _NCp1_NExprIntData* _Le_1;
_Le_1 = _Lexpr_0;
fprintf(_Gout, "%d", (*_Le_1)._Fvalue);
}
inline void _NCp1_NExprI_Pwrite_size_of_type_1(struct _NCp1_NExpr* _Lexpr_0) {
struct _NCp1_NExprSizeOfType* _Le_1;
_Le_1 = _Lexpr_0;
fprintf(_Gout, "sizeof(");
_NCp1_NAt_Pwrite_1((*_Le_1)._Ftype);
fprintf(_Gout, ")");
}
inline void _NCp1_NExprI_Pwrite_null_1(struct _NCp1_NExpr* _Lexpr_0) {
struct _NCp1_NExprNull* _Le_1;
_Le_1 = _Lexpr_0;
fprintf(_Gout, "NULL");
}
inline void _NCp1_NExprI_Pwrite_index_1(struct _NCp1_NExpr* _Lexpr_0) {
struct _NCp1_NExprIndex* _Le_1;
_Le_1 = _Lexpr_0;
_NCp1_NExprI_Pwrite_value_2((*_Le_1)._Fleft, &(*_Le_1)._Fleft_val);
fprintf(_Gout, "[");
_NCp1_NExprI_Pwrite_value_2((*_Le_1)._Fright, &(*_Le_1)._Fright_val);
fprintf(_Gout, "]");
}
void _NCp1_NDeclVarData_Pwrite_2(struct _NCp1_NDeclVarData* _Lvd_0, _NCp1_NDeclVarType _Lvar_type_1) {
if(((*_Lvd_0)._Fflags & _NCp1_NVarFlags_Creal_name) != _NCp1_NVarFlags_C0) {
if((*_Lvd_0)._Freal_name == _NCp1_NId_Cnil) {
fprintf(_Gout, "%s", _NCp1_NId_Pc_name_1((*_Lvd_0)._Fname));
} else {
fprintf(_Gout, "%s", _NCp1_NId_Pstr_1((*_Lvd_0)._Freal_name));
}
return;
}
switch(_Lvar_type_1) {
case _NCp1_NDeclVarType_Cgvar:;
fprintf(_Gout, "_G%s", _NCp1_NId_Pc_name_1((*_Lvd_0)._Fname));
break;
case _NCp1_NDeclVarType_Cfvar:;
fprintf(_Gout, "_F%s", _NCp1_NId_Pc_name_1((*_Lvd_0)._Fname));
break;
}
}
bool _NCp1_NExprI_Pwrite_value_2(_NCp1_NExprI _Le_0, struct _NCp1_NValue* _Lv_1) {
struct _NCp1_NExpr* _Lexpr_2;
int8_t _Lreff_3;
_Lexpr_2 = _NCp1_NExprI_Pptr_1(_Le_0);
_Lreff_3 = (*_Lv_1)._Freff;
if((*_Lv_1)._Fparen) {
if(_Lreff_3 <= 0) {
_NStdc_NFile_Pwrite_3(_Gout, "(&", 2);
} else {
_NStdc_NFile_Pwrite_3(_Gout, "(*******************************", _Lreff_3);
}
} else {
if(_Lreff_3 <= 0) {
_NStdc_NFile_Pwrite_3(_Gout, "&", 1);
} else if(_Lreff_3 > 1) {
_NStdc_NFile_Pwrite_3(_Gout, "*******************************", _Lreff_3 - 1);
}
}
if((*_Lexpr_2)._Ftype == _NCp1_NExprType_Ccast_fast) {
struct _NCp1_NExprCastFast* _Le_4;
_Le_4 = _Lexpr_2;
_NCp1_NExprCastFast_Pwrite_value_2(_Le_4, _Lv_1);
} else {
_NCp1_NExprI_Pwrite_1(_Le_0);
}
if((*_Lv_1)._Fparen) {
_NStdc_NFile_Pwrite_3(_Gout, ")", 1);
}
return true;
}
void _NCp1_NTypeInfo_Pcount_1(struct _NCp1_NTypeInfo* _Lti_0) {
int8_t _Lstar_c_1;
_Lstar_c_1 = (*_Lti_0)._Farray_c;
int8_t _Li_2;
_Li_2 = (*_Lti_0)._Farray_c;
for(int i = _Li_2 + 1; i > 0; ) {
i --;
_Lstar_c_1 += (*_Lti_0)._Fref_v[_Li_2];
_Li_2 -= 1;
continue_0:;
}
break_0:;
(*_Lti_0)._Fstar_c = _Lstar_c_1;
}
bool _NCp1_NAt_Pwrite_type_1(_NCp1_NAt _Ltd_0) {
_NCp1_NAt_Pwrite_1(_Ltd_0);
return true;
}
int32_t _NCp1_NAt_Pcount_stars0_2(_NCp1_NAt _Ltd_0, struct _NCp1_NTypeInfo* _Lti_1) {
return (*_Lti_1)._Fstar_c + _NCp1_NAt_Ppointer_1(_Ltd_0);
}
inline size_t _NStdc_NFile_Pwrite_3(struct FILE* _Lf_0, void* _Lbuf_1, size_t _Lsize_2) {
return fwrite(_Lbuf_1, 1, _Lsize_2, _Lf_0);
}
void _NCp1_NDeclVarData_Pwrite_lvar_2(struct _NCp1_NDeclVarData* _Lvd_0, _NCp1_NLvar _Llvar_1) {
fprintf(_Gout, "_L%s_%u", _NCp1_NId_Pc_name_1((*_Lvd_0)._Fname), _Llvar_1);
}
void _NCp1_NStmt_Pwrite_1(struct _NCp1_NStmt* _Ls_0) {
switch((*_Ls_0)._Ftype) {
case _NCp1_NStmtType_Cexpr:;
_NCp1_NStmt_Pwrite_expr_1(_Ls_0);
break;
case _NCp1_NStmtType_Cif:;
_NCp1_NStmt_Pwrite_if_1(_Ls_0);
break;
case _NCp1_NStmtType_Cif_elif:;
_NCp1_NStmt_Pwrite_if_elif_1(_Ls_0);
break;
case _NCp1_NStmtType_Cif_else:;
_NCp1_NStmt_Pwrite_if_else_1(_Ls_0);
break;
case _NCp1_NStmtType_Cif_end:;
_NCp1_NStmt_Pwrite_if_end_1(_Ls_0);
break;
case _NCp1_NStmtType_Cswitch:;
_NCp1_NStmt_Pwrite_switch_1(_Ls_0);
break;
case _NCp1_NStmtType_Ccase:;
_NCp1_NStmt_Pwrite_case_1(_Ls_0);
break;
case _NCp1_NStmtType_Ccase_end:;
_NCp1_NStmt_Pwrite_case_end_1(_Ls_0);
break;
case _NCp1_NStmtType_Cdefault:;
_NCp1_NStmt_Pwrite_default_1(_Ls_0);
break;
case _NCp1_NStmtType_Cdefault_end:;
_NCp1_NStmt_Pwrite_default_end_1(_Ls_0);
break;
case _NCp1_NStmtType_Cswitch_end:;
_NCp1_NStmt_Pwrite_switch_end_1(_Ls_0);
break;
case _NCp1_NStmtType_Cdo:;
_NCp1_NStmt_Pwrite_do_1(_Ls_0);
break;
case _NCp1_NStmtType_Cdo_end:;
_NCp1_NStmt_Pwrite_do_end_1(_Ls_0);
break;
case _NCp1_NStmtType_Cwhile:;
_NCp1_NStmt_Pwrite_while_1(_Ls_0);
break;
case _NCp1_NStmtType_Cwhile_end:;
_NCp1_NStmt_Pwrite_while_end_1(_Ls_0);
break;
case _NCp1_NStmtType_Ccontinue:;
_NCp1_NStmt_Pwrite_continue_1(_Ls_0);
break;
case _NCp1_NStmtType_Cbreak:;
_NCp1_NStmt_Pwrite_break_1(_Ls_0);
break;
case _NCp1_NStmtType_Creturn:;
_NCp1_NStmt_Pwrite_return_1(_Ls_0);
break;
case _NCp1_NStmtType_Cspace:;
_NCp1_NStmt_Pwrite_space_1(_Ls_0);
break;
default:;
fprintf(stdout, "write() not yet implemented in stmt #%s\n", _NCp1_NStmtType_Pcp1_name_1((*_Ls_0)._Ftype));
exit(_NStdc_NExit_Cfailure);
break;
}
}
inline void _NCp1_NVarFlags_Prd_2(_NCp1_NVarFlags* _Lf_0, union _NCp1_NRdr* _Lr_1) {
(*_Lf_0) = (_NCp1_NVarFlags)(Fgetnum(_Lr_1));
}
void _NCp1_NTypeInfo_Prd_2(struct _NCp1_NTypeInfo* _Lti_0, union _NCp1_NRdr* _Lr_1) {
uint8_t _Lc_2;
_Lc_2 = _NCp1_NRdr_Pn1_1(_Lr_1);
int32_t _Li_3;
_Li_3 = 0;
for(int i = _Lc_2; i > 0; ) {
i --;
(*_Lti_0)._Fref_v[_Li_3] = _NCp1_NRdr_Pn1_1(_Lr_1);
continue_0:;
_Li_3++;
}
break_0:;
(*_Lti_0)._Farray_c = _NCp1_NRdr_Pn1_1(_Lr_1);
(*_Lti_0)._Fstar_c = _NCp1_NRdr_Pn1_1(_Lr_1);
(*_Lti_0)._Fbuilt_in = (_NCp1_NRdr_Pn1_1(_Lr_1) != 0);
(*_Lti_0)._Fconst = (_NCp1_NRdr_Pn1_1(_Lr_1) != 0);
}
inline void _NCp1_NExprType_Prd_2(_NCp1_NExprType* _Le_0, union _NCp1_NRdr* _Lr_1) {
(*_Le_0) = (_NCp1_NExprType)(_NCp1_NRdr_Pn1_1(_Lr_1));
}
inline void _NCp1_NExprI_Prd_assign_2(_NCp1_NExprI _Le_idx_0, union _NCp1_NRdr* _Lr_1) {
struct _NCp1_NExprAssign* _Le_2;
_NCp1_Pquick_alloc_one_1(_Le_2);
_NCp1_NExprI_Pset_3(_Le_idx_0, &(*_Le_2)._Fbase, _NCp1_NExprType_Cassign);
_NCp1_NExprI_Prd_2(&(*_Le_2)._Fleft, _Lr_1);
_NCp1_NExprI_Prd_2(&(*_Le_2)._Fright, _Lr_1);
_NCp1_NAssign_Prd_2(&(*_Le_2)._Ftype, _Lr_1);
}
inline void _NCp1_NExprI_Prd_compare_2(_NCp1_NExprI _Le_idx_0, union _NCp1_NRdr* _Lr_1) {
struct _NCp1_NExprCompare* _Le_2;
_NCp1_Pquick_alloc_one_1(_Le_2);
_NCp1_NExprI_Pset_3(_Le_idx_0, &(*_Le_2)._Fbase, _NCp1_NExprType_Ccompare);
_NCp1_NExprI_Prd_2(&(*_Le_2)._Fleft, _Lr_1);
_NCp1_NExprI_Prd_2(&(*_Le_2)._Fright, _Lr_1);
_NCp1_NCompare_Prd_2(&(*_Le_2)._Ftype, _Lr_1);
}
inline void _NCp1_NExprI_Prd_bool_2(_NCp1_NExprI _Le_idx_0, union _NCp1_NRdr* _Lr_1) {
struct _NCp1_NExprBool* _Le_2;
_NCp1_Pquick_alloc_one_1(_Le_2);
_NCp1_NExprI_Pset_3(_Le_idx_0, &(*_Le_2)._Fbase, _NCp1_NExprType_Cbool);
(*_Le_2)._Fvalue = _NCp1_NRdr_Pb_1(_Lr_1);
}
inline void _NCp1_NExprI_Prd_char_2(_NCp1_NExprI _Le_idx_0, union _NCp1_NRdr* _Lr_1) {
struct _NCp1_NExprChar* _Le_2;
_NCp1_Pquick_alloc_one_1(_Le_2);
_NCp1_NExprI_Pset_3(_Le_idx_0, &(*_Le_2)._Fbase, _NCp1_NExprType_Cchar);
(*_Le_2)._Fvalue = Fgetnum(_Lr_1);
}
inline void _NCp1_NExprI_Prd_math_2(_NCp1_NExprI _Le_idx_0, union _NCp1_NRdr* _Lr_1) {
struct _NCp1_NExprMath* _Le_2;
uint8_t _Litem_c_3;
_NCp1_Pquick_alloc_one_1(_Le_2);
_NCp1_NExprI_Pset_3(_Le_idx_0, &(*_Le_2)._Fbase, _NCp1_NExprType_Cmath);
_NCp1_NExprI_Prd_2(&(*_Le_2)._Fleft, _Lr_1);
_NCp1_NExprI_Prd_2(&(*_Le_2)._Fright, _Lr_1);
_NCp1_NMath_Prd_2(&(*_Le_2)._Ftype, _Lr_1);
_Litem_c_3 = _NCp1_NRdr_Pn1_1(_Lr_1);
if(_Litem_c_3 > 0) {
(*_Le_2)._Fitem_c = _Litem_c_3;
_NCp1_Pquick_alloc_arr_2((*_Le_2)._Fitem_v, _Litem_c_3);
int32_t _Li_4;
_Li_4 = 0;
for(int i = (*_Le_2)._Fitem_c; i > 0; ) {
i --;
_NCp1_NExprI_Prd_2(&(*_Le_2)._Fitem_v[_Li_4]._Fexpr, _Lr_1);
continue_0:;
_Li_4++;
}
break_0:;
}
}
inline void _NCp1_NExprI_Prd_unary_2(_NCp1_NExprI _Le_idx_0, union _NCp1_NRdr* _Lr_1) {
struct _NCp1_NExprUnary* _Le_2;
_NCp1_Pquick_alloc_one_1(_Le_2);
_NCp1_NExprI_Pset_3(_Le_idx_0, &(*_Le_2)._Fbase, _NCp1_NExprType_Cunary);
_NCp1_NExprI_Prd_2(&(*_Le_2)._Fexpr, _Lr_1);
_NCp1_NUnary_Prd_2(&(*_Le_2)._Ftype, _Lr_1);
}
inline void _NCp1_NExprI_Prd_ref_2(_NCp1_NExprI _Le_idx_0, union _NCp1_NRdr* _Lr_1) {
struct _NCp1_NExprRef* _Le_2;
_NCp1_Pquick_alloc_one_1(_Le_2);
_NCp1_NExprI_Pset_3(_Le_idx_0, &(*_Le_2)._Fbase, _NCp1_NExprType_Cref);
_NCp1_NExprI_Prd_2(&(*_Le_2)._Fexpr, _Lr_1);
}
inline void _NCp1_NExprI_Prd_cast_fast_2(_NCp1_NExprI _Le_idx_0, union _NCp1_NRdr* _Lr_1) {
struct _NCp1_NExprCastFast* _Le_2;
_NCp1_Pquick_alloc_one_1(_Le_2);
_NCp1_NExprI_Pset_3(_Le_idx_0, &(*_Le_2)._Fbase, _NCp1_NExprType_Ccast_fast);
_NCp1_NExprI_Prd_2(&(*_Le_2)._Fexpr, _Lr_1);
_NCp1_NAt_Prd_2(&(*_Le_2)._Ftype, _Lr_1);
}
inline void _NCp1_NExprI_Prd_lvar_2(_NCp1_NExprI _Le_idx_0, union _NCp1_NRdr* _Lr_1) {
struct _NCp1_NExprLvar* _Le_2;
_NCp1_Pquick_alloc_one_1(_Le_2);
_NCp1_NExprI_Pset_3(_Le_idx_0, &(*_Le_2)._Fbase, _NCp1_NExprType_Clvar);
_NCp1_NLvar_Prd_2(&(*_Le_2)._Flvar, _Lr_1);
}
inline void _NCp1_NExprI_Prd_fvar_2(_NCp1_NExprI _Le_idx_0, union _NCp1_NRdr* _Lr_1) {
struct _NCp1_NExprFvar* _Le_2;
_NCp1_Pquick_alloc_one_1(_Le_2);
_NCp1_NExprI_Pset_3(_Le_idx_0, &(*_Le_2)._Fbase, _NCp1_NExprType_Cfvar);
_NCp1_NExprI_Prd_2(&(*_Le_2)._Fexpr, _Lr_1);
_NCp1_NId_Prd_2(&(*_Le_2)._Fmember, _Lr_1);
}
inline void _NCp1_NExprI_Prd_gvar_2(_NCp1_NExprI _Le_idx_0, union _NCp1_NRdr* _Lr_1) {
struct _NCp1_NExprGvar* _Le_2;
_NCp1_NAt _Lat_idx_3;
_NCp1_NId _Lname_4;
bool _Ltry_parent_5;
_NCp1_Pquick_alloc_one_1(_Le_2);
_NCp1_NExprI_Pset_3(_Le_idx_0, &(*_Le_2)._Fbase, _NCp1_NExprType_Cgvar);
_NCp1_NAt_Prd_2(&_Lat_idx_3, _Lr_1);
_NCp1_NId_Prd_2(&_Lname_4, _Lr_1);
_Ltry_parent_5 = false;
if(_Lat_idx_3 == _NCp1_NAt_Cnil) {
_Lat_idx_3 = (*_Gctx_func)._Fat;
_Ltry_parent_5 = true;
}
while(1) {
struct _NCp1_NAtData* _Lat_6;
_Lat_6 = _NCp1_NAt_Pptr_1(_Lat_idx_3);
int32_t _Li_7;
_Li_7 = 0;
for(int i = (*_Lat_6)._Fgvar_c; i > 0; ) {
i --;
_NCp1_NGvar _Lgvar_8;
_Lgvar_8 = (*_Lat_6)._Fgvar_v[_Li_7];
if((*_NCp1_NGvar_Pptr_1(_Lgvar_8))._Fdecl._Fname == _Lname_4) {
(*_Le_2)._Fgvar = _Lgvar_8;
return;
}
continue_1:;
_Li_7++;
}
break_1:;
if(!(_Ltry_parent_5)) {
goto break_0;
}
if(_Lat_idx_3 == _NCp1_NAt_Croot) {
goto break_0;
}
_Lat_idx_3 = (*_Lat_6)._Fparent;
continue_0:;
}
break_0:;
fprintf(stdout, "%s:%u:%u - %u:%u: Cannot find gvar '.%s'\n", _NCp1_NFile_Ppath_1((*_Gctx_func)._Ffile), _Gctx_begin_row, _Gctx_begin_col, _Gctx_end_row, _Gctx_end_col, _NCp1_NId_Pstr_1(_Lname_4));
exit(_NStdc_NExit_Cfailure);
}
inline void _NCp1_NExprI_Prd_cvar_2(_NCp1_NExprI _Le_idx_0, union _NCp1_NRdr* _Lr_1) {
struct _NCp1_NExprCvar* _Le_2;
_NCp1_Pquick_alloc_one_1(_Le_2);
_NCp1_NExprI_Pset_3(_Le_idx_0, &(*_Le_2)._Fbase, _NCp1_NExprType_Ccvar);
_NCp1_NAt_Prd_2(&(*_Le_2)._Fat, _Lr_1);
_NCp1_NId_Prd_2(&(*_Le_2)._Fname, _Lr_1);
(*_Le_2)._Ftry = _NCp1_NAt_Cnil;
}
inline void _NCp1_NExprI_Prd_bools_2(_NCp1_NExprI _Le_idx_0, union _NCp1_NRdr* _Lr_1) {
struct _NCp1_NExprBools* _Le_2;
uint8_t _Litem_c_3;
_NCp1_Pquick_alloc_one_1(_Le_2);
_NCp1_NExprI_Pset_3(_Le_idx_0, &(*_Le_2)._Fbase, _NCp1_NExprType_Cbools);
_NCp1_NExprI_Prd_2(&(*_Le_2)._Fleft, _Lr_1);
_NCp1_NExprI_Prd_2(&(*_Le_2)._Fright, _Lr_1);
_Litem_c_3 = _NCp1_NRdr_Pn1_1(_Lr_1);
if(_Litem_c_3 > 0) {
(*_Le_2)._Fitem_c = _Litem_c_3;
_NCp1_Pquick_alloc_arr_2((*_Le_2)._Fitem_v, _Litem_c_3);
int32_t _Li_4;
_Li_4 = 0;
for(int i = _Litem_c_3; i > 0; ) {
i --;
_NCp1_NExprI_Prd_2(&(*_Le_2)._Fitem_v[_Li_4]._Fexpr, _Lr_1);
continue_0:;
_Li_4++;
}
break_0:;
}
_NCp1_NBools_Prd_2(&(*_Le_2)._Ftype, _Lr_1);
}
inline void _NCp1_NExprI_Prd_method_2(_NCp1_NExprI _Le_idx_0, union _NCp1_NRdr* _Lr_1) {
_NCp1_NExprI _Lthis_expr_2;
_NCp1_NId _Lfunc_name_3;
uint8_t _Lgroup_c_4;
int8_t _Lgroup_v_5[_NCp1_Cexpr_carg_group_limit];
uint8_t _Lcarg_c_7;
struct _NCp1_NExprMethod* _Le_8;
_NCp1_NExprI_Prd_2(&_Lthis_expr_2, _Lr_1);
_NCp1_NId_Prd_2(&_Lfunc_name_3, _Lr_1);
_Lgroup_c_4 = _NCp1_NRdr_Pn1_1(_Lr_1);
int32_t _Li_6;
_Li_6 = 0;
for(int i = _Lgroup_c_4; i > 0; ) {
i --;
_Lgroup_v_5[_Li_6] = _NCp1_NRdr_Pn1_1(_Lr_1);
continue_0:;
_Li_6++;
}
break_0:;
_Lcarg_c_7 = _NCp1_NRdr_Pn1_1(_Lr_1);
_NCp1_Pquick_alloc_plus_2(_Le_8, sizeof(struct _NCp1_NCarg) * _Lcarg_c_7);
_NCp1_NExprI_Pset_3(_Le_idx_0, &(*_Le_8)._Fbase, _NCp1_NExprType_Cmethod);
(*_Le_8)._Fthiss = _Lthis_expr_2;
(*_Le_8)._Ffunc_name = _Lfunc_name_3;
(*_Le_8)._Fgroup_c = _Lgroup_c_4;
int32_t _Li_9;
_Li_9 = 0;
for(int i = _Lgroup_c_4; i > 0; ) {
i --;
(*_Le_8)._Fgroup_v[_Li_9] = _Lgroup_v_5[_Li_9];
continue_1:;
_Li_9++;
}
break_1:;
(*_Le_8)._Fcarg_c = _Lcarg_c_7;
int32_t _Li_10;
_Li_10 = 0;
for(int i = _Lcarg_c_7; i > 0; ) {
i --;
_NCp1_NExprI_Prd_2(&(*_Le_8)._Fcarg_v[_Li_10]._Fexpr, _Lr_1);
continue_2:;
_Li_10++;
}
break_2:;
}
inline void _NCp1_NExprI_Prd_func_2(_NCp1_NExprI _Le_idx_0, union _NCp1_NRdr* _Lr_1) {
_NCp1_NAt _Lat_idx_2;
_NCp1_NId _Lfunc_name_3;
uint8_t _Lgroup_c_4;
int8_t _Lgroup_v_5[_NCp1_Cexpr_carg_group_limit];
uint8_t _Lcarg_c_7;
struct _NCp1_NExprFunc* _Le_8;
_NCp1_NAt_Prd_2(&_Lat_idx_2, _Lr_1);
_NCp1_NId_Prd_2(&_Lfunc_name_3, _Lr_1);
_Lgroup_c_4 = _NCp1_NRdr_Pn1_1(_Lr_1);
int32_t _Li_6;
_Li_6 = 0;
for(int i = _Lgroup_c_4; i > 0; ) {
i --;
_Lgroup_v_5[_Li_6] = _NCp1_NRdr_Pn1_1(_Lr_1);
continue_0:;
_Li_6++;
}
break_0:;
_Lcarg_c_7 = _NCp1_NRdr_Pn1_1(_Lr_1);
_NCp1_Pquick_alloc_plus_2(_Le_8, sizeof(struct _NCp1_NCarg) * _Lcarg_c_7);
_NCp1_NExprI_Pset_3(_Le_idx_0, &(*_Le_8)._Fbase, _NCp1_NExprType_Cfunc);
(*_Le_8)._Fat = _Lat_idx_2;
(*_Le_8)._Ffunc_name = _Lfunc_name_3;
(*_Le_8)._Fgroup_c = _Lgroup_c_4;
int32_t _Li_9;
_Li_9 = 0;
for(int i = _Lgroup_c_4; i > 0; ) {
i --;
(*_Le_8)._Fgroup_v[_Li_9] = _Lgroup_v_5[_Li_9];
continue_1:;
_Li_9++;
}
break_1:;
(*_Le_8)._Fcarg_c = _Lcarg_c_7;
int32_t _Li_10;
_Li_10 = 0;
for(int i = _Lcarg_c_7; i > 0; ) {
i --;
_NCp1_NExprI_Prd_2(&(*_Le_8)._Fcarg_v[_Li_10]._Fexpr, _Lr_1);
continue_2:;
_Li_10++;
}
break_2:;
}
inline void _NCp1_NExprI_Prd_str_2(_NCp1_NExprI _Le_idx_0, union _NCp1_NRdr* _Lr_1) {
uint32_t _Lnode_c_2;
struct _NCp1_NExprStr* _Le_3;
bool _Lfirst_4;
_Lnode_c_2 = Fgetnum(_Lr_1);
_NCp1_Pquick_alloc_one_1(_Le_3);
_NCp1_NExprI_Pset_3(_Le_idx_0, &(*_Le_3)._Fbase, _NCp1_NExprType_Cstr);
_Lfirst_4 = true;
for(int i = _Lnode_c_2; i > 0; ) {
i --;
uint32_t _Llen_5;
struct _NCp1_NExprStrNode* _Ln_6;
_Llen_5 = Fgetnum(_Lr_1);
_NCp1_Pquick_alloc_plus_2(_Ln_6, _Llen_5 + 1);
(*_Ln_6)._Flen = _Llen_5;
_NCp1_NRdr_Pcopy_3(_Lr_1, (*_Ln_6)._Fbuf, _Llen_5);
(*_Ln_6)._Fbuf[_Llen_5] = 0;
(*_Ln_6)._Fnext = NULL;
if(_Lfirst_4) {
_Lfirst_4 = false;
(*_Le_3)._Ffirst = _Ln_6;
(*_Le_3)._Flast = _Ln_6;
} else {
(*(*_Le_3)._Flast)._Fnext = _Ln_6;
(*_Le_3)._Flast = _Ln_6;
}
continue_0:;
}
break_0:;
}
inline void _NCp1_NExprI_Prd_i32_2(_NCp1_NExprI _Le_idx_0, union _NCp1_NRdr* _Lr_1) {
struct _NCp1_NExprIntData* _Le_2;
_NCp1_Pquick_alloc_one_1(_Le_2);
_NCp1_NExprI_Pset_3(_Le_idx_0, &(*_Le_2)._Fbase, _NCp1_NExprType_Ci32);
(*_Le_2)._Ftype = (_NCp1_NExprInt)(_NCp1_NRdr_Pn1_1(_Lr_1));
(*_Le_2)._Fvalue = Fgetnum(_Lr_1);
}
inline void _NCp1_NExprI_Prd_size_of_type_2(_NCp1_NExprI _Le_idx_0, union _NCp1_NRdr* _Lr_1) {
struct _NCp1_NExprSizeOfType* _Le_2;
_NCp1_Pquick_alloc_one_1(_Le_2);
_NCp1_NExprI_Pset_3(_Le_idx_0, &(*_Le_2)._Fbase, _NCp1_NExprType_Csize_of_type);
_NCp1_NAt_Prd_2(&(*_Le_2)._Ftype, _Lr_1);
}
inline void _NCp1_NExprI_Prd_null_2(_NCp1_NExprI _Le_idx_0, union _NCp1_NRdr* _Lr_1) {
struct _NCp1_NExprNull* _Le_2;
_NCp1_Pquick_alloc_one_1(_Le_2);
_NCp1_NExprI_Pset_3(_Le_idx_0, &(*_Le_2)._Fbase, _NCp1_NExprType_Cnull);
}
inline void _NCp1_NExprI_Prd_index_2(_NCp1_NExprI _Le_idx_0, union _NCp1_NRdr* _Lr_1) {
struct _NCp1_NExprIndex* _Le_2;
_NCp1_Pquick_alloc_one_1(_Le_2);
_NCp1_NExprI_Pset_3(_Le_idx_0, &(*_Le_2)._Fbase, _NCp1_NExprType_Cindex);
_NCp1_NExprI_Prd_2(&(*_Le_2)._Fleft, _Lr_1);
_NCp1_NExprI_Prd_2(&(*_Le_2)._Fright, _Lr_1);
}
inline void _NCp1_NLvarFlags_Prd_2(_NCp1_NLvarFlags* _Lf_0, union _NCp1_NRdr* _Lr_1) {
(*_Lf_0) = (_NCp1_NLvarFlags)(_NCp1_NRdr_Pn1_1(_Lr_1));
}
inline void _NCp1_NLvar_Prd_2(_NCp1_NLvar* _Ll_0, union _NCp1_NRdr* _Lr_1) {
(*_Ll_0) = ((_NCp1_NLvar)(Fgetnum(_Lr_1) - 1));
}
inline void _NCp1_NStmtType_Prd_2(_NCp1_NStmtType* _Ls_0, union _NCp1_NRdr* _Lr_1) {
(*_Ls_0) = (_NCp1_NStmtType)(_NCp1_NRdr_Pn1_1(_Lr_1));
}
inline void _NCp1_NStmtSpace_Prd_expr_2(struct _NCp1_NStmtSpace* _Lspace_0, union _NCp1_NRdr* _Lr_1) {
struct _NCp1_NStmtExpr* _Ls_2;
_NCp1_Pquick_alloc_one_1(_Ls_2);
_NCp1_NExprI_Prd_2(&(*_Ls_2)._Fexpr, _Lr_1);
_NCp1_NStmtSpace_Pstmt_push_7(_Lspace_0, &(*_Ls_2)._Fbase, _Gctx_begin_row, _Gctx_begin_col, _Gctx_end_row, _Gctx_end_col, _NCp1_NStmtType_Cexpr);
}
inline void _NCp1_NStmtSpace_Prd_if_2(struct _NCp1_NStmtSpace* _Lspace_0, union _NCp1_NRdr* _Lr_1) {
struct _NCp1_NStmtIf* _Ls_2;
_NCp1_Pquick_alloc_one_1(_Ls_2);
(*_Ls_2)._Fnot = _NCp1_NRdr_Pb_1(_Lr_1);
_NCp1_NExprI_Prd_2(&(*_Ls_2)._Fexpr, _Lr_1);
_NCp1_NStmtSpace_Pstmt_push_7(_Lspace_0, &(*_Ls_2)._Fbase, _Gctx_begin_row, _Gctx_begin_col, _Gctx_end_row, _Gctx_end_col, _NCp1_NStmtType_Cif);
}
inline void _NCp1_NStmtSpace_Prd_if_elif_2(struct _NCp1_NStmtSpace* _Lspace_0, union _NCp1_NRdr* _Lr_1) {
struct _NCp1_NStmtIfElif* _Ls_2;
_NCp1_Pquick_alloc_one_1(_Ls_2);
(*_Ls_2)._Fnot = _NCp1_NRdr_Pb_1(_Lr_1);
_NCp1_NExprI_Prd_2(&(*_Ls_2)._Fexpr, _Lr_1);
_NCp1_NStmtSpace_Pstmt_push_7(_Lspace_0, &(*_Ls_2)._Fbase, _Gctx_begin_row, _Gctx_begin_col, _Gctx_end_row, _Gctx_end_col, _NCp1_NStmtType_Cif_elif);
}
inline void _NCp1_NStmtSpace_Prd_if_else_2(struct _NCp1_NStmtSpace* _Lspace_0, union _NCp1_NRdr* _Lr_1) {
struct _NCp1_NStmtIfElse* _Ls_2;
_NCp1_Pquick_alloc_one_1(_Ls_2);
_NCp1_NStmtSpace_Pstmt_push_7(_Lspace_0, &(*_Ls_2)._Fbase, 0, 0, 0, 0, _NCp1_NStmtType_Cif_else);
}
inline void _NCp1_NStmtSpace_Prd_if_end_2(struct _NCp1_NStmtSpace* _Lspace_0, union _NCp1_NRdr* _Lr_1) {
struct _NCp1_NStmtIfEnd* _Ls_2;
_NCp1_Pquick_alloc_one_1(_Ls_2);
_NCp1_NStmtSpace_Pstmt_push_7(_Lspace_0, &(*_Ls_2)._Fbase, 0, 0, 0, 0, _NCp1_NStmtType_Cif_end);
}
inline void _NCp1_NStmtSpace_Prd_switch_2(struct _NCp1_NStmtSpace* _Lspace_0, union _NCp1_NRdr* _Lr_1) {
struct _NCp1_NStmtSwitch* _Ls_2;
_NCp1_Pquick_alloc_one_1(_Ls_2);
_NCp1_NExprI_Prd_2(&(*_Ls_2)._Fexpr, _Lr_1);
_NCp1_NExprI_Prd_2(&(*_Ls_2)._Fcases, _Lr_1);
_NCp1_NStmtSpace_Pstmt_push_7(_Lspace_0, &(*_Ls_2)._Fbase, _Gctx_begin_row, _Gctx_begin_col, _Gctx_end_row, _Gctx_end_col, _NCp1_NStmtType_Cswitch);
}
inline void _NCp1_NStmtSpace_Prd_case_2(struct _NCp1_NStmtSpace* _Lspace_0, union _NCp1_NRdr* _Lr_1) {
uint32_t _Lexpr_c_2;
struct _NCp1_NStmtCase* _Ls_3;
_Lexpr_c_2 = Fgetnum(_Lr_1);
_NCp1_Pquick_alloc_plus_2(_Ls_3, sizeof(struct _NCp1_NStmtCaseItem) * _Lexpr_c_2);
(*_Ls_3)._Fexpr_c = _Lexpr_c_2;
int32_t _Li_4;
_Li_4 = 0;
for(int i = _Lexpr_c_2; i > 0; ) {
i --;
_NCp1_NExprI_Prd_2(&(*_Ls_3)._Fexpr_v[_Li_4]._Fexpr, _Lr_1);
continue_0:;
_Li_4++;
}
break_0:;
(*_Ls_3)._Ffall_through = _NCp1_NRdr_Pb_1(_Lr_1);
_NCp1_NStmtSpace_Pstmt_push_7(_Lspace_0, &(*_Ls_3)._Fbase, _Gctx_begin_row, _Gctx_begin_col, _Gctx_end_row, _Gctx_end_col, _NCp1_NStmtType_Ccase);
}
inline void _NCp1_NStmtSpace_Prd_case_end_2(struct _NCp1_NStmtSpace* _Lspace_0, union _NCp1_NRdr* _Lr_1) {
struct _NCp1_NStmtCaseEnd* _Ls_2;
_NCp1_Pquick_alloc_one_1(_Ls_2);
_NCp1_NStmtSpace_Pstmt_push_7(_Lspace_0, &(*_Ls_2)._Fbase, _Gctx_begin_row, _Gctx_begin_col, _Gctx_end_row, _Gctx_end_col, _NCp1_NStmtType_Ccase_end);
}
inline void _NCp1_NStmtSpace_Prd_default_2(struct _NCp1_NStmtSpace* _Lspace_0, union _NCp1_NRdr* _Lr_1) {
struct _NCp1_NStmtDefault* _Ls_2;
_NCp1_Pquick_alloc_one_1(_Ls_2);
(*_Ls_2)._Ffall_through = _NCp1_NRdr_Pb_1(_Lr_1);
_NCp1_NStmtSpace_Pstmt_push_7(_Lspace_0, &(*_Ls_2)._Fbase, _Gctx_begin_row, _Gctx_begin_col, _Gctx_end_row, _Gctx_end_col, _NCp1_NStmtType_Cdefault);
}
inline void _NCp1_NStmtSpace_Prd_default_end_2(struct _NCp1_NStmtSpace* _Lspace_0, union _NCp1_NRdr* _Lr_1) {
struct _NCp1_NStmtDefaultEnd* _Ls_2;
_NCp1_Pquick_alloc_one_1(_Ls_2);
_NCp1_NStmtSpace_Pstmt_push_7(_Lspace_0, &(*_Ls_2)._Fbase, _Gctx_begin_row, _Gctx_begin_col, _Gctx_end_row, _Gctx_end_col, _NCp1_NStmtType_Cdefault_end);
}
inline void _NCp1_NStmtSpace_Prd_switch_end_2(struct _NCp1_NStmtSpace* _Lspace_0, union _NCp1_NRdr* _Lr_1) {
struct _NCp1_NStmtSwitchEnd* _Ls_2;
_NCp1_Pquick_alloc_one_1(_Ls_2);
_NCp1_NStmtSpace_Pstmt_push_7(_Lspace_0, &(*_Ls_2)._Fbase, 0, 0, 0, 0, _NCp1_NStmtType_Cswitch_end);
}
inline void _NCp1_NStmtSpace_Prd_do_2(struct _NCp1_NStmtSpace* _Lspace_0, union _NCp1_NRdr* _Lr_1) {
struct _NCp1_NStmtDo* _Ls_2;
_NCp1_Pquick_alloc_one_1(_Ls_2);
_NCp1_NExprI_Prd_2(&(*_Ls_2)._Fexpr, _Lr_1);
_NCp1_NStmtSpace_Pstmt_push_7(_Lspace_0, &(*_Ls_2)._Fbase, _Gctx_begin_row, _Gctx_begin_col, _Gctx_end_row, _Gctx_end_col, _NCp1_NStmtType_Cdo);
if(_NCp1_NRdr_Pb_1(_Lr_1)) {
struct _NCp1_NStmtSpace* _Lspace2_3;
_NCp1_Pquick_alloc_one_1(_Lspace2_3);
(*_Ls_2)._Fcontinu = _Lspace2_3;
_NCp1_NStmtSpace_Prd_3(_Lspace2_3, _Lr_1, _Lspace_0);
}
_Gnest_stack_id_v[_Gnest_stack_c] = _Gnest_id++;
_Gnest_stack_ptr_v[_Gnest_stack_c]._Fdo = _Ls_2;
_Gnest_stack_c++;
}
inline void _NCp1_NStmtSpace_Prd_do_end_2(struct _NCp1_NStmtSpace* _Lspace_0, union _NCp1_NRdr* _Lr_1) {
struct _NCp1_NStmtDo* _Ldo_2;
struct _NCp1_NStmtDoEnd* _Ls_3;
_Ldo_2 = _Gnest_stack_ptr_v[(_Gnest_stack_c -= 1)]._Fdo;
_NCp1_Pquick_alloc_one_1(_Ls_3);
(*_Ls_3)._Fdo = _Ldo_2;
(*_Ldo_2)._Fend = _Ls_3;
_NCp1_NStmtSpace_Pstmt_push_7(_Lspace_0, &(*_Ls_3)._Fbase, 0, 0, 0, 0, _NCp1_NStmtType_Cdo_end);
}
inline void _NCp1_NStmtSpace_Prd_while_2(struct _NCp1_NStmtSpace* _Lspace_0, union _NCp1_NRdr* _Lr_1) {
struct _NCp1_NStmtWhile* _Ls_2;
_NCp1_Pquick_alloc_one_1(_Ls_2);
_NCp1_NExprI_Prd_2(&(*_Ls_2)._Fexpr, _Lr_1);
_NCp1_NStmtSpace_Pstmt_push_7(_Lspace_0, &(*_Ls_2)._Fbase, _Gctx_begin_row, _Gctx_begin_col, _Gctx_end_row, _Gctx_end_col, _NCp1_NStmtType_Cwhile);
if(_NCp1_NRdr_Pb_1(_Lr_1)) {
struct _NCp1_NStmtSpace* _Lspace2_3;
_NCp1_Pquick_alloc_one_1(_Lspace2_3);
(*_Ls_2)._Fcontinu = _Lspace2_3;
_NCp1_NStmtSpace_Prd_3(_Lspace2_3, _Lr_1, _Lspace_0);
}
_Gnest_stack_id_v[_Gnest_stack_c] = _Gnest_id++;
_Gnest_stack_ptr_v[_Gnest_stack_c]._Fwhil = _Ls_2;
_Gnest_stack_c++;
}
inline void _NCp1_NStmtSpace_Prd_while_end_2(struct _NCp1_NStmtSpace* _Lspace_0, union _NCp1_NRdr* _Lr_1) {
struct _NCp1_NStmtWhile* _Lwhil_2;
struct _NCp1_NStmtWhileEnd* _Ls_3;
_Lwhil_2 = _Gnest_stack_ptr_v[(_Gnest_stack_c -= 1)]._Fwhil;
_NCp1_Pquick_alloc_one_1(_Ls_3);
(*_Ls_3)._Fwhil = _Lwhil_2;
(*_Lwhil_2)._Fend = _Ls_3;
_NCp1_NStmtSpace_Pstmt_push_7(_Lspace_0, &(*_Ls_3)._Fbase, 0, 0, 0, 0, _NCp1_NStmtType_Cwhile_end);
}
inline void _NCp1_NStmtSpace_Prd_continue_2(struct _NCp1_NStmtSpace* _Lspace_0, union _NCp1_NRdr* _Lr_1) {
struct _NCp1_NStmtContinue* _Ls_2;
_NCp1_Pquick_alloc_one_1(_Ls_2);
(*_Ls_2)._Fnest = _NCp1_NRdr_Pn1_1(_Lr_1);
_NCp1_NStmtSpace_Pstmt_push_7(_Lspace_0, &(*_Ls_2)._Fbase, _Gctx_begin_row, _Gctx_begin_col, _Gctx_end_row, _Gctx_end_col, _NCp1_NStmtType_Ccontinue);
}
inline void _NCp1_NStmtSpace_Prd_break_2(struct _NCp1_NStmtSpace* _Lspace_0, union _NCp1_NRdr* _Lr_1) {
struct _NCp1_NStmtBreak* _Ls_2;
_NCp1_Pquick_alloc_one_1(_Ls_2);
(*_Ls_2)._Fnest = _NCp1_NRdr_Pn1_1(_Lr_1);
_NCp1_NStmtSpace_Pstmt_push_7(_Lspace_0, &(*_Ls_2)._Fbase, _Gctx_begin_row, _Gctx_begin_col, _Gctx_end_row, _Gctx_end_col, _NCp1_NStmtType_Cbreak);
}
inline void _NCp1_NStmtSpace_Prd_return_2(struct _NCp1_NStmtSpace* _Lspace_0, union _NCp1_NRdr* _Lr_1) {
struct _NCp1_NStmtReturn* _Ls_2;
_NCp1_Pquick_alloc_one_1(_Ls_2);
_NCp1_NExprI_Prd_2(&(*_Ls_2)._Fexpr, _Lr_1);
_NCp1_NStmtSpace_Pstmt_push_7(_Lspace_0, &(*_Ls_2)._Fbase, _Gctx_begin_row, _Gctx_begin_col, _Gctx_end_row, _Gctx_end_col, _NCp1_NStmtType_Creturn);
}
inline void _NCp1_NStmtSpace_Prd_space_2(struct _NCp1_NStmtSpace* _Lspace_0, union _NCp1_NRdr* _Lr_1) {
struct _NCp1_NStmtSpace* _Ls_2;
_NCp1_Pquick_alloc_one_1(_Ls_2);
_NCp1_NStmtSpace_Prd_3(_Ls_2, _Lr_1, _Lspace_0);
_NCp1_NStmtSpace_Pstmt_push_7(_Lspace_0, &(*_Ls_2)._Fbase, _Gctx_begin_row, _Gctx_begin_col, _Gctx_end_row, _Gctx_end_col, _NCp1_NStmtType_Cspace);
}
inline void _NCp1_NStmt_Pprocess_expr_2(struct _NCp1_NStmt* _Lstmt_0, bool* _Lok_1) {
struct _NCp1_NStmtExpr* _Ls_2;
_Ls_2 = _Lstmt_0;
if(!(_NCp1_NExprI_Pprocess_1((*_Ls_2)._Fexpr))) {
return;
}
(*_Lok_1) = true;
}
inline void _NCp1_NStmt_Pprocess_if_2(struct _NCp1_NStmt* _Lstmt_0, bool* _Lok_1) {
struct _NCp1_NStmtIf* _Ls_2;
_Ls_2 = _Lstmt_0;
if(!(_NCp1_NExprI_Pvalue_4((*_Ls_2)._Fexpr, 1, false, &(*_Ls_2)._Fval))) {
return;
}
(*_Lok_1) = true;
}
inline void _NCp1_NStmt_Pprocess_if_elif_2(struct _NCp1_NStmt* _Lstmt_0, bool* _Lok_1) {
struct _NCp1_NStmtIfElif* _Ls_2;
_Ls_2 = _Lstmt_0;
if(!(_NCp1_NExprI_Pvalue_4((*_Ls_2)._Fexpr, 1, false, &(*_Ls_2)._Fval))) {
return;
}
(*_Lok_1) = true;
}
inline void _NCp1_NStmt_Pprocess_if_else_2(struct _NCp1_NStmt* _Lstmt_0, bool* _Lok_1) {
struct _NCp1_NStmtIfElse* _Ls_2;
_Ls_2 = _Lstmt_0;
(*_Lok_1) = true;
}
inline void _NCp1_NStmt_Pprocess_if_end_2(struct _NCp1_NStmt* _Lstmt_0, bool* _Lok_1) {
struct _NCp1_NStmtIfEnd* _Ls_2;
_Ls_2 = _Lstmt_0;
(*_Lok_1) = true;
}
inline void _NCp1_NStmt_Pprocess_switch_2(struct _NCp1_NStmt* _Lstmt_0, bool* _Lok_1) {
struct _NCp1_NStmtSwitch* _Ls_2;
_Ls_2 = _Lstmt_0;
_Gswitch_stack_v[_Gswitch_stack_c++] = _Ls_2;
if(!(_NCp1_NExprI_Pvalue_4((*_Ls_2)._Fexpr, 1, false, &(*_Ls_2)._Fval))) {
return;
}
if((*_Ls_2)._Fval._Ftype == _NCp1_NAt_Cnil) {
fprintf(stdout, "%s:%u:%u: Error, the expression used for switch doesn:T have a type\n", _NCp1_NFile_Ppath_1((*_Gctx_func)._Ffile), (*_Ls_2)._Fbase._Fbegin_row, (*_Ls_2)._Fbase._Fbegin_col);
return;
}
if((*_Ls_2)._Fcases != _NCp1_NExprI_Cnil) {
struct _NCp1_NAtData* _Ltype_3;
struct _NCp1_NExprFunc* _Le_4;
_NCp1_NId _Lfunc_name_5;
struct _NCp1_NAtData* _Lf_6;
int32_t _Lcase_c_7;
int32_t _Lcase_cap_8;
_NCp1_NFunc* _Lcase_v_9;
_Ltype_3 = _NCp1_NAt_Pptr_1((*_Ls_2)._Fval._Ftype);
if((*_Ltype_3)._Fdef != _NCp1_NAtDef_Cenum) {
fprintf(stdout, "%s:%u:%u: Error, the expression used for switch must be an enum when using @case attribute\n", _NCp1_NFile_Ppath_1((*_Gctx_func)._Ffile), (*_Ls_2)._Fbase._Fbegin_row, (*_Ls_2)._Fbase._Fbegin_col);
return;
}
_Le_4 = _NCp1_NExprI_Pptr_1((*_Ls_2)._Fcases);
_Lfunc_name_5 = (*_Le_4)._Ffunc_name;
_Lf_6 = _NCp1_NAt_Pptr_1((*_Gctx_func)._Fat);
_Lcase_c_7 = 0;
_Lcase_cap_8 = 0;
_Lcase_v_9 = NULL;
int32_t _Li_10;
_Li_10 = 0;
for(int i = (*_Lf_6)._Ffunc_c; i > 0; ) {
i --;
_NCp1_NFunc _Lfunc_i_11;
struct _NCp1_NDeclFunc* _Lfunc_12;
_Lfunc_i_11 = (*_Lf_6)._Ffunc_v[_Li_10];
_Lfunc_12 = _NCp1_NFunc_Pptr_1(_Lfunc_i_11);
if(((*_Lfunc_12)._Fflags & _NCp1_NFuncFlags_Ccase) != _NCp1_NFuncFlags_C0) {
if((*_Lfunc_12)._Fcas == _Lfunc_name_5) {
int32_t _Lci_13;
_Lci_13 = _Lcase_c_7++;
if(_Lcase_cap_8 <= _Lcase_c_7) {
int32_t _Lold_cap_14;
_Lold_cap_14 = _Lcase_cap_8;
_NCp1_Pgrow_2(_Lcase_cap_8, _Lcase_c_7);
_NCp1_Prealloc_3(_Lcase_v_9, _Lcase_cap_8, _Lold_cap_14);
}
_Lcase_v_9[_Lci_13] = _Lfunc_i_11;
}
}
continue_0:;
_Li_10++;
}
break_0:;
if(_Lcase_c_7 > 0) {
char* _Lfunc_name_str_15;
uint8_t _Lfunc_name_len_16;
struct _NCp1_NStmtSwitchCaseFunc* _Lfunc_v_17;
if(!(_NCp1_NExprI_Pprocess_case_func_2(_NCp1_NExprI_Pptr_1((*_Ls_2)._Fcases), _Lcase_v_9[0]))) {
return;
}
_Lfunc_name_str_15 = _NCp1_NId_Pstr_1(_Lfunc_name_5);
_Lfunc_name_len_16 = _NCp1_NId_Plen_1(_Lfunc_name_5);
(*_Ls_2)._Fcase_func_c = _Lcase_c_7;
_NCp1_Pquick_alloc_arr_2((*_Ls_2)._Fcase_func_v, _Lcase_c_7);
_Lfunc_v_17 = (*_Ls_2)._Fcase_func_v;
int32_t _Li_18;
_Li_18 = 0;
for(int i = _Lcase_c_7; i > 0; ) {
i --;
_NCp1_NFunc _Lfunc_i_19;
struct _NCp1_NDeclFunc* _Lfunc_20;
_NCp1_NId _Lfunc_name2_21;
char* _Lcvar_name_str_22;
uint8_t _Lcvar_name_len_23;
_NCp1_NId _Lfound_id_24;
_NCp1_NCvar _Lfound_cvar_26;
_Lfunc_i_19 = _Lcase_v_9[_Li_18];
_Lfunc_20 = _NCp1_NFunc_Pptr_1(_Lfunc_i_19);
_Lfunc_name2_21 = (*_Lfunc_20)._Fdecl._Fname;
_Lcvar_name_str_22 = &_NCp1_NId_Pstr_1(_Lfunc_name2_21)[(_Lfunc_name_len_16 + 1)];
_Lcvar_name_len_23 = (_NCp1_NId_Plen_1(_Lfunc_name2_21) - (_Lfunc_name_len_16 + 1));
_Lfound_id_24 = _NCp1_NId_Cnil;
_NCp1_NId _Lj_25;
_Lj_25 = (_NCp1_NId)(0);
for(int i = _Gid_c; i > 0; ) {
i --;
if(((_NCp1_NId_Plen_1(_Lj_25) == _Lcvar_name_len_23) && (memcmp(_NCp1_NId_Pstr_1(_Lj_25), _Lcvar_name_str_22, _Lcvar_name_len_23) == 0))) {
_Lfound_id_24 = _Lj_25;
goto break_2;
}
continue_2:;
_Lj_25++;
}
break_2:;
if(_Lfound_id_24 == _NCp1_NId_Cnil) {
fprintf(stdout, "%s:%u:%u: Cannot find a case for cvar named '#%s'\n", _NCp1_NFile_Ppath_1((*_Lfunc_20)._Ffile), (*_Lfunc_20)._Fbegin_row, (*_Lfunc_20)._Fbegin_col, _Lcvar_name_str_22);
return;
}
_Lfound_cvar_26 = _NCp1_NCvar_Cnil;
int32_t _Lj_27;
_Lj_27 = 0;
for(int i = (*_Ltype_3)._Fcvar_c; i > 0; ) {
i --;
_NCp1_NCvar _Lcvar_i_28;
struct _NCp1_NCvarData* _Lcvar_29;
_Lcvar_i_28 = (*_Ltype_3)._Fcvar_v[_Lj_27];
_Lcvar_29 = _NCp1_NCvar_Pptr_1(_Lcvar_i_28);
if((*_Lcvar_29)._Fdecl._Fname == _Lfound_id_24) {
_Lfound_cvar_26 = _Lcvar_i_28;
goto break_3;
}
continue_3:;
_Lj_27++;
}
break_3:;
if(_Lfound_cvar_26 == _NCp1_NCvar_Cnil) {
fprintf(stdout, "%s:%u:%u: Cannot find a case for cvar named '#%s'\n", _NCp1_NFile_Ppath_1((*_Lfunc_20)._Ffile), (*_Lfunc_20)._Fbegin_row, (*_Lfunc_20)._Fbegin_col, _Lcvar_name_str_22);
return;
}
if(!(_NCp1_NCvar_Pprocess_1(_Lfound_cvar_26))) {
return;
}
_NCp1_NFunc_Pprocess_later_1(_Lfunc_i_19);
_Lfunc_v_17[_Li_18]._Fcvar = _Lfound_cvar_26;
_Lfunc_v_17[_Li_18]._Ffunc = _Lfunc_i_19;
continue_1:;
_Li_18++;
}
break_1:;
free(_Lcase_v_9);
}
}
(*_Lok_1) = true;
}
inline void _NCp1_NStmt_Pprocess_case_2(struct _NCp1_NStmt* _Lstmt_0, bool* _Lok_1) {
struct _NCp1_NStmtCase* _Ls_2;
struct _NCp1_NStmtSwitch* _Lswitc_3;
_Ls_2 = _Lstmt_0;
_Lswitc_3 = _Gswitch_stack_v[(_Gswitch_stack_c - 1)];
if((*_Lswitc_3)._Fval._Ftype != _NCp1_NAt_Cnil) {
_NCp1_NAt _Ltype_i_4;
struct _NCp1_NAtData* _Ltype_5;
_Ltype_i_4 = (*_Lswitc_3)._Fval._Ftype;
_Ltype_5 = _NCp1_NAt_Pptr_1(_Ltype_i_4);
if((*_Ltype_5)._Fdef == _NCp1_NAtDef_Cenum) {
int32_t _Li_6;
_Li_6 = 0;
for(int i = (*_Ls_2)._Fexpr_c; i > 0; ) {
i --;
_NCp1_NExprI _Le_i_7;
struct _NCp1_NExpr* _Le_8;
_Le_i_7 = (*_Ls_2)._Fexpr_v[_Li_6]._Fexpr;
_Le_8 = _NCp1_NExprI_Pptr_1(_Le_i_7);
if((*_Le_8)._Ftype == _NCp1_NExprType_Ccvar) {
struct _NCp1_NExprCvar* _Le2_9;
_Le2_9 = _Le_8;
if((*_Le2_9)._Fat == _NCp1_NAt_Cnil) {
(*_Le2_9)._Ftry = _Ltype_i_4;
}
}
continue_0:;
_Li_6++;
}
break_0:;
}
}
int32_t _Li_10;
_Li_10 = 0;
for(int i = (*_Ls_2)._Fexpr_c; i > 0; ) {
i --;
_NCp1_NExprI _Le_i_11;
_Le_i_11 = (*_Ls_2)._Fexpr_v[_Li_10]._Fexpr;
if(!(_NCp1_NExprI_Pvalue_4(_Le_i_11, 1, true, &(*_Ls_2)._Fexpr_v[_Li_10]._Fval))) {
return;
}
continue_1:;
_Li_10++;
}
break_1:;
(*_Lok_1) = true;
}
inline void _NCp1_NStmt_Pprocess_case_end_2(struct _NCp1_NStmt* _Lstmt_0, bool* _Lok_1) {
struct _NCp1_NStmtCaseEnd* _Ls_2;
_Ls_2 = _Lstmt_0;
(*_Lok_1) = true;
}
inline void _NCp1_NStmt_Pprocess_default_2(struct _NCp1_NStmt* _Lstmt_0, bool* _Lok_1) {
(*_Lok_1) = true;
}
inline void _NCp1_NStmt_Pprocess_default_end_2(struct _NCp1_NStmt* _Lstmt_0, bool* _Lok_1) {
struct _NCp1_NStmtDefaultEnd* _Ls_2;
_Ls_2 = _Lstmt_0;
(*_Lok_1) = true;
}
inline void _NCp1_NStmt_Pprocess_switch_end_2(struct _NCp1_NStmt* _Lstmt_0, bool* _Lok_1) {
struct _NCp1_NStmtSwitchEnd* _Ls_2;
_Gswitch_stack_c -= 1;
_Ls_2 = _Lstmt_0;
(*_Lok_1) = true;
}
inline void _NCp1_NStmt_Pprocess_do_2(struct _NCp1_NStmt* _Lstmt_0, bool* _Lok_1) {
struct _NCp1_NStmtDo* _Ls_2;
_Ls_2 = _Lstmt_0;
if((*_Ls_2)._Fexpr != _NCp1_NExprI_Cnil) {
if(!(_NCp1_NExprI_Pprocess_1((*_Ls_2)._Fexpr))) {
return;
}
}
(*_Lok_1) = true;
}
inline void _NCp1_NStmt_Pprocess_do_end_2(struct _NCp1_NStmt* _Lstmt_0, bool* _Lok_1) {
struct _NCp1_NStmtDoEnd* _Ls_2;
struct _NCp1_NStmtSpace* _Lcontinu_3;
_Ls_2 = _Lstmt_0;
_Lcontinu_3 = (*(*_Ls_2)._Fdo)._Fcontinu;
if(_Lcontinu_3 != NULL) {
_NCp1_NStmtSpace_Pprocess_1(_Lcontinu_3);
}
(*_Lok_1) = true;
}
inline void _NCp1_NStmt_Pprocess_while_2(struct _NCp1_NStmt* _Lstmt_0, bool* _Lok_1) {
struct _NCp1_NStmtWhile* _Ls_2;
_Ls_2 = _Lstmt_0;
if((*_Ls_2)._Fexpr != _NCp1_NExprI_Cnil) {
if(!(_NCp1_NExprI_Pprocess_1((*_Ls_2)._Fexpr))) {
return;
}
}
(*_Lok_1) = true;
}
inline void _NCp1_NStmt_Pprocess_while_end_2(struct _NCp1_NStmt* _Lstmt_0, bool* _Lok_1) {
struct _NCp1_NStmtWhileEnd* _Ls_2;
struct _NCp1_NStmtSpace* _Lcontinu_3;
_Ls_2 = _Lstmt_0;
_Lcontinu_3 = (*(*_Ls_2)._Fwhil)._Fcontinu;
if(_Lcontinu_3 != NULL) {
_NCp1_NStmtSpace_Pprocess_1(_Lcontinu_3);
}
(*_Lok_1) = true;
}
inline void _NCp1_NStmt_Pprocess_continue_2(struct _NCp1_NStmt* _Lstmt_0, bool* _Lok_1) {
struct _NCp1_NStmtContinue* _Ls_2;
_Ls_2 = _Lstmt_0;
(*_Lok_1) = true;
}
inline void _NCp1_NStmt_Pprocess_break_2(struct _NCp1_NStmt* _Lstmt_0, bool* _Lok_1) {
struct _NCp1_NStmtBreak* _Ls_2;
_Ls_2 = _Lstmt_0;
(*_Lok_1) = true;
}
inline void _NCp1_NStmt_Pprocess_return_2(struct _NCp1_NStmt* _Lstmt_0, bool* _Lok_1) {
struct _NCp1_NStmtReturn* _Ls_2;
_Ls_2 = _Lstmt_0;
if((*_Ls_2)._Fexpr != _NCp1_NExprI_Cnil) {
_NCp1_NExprI_Ptry_deduce_2((*_Ls_2)._Fexpr, (*_Gctx_func)._Fdecl._Ftype);
if(!(_NCp1_NExprI_Pvalue_4((*_Ls_2)._Fexpr, 1 + (*_Gctx_func)._Fdecl._Ftype_info._Fref_v[(*_Gctx_func)._Fdecl._Ftype_info._Farray_c], false, &(*_Ls_2)._Fval))) {
return;
}
}
(*_Lok_1) = true;
}
inline void _NCp1_NStmt_Pprocess_space_2(struct _NCp1_NStmt* _Lstmt_0, bool* _Lok_1) {
struct _NCp1_NStmtSpace* _Lspace_2;
_Lspace_2 = _Lstmt_0;
if(!(_NCp1_NStmtSpace_Pprocess_1(_Lspace_2))) {
return;
}
(*_Lok_1) = true;
}
inline void _NCp1_NExprI_Pvalue_assign_5(_NCp1_NExprI _Le_0, int8_t _Lreff_1, bool _Lparen_2, struct _NCp1_NValue* _Lv_3, bool* _Lok_4) {
struct _NCp1_NExprAssign* _Lexpr_5;
_Lexpr_5 = _NCp1_NExprI_Pptr_1(_Le_0);
if(_NCp1_NExprI_Pvalue_4((*_Lexpr_5)._Fleft, 1, _Lparen_2, _Lv_3) == false) {
return;
}
(*_Lv_3)._Fparen = _Lparen_2;
(*_Lv_3)._Freff = _Lreff_1;
(*_Lok_4) = true;
}
inline void _NCp1_NExprI_Pvalue_compare_5(_NCp1_NExprI _Le_0, int8_t _Lreff_1, bool _Lparen_2, struct _NCp1_NValue* _Lv_3, bool* _Lok_4) {
struct _NCp1_NExprCompare* _Lexpr_5;
_Lexpr_5 = _NCp1_NExprI_Pptr_1(_Le_0);
(*_Lv_3)._Ftype = _NCp1_Pbasic_type_1(_NCp1_NBasicTypeId_Cbool);
_NCp1_NTypeInfo_Pinit_1(&(*_Lv_3)._Finfo);
(*_Lv_3)._Finfo._Farray_c = 0;
(*_Lv_3)._Finfo._Fref_v[0] = '\0';
(*_Lv_3)._Finfo._Fstar_c = 0;
(*_Lv_3)._Freff = 1;
(*_Lv_3)._Fparen = _Lparen_2;
(*_Lok_4) = true;
}
inline void _NCp1_NExprI_Pvalue_bool_5(_NCp1_NExprI _Lle_0, int32_t _Lreff_1, bool _Lparen_2, struct _NCp1_NValue* _Lv_3, bool* _Lok_4) {
(*_Lv_3)._Ftype = _NCp1_Pbasic_type_1(_NCp1_NBasicTypeId_Cbool);
_NCp1_NTypeInfo_Pinit_1(&(*_Lv_3)._Finfo);
(*_Lv_3)._Finfo._Farray_c = 0;
(*_Lv_3)._Finfo._Fref_v[0] = '\0';
(*_Lv_3)._Finfo._Fstar_c = 0;
(*_Lv_3)._Freff = 1;
(*_Lv_3)._Fparen = false;
(*_Lok_4) = true;
}
inline void _NCp1_NExprI_Pvalue_char_5(_NCp1_NExprI _Lle_0, int32_t _Lreff_1, bool _Lparen_2, struct _NCp1_NValue* _Lv_3, bool* _Lok_4) {
(*_Lv_3)._Ftype = _NCp1_Pbasic_type_1(_NCp1_NBasicTypeId_Cchar);
_NCp1_NTypeInfo_Pinit_1(&(*_Lv_3)._Finfo);
(*_Lv_3)._Finfo._Farray_c = 0;
(*_Lv_3)._Finfo._Fref_v[0] = '\0';
(*_Lv_3)._Finfo._Fstar_c = 0;
(*_Lv_3)._Freff = 1;
(*_Lv_3)._Fparen = false;
(*_Lok_4) = true;
}
inline void _NCp1_NExprI_Pvalue_math_5(_NCp1_NExprI _Le_0, int8_t _Lreff_1, bool _Lparen_2, struct _NCp1_NValue* _Lv_3, bool* _Lok_4) {
struct _NCp1_NExprMath* _Lexpr_5;
_Lexpr_5 = _NCp1_NExprI_Pptr_1(_Le_0);
if(!(_NCp1_NExprI_Pvalue_4((*_Lexpr_5)._Fleft, 1, _Lparen_2, _Lv_3))) {
return;
}
(*_Lv_3)._Fparen = _Lparen_2;
(*_Lv_3)._Freff = _Lreff_1;
(*_Lok_4) = true;
}
inline void _NCp1_NExprI_Pvalue_unary_5(_NCp1_NExprI _Le_0, int8_t _Lreff_1, bool _Lparen_2, struct _NCp1_NValue* _Lv_3, bool* _Lok_4) {
struct _NCp1_NExprUnary* _Lexpr_5;
_Lexpr_5 = _NCp1_NExprI_Pptr_1(_Le_0);
(*_Lv_3)._Ftype = _NCp1_NExprI_Ptype_1((*_Lexpr_5)._Fexpr);
_NCp1_NTypeInfo_Pinit_1(&(*_Lv_3)._Finfo);
(*_Lv_3)._Finfo._Farray_c = 0;
(*_Lv_3)._Finfo._Fref_v[0] = 0;
(*_Lv_3)._Finfo._Fstar_c = 0;
(*_Lv_3)._Freff = 1;
(*_Lok_4) = true;
}
inline void _NCp1_NExprI_Pvalue_ref_5(_NCp1_NExprI _Le_0, int8_t _Lreff_1, bool _Lparen_2, struct _NCp1_NValue* _Lv_3, bool* _Lok_4) {
struct _NCp1_NExprRef* _Lexpr_5;
_Lexpr_5 = _NCp1_NExprI_Pptr_1(_Le_0);
(*_Lv_3)._Ftype = _NCp1_Pbasic_type_1(_NCp1_NBasicTypeId_Cref);
_NCp1_NTypeInfo_Pinit_1(&(*_Lv_3)._Finfo);
(*_Lv_3)._Finfo._Farray_c = 0;
(*_Lv_3)._Finfo._Fref_v[0] = 1;
(*_Lv_3)._Finfo._Fstar_c = 1;
(*_Lv_3)._Freff = 1;
(*_Lok_4) = true;
}
inline void _NCp1_NExprI_Pvalue_cast_fast_5(_NCp1_NExprI _Le_0, int8_t _Lreff_1, bool _Lparen_2, struct _NCp1_NValue* _Lv_3, bool* _Lok_4) {
struct _NCp1_NExprCastFast* _Lexpr_5;
_Lexpr_5 = _NCp1_NExprI_Pptr_1(_Le_0);
_NCp1_NExprI_Pvalue_4((*_Lexpr_5)._Fexpr, _Lreff_1, _Lparen_2, _Lv_3);
(*_Lv_3)._Ftype = (*_Lexpr_5)._Ftype;
(*_Lok_4) = true;
}
inline void _NCp1_NExprI_Pvalue_lvar_5(_NCp1_NExprI _Le_0, int8_t _Lreff_1, bool _Lparen_2, struct _NCp1_NValue* _Lv_3, bool* _Lok_4) {
struct _NCp1_NExprLvar* _Lexpr_5;
struct _NCp1_NLvarData* _Llvar_6;
_Lexpr_5 = _NCp1_NExprI_Pptr_1(_Le_0);
_Llvar_6 = _NCp1_NLvar_Pptr_1((*_Lexpr_5)._Flvar);
_NCp1_NValue_Pset_5(_Lv_3, _Lreff_1, _Lparen_2, (*_Llvar_6)._Fdecl._Ftype, &(*_Llvar_6)._Fdecl._Ftype_info);
if((*_Lv_3)._Freff == 1) {
(*_Lv_3)._Fparen = false;
}
(*_Lok_4) = true;
}
inline void _NCp1_NExprI_Pvalue_fvar_5(_NCp1_NExprI _Lexpr_0, int8_t _Lreff_1, bool _Lparen_2, struct _NCp1_NValue* _Lv_3, bool* _Lok_4) {
struct _NCp1_NExprFvar* _Le_5;
struct _NCp1_NFvarData* _Lfvar_6;
_Le_5 = _NCp1_NExprI_Pptr_1(_Lexpr_0);
_Lfvar_6 = (&(*_NCp1_NStruct_Pptr_1((*_NCp1_NAt_Pptr_1((*_Le_5)._Fval._Ftype))._Fdecl._Fstruct))._Ffvar_v[(*_Le_5)._Ffvar]);
_NCp1_NValue_Pset_5(_Lv_3, _Lreff_1, _Lparen_2, (*_Lfvar_6)._Fdecl._Ftype, &(*_Lfvar_6)._Fdecl._Ftype_info);
if((*_Lv_3)._Freff == 1) {
(*_Lv_3)._Fparen = false;
}
(*_Lok_4) = true;
}
inline void _NCp1_NExprI_Pvalue_gvar_5(_NCp1_NExprI _Lg_0, int32_t _Lreff_1, bool _Lparen_2, struct _NCp1_NValue* _Lv_3, bool* _Lok_4) {
struct _NCp1_NExprGvar* _Le_5;
struct _NCp1_NDeclGvar* _Lgvar_6;
_Le_5 = _NCp1_NExprI_Pptr_1(_Lg_0);
_Lgvar_6 = _NCp1_NGvar_Pptr_1((*_Le_5)._Fgvar);
_NCp1_NValue_Pset_5(_Lv_3, _Lreff_1, _Lparen_2, (*_Lgvar_6)._Fdecl._Ftype, &(*_Lgvar_6)._Fdecl._Ftype_info);
if((*_Lv_3)._Freff == 1) {
(*_Lv_3)._Fparen = false;
}
(*_Lok_4) = true;
}
inline void _NCp1_NExprI_Pvalue_cvar_5(_NCp1_NExprI _Le_0, int8_t _Lreff_1, bool _Lparen_2, struct _NCp1_NValue* _Lv_3, bool* _Lok_4) {
struct _NCp1_NExprCvar* _Lexpr_5;
struct _NCp1_NCvarData* _Lcvar_6;
_Lexpr_5 = _NCp1_NExprI_Pptr_1(_Le_0);
_Lcvar_6 = _NCp1_NCvar_Pptr_1((*_Lexpr_5)._Fcvar);
_NCp1_NValue_Pset_5(_Lv_3, _Lreff_1, _Lparen_2, (*_Lcvar_6)._Fdecl._Ftype, &(*_Lcvar_6)._Fdecl._Ftype_info);
if((*_Lv_3)._Freff == 1) {
(*_Lv_3)._Fparen = false;
}
(*_Lok_4) = true;
}
inline void _NCp1_NExprI_Pvalue_bools_5(_NCp1_NExprI _Le_0, int32_t _Lreff_1, bool _Lparen_2, struct _NCp1_NValue* _Lv_3, bool* _Lok_4) {
(*_Lv_3)._Ftype = _NCp1_Pbasic_type_1(_NCp1_NBasicTypeId_Cbool);
_NCp1_NTypeInfo_Pinit_1(&(*_Lv_3)._Finfo);
(*_Lv_3)._Finfo._Farray_c = 0;
(*_Lv_3)._Finfo._Fref_v[0] = '\0';
(*_Lv_3)._Finfo._Fstar_c = 0;
(*_Lv_3)._Freff = 1;
(*_Lv_3)._Fparen = false;
(*_Lok_4) = true;
}
inline void _NCp1_NExprI_Pvalue_func_5(_NCp1_NExprI _Le_0, int32_t _Lreff_1, bool _Lparen_2, struct _NCp1_NValue* _Lv_3, bool* _Lok_4) {
struct _NCp1_NExprFunc* _Lexpr_5;
struct _NCp1_NDeclFunc* _Lf_6;
_Lexpr_5 = _NCp1_NExprI_Pptr_1(_Le_0);
_Lf_6 = _NCp1_NFunc_Pptr_1((*_Lexpr_5)._Ffunc_idx);
_NCp1_NValue_Pset_5(_Lv_3, _Lreff_1, _Lparen_2, (*_Lf_6)._Fdecl._Ftype, &(*_Lf_6)._Fdecl._Ftype_info);
if((*_Lv_3)._Freff == 1) {
(*_Lv_3)._Fparen = false;
}
(*_Lok_4) = true;
}
inline void _NCp1_NExprI_Pvalue_method_5(_NCp1_NExprI _Le_0, int32_t _Lreff_1, bool _Lparen_2, struct _NCp1_NValue* _Lv_3, bool* _Lok_4) {
struct _NCp1_NExprMethod* _Lexpr_5;
struct _NCp1_NDeclFunc* _Lf_6;
_Lexpr_5 = _NCp1_NExprI_Pptr_1(_Le_0);
_Lf_6 = _NCp1_NFunc_Pptr_1((*_Lexpr_5)._Ffunc_idx);
_NCp1_NValue_Pset_5(_Lv_3, _Lreff_1, _Lparen_2, (*_Lf_6)._Fdecl._Ftype, &(*_Lf_6)._Fdecl._Ftype_info);
if((*_Lv_3)._Freff == 1) {
(*_Lv_3)._Fparen = false;
}
(*_Lok_4) = true;
}
inline void _NCp1_NExprI_Pvalue_str_5(_NCp1_NExprI _Ls_0, int32_t _Lreff_1, bool _Lparen_2, struct _NCp1_NValue* _Lv_3, bool* _Lok_4) {
(*_Lv_3)._Ftype = _NCp1_Pbasic_type_1(_NCp1_NBasicTypeId_Cchar);
_NCp1_NTypeInfo_Pinit_1(&(*_Lv_3)._Finfo);
(*_Lv_3)._Finfo._Farray_c = 1;
(*_Lv_3)._Finfo._Fref_v[0] = '\0';
(*_Lv_3)._Finfo._Fref_v[1] = '\0';
(*_Lv_3)._Finfo._Fstar_c = 1;
(*_Lv_3)._Freff = 1;
(*_Lok_4) = true;
}
inline void _NCp1_NExprI_Pvalue_i32_5(_NCp1_NExprI _Lle_0, int32_t _Lreff_1, bool _Lparen_2, struct _NCp1_NValue* _Lv_3, bool* _Lok_4) {
(*_Lv_3)._Ftype = _NCp1_Pbasic_type_1(_NCp1_NBasicTypeId_Ci32);
_NCp1_NTypeInfo_Pinit_1(&(*_Lv_3)._Finfo);
(*_Lv_3)._Finfo._Farray_c = 0;
(*_Lv_3)._Finfo._Fref_v[0] = '\0';
(*_Lv_3)._Finfo._Fstar_c = 0;
(*_Lv_3)._Freff = 1;
(*_Lv_3)._Fparen = false;
(*_Lok_4) = true;
}
inline void _NCp1_NExprI_Pvalue_size_of_type_5(_NCp1_NExprI _Lle_0, int32_t _Lreff_1, bool _Lparen_2, struct _NCp1_NValue* _Lv_3, bool* _Lok_4) {
(*_Lv_3)._Ftype = _NCp1_Pbasic_type_1(_NCp1_NBasicTypeId_Cusz);
_NCp1_NTypeInfo_Pinit_1(&(*_Lv_3)._Finfo);
(*_Lv_3)._Finfo._Farray_c = 0;
(*_Lv_3)._Finfo._Fref_v[0] = '\0';
(*_Lv_3)._Finfo._Fstar_c = 0;
(*_Lv_3)._Freff = 1;
(*_Lv_3)._Fparen = false;
(*_Lok_4) = true;
}
inline void _NCp1_NExprI_Pvalue_null_5(_NCp1_NExprI _Lle_0, int32_t _Lreff_1, bool _Lparen_2, struct _NCp1_NValue* _Lv_3, bool* _Lok_4) {
(*_Lv_3)._Ftype = _NCp1_Pbasic_type_1(_NCp1_NBasicTypeId_Cref);
_NCp1_NTypeInfo_Pinit_1(&(*_Lv_3)._Finfo);
(*_Lv_3)._Finfo._Farray_c = 0;
(*_Lv_3)._Finfo._Fref_v[0] = '\0';
(*_Lv_3)._Finfo._Fstar_c = 0;
(*_Lv_3)._Freff = 1;
(*_Lv_3)._Fparen = false;
(*_Lok_4) = true;
}
inline void _NCp1_NExprI_Pvalue_index_5(_NCp1_NExprI _Le_0, int8_t _Lreff_1, bool _Lparen_2, struct _NCp1_NValue* _Lv_3, bool* _Lok_4) {
struct _NCp1_NExprIndex* _Lexpr_5;
int8_t _Lc_6;
_Lexpr_5 = _NCp1_NExprI_Pptr_1(_Le_0);
(*_Lv_3)._Ftype = (*_Lexpr_5)._Fleft_val._Ftype;
_NCp1_NTypeInfo_Pinit_1(&(*_Lv_3)._Finfo);
_NCp1_NTypeInfo_Pcopy_from_2(&(*_Lv_3)._Finfo, &(*_Lexpr_5)._Fleft_val._Finfo);
(*_Lv_3)._Finfo._Farray_c -= 1;
_Lc_6 = (*_Lv_3)._Finfo._Fref_v[(*_Lv_3)._Finfo._Farray_c];
(*_Lv_3)._Freff = ((_Lc_6 + 2) - _Lreff_1);
(*_Lv_3)._Finfo._Fref_v[(*_Lv_3)._Finfo._Farray_c] = (_Lreff_1 - 1);
_NCp1_NTypeInfo_Pcount_1(&(*_Lv_3)._Finfo);
if((*_Lv_3)._Freff == 1) {
(*_Lv_3)._Fparen = false;
} else {
(*_Lv_3)._Fparen = _Lparen_2;
}
(*_Lok_4) = true;
}
inline void _NCp1_NExprI_Pprocess_assign_2(struct _NCp1_NExpr* _Lexpr_0, bool* _Lok_1) {
struct _NCp1_NExprAssign* _Le_2;
struct _NCp1_NExpr* _Lleft_e_3;
_Le_2 = _Lexpr_0;
_Lleft_e_3 = _NCp1_NExprI_Pptr_1((*_Le_2)._Fleft);
if((*_Lleft_e_3)._Ftype == _NCp1_NExprType_Clvar) {
struct _NCp1_NExprLvar* _Lleft_4;
struct _NCp1_NLvarData* _Llvar_5;
_Lleft_4 = _Lleft_e_3;
_Llvar_5 = _NCp1_NLvar_Pptr_1((*_Lleft_4)._Flvar);
if((*_Llvar_5)._Fdecl._Ftype == _NCp1_NAt_Cnil) {
struct _NCp1_NAtData* _Lat_6;
if(!(_NCp1_NExprI_Pvalue_4((*_Le_2)._Fright, 1, true, &(*_Le_2)._Fright_val))) {
return;
}
(*_Llvar_5)._Fdecl._Ftype = (*_Le_2)._Fright_val._Ftype;
_Lat_6 = _NCp1_NAt_Pptr_1((*_Llvar_5)._Fdecl._Ftype);
_NCp1_NTypeInfo_Pinit_1(&(*_Llvar_5)._Fdecl._Ftype_info);
_NCp1_NTypeInfo_Pcopy_from_2(&(*_Llvar_5)._Fdecl._Ftype_info, &(*_Le_2)._Fright_val._Finfo);
_NCp1_NExprI_Pvalue_4((*_Le_2)._Fleft, 1, true, &(*_Le_2)._Fleft_val);
(*_Lok_1) = true;
return;
}
}
if(!(_NCp1_NExprI_Pvalue_4((*_Le_2)._Fleft, 1, true, &(*_Le_2)._Fleft_val))) {
return;
}
_NCp1_NExprI_Ptry_deduce_2((*_Le_2)._Fright, _NCp1_NExprI_Ptype_1((*_Le_2)._Fleft));
if(!(_NCp1_NExprI_Pvalue_4((*_Le_2)._Fright, 1, true, &(*_Le_2)._Fright_val))) {
return;
}
(*_Lok_1) = true;
}
inline void _NCp1_NExprI_Pprocess_compare_2(struct _NCp1_NExpr* _Lexpr_0, bool* _Lok_1) {
struct _NCp1_NExprCompare* _Le_2;
_Le_2 = _Lexpr_0;
if(!(_NCp1_NExprI_Pvalue_4((*_Le_2)._Fleft, 1, true, &(*_Le_2)._Fleft_val))) {
return;
}
_NCp1_NExprI_Ptry_deduce_2((*_Le_2)._Fright, (*_Le_2)._Fleft_val._Ftype);
if(!(_NCp1_NExprI_Pvalue_4((*_Le_2)._Fright, 1, true, &(*_Le_2)._Fright_val))) {
return;
}
(*_Lok_1) = true;
}
inline void _NCp1_NExprI_Pprocess_bool_2(struct _NCp1_NExpr* _Lexpr_0, bool* _Lok_1) {
_Ginclude_stdbool = true;
(*_Lok_1) = true;
}
inline void _NCp1_NExprI_Pprocess_char_2(struct _NCp1_NExpr* _Lexpr_0, bool* _Lok_1) {
(*_Lok_1) = true;
}
inline void _NCp1_NExprI_Pprocess_math_2(struct _NCp1_NExpr* _Lexpr_0, bool* _Lok_1) {
struct _NCp1_NExprMath* _Le_2;
_Le_2 = _Lexpr_0;
if(!(_NCp1_NExprI_Pvalue_4((*_Le_2)._Fleft, 1, true, &(*_Le_2)._Fleft_val))) {
return;
}
_NCp1_NExprI_Ptry_deduce_2((*_Le_2)._Fright, (*_Le_2)._Fleft_val._Ftype);
if(!(_NCp1_NExprI_Pvalue_4((*_Le_2)._Fright, 1, true, &(*_Le_2)._Fright_val))) {
return;
}
int32_t _Li_3;
_Li_3 = 0;
for(int i = (*_Le_2)._Fitem_c; i > 0; ) {
i --;
struct _NCp1_NExprMathItem* _Litem_4;
_Litem_4 = (&(*_Le_2)._Fitem_v[_Li_3]);
if(!(_NCp1_NExprI_Pvalue_4((*_Litem_4)._Fexpr, 1, true, &(*_Litem_4)._Fval))) {
return;
}
continue_0:;
_Li_3++;
}
break_0:;
(*_Lok_1) = true;
}
inline void _NCp1_NExprI_Pprocess_unary_2(struct _NCp1_NExpr* _Lexpr_0, bool* _Lok_1) {
struct _NCp1_NExprUnary* _Le_2;
_Le_2 = _Lexpr_0;
if(!(_NCp1_NExprI_Pvalue_4((*_Le_2)._Fexpr, 1, true, &(*_Le_2)._Fval))) {
return;
}
(*_Lok_1) = true;
}
inline void _NCp1_NExprI_Pprocess_ref_2(struct _NCp1_NExpr* _Lexpr_0, bool* _Lok_1) {
struct _NCp1_NExprRef* _Le_2;
_Le_2 = _Lexpr_0;
if(!(_NCp1_NExprI_Pvalue_4((*_Le_2)._Fexpr, 2, false, &(*_Le_2)._Fval))) {
return;
}
(*_Lok_1) = true;
}
inline void _NCp1_NExprI_Pprocess_cast_fast_2(struct _NCp1_NExpr* _Lexpr_0, bool* _Lok_1) {
struct _NCp1_NExprCastFast* _Le_2;
_Le_2 = _Lexpr_0;
if(!(_NCp1_NExprI_Pvalue_4((*_Le_2)._Fexpr, 1, false, &(*_Le_2)._Fval))) {
return;
}
(*_Le_2)._Ftype = _NCp1_Pat_validate_5((*_Le_2)._Ftype, (*_Gctx_func)._Fat, (*_Gctx_func)._Ffile, _Gctx_begin_row, _Gctx_begin_col);
_NCp1_NAt_Poutput_4((*_Le_2)._Ftype, (*_Gctx_func)._Ffile, _Gctx_begin_row, _Gctx_begin_col);
(*_Lok_1) = true;
}
inline void _NCp1_NExprI_Pprocess_lvar_2(struct _NCp1_NExpr* _Lexpr_0, bool* _Lok_1) {
struct _NCp1_NExprLvar* _Le_2;
_Le_2 = _Lexpr_0;
if(!(_NCp1_NLvar_Pprocess_1((*_Le_2)._Flvar))) {
return;
}
(*_Lok_1) = true;
}
inline void _NCp1_NExprI_Pprocess_fvar_2(struct _NCp1_NExpr* _Lexpr_0, bool* _Lok_1) {
struct _NCp1_NExprFvar* _Le_2;
_NCp1_NAt _Ltype_i_3;
struct _NCp1_NAtData* _Ltype_4;
_NCp1_NStruct _Lstruct_i_5;
struct _NCp1_NStructData* _Lstruct_6;
_NCp1_NId _Lmember_7;
_Le_2 = _Lexpr_0;
_Ltype_i_3 = _NCp1_NExprI_Ptype_1((*_Le_2)._Fexpr);
if(_Ltype_i_3 == _NCp1_NAt_Cnil) {
fprintf(stdout, "%s:%u:%u - %u:%u Cannot get member '.%s' from an expression of unknown type\n", _NCp1_NFile_Ppath_1((*_Gctx_func)._Ffile), _Gctx_begin_row, _Gctx_begin_col, _Gctx_end_row, _Gctx_end_col, _NCp1_NId_Pstr_1((*_Le_2)._Fmember));
return;
}
_Ltype_4 = _NCp1_NAt_Pptr_1(_Ltype_i_3);
if((*_Ltype_4)._Fdef != _NCp1_NAtDef_Cstruct) {
fprintf(stdout, "%s:%u:%u - %u:%u Cannot get member '.%s' because the type is not a struct or union\n", _NCp1_NFile_Ppath_1((*_Gctx_func)._Ffile), _Gctx_begin_row, _Gctx_begin_col, _Gctx_end_row, _Gctx_end_col, _NCp1_NId_Pstr_1((*_Le_2)._Fmember));
return;
}
if(!(_NCp1_NExprI_Pvalue_4((*_Le_2)._Fexpr, 1 - _NCp1_NAt_Ppointer_1(_Ltype_i_3), true, &(*_Le_2)._Fval))) {
return;
}
if((*_Le_2)._Fval._Finfo._Farray_c > 0) {
fprintf(stdout, "%s:%u:%u - %u:%u Cannot get member '.%s' because the expression is an array(%d)\n", _NCp1_NFile_Ppath_1((*_Gctx_func)._Ffile), _Gctx_begin_row, _Gctx_begin_col, _Gctx_end_row, _Gctx_end_col, _NCp1_NId_Pstr_1((*_Le_2)._Fmember), (*_Le_2)._Fval._Finfo._Farray_c);
return;
}
if((*_Ltype_4)._Fdecl._Fstruct == _NCp1_NStruct_Cnil) {
fprintf(stdout, "%s:%u:%u - %u:%u Cannot get member '.%s' because the type '/%s' was not defined\n", _NCp1_NFile_Ppath_1((*_Gctx_func)._Ffile), _Gctx_begin_row, _Gctx_begin_col, _Gctx_end_row, _Gctx_end_col, _NCp1_NId_Pstr_1((*_Le_2)._Fmember), _NCp1_NId_Pstr_1((*_Ltype_4)._Fname._Fid));
return;
}
_Lstruct_i_5 = (*_Ltype_4)._Fdecl._Fstruct;
_NCp1_NStruct_Poutput_1(_Lstruct_i_5);
_Lstruct_6 = _NCp1_NStruct_Pptr_1(_Lstruct_i_5);
_Lmember_7 = (*_Le_2)._Fmember;
_NCp1_NFvar _Li_8;
_Li_8 = (_NCp1_NFvar)(0);
for(int i = (*_Lstruct_6)._Ffvar_c; i > 0; ) {
i --;
if((*_Lstruct_6)._Ffvar_v[_Li_8]._Fdecl._Fname == _Lmember_7) {
(*_Le_2)._Ffvar = _Li_8;
(*_Lok_1) = true;
return;
}
continue_0:;
_Li_8++;
}
break_0:;
fprintf(stdout, "%s:%u:%u - %u:%u Cannot find member named '.%s' from type '/%s'\n", _NCp1_NFile_Ppath_1((*_Gctx_func)._Ffile), _Gctx_begin_row, _Gctx_begin_col, _Gctx_end_row, _Gctx_end_col, _NCp1_NId_Pstr_1((*_Le_2)._Fmember), _NCp1_NId_Pstr_1((*_Ltype_4)._Fname._Fid));
}
inline void _NCp1_NExprI_Pprocess_gvar_2(struct _NCp1_NExpr* _Lexpr_0, bool* _Lok_1) {
struct _NCp1_NExprGvar* _Le_2;
_Le_2 = _Lexpr_0;
if(!(_NCp1_NGvar_Pprocess_1((*_Le_2)._Fgvar))) {
return;
}
(*_Lok_1) = true;
}
inline void _NCp1_NExprI_Pprocess_cvar_2(struct _NCp1_NExpr* _Lexpr_0, bool* _Lok_1) {
struct _NCp1_NExprCvar* _Le_2;
_NCp1_NId _Lname_3;
int32_t _Lcvar_c_4;
_NCp1_NCvar* _Lcvar_v_5;
_NCp1_NAt _Lat_idx_9;
struct _NCp1_NAtData* _Lat_10;
bool _Ltry_parent_11;
_Le_2 = _Lexpr_0;
_Lname_3 = (*_Le_2)._Fname;
if((*_Le_2)._Ftry != _NCp1_NAt_Cnil) {
struct _NCp1_NAtData* _Lat_6;
_Lat_6 = _NCp1_NAt_Pptr_1((*_Le_2)._Ftry);
_Lcvar_c_4 = (*_Lat_6)._Fcvar_c;
_Lcvar_v_5 = (*_Lat_6)._Fcvar_v;
int32_t _Li_7;
_Li_7 = 0;
for(int i = _Lcvar_c_4; i > 0; ) {
i --;
_NCp1_NCvar _Lcvar_8;
_Lcvar_8 = _Lcvar_v_5[_Li_7];
if((*_NCp1_NCvar_Pptr_1(_Lcvar_8))._Fdecl._Fname == _Lname_3) {
if(!(_NCp1_NCvar_Pprocess_1(_Lcvar_8))) {
return;
}
(*_Le_2)._Fcvar = _Lcvar_8;
(*_Lok_1) = true;
return;
}
continue_0:;
_Li_7++;
}
break_0:;
}
_Ltry_parent_11 = false;
if((*_Le_2)._Fat != _NCp1_NAt_Cnil) {
(*_Le_2)._Fat = _NCp1_Pat_validate_5((*_Le_2)._Fat, (*_Gctx_func)._Fat, (*_Gctx_func)._Ffile, _Gctx_begin_row, _Gctx_begin_col);
_Lat_idx_9 = (*_Le_2)._Fat;
_Lat_10 = _NCp1_NAt_Pptr_1(_Lat_idx_9);
_Lcvar_c_4 = (*_Lat_10)._Fcvar_c;
_Lcvar_v_5 = (*_Lat_10)._Fcvar_v;
} else {
_Lat_idx_9 = (*_Gctx_func)._Fat;
_Lat_10 = _NCp1_NAt_Pptr_1(_Lat_idx_9);
_Lcvar_c_4 = (*_Lat_10)._Fcvar_c;
_Lcvar_v_5 = (*_Lat_10)._Fcvar_v;
_Ltry_parent_11 = true;
}
while(1) {
int32_t _Li_12;
_Li_12 = 0;
for(int i = _Lcvar_c_4; i > 0; ) {
i --;
_NCp1_NCvar _Lcvar_13;
_Lcvar_13 = _Lcvar_v_5[_Li_12];
if((*_NCp1_NCvar_Pptr_1(_Lcvar_13))._Fdecl._Fname == _Lname_3) {
if(!(_NCp1_NCvar_Pprocess_1(_Lcvar_13))) {
return;
}
(*_Le_2)._Fcvar = _Lcvar_13;
(*_Lok_1) = true;
return;
}
continue_2:;
_Li_12++;
}
break_2:;
if(!(_Ltry_parent_11)) {
goto break_1;
}
if(_Lat_idx_9 == _NCp1_NAt_Croot) {
goto break_1;
}
_Lat_idx_9 = (*_Lat_10)._Fparent;
_Lat_10 = _NCp1_NAt_Pptr_1(_Lat_idx_9);
_Lcvar_c_4 = (*_Lat_10)._Fcvar_c;
_Lcvar_v_5 = (*_Lat_10)._Fcvar_v;
continue_1:;
}
break_1:;
fprintf(stdout, "%s:%u:%u - %u:%u: Cannot find #%s\n", _NCp1_NFile_Ppath_1((*_Gctx_func)._Ffile), _Gctx_begin_row, _Gctx_begin_col, _Gctx_end_row, _Gctx_end_col, _NCp1_NId_Pstr_1(_Lname_3));
}
inline void _NCp1_NExprI_Pprocess_bools_2(struct _NCp1_NExpr* _Lexpr_0, bool* _Lok_1) {
struct _NCp1_NExprBools* _Le_2;
_Le_2 = _Lexpr_0;
if(!(_NCp1_NExprI_Pvalue_4((*_Le_2)._Fleft, 1, true, &(*_Le_2)._Fleft_val))) {
return;
}
if(!(_NCp1_NExprI_Pvalue_4((*_Le_2)._Fright, 1, true, &(*_Le_2)._Fright_val))) {
return;
}
int32_t _Li_3;
_Li_3 = 0;
for(int i = (*_Le_2)._Fitem_c; i > 0; ) {
i --;
struct _NCp1_NExprBoolsItem* _Litem_4;
_Litem_4 = (&(*_Le_2)._Fitem_v[_Li_3]);
if(!(_NCp1_NExprI_Pvalue_4((*_Litem_4)._Fexpr, 1, true, &(*_Litem_4)._Fval))) {
return;
}
continue_0:;
_Li_3++;
}
break_0:;
(*_Lok_1) = true;
}
inline void _NCp1_NExprI_Pprocess_method_2(struct _NCp1_NExpr* _Lexpr_0, bool* _Lok_1) {
struct _NCp1_NExprMethod* _Le_2;
_NCp1_NId _Lfunc_name_3;
uint8_t _Lgroup_c_4;
uint8_t* _Lgroup_v_5;
uint8_t _Lcarg_c_6;
uint8_t _Lcarg_c1_7;
_NCp1_NAt _Lat_idx_8;
struct _NCp1_NAtData* _Lat_9;
int32_t _Lmethod_c_10;
_NCp1_NFunc* _Lmethod_v_11;
int32_t _Lfound_15;
int32_t _Lsimilar_c_16;
_Le_2 = _Lexpr_0;
_Lfunc_name_3 = (*_Le_2)._Ffunc_name;
_Lgroup_c_4 = (*_Le_2)._Fgroup_c;
_Lgroup_v_5 = (*_Le_2)._Fgroup_v;
_Lcarg_c_6 = (*_Le_2)._Fcarg_c;
_Lcarg_c1_7 = (_Lcarg_c_6 + 1);
_Lat_idx_8 = _NCp1_NExprI_Ptype_1((*_Le_2)._Fthiss);
if(_Lat_idx_8 == _NCp1_NAt_Cnil) {
fprintf(stdout, "%s:%u:%u - %u:%u: Cannot call method %s on a value without a type\n", _NCp1_NFile_Ppath_1((*_Gctx_func)._Ffile), _Gctx_begin_row, _Gctx_begin_col, _Gctx_end_row, _Gctx_end_col, _NCp1_NId_Pstr_1(_Lfunc_name_3));
return;
}
_Lat_9 = _NCp1_NAt_Pptr_1(_Lat_idx_8);
if((*_Lat_9)._Ftype == _NCp1_NNameType_Cbasic) {
struct _NCp1_NBasicType* _Lt_12;
_Lt_12 = (&_Gbasic_type[(*_Lat_9)._Fname._Fbasic]);
_Lmethod_c_10 = (*_Lt_12)._Fmethod_c;
_Lmethod_v_11 = (*_Lt_12)._Fmethod_v;
} else {
if((((*_Lat_9)._Fdecl._Fstruct == _NCp1_NStruct_Cnil) && ((*_Lat_9)._Ftype != _NCp1_NNameType_Cbasic) && ((*_Lat_9)._Ftype != _NCp1_NNameType_Cmodule))) {
fprintf(stdout, "%s:%u:%u - %u:%u: Cannot call method %s because the type :%s is not defined\n", _NCp1_NFile_Ppath_1((*_Gctx_func)._Ffile), _Gctx_begin_row, _Gctx_begin_col, _Gctx_end_row, _Gctx_end_col, _NCp1_NId_Pstr_1(_Lfunc_name_3), _NCp1_NId_Pstr_1((*_Lat_9)._Fname._Fid));
return;
}
if((*_Lat_9)._Fdef == _NCp1_NAtDef_Cstruct) {
struct _NCp1_NStructData* _Lt_13;
_Lt_13 = _NCp1_NStruct_Pptr_1((*_Lat_9)._Fdecl._Fstruct);
_Lmethod_c_10 = (*_Lt_13)._Fmethod_c;
_Lmethod_v_11 = (*_Lt_13)._Fmethod_v;
} else if((*_Lat_9)._Fdef == _NCp1_NAtDef_Cenum) {
struct _NCp1_NEnumData* _Lt_14;
_Lt_14 = _NCp1_NEnum_Pptr_1((*_Lat_9)._Fdecl._Fenum);
_Lmethod_c_10 = (*_Lt_14)._Fmethod_c;
_Lmethod_v_11 = (*_Lt_14)._Fmethod_v;
}
}
_Lfound_15 = -1;
_Lsimilar_c_16 = 0;
int32_t _Li_17;
_Li_17 = 0;
for(int i = _Lmethod_c_10; i > 0; ) {
i --;
_NCp1_NFunc _Lf_idx_18;
struct _NCp1_NDeclFunc* _Lf_19;
bool _Lmatch_20;
_NCp1_NAt _Lf_at_24;
int32_t _Lj_25;
int32_t _Lk_26;
_Lf_idx_18 = _Lmethod_v_11[_Li_17];
_Lf_19 = _NCp1_NFunc_Pptr_1(_Lf_idx_18);
if((*_Lf_19)._Fdecl._Fname != _Lfunc_name_3) {
goto continue_0;
}
_Lfound_15 = _Li_17;
_Lsimilar_c_16++;
if((*_Lf_19)._Fgroup_c != _Lgroup_c_4) {
goto continue_0;
}
_Lmatch_20 = true;
if(((*_Lf_19)._Fflags & _NCp1_NFuncFlags_Cvar_args) != _NCp1_NFuncFlags_C0) {
if((*_Lf_19)._Ffarg_c > _Lcarg_c1_7) {
goto continue_0;
}
int32_t _Lj_21;
_Lj_21 = 0;
for(int i = _Lgroup_c_4 - 1; i > 0; ) {
i --;
if((*_Lf_19)._Fthis_group == _Lj_21) {
if((*_Lf_19)._Fgroup_v[_Lj_21] != (_Lgroup_v_5[_Lj_21] + 1)) {
_Lmatch_20 = false;
goto break_1;
}
} else {
if((*_Lf_19)._Fgroup_v[_Lj_21] != _Lgroup_v_5[_Lj_21]) {
_Lmatch_20 = false;
goto break_1;
}
}
continue_1:;
_Lj_21++;
}
break_1:;
if(_Lmatch_20) {
uint8_t _Lj_22;
_Lj_22 = (_Lgroup_c_4 - 1);
if((*_Lf_19)._Fthis_group == _Lj_22) {
if((*_Lf_19)._Fgroup_v[_Lj_22] > (_Lgroup_v_5[_Lj_22] + 1)) {
_Lmatch_20 = false;
}
} else {
if((*_Lf_19)._Fgroup_v[_Lj_22] > _Lgroup_v_5[_Lj_22]) {
_Lmatch_20 = false;
}
}
}
} else {
if((*_Lf_19)._Ffarg_c != _Lcarg_c1_7) {
goto continue_0;
}
int32_t _Lj_23;
_Lj_23 = 0;
for(int i = _Lgroup_c_4; i > 0; ) {
i --;
if((*_Lf_19)._Fthis_group == _Lj_23) {
if((*_Lf_19)._Fgroup_v[_Lj_23] != (_Lgroup_v_5[_Lj_23] + 1)) {
_Lmatch_20 = false;
goto break_2;
}
} else {
if((*_Lf_19)._Fgroup_v[_Lj_23] != _Lgroup_v_5[_Lj_23]) {
_Lmatch_20 = false;
goto break_2;
}
}
continue_2:;
_Lj_23++;
}
break_2:;
}
if(!(_Lmatch_20)) {
goto continue_0;
}
_NCp1_NFunc_Pprocess_later_1(_Lf_idx_18);
_Lf_at_24 = (*_Lf_19)._Fat;
_Lj_25 = 0;
_Lk_26 = 0;
for(int i = (*_Lf_19)._Fthis_idx; i > 0; ) {
i --;
struct _NCp1_NCarg* _Lca_27;
_Lca_27 = (&(*_Le_2)._Fcarg_v[_Lk_26]);
if(!(_NCp1_Pfarg_process_5((*_Lca_27)._Fexpr, (*_Lca_27)._Freff, &(*_Lca_27)._Fvalue, &(*_Lf_19)._Ffarg_v[_Lj_25]._Fdecl, _Lf_at_24))) {
return;
}
continue_3:;
_Lj_25++;
_Lk_26++;
}
break_3:;
if(!(_NCp1_Pfarg_process_5((*_Le_2)._Fthiss, 0, &(*_Le_2)._Fthis_value, &(*_Lf_19)._Ffarg_v[_Lj_25++]._Fdecl, _Lf_at_24))) {
return;
}
for(int i = ((*_Lf_19)._Ffarg_c - 1) - (*_Lf_19)._Fthis_idx; i > 0; ) {
i --;
struct _NCp1_NCarg* _Lca_28;
_Lca_28 = (&(*_Le_2)._Fcarg_v[_Lk_26]);
if(!(_NCp1_Pfarg_process_5((*_Lca_28)._Fexpr, (*_Lca_28)._Freff, &(*_Lca_28)._Fvalue, &(*_Lf_19)._Ffarg_v[_Lj_25]._Fdecl, _Lf_at_24))) {
return;
}
continue_4:;
_Lj_25++;
_Lk_26++;
}
break_4:;
(*_Le_2)._Ffunc_idx = _Lf_idx_18;
if(((*_Lf_19)._Fflags & _NCp1_NFuncFlags_Cvar_args) != _NCp1_NFuncFlags_C0) {
for(int i = (*_Le_2)._Fcarg_c - _Lk_26; i > 0; ) {
i --;
struct _NCp1_NCarg* _Lca_29;
int32_t _Lr_30;
_Lca_29 = (&(*_Le_2)._Fcarg_v[_Lk_26]);
if((*_Lca_29)._Freff) {
_Lr_30 = (1 + (*_Lca_29)._Freff);
} else {
_Lr_30 = 1;
}
if(!(_NCp1_NExprI_Pvalue_4((*_Lca_29)._Fexpr, _Lr_30, false, &(*_Lca_29)._Fvalue))) {
return;
}
continue_5:;
_Lk_26++;
}
break_5:;
}
(*_Lok_1) = true;
return;
continue_0:;
_Li_17++;
}
break_0:;
fprintf(stdout, "%s:%u:%u - %u:%u: Cannot find method %s with %u argument:S\n", _NCp1_NFile_Ppath_1((*_Gctx_func)._Ffile), _Gctx_begin_row, _Gctx_begin_col, _Gctx_end_row, _Gctx_end_col, _NCp1_NId_Pstr_1(_Lfunc_name_3), _Lcarg_c_6);
if(_Lfound_15 != -1) {
fprintf(stdout, "But found %u functions with different no. of argument:S:\n", _Lsimilar_c_16);
int32_t _Li_31;
_Li_31 = 0;
for(int i = (*_Lat_9)._Ffunc_c; i > 0; ) {
i --;
_NCp1_NFunc _Lf_idx_32;
struct _NCp1_NDeclFunc* _Lf_33;
_Lf_idx_32 = (*_Lat_9)._Ffunc_v[_Li_31];
_Lf_33 = _Gfunc_v[_Lf_idx_32];
if((*_Lf_33)._Fdecl._Fname == _Lfunc_name_3) {
fprintf(stdout, "- :%s with %u args\n", _NCp1_NId_Pstr_1(_Lfunc_name_3), (*_Lf_33)._Ffarg_c);
}
continue_6:;
_Li_31++;
}
break_6:;
}
}
inline void _NCp1_NExprI_Pprocess_func_2(struct _NCp1_NExpr* _Lexpr_0, bool* _Lok_1) {
struct _NCp1_NExprFunc* _Le_2;
_NCp1_NId _Lfunc_name_3;
uint8_t _Lcarg_c_4;
uint8_t _Lgroup_c_5;
uint8_t* _Lgroup_v_6;
_NCp1_NAt _Lat_idx_7;
bool _Ltry_parent_8;
_Le_2 = _Lexpr_0;
_Lfunc_name_3 = (*_Le_2)._Ffunc_name;
_Lcarg_c_4 = (*_Le_2)._Fcarg_c;
_Lgroup_c_5 = (*_Le_2)._Fgroup_c;
_Lgroup_v_6 = (*_Le_2)._Fgroup_v;
_Lat_idx_7 = (*_Le_2)._Fat;
_Ltry_parent_8 = false;
if(_Lat_idx_7 == _NCp1_NAt_Cnil) {
_Lat_idx_7 = (*_Gctx_func)._Fat;
_Ltry_parent_8 = true;
} else {
_Lat_idx_7 = _NCp1_Pat_validate_5(_Lat_idx_7, (*_Gctx_func)._Fat, (*_Gctx_func)._Ffile, _Gctx_begin_row, _Gctx_begin_col);
(*_Le_2)._Fat = _Lat_idx_7;
}
while(1) {
struct _NCp1_NAtData* _Lat_9;
_Lat_9 = _NCp1_NAt_Pptr_1(_Lat_idx_7);
int32_t _Li_10;
_Li_10 = 0;
for(int i = (*_Lat_9)._Ffunc_c; i > 0; ) {
i --;
_NCp1_NFunc _Lf_idx_11;
struct _NCp1_NDeclFunc* _Lf_12;
bool _Lmatch_13;
_NCp1_NAt _Lf_at_17;
int32_t _Lj_18;
_Lf_idx_11 = (*_Lat_9)._Ffunc_v[_Li_10];
_Lf_12 = _NCp1_NFunc_Pptr_1(_Lf_idx_11);
if((*_Lf_12)._Fdecl._Fname != _Lfunc_name_3) {
goto continue_1;
}
if((*_Lf_12)._Fgroup_c != _Lgroup_c_5) {
goto continue_1;
}
_Lmatch_13 = true;
if(((*_Lf_12)._Fflags & _NCp1_NFuncFlags_Cvar_args) != _NCp1_NFuncFlags_C0) {
if((*_Lf_12)._Ffarg_c > _Lcarg_c_4) {
goto continue_1;
}
int32_t _Lj_14;
_Lj_14 = 0;
for(int i = _Lgroup_c_5 - 1; i > 0; ) {
i --;
if((*_Lf_12)._Fgroup_v[_Lj_14] != _Lgroup_v_6[_Lj_14]) {
_Lmatch_13 = false;
goto break_2;
}
continue_2:;
_Lj_14++;
}
break_2:;
if(_Lmatch_13) {
uint8_t _Lj_15;
_Lj_15 = (_Lgroup_c_5 - 1);
if((*_Lf_12)._Fgroup_v[_Lj_15] > _Lgroup_v_6[_Lj_15]) {
_Lmatch_13 = false;
}
}
} else {
if((*_Lf_12)._Ffarg_c != _Lcarg_c_4) {
goto continue_1;
}
int32_t _Lj_16;
_Lj_16 = 0;
for(int i = _Lgroup_c_5; i > 0; ) {
i --;
if((*_Lf_12)._Fgroup_v[_Lj_16] != _Lgroup_v_6[_Lj_16]) {
_Lmatch_13 = false;
goto break_3;
}
continue_3:;
_Lj_16++;
}
break_3:;
}
if(!(_Lmatch_13)) {
goto continue_1;
}
_NCp1_NFunc_Pprocess_later_1(_Lf_idx_11);
_Lf_at_17 = (*_Lf_12)._Fat;
_Lj_18 = 0;
for(int i = (*_Lf_12)._Ffarg_c; i > 0; ) {
i --;
struct _NCp1_NCarg* _Lca_19;
_Lca_19 = (&(*_Le_2)._Fcarg_v[_Lj_18]);
if(!(_NCp1_Pfarg_process_5((*_Lca_19)._Fexpr, (*_Lca_19)._Freff, &(*_Lca_19)._Fvalue, &(*_Lf_12)._Ffarg_v[_Lj_18]._Fdecl, _Lf_at_17))) {
return;
}
continue_4:;
_Lj_18++;
}
break_4:;
(*_Le_2)._Ffunc_idx = _Lf_idx_11;
if(((*_Lf_12)._Fflags & _NCp1_NFuncFlags_Cvar_args) != _NCp1_NFuncFlags_C0) {
for(int i = (*_Le_2)._Fcarg_c - _Lj_18; i > 0; ) {
i --;
struct _NCp1_NCarg* _Lca_20;
int32_t _Lr_21;
_Lca_20 = (&(*_Le_2)._Fcarg_v[_Lj_18]);
if((*_Lca_20)._Freff) {
_Lr_21 = (1 + (*_Lca_20)._Freff);
} else {
_Lr_21 = 1;
}
if(!(_NCp1_NExprI_Pvalue_4((*_Lca_20)._Fexpr, _Lr_21, false, &(*_Lca_20)._Fvalue))) {
return;
}
continue_5:;
_Lj_18++;
}
break_5:;
}
(*_Le_2)._Ffunc_idx = _Lf_idx_11;
(*_Lok_1) = true;
return;
continue_1:;
_Li_10++;
}
break_1:;
if(!(_Ltry_parent_8)) {
goto break_0;
}
if(_Lat_idx_7 == _NCp1_NAt_Croot) {
goto break_0;
}
_Lat_idx_7 = (*_Lat_9)._Fparent;
continue_0:;
}
break_0:;
fprintf(stdout, "%s:%u:%u - %u:%u: Cannot find function %s with %u argument:S\n", _NCp1_NFile_Ppath_1((*_Gctx_func)._Ffile), _Gctx_begin_row, _Gctx_begin_col, _Gctx_end_row, _Gctx_end_col, _NCp1_NId_Pstr_1(_Lfunc_name_3), _Lcarg_c_4);
}
inline void _NCp1_NExprI_Pprocess_str_2(struct _NCp1_NExpr* _Lexpr_0, bool* _Lok_1) {
(*_Lok_1) = true;
}
inline void _NCp1_NExprI_Pprocess_i32_2(struct _NCp1_NExpr* _Lexpr_0, bool* _Lok_1) {
(*_Lok_1) = true;
}
inline void _NCp1_NExprI_Pprocess_size_of_type_2(struct _NCp1_NExpr* _Lexpr_0, bool* _Lok_1) {
struct _NCp1_NExprSizeOfType* _Le_2;
_Le_2 = _Lexpr_0;
(*_Le_2)._Ftype = _NCp1_Pat_validate_5((*_Le_2)._Ftype, (*_Gctx_func)._Fat, (*_Gctx_func)._Ffile, _Gctx_begin_row, _Gctx_begin_col);
_NCp1_NAt_Poutput_4((*_Le_2)._Ftype, (*_Gctx_func)._Ffile, _Gctx_begin_row, _Gctx_begin_col);
(*_Lok_1) = true;
}
inline void _NCp1_NExprI_Pprocess_null_2(struct _NCp1_NExpr* _Lexpr_0, bool* _Lok_1) {
_Ginclude_stddef = true;
(*_Lok_1) = true;
}
inline void _NCp1_NExprI_Pprocess_index_2(struct _NCp1_NExpr* _Lexpr_0, bool* _Lok_1) {
struct _NCp1_NExprIndex* _Le_2;
_Le_2 = _Lexpr_0;
if(!(_NCp1_NExprI_Pvalue_4((*_Le_2)._Fleft, 1, true, &(*_Le_2)._Fleft_val))) {
return;
}
if(!(_NCp1_NExprI_Pvalue_4((*_Le_2)._Fright, 1, true, &(*_Le_2)._Fright_val))) {
return;
}
(*_Lok_1) = true;
}
void _NCp1_NGvar_Pwrite_1(_NCp1_NGvar _Lg_0) {
struct _NCp1_NDeclGvar* _Lgvar_1;
_Lgvar_1 = _NCp1_NGvar_Pptr_1(_Lg_0);
_NCp1_NDeclVarData_Pwrite_2(&(*_Lgvar_1)._Fdecl, _NCp1_NDeclVarType_Cgvar);
}
inline void _NCp1_NExprCastFast_Pwrite_value_2(struct _NCp1_NExprCastFast* _Le_0, struct _NCp1_NValue* _Lv_1) {
fprintf(_Gout, "(");
_NCp1_NAt_Pwrite_type_info_3((*_Le_0)._Ftype, &(*_Lv_1)._Finfo, 0);
fprintf(_Gout, ")(");
_NCp1_NExprI_Pwrite_value_2((*_Le_0)._Fexpr, &(*_Le_0)._Fval);
fprintf(_Gout, ")");
}
inline int32_t _NCp1_NAt_Ppointer_1(_NCp1_NAt _Ltd_0) {
if((*_NCp1_NAt_Pptr_1(_Ltd_0))._Fdef == _NCp1_NAtDef_Cstruct) {
return 1;
} else {
return 0;
}
}
inline void _NCp1_NStmt_Pwrite_expr_1(struct _NCp1_NStmt* _Lstmt_0) {
struct _NCp1_NStmtExpr* _Ls_1;
struct _NCp1_NExpr* _Lexpr_2;
_Ls_1 = _Lstmt_0;
_Lexpr_2 = _NCp1_NExprI_Pptr_1((*_Ls_1)._Fexpr);
if((*_Lexpr_2)._Ftype == _NCp1_NExprType_Cstr) {
struct _NCp1_NExprStr* _Le_3;
struct _NCp1_NExprStrNode* _Ln_4;
_Le_3 = _Lexpr_2;
_Ln_4 = (*_Le_3)._Ffirst;
while(1) {
fprintf(_Gout, "%.*s\n", (*_Ln_4)._Flen, (*_Ln_4)._Fbuf);
_Ln_4 = (*_Ln_4)._Fnext;
if(_Ln_4 == NULL) {
goto break_0;
}
continue_0:;
}
break_0:;
return;
}
_NCp1_NExprI_Pwrite_1((*_Ls_1)._Fexpr);
fprintf(_Gout, ";\n");
}
inline void _NCp1_NStmt_Pwrite_if_1(struct _NCp1_NStmt* _Lstmt_0) {
struct _NCp1_NStmtIf* _Ls_1;
struct _NCp1_NExpr* _Le_2;
_Ls_1 = _Lstmt_0;
_Le_2 = _NCp1_NExprI_Pptr_1((*_Ls_1)._Fexpr);
if((*_Ls_1)._Fnot) {
fprintf(_Gout, "if(!(");
_NCp1_NExprI_Pwrite_value_2((*_Ls_1)._Fexpr, &(*_Ls_1)._Fval);
fprintf(_Gout, ")) {\n");
} else {
fprintf(_Gout, "if(");
_NCp1_NExprI_Pwrite_value_2((*_Ls_1)._Fexpr, &(*_Ls_1)._Fval);
fprintf(_Gout, ") {\n");
}
}
inline void _NCp1_NStmt_Pwrite_if_elif_1(struct _NCp1_NStmt* _Lstmt_0) {
struct _NCp1_NStmtIfElif* _Ls_1;
_Ls_1 = _Lstmt_0;
if((*_Ls_1)._Fnot) {
fprintf(_Gout, "} else if(!(");
_NCp1_NExprI_Pwrite_value_2((*_Ls_1)._Fexpr, &(*_Ls_1)._Fval);
fprintf(_Gout, ")) {\n");
} else {
fprintf(_Gout, "} else if(");
_NCp1_NExprI_Pwrite_value_2((*_Ls_1)._Fexpr, &(*_Ls_1)._Fval);
fprintf(_Gout, ") {\n");
}
}
inline void _NCp1_NStmt_Pwrite_if_else_1(struct _NCp1_NStmt* _Lstmt_0) {
struct _NCp1_NStmtIfElse* _Ls_1;
_Ls_1 = _Lstmt_0;
fprintf(_Gout, "} else {\n");
}
inline void _NCp1_NStmt_Pwrite_if_end_1(struct _NCp1_NStmt* _Lstmt_0) {
struct _NCp1_NStmtIfEnd* _Ls_1;
_Ls_1 = _Lstmt_0;
fprintf(_Gout, "}\n");
}
inline void _NCp1_NStmt_Pwrite_switch_1(struct _NCp1_NStmt* _Lstmt_0) {
struct _NCp1_NStmtSwitch* _Ls_1;
_Ls_1 = _Lstmt_0;
fprintf(_Gout, "switch(");
_NCp1_NExprI_Pwrite_value_2((*_Ls_1)._Fexpr, &(*_Ls_1)._Fval);
fprintf(_Gout, ") {\n");
if((*_Ls_1)._Fcase_func_c > 0) {
struct _NCp1_NExpr* _Le_2;
struct _NCp1_NExprFunc* _Lfunc_3;
struct _NCp1_NStmtSwitchCaseFunc* _Lv_4;
_Le_2 = _NCp1_NExprI_Pptr_1((*_Ls_1)._Fcases);
_Lfunc_3 = _Le_2;
_Lv_4 = (*_Ls_1)._Fcase_func_v;
int32_t _Li_5;
_Li_5 = 0;
for(int i = (*_Ls_1)._Fcase_func_c; i > 0; ) {
i --;
fprintf(_Gout, "case ");
_NCp1_NCvar_Pwrite_1(_Lv_4[_Li_5]._Fcvar);
fprintf(_Gout, ":;\n");
(*_Lfunc_3)._Ffunc_idx = _Lv_4[_Li_5]._Ffunc;
_NCp1_NExprI_Pwrite_func_1(_Le_2);
fprintf(_Gout, ";\nbreak;\n");
continue_0:;
_Li_5++;
}
break_0:;
}
}
inline void _NCp1_NStmt_Pwrite_case_1(struct _NCp1_NStmt* _Lstmt_0) {
struct _NCp1_NStmtCase* _Ls_1;
_Ls_1 = _Lstmt_0;
int32_t _Li_2;
_Li_2 = 0;
for(int i = (*_Ls_1)._Fexpr_c; i > 0; ) {
i --;
fprintf(_Gout, "case ");
_NCp1_NExprI_Pwrite_value_2((*_Ls_1)._Fexpr_v[_Li_2]._Fexpr, &(*_Ls_1)._Fexpr_v[_Li_2]._Fval);
fprintf(_Gout, ":;\n");
continue_0:;
_Li_2++;
}
break_0:;
_Gcase_stack_v[_Gcase_stack_c++]._Fcas = _Ls_1;
}
inline void _NCp1_NStmt_Pwrite_case_end_1(struct _NCp1_NStmt* _Lstmt_0) {
struct _NCp1_NStmtCaseEnd* _Ls_1;
struct _NCp1_NStmtCase* _Lcas_2;
_Ls_1 = _Lstmt_0;
_Lcas_2 = _Gcase_stack_v[(_Gcase_stack_c -= 1)]._Fcas;
if(!((*_Lcas_2)._Ffall_through)) {
fprintf(_Gout, "break;\n");
}
}
inline void _NCp1_NStmt_Pwrite_default_1(struct _NCp1_NStmt* _Lstmt_0) {
struct _NCp1_NStmtDefault* _Ls_1;
_Ls_1 = _Lstmt_0;
fprintf(_Gout, "default:;\n");
_Gcase_stack_v[_Gcase_stack_c++]._Fdefaul = _Ls_1;
}
inline void _NCp1_NStmt_Pwrite_default_end_1(struct _NCp1_NStmt* _Lstmt_0) {
struct _NCp1_NStmtDefaultEnd* _Ls_1;
struct _NCp1_NStmtDefault* _Ldefaul_2;
_Ls_1 = _Lstmt_0;
_Ldefaul_2 = _Gcase_stack_v[(_Gcase_stack_c -= 1)]._Fdefaul;
if(!((*_Ldefaul_2)._Ffall_through)) {
fprintf(_Gout, "break;\n");
}
}
inline void _NCp1_NStmt_Pwrite_switch_end_1(struct _NCp1_NStmt* _Lstmt_0) {
struct _NCp1_NStmtSwitchEnd* _Ls_1;
_Ls_1 = _Lstmt_0;
fprintf(_Gout, "}\n");
}
inline void _NCp1_NStmt_Pwrite_do_1(struct _NCp1_NStmt* _Lstmt_0) {
struct _NCp1_NStmtDo* _Ls_1;
_Ls_1 = _Lstmt_0;
_Gnest_stack_id_v[_Gnest_stack_c] = _Gnest_id++;
_Gnest_stack_ptr_v[_Gnest_stack_c]._Fdo = _Ls_1;
_Gnest_stack_c++;
if((*_Ls_1)._Fexpr == _NCp1_NExprI_Cnil) {
fprintf(_Gout, "while(1) {\n");
} else {
fprintf(_Gout, "for(int i = ");
_NCp1_NExprI_Pwrite_1((*_Ls_1)._Fexpr);
fprintf(_Gout, "; i > 0; ) {\ni --;\n");
}
}
inline void _NCp1_NStmt_Pwrite_do_end_1(struct _NCp1_NStmt* _Lstmt_0) {
int32_t _Lid_1;
struct _NCp1_NStmtDoEnd* _Ls_2;
struct _NCp1_NStmtSpace* _Lcontinu_3;
_Lid_1 = _Gnest_stack_id_v[(_Gnest_stack_c -= 1)];
_Ls_2 = _Lstmt_0;
fprintf(_Gout, "continue_%u:;\n", _Lid_1);
_Lcontinu_3 = (*(*_Ls_2)._Fdo)._Fcontinu;
if(_Lcontinu_3 != NULL) {
_NCp1_NStmtSpace_Pwrite_1(_Lcontinu_3);
}
fprintf(_Gout, "}\nbreak_%u:;\n", _Lid_1);
}
inline void _NCp1_NStmt_Pwrite_while_1(struct _NCp1_NStmt* _Lstmt_0) {
struct _NCp1_NStmtWhile* _Ls_1;
_Ls_1 = _Lstmt_0;
_Gnest_stack_id_v[_Gnest_stack_c] = _Gnest_id++;
_Gnest_stack_ptr_v[_Gnest_stack_c]._Fwhil = _Ls_1;
_Gnest_stack_c++;
fprintf(_Gout, "while(");
_NCp1_NExprI_Pwrite_1((*_Ls_1)._Fexpr);
fprintf(_Gout, ") {\n");
}
inline void _NCp1_NStmt_Pwrite_while_end_1(struct _NCp1_NStmt* _Lstmt_0) {
int32_t _Lid_1;
struct _NCp1_NStmtWhileEnd* _Ls_2;
struct _NCp1_NStmtSpace* _Lcontinu_3;
_Lid_1 = _Gnest_stack_id_v[(_Gnest_stack_c -= 1)];
_Ls_2 = _Lstmt_0;
fprintf(_Gout, "continue_%u:;\n", _Lid_1);
_Lcontinu_3 = (*(*_Ls_2)._Fwhil)._Fcontinu;
if(_Lcontinu_3 != NULL) {
_NCp1_NStmtSpace_Pwrite_1(_Lcontinu_3);
}
fprintf(_Gout, "}\nbreak_%u:;\n", _Lid_1);
}
inline void _NCp1_NStmt_Pwrite_continue_1(struct _NCp1_NStmt* _Lstmt_0) {
struct _NCp1_NStmtContinue* _Ls_1;
_Ls_1 = _Lstmt_0;
fprintf(_Gout, "goto continue_%u;\n", _Gnest_stack_id_v[(*_Ls_1)._Fnest]);
}
inline void _NCp1_NStmt_Pwrite_break_1(struct _NCp1_NStmt* _Lstmt_0) {
struct _NCp1_NStmtBreak* _Ls_1;
_Ls_1 = _Lstmt_0;
fprintf(_Gout, "goto break_%u;\n", _Gnest_stack_id_v[(*_Ls_1)._Fnest]);
}
inline void _NCp1_NStmt_Pwrite_return_1(struct _NCp1_NStmt* _Lstmt_0) {
struct _NCp1_NStmtReturn* _Ls_1;
_Ls_1 = _Lstmt_0;
if((*_Ls_1)._Fexpr == _NCp1_NExprI_Cnil) {
fprintf(_Gout, "return;\n");
} else {
fprintf(_Gout, "return ");
_NCp1_NExprI_Pwrite_value_2((*_Ls_1)._Fexpr, &(*_Ls_1)._Fval);
fprintf(_Gout, ";\n");
}
}
inline void _NCp1_NStmt_Pwrite_space_1(struct _NCp1_NStmt* _Lstmt_0) {
struct _NCp1_NStmtSpace* _Lspace_1;
_Lspace_1 = _Lstmt_0;
_NCp1_NStmtSpace_Pwrite_1(_Lspace_1);
}
inline void _NCp1_NExprI_Pset_3(_NCp1_NExprI _Le_0, struct _NCp1_NExpr* _Lexpr_1, _NCp1_NExprType _Ltype_2) {
_Gexpr_v[_Le_0] = _Lexpr_1;
(*_Lexpr_1)._Ftype = _Ltype_2;
}
inline void _NCp1_NAssign_Prd_2(_NCp1_NAssign* _Ls_0, union _NCp1_NRdr* _Lr_1) {
(*_Ls_0) = (_NCp1_NAssign)(_NCp1_NRdr_Pn1_1(_Lr_1));
}
inline void _NCp1_NCompare_Prd_2(_NCp1_NCompare* _Le_0, union _NCp1_NRdr* _Lr_1) {
(*_Le_0) = (_NCp1_NCompare)(_NCp1_NRdr_Pn1_1(_Lr_1));
}
inline bool _NCp1_NRdr_Pb_1(union _NCp1_NRdr* _Lr_0) {
return _NCp1_NRdr_Pn1_1(_Lr_0) != 0;
}
inline void _NCp1_NMath_Prd_2(_NCp1_NMath* _Le_0, union _NCp1_NRdr* _Lr_1) {
(*_Le_0) = (_NCp1_NMath)(_NCp1_NRdr_Pn1_1(_Lr_1));
}
inline void _NCp1_NUnary_Prd_2(_NCp1_NUnary* _Lu_0, union _NCp1_NRdr* _Lr_1) {
(*_Lu_0) = (_NCp1_NUnary)(_NCp1_NRdr_Pn1_1(_Lr_1));
}
inline void _NCp1_NBools_Prd_2(_NCp1_NBools* _Le_0, union _NCp1_NRdr* _Lr_1) {
(*_Le_0) = (_NCp1_NBools)(_NCp1_NRdr_Pn1_1(_Lr_1));
}
inline void _NCp1_NRdr_Pcopy_3(union _NCp1_NRdr* _Lr_0, void* _Ldata_1, int32_t _Lsize_2) {
memcpy(_Ldata_1, (*_Lr_0)._Freff, _Lsize_2);
(*_Lr_0)._Fpos += _Lsize_2;
}
inline void _NCp1_NStmtSpace_Pstmt_push_7(struct _NCp1_NStmtSpace* _Ls_0, struct _NCp1_NStmt* _Ls2_1, int32_t _Lbegin_row_2, int32_t _Lbegin_col_3, int32_t _Lend_row_4, int32_t _Lend_col_5, _NCp1_NStmtType _Ltype_6) {
(*_Ls2_1)._Fbegin_row = _Lbegin_row_2;
(*_Ls2_1)._Fbegin_col = _Lbegin_col_3;
(*_Ls2_1)._Fend_row = _Lend_row_4;
(*_Ls2_1)._Fend_col = _Lend_col_5;
(*_Ls2_1)._Ftype = _Ltype_6;
(*_Ls2_1)._Fstmt_next = NULL;
if((*_Ls_0)._Fstmt_last == NULL) {
(*_Ls_0)._Fstmt_first = _Ls2_1;
(*_Ls_0)._Fstmt_last = _Ls2_1;
} else {
(*(*_Ls_0)._Fstmt_last)._Fstmt_next = _Ls2_1;
(*_Ls_0)._Fstmt_last = _Ls2_1;
}
}
inline bool _NCp1_NExprI_Pprocess_case_func_2(struct _NCp1_NExpr* _Lexpr_0, _NCp1_NFunc _Lf_idx_1) {
struct _NCp1_NExprFunc* _Le_2;
_NCp1_NId _Lfunc_name_3;
uint8_t _Lcarg_c_4;
uint8_t _Lgroup_c_5;
uint8_t* _Lgroup_v_6;
struct _NCp1_NAtData* _Lat_7;
struct _NCp1_NDeclFunc* _Lf_8;
_NCp1_NAt _Lf_at_9;
int32_t _Lj_10;
_Le_2 = _Lexpr_0;
_Lfunc_name_3 = (*_Le_2)._Ffunc_name;
_Lcarg_c_4 = (*_Le_2)._Fcarg_c;
_Lgroup_c_5 = (*_Le_2)._Fgroup_c;
_Lgroup_v_6 = (*_Le_2)._Fgroup_v;
_Lat_7 = _NCp1_NAt_Pptr_1((*_Gctx_func)._Fat);
_NCp1_NFunc_Pprocess_later_1(_Lf_idx_1);
_Lf_8 = _NCp1_NFunc_Pptr_1(_Lf_idx_1);
_Lf_at_9 = (*_Lf_8)._Fat;
_Lj_10 = 0;
for(int i = (*_Lf_8)._Ffarg_c; i > 0; ) {
i --;
struct _NCp1_NCarg* _Lca_11;
_Lca_11 = (&(*_Le_2)._Fcarg_v[_Lj_10]);
if(!(_NCp1_Pfarg_process_5((*_Lca_11)._Fexpr, (*_Lca_11)._Freff, &(*_Lca_11)._Fvalue, &(*_Lf_8)._Ffarg_v[_Lj_10]._Fdecl, _Lf_at_9))) {
return false;
}
continue_0:;
_Lj_10++;
}
break_0:;
(*_Le_2)._Ffunc_idx = _Lf_idx_1;
if(((*_Lf_8)._Fflags & _NCp1_NFuncFlags_Cvar_args) != _NCp1_NFuncFlags_C0) {
for(int i = (*_Le_2)._Fcarg_c - _Lj_10; i > 0; ) {
i --;
struct _NCp1_NCarg* _Lca_12;
int32_t _Lr_13;
_Lca_12 = (&(*_Le_2)._Fcarg_v[_Lj_10]);
if((*_Lca_12)._Freff) {
_Lr_13 = (1 + (*_Lca_12)._Freff);
} else {
_Lr_13 = 1;
}
if(!(_NCp1_NExprI_Pvalue_4((*_Lca_12)._Fexpr, _Lr_13, false, &(*_Lca_12)._Fvalue))) {
return false;
}
continue_1:;
_Lj_10++;
}
break_1:;
}
(*_Le_2)._Ffunc_idx = _Lf_idx_1;
return true;
}
inline uint8_t _NCp1_NId_Plen_1(_NCp1_NId _Lid_0) {
return _Gid_len_v[_Lid_0];
}
bool _NCp1_NStmtSpace_Pprocess_1(struct _NCp1_NStmtSpace* _Lspace_0) {
struct _NCp1_NStmt* _Ls_1;
uint8_t _Li_2;
int32_t _Llvar_c_3;
_Ls_1 = (*_Lspace_0)._Fstmt_first;
while(_Ls_1 != NULL) {
if(!(_NCp1_NStmt_Pprocess_1(_Ls_1))) {
return false;
}
_Ls_1 = (*_Ls_1)._Fstmt_next;
continue_0:;
}
break_0:;
if((*_Lspace_0)._Fparent == NULL) {
_Li_2 = (*_Gctx_func)._Ffarg_c;
_Llvar_c_3 = ((*_Lspace_0)._Flvar_c - (*_Gctx_func)._Ffarg_c);
} else {
_Li_2 = 0;
_Llvar_c_3 = (*_Lspace_0)._Flvar_c;
}
for(int i = _Llvar_c_3; i > 0; ) {
i --;
_NCp1_NLvar_Pprocess_1((*_Lspace_0)._Flvar_v[_Li_2]);
continue_1:;
_Li_2++;
}
break_1:;
return true;
}
void _NCp1_NExprI_Ptry_deduce_2(_NCp1_NExprI _Le_idx_0, _NCp1_NAt _Lat_1) {
struct _NCp1_NExpr* _Lexpr_2;
_Lexpr_2 = _NCp1_NExprI_Pptr_1(_Le_idx_0);
switch((*_Lexpr_2)._Ftype) {
case _NCp1_NExprType_Cmath:;
_NCp1_NExprI_Ptry_deduce_math_2(_Lexpr_2, _Lat_1);
break;
case _NCp1_NExprType_Ccvar:;
_NCp1_NExprI_Ptry_deduce_cvar_2(_Lexpr_2, _Lat_1);
break;
}
}
_NCp1_NAt _NCp1_NExprI_Ptype_1(_NCp1_NExprI _Le_0) {
struct _NCp1_NExpr* _Lexpr_1;
_NCp1_NAt _Lat_2;
if(!(_NCp1_NExprI_Pprocess_1(_Le_0))) {
return _NCp1_NAt_Cnil;
}
_Lexpr_1 = _NCp1_NExprI_Pptr_1(_Le_0);
_Lat_2 = _NCp1_NAt_Cnil;
switch((*_Lexpr_1)._Ftype) {
case _NCp1_NExprType_Cassign:;
_NCp1_NExprI_Ptype_assign_2(_Lexpr_1, &_Lat_2);
break;
case _NCp1_NExprType_Ccompare:;
_NCp1_NExprI_Ptype_compare_2(_Lexpr_1, &_Lat_2);
break;
case _NCp1_NExprType_Cbool:;
_NCp1_NExprI_Ptype_bool_2(_Lexpr_1, &_Lat_2);
break;
case _NCp1_NExprType_Cchar:;
_NCp1_NExprI_Ptype_char_2(_Lexpr_1, &_Lat_2);
break;
case _NCp1_NExprType_Cmath:;
_NCp1_NExprI_Ptype_math_2(_Lexpr_1, &_Lat_2);
break;
case _NCp1_NExprType_Cunary:;
_NCp1_NExprI_Ptype_unary_2(_Lexpr_1, &_Lat_2);
break;
case _NCp1_NExprType_Cref:;
_NCp1_NExprI_Ptype_ref_2(_Lexpr_1, &_Lat_2);
break;
case _NCp1_NExprType_Ccast_fast:;
_NCp1_NExprI_Ptype_cast_fast_2(_Lexpr_1, &_Lat_2);
break;
case _NCp1_NExprType_Clvar:;
_NCp1_NExprI_Ptype_lvar_2(_Lexpr_1, &_Lat_2);
break;
case _NCp1_NExprType_Cfvar:;
_NCp1_NExprI_Ptype_fvar_2(_Lexpr_1, &_Lat_2);
break;
case _NCp1_NExprType_Cgvar:;
_NCp1_NExprI_Ptype_gvar_2(_Lexpr_1, &_Lat_2);
break;
case _NCp1_NExprType_Ccvar:;
_NCp1_NExprI_Ptype_cvar_2(_Lexpr_1, &_Lat_2);
break;
case _NCp1_NExprType_Cbools:;
_NCp1_NExprI_Ptype_bools_2(_Lexpr_1, &_Lat_2);
break;
case _NCp1_NExprType_Cfunc:;
_NCp1_NExprI_Ptype_func_2(_Lexpr_1, &_Lat_2);
break;
case _NCp1_NExprType_Cmethod:;
_NCp1_NExprI_Ptype_method_2(_Lexpr_1, &_Lat_2);
break;
case _NCp1_NExprType_Ci32:;
_NCp1_NExprI_Ptype_i32_2(_Lexpr_1, &_Lat_2);
break;
case _NCp1_NExprType_Csize_of_type:;
_NCp1_NExprI_Ptype_size_of_type_2(_Lexpr_1, &_Lat_2);
break;
case _NCp1_NExprType_Cnull:;
_NCp1_NExprI_Ptype_null_2(_Lexpr_1, &_Lat_2);
break;
case _NCp1_NExprType_Cindex:;
_NCp1_NExprI_Ptype_index_2(_Lexpr_1, &_Lat_2);
break;
default:;
fprintf(stdout, "%u:%u - %u:%u: type() not implemented for #%s\n", _Gctx_begin_row, _Gctx_begin_col, _Gctx_end_row, _Gctx_end_col, _NCp1_NExprType_Pcp1_name_1((*_Lexpr_1)._Ftype));
break;
}
return _Lat_2;
}
void _NCp1_NValue_Pset_5(struct _NCp1_NValue* _Lv_0, int8_t _Lreff_1, bool _Lparen_2, _NCp1_NAt _Ltype_3, struct _NCp1_NTypeInfo* _Linfo_4) {
int8_t _Lc_5;
_Lc_5 = (*_Linfo_4)._Fref_v[(*_Linfo_4)._Farray_c];
(*_Lv_0)._Ftype = _Ltype_3;
(*_Lv_0)._Freff = ((_Lc_5 + 2) - _Lreff_1);
_NCp1_NTypeInfo_Pinit_1(&(*_Lv_0)._Finfo);
_NCp1_NTypeInfo_Pcopy_from_2(&(*_Lv_0)._Finfo, _Linfo_4);
(*_Lv_0)._Finfo._Fref_v[(*_Lv_0)._Finfo._Farray_c] = (_Lreff_1 - 1);
_NCp1_NTypeInfo_Pcount_1(&(*_Lv_0)._Finfo);
(*_Lv_0)._Fparen = _Lparen_2;
}
bool _NCp1_NGvar_Pprocess_1(_NCp1_NGvar _Lg_0) {
uint32_t _Lnum_1;
uint32_t _Ln3_2;
int32_t _Ln17_3;
struct _NCp1_NDeclGvar* _Lgvar_4;
_NCp1_NAt _Lat_i_5;
struct _NCp1_NAtData* _Lat_6;
_Lnum_1 = (uint32_t)(_Lg_0);
_Ln3_2 = (_Lnum_1 >> 3);
_Ln17_3 = (1 << (_Lnum_1 & 7));
if((_Ggvar_is_outputted[_Ln3_2] & _Ln17_3) != 0) {
return true;
}
_Ggvar_is_outputted[_Ln3_2] |= _Ln17_3;
_Lgvar_4 = _NCp1_NGvar_Pptr_1(_Lg_0);
_Lat_i_5 = (*_Lgvar_4)._Fdecl._Ftype;
_Lat_6 = _NCp1_NAt_Pptr_1(_Lat_i_5);
if(!(_NCp1_NDeclVarData_Pprocess_5(&(*_Lgvar_4)._Fdecl, (*_Lgvar_4)._Ffile, (*_Lgvar_4)._Frow, (*_Lgvar_4)._Fcol, (*_Lgvar_4)._Fat))) {
return false;
}
if(((*_Lgvar_4)._Fflags & _NCp1_NGvarFlags_Cno_decl) == _NCp1_NGvarFlags_C0) {
_Ggvar_outputted_v[_Ggvar_outputted_c++] = _Lg_0;
}
return true;
}
bool _NCp1_Pfarg_process_5(_NCp1_NExprI _Le_0, int8_t _Lca_ref_1, struct _NCp1_NValue* _Lca_value_2, struct _NCp1_NDeclVarData* _Lfd_arg_3, _NCp1_NAt _Lbase_at_4) {
struct _NCp1_NExpr* _Lce_5;
int32_t _Lr_6;
_Lce_5 = _NCp1_NExprI_Pptr_1(_Le_0);
if(_Lca_ref_1 != 0) {
_Lr_6 = (1 + _Lca_ref_1);
} else {
_Lr_6 = 1;
_Lr_6 += (int32_t)((*_Lfd_arg_3)._Ftype_info._Fref_v[(*_Lfd_arg_3)._Ftype_info._Farray_c]);
}
if((*_Lce_5)._Ftype == _NCp1_NExprType_Clvar) {
struct _NCp1_NExprLvar* _Lve_7;
struct _NCp1_NLvarData* _Llvar_8;
struct _NCp1_NDeclVarData* _Lvd_9;
_Lve_7 = _Lce_5;
_Llvar_8 = _NCp1_NLvar_Pptr_1((*_Lve_7)._Flvar);
_Lvd_9 = (&(*_Llvar_8)._Fdecl);
if((*_Lvd_9)._Ftype == _NCp1_NAt_Cnil) {
if(((*_Llvar_8)._Fflags & _NCp1_NLvarFlags_Cset_expr) == _NCp1_NLvarFlags_C0) {
(*_Lvd_9)._Ftype = (*_Lfd_arg_3)._Ftype;
_NCp1_NTypeInfo_Pinit_1(&(*_Lvd_9)._Ftype_info);
_NCp1_NTypeInfo_Pcopy_from_2(&(*_Lvd_9)._Ftype_info, &(*_Lfd_arg_3)._Ftype_info);
if((*_Lfd_arg_3)._Ftype_info._Fbuilt_in) {
(*_Lvd_9)._Ftype_info._Fbuilt_in = true;
(*_Lvd_9)._Ftype_info._Fref_v[0] = '\0';
} else if((*_Lvd_9)._Ftype_info._Fref_v[(*_Lvd_9)._Ftype_info._Farray_c] + _NCp1_NAt_Ppointer_1((*_Lvd_9)._Ftype)) {
(*_Lvd_9)._Ftype_info._Fref_v[(*_Lvd_9)._Ftype_info._Farray_c] -= (char)(1);
(*_Lvd_9)._Ftype_info._Fstar_c -= 1;
}
}
}
}
_NCp1_NExprI_Ptry_deduce_2(_Le_0, (*_Lfd_arg_3)._Ftype);
if(!(_NCp1_NExprI_Pvalue_4(_Le_0, _Lr_6, false, _Lca_value_2))) {
return false;
}
return true;
}
inline void _NCp1_NExprI_Ptry_deduce_math_2(struct _NCp1_NExpr* _Lexpr_0, _NCp1_NAt _Lat_1) {
struct _NCp1_NExprMath* _Le_2;
_Le_2 = _Lexpr_0;
_NCp1_NExprI_Ptry_deduce_2((*_Le_2)._Fleft, _Lat_1);
_NCp1_NExprI_Ptry_deduce_2((*_Le_2)._Fright, _Lat_1);
int32_t _Li_3;
_Li_3 = 0;
for(int i = (*_Le_2)._Fitem_c; i > 0; ) {
i --;
_NCp1_NExprI_Ptry_deduce_2((*_Le_2)._Fitem_v[_Li_3]._Fexpr, _Lat_1);
continue_0:;
_Li_3++;
}
break_0:;
}
inline void _NCp1_NExprI_Ptry_deduce_cvar_2(struct _NCp1_NExpr* _Lexpr_0, _NCp1_NAt _Lat_1) {
struct _NCp1_NExprCvar* _Le_2;
_Le_2 = _Lexpr_0;
if((*_Le_2)._Fat == _NCp1_NAt_Cnil) {
(*_Le_2)._Ftry = _Lat_1;
}
}
inline void _NCp1_NExprI_Ptype_assign_2(struct _NCp1_NExpr* _Lexpr_0, _NCp1_NAt* _Lat_1) {
struct _NCp1_NExprAssign* _Le_2;
_Le_2 = _Lexpr_0;
(*_Lat_1) = _NCp1_NExprI_Ptype_1((*_Le_2)._Fleft);
}
inline void _NCp1_NExprI_Ptype_compare_2(struct _NCp1_NExpr* _Lexpr_0, _NCp1_NAt* _Lat_1) {
struct _NCp1_NExprCompare* _Le_2;
_Le_2 = _Lexpr_0;
(*_Lat_1) = _NCp1_Pbasic_type_1(_NCp1_NBasicTypeId_Cbool);
}
inline void _NCp1_NExprI_Ptype_bool_2(struct _NCp1_NExpr* _Lexpr_0, _NCp1_NAt* _Lat_1) {
(*_Lat_1) = _NCp1_Pbasic_type_1(_NCp1_NBasicTypeId_Cbool);
}
inline void _NCp1_NExprI_Ptype_char_2(struct _NCp1_NExpr* _Lexpr_0, _NCp1_NAt* _Lat_1) {
(*_Lat_1) = _NCp1_Pbasic_type_1(_NCp1_NBasicTypeId_Cchar);
}
inline void _NCp1_NExprI_Ptype_math_2(struct _NCp1_NExpr* _Lexpr_0, _NCp1_NAt* _Lat_1) {
struct _NCp1_NExprMath* _Le_2;
_Le_2 = _Lexpr_0;
(*_Lat_1) = _NCp1_NExprI_Ptype_1((*_Le_2)._Fleft);
}
inline void _NCp1_NExprI_Ptype_unary_2(struct _NCp1_NExpr* _Lexpr_0, _NCp1_NAt* _Lat_1) {
struct _NCp1_NExprUnary* _Le_2;
_Le_2 = _Lexpr_0;
(*_Lat_1) = _NCp1_NExprI_Ptype_1((*_Le_2)._Fexpr);
}
inline void _NCp1_NExprI_Ptype_ref_2(struct _NCp1_NExpr* _Lexpr_0, _NCp1_NAt* _Lat_1) {
(*_Lat_1) = _NCp1_Pbasic_type_1(_NCp1_NBasicTypeId_Cref);
}
inline void _NCp1_NExprI_Ptype_cast_fast_2(struct _NCp1_NExpr* _Lexpr_0, _NCp1_NAt* _Lat_1) {
struct _NCp1_NExprCastFast* _Le_2;
_Le_2 = _Lexpr_0;
(*_Lat_1) = (*_Le_2)._Ftype;
}
inline void _NCp1_NExprI_Ptype_lvar_2(struct _NCp1_NExpr* _Lexpr_0, _NCp1_NAt* _Lat_1) {
struct _NCp1_NExprLvar* _Le_2;
struct _NCp1_NLvarData* _Llvar_3;
_Le_2 = _Lexpr_0;
_Llvar_3 = _NCp1_NLvar_Pptr_1((*_Le_2)._Flvar);
(*_Lat_1) = (*_Llvar_3)._Fdecl._Ftype;
}
inline void _NCp1_NExprI_Ptype_fvar_2(struct _NCp1_NExpr* _Lexpr_0, _NCp1_NAt* _Lat_1) {
struct _NCp1_NExprFvar* _Le_2;
_Le_2 = _Lexpr_0;
(*_Lat_1) = (*_NCp1_NStruct_Pptr_1((*_NCp1_NAt_Pptr_1((*_Le_2)._Fval._Ftype))._Fdecl._Fstruct))._Ffvar_v[(*_Le_2)._Ffvar]._Fdecl._Ftype;
}
inline void _NCp1_NExprI_Ptype_gvar_2(struct _NCp1_NExpr* _Lexpr_0, _NCp1_NAt* _Lat_1) {
struct _NCp1_NExprGvar* _Le_2;
struct _NCp1_NDeclGvar* _Lgvar_3;
_Le_2 = _Lexpr_0;
_Lgvar_3 = _NCp1_NGvar_Pptr_1((*_Le_2)._Fgvar);
(*_Lat_1) = (*_Lgvar_3)._Fdecl._Ftype;
}
inline void _NCp1_NExprI_Ptype_cvar_2(struct _NCp1_NExpr* _Lexpr_0, _NCp1_NAt* _Lat_1) {
struct _NCp1_NExprCvar* _Le_2;
struct _NCp1_NCvarData* _Lcvar_3;
_Le_2 = _Lexpr_0;
_Lcvar_3 = _NCp1_NCvar_Pptr_1((*_Le_2)._Fcvar);
(*_Lat_1) = (*_Lcvar_3)._Fdecl._Ftype;
}
inline void _NCp1_NExprI_Ptype_bools_2(struct _NCp1_NExpr* _Lexpr_0, _NCp1_NAt* _Lat_1) {
(*_Lat_1) = _NCp1_Pbasic_type_1(_NCp1_NBasicTypeId_Cbool);
}
inline void _NCp1_NExprI_Ptype_func_2(struct _NCp1_NExpr* _Lexpr_0, _NCp1_NAt* _Lat_1) {
struct _NCp1_NExprFunc* _Le_2;
_Le_2 = _Lexpr_0;
(*_Lat_1) = (*_NCp1_NFunc_Pptr_1((*_Le_2)._Ffunc_idx))._Fdecl._Ftype;
}
inline void _NCp1_NExprI_Ptype_method_2(struct _NCp1_NExpr* _Lexpr_0, _NCp1_NAt* _Lat_1) {
struct _NCp1_NExprMethod* _Le_2;
_Le_2 = _Lexpr_0;
(*_Lat_1) = (*_NCp1_NFunc_Pptr_1((*_Le_2)._Ffunc_idx))._Fdecl._Ftype;
}
inline void _NCp1_NExprI_Ptype_i32_2(struct _NCp1_NExpr* _Lexpr_0, _NCp1_NAt* _Lat_1) {
(*_Lat_1) = _NCp1_Pbasic_type_1(_NCp1_NBasicTypeId_Ci32);
}
inline void _NCp1_NExprI_Ptype_size_of_type_2(struct _NCp1_NExpr* _Lexpr_0, _NCp1_NAt* _Lat_1) {
(*_Lat_1) = _NCp1_Pbasic_type_1(_NCp1_NBasicTypeId_Cusz);
}
inline void _NCp1_NExprI_Ptype_null_2(struct _NCp1_NExpr* _Lexpr_0, _NCp1_NAt* _Lat_1) {
(*_Lat_1) = _NCp1_Pbasic_type_1(_NCp1_NBasicTypeId_Cref);
}
inline void _NCp1_NExprI_Ptype_index_2(struct _NCp1_NExpr* _Lexpr_0, _NCp1_NAt* _Lat_1) {
struct _NCp1_NExprIndex* _Le_2;
_Le_2 = _Lexpr_0;
(*_Lat_1) = _NCp1_NExprI_Ptype_1((*_Le_2)._Fleft);
}