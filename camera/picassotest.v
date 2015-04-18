`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   16:09:37 04/17/2015
// Design Name:   painter
// Module Name:   X:/Desktop/camera/picassotest.v
// Project Name:  camera
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: painter
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module picassotest;

	// Inputs
	reg [7:0] frame_pixel;
	reg clk50;

	// Outputs
	wire [2:0] vga_red;
	wire [2:0] vga_green;
	wire [1:0] vga_blue;
	wire vga_hsync;
	wire vga_vsync;
	wire [14:0] frame_addr;

	// Instantiate the Unit Under Test (UUT)
	painter uut (
		.vga_red(vga_red), 
		.vga_green(vga_green), 
		.vga_blue(vga_blue), 
		.vga_hsync(vga_hsync), 
		.vga_vsync(vga_vsync), 
		.frame_addr(frame_addr), 
		.frame_pixel(frame_pixel), 
		.clk50(clk50)
	);

	initial begin
		// Initialize Inputs
		frame_pixel = 0;
		clk50 = 0;

		// Wait 100 ns for global reset to finish
		#100;
        
		// Add stimulus here
		frame_pixel=8'b01010101;
	end
	
	always begin
		#10clk50=~clk50;
	end
      
endmodule

