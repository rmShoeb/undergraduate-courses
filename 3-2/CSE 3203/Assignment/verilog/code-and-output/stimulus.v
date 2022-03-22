`timescale 1ns / 1ps
module stimulus;

reg A;
reg B;
reg C;
reg D;

wire z;

assignment uut(
	.A(A),
	.B(B),
	.C(C),
	.D(D),
	.z(z)
);

initial begin
	$dumpfile("test.vcd");
	$dumpvars(0, stimulus);
	//0 0 0 0
	A=0;
	B=0;
	C=0;
	D=0;
	#20
	//0 0 0 1
	D=1;
	#20
	//0 0 1 1
	C=1;
	#20
	//0 0 1 0
	D=0;
	#20
	//0 1 1 0
	B=1;
	#20
	//0 1 0 0
	C=0;
	#20
	//1 1 0 0
	A=1;
	#20
	//1 0 0 0
	B=0;
	#20
	//1 0 0 1
	D=1;
	#20
	//1 0 1 1
	C=1;
	#20
	//1 0 1 0
	D=0;
	#20
	//1 1 1 0
	B=1;
	#20
	//1 1 1 1
	D=1;
	#20
	//0 1 1 1
	A=0;
	#20
	//0 1 0 1
	C=0;
	#20
	//1 1 0 1
	A=1;	
	#40;
end

initial begin
	$monitor("A=%d B=%d C=%d D=%d z=%d \n", A, B, C, D, z);
end
endmodule