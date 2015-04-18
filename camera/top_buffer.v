`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    18:13:52 04/17/2015 
// Design Name: 
// Module Name:    top_buffer 
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
//////////////////////////////////////////////////////////////////////////////////
module top_buffer(clk, cam_sioc, cam_siod, cam_reset, cam_pwdn, cam_vsync, cam_href, cam_pclk, 
						cam_xclk, cam_d);
						
	input clk, cam_vsync, cam_href, cam_pclk;
	output cam_sioc, cam_reset, cam_pwdn, cam_xclk;
	inout cam_siod; 

	 
	input [7:0] cam_d;
	
   wire [14:0] frame_addr, capture_addr;
   wire [7:0] frame_pixel, capture_data;

   wire capture_we, resend, config_finished;

	frame_buffer holding(frame_pixel, clk, capture_we, capture_addr, capture_data, clk, frame_addr);
  
	capture cam_in(capture_addr, capture_data, capture_we, cam_pclk, cam_vsync, cam_href, cam_d);
  
	cam_controller cam_control(cam_siod, cam_sioc, cam_reset, cam_pwdn, cam_xclk, config_finished, resend, clk);


endmodule
