`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    18:44:43 04/10/2015 
// Design Name: 
// Module Name:    steering_pwm 
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
module steering_pwm(clk, RxD, RCServo_pulse,PulseCount,ClkTick,direction,throttle,Throttle_pulse);
input clk, RxD;
output RCServo_pulse;
output  Throttle_pulse;

////////////////////////////////////////////////////////////////////////////
// use the serial port to control the servo

wire RxD_data_ready;
wire [7:0] RxD_data;
//async_receiver deserialer(.clk(clk), .RxD(RxD), .RxD_data_ready(RxD_data_ready), .RxD_data(RxD_data));  

reg [7:0] RxD_data_reg;
always @(posedge clk) if(RxD_data_ready) RxD_data_reg <= RxD_data;

////////////////////////////////////////////////////////////////////////////
// divide the clock

parameter ClkDiv = 1953; //1248 // means period = 20mS but ClkTick = 1 every 10 mS
reg [11:0] ClkCount;// = 0;
output reg ClkTick;
always @(posedge clk) ClkTick <= (ClkCount==ClkDiv-2);
always @(posedge clk) if(ClkTick) ClkCount <= 0; else ClkCount <= ClkCount + 1;

////////////////////////////////////////////////////////////////////////////
output reg [8:0] PulseCount;// = 0;
//output reg Pulse;//j = 0;
always @(posedge clk) if(ClkTick) PulseCount <= PulseCount + 1;
// make sure the RCServo_position is stable while the pulse is generated
integer left = 100;//2ms 
integer neutral = 75; // started at 36 then tried 45 1.4ms
integer right = 50;// 26 1ms
input [1:0] direction;
reg [7:0] RCServo_position;// = 0;

////////////////////////////////////////////////////////////////////////////
//direction mux
always @(posedge clk)begin 
if(PulseCount==0) begin
case (direction)

1:RCServo_position <= left; //RxD_data_reg;
2:RCServo_position <= right;
default: RCServo_position <=neutral;

endcase
end
end
////////////////////////////////////////////////////////////////////////////
//speed
reg [7:0] Throttle_position;
integer reverse = 50;//26;
integer stop = 75;//36;
integer forward = 90;//51;
input [1:0] throttle;

always @(posedge clk) begin
case (throttle)

1:Throttle_position <= reverse;
2:Throttle_position <= forward;
default: Throttle_position <= stop;
endcase
end
////////////////////////////////////////////////////////////////////////////
reg RCServo_pulse;// = 0;
always @(posedge clk) RCServo_pulse <= (PulseCount < RCServo_position);  //{4'b0001, RCServo_position});

reg Throttle_pulse;// = 0;
always @(posedge clk) Throttle_pulse <= (PulseCount < Throttle_position);
endmodule
