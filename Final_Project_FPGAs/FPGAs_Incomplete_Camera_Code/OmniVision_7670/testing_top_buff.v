`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   18:19:36 04/17/2015
// Design Name:   top_buffer
// Module Name:   X:/Desktop/camera/testing_top_buff.v
// Project Name:  camera
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: top_buffer
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module testing_top_buff;

	// Inputs
	reg clk;
	reg cam_vsync;
	reg cam_href;
	reg cam_pclk;
	reg [7:0] cam_d;

	// Outputs
	wire cam_sioc;
	wire cam_reset;
	wire cam_pwdn;
	wire cam_xclk;

	// Bidirs
	wire cam_siod;

	// Instantiate the Unit Under Test (UUT)
	top_buffer uut (
		.clk(clk), 
		.cam_sioc(cam_sioc), 
		.cam_siod(cam_siod), 
		.cam_reset(cam_reset), 
		.cam_pwdn(cam_pwdn), 
		.cam_vsync(cam_vsync), 
		.cam_href(cam_href), 
		.cam_pclk(cam_pclk), 
		.cam_xclk(cam_xclk), 
		.cam_d(cam_d)
	);

	initial begin
		// Initialize Inputs
		clk = 0;
		cam_vsync = 0;
		cam_href = 0;
		cam_pclk = 0;
		cam_d = 0;

		// Wait 100 ns for global reset to finish
		#100;
		// Add stimulus here

	end
	
	always begin
		#10 clk = ~clk;
		#5 cam_pclk = ~cam_pclk;
		#5 cam_vsync=~cam_vsync;
		#5 cam_href=~cam_href;
		cam_d = cam_d+1;
	end
      
endmodule

