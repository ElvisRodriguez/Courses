function plot_cubed_numbers
    x = 0:0.01:10;
    y = x.^3;
    plot(x,y), xlabel('x'), ylabel('cube(x)'), title('Cubes of x values');
end