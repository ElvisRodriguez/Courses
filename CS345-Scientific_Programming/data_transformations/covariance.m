% Load weighted values
weighted_average;

% Calculate Covariance of the richardson number and heat diffusivity values
n = max(size(richardson_number)) - 0;

mean_of_products = sum(richardson_number(1:n).*heat_diffusivity(1:n).*weight(1:n))/sum(weight(1:n));
covariance_of_kh_ri = mean_of_products - (average_richardson_number*average_heat_diffusivity);

fprintf('Covariance of RI and KH: %d\n', covariance_of_kh_ri);