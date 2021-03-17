% Load Oceanic data and create arrays from data columns
load_data;

% Load thickness values
depth_thickness;

% Calculate weights
thicki = thicki';
weight = thicki.*mask;

% Calculate weighted averages
average_richardson_number = sum(richardson_number.*weight)/sum(weight);
average_heat_diffusivity = sum(heat_diffusivity.*weight)/sum(weight);

% Display results with a precision of 4 decimal places
% fprintf('riavg: %.4d\n', average_richardson_number);
% fprintf('khavg: %.4d\n', average_heat_diffusivity);
