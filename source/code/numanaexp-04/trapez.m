function output = trapez(inputf, l, r)

    % @Author: Tifa
    % @LastEditTime: 2021-05-06 23:06:44

    output = (inputf(l) + inputf(r)) .* (r - l) / 2;
end
