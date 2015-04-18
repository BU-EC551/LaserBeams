`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   16:50:14 04/17/2015
// Design Name:   capture
// Module Name:   X:/Desktop/camera/capture_test.v
// Project Name:  camera
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: capture
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module capture_test;

	// Inputs
	reg pclk;
	reg vsync;
	reg href;
	reg [7:0] d;

	// Outputs
	wire [14:0] addr;
	wire [7:0] dout;
	wire we;

	// Instantiate the Unit Under Test (UUT)
	capture uut (
		.addr(addr), 
		.dout(dout), 
		.we(we), 
		.pclk(pclk), 
		.vsync(vsync), 
		.href(href), 
		.d(d)
	);

	initial begin
		// Initialize Inputs
		pclk = 0;
		vsync = 0;
		href = 0;
		d = 0;

		// Wait 100 ns for global reset to finish
		#100;
        d = 8'b01010101;
		// Add stimulus here

	end
	
	always begin
		#10 pclk = ~pclk;
		#10 href = ~href;
		#10 vsync=~vsync;
		d = d+1;
	end
      
endmodule

