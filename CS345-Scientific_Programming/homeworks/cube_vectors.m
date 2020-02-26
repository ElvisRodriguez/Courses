u = randi(10, 100,1);
v = 1:length(u);
for i = 1:length(u)
  v(i) = u(i) ^ 3;
end