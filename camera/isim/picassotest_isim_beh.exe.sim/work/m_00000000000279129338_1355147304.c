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
static const char *ng0 = "//ad/eng/users/m/d/mdean13/Desktop/camera/painter.v";
static unsigned int ng1[] = {0U, 0U};
static int ng2[] = {1, 0};
static int ng3[] = {0, 0};
static unsigned int ng4[] = {80U, 0U};
static unsigned int ng5[] = {720U, 0U};
static unsigned int ng6[] = {719U, 0U};
static unsigned int ng7[] = {3U, 0U};
static unsigned int ng8[] = {639U, 0U};
static unsigned int ng9[] = {1U, 0U};



static void Initial_49_0(char *t0)
{
    char *t1;
    char *t2;

LAB0:    xsi_set_current_line(49, ng0);

LAB2:    xsi_set_current_line(50, ng0);
    t1 = ((char*)((ng1)));
    t2 = (t0 + 3928);
    xsi_vlogvar_wait_assign_value(t2, t1, 0, 0, 11, 0LL);
    xsi_set_current_line(51, ng0);
    t1 = ((char*)((ng1)));
    t2 = (t0 + 4088);
    xsi_vlogvar_wait_assign_value(t2, t1, 0, 0, 10, 0LL);
    xsi_set_current_line(52, ng0);
    t1 = ((char*)((ng1)));
    t2 = (t0 + 4248);
    xsi_vlogvar_wait_assign_value(t2, t1, 0, 0, 17, 0LL);
    xsi_set_current_line(53, ng0);
    t1 = ((char*)((ng2)));
    t2 = (t0 + 4408);
    xsi_vlogvar_wait_assign_value(t2, t1, 0, 0, 1, 0LL);

LAB1:    return;
}

static void Always_56_1(char *t0)
{
    char t9[8];
    char t10[8];
    char t41[8];
    char t45[8];
    char t48[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    char *t11;
    char *t12;
    unsigned int t13;
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
    char *t25;
    char *t26;
    unsigned int t27;
    unsigned int t28;
    unsigned int t29;
    unsigned int t30;
    unsigned int t31;
    char *t32;
    char *t33;
    unsigned int t34;
    unsigned int t35;
    unsigned int t36;
    unsigned int t37;
    unsigned int t38;
    unsigned int t39;
    char *t40;
    char *t42;
    char *t43;
    char *t44;
    char *t46;
    char *t47;
    char *t49;
    char *t50;
    char *t51;
    char *t52;
    char *t53;
    unsigned int t54;
    unsigned int t55;
    unsigned int t56;
    unsigned int t57;
    unsigned int t58;
    unsigned int t59;
    unsigned int t60;
    unsigned int t61;
    int t62;
    int t63;
    unsigned int t64;
    unsigned int t65;
    unsigned int t66;
    unsigned int t67;
    unsigned int t68;
    unsigned int t69;
    char *t70;
    unsigned int t71;
    unsigned int t72;
    unsigned int t73;
    unsigned int t74;
    unsigned int t75;
    char *t76;
    char *t77;

LAB0:    t1 = (t0 + 5576U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(56, ng0);
    t2 = (t0 + 6144);
    *((int *)t2) = 1;
    t3 = (t0 + 5608);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(56, ng0);

LAB5:    xsi_set_current_line(58, ng0);
    t4 = (t0 + 3928);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t0 + 744);
    t8 = *((char **)t7);
    t7 = ((char*)((ng2)));
    memset(t9, 0, 8);
    xsi_vlog_unsigned_minus(t9, 32, t8, 32, t7, 32);
    memset(t10, 0, 8);
    t11 = (t6 + 4);
    t12 = (t9 + 4);
    t13 = *((unsigned int *)t6);
    t14 = *((unsigned int *)t9);
    t15 = (t13 ^ t14);
    t16 = *((unsigned int *)t11);
    t17 = *((unsigned int *)t12);
    t18 = (t16 ^ t17);
    t19 = (t15 | t18);
    t20 = *((unsigned int *)t11);
    t21 = *((unsigned int *)t12);
    t22 = (t20 | t21);
    t23 = (~(t22));
    t24 = (t19 & t23);
    if (t24 != 0)
        goto LAB9;

LAB6:    if (t22 != 0)
        goto LAB8;

LAB7:    *((unsigned int *)t10) = 1;

LAB9:    t26 = (t10 + 4);
    t27 = *((unsigned int *)t26);
    t28 = (~(t27));
    t29 = *((unsigned int *)t10);
    t30 = (t29 & t28);
    t31 = (t30 != 0);
    if (t31 > 0)
        goto LAB10;

LAB11:    xsi_set_current_line(66, ng0);
    t2 = (t0 + 3928);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng2)));
    memset(t9, 0, 8);
    xsi_vlog_unsigned_add(t9, 32, t4, 11, t5, 32);
    t6 = (t0 + 3928);
    xsi_vlogvar_wait_assign_value(t6, t9, 0, 0, 11, 0LL);

LAB12:    xsi_set_current_line(68, ng0);
    t2 = (t0 + 4408);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng3)));
    memset(t9, 0, 8);
    t6 = (t4 + 4);
    t7 = (t5 + 4);
    t13 = *((unsigned int *)t4);
    t14 = *((unsigned int *)t5);
    t15 = (t13 ^ t14);
    t16 = *((unsigned int *)t6);
    t17 = *((unsigned int *)t7);
    t18 = (t16 ^ t17);
    t19 = (t15 | t18);
    t20 = *((unsigned int *)t6);
    t21 = *((unsigned int *)t7);
    t22 = (t20 | t21);
    t23 = (~(t22));
    t24 = (t19 & t23);
    if (t24 != 0)
        goto LAB24;

LAB21:    if (t22 != 0)
        goto LAB23;

LAB22:    *((unsigned int *)t9) = 1;

LAB24:    t11 = (t9 + 4);
    t27 = *((unsigned int *)t11);
    t28 = (~(t27));
    t29 = *((unsigned int *)t9);
    t30 = (t29 & t28);
    t31 = (t30 != 0);
    if (t31 > 0)
        goto LAB25;

LAB26:    xsi_set_current_line(73, ng0);

LAB29:    xsi_set_current_line(74, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 3128);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 3, 0LL);
    xsi_set_current_line(75, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 3288);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 3, 0LL);
    xsi_set_current_line(76, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 3448);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 2, 0LL);

LAB27:    xsi_set_current_line(79, ng0);
    t2 = (t0 + 4088);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 608);
    t6 = *((char **)t5);
    memset(t9, 0, 8);
    t5 = (t4 + 4);
    if (*((unsigned int *)t5) != 0)
        goto LAB31;

LAB30:    t7 = (t6 + 4);
    if (*((unsigned int *)t7) != 0)
        goto LAB31;

LAB34:    if (*((unsigned int *)t4) < *((unsigned int *)t6))
        goto LAB33;

LAB32:    *((unsigned int *)t9) = 1;

LAB33:    t11 = (t9 + 4);
    t13 = *((unsigned int *)t11);
    t14 = (~(t13));
    t15 = *((unsigned int *)t9);
    t16 = (t15 & t14);
    t17 = (t16 != 0);
    if (t17 > 0)
        goto LAB35;

LAB36:    xsi_set_current_line(84, ng0);
    t2 = (t0 + 3928);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng4)));
    memset(t9, 0, 8);
    t6 = (t4 + 4);
    if (*((unsigned int *)t6) != 0)
        goto LAB40;

LAB39:    t7 = (t5 + 4);
    if (*((unsigned int *)t7) != 0)
        goto LAB40;

LAB43:    if (*((unsigned int *)t4) < *((unsigned int *)t5))
        goto LAB42;

LAB41:    *((unsigned int *)t9) = 1;

LAB42:    memset(t10, 0, 8);
    t11 = (t9 + 4);
    t13 = *((unsigned int *)t11);
    t14 = (~(t13));
    t15 = *((unsigned int *)t9);
    t16 = (t15 & t14);
    t17 = (t16 & 1U);
    if (t17 != 0)
        goto LAB44;

LAB45:    if (*((unsigned int *)t11) != 0)
        goto LAB46;

LAB47:    t25 = (t10 + 4);
    t18 = *((unsigned int *)t10);
    t19 = *((unsigned int *)t25);
    t20 = (t18 || t19);
    if (t20 > 0)
        goto LAB48;

LAB49:    memcpy(t48, t10, 8);

LAB50:    t70 = (t48 + 4);
    t71 = *((unsigned int *)t70);
    t72 = (~(t71));
    t73 = *((unsigned int *)t48);
    t74 = (t73 & t72);
    t75 = (t74 != 0);
    if (t75 > 0)
        goto LAB63;

LAB64:    xsi_set_current_line(96, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 4408);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 0LL);

LAB65:
LAB37:    xsi_set_current_line(99, ng0);
    t2 = (t0 + 3928);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 880);
    t6 = *((char **)t5);
    memset(t9, 0, 8);
    t5 = (t4 + 4);
    if (*((unsigned int *)t5) != 0)
        goto LAB83;

LAB82:    t7 = (t6 + 4);
    if (*((unsigned int *)t7) != 0)
        goto LAB83;

LAB86:    if (*((unsigned int *)t4) > *((unsigned int *)t6))
        goto LAB84;

LAB85:    memset(t10, 0, 8);
    t11 = (t9 + 4);
    t13 = *((unsigned int *)t11);
    t14 = (~(t13));
    t15 = *((unsigned int *)t9);
    t16 = (t15 & t14);
    t17 = (t16 & 1U);
    if (t17 != 0)
        goto LAB87;

LAB88:    if (*((unsigned int *)t11) != 0)
        goto LAB89;

LAB90:    t25 = (t10 + 4);
    t18 = *((unsigned int *)t10);
    t19 = *((unsigned int *)t25);
    t20 = (t18 || t19);
    if (t20 > 0)
        goto LAB91;

LAB92:    memcpy(t48, t10, 8);

LAB93:    t70 = (t48 + 4);
    t71 = *((unsigned int *)t70);
    t72 = (~(t71));
    t73 = *((unsigned int *)t48);
    t74 = (t73 & t72);
    t75 = (t74 != 0);
    if (t75 > 0)
        goto LAB106;

LAB107:    xsi_set_current_line(102, ng0);
    t2 = ((char*)((ng9)));
    memset(t9, 0, 8);
    t3 = (t2 + 4);
    t13 = *((unsigned int *)t3);
    t14 = (~(t13));
    t15 = *((unsigned int *)t2);
    t16 = (t15 & t14);
    t17 = (t16 & 1U);
    if (t17 != 0)
        goto LAB112;

LAB110:    if (*((unsigned int *)t3) == 0)
        goto LAB109;

LAB111:    t4 = (t9 + 4);
    *((unsigned int *)t9) = 1;
    *((unsigned int *)t4) = 1;

LAB112:    t5 = (t9 + 4);
    t6 = (t2 + 4);
    t18 = *((unsigned int *)t2);
    t19 = (~(t18));
    *((unsigned int *)t9) = t19;
    *((unsigned int *)t5) = 0;
    if (*((unsigned int *)t6) != 0)
        goto LAB114;

LAB113:    t24 = *((unsigned int *)t9);
    *((unsigned int *)t9) = (t24 & 1U);
    t27 = *((unsigned int *)t5);
    *((unsigned int *)t5) = (t27 & 1U);
    t7 = (t0 + 3608);
    xsi_vlogvar_wait_assign_value(t7, t9, 0, 0, 1, 0LL);

LAB108:    xsi_set_current_line(105, ng0);
    t2 = (t0 + 4088);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 1288);
    t6 = *((char **)t5);
    memset(t9, 0, 8);
    t5 = (t4 + 4);
    if (*((unsigned int *)t5) != 0)
        goto LAB116;

LAB115:    t7 = (t6 + 4);
    if (*((unsigned int *)t7) != 0)
        goto LAB116;

LAB119:    if (*((unsigned int *)t4) < *((unsigned int *)t6))
        goto LAB118;

LAB117:    *((unsigned int *)t9) = 1;

LAB118:    memset(t10, 0, 8);
    t11 = (t9 + 4);
    t13 = *((unsigned int *)t11);
    t14 = (~(t13));
    t15 = *((unsigned int *)t9);
    t16 = (t15 & t14);
    t17 = (t16 & 1U);
    if (t17 != 0)
        goto LAB120;

LAB121:    if (*((unsigned int *)t11) != 0)
        goto LAB122;

LAB123:    t25 = (t10 + 4);
    t18 = *((unsigned int *)t10);
    t19 = *((unsigned int *)t25);
    t20 = (t18 || t19);
    if (t20 > 0)
        goto LAB124;

LAB125:    memcpy(t48, t10, 8);

LAB126:    t70 = (t48 + 4);
    t71 = *((unsigned int *)t70);
    t72 = (~(t71));
    t73 = *((unsigned int *)t48);
    t74 = (t73 & t72);
    t75 = (t74 != 0);
    if (t75 > 0)
        goto LAB139;

LAB140:    xsi_set_current_line(108, ng0);
    t2 = ((char*)((ng9)));
    memset(t9, 0, 8);
    t3 = (t2 + 4);
    t13 = *((unsigned int *)t3);
    t14 = (~(t13));
    t15 = *((unsigned int *)t2);
    t16 = (t15 & t14);
    t17 = (t16 & 1U);
    if (t17 != 0)
        goto LAB145;

LAB143:    if (*((unsigned int *)t3) == 0)
        goto LAB142;

LAB144:    t4 = (t9 + 4);
    *((unsigned int *)t9) = 1;
    *((unsigned int *)t4) = 1;

LAB145:    t5 = (t9 + 4);
    t6 = (t2 + 4);
    t18 = *((unsigned int *)t2);
    t19 = (~(t18));
    *((unsigned int *)t9) = t19;
    *((unsigned int *)t5) = 0;
    if (*((unsigned int *)t6) != 0)
        goto LAB147;

LAB146:    t24 = *((unsigned int *)t9);
    *((unsigned int *)t9) = (t24 & 1U);
    t27 = *((unsigned int *)t5);
    *((unsigned int *)t5) = (t27 & 1U);
    t7 = (t0 + 3768);
    xsi_vlogvar_wait_assign_value(t7, t9, 0, 0, 1, 0LL);

LAB141:    goto LAB2;

LAB8:    t25 = (t10 + 4);
    *((unsigned int *)t10) = 1;
    *((unsigned int *)t25) = 1;
    goto LAB9;

LAB10:    xsi_set_current_line(58, ng0);

LAB13:    xsi_set_current_line(59, ng0);
    t32 = ((char*)((ng1)));
    t33 = (t0 + 3928);
    xsi_vlogvar_wait_assign_value(t33, t32, 0, 0, 11, 0LL);
    xsi_set_current_line(60, ng0);
    t2 = (t0 + 4088);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 1152);
    t6 = *((char **)t5);
    t5 = ((char*)((ng2)));
    memset(t9, 0, 8);
    xsi_vlog_unsigned_minus(t9, 32, t6, 32, t5, 32);
    memset(t10, 0, 8);
    t7 = (t4 + 4);
    t8 = (t9 + 4);
    t13 = *((unsigned int *)t4);
    t14 = *((unsigned int *)t9);
    t15 = (t13 ^ t14);
    t16 = *((unsigned int *)t7);
    t17 = *((unsigned int *)t8);
    t18 = (t16 ^ t17);
    t19 = (t15 | t18);
    t20 = *((unsigned int *)t7);
    t21 = *((unsigned int *)t8);
    t22 = (t20 | t21);
    t23 = (~(t22));
    t24 = (t19 & t23);
    if (t24 != 0)
        goto LAB17;

LAB14:    if (t22 != 0)
        goto LAB16;

LAB15:    *((unsigned int *)t10) = 1;

LAB17:    t12 = (t10 + 4);
    t27 = *((unsigned int *)t12);
    t28 = (~(t27));
    t29 = *((unsigned int *)t10);
    t30 = (t29 & t28);
    t31 = (t30 != 0);
    if (t31 > 0)
        goto LAB18;

LAB19:    xsi_set_current_line(63, ng0);
    t2 = (t0 + 4088);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng2)));
    memset(t9, 0, 8);
    xsi_vlog_unsigned_add(t9, 32, t4, 10, t5, 32);
    t6 = (t0 + 4088);
    xsi_vlogvar_wait_assign_value(t6, t9, 0, 0, 10, 0LL);

LAB20:    goto LAB12;

LAB16:    t11 = (t10 + 4);
    *((unsigned int *)t10) = 1;
    *((unsigned int *)t11) = 1;
    goto LAB17;

LAB18:    xsi_set_current_line(61, ng0);
    t25 = ((char*)((ng1)));
    t26 = (t0 + 4088);
    xsi_vlogvar_wait_assign_value(t26, t25, 0, 0, 10, 0LL);
    goto LAB20;

LAB23:    t8 = (t9 + 4);
    *((unsigned int *)t9) = 1;
    *((unsigned int *)t8) = 1;
    goto LAB24;

LAB25:    xsi_set_current_line(68, ng0);

LAB28:    xsi_set_current_line(69, ng0);
    t12 = (t0 + 2568U);
    t25 = *((char **)t12);
    memset(t10, 0, 8);
    t12 = (t10 + 4);
    t26 = (t25 + 4);
    t34 = *((unsigned int *)t25);
    t35 = (t34 >> 5);
    *((unsigned int *)t10) = t35;
    t36 = *((unsigned int *)t26);
    t37 = (t36 >> 5);
    *((unsigned int *)t12) = t37;
    t38 = *((unsigned int *)t10);
    *((unsigned int *)t10) = (t38 & 7U);
    t39 = *((unsigned int *)t12);
    *((unsigned int *)t12) = (t39 & 7U);
    t32 = (t0 + 3128);
    xsi_vlogvar_wait_assign_value(t32, t10, 0, 0, 3, 0LL);
    xsi_set_current_line(70, ng0);
    t2 = (t0 + 2568U);
    t3 = *((char **)t2);
    memset(t9, 0, 8);
    t2 = (t9 + 4);
    t4 = (t3 + 4);
    t13 = *((unsigned int *)t3);
    t14 = (t13 >> 2);
    *((unsigned int *)t9) = t14;
    t15 = *((unsigned int *)t4);
    t16 = (t15 >> 2);
    *((unsigned int *)t2) = t16;
    t17 = *((unsigned int *)t9);
    *((unsigned int *)t9) = (t17 & 7U);
    t18 = *((unsigned int *)t2);
    *((unsigned int *)t2) = (t18 & 7U);
    t5 = (t0 + 3288);
    xsi_vlogvar_wait_assign_value(t5, t9, 0, 0, 3, 0LL);
    xsi_set_current_line(71, ng0);
    t2 = (t0 + 2568U);
    t3 = *((char **)t2);
    memset(t9, 0, 8);
    t2 = (t9 + 4);
    t4 = (t3 + 4);
    t13 = *((unsigned int *)t3);
    t14 = (t13 >> 0);
    *((unsigned int *)t9) = t14;
    t15 = *((unsigned int *)t4);
    t16 = (t15 >> 0);
    *((unsigned int *)t2) = t16;
    t17 = *((unsigned int *)t9);
    *((unsigned int *)t9) = (t17 & 3U);
    t18 = *((unsigned int *)t2);
    *((unsigned int *)t2) = (t18 & 3U);
    t5 = (t0 + 3448);
    xsi_vlogvar_wait_assign_value(t5, t9, 0, 0, 2, 0LL);
    goto LAB27;

LAB31:    t8 = (t9 + 4);
    *((unsigned int *)t9) = 1;
    *((unsigned int *)t8) = 1;
    goto LAB33;

LAB35:    xsi_set_current_line(79, ng0);

LAB38:    xsi_set_current_line(80, ng0);
    t12 = ((char*)((ng1)));
    t25 = (t0 + 4248);
    xsi_vlogvar_wait_assign_value(t25, t12, 0, 0, 17, 0LL);
    xsi_set_current_line(81, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 4408);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 0LL);
    goto LAB37;

LAB40:    t8 = (t9 + 4);
    *((unsigned int *)t9) = 1;
    *((unsigned int *)t8) = 1;
    goto LAB42;

LAB44:    *((unsigned int *)t10) = 1;
    goto LAB47;

LAB46:    t12 = (t10 + 4);
    *((unsigned int *)t10) = 1;
    *((unsigned int *)t12) = 1;
    goto LAB47;

LAB48:    t26 = (t0 + 3928);
    t32 = (t26 + 56U);
    t33 = *((char **)t32);
    t40 = ((char*)((ng5)));
    memset(t41, 0, 8);
    t42 = (t33 + 4);
    if (*((unsigned int *)t42) != 0)
        goto LAB52;

LAB51:    t43 = (t40 + 4);
    if (*((unsigned int *)t43) != 0)
        goto LAB52;

LAB55:    if (*((unsigned int *)t33) < *((unsigned int *)t40))
        goto LAB53;

LAB54:    memset(t45, 0, 8);
    t46 = (t41 + 4);
    t21 = *((unsigned int *)t46);
    t22 = (~(t21));
    t23 = *((unsigned int *)t41);
    t24 = (t23 & t22);
    t27 = (t24 & 1U);
    if (t27 != 0)
        goto LAB56;

LAB57:    if (*((unsigned int *)t46) != 0)
        goto LAB58;

LAB59:    t28 = *((unsigned int *)t10);
    t29 = *((unsigned int *)t45);
    t30 = (t28 & t29);
    *((unsigned int *)t48) = t30;
    t49 = (t10 + 4);
    t50 = (t45 + 4);
    t51 = (t48 + 4);
    t31 = *((unsigned int *)t49);
    t34 = *((unsigned int *)t50);
    t35 = (t31 | t34);
    *((unsigned int *)t51) = t35;
    t36 = *((unsigned int *)t51);
    t37 = (t36 != 0);
    if (t37 == 1)
        goto LAB60;

LAB61:
LAB62:    goto LAB50;

LAB52:    t44 = (t41 + 4);
    *((unsigned int *)t41) = 1;
    *((unsigned int *)t44) = 1;
    goto LAB54;

LAB53:    *((unsigned int *)t41) = 1;
    goto LAB54;

LAB56:    *((unsigned int *)t45) = 1;
    goto LAB59;

LAB58:    t47 = (t45 + 4);
    *((unsigned int *)t45) = 1;
    *((unsigned int *)t47) = 1;
    goto LAB59;

LAB60:    t38 = *((unsigned int *)t48);
    t39 = *((unsigned int *)t51);
    *((unsigned int *)t48) = (t38 | t39);
    t52 = (t10 + 4);
    t53 = (t45 + 4);
    t54 = *((unsigned int *)t10);
    t55 = (~(t54));
    t56 = *((unsigned int *)t52);
    t57 = (~(t56));
    t58 = *((unsigned int *)t45);
    t59 = (~(t58));
    t60 = *((unsigned int *)t53);
    t61 = (~(t60));
    t62 = (t55 & t57);
    t63 = (t59 & t61);
    t64 = (~(t62));
    t65 = (~(t63));
    t66 = *((unsigned int *)t51);
    *((unsigned int *)t51) = (t66 & t64);
    t67 = *((unsigned int *)t51);
    *((unsigned int *)t51) = (t67 & t65);
    t68 = *((unsigned int *)t48);
    *((unsigned int *)t48) = (t68 & t64);
    t69 = *((unsigned int *)t48);
    *((unsigned int *)t48) = (t69 & t65);
    goto LAB62;

LAB63:    xsi_set_current_line(84, ng0);

LAB66:    xsi_set_current_line(85, ng0);
    t76 = ((char*)((ng3)));
    t77 = (t0 + 4408);
    xsi_vlogvar_wait_assign_value(t77, t76, 0, 0, 1, 0LL);
    xsi_set_current_line(86, ng0);
    t2 = (t0 + 3928);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng6)));
    memset(t9, 0, 8);
    t6 = (t4 + 4);
    t7 = (t5 + 4);
    t13 = *((unsigned int *)t4);
    t14 = *((unsigned int *)t5);
    t15 = (t13 ^ t14);
    t16 = *((unsigned int *)t6);
    t17 = *((unsigned int *)t7);
    t18 = (t16 ^ t17);
    t19 = (t15 | t18);
    t20 = *((unsigned int *)t6);
    t21 = *((unsigned int *)t7);
    t22 = (t20 | t21);
    t23 = (~(t22));
    t24 = (t19 & t23);
    if (t24 != 0)
        goto LAB70;

LAB67:    if (t22 != 0)
        goto LAB69;

LAB68:    *((unsigned int *)t9) = 1;

LAB70:    t11 = (t9 + 4);
    t27 = *((unsigned int *)t11);
    t28 = (~(t27));
    t29 = *((unsigned int *)t9);
    t30 = (t29 & t28);
    t31 = (t30 != 0);
    if (t31 > 0)
        goto LAB71;

LAB72:    xsi_set_current_line(93, ng0);
    t2 = (t0 + 4248);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng2)));
    memset(t9, 0, 8);
    xsi_vlog_unsigned_add(t9, 32, t4, 17, t5, 32);
    t6 = (t0 + 4248);
    xsi_vlogvar_wait_assign_value(t6, t9, 0, 0, 17, 0LL);

LAB73:    goto LAB65;

LAB69:    t8 = (t9 + 4);
    *((unsigned int *)t9) = 1;
    *((unsigned int *)t8) = 1;
    goto LAB70;

LAB71:    xsi_set_current_line(86, ng0);

LAB74:    xsi_set_current_line(87, ng0);
    t12 = (t0 + 4088);
    t25 = (t12 + 56U);
    t26 = *((char **)t25);
    memset(t10, 0, 8);
    t32 = (t10 + 4);
    t33 = (t26 + 4);
    t34 = *((unsigned int *)t26);
    t35 = (t34 >> 0);
    *((unsigned int *)t10) = t35;
    t36 = *((unsigned int *)t33);
    t37 = (t36 >> 0);
    *((unsigned int *)t32) = t37;
    t38 = *((unsigned int *)t10);
    *((unsigned int *)t10) = (t38 & 3U);
    t39 = *((unsigned int *)t32);
    *((unsigned int *)t32) = (t39 & 3U);
    t40 = ((char*)((ng7)));
    memset(t41, 0, 8);
    t42 = (t10 + 4);
    t43 = (t40 + 4);
    t54 = *((unsigned int *)t10);
    t55 = *((unsigned int *)t40);
    t56 = (t54 ^ t55);
    t57 = *((unsigned int *)t42);
    t58 = *((unsigned int *)t43);
    t59 = (t57 ^ t58);
    t60 = (t56 | t59);
    t61 = *((unsigned int *)t42);
    t64 = *((unsigned int *)t43);
    t65 = (t61 | t64);
    t66 = (~(t65));
    t67 = (t60 & t66);
    if (t67 != 0)
        goto LAB76;

LAB75:    if (t65 != 0)
        goto LAB77;

LAB78:    t46 = (t41 + 4);
    t68 = *((unsigned int *)t46);
    t69 = (~(t68));
    t71 = *((unsigned int *)t41);
    t72 = (t71 & t69);
    t73 = (t72 != 0);
    if (t73 > 0)
        goto LAB79;

LAB80:    xsi_set_current_line(90, ng0);
    t2 = (t0 + 4248);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng2)));
    memset(t9, 0, 8);
    xsi_vlog_unsigned_add(t9, 32, t4, 17, t5, 32);
    t6 = (t0 + 4248);
    xsi_vlogvar_wait_assign_value(t6, t9, 0, 0, 17, 0LL);

LAB81:    goto LAB73;

LAB76:    *((unsigned int *)t41) = 1;
    goto LAB78;

LAB77:    t44 = (t41 + 4);
    *((unsigned int *)t41) = 1;
    *((unsigned int *)t44) = 1;
    goto LAB78;

LAB79:    xsi_set_current_line(88, ng0);
    t47 = (t0 + 4248);
    t49 = (t47 + 56U);
    t50 = *((char **)t49);
    t51 = ((char*)((ng8)));
    memset(t45, 0, 8);
    xsi_vlog_unsigned_minus(t45, 17, t50, 17, t51, 17);
    t52 = (t0 + 4248);
    xsi_vlogvar_wait_assign_value(t52, t45, 0, 0, 17, 0LL);
    goto LAB81;

LAB83:    t8 = (t9 + 4);
    *((unsigned int *)t9) = 1;
    *((unsigned int *)t8) = 1;
    goto LAB85;

LAB84:    *((unsigned int *)t9) = 1;
    goto LAB85;

LAB87:    *((unsigned int *)t10) = 1;
    goto LAB90;

LAB89:    t12 = (t10 + 4);
    *((unsigned int *)t10) = 1;
    *((unsigned int *)t12) = 1;
    goto LAB90;

LAB91:    t26 = (t0 + 3928);
    t32 = (t26 + 56U);
    t33 = *((char **)t32);
    t40 = (t0 + 1016);
    t42 = *((char **)t40);
    memset(t41, 0, 8);
    t40 = (t33 + 4);
    if (*((unsigned int *)t40) != 0)
        goto LAB95;

LAB94:    t43 = (t42 + 4);
    if (*((unsigned int *)t43) != 0)
        goto LAB95;

LAB98:    if (*((unsigned int *)t33) > *((unsigned int *)t42))
        goto LAB97;

LAB96:    *((unsigned int *)t41) = 1;

LAB97:    memset(t45, 0, 8);
    t46 = (t41 + 4);
    t21 = *((unsigned int *)t46);
    t22 = (~(t21));
    t23 = *((unsigned int *)t41);
    t24 = (t23 & t22);
    t27 = (t24 & 1U);
    if (t27 != 0)
        goto LAB99;

LAB100:    if (*((unsigned int *)t46) != 0)
        goto LAB101;

LAB102:    t28 = *((unsigned int *)t10);
    t29 = *((unsigned int *)t45);
    t30 = (t28 & t29);
    *((unsigned int *)t48) = t30;
    t49 = (t10 + 4);
    t50 = (t45 + 4);
    t51 = (t48 + 4);
    t31 = *((unsigned int *)t49);
    t34 = *((unsigned int *)t50);
    t35 = (t31 | t34);
    *((unsigned int *)t51) = t35;
    t36 = *((unsigned int *)t51);
    t37 = (t36 != 0);
    if (t37 == 1)
        goto LAB103;

LAB104:
LAB105:    goto LAB93;

LAB95:    t44 = (t41 + 4);
    *((unsigned int *)t41) = 1;
    *((unsigned int *)t44) = 1;
    goto LAB97;

LAB99:    *((unsigned int *)t45) = 1;
    goto LAB102;

LAB101:    t47 = (t45 + 4);
    *((unsigned int *)t45) = 1;
    *((unsigned int *)t47) = 1;
    goto LAB102;

LAB103:    t38 = *((unsigned int *)t48);
    t39 = *((unsigned int *)t51);
    *((unsigned int *)t48) = (t38 | t39);
    t52 = (t10 + 4);
    t53 = (t45 + 4);
    t54 = *((unsigned int *)t10);
    t55 = (~(t54));
    t56 = *((unsigned int *)t52);
    t57 = (~(t56));
    t58 = *((unsigned int *)t45);
    t59 = (~(t58));
    t60 = *((unsigned int *)t53);
    t61 = (~(t60));
    t62 = (t55 & t57);
    t63 = (t59 & t61);
    t64 = (~(t62));
    t65 = (~(t63));
    t66 = *((unsigned int *)t51);
    *((unsigned int *)t51) = (t66 & t64);
    t67 = *((unsigned int *)t51);
    *((unsigned int *)t51) = (t67 & t65);
    t68 = *((unsigned int *)t48);
    *((unsigned int *)t48) = (t68 & t64);
    t69 = *((unsigned int *)t48);
    *((unsigned int *)t48) = (t69 & t65);
    goto LAB105;

LAB106:    xsi_set_current_line(100, ng0);
    t76 = ((char*)((ng9)));
    t77 = (t0 + 3608);
    xsi_vlogvar_wait_assign_value(t77, t76, 0, 0, 1, 0LL);
    goto LAB108;

LAB109:    *((unsigned int *)t9) = 1;
    goto LAB112;

LAB114:    t20 = *((unsigned int *)t9);
    t21 = *((unsigned int *)t6);
    *((unsigned int *)t9) = (t20 | t21);
    t22 = *((unsigned int *)t5);
    t23 = *((unsigned int *)t6);
    *((unsigned int *)t5) = (t22 | t23);
    goto LAB113;

LAB116:    t8 = (t9 + 4);
    *((unsigned int *)t9) = 1;
    *((unsigned int *)t8) = 1;
    goto LAB118;

LAB120:    *((unsigned int *)t10) = 1;
    goto LAB123;

LAB122:    t12 = (t10 + 4);
    *((unsigned int *)t10) = 1;
    *((unsigned int *)t12) = 1;
    goto LAB123;

LAB124:    t26 = (t0 + 4088);
    t32 = (t26 + 56U);
    t33 = *((char **)t32);
    t40 = (t0 + 1424);
    t42 = *((char **)t40);
    memset(t41, 0, 8);
    t40 = (t33 + 4);
    if (*((unsigned int *)t40) != 0)
        goto LAB128;

LAB127:    t43 = (t42 + 4);
    if (*((unsigned int *)t43) != 0)
        goto LAB128;

LAB131:    if (*((unsigned int *)t33) < *((unsigned int *)t42))
        goto LAB129;

LAB130:    memset(t45, 0, 8);
    t46 = (t41 + 4);
    t21 = *((unsigned int *)t46);
    t22 = (~(t21));
    t23 = *((unsigned int *)t41);
    t24 = (t23 & t22);
    t27 = (t24 & 1U);
    if (t27 != 0)
        goto LAB132;

LAB133:    if (*((unsigned int *)t46) != 0)
        goto LAB134;

LAB135:    t28 = *((unsigned int *)t10);
    t29 = *((unsigned int *)t45);
    t30 = (t28 & t29);
    *((unsigned int *)t48) = t30;
    t49 = (t10 + 4);
    t50 = (t45 + 4);
    t51 = (t48 + 4);
    t31 = *((unsigned int *)t49);
    t34 = *((unsigned int *)t50);
    t35 = (t31 | t34);
    *((unsigned int *)t51) = t35;
    t36 = *((unsigned int *)t51);
    t37 = (t36 != 0);
    if (t37 == 1)
        goto LAB136;

LAB137:
LAB138:    goto LAB126;

LAB128:    t44 = (t41 + 4);
    *((unsigned int *)t41) = 1;
    *((unsigned int *)t44) = 1;
    goto LAB130;

LAB129:    *((unsigned int *)t41) = 1;
    goto LAB130;

LAB132:    *((unsigned int *)t45) = 1;
    goto LAB135;

LAB134:    t47 = (t45 + 4);
    *((unsigned int *)t45) = 1;
    *((unsigned int *)t47) = 1;
    goto LAB135;

LAB136:    t38 = *((unsigned int *)t48);
    t39 = *((unsigned int *)t51);
    *((unsigned int *)t48) = (t38 | t39);
    t52 = (t10 + 4);
    t53 = (t45 + 4);
    t54 = *((unsigned int *)t10);
    t55 = (~(t54));
    t56 = *((unsigned int *)t52);
    t57 = (~(t56));
    t58 = *((unsigned int *)t45);
    t59 = (~(t58));
    t60 = *((unsigned int *)t53);
    t61 = (~(t60));
    t62 = (t55 & t57);
    t63 = (t59 & t61);
    t64 = (~(t62));
    t65 = (~(t63));
    t66 = *((unsigned int *)t51);
    *((unsigned int *)t51) = (t66 & t64);
    t67 = *((unsigned int *)t51);
    *((unsigned int *)t51) = (t67 & t65);
    t68 = *((unsigned int *)t48);
    *((unsigned int *)t48) = (t68 & t64);
    t69 = *((unsigned int *)t48);
    *((unsigned int *)t48) = (t69 & t65);
    goto LAB138;

LAB139:    xsi_set_current_line(106, ng0);
    t76 = ((char*)((ng9)));
    t77 = (t0 + 3768);
    xsi_vlogvar_wait_assign_value(t77, t76, 0, 0, 1, 0LL);
    goto LAB141;

LAB142:    *((unsigned int *)t9) = 1;
    goto LAB145;

LAB147:    t20 = *((unsigned int *)t9);
    t21 = *((unsigned int *)t6);
    *((unsigned int *)t9) = (t20 | t21);
    t22 = *((unsigned int *)t5);
    t23 = *((unsigned int *)t6);
    *((unsigned int *)t5) = (t22 | t23);
    goto LAB146;

}

static void Cont_111_2(char *t0)
{
    char t3[8];
    char *t1;
    char *t2;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    char *t14;
    char *t15;
    char *t16;
    char *t17;
    char *t18;
    unsigned int t19;
    unsigned int t20;
    char *t21;
    unsigned int t22;
    unsigned int t23;
    char *t24;
    unsigned int t25;
    unsigned int t26;
    char *t27;

LAB0:    t1 = (t0 + 5824U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(111, ng0);
    t2 = (t0 + 4248);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    memset(t3, 0, 8);
    t6 = (t3 + 4);
    t7 = (t5 + 4);
    t8 = *((unsigned int *)t5);
    t9 = (t8 >> 2);
    *((unsigned int *)t3) = t9;
    t10 = *((unsigned int *)t7);
    t11 = (t10 >> 2);
    *((unsigned int *)t6) = t11;
    t12 = *((unsigned int *)t3);
    *((unsigned int *)t3) = (t12 & 32767U);
    t13 = *((unsigned int *)t6);
    *((unsigned int *)t6) = (t13 & 32767U);
    t14 = (t0 + 6240);
    t15 = (t14 + 56U);
    t16 = *((char **)t15);
    t17 = (t16 + 56U);
    t18 = *((char **)t17);
    memset(t18, 0, 8);
    t19 = 32767U;
    t20 = t19;
    t21 = (t3 + 4);
    t22 = *((unsigned int *)t3);
    t19 = (t19 & t22);
    t23 = *((unsigned int *)t21);
    t20 = (t20 & t23);
    t24 = (t18 + 4);
    t25 = *((unsigned int *)t18);
    *((unsigned int *)t18) = (t25 | t19);
    t26 = *((unsigned int *)t24);
    *((unsigned int *)t24) = (t26 | t20);
    xsi_driver_vfirst_trans(t14, 0, 14);
    t27 = (t0 + 6160);
    *((int *)t27) = 1;

LAB1:    return;
}


extern void work_m_00000000000279129338_1355147304_init()
{
	static char *pe[] = {(void *)Initial_49_0,(void *)Always_56_1,(void *)Cont_111_2};
	xsi_register_didat("work_m_00000000000279129338_1355147304", "isim/picassotest_isim_beh.exe.sim/work/m_00000000000279129338_1355147304.didat");
	xsi_register_executes(pe);
}
