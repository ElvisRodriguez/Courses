clear;
A(1) = 1.e6;
B(1) = 1.e6;
C(1) = 1.e6;
t(1) = 0;
dt = 1800;
half_life_rate = log(2) / 612;
k = half_life_rate;
time_total = 3600.;
nl = time_total / dt;

for l = 1:nl
    t(l+1) = l * dt;
    A(l+1) = (1 - k * dt) * A(l);
    B(l+1) = B(l) / (1 + k * dt);
    C(l+1) = 0.5 * ((1 - k * dt) + 1 / (1 + k * dt)) * C(l);
end

plot(t,A,t,B,'--',t,C,':')
axis([0. 3600. -1.e6 1.e6]);
xlabel('Time in seconds (dt=1800)');
ylabel('Number of neutrons');
title('Simulated neutron decay of Equations 1,2,3');