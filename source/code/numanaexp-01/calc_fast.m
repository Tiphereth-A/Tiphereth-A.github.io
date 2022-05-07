function ret = calc_fast()
    % Syntax: ret = calc_fast()
    %
    % The function about calculating Hamming's series

    % @Author: Tifa
    % @LastEditTime: 2021-04-16 20:30:47

    % check results when this variable is true
    check = true;

    ret = zeros(3001, 1);
    ret(1) = pi^2/6;

    syms k s

    for x = 0.1:0.1:0.9
        s = 1 / (k * (k + 1) * (k + x));
        ret(floor(x * 10) + 1) = (1 - x) * vpa(symsum(s, k, 1, 71000)) + 1;
    end

    for x = 1:0.1:300
        ret(floor(x * 10) + 1) = (x - 1) * ret(floor(x * 10) - 9) / x + 1 / x / x;
    end

    if check

        for x = 0:0.1:300

            if error_judge(x, ret(floor(x * 10) + 1))
                error('Error exceed!')
            end

        end

    end

end
