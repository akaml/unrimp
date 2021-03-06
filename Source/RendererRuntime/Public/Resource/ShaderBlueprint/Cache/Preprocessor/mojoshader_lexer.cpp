/* Generated by re2c 0.16 on Mon Jan  2 17:02:21 2017 */
//#line 1 "mojoshader_lexer.re"
/**
 * MojoShader; generate shader programs from bytecode of compiled
 *  Direct3D shaders.
 *
 * Please see the file LICENSE.txt in the source's root directory.
 *
 *  This file written by Ryan C. Gordon.
 */

// This was originally based on examples/pp-c.re from re2c: http://re2c.org/
//   re2c is public domain code.
//
// You build mojoshader_lexer.c from the .re file with re2c...
// re2c -is -o mojoshader_lexer.c mojoshader_lexer.re
//
// Changes to the lexer are done to the .re file, not the C code!
//
// Please note that this isn't a perfect C lexer, since it is used for both
//  HLSL and shader assembly language, and follows the quirks of Microsoft's
//  tools.

// Disable warnings
#ifdef _WIN32
	#pragma warning(disable: 4267)	// warning C4267: '=' : conversion from '<x>' to '<y>', possible loss of data
	#pragma warning(disable: 4668)	// warning C4668: '<x>' is not defined as a preprocessor macro, replacing with '0' for '#if/#elif'
	#pragma warning(disable: 4127)	// warning C4127: conditional expression is constant
	#pragma warning(disable: 4702)	// warning C4702: unreachable code
	#pragma warning(disable: 4061)	// warning C4061: enumerator '<x>' in switch of enum '<y>' is not explicitly handled by a case label
	#pragma warning(disable: 4505)	// warning C4505: '<x>': unreferenced local function has been removed
#endif

#define MOJOSHADER_NO_VERSION_INCLUDE


#define __MOJOSHADER_INTERNAL__ 1
#include "RendererRuntime/Public/Resource/ShaderBlueprint/Cache/Preprocessor/mojoshader_internal.h"

typedef unsigned char uchar;

#define YYMAXFILL 10
#define RET(t) return update_state(s, eoi, cursor, token, (Token) t)
#define YYCTYPE uchar
#define YYCURSOR cursor
#define YYLIMIT limit
#define YYMARKER s->lexer_marker
#define YYFILL(n) { if ((n) == 1) { cursor = sentinel; limit = cursor + YYMAXFILL; eoi = 1; } }

static uchar sentinel[YYMAXFILL];

static Token update_state(IncludeState *s, int eoi, const uchar *cur,
                          const uchar *tok, const Token val)
{
    if (eoi)
    {
        s->bytes_left = 0;
        s->source = (const char *) s->source_base + s->orig_length;
        if ( (tok >= sentinel) && (tok < (sentinel+YYMAXFILL)) )
            s->token = s->source;
        else
            s->token = (const char *) tok;
    } // if
    else
    {
        s->bytes_left -= (unsigned int) (cur - ((const uchar *) s->source));
        s->source = (const char *) cur;
        s->token = (const char *) tok;
    } // else
    s->tokenlen = (unsigned int) (s->source - s->token);
    s->tokenval = val;
    return val;
} // update_state

Token preprocessor_lexer(IncludeState *s)
{
    const uchar *cursor = (const uchar *) s->source;
    const uchar *token = cursor;
    const uchar *matchptr;
    const uchar *limit = cursor + s->bytes_left;
    int eoi = 0;

#line 82 "mojoshader_lexer.re"


    // preprocessor directives are only valid at start of line.
    if (s->tokenval == ((Token) '\n'))
        goto ppdirective;  // may jump back to scanner_loop.

scanner_loop:
    if (YYLIMIT == YYCURSOR) YYFILL(1);
    token = cursor;


#line 83 "<stdout>"
{
	YYCTYPE yych;
	unsigned int yyaccept = 0;
	if ((YYLIMIT - YYCURSOR) < 4) YYFILL(4);
	yych = *YYCURSOR;
	switch (yych) {
	case 0x00:	goto yy2;
	case '\t':
	case '\v':
	case '\f':
	case ' ':	goto yy6;
	case '\n':	goto yy9;
	case '\r':	goto yy11;
	case '!':	goto yy12;
	case '"':	goto yy14;
	case '#':	goto yy15;
	case '%':	goto yy17;
	case '&':	goto yy19;
	case '\'':	goto yy21;
	case '(':	goto yy22;
	case ')':	goto yy24;
	case '*':	goto yy26;
	case '+':	goto yy28;
	case ',':	goto yy30;
	case '-':	goto yy32;
	case '.':	goto yy34;
	case '/':	goto yy36;
	case '0':	goto yy38;
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	goto yy40;
	case ':':	goto yy42;
	case ';':	goto yy44;
	case '<':	goto yy46;
	case '=':	goto yy48;
	case '>':	goto yy50;
	case '?':	goto yy52;
	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':
	case '_':
	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':	goto yy54;
	case '[':	goto yy57;
	case '\\':	goto yy59;
	case ']':	goto yy60;
	case '^':	goto yy62;
	case '{':	goto yy64;
	case '|':	goto yy66;
	case '}':	goto yy68;
	case '~':	goto yy70;
	default:	goto yy4;
	}
yy2:
	++YYCURSOR;
#line 158 "mojoshader_lexer.re"
	{ if (eoi) { RET(TOKEN_EOI); } goto bad_chars; }
#line 194 "<stdout>"
yy4:
	++YYCURSOR;
yy5:
#line 162 "mojoshader_lexer.re"
	{ goto bad_chars; }
#line 200 "<stdout>"
yy6:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	switch (yych) {
	case '\t':
	case '\v':
	case '\f':
	case ' ':	goto yy6;
	default:	goto yy8;
	}
yy8:
#line 160 "mojoshader_lexer.re"
	{ if (s->report_whitespace) RET(' '); goto scanner_loop; }
#line 215 "<stdout>"
yy9:
	++YYCURSOR;
yy10:
#line 161 "mojoshader_lexer.re"
	{ s->line++; RET('\n'); }
#line 221 "<stdout>"
yy11:
	yych = *++YYCURSOR;
	switch (yych) {
	case '\n':	goto yy9;
	default:	goto yy10;
	}
yy12:
	++YYCURSOR;
	switch ((yych = *YYCURSOR)) {
	case '=':	goto yy72;
	default:	goto yy13;
	}
yy13:
#line 139 "mojoshader_lexer.re"
	{ RET('!'); }
#line 237 "<stdout>"
yy14:
	yyaccept = 0;
	yych = *(YYMARKER = ++YYCURSOR);
	switch (yych) {
	case '\n':
	case '\r':	goto yy5;
	default:	goto yy75;
	}
yy15:
	++YYCURSOR;
	switch ((yych = *YYCURSOR)) {
	case '#':	goto yy80;
	default:	goto yy16;
	}
yy16:
#line 130 "mojoshader_lexer.re"
	{ RET(TOKEN_HASH); }
#line 255 "<stdout>"
yy17:
	++YYCURSOR;
	switch ((yych = *YYCURSOR)) {
	case '=':	goto yy82;
	default:	goto yy18;
	}
yy18:
#line 145 "mojoshader_lexer.re"
	{ RET('%'); }
#line 265 "<stdout>"
yy19:
	++YYCURSOR;
	switch ((yych = *YYCURSOR)) {
	case '&':	goto yy84;
	case '=':	goto yy86;
	default:	goto yy20;
	}
yy20:
#line 138 "mojoshader_lexer.re"
	{ RET('&'); }
#line 276 "<stdout>"
yy21:
	yyaccept = 0;
	yych = *(YYMARKER = ++YYCURSOR);
	switch (yych) {
	case '\n':
	case '\r':	goto yy5;
	default:	goto yy89;
	}
yy22:
	++YYCURSOR;
#line 132 "mojoshader_lexer.re"
	{ RET('('); }
#line 289 "<stdout>"
yy24:
	++YYCURSOR;
#line 133 "mojoshader_lexer.re"
	{ RET(')'); }
#line 294 "<stdout>"
yy26:
	++YYCURSOR;
	switch ((yych = *YYCURSOR)) {
	case '=':	goto yy92;
	default:	goto yy27;
	}
yy27:
#line 143 "mojoshader_lexer.re"
	{ RET('*'); }
#line 304 "<stdout>"
yy28:
	++YYCURSOR;
	switch ((yych = *YYCURSOR)) {
	case '+':	goto yy94;
	case '=':	goto yy96;
	default:	goto yy29;
	}
yy29:
#line 142 "mojoshader_lexer.re"
	{ RET('+'); }
#line 315 "<stdout>"
yy30:
	++YYCURSOR;
#line 137 "mojoshader_lexer.re"
	{ RET(','); }
#line 320 "<stdout>"
yy32:
	++YYCURSOR;
	switch ((yych = *YYCURSOR)) {
	case '-':	goto yy98;
	case '=':	goto yy100;
	default:	goto yy33;
	}
yy33:
#line 141 "mojoshader_lexer.re"
	{ RET('-'); }
#line 331 "<stdout>"
yy34:
	++YYCURSOR;
	switch ((yych = *YYCURSOR)) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	goto yy102;
	default:	goto yy35;
	}
yy35:
#line 136 "mojoshader_lexer.re"
	{ RET('.'); }
#line 350 "<stdout>"
yy36:
	++YYCURSOR;
	switch ((yych = *YYCURSOR)) {
	case '*':	goto yy105;
	case '/':	goto yy107;
	case '=':	goto yy109;
	default:	goto yy37;
	}
yy37:
#line 144 "mojoshader_lexer.re"
	{ RET('/'); }
#line 362 "<stdout>"
yy38:
	yyaccept = 1;
	yych = *(YYMARKER = ++YYCURSOR);
	switch (yych) {
	case '.':	goto yy102;
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	goto yy40;
	case 'E':
	case 'e':	goto yy111;
	case 'L':
	case 'U':
	case 'l':
	case 'u':	goto yy112;
	case 'X':
	case 'x':	goto yy114;
	default:	goto yy39;
	}
yy39:
#line 102 "mojoshader_lexer.re"
	{ RET(TOKEN_INT_LITERAL); }
#line 391 "<stdout>"
yy40:
	yyaccept = 1;
	YYMARKER = ++YYCURSOR;
	if ((YYLIMIT - YYCURSOR) < 3) YYFILL(3);
	yych = *YYCURSOR;
	switch (yych) {
	case '.':	goto yy102;
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	goto yy40;
	case 'E':
	case 'e':	goto yy111;
	case 'L':
	case 'U':
	case 'l':
	case 'u':	goto yy112;
	default:	goto yy39;
	}
yy42:
	++YYCURSOR;
#line 150 "mojoshader_lexer.re"
	{ RET(':'); }
#line 421 "<stdout>"
yy44:
	++YYCURSOR;
#line 156 "mojoshader_lexer.re"
	{ if (s->asm_comments) goto singlelinecomment; RET(';'); }
#line 426 "<stdout>"
yy46:
	++YYCURSOR;
	switch ((yych = *YYCURSOR)) {
	case '<':	goto yy115;
	case '=':	goto yy117;
	default:	goto yy47;
	}
yy47:
#line 146 "mojoshader_lexer.re"
	{ RET('<'); }
#line 437 "<stdout>"
yy48:
	++YYCURSOR;
	switch ((yych = *YYCURSOR)) {
	case '=':	goto yy119;
	default:	goto yy49;
	}
yy49:
#line 153 "mojoshader_lexer.re"
	{ RET('='); }
#line 447 "<stdout>"
yy50:
	++YYCURSOR;
	switch ((yych = *YYCURSOR)) {
	case '=':	goto yy121;
	case '>':	goto yy123;
	default:	goto yy51;
	}
yy51:
#line 147 "mojoshader_lexer.re"
	{ RET('>'); }
#line 458 "<stdout>"
yy52:
	++YYCURSOR;
#line 154 "mojoshader_lexer.re"
	{ RET('?'); }
#line 463 "<stdout>"
yy54:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	switch (yych) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':
	case '_':
	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':	goto yy54;
	default:	goto yy56;
	}
yy56:
#line 98 "mojoshader_lexer.re"
	{ RET(TOKEN_IDENTIFIER); }
#line 537 "<stdout>"
yy57:
	++YYCURSOR;
#line 134 "mojoshader_lexer.re"
	{ RET('['); }
#line 542 "<stdout>"
yy59:
	yyaccept = 0;
	yych = *(YYMARKER = ++YYCURSOR);
	switch (yych) {
	case '\t':
	case '\n':
	case '\v':
	case '\f':
	case '\r':
	case ' ':	goto yy126;
	default:	goto yy5;
	}
yy60:
	++YYCURSOR;
#line 135 "mojoshader_lexer.re"
	{ RET(']'); }
#line 559 "<stdout>"
yy62:
	++YYCURSOR;
	switch ((yych = *YYCURSOR)) {
	case '=':	goto yy130;
	default:	goto yy63;
	}
yy63:
#line 148 "mojoshader_lexer.re"
	{ RET('^'); }
#line 569 "<stdout>"
yy64:
	++YYCURSOR;
#line 151 "mojoshader_lexer.re"
	{ RET('{'); }
#line 574 "<stdout>"
yy66:
	++YYCURSOR;
	switch ((yych = *YYCURSOR)) {
	case '=':	goto yy132;
	case '|':	goto yy134;
	default:	goto yy67;
	}
yy67:
#line 149 "mojoshader_lexer.re"
	{ RET('|'); }
#line 585 "<stdout>"
yy68:
	++YYCURSOR;
#line 152 "mojoshader_lexer.re"
	{ RET('}'); }
#line 590 "<stdout>"
yy70:
	++YYCURSOR;
#line 140 "mojoshader_lexer.re"
	{ RET('~'); }
#line 595 "<stdout>"
yy72:
	++YYCURSOR;
#line 129 "mojoshader_lexer.re"
	{ RET(TOKEN_NEQ); }
#line 600 "<stdout>"
yy74:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
yy75:
	switch (yych) {
	case '\n':
	case '\r':	goto yy76;
	case '"':	goto yy77;
	case '\\':	goto yy79;
	default:	goto yy74;
	}
yy76:
	YYCURSOR = YYMARKER;
	switch (yyaccept) {
	case 0: 	goto yy5;
	case 1: 	goto yy39;
	default:	goto yy104;
	}
yy77:
	++YYCURSOR;
#line 108 "mojoshader_lexer.re"
	{ RET(TOKEN_STRING_LITERAL); }
#line 624 "<stdout>"
yy79:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	switch (yych) {
	case '"':
	case '\'':
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '?':
	case '\\':
	case 'a':
	case 'b':
	case 'f':
	case 'n':
	case 'r':
	case 't':
	case 'v':	goto yy74;
	case 'x':	goto yy136;
	default:	goto yy76;
	}
yy80:
	++YYCURSOR;
#line 131 "mojoshader_lexer.re"
	{ RET(TOKEN_HASHHASH); }
#line 656 "<stdout>"
yy82:
	++YYCURSOR;
#line 116 "mojoshader_lexer.re"
	{ RET(TOKEN_MODASSIGN); }
#line 661 "<stdout>"
yy84:
	++YYCURSOR;
#line 124 "mojoshader_lexer.re"
	{ RET(TOKEN_ANDAND); }
#line 666 "<stdout>"
yy86:
	++YYCURSOR;
#line 118 "mojoshader_lexer.re"
	{ RET(TOKEN_ANDASSIGN); }
#line 671 "<stdout>"
yy88:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
yy89:
	switch (yych) {
	case '\n':
	case '\r':	goto yy76;
	case '\'':	goto yy90;
	case '\\':	goto yy91;
	default:	goto yy88;
	}
yy90:
	yych = *++YYCURSOR;
	goto yy39;
yy91:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	switch (yych) {
	case '"':
	case '\'':
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '?':
	case '\\':
	case 'a':
	case 'b':
	case 'f':
	case 'n':
	case 'r':
	case 't':
	case 'v':	goto yy88;
	case 'x':	goto yy137;
	default:	goto yy76;
	}
yy92:
	++YYCURSOR;
#line 114 "mojoshader_lexer.re"
	{ RET(TOKEN_MULTASSIGN); }
#line 718 "<stdout>"
yy94:
	++YYCURSOR;
#line 120 "mojoshader_lexer.re"
	{ RET(TOKEN_INCREMENT); }
#line 723 "<stdout>"
yy96:
	++YYCURSOR;
#line 112 "mojoshader_lexer.re"
	{ RET(TOKEN_ADDASSIGN); }
#line 728 "<stdout>"
yy98:
	++YYCURSOR;
#line 121 "mojoshader_lexer.re"
	{ RET(TOKEN_DECREMENT); }
#line 733 "<stdout>"
yy100:
	++YYCURSOR;
#line 113 "mojoshader_lexer.re"
	{ RET(TOKEN_SUBASSIGN); }
#line 738 "<stdout>"
yy102:
	yyaccept = 2;
	YYMARKER = ++YYCURSOR;
	if ((YYLIMIT - YYCURSOR) < 3) YYFILL(3);
	yych = *YYCURSOR;
	switch (yych) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	goto yy102;
	case 'E':
	case 'e':	goto yy111;
	case 'F':
	case 'H':
	case 'f':
	case 'h':	goto yy138;
	default:	goto yy104;
	}
yy104:
#line 105 "mojoshader_lexer.re"
	{ RET(TOKEN_FLOAT_LITERAL); }
#line 766 "<stdout>"
yy105:
	++YYCURSOR;
#line 95 "mojoshader_lexer.re"
	{ goto multilinecomment; }
#line 771 "<stdout>"
yy107:
	++YYCURSOR;
#line 96 "mojoshader_lexer.re"
	{ goto singlelinecomment; }
#line 776 "<stdout>"
yy109:
	++YYCURSOR;
#line 115 "mojoshader_lexer.re"
	{ RET(TOKEN_DIVASSIGN); }
#line 781 "<stdout>"
yy111:
	yych = *++YYCURSOR;
	switch (yych) {
	case '+':
	case '-':	goto yy139;
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	goto yy140;
	default:	goto yy76;
	}
yy112:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	switch (yych) {
	case 'L':
	case 'U':
	case 'l':
	case 'u':	goto yy112;
	default:	goto yy39;
	}
yy114:
	yych = *++YYCURSOR;
	switch (yych) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':	goto yy142;
	default:	goto yy76;
	}
yy115:
	++YYCURSOR;
	switch ((yych = *YYCURSOR)) {
	case '=':	goto yy144;
	default:	goto yy116;
	}
yy116:
#line 123 "mojoshader_lexer.re"
	{ RET(TOKEN_LSHIFT); }
#line 846 "<stdout>"
yy117:
	++YYCURSOR;
#line 126 "mojoshader_lexer.re"
	{ RET(TOKEN_LEQ); }
#line 851 "<stdout>"
yy119:
	++YYCURSOR;
#line 128 "mojoshader_lexer.re"
	{ RET(TOKEN_EQL); }
#line 856 "<stdout>"
yy121:
	++YYCURSOR;
#line 127 "mojoshader_lexer.re"
	{ RET(TOKEN_GEQ); }
#line 861 "<stdout>"
yy123:
	++YYCURSOR;
	switch ((yych = *YYCURSOR)) {
	case '=':	goto yy146;
	default:	goto yy124;
	}
yy124:
#line 122 "mojoshader_lexer.re"
	{ RET(TOKEN_RSHIFT); }
#line 871 "<stdout>"
yy125:
	++YYCURSOR;
	if ((YYLIMIT - YYCURSOR) < 2) YYFILL(2);
	yych = *YYCURSOR;
yy126:
	switch (yych) {
	case '\t':
	case '\v':
	case '\f':
	case ' ':	goto yy125;
	case '\n':	goto yy127;
	case '\r':	goto yy129;
	default:	goto yy76;
	}
yy127:
	++YYCURSOR;
yy128:
#line 93 "mojoshader_lexer.re"
	{ s->line++; goto scanner_loop; }
#line 891 "<stdout>"
yy129:
	yych = *++YYCURSOR;
	switch (yych) {
	case '\n':	goto yy127;
	default:	goto yy128;
	}
yy130:
	++YYCURSOR;
#line 117 "mojoshader_lexer.re"
	{ RET(TOKEN_XORASSIGN); }
#line 902 "<stdout>"
yy132:
	++YYCURSOR;
#line 119 "mojoshader_lexer.re"
	{ RET(TOKEN_ORASSIGN); }
#line 907 "<stdout>"
yy134:
	++YYCURSOR;
#line 125 "mojoshader_lexer.re"
	{ RET(TOKEN_OROR); }
#line 912 "<stdout>"
yy136:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	switch (yych) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':	goto yy74;
	default:	goto yy76;
	}
yy137:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	switch (yych) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':	goto yy88;
	default:	goto yy76;
	}
yy138:
	yych = *++YYCURSOR;
	goto yy104;
yy139:
	yych = *++YYCURSOR;
	switch (yych) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	goto yy140;
	default:	goto yy76;
	}
yy140:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	switch (yych) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	goto yy140;
	case 'F':
	case 'H':
	case 'f':
	case 'h':	goto yy138;
	default:	goto yy104;
	}
yy142:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	switch (yych) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':	goto yy142;
	case 'L':
	case 'U':
	case 'l':
	case 'u':	goto yy112;
	default:	goto yy39;
	}
yy144:
	++YYCURSOR;
#line 111 "mojoshader_lexer.re"
	{ RET(TOKEN_LSHIFTASSIGN); }
#line 1047 "<stdout>"
yy146:
	++YYCURSOR;
#line 110 "mojoshader_lexer.re"
	{ RET(TOKEN_RSHIFTASSIGN); }
#line 1052 "<stdout>"
}
#line 163 "mojoshader_lexer.re"


multilinecomment:
    if (YYLIMIT == YYCURSOR) YYFILL(1);
    matchptr = cursor;
// The "*\/" is just to avoid screwing up text editor syntax highlighting.

#line 1062 "<stdout>"
{
	YYCTYPE yych;
	if ((YYLIMIT - YYCURSOR) < 2) YYFILL(2);
	yych = *YYCURSOR;
	switch (yych) {
	case 0x00:	goto yy150;
	case '\n':	goto yy154;
	case '\r':	goto yy156;
	case '*':	goto yy157;
	default:	goto yy152;
	}
yy150:
	++YYCURSOR;
#line 193 "mojoshader_lexer.re"
	{
                        if (eoi)
                            RET(TOKEN_INCOMPLETE_COMMENT);
                        goto multilinecomment;
                    }
#line 1082 "<stdout>"
yy152:
	++YYCURSOR;
yy153:
#line 198 "mojoshader_lexer.re"
	{ goto multilinecomment; }
#line 1088 "<stdout>"
yy154:
	++YYCURSOR;
yy155:
#line 189 "mojoshader_lexer.re"
	{
                        s->line++;
                        goto multilinecomment;
                    }
#line 1097 "<stdout>"
yy156:
	yych = *++YYCURSOR;
	switch (yych) {
	case '\n':	goto yy154;
	default:	goto yy155;
	}
yy157:
	yych = *++YYCURSOR;
	switch (yych) {
	case '/':	goto yy158;
	default:	goto yy153;
	}
yy158:
	++YYCURSOR;
#line 170 "mojoshader_lexer.re"
	{
                        if (s->report_comments)
                            RET(TOKEN_MULTI_COMMENT);
                        else if (s->report_whitespace)
                            RET(' ');

                        // Microsoft's preprocessor allows multiline comments
                        //  before a preprocessor directive, even though C/C++
                        //  doesn't. See if we've hit this case.
                        #if MATCH_MICROSOFT_PREPROCESSOR
                        if (s->tokenval == ((Token) '\n'))  // was start of line?
                        {
                            update_state(s, eoi, cursor, token, (Token) '\n');
                            goto ppdirective;  // may jump back to scanner_loop.
                        }
                        #endif

                        goto scanner_loop;
                    }
#line 1132 "<stdout>"
}
#line 199 "mojoshader_lexer.re"


singlelinecomment:
    if (YYLIMIT == YYCURSOR) YYFILL(1);
    matchptr = cursor;

#line 1141 "<stdout>"
{
	YYCTYPE yych;
	if ((YYLIMIT - YYCURSOR) < 2) YYFILL(2);
	yych = *YYCURSOR;
	switch (yych) {
	case 0x00:	goto yy162;
	case '\n':	goto yy166;
	case '\r':	goto yy168;
	default:	goto yy164;
	}
yy162:
	++YYCURSOR;
#line 215 "mojoshader_lexer.re"
	{
                        if (eoi)
                        {
                            if (s->report_comments)
                                RET(TOKEN_SINGLE_COMMENT);
                            else
                                RET(TOKEN_EOI);
                        }
                        goto singlelinecomment;
                    }
#line 1165 "<stdout>"
yy164:
	++YYCURSOR;
#line 225 "mojoshader_lexer.re"
	{ goto singlelinecomment; }
#line 1170 "<stdout>"
yy166:
	++YYCURSOR;
yy167:
#line 205 "mojoshader_lexer.re"
	{
                        s->line++;
                        if (s->report_comments)
                        {
                            cursor = matchptr;  // so we RET('\n') next.
                            RET(TOKEN_SINGLE_COMMENT);
                        }
                        token = matchptr;
                        RET('\n');
                    }
#line 1185 "<stdout>"
yy168:
	++YYCURSOR;
	switch ((yych = *YYCURSOR)) {
	case '\n':	goto yy166;
	default:	goto yy167;
	}
}
#line 226 "mojoshader_lexer.re"


ppdirective:
    if (YYLIMIT == YYCURSOR) YYFILL(1);

#line 1199 "<stdout>"
{
	YYCTYPE yych;
	unsigned int yyaccept = 0;
	if ((YYLIMIT - YYCURSOR) < 10) YYFILL(10);
	yych = *YYCURSOR;
	switch (yych) {
	case '\t':
	case '\v':
	case '\f':
	case ' ':	goto yy173;
	case '#':	goto yy176;
	default:	goto yy171;
	}
yy171:
	++YYCURSOR;
yy172:
#line 247 "mojoshader_lexer.re"
	{
                            token = cursor = (const uchar *) s->source;
                            limit = cursor + s->bytes_left;
                            goto scanner_loop;
                        }
#line 1222 "<stdout>"
yy173:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	switch (yych) {
	case '\t':
	case '\v':
	case '\f':
	case ' ':	goto yy173;
	default:	goto yy175;
	}
yy175:
#line 245 "mojoshader_lexer.re"
	{ goto ppdirective; }
#line 1237 "<stdout>"
yy176:
	yyaccept = 0;
	yych = *(YYMARKER = ++YYCURSOR);
	switch (yych) {
	case '\t':
	case ' ':
	case 'd':
	case 'e':
	case 'i':
	case 'l':
	case 'p':
	case 'u':
	case 'v':	goto yy178;
	default:	goto yy172;
	}
yy177:
	++YYCURSOR;
	if ((YYLIMIT - YYCURSOR) < 9) YYFILL(9);
	yych = *YYCURSOR;
yy178:
	switch (yych) {
	case '\t':
	case ' ':	goto yy177;
	case 'd':	goto yy180;
	case 'e':	goto yy181;
	case 'i':	goto yy182;
	case 'l':	goto yy183;
	case 'p':	goto yy184;
	case 'u':	goto yy185;
	case 'v':	goto yy186;
	default:	goto yy179;
	}
yy179:
	YYCURSOR = YYMARKER;
	if (yyaccept == 0) {
		goto yy172;
	} else {
		goto yy193;
	}
yy180:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'e':	goto yy187;
	default:	goto yy179;
	}
yy181:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'l':	goto yy188;
	case 'n':	goto yy189;
	case 'r':	goto yy190;
	case 'x':	goto yy191;
	default:	goto yy179;
	}
yy182:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'f':	goto yy192;
	case 'n':	goto yy194;
	default:	goto yy179;
	}
yy183:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'i':	goto yy195;
	default:	goto yy179;
	}
yy184:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'r':	goto yy196;
	default:	goto yy179;
	}
yy185:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'n':	goto yy197;
	default:	goto yy179;
	}
yy186:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'e':	goto yy198;
	default:	goto yy179;
	}
yy187:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'f':	goto yy199;
	default:	goto yy179;
	}
yy188:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'i':	goto yy200;
	case 's':	goto yy201;
	default:	goto yy179;
	}
yy189:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'd':	goto yy202;
	default:	goto yy179;
	}
yy190:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'r':	goto yy203;
	default:	goto yy179;
	}
yy191:
	yych = *++YYCURSOR;
	switch (yych) {
	case 't':	goto yy204;
	default:	goto yy179;
	}
yy192:
	yyaccept = 1;
	yych = *(YYMARKER = ++YYCURSOR);
	switch (yych) {
	case 'd':	goto yy205;
	case 'n':	goto yy206;
	default:	goto yy193;
	}
yy193:
#line 235 "mojoshader_lexer.re"
	{ RET(TOKEN_PP_IF); }
#line 1365 "<stdout>"
yy194:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'c':	goto yy207;
	default:	goto yy179;
	}
yy195:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'n':	goto yy208;
	default:	goto yy179;
	}
yy196:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'a':	goto yy209;
	default:	goto yy179;
	}
yy197:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'd':	goto yy210;
	default:	goto yy179;
	}
yy198:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'r':	goto yy211;
	default:	goto yy179;
	}
yy199:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'i':	goto yy212;
	default:	goto yy179;
	}
yy200:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'f':	goto yy213;
	default:	goto yy179;
	}
yy201:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'e':	goto yy215;
	default:	goto yy179;
	}
yy202:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'i':	goto yy217;
	default:	goto yy179;
	}
yy203:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'o':	goto yy218;
	default:	goto yy179;
	}
yy204:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'e':	goto yy219;
	default:	goto yy179;
	}
yy205:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'e':	goto yy220;
	default:	goto yy179;
	}
yy206:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'd':	goto yy221;
	default:	goto yy179;
	}
yy207:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'l':	goto yy222;
	default:	goto yy179;
	}
yy208:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'e':	goto yy223;
	default:	goto yy179;
	}
yy209:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'g':	goto yy225;
	default:	goto yy179;
	}
yy210:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'e':	goto yy226;
	default:	goto yy179;
	}
yy211:
	yych = *++YYCURSOR;
	switch (yych) {
	case 's':	goto yy227;
	default:	goto yy179;
	}
yy212:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'n':	goto yy228;
	default:	goto yy179;
	}
yy213:
	++YYCURSOR;
#line 239 "mojoshader_lexer.re"
	{ RET(TOKEN_PP_ELIF); }
#line 1484 "<stdout>"
yy215:
	++YYCURSOR;
#line 238 "mojoshader_lexer.re"
	{ RET(TOKEN_PP_ELSE); }
#line 1489 "<stdout>"
yy217:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'f':	goto yy229;
	default:	goto yy179;
	}
yy218:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'r':	goto yy231;
	default:	goto yy179;
	}
yy219:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'n':	goto yy233;
	default:	goto yy179;
	}
yy220:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'f':	goto yy234;
	default:	goto yy179;
	}
yy221:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'e':	goto yy236;
	default:	goto yy179;
	}
yy222:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'u':	goto yy237;
	default:	goto yy179;
	}
yy223:
	++YYCURSOR;
#line 232 "mojoshader_lexer.re"
	{ RET(TOKEN_PP_LINE); }
#line 1530 "<stdout>"
yy225:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'm':	goto yy238;
	default:	goto yy179;
	}
yy226:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'f':	goto yy239;
	default:	goto yy179;
	}
yy227:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'i':	goto yy241;
	default:	goto yy179;
	}
yy228:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'e':	goto yy242;
	default:	goto yy179;
	}
yy229:
	++YYCURSOR;
#line 240 "mojoshader_lexer.re"
	{ RET(TOKEN_PP_ENDIF); }
#line 1559 "<stdout>"
yy231:
	++YYCURSOR;
#line 241 "mojoshader_lexer.re"
	{ RET(TOKEN_PP_ERROR); }
#line 1564 "<stdout>"
yy233:
	yych = *++YYCURSOR;
	switch (yych) {
	case 's':	goto yy244;
	default:	goto yy179;
	}
yy234:
	++YYCURSOR;
#line 236 "mojoshader_lexer.re"
	{ RET(TOKEN_PP_IFDEF); }
#line 1575 "<stdout>"
yy236:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'f':	goto yy245;
	default:	goto yy179;
	}
yy237:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'd':	goto yy247;
	default:	goto yy179;
	}
yy238:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'a':	goto yy248;
	default:	goto yy179;
	}
yy239:
	++YYCURSOR;
#line 234 "mojoshader_lexer.re"
	{ RET(TOKEN_PP_UNDEF); }
#line 1598 "<stdout>"
yy241:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'o':	goto yy250;
	default:	goto yy179;
	}
yy242:
	++YYCURSOR;
#line 233 "mojoshader_lexer.re"
	{ RET(TOKEN_PP_DEFINE); }
#line 1609 "<stdout>"
yy244:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'i':	goto yy251;
	default:	goto yy179;
	}
yy245:
	++YYCURSOR;
#line 237 "mojoshader_lexer.re"
	{ RET(TOKEN_PP_IFNDEF); }
#line 1620 "<stdout>"
yy247:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'e':	goto yy252;
	default:	goto yy179;
	}
yy248:
	++YYCURSOR;
#line 242 "mojoshader_lexer.re"
	{ RET(TOKEN_PP_PRAGMA); }
#line 1631 "<stdout>"
yy250:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'n':	goto yy254;
	default:	goto yy179;
	}
yy251:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'o':	goto yy256;
	default:	goto yy179;
	}
yy252:
	++YYCURSOR;
#line 231 "mojoshader_lexer.re"
	{ RET(TOKEN_PP_INCLUDE); }
#line 1648 "<stdout>"
yy254:
	++YYCURSOR;
#line 244 "mojoshader_lexer.re"
	{ RET(TOKEN_PP_VERSION); }
#line 1653 "<stdout>"
yy256:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'n':	goto yy257;
	default:	goto yy179;
	}
yy257:
	++YYCURSOR;
#line 243 "mojoshader_lexer.re"
	{ RET(TOKEN_PP_EXTENSION); }
#line 1664 "<stdout>"
}
#line 252 "mojoshader_lexer.re"


bad_chars:
    if (YYLIMIT == YYCURSOR) YYFILL(1);

#line 1672 "<stdout>"
{
	YYCTYPE yych;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	switch (yych) {
	case 0x00:	goto yy261;
	case '\t':
	case '\n':
	case '\v':
	case '\f':
	case '\r':
	case ' ':
	case '!':
	case '#':
	case '%':
	case '&':
	case '\'':
	case '(':
	case ')':
	case '*':
	case '+':
	case ',':
	case '-':
	case '.':
	case '/':
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	case ':':
	case ';':
	case '<':
	case '=':
	case '>':
	case '?':
	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':
	case '[':
	case '\\':
	case ']':
	case '^':
	case '_':
	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':
	case '{':
	case '|':
	case '}':
	case '~':	goto yy265;
	default:	goto yy263;
	}
yy261:
	++YYCURSOR;
#line 258 "mojoshader_lexer.re"
	{
                        if (eoi)
                        {
                            assert( !((token >= sentinel) &&
                                     (token < sentinel+YYMAXFILL)) );
                            eoi = 0;
                            cursor = (uchar *) s->source_base + s->orig_length;
                            RET(TOKEN_BAD_CHARS);  // next call will be EOI.
                        }
                        goto bad_chars;
                    }
#line 1791 "<stdout>"
yy263:
	++YYCURSOR;
#line 270 "mojoshader_lexer.re"
	{ goto bad_chars; }
#line 1796 "<stdout>"
yy265:
	++YYCURSOR;
#line 257 "mojoshader_lexer.re"
	{ cursor--; RET(TOKEN_BAD_CHARS); }
#line 1801 "<stdout>"
}
#line 271 "mojoshader_lexer.re"


    assert(0 && "Shouldn't hit this code");
    RET(TOKEN_UNKNOWN);
} // preprocessor_lexer

// end of mojoshader_lexer.re (or .c) ...

