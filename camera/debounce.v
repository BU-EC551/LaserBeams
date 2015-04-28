`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    22:45:08 04/16/2015 
// Design Name: 
// Module Name:    debounce 
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
//Basic debouncer
//
//////////////////////////////////////////////////////////////////////////////////
module debounce(o, i, clk);
	output reg o;
	input i, clk;

   reg [23:0] c;
	
   always @(posedge clk) begin
         if (i == 1) begin
            c <= c+1;
            if (c == 24'hFFFFFF)
               o <= 1;
            else
               o <= 0;
			end
         else begin
            c <= 24'b0;
            o <= 0;
         end
   end

endmodule
