function pp_out = calc_spline3(input_x, input_y)
    %calc_spline3 - Calculating cubic spline interpolating polynomial with given points
    %
    % Syntax: pp_out = calc_spline3(input_x, input_y)
    %
    % You can also use 'pp_out = spline(input_x, input_y)' instead

    % @Author: Tifa
    % @LastEditTime: 2021-04-16 20:49:47

    input_check(input_x, input_y);

    if ~issorted(input_x)
        error('X coordinates of input points should be in ascending order!')
    end

    if iscolumn(input_x)
        input_x = input_x';
    end

    if iscolumn(input_y)
        input_y = input_y';
    end

    len = length(input_x);

    diff_matrix = zeros(len);
    diff_matrix(:, 1) = input_y';

    for i = 2:len

        for j = i:len
            diff_matrix(j, i) = (diff_matrix(j, i - 1) - diff_matrix(j - 1, i - 1)) / (input_x(j) - input_x(j - i + 1));
        end

    end

    h = input_x(2:len) - input_x(1:len - 1);
    g = 6 * (diff_matrix(3:len, 2) - diff_matrix(2:len - 1, 2)) ./ (h(1:len - 2) + h(2:len - 1))';

    m = [0; (eye(len - 2) * 2 + ...
            diag(h(2:len - 2) ./ (h(1:len - 3) + h(2:len - 2)), 1) + ...
            diag(h(2:len - 2) ./ (h(2:len - 2) + h(3:len - 1)), -1)) \ g; 0];

    polys = zeros(len - 1, 4);

    for i = 1:len - 1
        syms x
        polys(i, :) = sym2poly(m(i, 1) * (h(i) - x)^3 / (6 * h(i)) + ...
            m(i + 1, 1) * x^3 / (6 * h(i)) + ...
            (diff_matrix(i, 1) - m(i, 1) / 6 * (h(i))^2) * (h(i) - x) / h(i) + ...
            (diff_matrix(i + 1, 1) - m(i + 1, 1) / 6 * (h(i))^2) * x / h(i));
    end

    pp_out = mkpp(input_x, polys);

end
