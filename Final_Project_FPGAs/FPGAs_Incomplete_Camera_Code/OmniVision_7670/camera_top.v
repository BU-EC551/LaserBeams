`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    22:49:16 04/16/2015 
// Design Name: 
// Module Name:    camera_top 
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
//Adapted from VHDL code at: http://hamsterworks.co.nz/mediawiki/index.php/OV7670_camera
//
//////////////////////////////////////////////////////////////////////////////////
module camera_top(clk, cam_sioc, cam_siod, cam_reset, cam_pwdn, cam_vsync, cam_href, cam_pclk, 
						cam_xclk, cam_d, LED, vga_red, vga_green, vga_blue, vga_hsync, vga_vsync, btn);
						
					
	input clk, cam_vsync, cam_href, cam_pclk, btn;
	output cam_sioc, cam_reset, cam_pwdn, cam_xclk, vga_hsync, vga_vsync;
	inout cam_siod; 
	 
	input [7:0] cam_d;

	output [7:0] LED;
	
	output [2:0] vga_red, vga_green;
	output [1:0] vga_blue;

   wire rst;
	wire con_clk;
	wire [2:0] sel;
	
   wire [14:0] frame_addr, capture_addr;
   wire [7:0] frame_pixel, capture_data;

   wire capture_we, resend, config_finished;

	assign rst = 0;
	assign sel = 3'b0;
	divider(con_clk, clk);
	
	debounce bouncy(resend, btn, clk);

   painter picasso(vga_red, vga_green, vga_blue, vga_hsync, vga_vsync, frame_addr, frame_pixel, clk);

	frame_buffer holding(frame_pixel, cam_pclk, capture_we, capture_addr, capture_data, clk, frame_addr);
  
	assign LED= capture_data[7:0];
	
	capture cam_in(capture_addr, capture_data, capture_we, cam_pclk, cam_vsync, cam_href, cam_d);
  
	cam_controller cam_control(cam_siod, cam_sioc, cam_reset, cam_pwdn, cam_xclk, config_finished, resend, con_clk);

endmodule
