#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *stpcpy(char *dest, const char *src);
#define FONT_HEIGHT 16
#define FONT_WIDTH 8
#define TAB_WIDTH 32
#define TAB_PATH(x) "m" #x " 0"
#define ICON_HEIGHT 96
#define ICON_WIDTH 96


static const char *char_paths[96] = {
	/*   */	"m8 0",
	/* ! */	"m4 2v10m0 1v1m4-14",
	/* " */	"m3 3v3m2-3v3m3-6",
	/* # */	"m2 4v8m4-8v8m-5-2h6m-6-4h6m1-6",
	/* $ */	"m2 12a2 3 0 1 0 2-4a2 3 0 1 1 2-4m-2-3v14m4-15",
	/* % */	"m2 2v1m4-1l-4 12m4-1v1m2-14",
	/* & */	"m6 4a2 2 0 1 0-3 3a3 3 0 1 0 4 4m0 2l-4-6m5-7",
	/* ' */	"m4 3v3m4-6",
	/* ( */	"m4 14q-3-6 0-12m4-2",
	/* ) */	"m4 14q3-6 0-12m4-2",
	/* * */	"m1 8h6m-1 4l-4-8m2 0v8m-2 0l4-8m2-4",
	/* + */	"m1 8h6m-3-4v8m4-12",
	/* , */	"m5 11v1l-2 2m5-14",
	/* - */	"m2 8h4m2-8",
	/* . */	"m4 11v1m4-12",
	/* / */	"m2 14l4-12m2-2",
	/* 0 */	"m2 7a2 4 0 1 1 4 0v2a2 4 0 1 1-4 0zm2 0v2m4-9.1",
	/* 1 */	"m3 4l1-1v11m4-14",
	/* 2 */	"m2 4a2 3 0 1 1 3 5l-3 4h4m2-13",
	/* 3 */	"m2 4a2 2 0 1 1 1 3m0 0a2 3 0 1 1-1 4m6-11",
	/* 4 */	"m2 2v6h4v6-12l2-2",
	/* 5 */	"m2 14h2a2 2 0 1 0 -2-6v-5h4m2-3",
	/* 6 */	"m3 8a2 3 0 1 1 -1 1l4-7m2-2",
	/* 7 */	"m2 3h4l-4 11m6-14",
	/* 8 */	"m3.5 7a2 2 0 1 1 1 0a2 3 0 1 1 -1 0zm4.5-7",
	/* 9 */	"m2 14l4-6a2 3 0 1 0 -1 1m3-9",
	/* : */	"m4 4v1m0 4v1m4-10",
	/* ; */	"m4 4v1m0 4q0 1-1 1m5-10",
	/* < */	"m6 12l-4-4 4-4m2-4",
	/* = */	"m2 6h4m-4 3h4m2-9",
	/* > */	"m2 12l4-4-4-4m6-4",
	/* ? */	"m2 6a2 2 0 1 1 2 2v2m0 1v1m4-12",
	/* @ */	"m5 8a1 1 0 1 1 0 -1a1 2 0 1 0 2-0a3 4 0 1 0 -2 4m3-11",
	/* A */	"m1 14l3-12l3 12m-1-4h-4m6-10",
	/* B */	"m2 2a3 2 0 1 1 0 5a2.5 2 0 1 1 0 7zm6-2",
	/* C */	"m6 4a2.5 6 0 1 0 0 8m2-12",
	/* D */	"m2 2a4 6 0 1 1 0 12zm6-2",
	/* E */	"m6 14h-4v-12h4m-4 6h3m3-8",
	/* F */	"m2 14v-12h4m-4 6h3m3-8",
	/* G */	"m6 4a2.5 6 0 1 0 0 8v-2h-1m3-10",
	/* H */	"m2 2v12-6h4v6-12m2-2",
	/* I */	"m2 2h4-2v12h2-4m6-14",
	/* J */	"m4 2h2v8q0 4-4 4m6-14",
	/* K */	"m2 2v12-7l4 7-4-7 4-5m2-2",
	/* L */	"m2 2v12h4m2-14",
	/* M */	"m2 14v-12l2 6 2-6v12m2-14",
	/* N */	"m2 14v-12l4 12v-12m2-2",
	/* O */	"m6 8a2 6 0 1 0 0 .1zm2-8.1",
	/* P */	"m2 2a3 2 0 1 1 0 5v7zm6-2",
	/* Q */	"m6 8a2 6 0 1 0 0 .1zm-2-1.1l3 7m1-14",
	/* R */	"m2 14v-12a3 2 0 1 1 0 5l4 7m2-14",
	/* S */	"m2 12a2 3 0 1 0 2-4a2 3 0 1 1 2-4m2-4",
	/* T */	"m1 2h6-3v12m4-14",
	/* U */	"m2 2v10q2 4 4 0v-10m2-2",
	/* V */	"m2 2l2 12 2-12m2-2",
	/* W */	"m2 2l1 12 1-6 1 6 1-12m2-2",
	/* X */	"m2 2l4 12m-4 0l4-12m2-2",
	/* Y */	"m2 2l2 6v6-6l2-6m2-2",
	/* Z */	"m6 14h-4l4-12h-4m6-2",
	/* [ */	"m5 14h-2v-12h2m3-2",
	/* \ */	"m2 2l4 12m2-14",
	/* ] */	"m3 14h2v-12h-2m5-2",
	/* ^ */	"m2 5l2-2 2 2m2-5",
	/* _ */	"m1 15h6m1-15",
	/* ` */	"m3 4l2 1m3-5",
	/* a */	"m6 9a2 3 0 1 0 0 3v2-7m2-7",
	/* b */	"m2 9a2 3 0 1 1 0 3v2-12m6-2",
	/* c */	"m6 9a2 3 0 1 0 0 3m2-12",
	/* d */	"m6 9a2 3 0 1 0 0 3v2-12m2-2",
	/* e */	"m6 12a2 3 0 1 1 0-2h-4m6-10",
	/* f */	"m2 14v-6h2-2q0-4 4-4m2-4",
	/* g */	"m6 11a2 3 0 1 1 0-3a2 4 0 1 1-4 6m6-14",
	/* h */	"m2 2v12-4a2 2 0 1 1 4 0v4m2-14",
	/* i */	"m4 6v1m0 1v6m4-13",
	/* j */	"m4 6v1m0 1v5q0 2-2 2m6-15",
	/* k */	"m2 2v12-4l4 4-4-4 4-2m2-8",
	/* l */	"m4 2v12m4-14",
	/* m */	"m2 8v6-4a1 2 0 1 1 2 0v4-4a1 2 0 1 1 2 0v4m2-14",
	/* n */	"m2 8v6-4a2 2 0 1 1 4 0v4m2-14",
	/* o */	"m6 10a2 3 0 1 0 0 .1zm2-10.1",
	/* p */	"m2 9a2 3 0 1 1 0 3v4-8m6-8",
	/* q */	"m6 9a2 3 0 1 0 0 3v5-9m2-8",
	/* r */	"m2 8v6-4a2 2 0 1 1 4 0m2-10",
	/* s */	"m2 13a2 1 0 0 0 2-3a2 1 0 0 1 2-2m2-8",
	/* t */	"m4 6v8-6h2-4m6-8",
	/* u */	"m2 8v4a2 2 0 1 0 4 0v2-6m2-8",
	/* v */	"m2 8l2 6 2-6m2-8",
	/* w */	"m2 8l1 6 1-4 1 4 1-6m2-8",
	/* x */	"m2 8l4 6m-4 0l4-6m2-8",
	/* y */	"m2 8l2 4l2-4-4 8m6-16",
	/* z */	"m2 8h4l-4 6h4m2-14",
	/* { */	"m5 14a1 6 0 0 1-1-5l-1-1 1-1a1 6 0 0 1 1-5m3-2",
	/* | */	"m4 14v-12m4-2",
	/* } */	"m3 14a1 6 0 0 0 1-5l1-1-1-1a1 6 0 0 0 -1-5m5-2",
	/* ~ */	"m2 4q1-1 2 0t2 0m2-4",
	/*???*/	"m1 1h6v14h-6zm7-1"
};


#define ICON_MAP(OP) /* OP(name, path) */ \
	OP(AtoZ,	"m12 72h12l2-12h12l2 12h12l-12-48h-18zm22-24h-6l3-12zm16-6h8v6h-8zm22-6h-16v-12h30v12l-16 24h16v12h-30v-12z")  \
	OP(GT_left,	"m28 6v12l18 30-18 30v12l26-42z")  \
	OP(GT_right,	"m68 6v12l18 30-18 30v12l26-42z")  \
	OP(LT_left,	"m28 6v12l-18 30 18 30v12l-26-42z")  \
	OP(LT_right,	"m68 6v12l-18 30 18 30v12l-26-42z")  \
	OP(X,	"m12 24l12-12 24 24 24-24 12 12-24 24 24 24-12 12-24-24-24 24-12-12 24-24z")  \
	OP(arrow_down,	"m30 48h12v-12h12v12h12l-18 24z")  \
	OP(arrow_left,	"m48 30v12h12v12h-12v12l-24-18z")  \
	OP(arrow_right,	"m48 30v12h-12v12h12v12l24-18z")  \
	OP(arrow_up,	"m48 30l18 24h-12v12h-12v-12h-12z")  \
	OP(articulated_spline,	"m15 15q12 32 32 32t34 34l-12 8q-24-24-24-48t-24-32m-5 9l8-8m0 24l16-12m8 36l9-9m0 26l16-9")  \
	OP(at,	"m57 47c0 16 -21 16 -21 0s21-16 21 0zm8 17c-17 15 -41 4 -41-16c0 -30 46 -30 46-3c0 10-6 14-13 14v-24")  \
	OP(bar_bottom,	"m18 78h60v6h-60z")  \
	OP(bar_left,	"m12 18h6v60h-6z")  \
	OP(bar_right,	"m78 18h6v60h-6z")  \
	OP(bar_top,	"m18 12h60v6h-60z")  \
	OP(bluetooth,	"m48 48l-24 24 6 6 18-18 0 36 30-30-18-18 18-18-30-30 0 36-18-18-6 6zm8-8l0-19 9 9zm0 36l0-19 9 9z")  \
	OP(bulb,	"m36 68a32 32 0 1 1 24 0zv6h24v-6zh24v12h-24zv18h24v-18zm12-28q3 6 0 24z")  \
	OP(button_clear,	"m0 42q0-42 42-42h12q42 0 42 42v12q0 42-42 42h-12q-42 0-42-42zM0 48a48 48 0 1 0 0-0.1z")  \
	OP(calculator,	"m24 6v84h48v-84h-48zm6 6h36v24h-36v-24zm3 30h6v6h-6zm12 0h6v6h-6zm12 0h6v6h-6zm-24 12h6v6h-6zm12 0h6v6h-6zm12 0h6v6h-6zm-24 12h6v6h-6zm12 0h6v6h-6zm12 0h6v6h-6zm-24 12h6v6h-6zm12 0h6v6h-6zm12 0h6v6h-6z")  \
	OP(camera,	"m84 48c0 28-42 28-42 0s42-28 42 0zm-21-15c-7.5 0-15 5-15 15c0 20 30 20 30 0c0-10-7.5-15-15-15zm0 6c4.5 0 9 3 9 9c0 12-18 12-18 0c0-6 4.5-9 9-9zm-54-18v54h78v-54zm6 6h15v12h-15v-12z")  \
	OP(cd,	"m4 48a44 44 0 1 1 0 1zm39 1a5 5 0 1 0 0-1z")  \
	OP(circle,	"m0 47v1a48 48 0 1 0 0-1z")  \
	OP(cylinder,	"m24 8q24-6 48 0v80q-24 8-48 0z")  \
	OP(cylinder_reverse_large,	"m30 12v54q18 6 36 0v-54q-18 -4 -36 0z")  \
	OP(cylinder_reverse_max,	"m30 12v72q18 6 36 0v-72q-18 -4 -36 0z")  \
	OP(cylinder_reverse_med,	"m30 12v30q18 6 36 0v-30q-18 -4 -36 0z")  \
	OP(cylinder_reverse_small,	"m30 12v12q18 6 36 0v-12q-18 -4 -36 0z")  \
	OP(e2dots,	"m48 23c-46.5 0-40.5 88 25.5 61v-10c-20 8-43 8-43-15h46v-6c0-19-14.3-30-28.5-30zm18.5 27h-36c0-24 36-24 36 0zm5.5-37.5c0 8.5-14 8.5-14 0s14-8.5 14 0zm-34 0c0 8.5-14 8.5-14 0s14-8.5 14 0z")  \
	OP(e,	"m32 60h48a30 36 0 1 0-6 18l-6-12a9 8 0 1 1-36-6zm2-12a12 12 0 1 1 32 0z")  \
	OP(film,	"m14 14v68h68v-68zm6 6h6v6h-6zm0 12h6v6h-6zm0 12h6v6h-6zm0 12h6v6h-6zm0 12h6v6h-6zm50 -48h6v6h-6zm0 12h6v6h-6zm0 12h6v6h-6zm0 12h6v6h-6zm0 12h6v6h-6z")  \
	OP(flag,	"m12 80v-64h6v2h-2v2h70v48h-70v16")  \
	OP(flag_blank,	"m12 18q24 8 36 0t36 0v48q0-8-36 0t-36 0z")  \
	OP(globe,	"m48 1a47 47 0 1 0 0.1 0a18 47 0 1 0 0.1 0zm-41 24h82m-88 22h94m-88 24h82")  \
	OP(joypad,	"m80 12l-24 24 24 24a12 12 0 0 1 -24 24l-42-42a12 12 0 0 1 24-24l18 18m-24-12l-4-4-4 4-4-4-4 4 4 4-4 4 4 4 4-4 4 4 4-4-4-4zm32 28a4 4 0 1 0 1 1zm8 8a4 4 0 1 0 1 1zm-8 8a4 4 0 1 0 1 1zm-8-8a4 4 0 1 0 1 1z")  \
	OP(keyboard,	"m6 36v24q0 6 6 6h72q6 0 6-6v-24q0-6-6-6h-72q-6 0-6 6m6 0v3h3v-3m3 0v3h3v-3m1 0v3h3v-3m1 0v3h3v-3m1 0v3h3v-3m3 0v3h3v-3m1 0v3h3v-3m1 0v3h3v-3m1 0v3h3v-3m3 0v3h3v-3m1 0v3h3v-3m1 0v3h3v-3m1 0v3h3v-3m3 0v3h3v-3m1 0v3h3v-3m1 0v3h3v-3m-71 6v3h3v-3m1 0v3h3v-3m1 0v3h3v-3m1 0v3h3v-3m1 0v3h3v-3m1 0v3h3v-3m1 0v3h3v-3m1 0v3h3v-3m1 0v3h3v-3m1 0v3h3v-3m1 0v3h3v-3m1 0v3h3v-3m1 0v3h9v-3m3 0v3h3v-3m1 0v3h3v-3m1 0v3h3v-3m-71 4v3h5v-3m1 0v3h3v-3m1 0v3h3v-3m1 0v3h3v-3m1 0v3h3v-3m1 0v3h3v-3m1 0v3h3v-3m1 0v3h3v-3m1 0v3h3v-3m1 0v3h3v-3m1 0v3h3v-3m1 0v3h3v-3m1 0v3h7v-3m3 0v3h3v-3m1 0v3h3v-3m1 0v3h3v-3m-71 4v3h7v-3m1 0v3h3v-3m1 0v3h3v-3m1 0v3h3v-3m1 0v3h3v-3m1 0v3h3v-3m1 0v3h3v-3m1 0v3h3v-3m1 0v3h3v-3m1 0v3h3v-3m1 0v3h3v-3m1 0v3h9v-3m-57 4v3h9v-3m1 0v3h3v-3m1 0v3h3v-3m1 0v3h3v-3m1 0v3h3v-3m1 0v3h3v-3m1 0v3h3v-3m1 0v3h3v-3m1 0v3h3v-3m1 0v3h3v-3m1 0v3h11v-3m7 0v3h3v-3m-67 4v3h5v-3m1 0v3h4v-3m1 0v3h4v-3m1 0v3h24v-3m1 0v3h3v-3m1 0v3h3v-3m1 0v3h3v-3m1 0v3h4v-3m3 0v3h3v-3m1 0v3h3v-3m1 0v3h3v-3m-34-58v30")  \
	OP(key,	"m36 48a18 18 0 1 0 12 12l12-12 0-6 6 0 3-3 0 -4 2 0 0-2 4 0 0-4 4-4 0-12-6 0zm6 0l30-30m-36 48a6 6 0 1 1 -6 -6z")  \
	OP(laptop,	"m16 14h64v36h-64zm6 6v24h52v-24zm-6 32h64l6 16v4h-76v-4zm24 10l-2 5h18l-2-5z")  \
	OP(magazine,	"m12 24q24-8 36 0q24-8 36 0v48q0-8-36 0q0-8-36 0z")  \
	OP(menu,	"m24 18a6 6 0 1 0 0 12h48a6 6 0 1 0 0 -12zm0 24a6 6 0 1 0 0 12h48a6 6 0 1 0 0 -12zm0 24a6 6 0 1 0 0 12h48a6 6 0 1 0 0 -12z")  \
	OP(mic,	"m42 12a12 12 0 0 0-24 24l12 6 48 42 10-12-42-48zl-24 24z")  \
	OP(music_note,	"m68 29v25c0 10-16 10-17 8-1-3 3-8 11-8v-14l-18 3v17c0 10-16 11-17 8s3-8 11-8l0-26z")  \
	OP(notepad,	"m8 24v48h2v-48l24-6h2l-24 6v48h2v-48l24-6h2l-24 6v48h2v-48l24-6h2l-24 6q0 24 36 36l24-6q-24 0-36-36h-12l-24 6v48h12l24-6v-10q-23-9-24-32")  \
	OP(paperclip,	"m13 48l5 4l36-36c14-14 35 7 21 21l-41 41c-9 9-21-4-13-12l41-41c3-2 6 1 4 4l-36 36l5 4l36-36c8-8-5-21-13-13l-40 40c-18 18 6 37 21 22l40-40c20-20-10-50-30-30z")  \
	OP(paper,	"m66 6l18 72-48 6-18-72zm-40 12l32-4m-30 12l32-4m-30 12l32-4m-30 12l32-4m-30 12l32-4m-30 12l32-4z")  \
	OP(pencil,	"m48 72l12-12 12-48-12-6-12 48z")  \
	OP(phone,	"m48 2h-12a22 46 0 1 0 0 92h6v-24a18 24 0 1 1 0-48z")  \
	OP(puppy,	"m90 54c-2 56-82 56-84 0 0-2.9 1-6 1-9v-19c0-6 13-11 23-8 10-6 20-6 29-4h20c8 0 10 16 4 20 3 3 7 12 7 20m-12-12a6 6 0 1 0 1 1zm-36 6a12 12 0 1 0 1 1zm-1 0a6 6 0 1 0 1 1zm18 24l12-12-24 6zq6 6 18 -6q-12 12 -18 6 q-6 12-18 6q12 6 18-6m24-38q-6 6 -8 -6t-6-12m-40 2q6 12 -18 16")  \
	OP(puppy_outline,	"m90 54c-2 56-82 56-84 0 0-2.9 1-6 1-9v-19c0-6 13-11 23-8 10-6 20-6 29-4h20c8 0 10 16 4 20 3 3 7 12 7 20")  \
	OP(rect,	"m0 0h96v96h-96z")  \
	OP(rect_rounded2,	"m0 12q0-12 12-12h72q12 0 12 12v72q0 12-12 12h-72q-12 0-12-12z")  \
	OP(rect_rounded3,	"m0 18q0-18 18-18h60q18 0 18 18v60q0 18-18 18h-60q-18 0-18-18z")  \
	OP(rect_rounded4,	"m0 24q0-24 24-24h48q24 0 24 24v48q0 24-24 24h-48q-24 0-24-24z")  \
	OP(rect_rounded5,	"m0 30q0-30 30-30h36q30 0 30 30v36q0 30-30 30h-36q-30 0-30-30z")  \
	OP(rect_rounded6,	"m0 36q0-36 36-36h24q36 0 36 36v24q0 36-36 36h-24q-36 0-36-36z")  \
	OP(rect_rounded7,	"m0 42q0-42 42-42h12q42 0 42 42v12q0 42-42 42h-12q-42 0-42-42z")  \
	OP(rect_rounded8,	"m0 45q0-45 45-45h6q45 0 45 45v6q0 45-45 45h-6q-45 0-45-45z")  \
	OP(rect_rounded,	"m0 6q0-6 6-6h84q6 0 6 6v84q0 6-6 6h-84q-6 0-6-6z")  \
	OP(ribbon,	"m15 15q12 32 32 32t34 34l-12 8q-12-32-34-34t-28-28z")  \
	OP(slash,	"m48 6h12l-12 84h-12z")  \
	OP(touch_bottom,	"m0 96h96v-48a48 48 0 0 0-96 0z")  \
	OP(touch_left,	"m0 0h48a48 48 0 1 1 0 96h-48z")  \
	OP(touch_right,	"m48 96a48 48 0 0 1 0-96h48v96z")  \
	OP(touch_top,	"m0 0h96v48a48 48 0 0 1-96 0z")  \
	OP(triangle,	"m12 18v60h48zm28 50h-18v-24z")  \
	OP(umlaut,	"m32 6a6 6 0 1 0 1 0zm30 0a6 6 0 1 0 1 0z")  \
	OP(video_cam,	"m36 30c0 8-12 8-12 0s12-8 12 0zm-18-12v12c0-16 24-16 24 0v-12c0-16-24-16-24 0zm24 12c0 16-24 16-24 0v48c0 16.12 24 16.406 24 0zm0-6h6v-12h24c7 0 12 5 12 12v24h-36v-12h-6")  \
	OP(warn,	"m48 48l24 30h-48zm3 6h-6v12h6zm0 15h-6v6h6z")  \
	OP(wrench,	"m84 72q6 0 6-6l-42-42q6 -24-18-18l8 8q0 6-6 6l-8-8q0 24 18 18z")  \
	OP(zzLASTICON,	"")

#define AS_ICON_ENUM(x,...) ICON_ENUM_##x,
#define AS_ICON_STRING(x,...) #x,
#define AS_ICON_PATH(x,y) y,

enum {SVG_DX,SVG_DY,SVG_MAX_X,SVG_MAX_Y,SVG_NUM_SIZES};
enum icon_enum { ICON_MAP(AS_ICON_ENUM) };
static const char *icon_names[] = { ICON_MAP(AS_ICON_STRING) };
static const char *icon_paths[] = { ICON_MAP(AS_ICON_PATH) };

static inline const char *get_icon_path(const char *icon){
	size_t bot=0, top=ICON_ENUM_zzLASTICON, i=(bot+top)>>1;
	int cmp;
	for (; bot<=top && i<=ICON_ENUM_zzLASTICON; i=(bot+top)>>1){
		cmp=strcmp(icon,icon_names[i]);
		if (! cmp) return icon_paths[i]; //match found
		else if (cmp>0) bot=i+1;
		else top=i-1;
	}
	return "";
}

static inline char *
put_icon(
	char *bp,
	const char *s,
	const char *style,
	int *sizes
){
	if (!s || !bp) return bp;
	int width = sizes[SVG_DX]+ICON_WIDTH;
	int height = sizes[SVG_DY]+ICON_HEIGHT;

	bp+=sprintf(bp,"\t<path %s d=\"M%d %d%s\"/>\n",
		style,sizes[SVG_DX],sizes[SVG_DY], get_icon_path(s));
	if (width > sizes[SVG_MAX_X]) sizes[SVG_MAX_X] = width;
	if (height > sizes[SVG_MAX_Y]) sizes[SVG_MAX_Y] = height;
	return bp;
}

static inline int usage(int r){
	puts("\nusage:\n" \
"  text2svg [-x x_offset] [-y y_offset] [-w width] [-w height] [-s style]\n"\
"    [-v viewBox] [-t \"text to style\"] [-d \"extra data\"] [-b background]\n"\
"    [-i icon] [-l all/single)" \
"example:\n" \
"  text2svg -x 96 -y 0 -s 'stroke=\"#fff\" fill=\"none\"' -d '<path d=\"m0 0h96v96h-96z\"/>' -t 'hello world'\n"
	);
	return r;
}

static inline char *
convert2paths(
	char *bp,
	const char *s,
	const char *style,
	int *sizes
){
	if (!s || !bp) return bp;
	bp+=sprintf(bp,"\t<path %s d=\"M%d %d",style,sizes[SVG_DX],sizes[SVG_DY]);
	int width = sizes[SVG_DX];
	int height = sizes[SVG_DY]+FONT_HEIGHT;
	for(;*s;s++){
		if (*s == '\n' || *s == '\t'){
			if (*s=='\n'){
				bp+=sprintf(bp,"m-%d %d",width-sizes[SVG_DX],FONT_HEIGHT);
				if (width > sizes[SVG_MAX_X]) sizes[SVG_MAX_X] = width;
				width =sizes[SVG_DX];
				height += FONT_HEIGHT;
			}
			if (*s=='\t'){
				bp=stpcpy(bp,TAB_PATH(TAB_WIDTH));
				width += TAB_WIDTH;
			}
		}else{
			size_t c = (size_t)(*s-' ');
			if (c>95) c=95; //non-printing characters get a rectangle
			bp=stpcpy(bp,char_paths[c]);
			width += FONT_WIDTH;
		}
	}
	if (width > sizes[SVG_MAX_X]) sizes[SVG_MAX_X] = width;
	if (height > sizes[SVG_MAX_Y]) sizes[SVG_MAX_Y] = height;
	bp=stpcpy(bp,"\"/>\n");
	return bp;
}

int main(int argc, char **argv){
	char  buf[65536], w[32], h[32], vB[32];
	char *bp=buf, *vBp=NULL, *style=NULL, *hp=NULL, *wp=NULL;
	const char *defaultstyle="stroke=\"#fff\" fill=\"none\"";
	int sizes[SVG_NUM_SIZES]={0};
	if (argc<3) return usage(1);
	while(argc>2){
		argc-=2;
		char *var = *++argv, *arg = *++argv;
		if ( !var  || !arg || *var++ != '-' ) return usage(2);
		switch (*var){
		case 'x': sizes[SVG_DX]=atoi(arg);break;
		case 'y': sizes[SVG_DY]=atoi(arg);break;
		case 'w': wp=w; (void)sprintf(wp,"width=\"%s\" ",arg);     break;
		case 'h': hp=h; (void)sprintf(hp,"height=\"%s\" ",arg);    break;
		case 'v': vBp=vB; (void)sprintf(vBp,"viewBox=\"%s\"",arg); break;
		case 's': style=arg;break;
		case 'i': 
			bp=put_icon(bp, arg,(style)?style:defaultstyle,sizes);
			break;
		case 'l': 
			for(size_t i = 0;i<ICON_ENUM_zzLASTICON;i++)
				puts(icon_names[i]);
			return 0;
		case 'b':
			bp+=sprintf(bp,"\t<path fill=\"%s\" d=\"M0 0h999v999h-999z\"/>",arg);
			break;
		case 't':
			bp=convert2paths(bp,arg,(style)?style:defaultstyle,sizes);
			break;
		case 'd': for(const char *data=arg;*data;) *bp++=*data++;;break;
		default: return usage(1);
		}
	}
	*bp=0;
	if (!vBp){
		vBp=vB;
		(void)sprintf(vBp,"viewBox=\"0 0 %d %d\"",sizes[SVG_MAX_X],sizes[SVG_MAX_Y]);
	}
	printf( "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n" \
"<svg xmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\" %s%s%s>\n%s</svg>\n",
	(wp)?wp:"", (hp)?hp:"", vBp, buf);
	
	return 0;
}
