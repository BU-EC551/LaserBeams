`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    11:39:35 04/30/2015 
// Design Name: 
// Module Name:    laser 
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
module laser(clk, laser, fire
    );
input clk, laser;
output reg fire;

always@(posedge clk)begin
case(laser)
1:fire=laser;
default fire = 0;
endcase
end

endmodule
