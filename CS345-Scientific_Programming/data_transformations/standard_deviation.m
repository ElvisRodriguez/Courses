% Load Variance values
variance;

% Calculate Standard Deviations
richardson_number_standard_deviation = variance_richardson_number^(1/2);
heat_diffusivity_standard_deviation = variance_heat_diffusivity^(1/2);

% Print Results
fprintf('Standard Deviation of Richardson Number:\n');
fprintf('%d\n', richardson_number_standard_deviation);
fprintf('Standard Deviation of Heat Diffusivity:\n');
fprintf('%d\n', heat_diffusivity_standard_deviation);