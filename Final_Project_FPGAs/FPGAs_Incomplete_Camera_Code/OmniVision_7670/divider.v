`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    17:19:51 04/22/2015 
// Design Name: 
// Module Name:    divider 
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
module divider(out_clk, in_clk);

	input in_clk;
	output out_clk;
	
	reg count;
	reg temp;

	always @ (posedge in_clk) begin
		count <= count + 1'b1;
	end
	
	assign out_clk = count;
endmodule
