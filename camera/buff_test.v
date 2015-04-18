`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   15:42:49 04/17/2015
// Design Name:   frame_buffer
// Module Name:   X:/Desktop/camera/buff_test.v
// Project Name:  camera
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: frame_buffer
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module buff_test;

	// Inputs
	reg clka;
	reg wea;
	reg [14:0] addra;
	reg [7:0] din;
	reg clkb;
	reg [14:0] addrb;

	// Outputs
	wire [7:0] doutb;

	// Instantiate the Unit Under Test (UUT)
	frame_buffer uut (
		.doutb(doutb), 
		.clka(clka), 
		.wea(wea), 
		.addra(addra), 
		.din(din), 
		.clkb(clkb), 
		.addrb(addrb)
	);

	initial begin
		// Initialize Inputs
		clka = 0;
		wea = 0;
		addra = 0;
		din = 0;
		clkb = 0;
		addrb = 0;

		// Wait 100 ns for global reset to finish
		#100;
        
		// Add stimulus here
		din = 8'b11111111;
		addra = 15'b000000000011111;
		addrb = 15'b000000000011111;
		wea=1;
	end
	
	always begin
		clkb=~clkb;
		#10;
		clka=~clka;
		din=din+1;
	end
      
endmodule

