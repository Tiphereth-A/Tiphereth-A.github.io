function poly_out = calc_neville(input_x, input_y)
    %calc_neville - Calculating Neville interpolating polynomial with given points
    %
    % Syntax: poly_out = calc_neville(input_x, input_y)

    % @Author: Tifa
    % @LastEditTime: 2021-04-16 20:49:47

    input_check(input_x, input_y);

    if isrow(input_y)
        input_y = input_y';
    end

    len = length(input_x);
    A = sym(zeros(len)); A(:, 1) = sym(input_y)';

    syms x

    for i = 2:len

        for j = i:len
            A(j, i) =- ((x - input_x(j)) * A(j - 1, i - 1) + (input_x(j - i + 1) - x) * A(j, i - 1)) / (input_x(j) - input_x(j - i + 1));
        end

    end

    poly_out = sym2poly(A(len, len));

end
