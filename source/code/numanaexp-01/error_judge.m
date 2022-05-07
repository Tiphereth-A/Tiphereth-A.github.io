function output = error_judge(x, input_sum)
    % Syntax: output = error_judge(x, input_sum)
    %
    % return true if the input value's error exceeded, otherwise return false

    % @Author: Tifa
    % @LastEditTime: 2021-04-16 20:30:47

    syms k s
    s = 1 / (k * (k + x));
    accurate_sum = symsum(s, k, 1, inf);

    output = abs(input_sum - vpa(accurate_sum)) > 1e-10;
end
