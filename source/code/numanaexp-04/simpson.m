function output = simpson(inputf, l, r)

    % @Author: Tifa
    % @LastEditTime: 2021-05-06 23:06:44

    output = (inputf(l) + 4 * inputf (l + (r - l) / 2) + inputf(r)) .* (r - l) / 6;
end
