function solution()
  n = [-4:4];
  x = [1:5 4:-1:1];
  subplot(2,1,1);
  stem(n,x);
  title('Input Signal');
  xlabel('n');
  ylabel('x(n)');
  
  [x11,n11] = sigshift(x,n,2);
  [x12,n12] = sigshift(x,n,-3);
  [x1,n1] = sigadd(x11,n11,x12,n12);
  subplot(2,1,2);
  stem(n1,x1);
  title('Output Signal');
  xlabel('n');
  ylabel('y(n)');
end