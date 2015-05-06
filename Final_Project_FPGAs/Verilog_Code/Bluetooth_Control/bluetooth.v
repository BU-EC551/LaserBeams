`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    20:24:21 04/28/2015 
// Design Name: 
// Module Name:    bluetooth 
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
module bluetooth (
				output STATUS_OUT,  //show status on a LED
				//output reg CTS=1,
				//input RTS,
				input STATUS_IN,
				output reg RST=1,
				
				output reg data_t=1,
				output clk_9600,
				output reg	[7:0] temp=0,
				input clk,
				input send_button,
				input data_r
				);
	reg [3:0] count_t=0,count_r=0;
	reg [7:0] pack_t=8'b01011000;//info bits
	reg [7:0] pack_r =8'b11111111;	
	//reg [7:0] temp=0;
	
	assign STATUS_OUT=STATUS_IN;


	clock C1(	clk_9600,//output  clk_9600=0, 
					clk_2,clk_4,clk_8,//output clk_2,clk_4,clk_8,
					clk//input clk
				);
//VGA//////////////////////////////////////////////////////////////////////////////
reg [7:0] keep=0;

//RXD//////////////////////////////////////////////////////////////////////////////
	reg [9:0] count_30=0;
	
	always@(posedge clk_9600)
	begin
	
		count_30<=count_30+1'b1;
		if (count_30==500)//x=319   (x+1)/9600=1/30 Tpp=1/30s
			begin
			temp<=0;	
			count_30<=0;
			end
		
		
		case(count_r)
		8:	begin //first info bit
			count_r<=count_r-1;
			pack_r[0]<=data_r;
			temp[0]<=data_r;
			end
		7:	begin 
			count_r<=count_r-1;
			pack_r[1]<=data_r;
			temp[1]<=data_r;
			end
		6:	begin 
			count_r<=count_r-1;
			pack_r[2]<=data_r;
			temp[2]<=data_r;
			end
		5:	begin 
			count_r<=count_r-1;
			pack_r[3]<=data_r;
			temp[3]<=data_r;
			end
		4:	begin 
			count_r<=count_r-1;
			pack_r[4]<=data_r;
			temp[4]<=data_r;
			end
		3:	begin 
			count_r<=count_r-1;
			pack_r[5]<=data_r;
			temp[5]<=data_r;
			end
		2:	begin 
			count_r<=count_r-1;
			pack_r[6]<=data_r;
			temp[6]<=data_r;
			end
		1:	begin //last info bit
			count_r<=count_r-1;
			pack_r[7]<=data_r;
			temp[7]<=data_r;
			end
		default: 		
			if (!data_r)
			begin
			count_r<=8;
			keep<=keep+1;
			end
		endcase
		end
//TXD//////////////////////////////////////////////////////////////////////////////
	always@(posedge clk_9600)
	begin
		if (send_button)
		count_t<=9;
		case(count_t)
		9:	begin //start bit
			count_t<=count_t-1;
			data_t<=0;
			end
		8:	begin //first info bit
			count_t<=count_t-1;
			data_t<=pack_t[0];
			end
		7:	begin 
			count_t<=count_t-1;
			data_t<=pack_t[1];
			end
		6:	begin 
			count_t<=count_t-1;
			data_t<=pack_t[2];
			end
		5:	begin 
			count_t<=count_t-1;
			data_t<=pack_t[3];
			end
		4:	begin 
			count_t<=count_t-1;
			data_t<=pack_t[4];
			end
		3:	begin 
			count_t<=count_t-1;
			data_t<=pack_t[5];
			end
		2:	begin 
			count_t<=count_t-1;
			data_t<=pack_t[6];
			end
		1:	begin //last info bit
			count_t<=count_t-1;
			data_t<=pack_t[7];
			end
		0:	begin 
			data_t<=1;
			end
		default: ;
		endcase
		end
endmodule