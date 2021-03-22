bad=-1.e30;
dimen=size(depthi);
n=dimen(1);
thicki(1)=(depthi(1)+depthi(2))/2;
for k=2:n-1
    thicki(k)=(depthi(k+1)-depthi(k-1))/2;
    if ri(k+2)==bad  
       m=k+1;	    
       break
    end
end
thicki(m)=(depthi(m)-depthi(m-1))/2;
thicki=thicki';