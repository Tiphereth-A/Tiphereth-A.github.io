function poly_out = calc_newton(input_x, input_y)
    %calc_newton - Calculating Newton interpolating polynomial with given points
    %
    % Syntax: poly_out = calc_newton(input_x, input_y)
    input_check(input_x, input_y);

    % @Author: Tifa
    % @LastEditTime: 2021-04-16 20:49:47

    if isrow(input_y)
        input_y = input_y';
    end

    len = length(input_x);
    diff_mat = zeros(len); diff_mat(:, 1) = input_y';

    for i = 2:len

        for j = i:len
            diff_mat(j, i) = (diff_mat(j, i - 1) - diff_mat(j - 1, i - 1)) / (input_x(j) - input_x(j - i + 1));
        end

    end

    poly_out = diff_mat(len, len);

    for i = len - 1:-1:1
        poly_out = conv(poly_out, poly(input_x(i)));
        poly_out(end) = poly_out(end) + diff_mat(i, i);
    end

end
