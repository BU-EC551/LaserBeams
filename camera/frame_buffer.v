`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    13:31:47 04/17/2015 
// Design Name: 
// Module Name:    frame_buffer 
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
//adapted from: http://www.dilloneng.com/inferring-block-ram-vs-distributed-ram-in-xst-and-precision.html#/
//
//////////////////////////////////////////////////////////////////////////////////
module frame_buffer(doutb, clka, wea, addra, din, clkb, addrb);
	output	[7:0]		doutb;
	input		[14:0]	addra, addrb;
	input		[7:0] 	din;
	input					clka, clkb, wea;
	
	
	   
   reg	 [7:0]  mem[0:4095]; 
   reg    [14:0]  raddr_reg;
 
   always @ (posedge clkb)
   begin
      raddr_reg  <= addra;
   end
	 
	always @ (posedge clka) begin
		if (wea) begin     
			mem[addrb]  <= din;  
      end
	end
 
   assign doutb = mem[raddr_reg]; 

endmodule
