#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#define _NStdC_NFd_Cnil (-1)
#define _NStdC_NExit_Csuccess 0
#define _NStdC_NExit_Cfailure (_NStdC_NExit_Csuccess + 1)
#define _NCmd_Cc 0
#define _NCmd_Crun (_NCmd_Cc + 1)
typedef int _NStdC_NFd;
typedef int _NStdC_NOpenFlags;
typedef int _NStdC_NExit;
typedef uint8_t _NCmd;
typedef int _NStdC_NSeek;
char _Ginclude_dir[512];
uint16_t _Ginclude_dir_len;
int32_t _Gcp1_path_c;
char** _Gcp1_path_v;
char** _Gcp1_path_real_v;
uint32_t _Gatexit_rm_c;
char** _Gatexit_rm_v;
uint32_t _Gatexit_rm_cap;
char _Gcmd_preprocess[512];
int32_t _Gincluded_c;
uint32_t* _Gincluded_len_v;
char** _Gincluded_v;
int32_t _Gincluded_cap;
int32_t _Gcp1_path_cap;
uint32_t* _Gcp1_path_len_v;
uint32_t* _Gcp1_path_real_len_v;
int main(int _Larg_c_0, char** _Larg_v_1);
void _Pon_exit_0();
void _Pprint_commands_1(char* _Lbin_0);
void _Pprint_c_usage_1(char* _Lbin_0);
bool _Pvalidate_cp1_paths_5(int32_t _Lstart_0, int32_t _Larg_c_1, char** _Larg_v_2, char* _Lbin_3, _NCmd _Lcmd_4);
void _Pprint_command_2(int32_t _Larg_c_0, char** _Larg_v_1);
void _Patexit_rm_1(char* _Lpath_0);
struct FILE* _NStdC_NFd_Pfopen_2(_NStdC_NFd _Lfile_0, char* _Lmode_1);
void _Pprint_run_usage_1(char* _Lbin_0);
int _NStdC_NFd_Pclose_1(_NStdC_NFd _Lfile_0);
void _Pget_compile_2(char* _Lbin_0, struct FILE* _Lninja_f_1);
void _Pprint_usage_2(char* _Lbin_0, _NCmd _Lcmd_1);
bool _Pcp1_path_input_4(char* _Lcp1_path_0, int32_t _Lcp1_path_len_1, char* _Lbin_2, _NCmd _Lcmd_3);
bool _NStdC_NFd_Popen_3(_NStdC_NFd* _Lfile_0, char* _Lpath_1, _NStdC_NOpenFlags _Lflags_2);
void _Pcp1_path_add_4(char* _Lcp1_path_real_0, int32_t _Lcp1_path_real_len_1, char* _Lcp1_path_2, int32_t _Lcp1_path_len_3);
int main(int _Larg_c_0, char** _Larg_v_1) {
char* _Lbin_2;
char _Labs_path_3[512];
uint16_t _Labs_path_len_4;
char* _Lslash_10;
char* _Lcmd_11;
if(false) {
_Pon_exit_0();
}
atexit(_Pon_exit_0);
_Lbin_2 = _Larg_v_1[0];
_Labs_path_len_4 = 0;
if(_Lbin_2[0] == '/') {
_Labs_path_len_4 = strlen(_Lbin_2);
memcpy(_Labs_path_3, _Lbin_2, _Labs_path_len_4);
_Labs_path_3[_Labs_path_len_4] = '\0';
} else {
bool _Lhas_slash_5;
_Lhas_slash_5 = false;
int32_t _Li_6;
_Li_6 = 0;
while(1) {
if(_Lbin_2[_Li_6] == '\0') {
goto break_0;
}
if(_Lbin_2[_Li_6] == '/') {
_Lhas_slash_5 = true;
goto break_0;
}
continue_0:;
_Li_6++;
}
break_0:;
if(_Lhas_slash_5) {
realpath(_Lbin_2, _Labs_path_3);
} else {
char* _Lpath_7;
char* _Lfound_8;
_NStdC_NFd _Lfd_9;
_Lpath_7 = strdup(getenv("PATH"));
_Lfound_8 = strtok(_Lpath_7, ":");
_Lfd_9 = _NStdC_NFd_Cnil;
while(_Lfound_8 != NULL) {
sprintf(_Labs_path_3, "%s/%s", _Lfound_8, _Lbin_2);
_Lfd_9 = open(_Labs_path_3, O_RDONLY);
if(_Lfd_9 != _NStdC_NFd_Cnil) {
goto break_1;
}
_Lfound_8 = strtok(NULL, ":");
continue_1:;
}
break_1:;
if(_Lfd_9 == _NStdC_NFd_Cnil) {
printf("Cannot run %s because we can:T detect its absolute path\n", _Lbin_2);
exit(_NStdC_NExit_Cfailure);
}
free(_Lpath_7);
}
}
_Lslash_10 = strrchr(_Labs_path_3, '/');
_Lslash_10[0] = '\0';
_Lslash_10 = strrchr(_Labs_path_3, '/');
_Lslash_10[0] = '\0';
sprintf(_Ginclude_dir, "%s/include", _Labs_path_3);
_Ginclude_dir_len = strlen(_Ginclude_dir);
if(_Larg_c_0 < 2) {
_Pprint_commands_1(_Lbin_2);
exit(_NStdC_NExit_Cfailure);
}
_Lcmd_11 = _Larg_v_1[1];
if(strcmp(_Lcmd_11, "c") == 0) {
char* _Lc_path_12;
size_t _Lc_path_len_13;
char _Lninja_path_14[24];
_NStdC_NFd _Lninja_fd_15;
struct FILE* _Lninja_f_16;
char _Lcommand_19[24 + 9];
int _Lret_20;
if(_Larg_c_0 < 4) {
_Pprint_c_usage_1(_Lbin_2);
exit(_NStdC_NExit_Cfailure);
}
_Lc_path_12 = _Larg_v_1[2];
_Lc_path_len_13 = strlen(_Lc_path_12);
if(!(((_Lc_path_len_13 > 2) && (_Lc_path_12[(_Lc_path_len_13 - 2)] == '.') && (_Lc_path_12[(_Lc_path_len_13 - 1)] == 'c')))) {
_Pprint_c_usage_1(_Lbin_2);
printf("Error, [output.c] (which is '%s') must be a filename that ends with '.c', for example: main.c\n", _Lc_path_12);
exit(_NStdC_NExit_Cfailure);
}
if(!(_Pvalidate_cp1_paths_5(3, _Larg_c_0, _Larg_v_1, _Lbin_2, _NCmd_Cc))) {
_Pprint_command_2(_Larg_c_0, _Larg_v_1);
exit(_NStdC_NExit_Cfailure);
}
mkdir("cp1-tmp", 32749);
strcpy(_Lninja_path_14, "cp1-tmp/ninja-XXXXXXXXX");
_Lninja_fd_15 = mkstemp(_Lninja_path_14);
_Patexit_rm_1(strdup(_Lninja_path_14));
if(_Lninja_fd_15 == _NStdC_NFd_Cnil) {
_Pprint_c_usage_1(_Lbin_2);
printf("Error, cannot open file for reading: %s\n", _Lninja_path_14);
exit(_NStdC_NExit_Cfailure);
}
_Lninja_f_16 = _NStdC_NFd_Pfopen_2(_Lninja_fd_15, "w");
fprintf(_Lninja_f_16, "rule parse\n");
fprintf(_Lninja_f_16, " command = %s-parse $in $out\n", _Lbin_2);
fprintf(_Lninja_f_16, "rule compile\n");
fprintf(_Lninja_f_16, " command = %s-compile $in $out\n", _Lbin_2);
int32_t _Li_17;
_Li_17 = 0;
for(int i = _Gcp1_path_c; i > 0; ) {
i --;
fprintf(_Lninja_f_16, "build cp1-tmp/%s-b: parse %s\n", _Gcp1_path_v[_Li_17], _Gcp1_path_real_v[_Li_17]);
continue_2:;
_Li_17++;
}
break_2:;
fprintf(_Lninja_f_16, "build %s: compile", _Lc_path_12);
int32_t _Li_18;
_Li_18 = 0;
for(int i = _Gcp1_path_c; i > 0; ) {
i --;
fprintf(_Lninja_f_16, " cp1-tmp/%s-b", _Gcp1_path_v[_Li_18]);
continue_3:;
_Li_18++;
}
break_3:;
fprintf(_Lninja_f_16, "\n");
fclose(_Lninja_f_16);
sprintf(_Lcommand_19, "ninja -f %s", _Lninja_path_14);
_Lret_20 = system(_Lcommand_19);
if(_Lret_20 != 0) {
exit(_NStdC_NExit_Cfailure);
}
} else if(strcmp(_Lcmd_11, "run") == 0) {
char _Lc_path_21[22];
_NStdC_NFd _Lc_fd_22;
char _Lexe_path_23[24];
_NStdC_NFd _Lexe_fd_24;
char _Lninja_path_25[24];
_NStdC_NFd _Lninja_fd_26;
struct FILE* _Lninja_f_27;
char _Lcommand_30[32 + 9];
int _Lninja_ret_31;
int _Lexe_ret_32;
if(_Larg_c_0 < 3) {
_Pprint_run_usage_1(_Lbin_2);
exit(_NStdC_NExit_Cfailure);
}
if(!(_Pvalidate_cp1_paths_5(2, _Larg_c_0, _Larg_v_1, _Lbin_2, _NCmd_Crun))) {
_Pprint_command_2(_Larg_c_0, _Larg_v_1);
exit(_NStdC_NExit_Cfailure);
}
mkdir("cp1-tmp", 32749);
strcpy(_Lc_path_21, "cp1-tmp/c-XXXXXXXXX");
_Lc_fd_22 = mkstemp(_Lc_path_21);
if(_Lc_fd_22 == _NStdC_NFd_Cnil) {
_Pprint_run_usage_1(_Lbin_2);
printf("Error, cannot open file for reading: %s\n", _Lc_path_21);
exit(_NStdC_NExit_Cfailure);
}
_NStdC_NFd_Pclose_1(_Lc_fd_22);
unlink(_Lc_path_21);
strcpy(_Lexe_path_23, "cp1-tmp/exe-XXXXXXXXX");
_Lexe_fd_24 = mkstemp(_Lexe_path_23);
if(_Lexe_fd_24 == _NStdC_NFd_Cnil) {
_Pprint_run_usage_1(_Lbin_2);
printf("Error, cannot open file for reading: %s\n", _Lexe_path_23);
exit(_NStdC_NExit_Cfailure);
}
_NStdC_NFd_Pclose_1(_Lexe_fd_24);
unlink(_Lexe_path_23);
_Lc_path_21[19] = '.';
_Lc_path_21[20] = 'c';
_Lc_path_21[21] = '\0';
_Patexit_rm_1(strdup(_Lc_path_21));
strcpy(_Lninja_path_25, "cp1-tmp/ninja-XXXXXXXXX");
_Lninja_fd_26 = mkstemp(_Lninja_path_25);
_Patexit_rm_1(strdup(_Lninja_path_25));
if(_Lninja_fd_26 == _NStdC_NFd_Cnil) {
_Pprint_run_usage_1(_Lbin_2);
printf("Error, cannot open file for reading: %s\n", _Lninja_path_25);
exit(_NStdC_NExit_Cfailure);
}
_Lninja_f_27 = _NStdC_NFd_Pfopen_2(_Lninja_fd_26, "w");
fprintf(_Lninja_f_27, "rule parse\n");
fprintf(_Lninja_f_27, " command = %s-parse $in $out\n", _Lbin_2);
fprintf(_Lninja_f_27, "rule compile\n");
fprintf(_Lninja_f_27, " command = %s-compile $in $out\n", _Lbin_2);
_Pget_compile_2(_Lbin_2, _Lninja_f_27);
int32_t _Li_28;
_Li_28 = 0;
for(int i = _Gcp1_path_c; i > 0; ) {
i --;
fprintf(_Lninja_f_27, "build cp1-tmp/%s-b: parse %s\n", _Gcp1_path_v[_Li_28], _Gcp1_path_real_v[_Li_28]);
continue_4:;
_Li_28++;
}
break_4:;
fprintf(_Lninja_f_27, "build %s: compile", _Lc_path_21);
int32_t _Li_29;
_Li_29 = 0;
for(int i = _Gcp1_path_c; i > 0; ) {
i --;
fprintf(_Lninja_f_27, " cp1-tmp/%s-b", _Gcp1_path_v[_Li_29]);
continue_5:;
_Li_29++;
}
break_5:;
fprintf(_Lninja_f_27, "\n");
fprintf(_Lninja_f_27, "build %s: c %s\n", _Lexe_path_23, _Lc_path_21);
fclose(_Lninja_f_27);
sprintf(_Lcommand_30, "ninja --quiet -f %s", _Lninja_path_25);
_Lninja_ret_31 = system(_Lcommand_30);
if(_Lninja_ret_31 != 0) {
exit(_NStdC_NExit_Cfailure);
}
_Lexe_ret_32 = system(_Lexe_path_23);
unlink(_Lexe_path_23);
if(_Lexe_ret_32 != 0) {
exit(_NStdC_NExit_Cfailure);
}
} else {
_Pprint_commands_1(_Lbin_2);
exit(_NStdC_NExit_Cfailure);
}
return 0;
}
void _Pon_exit_0() {
int32_t _Li_0;
_Li_0 = 0;
for(int i = _Gatexit_rm_c; i > 0; ) {
i --;
unlink(_Gatexit_rm_v[_Li_0]);
continue_0:;
_Li_0++;
}
break_0:;
}
void _Pprint_commands_1(char* _Lbin_0) {
printf("Usage: %s [command] [options]\n", _Lbin_0);
printf("Commands:\n");
printf("  c     Build a C file.\n");
printf("  run      Compile and run the cp1 codes.\n");
}
void _Pprint_c_usage_1(char* _Lbin_0) {
printf("Usage: %s c [output.c] [cp1 file/s...]\n", _Lbin_0);
}
bool _Pvalidate_cp1_paths_5(int32_t _Lstart_0, int32_t _Larg_c_1, char** _Larg_v_2, char* _Lbin_3, _NCmd _Lcmd_4) {
int32_t _Li_5;
_Li_5 = _Lstart_0;
for(int i = _Larg_c_1 - _Lstart_0; i > 0; ) {
i --;
char* _Lcp1_path_6;
size_t _Lcp1_path_len_7;
_Lcp1_path_6 = _Larg_v_2[_Li_5];
if(_Lcp1_path_6[0] == '/') {
_Pprint_usage_2(_Lbin_3, _Lcmd_4);
printf("Error, [cp1 file] (which is '%s') must be a relative filepath (e.g. file.cp1), not an absolute path (/home/user/file.cp1)\n", _Lcp1_path_6);
exit(_NStdC_NExit_Cfailure);
}
_Lcp1_path_len_7 = strlen(_Lcp1_path_6);
if(((_Lcp1_path_6[0] == '.') && (_Lcp1_path_6[1] == '/'))) {
_Lcp1_path_6 = &_Lcp1_path_6[2];
_Lcp1_path_len_7 -= 2;
}
int32_t _Lj_8;
_Lj_8 = 0;
for(int i = _Lcp1_path_len_7; i > 0; ) {
i --;
if(_Lcp1_path_6[_Lj_8] == '\\') {
_Pprint_usage_2(_Lbin_3, _Lcmd_4);
printf("Error, [cp1 file] (which is '%s') must not contain backslashes '\\', please use forward slashes '/' instead\n", _Lcp1_path_6);
exit(_NStdC_NExit_Cfailure);
}
continue_1:;
_Lj_8++;
}
break_1:;
int32_t _Lj_9;
_Lj_9 = 0;
for(int i = _Lcp1_path_len_7 - 1; i > 0; ) {
i --;
if(((_Lcp1_path_6[_Lj_9] == '.') && (_Lcp1_path_6[(_Lj_9 + 1)] == '/'))) {
_Pprint_usage_2(_Lbin_3, _Lcmd_4);
printf("Error, [cp1 file] (which is '%s') must not contain './'\n", _Lcp1_path_6);
exit(_NStdC_NExit_Cfailure);
}
continue_2:;
_Lj_9++;
}
break_2:;
if(!(((_Lcp1_path_len_7 > 4) && (_Lcp1_path_6[(_Lcp1_path_len_7 - 4)] == '.') && (_Lcp1_path_6[(_Lcp1_path_len_7 - 3)] == 'c') && (_Lcp1_path_6[(_Lcp1_path_len_7 - 2)] == 'p') && (_Lcp1_path_6[(_Lcp1_path_len_7 - 1)] == '1')))) {
_Pprint_usage_2(_Lbin_3, _Lcmd_4);
printf("Error, [cp1 file] (which is '%s') must be a filename that ends with '.cp1', for example: main.cp1\n", _Lcp1_path_6);
exit(_NStdC_NExit_Cfailure);
}
if(!(_Pcp1_path_input_4(_Lcp1_path_6, _Lcp1_path_len_7, _Lbin_3, _Lcmd_4))) {
_Pprint_usage_2(_Lbin_3, _Lcmd_4);
return false;
}
continue_0:;
_Li_5++;
}
break_0:;
return true;
}
void _Pprint_command_2(int32_t _Larg_c_0, char** _Larg_v_1) {
printf("Command was:");
int32_t _Li_2;
_Li_2 = 0;
for(int i = _Larg_c_0; i > 0; ) {
i --;
printf(" %s", _Larg_v_1[_Li_2]);
continue_0:;
_Li_2++;
}
break_0:;
printf("\n");
}
void _Patexit_rm_1(char* _Lpath_0) {
uint32_t _Li_1;
_Li_1 = _Gatexit_rm_c++;
if(_Gatexit_rm_cap < _Gatexit_rm_c) {
_Gatexit_rm_cap = ((_Gatexit_rm_c << 1) + 8);
_Gatexit_rm_v = realloc(_Gatexit_rm_v, _Gatexit_rm_cap * sizeof(size_t));
}
_Gatexit_rm_v[_Li_1] = _Lpath_0;
}
inline struct FILE* _NStdC_NFd_Pfopen_2(_NStdC_NFd _Lfile_0, char* _Lmode_1) {
return fdopen(_Lfile_0, _Lmode_1);
}
void _Pprint_run_usage_1(char* _Lbin_0) {
printf("Usage: %s run [cp1 file/s...]\n", _Lbin_0);
}
inline int _NStdC_NFd_Pclose_1(_NStdC_NFd _Lfile_0) {
return close(_Lfile_0);
}
void _Pget_compile_2(char* _Lbin_0, struct FILE* _Lninja_f_1) {
char* _Lpath_2;
char* _Lfound_3;
_Lpath_2 = strdup(getenv("PATH"));
_Lfound_3 = strtok(_Lpath_2, ":");
while(_Lfound_3 != NULL) {
_NStdC_NFd _Lfd_4;
char _Lcompile_5[512];
sprintf(_Lcompile_5, "%s/tcc", _Lfound_3);
_Lfd_4 = open(_Lcompile_5, O_RDONLY);
if(_Lfd_4 != _NStdC_NFd_Cnil) {
fprintf(_Lninja_f_1, "rule c\n");
fprintf(_Lninja_f_1, " command = tcc $in -o $out\n");
_NStdC_NFd_Pclose_1(_Lfd_4);
free(_Lpath_2);
return;
}
sprintf(_Lcompile_5, "%s/clang", _Lfound_3);
_Lfd_4 = open(_Lcompile_5, O_RDONLY);
if(_Lfd_4 != _NStdC_NFd_Cnil) {
fprintf(_Lninja_f_1, "rule c\n");
fprintf(_Lninja_f_1, " command = clang $in -o $out\n");
_NStdC_NFd_Pclose_1(_Lfd_4);
free(_Lpath_2);
return;
}
sprintf(_Lcompile_5, "%s/gcc", _Lfound_3);
_Lfd_4 = open(_Lcompile_5, O_RDONLY);
if(_Lfd_4 != _NStdC_NFd_Cnil) {
fprintf(_Lninja_f_1, "rule c\n");
fprintf(_Lninja_f_1, " command = gcc $in -o $out\n");
_NStdC_NFd_Pclose_1(_Lfd_4);
free(_Lpath_2);
return;
}
_Lfound_3 = strtok(NULL, ":");
continue_0:;
}
break_0:;
printf("Cannot execute '%s run' because the required compile was not found: tcc clang or gcc\n", _Lbin_0);
exit(_NStdC_NExit_Cfailure);
}
void _Pprint_usage_2(char* _Lbin_0, _NCmd _Lcmd_1) {
switch(_Lcmd_1) {
case _NCmd_Cc:;
_Pprint_c_usage_1(_Lbin_0);
break;
case _NCmd_Crun:;
_Pprint_run_usage_1(_Lbin_0);
break;
}
}
bool _Pcp1_path_input_4(char* _Lcp1_path_0, int32_t _Lcp1_path_len_1, char* _Lbin_2, _NCmd _Lcmd_3) {
_NStdC_NFd _Lfd_5;
size_t _Llen_6;
char* _Ldata_7;
int32_t _Lpos_8;
int32_t _Lline_9;
bool _Lpreprocess_10;
int32_t _Li_4;
_Li_4 = 0;
for(int i = _Gcp1_path_c; i > 0; ) {
i --;
if(memcmp(_Gcp1_path_v[_Li_4], _Lcp1_path_0, _Lcp1_path_len_1) == 0) {
return true;
}
continue_0:;
_Li_4++;
}
break_0:;
if(!(_NStdC_NFd_Popen_3(&_Lfd_5, _Lcp1_path_0, O_RDONLY))) {
printf("Error, [cp1 file] (which is '%s') cannot be opened for reading\n", _Lcp1_path_0);
return false;
}
_Llen_6 = lseek(_Lfd_5, 0, SEEK_END);
lseek(_Lfd_5, 0, SEEK_SET);
_Ldata_7 = malloc(_Llen_6);
read(_Lfd_5, _Ldata_7, _Llen_6);
_NStdC_NFd_Pclose_1(_Lfd_5);
if(!(((_Llen_6 > 0) && (_Ldata_7[(_Llen_6 - 1)] == '\n')))) {
printf("Error, [cp1 file] (which is '%s') must end a new line\n", _Lcp1_path_0);
return false;
}
if(_Ldata_7[(_Llen_6 - 2)] == '\r') {
printf("Error, [cp1 file] (which is '%s') must have Unix line endings '\\n' instead of Windows line endings '\\r\\n'\n", _Lcp1_path_0);
return false;
}
_Lpos_8 = 0;
_Lline_9 = 0;
_Lpreprocess_10 = false;
while(_Lpos_8 < _Llen_6) {
int32_t _Lstart_11;
int32_t _Lfirst_char_12;
_Lline_9++;
_Lstart_11 = _Lpos_8;
while(1) {
if(_Ldata_7[_Lpos_8] == '\n') {
goto break_2;
}
_Lpos_8++;
continue_2:;
}
break_2:;
_Lfirst_char_12 = _Lstart_11;
while(1) {
if(((_Ldata_7[_Lfirst_char_12] == ' ') || (_Ldata_7[_Lfirst_char_12] == '\t'))) {
_Lfirst_char_12++;
goto continue_3;
} else {
goto break_3;
}
continue_3:;
}
break_3:;
if(((_Ldata_7[_Lfirst_char_12] == '#') && (_Ldata_7[(_Lfirst_char_12 + 1)] == 'i') && (_Ldata_7[(_Lfirst_char_12 + 2)] == 'f') && ((_Ldata_7[(_Lfirst_char_12 + 3)] == '(') || ((_Ldata_7[(_Lfirst_char_12 + 3)] == '!') && (_Ldata_7[(_Lfirst_char_12 + 4)] == '('))))) {
_Lpreprocess_10 = true;
goto break_1;
}
_Lpos_8++;
continue_1:;
}
break_1:;
if(_Lpreprocess_10) {
char _Ltmp_path_13[17];
_NStdC_NFd _Ltmp_fd_14;
void* _Ltmp_path_dup_15;
free(_Ldata_7);
memcpy(_Ltmp_path_13, "cp1-tmp-XXXXXXXX", 17);
_Ltmp_fd_14 = mkstemp(_Ltmp_path_13);
if(_Ltmp_fd_14 == _NStdC_NFd_Cnil) {
printf("Error, cannot create a temporary file at the current folder\n");
return false;
}
_NStdC_NFd_Pclose_1(_Ltmp_fd_14);
sprintf(_Gcmd_preprocess, "%s-preprocess %.*s %s\n", _Lbin_2, _Lcp1_path_len_1, _Lcp1_path_0, _Ltmp_path_13);
fflush(stdout);
if(system(_Gcmd_preprocess) != 0) {
return false;
}
_Ltmp_path_dup_15 = malloc(17);
memcpy(_Ltmp_path_dup_15, _Ltmp_path_13, 17);
_Patexit_rm_1(_Ltmp_path_dup_15);
_Pcp1_path_add_4(_Ltmp_path_dup_15, 16, _Lcp1_path_0, _Lcp1_path_len_1);
if(!(_NStdC_NFd_Popen_3(&_Lfd_5, _Ltmp_path_dup_15, O_RDONLY))) {
printf("Error, cannot open file for reading: %s\n", _Ltmp_path_13);
return false;
}
_Llen_6 = lseek(_Lfd_5, 0, SEEK_END);
lseek(_Lfd_5, 0, SEEK_SET);
_Ldata_7 = malloc(_Llen_6);
read(_Lfd_5, _Ldata_7, _Llen_6);
_NStdC_NFd_Pclose_1(_Lfd_5);
} else {
_Pcp1_path_add_4(_Lcp1_path_0, _Lcp1_path_len_1, _Lcp1_path_0, _Lcp1_path_len_1);
}
_Lpos_8 = 0;
_Lline_9 = 0;
while(_Lpos_8 < _Llen_6) {
int32_t _Lstart_16;
int32_t _Lfirst_char_17;
int32_t _Li_52;
_Lline_9++;
_Lstart_16 = _Lpos_8;
while(1) {
if(_Ldata_7[_Lpos_8] == '\n') {
goto break_5;
}
_Lpos_8++;
continue_5:;
}
break_5:;
_Lfirst_char_17 = _Lstart_16;
while(1) {
if(((_Ldata_7[_Lfirst_char_17] == ' ') || (_Ldata_7[_Lfirst_char_17] == '\t'))) {
_Lfirst_char_17++;
goto continue_6;
} else {
goto break_6;
}
continue_6:;
}
break_6:;
if(((_Ldata_7[_Lfirst_char_17] == '#') && (_Ldata_7[(_Lfirst_char_17 + 1)] == 'i') && (_Ldata_7[(_Lfirst_char_17 + 2)] == 'm') && (_Ldata_7[(_Lfirst_char_17 + 3)] == 'p') && (_Ldata_7[(_Lfirst_char_17 + 4)] == 'o') && (_Ldata_7[(_Lfirst_char_17 + 5)] == 'r') && (_Ldata_7[(_Lfirst_char_17 + 6)] == 't') && ((_Ldata_7[(_Lfirst_char_17 + 7)] == ' ') || (_Ldata_7[(_Lfirst_char_17 + 7)] == '\t')))) {
int32_t _Lbegin_18;
_Lstart_16 += 8;
_Lbegin_18 = -1;
int32_t _Lj_19;
_Lj_19 = _Lstart_16;
for(int i = _Lpos_8 - _Lstart_16; i > 0; ) {
i --;
if(_Ldata_7[_Lj_19] == '\"') {
_Lbegin_18 = _Lj_19;
goto break_7;
} else if(_Ldata_7[_Lj_19] == ' ') {
} else if(_Ldata_7[_Lj_19] == '\t') {
} else {
fprintf(stdout, "%s:%u: Invalid character '%c' found in #include <...>\n", _Lcp1_path_0, _Lline_9, _Ldata_7[_Lj_19]);
return false;
}
continue_7:;
_Lj_19++;
}
break_7:;
if(_Lbegin_18 != -1) {
int32_t _Lend_20;
char* _Limport_22;
int32_t _Limport_path_len_23;
char* _Limport_path_26;
_Lstart_16 = (_Lbegin_18 + 1);
_Lend_20 = -1;
int32_t _Lj_21;
_Lj_21 = _Lstart_16;
for(int i = _Lpos_8 - _Lstart_16; i > 0; ) {
i --;
if(_Ldata_7[_Lj_21] == '\"') {
_Lend_20 = _Lj_21;
goto break_8;
}
continue_8:;
_Lj_21++;
}
break_8:;
if(_Lend_20 == -1) {
printf("%s:%u: #import \"...\" must end with '\"'\n", _Lcp1_path_0, _Lline_9);
return false;
}
_Limport_22 = &_Ldata_7[_Lstart_16];
_Limport_path_len_23 = (_Lend_20 - _Lstart_16);
if(((_Limport_path_len_23 >= 4) && (_Limport_22[(_Limport_path_len_23 - 4)] == '.') && (_Limport_22[(_Limport_path_len_23 - 3)] == 'c') && (_Limport_22[(_Limport_path_len_23 - 2)] == 'p') && (_Limport_22[(_Limport_path_len_23 - 1)] == '1'))) {
printf("%s:%u: #import \"%.*s\" doesn:T need a '.cp1' suffix\n", _Lcp1_path_0, _Lline_9, _Limport_path_len_23, _Limport_22);
return false;
}
if(_Limport_22[0] == '/') {
printf("%s:%u: #import \"%.*s\" must be a relative path, '/' was detected at the beginning of file path\n", _Lcp1_path_0, _Lline_9, _Limport_path_len_23, _Limport_22);
return false;
}
int32_t _Lj_24;
_Lj_24 = 0;
for(int i = _Limport_path_len_23; i > 0; ) {
i --;
if(_Limport_22[_Lj_24] == '\\') {
printf("%s:%u: #import \"%.*s\" must not contain backslashes '\\', please use forward slashes '/' instead\n", _Lcp1_path_0, _Lline_9, _Limport_path_len_23, _Limport_22);
return false;
}
continue_9:;
_Lj_24++;
}
break_9:;
int32_t _Lj_25;
_Lj_25 = 0;
for(int i = _Limport_path_len_23 - 1; i > 0; ) {
i --;
if(((_Limport_22[_Lj_25] == '.') && (_Limport_22[(_Lj_25 + 1)] == '/'))) {
printf("%s:%u: #import \"%.*s\" must not contain './'\n", _Lcp1_path_0, _Lline_9, _Limport_path_len_23, _Limport_22);
return false;
}
continue_10:;
_Lj_25++;
}
break_10:;
_Limport_path_26 = malloc(_Limport_path_len_23 + 5);
memcpy(_Limport_path_26, _Limport_22, _Limport_path_len_23);
_Limport_path_26[_Limport_path_len_23++] = '.';
_Limport_path_26[_Limport_path_len_23++] = 'c';
_Limport_path_26[_Limport_path_len_23++] = 'p';
_Limport_path_26[_Limport_path_len_23++] = '1';
_Limport_path_26[_Limport_path_len_23] = '\0';
if(!(_Pcp1_path_input_4(_Limport_path_26, _Limport_path_len_23, _Lbin_2, _Lcmd_3))) {
printf("Error from #import \"%.*s\" at file '%s' line %u\n", _Limport_path_len_23 - 4, _Limport_22, _Lcp1_path_0, _Lline_9);
return false;
}
}
} else if(((_Ldata_7[_Lfirst_char_17] == '#') && (_Ldata_7[(_Lfirst_char_17 + 1)] == 'i') && (_Ldata_7[(_Lfirst_char_17 + 2)] == 'n') && (_Ldata_7[(_Lfirst_char_17 + 3)] == 'c') && (_Ldata_7[(_Lfirst_char_17 + 4)] == 'l') && (_Ldata_7[(_Lfirst_char_17 + 5)] == 'u') && (_Ldata_7[(_Lfirst_char_17 + 6)] == 'd') && (_Ldata_7[(_Lfirst_char_17 + 7)] == 'e') && ((_Ldata_7[(_Lfirst_char_17 + 8)] == ' ') || (_Ldata_7[(_Lfirst_char_17 + 8)] == '\t')))) {
int32_t _Lbegin_27;
_Lstart_16 += 9;
_Lbegin_27 = -1;
int32_t _Lj_28;
_Lj_28 = _Lstart_16;
for(int i = _Lpos_8 - _Lstart_16; i > 0; ) {
i --;
if(_Ldata_7[_Lj_28] == '<') {
_Lbegin_27 = _Lj_28;
goto break_11;
} else if(_Ldata_7[_Lj_28] == ' ') {
} else if(_Ldata_7[_Lj_28] == '\t') {
} else {
fprintf(stdout, "%s:%u: Invalid character '%c' found in #include <...>\n", _Lcp1_path_0, _Lline_9, _Ldata_7[_Lj_28]);
return false;
}
continue_11:;
_Lj_28++;
}
break_11:;
if(_Lbegin_27 != -1) {
int32_t _Lend_29;
char* _Linclude_path_31;
int32_t _Linclude_path_len_32;
bool _Lfound_33;
_Lstart_16 = (_Lbegin_27 + 1);
_Lend_29 = -1;
int32_t _Lj_30;
_Lj_30 = _Lstart_16;
for(int i = _Lpos_8 - _Lstart_16; i > 0; ) {
i --;
if(_Ldata_7[_Lj_30] == '>') {
_Lend_29 = _Lj_30;
goto break_12;
}
continue_12:;
_Lj_30++;
}
break_12:;
if(_Lend_29 == -1) {
printf("%s:%u: #include <...> must end with '>'\n", _Lcp1_path_0, _Lline_9);
return false;
}
_Linclude_path_31 = &_Ldata_7[_Lstart_16];
_Linclude_path_len_32 = (_Lend_29 - _Lstart_16);
_Lfound_33 = false;
int32_t _Lj_34;
_Lj_34 = 0;
for(int i = _Gincluded_c; i > 0; ) {
i --;
if(((_Linclude_path_len_32 == _Gincluded_len_v[_Lj_34]) && (memcmp(_Gincluded_v[_Lj_34], _Linclude_path_31, _Linclude_path_len_32) == 0))) {
_Lfound_33 = true;
goto break_13;
}
continue_13:;
_Lj_34++;
}
break_13:;
if(!(_Lfound_33)) {
int32_t _Li_35;
char* _Lpath_36;
char _Lspec_path_37[128];
_NStdC_NFd _Lspec_fd_39;
size_t _Lspec_len_40;
char* _Lspec_data_41;
int32_t _Lspec_pos_42;
int32_t _Lspec_line_43;
_Li_35 = _Gincluded_c++;
if(_Gincluded_cap < _Gincluded_c) {
_Gincluded_cap = ((_Gincluded_c << 1) + 8);
_Gincluded_v = realloc(_Gincluded_v, _Gincluded_cap * sizeof(size_t));
_Gincluded_len_v = realloc(_Gincluded_len_v, _Gincluded_cap * sizeof(uint32_t));
}
_Lpath_36 = malloc(_Linclude_path_len_32 + 1);
memcpy(_Lpath_36, _Linclude_path_31, _Linclude_path_len_32);
_Lpath_36[_Linclude_path_len_32] = '\0';
_Gincluded_v[_Li_35] = _Lpath_36;
_Gincluded_len_v[_Li_35] = _Linclude_path_len_32;
sprintf(_Lspec_path_37, "%s/%s", _Ginclude_dir, _Lpath_36);
uint16_t _Li_38;
_Li_38 = (_Ginclude_dir_len + 1);
for(int i = strlen(_Lspec_path_37) - (_Ginclude_dir_len + 1); i > 0; ) {
i --;
if(_Lspec_path_37[_Li_38] == '/') {
_Lspec_path_37[_Li_38] = '-';
}
continue_14:;
_Li_38++;
}
break_14:;
if(!(_NStdC_NFd_Popen_3(&_Lspec_fd_39, _Lspec_path_37, O_RDONLY))) {
printf("%s:%u: #include <%s> failed because '%s' does not exists\n", _Lcp1_path_0, _Lline_9, _Lpath_36, _Lspec_path_37);
return false;
}
_Lspec_len_40 = lseek(_Lspec_fd_39, 0, SEEK_END);
lseek(_Lspec_fd_39, 0, SEEK_SET);
_Lspec_data_41 = malloc(_Lspec_len_40 + 1);
read(_Lspec_fd_39, _Lspec_data_41, _Lspec_len_40);
_Lspec_pos_42 = 0;
_Lspec_line_43 = 0;
while(_Lspec_pos_42 < _Lspec_len_40) {
int32_t _Lstart_44;
_Lspec_line_43++;
_Lstart_44 = _Lspec_pos_42;
while(1) {
if(_Lspec_data_41[_Lspec_pos_42] == '\n') {
if(_Lspec_data_41[_Lstart_44] == '<') {
int32_t _Lrangle_45;
_Lstart_44++;
_Lrangle_45 = -1;
int32_t _Lj_46;
_Lj_46 = _Lstart_44;
for(int i = _Lspec_pos_42 - _Lstart_44; i > 0; ) {
i --;
if(_Lspec_data_41[_Lj_46] == '>') {
_Lrangle_45 = _Lj_46;
goto break_17;
}
continue_17:;
_Lj_46++;
}
break_17:;
if(_Lrangle_45 != -1) {
char* _Lfile_path_47;
int32_t _Lfile_path_len_48;
char* _Lfile_path_dup_49;
char* _Lreal_path_50;
size_t _Lreal_path_len_51;
_Lfile_path_47 = &_Lspec_data_41[_Lstart_44];
_Lfile_path_len_48 = (_Lrangle_45 - _Lstart_44);
_Lfile_path_dup_49 = malloc(_Lfile_path_len_48 + 1);
memcpy(_Lfile_path_dup_49, _Lfile_path_47, _Lfile_path_len_48);
_Lfile_path_dup_49[_Lfile_path_len_48] = '\0';
_Lreal_path_50 = malloc(_Ginclude_dir_len + 1 + _Lfile_path_len_48 + 1);
sprintf(_Lreal_path_50, "%s/%.*s", _Ginclude_dir, _Lfile_path_len_48, _Lfile_path_47);
_Lreal_path_len_51 = strlen(_Lreal_path_50);
_Pcp1_path_add_4(_Lreal_path_50, _Lreal_path_len_51, _Lfile_path_dup_49, _Lfile_path_len_48);
}
}
_Lspec_pos_42++;
goto break_16;
}
_Lspec_pos_42++;
continue_16:;
}
break_16:;
continue_15:;
}
break_15:;
free(_Lspec_data_41);
}
}
}
_Li_52 = _Lfirst_char_17;
while(1) {
if(_Ldata_7[_Li_52] == '\n') {
goto break_18;
}
if(((_Ldata_7[_Li_52] == '/') && (_Ldata_7[(_Li_52 + 1)] == '/'))) {
goto break_18;
}
if(_Ldata_7[_Li_52] == '{') {
goto stop;
}
_Li_52++;
continue_18:;
}
break_18:;
_Lpos_8++;
continue_4:;
}
break_4:;
stop:
free(_Ldata_7);
return true;
}
inline bool _NStdC_NFd_Popen_3(_NStdC_NFd* _Lfile_0, char* _Lpath_1, _NStdC_NOpenFlags _Lflags_2) {
_NStdC_NFd _Lfd_3;
_Lfd_3 = open(_Lpath_1, _Lflags_2);
if(_Lfd_3 != -1) {
(*_Lfile_0) = _Lfd_3;
return true;
} else {
return false;
}
}
void _Pcp1_path_add_4(char* _Lcp1_path_real_0, int32_t _Lcp1_path_real_len_1, char* _Lcp1_path_2, int32_t _Lcp1_path_len_3) {
int32_t _Li_4;
_Li_4 = _Gcp1_path_c++;
if(_Gcp1_path_cap < _Gcp1_path_c) {
_Gcp1_path_cap = ((_Gcp1_path_cap << 1) + 8);
_Gcp1_path_v = realloc(_Gcp1_path_v, _Gcp1_path_cap * sizeof(size_t));
_Gcp1_path_len_v = realloc(_Gcp1_path_len_v, _Gcp1_path_cap * sizeof(uint32_t));
_Gcp1_path_real_v = realloc(_Gcp1_path_real_v, _Gcp1_path_cap * sizeof(size_t));
_Gcp1_path_real_len_v = realloc(_Gcp1_path_real_len_v, _Gcp1_path_cap * sizeof(uint32_t));
}
_Gcp1_path_v[_Li_4] = _Lcp1_path_2;
_Gcp1_path_len_v[_Li_4] = _Lcp1_path_len_3;
_Gcp1_path_real_v[_Li_4] = _Lcp1_path_real_0;
_Gcp1_path_real_len_v[_Li_4] = _Lcp1_path_real_len_1;
}
