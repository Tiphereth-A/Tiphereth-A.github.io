function input_check(input_x, input_y)
    % Input check of Exp.2

    % @Author: Tifa
    % @LastEditTime: 2021-04-16 20:49:47

    if ~isvector(input_x) ||~isvector(input_y) || length(input_x) ~= length(input_y)
        error('Invalid input!')
    end

end
