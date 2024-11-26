% Find peaks on given data

% @Author: Tifa
% @LastEditTime: 2021-04-12 19:56:47

load SpecData

for i = 1:13
    now_y = Spectra(i, :);
    [pks, loc] = findpeaks(now_y, 'MinPeakProminence', 190, 'MinPeakDistance', 5);
    subplot(3, 5, i)
    hold on

    % Plot given data
    plot(xAxis, now_y)
    title(sprintf('Fig. %d', i))

    % Plot peak points
    plot(xAxis(loc), pks, 'ro')

    % Plot range for all peaks
    for x = pks
        line([(x - 25) (x - 25)], [0 15000], 'Color', 'g')
        line([(x + 25) (x + 25)], [0 15000], 'Color', 'g')
    end

    axis([200 1800 min(now_y) - 500 max(now_y) + 500])
    hold off
end
