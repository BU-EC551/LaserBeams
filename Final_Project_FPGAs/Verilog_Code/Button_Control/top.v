`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    20:19:06 04/28/2015 
// Design Name: 
// Module Name:    top 
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
module top(clk, RCServo_pulse,Throttle_pulse,throttle, direction,laser,
//data_t,data_r,clk_9600,send_button,STATUS_OUT,STATUS_IN,RST,led,
fire//RxD
    );
input clk,laser;
input [1:0] throttle, direction;
output RCServo_pulse,Throttle_pulse;
//input data_r;
//output data_t;
//output clk_9600;
//output STATUS_OUT;
///input STATUS_IN;
//output RST;
//output [7:0] led;

output fire;
//input laser;

wire [7:0] temp;
//input send_button;

//assign throttle = temp[3:2];
//assign direction = temp[1:0];
//assign laser = temp[4];
//input laser;
//assign led = temp;
/*
bluetooth M2(STATUS_OUT,//output STATUS_OUT,  //show status on a LED
				STATUS_IN,//input STATUS_IN,
			   RST,//output reg RST=1,
				data_t,//output reg data_t=1,
				clk_9600,//output clk_9600,
				temp,//	output reg	[7:0] temp=0,
				clk,//input clk,
				send_button,//input send_button,
				data_r//input data_r
				);
	*/			
steering_pwm M1(clk, RCServo_pulse,direction,throttle,Throttle_pulse//RxD
);

laser M3(clk, laser, fire);

endmodule
