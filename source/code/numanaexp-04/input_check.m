function input_check(input_function, integral_type, l, r, h_or_epsi)
    % Input check of Exp.4

    % @Author: Tifa
    % @LastEditTime: 2021-05-06 23:06:44

    if ~isnumeric(l) ||~isnumeric(r) ||~isnumeric(h_or_epsi)
        error('l, r, h and eps should be numerals')
    end

    if h_or_epsi <= 0
        error('h and eps should be positive')
    end

    if ~ischar(integral_type)
        error('Integral type should be a character array')
    end

    if ~isa(input_function, 'function_handle')
        error('Input function should be function handle')
    end

    if nargin(input_function) ~= 1
        error('Input function should be only one variant')
    end

end
