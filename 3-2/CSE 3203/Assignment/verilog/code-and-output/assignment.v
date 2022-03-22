//(~A.B.~C.~D)+(~A.~B.~C.~D)
module assignment(
	input A,
	input B,
	input C,
	input D,
	output z
);

wire A_, B_, C_, D_, p, q, r;
//defining NOTs
not(A_, A);
not(B_, B);
not(C_, C);
not(D_, D);
//defining ANDs
and(p, A_, C_, D_);
and(q, p, B);
and(r, p, B_);
//final result
or(z, q, r);

endmodule