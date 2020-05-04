% Parameters
a0 = [1; 0; -1];
A = [0, -0.8, -0.2; 0.8, 0, -0.8; 0.2, 0.8, 0];
n = 4e6; h = 1e-5;
% Initial value
u_start = [4; 2; 1];
% Time
t = 0:h:((n - 1) * h);

% Euler's method
% Faster but less accurate
u_ans = euler_solve(u_start, a0, A, h, n);

% RK4 method
% More accurate but slower
% u_ans = rk4_solve(u_start, a0, A, h, n);

% Amount plot
figure;
plot(t, u_ans(:, 1), 'linewidth', 1.5);
hold on
plot(t, u_ans(:, 2), 'linewidth', 1.5);
plot(t, u_ans(:, 3), 'linewidth', 1.5);
xlabel('Time (t)');
ylabel('Amount (u_1, u_2, u_3)');
legend('show');
legend('u_1', 'u_2', 'u_3')
title('Amount of 3 species')

% Phase-space plot
figure;
subplot(2, 2, 1);
plot3(u_ans(:, 1), u_ans(:, 2), u_ans(:, 3), 'linewidth', 1.5);
grid on
title("Phase-space plot of 3 species");
xlabel('u_1');
ylabel('u_2');
zlabel('u_3');

subplot(2, 2, 2);
plot(u_ans(:, 1), u_ans(:, 2), ...
    'color', [0.8500 0.3250 0.0980], ...
    'linewidth', 1.5);
title("Phase-space plot of u_1 and u_2");
xlabel('u_1');
ylabel('u_2');

subplot(2, 2, 3);
plot(u_ans(:, 1), u_ans(:, 3), ...
    'color', [0.9290 0.6940 0.1250], ...
    'linewidth', 1.5);
title("Phase-space plot of u_1 and u_3");
xlabel('u_1');
ylabel('u_3');

subplot(2, 2, 4);
plot(u_ans(:, 2), u_ans(:, 3), ...
    'color', [0.4940 0.1840 0.5560], ...
    'linewidth', 1.5);
title("Phase-space plot of u_2 and u_3");
xlabel('u_2');
ylabel('u_3');
