function output = integral_with_h(input_function, integral_type, l, r, h)
    input_check(input_function, integral_type, l, r, h)

    % @Author: Tifa
    % @LastEditTime: 2021-05-06 23:06:44

    if ~isinteger(h) && h ~= round(h)
        h = round(h);
        fprintf(2, 'Warning: input h is not integer, using h = %d\n', h)
    end

    x = linspace(l, r, 2^h + 1);

    if l <= r
        output = 1;
    else
        output = -1;
        tmp = l; l = r; r = tmp;
    end

    switch integral_type
        case 'sps'
            output = output .* vpa(sum(simpson(input_function, x(1:end - 1), x(2:end))));
        case 'tpz'
            output = output .* vpa(sum(trapez(input_function, x(1:end - 1), x(2:end))));
        case 'rbg'
            output = output .* vpa(romberg(input_function, l, r, h));
        otherwise
            error('Unknown integral type')
    end

end

function output = romberg(inputf, l, r, h)
    n = 1; len = r - l;
    T = zeros(h + 1);

    T(1, 1) = len / 2 * (inputf(l) + inputf(r));

    for k = 2:h + 1
        len = len / 2;
        T(k, 1) = T(k - 1, 1) / 2 + len * sum(inputf(l + (2 * (1:n) - 1) .* len));

        for j = 1:k - 1
            T(k, j + 1) = T(k, j) + (T(k, j) - T(k - 1, j)) / (4^j - 1);
        end

        n = n * 2;
    end

    output = T(h + 1, h + 1);
end
