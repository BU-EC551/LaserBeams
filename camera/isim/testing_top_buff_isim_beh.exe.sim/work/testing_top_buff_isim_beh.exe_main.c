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

#include "xsi.h"

struct XSI_INFO xsi_info;



int main(int argc, char **argv)
{
    xsi_init_design(argc, argv);
    xsi_register_info(&xsi_info);

    xsi_register_min_prec_unit(-12);
    work_m_00000000003333589210_0975962166_init();
    work_m_00000000003365700769_3543484181_init();
    work_m_00000000002569896762_0949684337_init();
    work_m_00000000002992415452_1260470467_init();
    work_m_00000000004186516278_0444708417_init();
    work_m_00000000000566819148_2450498241_init();
    work_m_00000000003493433441_3924142895_init();
    work_m_00000000004134447467_2073120511_init();


    xsi_register_tops("work_m_00000000003493433441_3924142895");
    xsi_register_tops("work_m_00000000004134447467_2073120511");


    return xsi_run_simulation(argc, argv);

}
