`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    13:03:19 04/23/2015 
// Design Name: 
// Module Name:    test_divide 
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
module test_divide(in_clk, out);
	input in_clk;
	output [7:0]out;
	parameter N = 40;
	
	reg [N-1:0] count;

	always @ (posedge in_clk) begin
		count <= count + 1'b1;
	end
	
	assign out = out+count[N-1];

endmodule
