`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    20:43:59 04/16/2015 
// Design Name: 
// Module Name:    cam_controller 
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
module cam_controller(siod, sioc, reset, pwdn, xclk, config_finished, resend, clk);
	 
	 input clk, resend;
	 output wire config_finished, sioc, reset, pwdn, xclk;
	 inout siod;

   reg sys_clk;   
   wire [15:0] command;
   wire finished;
   wire taken;
   wire send;

   parameter [8:0] camera_address = 8'h42;  // 42"; -- Device write ID - see top of page 11 of data sheet

	initial begin
		sys_clk <= 0;
		//finished <= 0;
		//taken <= 0;
	end
	
   assign config_finished = finished;
   
   assign send = ~finished;
	

   sender sending(siod, sioc, taken, send, camera_address, command[15:8], command[7:0], clk);
   

   assign reset = 1; 	// Normal mode
   assign pwdn  = 0;                   // Power device up
   
	//assign reset = 0;
	
   registers regmod(command, finished, clk, resend, taken);

   always @(posedge clk) begin
      sys_clk <= ~sys_clk;
   end 
	
	
   assign xclk  = sys_clk;

endmodule
