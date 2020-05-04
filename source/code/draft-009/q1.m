% Plot histogram and line chart with given data

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
strR = ['RGR'; 'YGR'; 'AGR'];
nbins = 6;

for i = 1:3
    % Plot histogram
    subplot(2, 3, i)
    histogram(R(i, :), nbins)
    title(sprintf('histogram of %s', strR(i, :)))
    xlabel('Rate/%')
    ylabel('Frequency')

    % Plot line chart
    subplot(2, 3, 3 + i)
    plot(R(i, :))
    title(sprintf('line chart of %s', strR(i, :)))
    xlabel('Month')
    ylabel('Rate/%')
    grid on
end
