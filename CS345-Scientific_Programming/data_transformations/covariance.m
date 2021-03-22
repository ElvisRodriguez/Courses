% Calculate Covariance of the richardson number and heat diffusivity values

% Load weighted values
weighted_average;

% Create variable to hold covariance
covariance_of_kh_ri = 0;

% Calculate covariance which is Σ((xi - xm) * (yi - ym))/(n - 1)
n = max(size(richardson_number));
for i = 1:n
    xi_sub_xm = richardson_number(i) - average_richardson_number;
    yi_sub_ym = heat_diffusivity(i) - average_heat_diffusivity;
    covariance_of_kh_ri = covariance_of_kh_ri + (xi_sub_xm * yi_sub_ym);
end
covariance_of_kh_ri = covariance_of_kh_ri / (n - 1);

fprintf('Covariance of RI and KH: %d', covariance_of_kh_ri);