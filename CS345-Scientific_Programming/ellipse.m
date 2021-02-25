clear;

deg=pi/180.;
a=1;
b=1;

for itheta=0:359
    jtheta=itheta+1;
    theta(jtheta)=jtheta*deg;
end

x=cos(theta)*a;
y=sin(theta)*b;
plot(x,y);

axis([-1.25 1.25 -1.25 1.25]);