% Remove any previously loaded variables
clear;

% Load Data
data = load('oceanic_data.txt');

% Extract columns from matrix data
longitude = data(:,1);
latitude = data(:,2);
depthi = data(:,3);
richardson_number = data(:,4);
heat_diffusivity = data(:,5);

% Remove bad values
mask = (richardson_number ~= -1.e30);