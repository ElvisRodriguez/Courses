% Load weighted values
weighted_average;

% Create arrays to hold the squared difference of each data point and the mean 
squared_difference_ri = 1:max(size(richardson_number));
squared_difference_kh = 1:max(size(heat_diffusivity));

% Transpose arrays to match the dimensions of the other arrays
squared_difference_ri = squared_difference_ri';
squared_difference_kh = squared_difference_kh';

% Calculate the difference of each data point and the appropriate mean
for i = 1:max(size(richardson_number))
    squared_difference_ri(i) = (richardson_number(i) - average_richardson_number)^2;
    squared_difference_kh(i) = (heat_diffusivity(i) - average_heat_diffusivity)^2;
end

% Add weight to each array
squared_difference_ri = squared_difference_ri.*weight;
squared_difference_kh = squared_difference_kh.*weight;

% Calculate the sum of each square_difference array
sum_squared_difference_ri = sum(squared_difference_ri, 'all');
sum_squared_difference_kh = sum(squared_difference_kh, 'all');

% Calculate the variance of each array
variance_richardson_number = sum_squared_difference_ri / sum(weight);
variance_heat_diffusivity = sum_squared_difference_kh / sum(weight);

% Display variances
% fprintf('Variance of Richardson Number: %d\n', variance_richardson_number);
% fprintf('Variance of Heat Diffusivity: %d\n', variance_heat_diffusivity);
