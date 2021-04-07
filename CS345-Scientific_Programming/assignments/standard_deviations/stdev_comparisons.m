% Load manually calculated RI/KH standard deviations and weight
stdev;

% Calculate standard deviation using built in std() function
ri_builtin_stdev = std(ri(1:31), weight);
kh_builtin_stdev = std(kh(1:31), weight);

% Compare both standard deviations of RI
fprintf('RI standard deviation (without built in function):\n');
fprintf('%.11d\n', ri_stdev);
fprintf('RI standard deviation (using built in function):\n');
fprintf('%.11d\n', ri_builtin_stdev);

% Compare both standard deviations of KH
fprintf('KH standard deviation (without built in function):\n');
fprintf('%d\n', kh_stdev);
fprintf('KH standard deviation (using built in function):\n');
fprintf('%d\n', kh_builtin_stdev);