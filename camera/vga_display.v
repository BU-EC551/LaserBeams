`timescale 1ns / 1ps

module vga_display(rst, clk, sel, vals, R, G, B, HS, VS, R_control, G_control, B_control);
	input rst;	// global reset
	input clk;	// 100MHz clk
	input [2:0] sel; //indicating which register is selected
	input [111:0] vals;
	// color inputs for a given pixel
	input [2:0] R_control, G_control;
	input [1:0] B_control; 
	
	// color outputs to show on display (current pixel)
	output reg [2:0] R, G;
	output reg [1:0] B;
	
	// Synchronization signals
	output HS;
	output VS;
	
	// controls:
	wire [10:0] hcount, vcount;	// coordinates for the current pixel
	wire blank;	// signal to indicate the current coordinate is blank
	wire figure1;
	wire figure2;// the figure you want to display
	wire a1, a2, a3, a4, a5;
	wire b1, b2, b3, b4, b5;
	wire c1, c2, c3, c4, c5;
	wire d1, d2, d3, d4, d5;
	wire e1, e2, e3, e4, e5;
	wire f1, f2, f3, f4, f5;
	wire g1, g2, g3, g4, g5;
	reg [15:0] pc;
	reg[6:0] regl;
	reg[6:0] sev1, sev2, sev3, sev4;
	reg [3:0] seg1, seg2, seg3, seg4;
		
		initial begin
			pc 	<= 16'd0;
			sev1 <= 0;
			sev2 <= 0;
			sev3 <= 0;
			sev4 <= 0;
		end
	
		always @ (sel)
		begin
			case(sel)
				3'b000 : regl <= 7'b1000000;
				3'b001 : regl <= 7'b1111001;
				3'b010 : regl <= 7'b0100100;
				3'b011 : regl <= 7'b0110000;
				3'b100 : regl <= 7'b0011001;
				3'b101 : regl <= 7'b0010010;
				default : regl <= 7'b0000010;
			endcase
		end
	
		always @ (sel or vals)
		begin
			case(sel)
				3'b000: pc[15:0] <= vals[15:0];
				3'b001: pc[15:0] <= vals[31:16];
				3'b010: pc[15:0] <= vals[47:32];
				3'b011: pc[15:0] <= vals[63:48];
				3'b100: pc[15:0] <= vals[79:64];
				3'b101: pc[15:0] <= vals[95:80];
				default: pc[15:0] <= vals[111:96];
			endcase
		end
	always @ (*) begin
		seg1 <= pc[15:12];
		seg2 <= pc[11:8];
		seg3 <= pc[7:4];
		seg4 <= pc[3:0];
	end
	
	
	always @ (seg1 or pc)
		begin
			case(seg1)
				4'b0000 : sev1 = 7'b1000000;
				4'b0001 : sev1 = 7'b1111001;
				4'b0010 : sev1 = 7'b0100100;
				4'b0011 : sev1 = 7'b0110000;
				4'b0100 : sev1 = 7'b0011001;
				4'b0101 : sev1 = 7'b0010010;
				4'b0110 : sev1 = 7'b0000010;
				4'b0111 : sev1 = 7'b1111000;
				4'b1000 : sev1 = 7'b0000000;
				4'b1001 : sev1 = 7'b0010000;
				4'b1010 : sev1 = 7'b0001000;
				4'b1011 : sev1 = 7'b0000011;
				4'b1100 : sev1 = 7'b1000110;
				4'b1101 : sev1 = 7'b0100001;
				4'b1110 : sev1 = 7'b0000110;
				4'b1111 : sev1 = 7'b0001110;
				default : sev1 = 7'b1000000;
			endcase
		end
		
	always @ (seg2 or pc)
		begin
			case(seg2)
				4'b0000 : sev2 = 7'b1000000;
				4'b0001 : sev2 = 7'b1111001;
				4'b0010 : sev2 = 7'b0100100;
				4'b0011 : sev2 = 7'b0110000;
				4'b0100 : sev2 = 7'b0011001;
				4'b0101 : sev2 = 7'b0010010;
				4'b0110 : sev2 = 7'b0000010;
				4'b0111 : sev2 = 7'b1111000;
				4'b1000 : sev2 = 7'b0000000;
				4'b1001 : sev2 = 7'b0010000;
				4'b1010 : sev2 = 7'b0001000;
				4'b1011 : sev2 = 7'b0000011;
				4'b1100 : sev2 = 7'b1000110;
				4'b1101 : sev2 = 7'b0100001;
				4'b1110 : sev2 = 7'b0000110;
				4'b1111 : sev2 = 7'b0001110;
				default : sev2 = 7'b1000000;
			endcase
		end
		
	always @ (seg3 or pc)
		begin
			case(seg3)
				4'b0000 : sev3 = 7'b1000000;
				4'b0001 : sev3 = 7'b1111001;
				4'b0010 : sev3 = 7'b0100100;
				4'b0011 : sev3 = 7'b0110000;
				4'b0100 : sev3 = 7'b0011001;
				4'b0101 : sev3 = 7'b0010010;
				4'b0110 : sev3 = 7'b0000010;
				4'b0111 : sev3 = 7'b1111000;
				4'b1000 : sev3 = 7'b0000000;
				4'b1001 : sev3 = 7'b0010000;
				4'b1010 : sev3 = 7'b0001000;
				4'b1011 : sev3 = 7'b0000011;
				4'b1100 : sev3 = 7'b1000110;
				4'b1101 : sev3 = 7'b0100001;
				4'b1110 : sev3 = 7'b0000110;
				4'b1111 : sev3 = 7'b0001110;
				default : sev3 = 7'b1000000;
			endcase
		end
		
	always @ (seg4 or pc)
		begin
			case(seg4)
				4'b0000 : sev4 = 7'b1000000;
				4'b0001 : sev4 = 7'b1111001;
				4'b0010 : sev4 = 7'b0100100;
				4'b0011 : sev4 = 7'b0110000;
				4'b0100 : sev4 = 7'b0011001;
				4'b0101 : sev4 = 7'b0010010;
				4'b0110 : sev4 = 7'b0000010;
				4'b0111 : sev4 = 7'b1111000;
				4'b1000 : sev4 = 7'b0000000;
				4'b1001 : sev4 = 7'b0010000;
				4'b1010 : sev4 = 7'b0001000;
				4'b1011 : sev4 = 7'b0000011;
				4'b1100 : sev4 = 7'b1000110;
				4'b1101 : sev4 = 7'b0100001;
				4'b1110 : sev4 = 7'b0000110;
				4'b1111 : sev4 = 7'b0001110;
				default : sev4 = 7'b1000000;
			endcase
		end
	
	/////////////////////////////////////////////////////
	// Begin clock division
	parameter N = 2;	// parameter for clock division
	reg clk_25Mhz;
	reg [N-1:0] count;
	always @ (posedge clk) begin
		count <= count + 1'b1;
		clk_25Mhz <= count[N-1];
	end
	// End clock division
	/////////////////////////////////////////////////////
	
	// Call driver
	vga_controller_640_60 vc(
		.rst(rst), 
		.pixel_clk(clk_25Mhz), 
		.HS(HS), 
		.VS(VS), 
		.hcounter(hcount), 
		.vcounter(vcount), 
		.blank(blank));
	
	
	// create a box:
	assign figure1 = ~blank & (hcount >= 200 & hcount <= 250 & vcount >= 150 & vcount <= 155);
	assign figure2 = ~blank & (hcount >= 200 & hcount <= 250 & vcount >= 140 & vcount <= 145);
	//s
	
	// Assigning by segments:
	assign g1 = (hcount >= 110 & hcount <= 150 & vcount >= 100 & vcount <= 105);
	assign f1 = (hcount >= 150 & hcount <= 155 & vcount >=105  & vcount <= 145);
	assign e1 = (hcount >= 150 & hcount <= 155 & vcount >= 150 & vcount <= 190);
	assign d1 = (hcount >= 110 & hcount <= 150 & vcount >= 190 & vcount <= 195);
	assign c1 = (hcount >= 105 & hcount <= 110 & vcount >= 150 & vcount <= 190);
	assign b1 = (hcount >= 105 & hcount <= 110 & vcount >= 105  & vcount <= 145);
	assign a1 = (hcount >= 110 & hcount <= 150 & vcount >= 145 & vcount <= 150);
	
	//seg1
	assign g2 = (hcount >= 305 & hcount <= 345 & vcount >= 100 & vcount <= 105);
	assign f2 = (hcount >= 345 & hcount <= 350 & vcount >=105  & vcount <= 145);
	assign e2 = (hcount >= 345 & hcount <= 350 & vcount >= 150 & vcount <= 190);
	assign d2 = (hcount >= 305 & hcount <= 345 & vcount >= 190 & vcount <= 195);
	assign c2 = (hcount >= 300 & hcount <= 305 & vcount >= 150 & vcount <= 190);
	assign b2 = (hcount >= 300 & hcount <= 305 & vcount >= 105  & vcount <= 145);
	assign a2 = (hcount >= 305 & hcount <= 345 & vcount >= 145 & vcount <= 150);
	
	
	//seg2
	assign g3 = (hcount >= 360 & hcount <= 400 & vcount >= 100 & vcount <= 105);
	assign f3 = (hcount >= 400 & hcount <= 405 & vcount >=105  & vcount <= 145);
	assign e3 = (hcount >= 400 & hcount <= 405 & vcount >= 150 & vcount <= 190);
	assign d3 = (hcount >= 360 & hcount <= 400 & vcount >= 190 & vcount <= 195);
	assign c3 = (hcount >= 355 & hcount <= 360 & vcount >= 150 & vcount <= 190);
	assign b3 = (hcount >= 355 & hcount <= 360 & vcount >= 105  & vcount <= 145);
	assign a3 = (hcount >= 360 & hcount <= 400 & vcount >= 145 & vcount <= 150);
	
	
	
	//seg3
	assign g4 = (hcount >= 415 & hcount <= 455 & vcount >= 100 & vcount <= 105);
	assign f4 = (hcount >= 455 & hcount <= 460 & vcount >=105  & vcount <= 145);
	assign e4 = (hcount >= 455 & hcount <= 460 & vcount >= 150 & vcount <= 190);
	assign d4 = (hcount >= 415 & hcount <= 455 & vcount >= 190 & vcount <= 195);
	assign c4 = (hcount >= 410 & hcount <= 415 & vcount >= 150 & vcount <= 190);
	assign b4 = (hcount >= 410 & hcount <= 415 & vcount >= 105  & vcount <= 145);
	assign a4 = (hcount >= 415 & hcount <= 455 & vcount >= 145 & vcount <= 150);
	
	
	//seg4
	assign g5 = (hcount >= 470 & hcount <= 510 & vcount >= 100 & vcount <= 105);
	assign f5 = (hcount >= 510 & hcount <= 515 & vcount >=105  & vcount <= 145);
	assign e5 = (hcount >= 510 & hcount <= 515 & vcount >= 150 & vcount <= 190);
	assign d5 = (hcount >= 470 & hcount <= 510 & vcount >= 190 & vcount <= 195);
	assign c5 = (hcount >= 465 & hcount <= 470 & vcount >= 150 & vcount <= 190);
	assign b5 = (hcount >= 465 & hcount <= 470 & vcount >= 105  & vcount <= 145);
	assign a5 = (hcount >= 470 & hcount <= 510 & vcount >= 145 & vcount <= 150);
	
	
	
	// send colors:
	always @ (posedge clk) begin
		if (figure1 || figure2) begin	// if you are within the valid region
			R = 111;
			G = 0;
			B = 0;
		end
		else begin	// if you are outside the valid region
			R = 0;
			G = 0;
			B = 0;
		end
		
		//Defining what register it is
		if (a1)
			if (regl[6] == 0) begin
				R = 3'b111;
				G = 0;
				B = 0;
			end
			else begin
				R = R_control;
				G = G_control;
				B = B_control;
			end
		else if (b1)
			if (regl[5] == 0) begin
				R = 3'b111;
				G = 0;
				B = 0;
			end
			else begin
				R = R_control;
				G = G_control;
				B = B_control;
			end
		else if (c1)
			if (regl[4] == 0) begin
				R = 3'b111;
				G = 0;
				B = 0;
			end
			else begin
				R = R_control;
				G = G_control;
				B = B_control;
			end
		else if (d1)
			if (regl[3] == 0) begin
				R = 3'b111;
				G = 0;
				B = 0;
			end
			else begin
				R = R_control;
				G = G_control;
				B = B_control;
			end
		else if (e1)
			if (regl[2] == 0) begin
				R = 3'b111;
				G = 0;
				B = 0;
			end
			else begin
				R = R_control;
				G = G_control;
				B = B_control;
			end
		else if (f1)
			if (regl[1] == 0) begin
				R = 3'b111;
				G = 0;
				B = 0;
			end
			else begin
				R = R_control;
				G = G_control;
				B = B_control;
			end
		else if (g1)
			if (regl[0] == 0) begin
				R = 3'b111;
				G = 0;
				B = 0;
			end
			else begin
				R = R_control;
				G = G_control;
				B = B_control;
			end
			
			else if (a2)
			if (sev1[6] == 0) begin
				R = 3'b111;
				G = 0;
				B = 0;
			end
			else begin
				R = R_control;
				G = G_control;
				B = B_control;
			end
		else if (b2)
			if (sev1[5] == 0) begin
				R = 3'b111;
				G = 0;
				B = 0;
			end
			else begin
				R = R_control;
				G = G_control;
				B = B_control;
			end
		else if (c2)
			if (sev1[4] == 0) begin
				R = 3'b111;
				G = 0;
				B = 0;
			end
			else begin
				R = R_control;
				G = G_control;
				B = B_control;
			end
		else if (d2)
			if (sev1[3] == 0) begin
				R = 3'b111;
				G = 0;
				B = 0;
			end
			else begin
				R = R_control;
				G = G_control;
				B = B_control;
			end
		else if (e2)
			if (sev1[2] == 0) begin
				R = 3'b111;
				G = 0;
				B = 0;
			end
			else begin
				R = R_control;
				G = G_control;
				B = B_control;
			end
		else if (f2)
			if (sev1[1] == 0) begin
				R = 3'b111;
				G = 0;
				B = 0;
			end
			else begin
				R = R_control;
				G = G_control;
				B = B_control;
			end
		else if (g2)
			if (sev1[0] == 0) begin
				R = 3'b111;
				G = 0;
				B = 0;
			end
			else begin
				R = R_control;
				G = G_control;
				B = B_control;
			end
		
		if (a3)
			if (sev2[6] == 0) begin
				R = 3'b111;
				G = 0;
				B = 0;
			end
			else begin
				R = R_control;
				G = G_control;
				B = B_control;
			end
		else if (b3)
			if (sev2[5] == 0) begin
				R = 3'b111;
				G = 0;
				B = 0;
			end
			else begin
				R = R_control;
				G = G_control;
				B = B_control;
			end
		else if (c3)
			if (sev2[4] == 0) begin
				R = 3'b111;
				G = 0;
				B = 0;
			end
			else begin
				R = R_control;
				G = G_control;
				B = B_control;
			end
		else if (d3)
			if (sev2[3] == 0) begin
				R = 3'b111;
				G = 0;
				B = 0;
			end
			else begin
				R = R_control;
				G = G_control;
				B = B_control;
			end
		else if (e3)
			if (sev2[2] == 0) begin
				R = 3'b111;
				G = 0;
				B = 0;
			end
			else begin
				R = R_control;
				G = G_control;
				B = B_control;
			end
		else if (f3)
			if (sev2[1] == 0) begin
				R = 3'b111;
				G = 0;
				B = 0;
			end
			else begin
				R = R_control;
				G = G_control;
				B = B_control;
			end
		else if (g3)
			if (sev2[0] == 0) begin
				R = 3'b111;
				G = 0;
				B = 0;
			end
			else begin
				R = R_control;
				G = G_control;
				B = B_control;
			end
			
		else if (a4)
			if (sev3[6] == 0) begin
				R = 3'b111;
				G = 0;
				B = 0;
			end
			else begin
				R = R_control;
				G = G_control;
				B = B_control;
			end
		else if (b4)
			if (sev3[5] == 0) begin
				R = 3'b111;
				G = 0;
				B = 0;
			end
			else begin
				R = R_control;
				G = G_control;
				B = B_control;
			end
		else if (c4)
			if (sev3[4] == 0) begin
				R = 3'b111;
				G = 0;
				B = 0;
			end
			else begin
				R = R_control;
				G = G_control;
				B = B_control;
			end
		else if (d4)
			if (sev3[3] == 0) begin
				R = 3'b111;
				G = 0;
				B = 0;
			end
			else begin
				R = R_control;
				G = G_control;
				B = B_control;
			end
		else if (e4)
			if (sev3[2] == 0) begin
				R = 3'b111;
				G = 0;
				B = 0;
			end
			else begin
				R = R_control;
				G = G_control;
				B = B_control;
			end
		else if (f4)
			if (sev3[1] == 0) begin
				R = 3'b111;
				G = 0;
				B = 0;
			end
			else begin
				R = R_control;
				G = G_control;
				B = B_control;
			end
		else if (g4)
			if (sev3[0] == 0) begin
				R = 3'b111;
				G = 0;
				B = 0;
			end
			else begin
				R = R_control;
				G = G_control;
				B = B_control;
			end
			
			
		else if (a5)
			if (sev4[6] == 0) begin
				R = 3'b111;
				G = 0;
				B = 0;
			end
			else begin
				R = R_control;
				G = G_control;
				B = B_control;
			end
		else if (b5)
			if (sev4[5] == 0) begin
				R = 3'b111;
				G = 0;
				B = 0;
			end
			else begin
				R = R_control;
				G = G_control;
				B = B_control;
			end
		else if (c5)
			if (sev4[4] == 0) begin
				R = 3'b111;
				G = 0;
				B = 0;
			end
			else begin
				R = R_control;
				G = G_control;
				B = B_control;
			end
		else if (d5)
			if (sev4[3] == 0) begin
				R = 3'b111;
				G = 0;
				B = 0;
			end
			else begin
				R = R_control;
				G = G_control;
				B = B_control;
			end
		else if (e5)
			if (sev4[2] == 0) begin
				R = 3'b111;
				G = 0;
				B = 0;
			end
			else begin
				R = R_control;
				G = G_control;
				B = B_control;
			end
		else if (f5)
			if (sev4[1] == 0) begin
				R = 3'b111;
				G = 0;
				B = 0;
			end
			else begin
				R = R_control;
				G = G_control;
				B = B_control;
			end
		else if (g5)
			if (sev4[0] == 0) begin
				R = 3'b111;
				G = 0;
				B = 0;
			end
			else begin
				R = R_control;
				G = G_control;
				B = B_control;
			end
			
		
	end

endmodule
