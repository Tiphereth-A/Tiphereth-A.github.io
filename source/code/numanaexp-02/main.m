% Exp.2

% @Author: Tifa
% @LastEditTime: 2021-04-16 20:49:47

% Question flag
now_question = 1;

% Data
if now_question == 1
    x = [0.4, 0.55, 0.65, 0.80, 0.95, 1.05];
    y = [0.41075, 0.57815, 0.69675, 0.90, 1.00, 1.25382];
    xx = [0.596, 0.99];
    plot_x = linspace(0.2, 1.2, 1000);
else
    x = [1, 2, 3, 4, 5, 6, 7];
    y = [0.368, 0.135, 0.050, 0.018, 0.007, 0.002, 0.001];
    xx = [1.8, 6.15];
    plot_x = linspace(0, 9, 1000);
end

% Lagrange interpolating polynomial
p1 = calc_lagrange(x, y);
Y1 = polyval(p1, xx);
disp(vpa(poly2sym(p1), 8))

subplot(2, 2, 1)
plot_y = polyval(p1, plot_x);
hold on
plot(x, y, 'k*');
plot(plot_x, plot_y, 'k');
plot(xx, Y1, 'ko');
title('{\bf Fig. 1} Lagrange interpolating polynomial')
legend('Input points', 'Interpolating polynomial', 'Query points');
hold off

% Cubic spline interpolating polynomial
pp2 = calc_spline3(x, y);
Y2 = ppval(pp2, xx);

for i = 1:size(pp2.coefs, 1)
    disp(vpa(poly2sym(pp2.coefs(i, :)), 8))
end

subplot(2, 2, 2)
plot_y = ppval(pp2, plot_x);
hold on
plot(x, y, 'k*');
plot(plot_x, plot_y, 'k');
plot(xx, Y2, 'ko');
title('{\bf Fig. 2} Cubic spline interpolating polynomial')
legend('Input points', 'Interpolating polynomial', 'Query points');
axis
hold off

% Neville interpolating polynomial
p3 = calc_neville(x, y);
Y3 = polyval(p3, xx);
disp(vpa(poly2sym(p3), 8))

subplot(2, 2, 3)
plot_y = polyval(p3, plot_x);
hold on
plot(x, y, 'k*');
plot(plot_x, plot_y, 'k');
plot(xx, Y3, 'ko');
title('{\bf Fig. 3} Neville interpolating polynomial')
legend('Input points', 'Interpolating polynomial', 'Query points');
axis
hold off

% Newton interpolating polynomial
p4 = calc_newton(x, y);
Y4 = polyval(p4, xx);
disp(vpa(poly2sym(p4), 8))

subplot(2, 2, 4)
plot_y = polyval(p4, plot_x);
hold on
plot(x, y, 'k*');
plot(plot_x, plot_y, 'k');
plot(xx, Y4, 'ko');
title('{\bf Fig. 4} Newton interpolating polynomial')
legend('Input points', 'Interpolating polynomial', 'Query points');
axis
hold off
