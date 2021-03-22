clear;
data= load('oceanic_data.txt');
lon=data(:,1);
lat=data(:,2);
depthi=data(:,3);
kh=data(:,5);
ri=data(:,4);
thicket1;
weight=thicki(1:m);
riavg=sum(ri(1:m).*weight)/sum(weight);
khavg=sum(kh(1:m).*weight)/sum(weight);
%Squares of mean
riavg2=riavg^2;
khavg2=khavg^2;
%Mean of squares
ri2avg=sum(ri(1:m).^2.*weight)/sum(weight);
kh2avg=sum(kh(1:m).^2.*weight)/sum(weight);
rivar=ri2avg-riavg2;
khvar=kh2avg-khavg2;
ri_stdev=rivar^(1/2);
kh_stdev=khvar^(1/2);