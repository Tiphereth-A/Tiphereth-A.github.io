% Exp.3

% @Author: Tifa
% @LastEditTime: 2021-04-22 23:05:47

% Data
data_x = 0:5:55;
data_y = [0, 1.27, 2.16, 2.86, 3.44, 3.87, 4.15, 4.37, 4.51, 4.58, 4.02, 4.64] * 1e-4;
plot_x = linspace(0, 60, 1000);

% Calculate $\varphi(t)$ and errors
syms x
f1 = lsmfit([x, x^2, x^3], data_x, data_y);
plot_y = subs(f1, plot_x);
err1 = data_y - subs(f1, data_x);
% Print function and errors
disp('function 1:')
vpa(f1, 8)
disp('error:')
fprintf('%.8f ', err1)
fprintf('\n\n')

% Calculate $\varphi_2(t)=b_0+b_1t+b_2t^2+b_3t^3$ and errors
f2 = poly2sym(polyfit(data_x, data_y, 3));
plot_y2 = subs(f2, plot_x);
err2 = data_y - subs(f2, data_x);
% Print function and errors
disp('function 2:')
vpa(f2, 8)
disp('error:')
fprintf('%.8f ', err2)
fprintf('\n\n')

% Plot two functions
subplot(1, 2, 1)
hold on
plot(data_x, data_y, 'k*')
plot(plot_x, plot_y, 'k')
title('Fig. 1')
xlabel('t/minutes')
legend('data', '{f_1}')
hold off

subplot(1, 2, 2)
hold on
plot(data_x, data_y, 'k*')
plot(plot_x, plot_y2, 'k')
title('Fig. 2')
xlabel('t/minutes')
legend('data', '{f_2}')
hold off
