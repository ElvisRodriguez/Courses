% Load the standard deviations of RI and KH
standard_deviation;

% Load RI, KH, and their covariance
covariance;

% Calculate the correlation coeffecient of the richardson number and heat diffusivity
correlation_coeff = covariance_of_kh_ri / (richardson_number_standard_deviation * heat_diffusivity_standard_deviation);

fprintf("\nCorrelation Coeffecient:%d \n", correlation_coeff);