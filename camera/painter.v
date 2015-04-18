`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    20:46:33 04/16/2015 
// Design Name: 
// Module Name:    painter 
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
module painter(vga_red, vga_green, vga_blue, vga_hsync, vga_vsync, frame_addr, frame_pixel, clk50);
		input clk50;
		input [7:0] frame_pixel;
		output reg [2:0] vga_red, vga_green;
		output reg [1:0] vga_blue;
		output vga_hsync, vga_vsync;
		output [14:0] frame_addr;

	parameter hRez = 800;
   parameter vRez = 600;

   parameter hMaxCount = 1056;
   parameter hStartSync = 840;
   parameter hEndSync = 968;
   parameter vMaxCount = 628;
   parameter vStartSync = 601;
   parameter vEndSync = 605;
   parameter hsync_active = 1'b1;
   parameter vsync_active = 1'b1;
	parameter N = 2;
	parameter rst = 0;

   wire [10:0] hCounter;
   wire [9:0] vCounter;
   reg [16:0] address;
   wire blank;
	reg pixel_clk;
	reg [N-1:0] count;
	
	initial begin
		address <= 17'b0;
		//blank <= 1;
	end
	
	always @ (posedge clk50) begin
		count <= count + 1'b1;
		pixel_clk <= count[N-1];
	end
	
	vga_controller_640_60 controlling(
		.rst(rst),
		.pixel_clk(pixel_clk),
		.HS(vga_hsync),
		.VS(vga_vsync),
		.hcounter(hCounter),
		.vcounter(vCounter),
		.blank(blank));

   always @(posedge clk50) begin
         //Count the lines and rows      
//         if (hCounter == hMaxCount-1) begin
//            hCounter <= 11'b0;
//            if (vCounter == vMaxCount-1) 
//               vCounter <= 10'b0;
//            else
//               vCounter <= vCounter+1;
//			end
//         else
//            hCounter <= hCounter+1;

         if (blank == 0) begin
            vga_red   <= frame_pixel[7:5];
            vga_green <= frame_pixel[4:2];
            vga_blue  <= frame_pixel[1:0];
			end
         else begin
            vga_red   <= 3'b0;
            vga_green <= 3'b0;
            vga_blue  <= 2'b0;
         end
   
         if (vCounter  >= vRez) begin
            address <= 17'b0;
            //blank <= 1;
			end
         else 
            if (hCounter  >= 11'd80 && hCounter  < 11'd720) begin
               //blank <= 0;
               if (hCounter == 11'd719) begin
                  if (vCounter[1:0] != 2'b11)
                     address <= address - 17'd639;
                  else
                      address <= address+1;
					end
               else
                  address <= address+1;
				end
//            else
//               blank <= 1;
   
         // Are we in the hSync pulse? (one has been added to include frame_buffer_latency)
//         if (hCounter > hStartSync && hCounter <= hEndSync) 
//            vga_hsync <= hsync_active;
//         else
//            vga_hsync <= ~hsync_active;

         // Are we in the vSync pulse?
//         if (vCounter >= vStartSync && vCounter < vEndSync) 
//            vga_vsync <= vsync_active;
//         else
//            vga_vsync <= ~vsync_active;
   end

   assign frame_addr = address[16:2];

endmodule
