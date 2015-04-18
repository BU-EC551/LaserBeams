`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    20:45:58 04/16/2015 
// Design Name: 
// Module Name:    sender 
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
module sender(siod, sioc, taken, send, id, regis, value, clk);
	input clk, send;
	input [7:0] id, regis, value;
	inout siod;
	output reg sioc, taken;

   reg [7:0] divider;
   reg [31:0] busy_sr;
   reg [31:0] data_sr;
	reg siod_temp;
	
	initial begin
		divider <= 8'b00000001;   // this value gives a 254 cycle pause before the initial frame is sent
		busy_sr <=32'b0;
		data_sr <= 32'd1;
	end
	
   always @(busy_sr, data_sr[31])  begin
      if (!(busy_sr[11:10] == 2'b10 || busy_sr[20:19] == 2'b10 || busy_sr[29:28] == 2'b10))
         //siod_temp <= z; //original code said to set at z
      //else
         siod_temp <= data_sr[31];
   end
   
   always @ (posedge clk) begin
		taken <= 0;
		
			if (busy_sr[31] == 0) begin
            sioc <= 1;
            if (send == 1) begin
               if (divider == 8'b00000000) begin
                  data_sr <= {3'b100, id, 1'b0, regis, 1'b0, value, 'b0, 2'b01};
                  busy_sr <= 32'hffffffff;
                  taken <= 1;
					end
               else
                  divider <= divider+1; //this only happens on powerup
            end
			end
         else begin
            case ({busy_sr[31:29],busy_sr[2:0]})
               6'b111111: // start seq #1
                  case (divider[7:6])
                     2'b00:   sioc <= 1;
                     2'b01:   sioc <= 1;
                     2'b10:   sioc <= 1;
                     default: sioc <= 1;
                  endcase
               6'b111110: // start seq #2
                  case (divider[7:6])
                     2'b00:   sioc <= 1;
                     2'b01:   sioc <= 1;
                     2'b10:   sioc <= 1;
                     default: sioc <= 1;
                  endcase
               6'b111100: // start seq #3
                  case (divider[7:6])
                     2'b00:   sioc <= 0;
                     2'b01:   sioc <= 0;
                     2'b10:   sioc <= 0;
                     default: sioc <= 0;
                  endcase
               6'b110000: // end seq #1
                  case (divider[7:6])
                     2'b00:   sioc <= 0;
                     2'b01:   sioc <= 1;
                     2'b10:   sioc <= 1;
                     default: sioc <= 1;
                  endcase
               6'b100000: // end seq #2
                  case (divider[7:6])
                     2'b00:   sioc <= 1;
                     2'b01:   sioc <= 1;
                     2'b10:   sioc <= 1;
                     default: sioc <= 1;
                  endcase
               6'b000000: // Idle
                  case (divider[7:6])
                     2'b00:   sioc <= 1;
                     2'b01:   sioc <= 1;
                     2'b10:   sioc <= 1;
                     default: sioc <= 1;
                  endcase
               default:       
                  case (divider[7:6])
                     2'b00:   sioc <= 0;
                     2'b01:   sioc <= 1;
                     2'b10:   sioc <= 1;
                     default: sioc <= 0;
                  endcase
            endcase  

            if (divider == 8'b11111111) begin
               busy_sr <= {busy_sr[30:0], 0};
               data_sr <= {data_sr[30:0], 1};
               divider <= 8'b0;
				end
            else
               divider <= divider+1;
         end
   end
	
	assign siod = siod_temp;

endmodule
