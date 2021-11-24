function [y,n] = scaling_shrink(x,m,k,lb,ub)
  % lb = lower bound of n
  % ub = upper bound of n
  n = m*k;
  y = [(n>=lb)|(n<=ub)];