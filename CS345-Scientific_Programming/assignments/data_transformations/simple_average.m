% Load Oceanic data and create arrays from data columns
load_data;

% Calculate averages
average_richardson_number = sum(richardson_number.*mask)/sum(mask);
average_heat_diffusivity = sum(heat_diffusivity.*mask)/sum(mask);

% Display results with a precision of 4 decimal places
fprintf('riavg: %.4d\n', average_richardson_number);
fprintf('khavg: %.4d\n', average_heat_diffusivity);
