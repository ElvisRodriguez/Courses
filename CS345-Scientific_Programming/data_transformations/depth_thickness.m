% Load Oceanic data and create arrays from data columns
load_data;

% Create an array to hold our thickness values
thicki = 1:max(size(depthi));

% Calculate thickness using upper and lower bounds
for k = 1:max(size(depthi))
    if k == 1
        thicki(k) = depthi(k);
    elseif k == max(size(depthi))
        thicki(k) = (depthi(k) - depthi(k-1));
    else
        thicki(k) = (depthi(k+1)-depthi(k-1))/2;
    end
end

% Display results
% disp(thicki);