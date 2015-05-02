`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    16:36:56 04/16/2015 
// Design Name: 
// Module Name:    capture 
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
module capture(addr, dout, we, pclk, vsync, href, d);
	output [14:0] addr;
	output [7:0] dout;
	output reg we;
	input pclk, vsync, href;
	input [7:0] d;
	
	reg [7:0] d_latch;
	reg href_last;
	reg [1:0] cnt;
	reg [2:0] hold_red, hold_green;
	reg [1:0] hold_blue;
	reg [14:0] address;
	reg count;
	
	initial begin
		d_latch <= 0;
		cnt <= 0;
		hold_red <= 0;
		hold_green <= 0;
		address <= 0;
		count <= 0;
	end
	
	always @ (posedge pclk) begin
		we   <= 0;
		
		if (vsync == 1) begin
			address <= 15'b111111111111111;
			href_last <= 0;
			cnt <= 2'b00;
		end
	
		if (href_last == 1 && address != 15'b100101011111111) begin
			if (cnt == 2'b11) begin
				address <= address+1;
			end
			if (cnt == 01) begin
				we   <= 1;
			end
			
			cnt <= cnt+1;
		end

		/*if(address<15'b000111111111111) begin
			
			hold_red <= 3'b0;;  
			hold_green <= 3'b0;
			hold_blue <= 2'b0;
		end*/
			
		if (count==0) begin
			hold_red <= d_latch[7:5];  
			hold_green <= d_latch[2:0];
		end
		else
			hold_blue <= d_latch[4:3];
			
		d_latch <= d;
		count <= count+1;
		
		href_last <= href;
	end
	
	
	assign dout = {hold_red, hold_green, hold_blue};   
	assign addr = address;

endmodule
