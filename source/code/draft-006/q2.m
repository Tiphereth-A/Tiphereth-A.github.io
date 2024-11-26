% Normalize and fit probability distribution object on given data, then plot histogram, fit curve and error

% @Author: Tifa
% @LastEditTime: 2021-04-12 19:24:47

% Data
% Round-ratio growth rate
RGR = [1.0, 1.3, -0.2, 0.1, 0.1, 0.3, 0.5, 0.3, 0.5, 0.1, -0.2, 0.3];
% Year-on-year growth rate
YGR = [4.9, 4.9, 5.4, 5.3, 5.5, 6.4, 6.5, 6.2, 6.1, 5.5, 4.2, 4.1];
% Accumulated growth rate
AGR = [4.9, 4.9, 5.0, 5.1, 5.2, 5.4, 5.5, 5.6, 5.7, 5.6, 5.5, 5.4];

R = [RGR; YGR; AGR];
m = min(R, [], 2); M = max(R, [], 2);
strR = ['RGR'; 'YGR'; 'AGR'];
distR = ['kernel'; 'kernel'; 'kernel'];
nbins = 6;

for i = 1:3
    subplot(1, 3, i);
    hold on
    grid on
    % Plot normalized histogram
    h = histogram(R(i, :), nbins, 'Normalization', 'pdf');

    % Plot fit curve
    pd = fitdist(R(i, :)', distR(i, :));
    plot_x = linspace(m(i) - abs(m(i)) * 0.1, M(i) + abs(M(i)) * 0.1, 1000);
    plot(plot_x, pdf(pd, plot_x))

    % Plot error
    xx = linspace(m(i), M(i), nbins + 1) + ((M(i) - m(i)) / 2 / nbins);
    xx = xx(1:end - 1);
    yy = h.Values - pdf(pd, xx);
    plot(xx, yy, 'go')
    for j = 1:nbins
        line([xx(j), xx(j)], [0, yy(j)], 'Color', 'g')
    end

    title(sprintf('histogram of %s (normalized)', strR(i, :)))
    xlabel('Rate')
    ylabel('Frequency')
    legend('histogram', 'fit curve', 'error')
    hold off
end
