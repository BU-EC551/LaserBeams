`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    17:22:36 04/16/2015 
// Design Name: 
// Module Name:    registers 
// Project Name: 
// Target Devices: 
// Tool versions: 
// Description: 
//
// Dependencies: 
//
// Revision: 
// Revision 0.01 - File Created
// Additional Comments: 
//
//
//Adapted from VHDL code at: http://hamsterworks.co.nz/mediawiki/index.php/OV7670_camera
//
//////////////////////////////////////////////////////////////////////////////////
module registers(command, finished, clk, resend, advance);
	input clk, resend, advance;
	output [15:0] command;
	output reg finished;

   reg [15:0] sreg;
   reg [7:0] address;
	
	initial begin
		address <= 0;
	end
	
   always @(sreg) begin 
		case(sreg)
			16'hxffff: finished  <= 1;
			default: finished <= 0;
		endcase
   end
	
   always @(posedge clk) begin
         if (resend == 1) 
            address <= 8'b0;
         else if (advance == 1) 
            address <= address+1;



         case (address)
            8'h00: sreg <= 16'h1280; // COM7   Reset
            8'h01: sreg <= 16'h1280; // COM7   Reset
            8'h02: sreg <= 16'h1100; // CLKRC  Prescaler - Fin/(1+1)
            8'h03: sreg <= 16'h1204; // COM7   QIF + RGB output
            8'h04: sreg <= 16'h0C04; // COM3  Lots of stuff, enable scaling, all others off
            8'h05: sreg <= 16'h3E19; // COM14  PCLK scaling = 0
            
            8'h06: sreg <= 16'h4010; // COM15  Full 0-255 output, RGB 565
            8'h07: sreg <= 16'h3a04; // TSLB   Set UV ordering,  do not auto-reset window
            8'h08: sreg <= 16'h8C00; // RGB444 Set RGB format
           
            8'h09: sreg <= 16'h1714; // HSTART HREF start (high 8 bits)
            8'h0a: sreg <= 16'h1802; // HSTOP  HREF stop (high 8 bits)
            8'h0b: sreg <= 16'h32A4; // HREF   Edge offset and low 3 bits of HSTART and HSTOP
            8'h0c: sreg <= 16'h1903; // VSTART VSYNC start (high 8 bits)
            8'h0d: sreg <= 16'h1A7b; // VSTOP  VSYNC stop (high 8 bits) 
            8'h0e: sreg <= 16'h030a; // VREF   VSYNC low two bits
           
            8'h0f: sreg <= 16'h703a; // SCALING_XSC
            8'h10: sreg <= 16'h7135; // SCALING_YSC
            8'h11: sreg <= 16'h7211; // SCALING_DCWCTR
            8'h12: sreg <= 16'h73f1; // SCALING_PCLK_DIV
            8'h13: sreg <= 16'ha202; // SCALING_PCLK_DELAY  PCLK scaling = 4, must match COM14
            
            8'h14: sreg <= 16'h1500; // COM10 Use HREF not hSYNC
            8'h15: sreg <= 16'h7a20; // SLOP
            8'h16: sreg <= 16'h7b10; // GAM1
            8'h17: sreg <= 16'h7c1e; // GAM2
            8'h18: sreg <= 16'h7d35; // GAM3
            8'h19: sreg <= 16'h7e5a; // GAM4
            8'h1A: sreg <= 16'h7f69; // GAM5
            8'h1B: sreg <= 16'h8076; // GAM6
            8'h1C: sreg <= 16'h8180; // GAM7
            8'h1D: sreg <= 16'h8288; // GAM8
            8'h1E: sreg <= 16'h838f; // GAM9
            8'h1F: sreg <= 16'h8496; // GAM10
            8'h20: sreg <= 16'h85a3; // GAM11
            8'h21: sreg <= 16'h86af; // GAM12
            8'h22: sreg <= 16'h87c4; // GAM13
            8'h23: sreg <= 16'h88d7; // GAM14
            8'h24: sreg <= 16'h89e8; // GAM15
            8'h25: sreg <= 16'h13E0; // COM8 - AGC, White balance
            8'h26: sreg <= 16'h0000; // GAIN AGC 
            8'h27: sreg <= 16'h1000; // AECH Exposure
            8'h28: sreg <= 16'h0D40; // COMM4 - Window Size
            8'h29: sreg <= 16'h1418; // COMM9 AGC 
            8'h2a: sreg <= 16'ha505; // AECGMAX banding filter step
            8'h2b: sreg <= 16'h2495; // AEW AGC Stable upper limite
            8'h2c: sreg <= 16'h2533; // AEB AGC Stable lower limi
            8'h2d: sreg <= 16'h26e3; // VPT AGC fast mode limits
            8'h2e: sreg <= 16'h9f78; // HRL High reference level
            8'h2f: sreg <= 16'hA068; // LRL low reference level
            8'h30: sreg <= 16'ha103; // DSPC3 DSP control
            8'h31: sreg <= 16'hA6d8; // LPH Lower Prob High
            8'h32: sreg <= 16'hA7d8; // UPL Upper Prob Low
            8'h33: sreg <= 16'hA8f0; // TPL Total Prob Low
            8'h34: sreg <= 16'hA990; // TPH Total Prob High
            8'h35: sreg <= 16'hAA94; // NALG AEC Algo select
            8'h36: sreg <= 16'h13E5; // COM8 AGC Settings
            default: sreg <= 16'hffff;
         endcase




//         case (address)
//            8'h00: sreg <= 16'h1280; // COM7   Reset
//            8'h01: sreg <= 16'h1280; // COM7   Reset
//            8'h02: sreg <= 16'h1100; // CLKRC  Prescaler - Fin/(1+1)
//            8'h03: sreg <= 16'h1204; // COM7   QIF + RGB output
//            8'h04: sreg <= 16'h0C04; // COM3  Lots of stuff, enable scaling, all others off
//            8'h05: sreg <= 16'h3E19; // COM14  PCLK scaling = 0
//            
//            8'h06: sreg <= 16'h4010; // COM15  Full 0-255 output, RGB 565
//            8'h07: sreg <= 16'h3a04; // TSLB   Set UV ordering,  do not auto-reset window
//            8'h08: sreg <= 16'h8C00; // RGB444 Set RGB format
//           
//            8'h09: sreg <= 16'h1714; // HSTART HREF start (high 8 bits)
//            8'h0a: sreg <= 16'h1802; // HSTOP  HREF stop (high 8 bits)
//            8'h0b: sreg <= 16'h32A4; // HREF   Edge offset and low 3 bits of HSTART and HSTOP
//            8'h0c: sreg <= 16'h1903; // VSTART VSYNC start (high 8 bits)
//            8'h0d: sreg <= 16'h1A7b; // VSTOP  VSYNC stop (high 8 bits) 
//            8'h0e: sreg <= 16'h030a; // VREF   VSYNC low two bits
//           
//            8'h0f: sreg <= 16'h703a; // SCALING_XSC
//            8'h10: sreg <= 16'h7135; // SCALING_YSC
//            8'h11: sreg <= 16'h7211; // SCALING_DCWCTR
//            8'h12: sreg <= 16'h73f1; // SCALING_PCLK_DIV
//            8'h13: sreg <= 16'ha202; // SCALING_PCLK_DELAY  PCLK scaling = 4, must match COM14
//            
//            8'h14: sreg <= 16'h1500; // COM10 Use HREF not hSYNC
//            8'h15: sreg <= 16'h7a20; // SLOP
//            8'h16: sreg <= 16'h7b10; // GAM1
//            8'h17: sreg <= 16'h7c1e; // GAM2
//            8'h18: sreg <= 16'h7d35; // GAM3
//            8'h19: sreg <= 16'h7e5a; // GAM4
//            8'h1A: sreg <= 16'h7f69; // GAM5
//            8'h1B: sreg <= 16'h8076; // GAM6
//            8'h1C: sreg <= 16'h8180; // GAM7
//            8'h1D: sreg <= 16'h8288; // GAM8
//            8'h1E: sreg <= 16'h838f; // GAM9
//            8'h1F: sreg <= 16'h8496; // GAM10
//            8'h20: sreg <= 16'h85a3; // GAM11
//            8'h21: sreg <= 16'h86af; // GAM12
//            8'h22: sreg <= 16'h87c4; // GAM13
//            8'h23: sreg <= 16'h88d7; // GAM14
//            8'h24: sreg <= 16'h89e8; // GAM15
//            8'h25: sreg <= 16'h13E0; // COM8 - AGC, White balance
//            8'h26: sreg <= 16'h0000; // GAIN AGC 
//            8'h27: sreg <= 16'h1000; // AECH Exposure
//            8'h28: sreg <= 16'h0D40; // COMM4 - Window Size
//            8'h29: sreg <= 16'h1418; // COMM9 AGC 
//            8'h2a: sreg <= 16'ha505; // AECGMAX banding filter step
//            8'h2b: sreg <= 16'h2495; // AEW AGC Stable upper limite
//            8'h2c: sreg <= 16'h2533; // AEB AGC Stable lower limi
//            8'h2d: sreg <= 16'h26e3; // VPT AGC fast mode limits
//            8'h2e: sreg <= 16'h9f78; // HRL High reference level
//            8'h2f: sreg <= 16'hA068; // LRL low reference level
//            8'h30: sreg <= 16'ha103; // DSPC3 DSP control
//            8'h31: sreg <= 16'hA6d8; // LPH Lower Prob High
//            8'h32: sreg <= 16'hA7d8; // UPL Upper Prob Low
//            8'h33: sreg <= 16'hA8f0; // TPL Total Prob Low
//            8'h34: sreg <= 16'hA990; // TPH Total Prob High
//            8'h35: sreg <= 16'hAA94; // NALG AEC Algo select
//            8'h36: sreg <= 16'h13E5; // COM8 AGC Settings
//            default: sreg <= 16'hffff;
//         endcase
   end
	
   assign command = sreg;

endmodule
