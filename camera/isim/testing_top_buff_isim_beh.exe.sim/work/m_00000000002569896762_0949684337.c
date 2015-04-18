/**********************************************************************/
/*   ____  ____                                                       */
/*  /   /\/   /                                                       */
/* /___/  \  /                                                        */
/* \   \   \/                                                       */
/*  \   \        Copyright (c) 2003-2009 Xilinx, Inc.                */
/*  /   /          All Right Reserved.                                 */
/* /---/   /\                                                         */
/* \   \  /  \                                                      */
/*  \___\/\___\                                                    */
/***********************************************************************/

/* This file is designed for use with ISim build 0xa0883be4 */

#define XSI_HIDE_SYMBOL_SPEC true
#include "xsi.h"
#include <memory.h>
#ifdef __GNUC__
#include <stdlib.h>
#else
#include <malloc.h>
#define alloca _alloca
#endif
static const char *ng0 = "//ad/eng/users/m/d/mdean13/Desktop/camera/sender.v";
static unsigned int ng1[] = {1U, 0U};
static unsigned int ng2[] = {0U, 0U};
static unsigned int ng3[] = {2U, 0U};
static int ng4[] = {0, 0};
static int ng5[] = {31, 0};
static int ng6[] = {1, 0};
static unsigned int ng7[] = {4U, 0U};
static unsigned int ng8[] = {4294967295U, 0U};
static unsigned int ng9[] = {63U, 0U};
static unsigned int ng10[] = {62U, 0U};
static unsigned int ng11[] = {60U, 0U};
static unsigned int ng12[] = {48U, 0U};
static unsigned int ng13[] = {32U, 0U};
static unsigned int ng14[] = {255U, 0U};



static void Initial_35_0(char *t0)
{
    char *t1;
    char *t2;

LAB0:    xsi_set_current_line(35, ng0);

LAB2:    xsi_set_current_line(36, ng0);
    t1 = ((char*)((ng1)));
    t2 = (t0 + 2568);
    xsi_vlogvar_wait_assign_value(t2, t1, 0, 0, 8, 0LL);
    xsi_set_current_line(37, ng0);
    t1 = ((char*)((ng2)));
    t2 = (t0 + 2728);
    xsi_vlogvar_wait_assign_value(t2, t1, 0, 0, 32, 0LL);
    xsi_set_current_line(38, ng0);
    t1 = ((char*)((ng1)));
    t2 = (t0 + 2888);
    xsi_vlogvar_wait_assign_value(t2, t1, 0, 0, 32, 0LL);

LAB1:    return;
}

static void Always_41_1(char *t0)
{
    char t4[8];
    char t5[8];
    char t18[8];
    char t34[8];
    char t47[8];
    char t60[8];
    char t76[8];
    char t84[8];
    char t112[8];
    char t125[8];
    char t138[8];
    char t154[8];
    char t162[8];
    char t206[8];
    char *t1;
    char *t2;
    char *t3;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    char *t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    char *t17;
    char *t19;
    char *t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    unsigned int t24;
    unsigned int t25;
    unsigned int t26;
    unsigned int t27;
    unsigned int t28;
    unsigned int t29;
    unsigned int t30;
    unsigned int t31;
    unsigned int t32;
    char *t33;
    char *t35;
    unsigned int t36;
    unsigned int t37;
    unsigned int t38;
    unsigned int t39;
    unsigned int t40;
    char *t41;
    char *t42;
    unsigned int t43;
    unsigned int t44;
    unsigned int t45;
    unsigned int t46;
    char *t48;
    char *t49;
    char *t50;
    char *t51;
    char *t52;
    unsigned int t53;
    unsigned int t54;
    unsigned int t55;
    unsigned int t56;
    unsigned int t57;
    unsigned int t58;
    char *t59;
    char *t61;
    char *t62;
    unsigned int t63;
    unsigned int t64;
    unsigned int t65;
    unsigned int t66;
    unsigned int t67;
    unsigned int t68;
    unsigned int t69;
    unsigned int t70;
    unsigned int t71;
    unsigned int t72;
    unsigned int t73;
    unsigned int t74;
    char *t75;
    char *t77;
    unsigned int t78;
    unsigned int t79;
    unsigned int t80;
    unsigned int t81;
    unsigned int t82;
    char *t83;
    unsigned int t85;
    unsigned int t86;
    unsigned int t87;
    char *t88;
    char *t89;
    char *t90;
    unsigned int t91;
    unsigned int t92;
    unsigned int t93;
    unsigned int t94;
    unsigned int t95;
    unsigned int t96;
    unsigned int t97;
    char *t98;
    char *t99;
    unsigned int t100;
    unsigned int t101;
    unsigned int t102;
    int t103;
    unsigned int t104;
    unsigned int t105;
    unsigned int t106;
    int t107;
    unsigned int t108;
    unsigned int t109;
    unsigned int t110;
    unsigned int t111;
    char *t113;
    unsigned int t114;
    unsigned int t115;
    unsigned int t116;
    unsigned int t117;
    unsigned int t118;
    char *t119;
    char *t120;
    unsigned int t121;
    unsigned int t122;
    unsigned int t123;
    unsigned int t124;
    char *t126;
    char *t127;
    char *t128;
    char *t129;
    char *t130;
    unsigned int t131;
    unsigned int t132;
    unsigned int t133;
    unsigned int t134;
    unsigned int t135;
    unsigned int t136;
    char *t137;
    char *t139;
    char *t140;
    unsigned int t141;
    unsigned int t142;
    unsigned int t143;
    unsigned int t144;
    unsigned int t145;
    unsigned int t146;
    unsigned int t147;
    unsigned int t148;
    unsigned int t149;
    unsigned int t150;
    unsigned int t151;
    unsigned int t152;
    char *t153;
    char *t155;
    unsigned int t156;
    unsigned int t157;
    unsigned int t158;
    unsigned int t159;
    unsigned int t160;
    char *t161;
    unsigned int t163;
    unsigned int t164;
    unsigned int t165;
    char *t166;
    char *t167;
    char *t168;
    unsigned int t169;
    unsigned int t170;
    unsigned int t171;
    unsigned int t172;
    unsigned int t173;
    unsigned int t174;
    unsigned int t175;
    char *t176;
    char *t177;
    unsigned int t178;
    unsigned int t179;
    unsigned int t180;
    int t181;
    unsigned int t182;
    unsigned int t183;
    unsigned int t184;
    int t185;
    unsigned int t186;
    unsigned int t187;
    unsigned int t188;
    unsigned int t189;
    char *t190;
    unsigned int t191;
    unsigned int t192;
    unsigned int t193;
    unsigned int t194;
    unsigned int t195;
    char *t196;
    char *t197;
    unsigned int t198;
    unsigned int t199;
    unsigned int t200;
    unsigned int t201;
    unsigned int t202;
    char *t203;
    char *t204;
    char *t205;
    char *t207;
    char *t208;
    unsigned int t209;
    unsigned int t210;
    unsigned int t211;
    unsigned int t212;
    unsigned int t213;
    unsigned int t214;
    char *t215;

LAB0:    t1 = (t0 + 4216U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(41, ng0);
    t2 = (t0 + 5032);
    *((int *)t2) = 1;
    t3 = (t0 + 4248);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(41, ng0);

LAB5:    xsi_set_current_line(42, ng0);
    t6 = (t0 + 2728);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    memset(t5, 0, 8);
    t9 = (t5 + 4);
    t10 = (t8 + 4);
    t11 = *((unsigned int *)t8);
    t12 = (t11 >> 10);
    *((unsigned int *)t5) = t12;
    t13 = *((unsigned int *)t10);
    t14 = (t13 >> 10);
    *((unsigned int *)t9) = t14;
    t15 = *((unsigned int *)t5);
    *((unsigned int *)t5) = (t15 & 3U);
    t16 = *((unsigned int *)t9);
    *((unsigned int *)t9) = (t16 & 3U);
    t17 = ((char*)((ng3)));
    memset(t18, 0, 8);
    t19 = (t5 + 4);
    t20 = (t17 + 4);
    t21 = *((unsigned int *)t5);
    t22 = *((unsigned int *)t17);
    t23 = (t21 ^ t22);
    t24 = *((unsigned int *)t19);
    t25 = *((unsigned int *)t20);
    t26 = (t24 ^ t25);
    t27 = (t23 | t26);
    t28 = *((unsigned int *)t19);
    t29 = *((unsigned int *)t20);
    t30 = (t28 | t29);
    t31 = (~(t30));
    t32 = (t27 & t31);
    if (t32 != 0)
        goto LAB9;

LAB6:    if (t30 != 0)
        goto LAB8;

LAB7:    *((unsigned int *)t18) = 1;

LAB9:    memset(t34, 0, 8);
    t35 = (t18 + 4);
    t36 = *((unsigned int *)t35);
    t37 = (~(t36));
    t38 = *((unsigned int *)t18);
    t39 = (t38 & t37);
    t40 = (t39 & 1U);
    if (t40 != 0)
        goto LAB10;

LAB11:    if (*((unsigned int *)t35) != 0)
        goto LAB12;

LAB13:    t42 = (t34 + 4);
    t43 = *((unsigned int *)t34);
    t44 = (!(t43));
    t45 = *((unsigned int *)t42);
    t46 = (t44 || t45);
    if (t46 > 0)
        goto LAB14;

LAB15:    memcpy(t84, t34, 8);

LAB16:    memset(t112, 0, 8);
    t113 = (t84 + 4);
    t114 = *((unsigned int *)t113);
    t115 = (~(t114));
    t116 = *((unsigned int *)t84);
    t117 = (t116 & t115);
    t118 = (t117 & 1U);
    if (t118 != 0)
        goto LAB28;

LAB29:    if (*((unsigned int *)t113) != 0)
        goto LAB30;

LAB31:    t120 = (t112 + 4);
    t121 = *((unsigned int *)t112);
    t122 = (!(t121));
    t123 = *((unsigned int *)t120);
    t124 = (t122 || t123);
    if (t124 > 0)
        goto LAB32;

LAB33:    memcpy(t162, t112, 8);

LAB34:    memset(t4, 0, 8);
    t190 = (t162 + 4);
    t191 = *((unsigned int *)t190);
    t192 = (~(t191));
    t193 = *((unsigned int *)t162);
    t194 = (t193 & t192);
    t195 = (t194 & 1U);
    if (t195 != 0)
        goto LAB49;

LAB47:    if (*((unsigned int *)t190) == 0)
        goto LAB46;

LAB48:    t196 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t196) = 1;

LAB49:    t197 = (t4 + 4);
    t198 = *((unsigned int *)t197);
    t199 = (~(t198));
    t200 = *((unsigned int *)t4);
    t201 = (t200 & t199);
    t202 = (t201 != 0);
    if (t202 > 0)
        goto LAB50;

LAB51:
LAB52:    goto LAB2;

LAB8:    t33 = (t18 + 4);
    *((unsigned int *)t18) = 1;
    *((unsigned int *)t33) = 1;
    goto LAB9;

LAB10:    *((unsigned int *)t34) = 1;
    goto LAB13;

LAB12:    t41 = (t34 + 4);
    *((unsigned int *)t34) = 1;
    *((unsigned int *)t41) = 1;
    goto LAB13;

LAB14:    t48 = (t0 + 2728);
    t49 = (t48 + 56U);
    t50 = *((char **)t49);
    memset(t47, 0, 8);
    t51 = (t47 + 4);
    t52 = (t50 + 4);
    t53 = *((unsigned int *)t50);
    t54 = (t53 >> 19);
    *((unsigned int *)t47) = t54;
    t55 = *((unsigned int *)t52);
    t56 = (t55 >> 19);
    *((unsigned int *)t51) = t56;
    t57 = *((unsigned int *)t47);
    *((unsigned int *)t47) = (t57 & 3U);
    t58 = *((unsigned int *)t51);
    *((unsigned int *)t51) = (t58 & 3U);
    t59 = ((char*)((ng3)));
    memset(t60, 0, 8);
    t61 = (t47 + 4);
    t62 = (t59 + 4);
    t63 = *((unsigned int *)t47);
    t64 = *((unsigned int *)t59);
    t65 = (t63 ^ t64);
    t66 = *((unsigned int *)t61);
    t67 = *((unsigned int *)t62);
    t68 = (t66 ^ t67);
    t69 = (t65 | t68);
    t70 = *((unsigned int *)t61);
    t71 = *((unsigned int *)t62);
    t72 = (t70 | t71);
    t73 = (~(t72));
    t74 = (t69 & t73);
    if (t74 != 0)
        goto LAB20;

LAB17:    if (t72 != 0)
        goto LAB19;

LAB18:    *((unsigned int *)t60) = 1;

LAB20:    memset(t76, 0, 8);
    t77 = (t60 + 4);
    t78 = *((unsigned int *)t77);
    t79 = (~(t78));
    t80 = *((unsigned int *)t60);
    t81 = (t80 & t79);
    t82 = (t81 & 1U);
    if (t82 != 0)
        goto LAB21;

LAB22:    if (*((unsigned int *)t77) != 0)
        goto LAB23;

LAB24:    t85 = *((unsigned int *)t34);
    t86 = *((unsigned int *)t76);
    t87 = (t85 | t86);
    *((unsigned int *)t84) = t87;
    t88 = (t34 + 4);
    t89 = (t76 + 4);
    t90 = (t84 + 4);
    t91 = *((unsigned int *)t88);
    t92 = *((unsigned int *)t89);
    t93 = (t91 | t92);
    *((unsigned int *)t90) = t93;
    t94 = *((unsigned int *)t90);
    t95 = (t94 != 0);
    if (t95 == 1)
        goto LAB25;

LAB26:
LAB27:    goto LAB16;

LAB19:    t75 = (t60 + 4);
    *((unsigned int *)t60) = 1;
    *((unsigned int *)t75) = 1;
    goto LAB20;

LAB21:    *((unsigned int *)t76) = 1;
    goto LAB24;

LAB23:    t83 = (t76 + 4);
    *((unsigned int *)t76) = 1;
    *((unsigned int *)t83) = 1;
    goto LAB24;

LAB25:    t96 = *((unsigned int *)t84);
    t97 = *((unsigned int *)t90);
    *((unsigned int *)t84) = (t96 | t97);
    t98 = (t34 + 4);
    t99 = (t76 + 4);
    t100 = *((unsigned int *)t98);
    t101 = (~(t100));
    t102 = *((unsigned int *)t34);
    t103 = (t102 & t101);
    t104 = *((unsigned int *)t99);
    t105 = (~(t104));
    t106 = *((unsigned int *)t76);
    t107 = (t106 & t105);
    t108 = (~(t103));
    t109 = (~(t107));
    t110 = *((unsigned int *)t90);
    *((unsigned int *)t90) = (t110 & t108);
    t111 = *((unsigned int *)t90);
    *((unsigned int *)t90) = (t111 & t109);
    goto LAB27;

LAB28:    *((unsigned int *)t112) = 1;
    goto LAB31;

LAB30:    t119 = (t112 + 4);
    *((unsigned int *)t112) = 1;
    *((unsigned int *)t119) = 1;
    goto LAB31;

LAB32:    t126 = (t0 + 2728);
    t127 = (t126 + 56U);
    t128 = *((char **)t127);
    memset(t125, 0, 8);
    t129 = (t125 + 4);
    t130 = (t128 + 4);
    t131 = *((unsigned int *)t128);
    t132 = (t131 >> 28);
    *((unsigned int *)t125) = t132;
    t133 = *((unsigned int *)t130);
    t134 = (t133 >> 28);
    *((unsigned int *)t129) = t134;
    t135 = *((unsigned int *)t125);
    *((unsigned int *)t125) = (t135 & 3U);
    t136 = *((unsigned int *)t129);
    *((unsigned int *)t129) = (t136 & 3U);
    t137 = ((char*)((ng3)));
    memset(t138, 0, 8);
    t139 = (t125 + 4);
    t140 = (t137 + 4);
    t141 = *((unsigned int *)t125);
    t142 = *((unsigned int *)t137);
    t143 = (t141 ^ t142);
    t144 = *((unsigned int *)t139);
    t145 = *((unsigned int *)t140);
    t146 = (t144 ^ t145);
    t147 = (t143 | t146);
    t148 = *((unsigned int *)t139);
    t149 = *((unsigned int *)t140);
    t150 = (t148 | t149);
    t151 = (~(t150));
    t152 = (t147 & t151);
    if (t152 != 0)
        goto LAB38;

LAB35:    if (t150 != 0)
        goto LAB37;

LAB36:    *((unsigned int *)t138) = 1;

LAB38:    memset(t154, 0, 8);
    t155 = (t138 + 4);
    t156 = *((unsigned int *)t155);
    t157 = (~(t156));
    t158 = *((unsigned int *)t138);
    t159 = (t158 & t157);
    t160 = (t159 & 1U);
    if (t160 != 0)
        goto LAB39;

LAB40:    if (*((unsigned int *)t155) != 0)
        goto LAB41;

LAB42:    t163 = *((unsigned int *)t112);
    t164 = *((unsigned int *)t154);
    t165 = (t163 | t164);
    *((unsigned int *)t162) = t165;
    t166 = (t112 + 4);
    t167 = (t154 + 4);
    t168 = (t162 + 4);
    t169 = *((unsigned int *)t166);
    t170 = *((unsigned int *)t167);
    t171 = (t169 | t170);
    *((unsigned int *)t168) = t171;
    t172 = *((unsigned int *)t168);
    t173 = (t172 != 0);
    if (t173 == 1)
        goto LAB43;

LAB44:
LAB45:    goto LAB34;

LAB37:    t153 = (t138 + 4);
    *((unsigned int *)t138) = 1;
    *((unsigned int *)t153) = 1;
    goto LAB38;

LAB39:    *((unsigned int *)t154) = 1;
    goto LAB42;

LAB41:    t161 = (t154 + 4);
    *((unsigned int *)t154) = 1;
    *((unsigned int *)t161) = 1;
    goto LAB42;

LAB43:    t174 = *((unsigned int *)t162);
    t175 = *((unsigned int *)t168);
    *((unsigned int *)t162) = (t174 | t175);
    t176 = (t112 + 4);
    t177 = (t154 + 4);
    t178 = *((unsigned int *)t176);
    t179 = (~(t178));
    t180 = *((unsigned int *)t112);
    t181 = (t180 & t179);
    t182 = *((unsigned int *)t177);
    t183 = (~(t182));
    t184 = *((unsigned int *)t154);
    t185 = (t184 & t183);
    t186 = (~(t181));
    t187 = (~(t185));
    t188 = *((unsigned int *)t168);
    *((unsigned int *)t168) = (t188 & t186);
    t189 = *((unsigned int *)t168);
    *((unsigned int *)t168) = (t189 & t187);
    goto LAB45;

LAB46:    *((unsigned int *)t4) = 1;
    goto LAB49;

LAB50:    xsi_set_current_line(45, ng0);
    t203 = (t0 + 2888);
    t204 = (t203 + 56U);
    t205 = *((char **)t204);
    memset(t206, 0, 8);
    t207 = (t206 + 4);
    t208 = (t205 + 4);
    t209 = *((unsigned int *)t205);
    t210 = (t209 >> 31);
    t211 = (t210 & 1);
    *((unsigned int *)t206) = t211;
    t212 = *((unsigned int *)t208);
    t213 = (t212 >> 31);
    t214 = (t213 & 1);
    *((unsigned int *)t207) = t214;
    t215 = (t0 + 3048);
    xsi_vlogvar_wait_assign_value(t215, t206, 0, 0, 1, 0LL);
    goto LAB52;

}

static void Always_48_2(char *t0)
{
    char t6[8];
    char t11[8];
    char t52[16];
    char t62[8];
    char t64[8];
    char t66[8];
    char t67[8];
    char t68[8];
    char t69[8];
    char t70[8];
    char t71[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t7;
    char *t8;
    char *t9;
    char *t10;
    char *t12;
    char *t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    unsigned int t24;
    unsigned int t25;
    char *t26;
    char *t27;
    unsigned int t28;
    unsigned int t29;
    unsigned int t30;
    unsigned int t31;
    unsigned int t32;
    char *t33;
    char *t34;
    unsigned int t35;
    unsigned int t36;
    unsigned int t37;
    unsigned int t38;
    unsigned int t39;
    unsigned int t40;
    unsigned int t41;
    unsigned int t42;
    unsigned int t43;
    unsigned int t44;
    unsigned int t45;
    unsigned int t46;
    unsigned int t47;
    unsigned int t48;
    unsigned int t49;
    unsigned int t50;
    unsigned int t51;
    char *t53;
    char *t54;
    char *t55;
    char *t56;
    char *t57;
    char *t58;
    char *t59;
    char *t60;
    char *t61;
    int t63;
    int t65;

LAB0:    t1 = (t0 + 4464U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(48, ng0);
    t2 = (t0 + 5048);
    *((int *)t2) = 1;
    t3 = (t0 + 4496);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(48, ng0);

LAB5:    xsi_set_current_line(49, ng0);
    t4 = ((char*)((ng4)));
    t5 = (t0 + 2408);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 1, 0LL);
    xsi_set_current_line(51, ng0);
    t2 = (t0 + 2728);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 2728);
    t7 = (t5 + 72U);
    t8 = *((char **)t7);
    t9 = ((char*)((ng5)));
    xsi_vlog_generic_get_index_select_value(t6, 32, t4, t8, 2, t9, 32, 1);
    t10 = ((char*)((ng4)));
    memset(t11, 0, 8);
    t12 = (t6 + 4);
    t13 = (t10 + 4);
    t14 = *((unsigned int *)t6);
    t15 = *((unsigned int *)t10);
    t16 = (t14 ^ t15);
    t17 = *((unsigned int *)t12);
    t18 = *((unsigned int *)t13);
    t19 = (t17 ^ t18);
    t20 = (t16 | t19);
    t21 = *((unsigned int *)t12);
    t22 = *((unsigned int *)t13);
    t23 = (t21 | t22);
    t24 = (~(t23));
    t25 = (t20 & t24);
    if (t25 != 0)
        goto LAB9;

LAB6:    if (t23 != 0)
        goto LAB8;

LAB7:    *((unsigned int *)t11) = 1;

LAB9:    t27 = (t11 + 4);
    t28 = *((unsigned int *)t27);
    t29 = (~(t28));
    t30 = *((unsigned int *)t11);
    t31 = (t30 & t29);
    t32 = (t31 != 0);
    if (t32 > 0)
        goto LAB10;

LAB11:    xsi_set_current_line(63, ng0);

LAB30:    xsi_set_current_line(64, ng0);
    t2 = (t0 + 2728);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    memset(t11, 0, 8);
    t5 = (t11 + 4);
    t7 = (t4 + 4);
    t14 = *((unsigned int *)t4);
    t15 = (t14 >> 0);
    *((unsigned int *)t11) = t15;
    t16 = *((unsigned int *)t7);
    t17 = (t16 >> 0);
    *((unsigned int *)t5) = t17;
    t18 = *((unsigned int *)t11);
    *((unsigned int *)t11) = (t18 & 7U);
    t19 = *((unsigned int *)t5);
    *((unsigned int *)t5) = (t19 & 7U);
    t8 = (t0 + 2728);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memset(t62, 0, 8);
    t12 = (t62 + 4);
    t13 = (t10 + 4);
    t20 = *((unsigned int *)t10);
    t21 = (t20 >> 29);
    *((unsigned int *)t62) = t21;
    t22 = *((unsigned int *)t13);
    t23 = (t22 >> 29);
    *((unsigned int *)t12) = t23;
    t24 = *((unsigned int *)t62);
    *((unsigned int *)t62) = (t24 & 7U);
    t25 = *((unsigned int *)t12);
    *((unsigned int *)t12) = (t25 & 7U);
    xsi_vlogtype_concat(t6, 6, 6, 2U, t62, 3, t11, 3);

LAB31:    t26 = ((char*)((ng9)));
    t63 = xsi_vlog_unsigned_case_compare(t6, 6, t26, 6);
    if (t63 == 1)
        goto LAB32;

LAB33:    t2 = ((char*)((ng10)));
    t63 = xsi_vlog_unsigned_case_compare(t6, 6, t2, 6);
    if (t63 == 1)
        goto LAB34;

LAB35:    t2 = ((char*)((ng11)));
    t63 = xsi_vlog_unsigned_case_compare(t6, 6, t2, 6);
    if (t63 == 1)
        goto LAB36;

LAB37:    t2 = ((char*)((ng12)));
    t63 = xsi_vlog_unsigned_case_compare(t6, 6, t2, 6);
    if (t63 == 1)
        goto LAB38;

LAB39:    t2 = ((char*)((ng13)));
    t63 = xsi_vlog_unsigned_case_compare(t6, 6, t2, 6);
    if (t63 == 1)
        goto LAB40;

LAB41:    t2 = ((char*)((ng2)));
    t63 = xsi_vlog_unsigned_case_compare(t6, 6, t2, 6);
    if (t63 == 1)
        goto LAB42;

LAB43:
LAB45:
LAB44:    xsi_set_current_line(108, ng0);
    t2 = (t0 + 2568);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    memset(t69, 0, 8);
    t5 = (t69 + 4);
    t7 = (t4 + 4);
    t14 = *((unsigned int *)t4);
    t15 = (t14 >> 6);
    *((unsigned int *)t69) = t15;
    t16 = *((unsigned int *)t7);
    t17 = (t16 >> 6);
    *((unsigned int *)t5) = t17;
    t18 = *((unsigned int *)t69);
    *((unsigned int *)t69) = (t18 & 3U);
    t19 = *((unsigned int *)t5);
    *((unsigned int *)t5) = (t19 & 3U);

LAB107:    t8 = ((char*)((ng2)));
    t63 = xsi_vlog_unsigned_case_compare(t69, 2, t8, 2);
    if (t63 == 1)
        goto LAB108;

LAB109:    t2 = ((char*)((ng1)));
    t63 = xsi_vlog_unsigned_case_compare(t69, 2, t2, 2);
    if (t63 == 1)
        goto LAB110;

LAB111:    t2 = ((char*)((ng3)));
    t63 = xsi_vlog_unsigned_case_compare(t69, 2, t2, 2);
    if (t63 == 1)
        goto LAB112;

LAB113:
LAB115:
LAB114:    xsi_set_current_line(112, ng0);
    t2 = ((char*)((ng4)));
    t3 = (t0 + 2248);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 0LL);

LAB116:
LAB46:    xsi_set_current_line(116, ng0);
    t2 = (t0 + 2568);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng14)));
    memset(t70, 0, 8);
    t7 = (t4 + 4);
    t8 = (t5 + 4);
    t14 = *((unsigned int *)t4);
    t15 = *((unsigned int *)t5);
    t16 = (t14 ^ t15);
    t17 = *((unsigned int *)t7);
    t18 = *((unsigned int *)t8);
    t19 = (t17 ^ t18);
    t20 = (t16 | t19);
    t21 = *((unsigned int *)t7);
    t22 = *((unsigned int *)t8);
    t23 = (t21 | t22);
    t24 = (~(t23));
    t25 = (t20 & t24);
    if (t25 != 0)
        goto LAB120;

LAB117:    if (t23 != 0)
        goto LAB119;

LAB118:    *((unsigned int *)t70) = 1;

LAB120:    t10 = (t70 + 4);
    t28 = *((unsigned int *)t10);
    t29 = (~(t28));
    t30 = *((unsigned int *)t70);
    t31 = (t30 & t29);
    t32 = (t31 != 0);
    if (t32 > 0)
        goto LAB121;

LAB122:    xsi_set_current_line(122, ng0);
    t2 = (t0 + 2568);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng6)));
    memset(t70, 0, 8);
    xsi_vlog_unsigned_add(t70, 32, t4, 8, t5, 32);
    t7 = (t0 + 2568);
    xsi_vlogvar_wait_assign_value(t7, t70, 0, 0, 8, 0LL);

LAB123:
LAB12:    goto LAB2;

LAB8:    t26 = (t11 + 4);
    *((unsigned int *)t11) = 1;
    *((unsigned int *)t26) = 1;
    goto LAB9;

LAB10:    xsi_set_current_line(51, ng0);

LAB13:    xsi_set_current_line(52, ng0);
    t33 = ((char*)((ng6)));
    t34 = (t0 + 2248);
    xsi_vlogvar_wait_assign_value(t34, t33, 0, 0, 1, 0LL);
    xsi_set_current_line(53, ng0);
    t2 = (t0 + 1208U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng6)));
    memset(t6, 0, 8);
    t4 = (t3 + 4);
    t5 = (t2 + 4);
    t14 = *((unsigned int *)t3);
    t15 = *((unsigned int *)t2);
    t16 = (t14 ^ t15);
    t17 = *((unsigned int *)t4);
    t18 = *((unsigned int *)t5);
    t19 = (t17 ^ t18);
    t20 = (t16 | t19);
    t21 = *((unsigned int *)t4);
    t22 = *((unsigned int *)t5);
    t23 = (t21 | t22);
    t24 = (~(t23));
    t25 = (t20 & t24);
    if (t25 != 0)
        goto LAB17;

LAB14:    if (t23 != 0)
        goto LAB16;

LAB15:    *((unsigned int *)t6) = 1;

LAB17:    t8 = (t6 + 4);
    t28 = *((unsigned int *)t8);
    t29 = (~(t28));
    t30 = *((unsigned int *)t6);
    t31 = (t30 & t29);
    t32 = (t31 != 0);
    if (t32 > 0)
        goto LAB18;

LAB19:
LAB20:    goto LAB12;

LAB16:    t7 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t7) = 1;
    goto LAB17;

LAB18:    xsi_set_current_line(53, ng0);

LAB21:    xsi_set_current_line(54, ng0);
    t9 = (t0 + 2568);
    t10 = (t9 + 56U);
    t12 = *((char **)t10);
    t13 = ((char*)((ng2)));
    memset(t11, 0, 8);
    t26 = (t12 + 4);
    t27 = (t13 + 4);
    t35 = *((unsigned int *)t12);
    t36 = *((unsigned int *)t13);
    t37 = (t35 ^ t36);
    t38 = *((unsigned int *)t26);
    t39 = *((unsigned int *)t27);
    t40 = (t38 ^ t39);
    t41 = (t37 | t40);
    t42 = *((unsigned int *)t26);
    t43 = *((unsigned int *)t27);
    t44 = (t42 | t43);
    t45 = (~(t44));
    t46 = (t41 & t45);
    if (t46 != 0)
        goto LAB25;

LAB22:    if (t44 != 0)
        goto LAB24;

LAB23:    *((unsigned int *)t11) = 1;

LAB25:    t34 = (t11 + 4);
    t47 = *((unsigned int *)t34);
    t48 = (~(t47));
    t49 = *((unsigned int *)t11);
    t50 = (t49 & t48);
    t51 = (t50 != 0);
    if (t51 > 0)
        goto LAB26;

LAB27:    xsi_set_current_line(60, ng0);
    t2 = (t0 + 2568);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng6)));
    memset(t6, 0, 8);
    xsi_vlog_unsigned_add(t6, 32, t4, 8, t5, 32);
    t7 = (t0 + 2568);
    xsi_vlogvar_wait_assign_value(t7, t6, 0, 0, 8, 0LL);

LAB28:    goto LAB20;

LAB24:    t33 = (t11 + 4);
    *((unsigned int *)t11) = 1;
    *((unsigned int *)t33) = 1;
    goto LAB25;

LAB26:    xsi_set_current_line(54, ng0);

LAB29:    xsi_set_current_line(55, ng0);
    t53 = ((char*)((ng1)));
    t54 = ((char*)((ng2)));
    t55 = (t0 + 1688U);
    t56 = *((char **)t55);
    t55 = ((char*)((ng2)));
    t57 = (t0 + 1528U);
    t58 = *((char **)t57);
    t57 = ((char*)((ng2)));
    t59 = (t0 + 1368U);
    t60 = *((char **)t59);
    t59 = ((char*)((ng7)));
    xsi_vlogtype_concat(t52, 63, 63, 8U, t59, 3, t60, 8, t57, 1, t58, 8, t55, 1, t56, 8, t54, 32, t53, 2);
    t61 = (t0 + 2888);
    xsi_vlogvar_wait_assign_value(t61, t52, 0, 0, 32, 0LL);
    xsi_set_current_line(56, ng0);
    t2 = ((char*)((ng8)));
    t3 = (t0 + 2728);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 32, 0LL);
    xsi_set_current_line(57, ng0);
    t2 = ((char*)((ng6)));
    t3 = (t0 + 2408);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 0LL);
    goto LAB28;

LAB32:    xsi_set_current_line(66, ng0);
    t27 = (t0 + 2568);
    t33 = (t27 + 56U);
    t34 = *((char **)t33);
    memset(t64, 0, 8);
    t53 = (t64 + 4);
    t54 = (t34 + 4);
    t28 = *((unsigned int *)t34);
    t29 = (t28 >> 6);
    *((unsigned int *)t64) = t29;
    t30 = *((unsigned int *)t54);
    t31 = (t30 >> 6);
    *((unsigned int *)t53) = t31;
    t32 = *((unsigned int *)t64);
    *((unsigned int *)t64) = (t32 & 3U);
    t35 = *((unsigned int *)t53);
    *((unsigned int *)t53) = (t35 & 3U);

LAB47:    t55 = ((char*)((ng2)));
    t65 = xsi_vlog_unsigned_case_compare(t64, 2, t55, 2);
    if (t65 == 1)
        goto LAB48;

LAB49:    t2 = ((char*)((ng1)));
    t63 = xsi_vlog_unsigned_case_compare(t64, 2, t2, 2);
    if (t63 == 1)
        goto LAB50;

LAB51:    t2 = ((char*)((ng3)));
    t63 = xsi_vlog_unsigned_case_compare(t64, 2, t2, 2);
    if (t63 == 1)
        goto LAB52;

LAB53:
LAB55:
LAB54:    xsi_set_current_line(70, ng0);
    t2 = ((char*)((ng6)));
    t3 = (t0 + 2248);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 0LL);

LAB56:    goto LAB46;

LAB34:    xsi_set_current_line(73, ng0);
    t3 = (t0 + 2568);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    memset(t11, 0, 8);
    t7 = (t11 + 4);
    t8 = (t5 + 4);
    t14 = *((unsigned int *)t5);
    t15 = (t14 >> 6);
    *((unsigned int *)t11) = t15;
    t16 = *((unsigned int *)t8);
    t17 = (t16 >> 6);
    *((unsigned int *)t7) = t17;
    t18 = *((unsigned int *)t11);
    *((unsigned int *)t11) = (t18 & 3U);
    t19 = *((unsigned int *)t7);
    *((unsigned int *)t7) = (t19 & 3U);

LAB57:    t9 = ((char*)((ng2)));
    t65 = xsi_vlog_unsigned_case_compare(t11, 2, t9, 2);
    if (t65 == 1)
        goto LAB58;

LAB59:    t2 = ((char*)((ng1)));
    t63 = xsi_vlog_unsigned_case_compare(t11, 2, t2, 2);
    if (t63 == 1)
        goto LAB60;

LAB61:    t2 = ((char*)((ng3)));
    t63 = xsi_vlog_unsigned_case_compare(t11, 2, t2, 2);
    if (t63 == 1)
        goto LAB62;

LAB63:
LAB65:
LAB64:    xsi_set_current_line(77, ng0);
    t2 = ((char*)((ng6)));
    t3 = (t0 + 2248);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 0LL);

LAB66:    goto LAB46;

LAB36:    xsi_set_current_line(80, ng0);
    t3 = (t0 + 2568);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    memset(t62, 0, 8);
    t7 = (t62 + 4);
    t8 = (t5 + 4);
    t14 = *((unsigned int *)t5);
    t15 = (t14 >> 6);
    *((unsigned int *)t62) = t15;
    t16 = *((unsigned int *)t8);
    t17 = (t16 >> 6);
    *((unsigned int *)t7) = t17;
    t18 = *((unsigned int *)t62);
    *((unsigned int *)t62) = (t18 & 3U);
    t19 = *((unsigned int *)t7);
    *((unsigned int *)t7) = (t19 & 3U);

LAB67:    t9 = ((char*)((ng2)));
    t65 = xsi_vlog_unsigned_case_compare(t62, 2, t9, 2);
    if (t65 == 1)
        goto LAB68;

LAB69:    t2 = ((char*)((ng1)));
    t63 = xsi_vlog_unsigned_case_compare(t62, 2, t2, 2);
    if (t63 == 1)
        goto LAB70;

LAB71:    t2 = ((char*)((ng3)));
    t63 = xsi_vlog_unsigned_case_compare(t62, 2, t2, 2);
    if (t63 == 1)
        goto LAB72;

LAB73:
LAB75:
LAB74:    xsi_set_current_line(84, ng0);
    t2 = ((char*)((ng4)));
    t3 = (t0 + 2248);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 0LL);

LAB76:    goto LAB46;

LAB38:    xsi_set_current_line(87, ng0);
    t3 = (t0 + 2568);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    memset(t66, 0, 8);
    t7 = (t66 + 4);
    t8 = (t5 + 4);
    t14 = *((unsigned int *)t5);
    t15 = (t14 >> 6);
    *((unsigned int *)t66) = t15;
    t16 = *((unsigned int *)t8);
    t17 = (t16 >> 6);
    *((unsigned int *)t7) = t17;
    t18 = *((unsigned int *)t66);
    *((unsigned int *)t66) = (t18 & 3U);
    t19 = *((unsigned int *)t7);
    *((unsigned int *)t7) = (t19 & 3U);

LAB77:    t9 = ((char*)((ng2)));
    t65 = xsi_vlog_unsigned_case_compare(t66, 2, t9, 2);
    if (t65 == 1)
        goto LAB78;

LAB79:    t2 = ((char*)((ng1)));
    t63 = xsi_vlog_unsigned_case_compare(t66, 2, t2, 2);
    if (t63 == 1)
        goto LAB80;

LAB81:    t2 = ((char*)((ng3)));
    t63 = xsi_vlog_unsigned_case_compare(t66, 2, t2, 2);
    if (t63 == 1)
        goto LAB82;

LAB83:
LAB85:
LAB84:    xsi_set_current_line(91, ng0);
    t2 = ((char*)((ng6)));
    t3 = (t0 + 2248);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 0LL);

LAB86:    goto LAB46;

LAB40:    xsi_set_current_line(94, ng0);
    t3 = (t0 + 2568);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    memset(t67, 0, 8);
    t7 = (t67 + 4);
    t8 = (t5 + 4);
    t14 = *((unsigned int *)t5);
    t15 = (t14 >> 6);
    *((unsigned int *)t67) = t15;
    t16 = *((unsigned int *)t8);
    t17 = (t16 >> 6);
    *((unsigned int *)t7) = t17;
    t18 = *((unsigned int *)t67);
    *((unsigned int *)t67) = (t18 & 3U);
    t19 = *((unsigned int *)t7);
    *((unsigned int *)t7) = (t19 & 3U);

LAB87:    t9 = ((char*)((ng2)));
    t65 = xsi_vlog_unsigned_case_compare(t67, 2, t9, 2);
    if (t65 == 1)
        goto LAB88;

LAB89:    t2 = ((char*)((ng1)));
    t63 = xsi_vlog_unsigned_case_compare(t67, 2, t2, 2);
    if (t63 == 1)
        goto LAB90;

LAB91:    t2 = ((char*)((ng3)));
    t63 = xsi_vlog_unsigned_case_compare(t67, 2, t2, 2);
    if (t63 == 1)
        goto LAB92;

LAB93:
LAB95:
LAB94:    xsi_set_current_line(98, ng0);
    t2 = ((char*)((ng6)));
    t3 = (t0 + 2248);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 0LL);

LAB96:    goto LAB46;

LAB42:    xsi_set_current_line(101, ng0);
    t3 = (t0 + 2568);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    memset(t68, 0, 8);
    t7 = (t68 + 4);
    t8 = (t5 + 4);
    t14 = *((unsigned int *)t5);
    t15 = (t14 >> 6);
    *((unsigned int *)t68) = t15;
    t16 = *((unsigned int *)t8);
    t17 = (t16 >> 6);
    *((unsigned int *)t7) = t17;
    t18 = *((unsigned int *)t68);
    *((unsigned int *)t68) = (t18 & 3U);
    t19 = *((unsigned int *)t7);
    *((unsigned int *)t7) = (t19 & 3U);

LAB97:    t9 = ((char*)((ng2)));
    t65 = xsi_vlog_unsigned_case_compare(t68, 2, t9, 2);
    if (t65 == 1)
        goto LAB98;

LAB99:    t2 = ((char*)((ng1)));
    t63 = xsi_vlog_unsigned_case_compare(t68, 2, t2, 2);
    if (t63 == 1)
        goto LAB100;

LAB101:    t2 = ((char*)((ng3)));
    t63 = xsi_vlog_unsigned_case_compare(t68, 2, t2, 2);
    if (t63 == 1)
        goto LAB102;

LAB103:
LAB105:
LAB104:    xsi_set_current_line(105, ng0);
    t2 = ((char*)((ng6)));
    t3 = (t0 + 2248);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 0LL);

LAB106:    goto LAB46;

LAB48:    xsi_set_current_line(67, ng0);
    t56 = ((char*)((ng6)));
    t57 = (t0 + 2248);
    xsi_vlogvar_wait_assign_value(t57, t56, 0, 0, 1, 0LL);
    goto LAB56;

LAB50:    xsi_set_current_line(68, ng0);
    t3 = ((char*)((ng6)));
    t4 = (t0 + 2248);
    xsi_vlogvar_wait_assign_value(t4, t3, 0, 0, 1, 0LL);
    goto LAB56;

LAB52:    xsi_set_current_line(69, ng0);
    t3 = ((char*)((ng6)));
    t4 = (t0 + 2248);
    xsi_vlogvar_wait_assign_value(t4, t3, 0, 0, 1, 0LL);
    goto LAB56;

LAB58:    xsi_set_current_line(74, ng0);
    t10 = ((char*)((ng6)));
    t12 = (t0 + 2248);
    xsi_vlogvar_wait_assign_value(t12, t10, 0, 0, 1, 0LL);
    goto LAB66;

LAB60:    xsi_set_current_line(75, ng0);
    t3 = ((char*)((ng6)));
    t4 = (t0 + 2248);
    xsi_vlogvar_wait_assign_value(t4, t3, 0, 0, 1, 0LL);
    goto LAB66;

LAB62:    xsi_set_current_line(76, ng0);
    t3 = ((char*)((ng6)));
    t4 = (t0 + 2248);
    xsi_vlogvar_wait_assign_value(t4, t3, 0, 0, 1, 0LL);
    goto LAB66;

LAB68:    xsi_set_current_line(81, ng0);
    t10 = ((char*)((ng4)));
    t12 = (t0 + 2248);
    xsi_vlogvar_wait_assign_value(t12, t10, 0, 0, 1, 0LL);
    goto LAB76;

LAB70:    xsi_set_current_line(82, ng0);
    t3 = ((char*)((ng4)));
    t4 = (t0 + 2248);
    xsi_vlogvar_wait_assign_value(t4, t3, 0, 0, 1, 0LL);
    goto LAB76;

LAB72:    xsi_set_current_line(83, ng0);
    t3 = ((char*)((ng4)));
    t4 = (t0 + 2248);
    xsi_vlogvar_wait_assign_value(t4, t3, 0, 0, 1, 0LL);
    goto LAB76;

LAB78:    xsi_set_current_line(88, ng0);
    t10 = ((char*)((ng4)));
    t12 = (t0 + 2248);
    xsi_vlogvar_wait_assign_value(t12, t10, 0, 0, 1, 0LL);
    goto LAB86;

LAB80:    xsi_set_current_line(89, ng0);
    t3 = ((char*)((ng6)));
    t4 = (t0 + 2248);
    xsi_vlogvar_wait_assign_value(t4, t3, 0, 0, 1, 0LL);
    goto LAB86;

LAB82:    xsi_set_current_line(90, ng0);
    t3 = ((char*)((ng6)));
    t4 = (t0 + 2248);
    xsi_vlogvar_wait_assign_value(t4, t3, 0, 0, 1, 0LL);
    goto LAB86;

LAB88:    xsi_set_current_line(95, ng0);
    t10 = ((char*)((ng6)));
    t12 = (t0 + 2248);
    xsi_vlogvar_wait_assign_value(t12, t10, 0, 0, 1, 0LL);
    goto LAB96;

LAB90:    xsi_set_current_line(96, ng0);
    t3 = ((char*)((ng6)));
    t4 = (t0 + 2248);
    xsi_vlogvar_wait_assign_value(t4, t3, 0, 0, 1, 0LL);
    goto LAB96;

LAB92:    xsi_set_current_line(97, ng0);
    t3 = ((char*)((ng6)));
    t4 = (t0 + 2248);
    xsi_vlogvar_wait_assign_value(t4, t3, 0, 0, 1, 0LL);
    goto LAB96;

LAB98:    xsi_set_current_line(102, ng0);
    t10 = ((char*)((ng6)));
    t12 = (t0 + 2248);
    xsi_vlogvar_wait_assign_value(t12, t10, 0, 0, 1, 0LL);
    goto LAB106;

LAB100:    xsi_set_current_line(103, ng0);
    t3 = ((char*)((ng6)));
    t4 = (t0 + 2248);
    xsi_vlogvar_wait_assign_value(t4, t3, 0, 0, 1, 0LL);
    goto LAB106;

LAB102:    xsi_set_current_line(104, ng0);
    t3 = ((char*)((ng6)));
    t4 = (t0 + 2248);
    xsi_vlogvar_wait_assign_value(t4, t3, 0, 0, 1, 0LL);
    goto LAB106;

LAB108:    xsi_set_current_line(109, ng0);
    t9 = ((char*)((ng4)));
    t10 = (t0 + 2248);
    xsi_vlogvar_wait_assign_value(t10, t9, 0, 0, 1, 0LL);
    goto LAB116;

LAB110:    xsi_set_current_line(110, ng0);
    t3 = ((char*)((ng6)));
    t4 = (t0 + 2248);
    xsi_vlogvar_wait_assign_value(t4, t3, 0, 0, 1, 0LL);
    goto LAB116;

LAB112:    xsi_set_current_line(111, ng0);
    t3 = ((char*)((ng6)));
    t4 = (t0 + 2248);
    xsi_vlogvar_wait_assign_value(t4, t3, 0, 0, 1, 0LL);
    goto LAB116;

LAB119:    t9 = (t70 + 4);
    *((unsigned int *)t70) = 1;
    *((unsigned int *)t9) = 1;
    goto LAB120;

LAB121:    xsi_set_current_line(116, ng0);

LAB124:    xsi_set_current_line(117, ng0);
    t12 = ((char*)((ng4)));
    t13 = (t0 + 2728);
    t26 = (t13 + 56U);
    t27 = *((char **)t26);
    memset(t71, 0, 8);
    t33 = (t71 + 4);
    t34 = (t27 + 4);
    t35 = *((unsigned int *)t27);
    t36 = (t35 >> 0);
    *((unsigned int *)t71) = t36;
    t37 = *((unsigned int *)t34);
    t38 = (t37 >> 0);
    *((unsigned int *)t33) = t38;
    t39 = *((unsigned int *)t71);
    *((unsigned int *)t71) = (t39 & 2147483647U);
    t40 = *((unsigned int *)t33);
    *((unsigned int *)t33) = (t40 & 2147483647U);
    xsi_vlogtype_concat(t52, 63, 63, 2U, t71, 31, t12, 32);
    t53 = (t0 + 2728);
    xsi_vlogvar_wait_assign_value(t53, t52, 0, 0, 32, 0LL);
    xsi_set_current_line(118, ng0);
    t2 = ((char*)((ng6)));
    t3 = (t0 + 2888);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    memset(t70, 0, 8);
    t7 = (t70 + 4);
    t8 = (t5 + 4);
    t14 = *((unsigned int *)t5);
    t15 = (t14 >> 0);
    *((unsigned int *)t70) = t15;
    t16 = *((unsigned int *)t8);
    t17 = (t16 >> 0);
    *((unsigned int *)t7) = t17;
    t18 = *((unsigned int *)t70);
    *((unsigned int *)t70) = (t18 & 2147483647U);
    t19 = *((unsigned int *)t7);
    *((unsigned int *)t7) = (t19 & 2147483647U);
    xsi_vlogtype_concat(t52, 63, 63, 2U, t70, 31, t2, 32);
    t9 = (t0 + 2888);
    xsi_vlogvar_wait_assign_value(t9, t52, 0, 0, 32, 0LL);
    xsi_set_current_line(119, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 2568);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 8, 0LL);
    goto LAB123;

}

static void Cont_126_3(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    unsigned int t10;
    unsigned int t11;
    char *t12;
    unsigned int t13;
    unsigned int t14;
    char *t15;
    unsigned int t16;
    unsigned int t17;
    char *t18;

LAB0:    t1 = (t0 + 4712U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(126, ng0);
    t2 = (t0 + 3048);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 5144);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memset(t9, 0, 8);
    t10 = 1U;
    t11 = t10;
    t12 = (t4 + 4);
    t13 = *((unsigned int *)t4);
    t10 = (t10 & t13);
    t14 = *((unsigned int *)t12);
    t11 = (t11 & t14);
    t15 = (t9 + 4);
    t16 = *((unsigned int *)t9);
    *((unsigned int *)t9) = (t16 | t10);
    t17 = *((unsigned int *)t15);
    *((unsigned int *)t15) = (t17 | t11);
    xsi_driver_vfirst_trans(t5, 0, 0);
    t18 = (t0 + 5064);
    *((int *)t18) = 1;

LAB1:    return;
}


extern void work_m_00000000002569896762_0949684337_init()
{
	static char *pe[] = {(void *)Initial_35_0,(void *)Always_41_1,(void *)Always_48_2,(void *)Cont_126_3};
	xsi_register_didat("work_m_00000000002569896762_0949684337", "isim/testing_top_buff_isim_beh.exe.sim/work/m_00000000002569896762_0949684337.didat");
	xsi_register_executes(pe);
}
