clear;
distances = [10,9,8,7,6,5,4,3,2,1.5];
forces = [-21.6,-26.6,-33.7,-44.0,-59.9,-86.3,-135,-240,-539,-959];
plot(distances, forces);
xlabel('Force (N)');
ylabel('Charge(µC)');
title('Force of q2 on q1 as a function of distance');
axis([0. -1000. 0. 15.]);