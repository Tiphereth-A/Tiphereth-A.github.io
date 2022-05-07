function output_function = lsmfit(input_functions, x, y)
    %lsmfit - Calculating linear least square method fit curve with given data
    %
    % Syntax: output_function = lsmfit(input_functions, x, y)

    % @Author: Tifa
    % @LastEditTime: 2021-04-22 23:05:47

    input_check(input_functions, x, y)

    len_x = length(x);
    len_funcs = length(input_functions);
    output_function = 0;

    X = zeros(len_x, len_funcs);

    for i = 1:len_funcs
        X(:, i) = subs(input_functions(i), x);
    end

    A = X' * X \ X' * y';

    for i = 1:len_funcs
        output_function = output_function + A(i) * input_functions(i);
    end

end

function input_check(input_functions, x, y)
    % Input check of Exp.2

    % @Author: Tifa
    % @LastEditTime: 2021-04-22 23:05:47

    if ~isvector(input_functions) ||~isvector(x) ||~isvector(y)
        error('All arguments should be vectors')
    end

    if ~isnumeric(x) ||~isnumeric(y)
        error('Input x and y should be numerals')
    end

    if ~isa(input_functions, 'sym')
        error('Input functions should be symbolic expressions')
    end

    if length(x) ~= length(y)
        error('The length of x and y should be equal')
    end

    var1 = symvar(input_functions(1));

    if length(var1) ~= 1
        error('All the input functions should be only one variant')
    end

    for now_func = input_functions(2:end)

        if symvar(now_func) ~= var1
            error('Variant in every input functions should be the same')
        end

    end

end
