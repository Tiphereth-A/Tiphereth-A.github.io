function poly_out = calc_lagrange(input_x, input_y)
    %calc_lagrange - Calculating Lagrange interpolating polynomial with given points
    %
    % Syntax: poly_out = calc_lagrange(input_x, input_y)

    % @Author: Tifa
    % @LastEditTime: 2021-04-16 20:49:47

    input_check(input_x, input_y);

    len = length(input_x);
    base_funcs = ones(len);

    for i = 1:len
        now_func = 1;

        for j = 1:len

            if i ~= j
                now_func = conv(now_func, poly(input_x(j))) / (input_x(i) - input_x(j));
            end

        end

        base_funcs(i, :) = now_func;
    end

    poly_out = input_y * base_funcs;

end
