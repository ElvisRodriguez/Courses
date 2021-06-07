% CS 345 - Project 1 Option A
% Simulation for a rocket launch on the surface of the moon.
clear;
% Mass of rocket body (kg)
mass_body = 1.00;
% Initial mass of rocket fuel (kg)
mass_fuel = 0.305;
% Gravitational constant of the moon (m/s^2)
g = 1.62;
% initial height (from the moon's surface) (km)
height(1) = 0;
% Placeholder variables for future calculations
acceleration = 0;
speed = 0;
current_fuel = mass_fuel;
% Variables to keep track of maximum height at minimum speed
all_speed(1) = 0;
max_height_at_min_speed = 0;
% Constants
timestep = 0.01;
fuel_loss_rate = mass_fuel * timestep / 2;
% Keep track of time and current height
t = 0;
l = 1;
while height(l) >= 0
    % Force of the thrust on the rocket (N)
    force_thrust = (423 / mass_fuel) * current_fuel * 2;
    % Gravitational force on the surface of the moon against the rocket (N)
    force_gravity = -1 * (mass_body + current_fuel) * g;
    % Calculate acceleration (m/s^2) f=ma -> a=f/m
    acceleration = (force_thrust + force_gravity) / mass_body;
    % Derive speed (velocity) from acceleration (m/s)
    speed = acceleration * t;
    % Calculate height using displacement formula (m)
    height(l+1) = (0.5 * acceleration * (t * t));
    % Convert height from meters to kilometers
    height(l+1) = height(l+1) / 1000;
    height(l+1) = height(l+1) + height(l);
    all_speed(l) = speed;
    current_fuel = current_fuel - fuel_loss_rate;
    % This branch is needed due to how matlab handles floating point arithmetic
    if current_fuel <= fuel_loss_rate
        current_fuel = 0;
    end
    t = t + timestep;
    l = l + 1;
end

% Calculating answer to question: "What is the height when speed is minimum?"
% Need to remove the initial speed is 0 as that value is before rocket launch
all_speed(1) = all_speed(2);
% We're interested in the minimum magnitude and this have to use absolute value
all_speed = abs(all_speed);
% Now that we know minimum speed, we can find out the height at that moment in time
minimum_speed = min(all_speed);
for i = 1:size(all_speed(:))
    if all_speed(i) == minimum_speed
        max_height_at_min_speed = height(i)
    end
end

time = 0:timestep:t;
height(end) = [];
plot(time,height);
xlabel('Time (seconds)');
ylabel('Height of Rocket (km)');
title('Simulation of 1kg Rocket Launch on Moon');
axis([0. t 0. 30]);