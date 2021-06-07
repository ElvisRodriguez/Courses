clear
a(1)=1.e6;
t(1)=0;
dt=1;
%dt=10;
%dt=60;
%dt=600;
%dt=1200;
%dt=1800;
%k=1./1200.
k=log(2)/612; %Casey value of neutron half-life = 10.2 minute
ttotal=3600.;
nl=ttotal/dt;
for l=1:nl
    t(l+1)=l*dt;
    a(l+1)=(1-k*dt)*a(l);
end
% Q4: a(l+1)=a(l)/(1+k*dt)
% Q5: a(l+1)=0.5*((1-k*dt)+1/(1+k*dt))*a(l)

%plot(t,a);
%axis([0. 3600. -1.e6 1.e6]);
%xlabel('time in seconds (dt=1800)');
%ylabel('Number of neutrons');
%title('Simulated neutron decay');

for l=1:nl+1
    t_th(l)=(l-1)*dt;
    a_th(l)=a(1)*exp(-k*t_th(l));
end
plot(t_th,a_th)
xlabel('time in seconds (dt=1)');
ylabel('Number of neutrons');
title('Proportional Error From Theoretical neutron decay')
axis([0. 3600. -1.e6 1.e6])
%plot(t_th,a-a_th);
%title('simulated - theoretical neutron decay')
%axis([0. 3600. -250 250])
%axis([0. 3600. -2500 2500])
%axis([0. 3600. -15000 15000])
%axis([0. 3600. -300000 300000])
%ylabel('simulated expectation number - theoretical expectation number')
%plot(t_th,(a-a_th)./a_th);
%ylabel('(sim. ex. number - theo. ex. number)/theo. ex. number')
%title('proportional simulated - theoretical neutron decay')
%axis([0. 3600. -4.e-3 4.e-3])
%axis([0. 3600. -4.e-2 4.e-2])
%axis([0. 3600. -2.4e-1 2.4e-1])
%axis([0. 3600. -4.8 4.8])

