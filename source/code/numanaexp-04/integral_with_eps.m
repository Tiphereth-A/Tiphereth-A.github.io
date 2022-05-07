function [val, min_step] = integral_with_eps(input_function, integral_type, l, r, epsi)
    input_check(input_function, integral_type, l, r, epsi)

    % @Author: Tifa
    % @LastEditTime: 2021-05-06 23:06:44

    if l <= r
        flag = 1;
    else
        flag = -1;
        tmp = l; l = r; r = tmp;
    end

    switch integral_type
        case 'sps'
            func = @asr;
        case 'tpz'
            func = @atr;
        case 'rbg'
            func = @romberg;
        otherwise
            error('Unknown integral type')
    end

    [val, min_step] = func(input_function, l, r, epsi);
    val = val * flag;

end

function [val, min_step] = asr(inputf, l, r, epsi)
    [val, min_step] = BASE(inputf, l, r, epsi, @simpson, 15);
end

function [val, min_step] = atr(inputf, l, r, epsi)
    [val, min_step] = BASE(inputf, l, r, epsi, @trapez, 3);
end

function [val, min_step] = BASE(inputf, l, r, epsi, integral_function, C, S)
    narginchk(5, 7)

    if nargin == 5
        C = 1;
        S = integral_function(inputf, l, r);
    elseif nargin == 6
        S = integral_function(inputf, l, r);
    end

    mid = l + (r - l) / 2;
    Sl = integral_function(inputf, l, mid); Sr = integral_function(inputf, mid, r);

    if abs(Sl + Sr - S) < C * epsi
        val = vpa(Sl + Sr + (Sl + Sr - S) / C);
        min_step = r - l;
    else
        [vall, stpl] = BASE(inputf, l, mid, epsi / 2, integral_function, C, Sl);
        [valr, stpr] = BASE(inputf, mid, r, epsi / 2, integral_function, C, Sr);
        val = vall + valr;
        min_step = min(stpl, stpr);
    end

end

function [val, min_step] = romberg(inputf, l, r, epsi)
    k = 0; len = r - l;
    T = len * (inputf(l) + inputf(r)) / 2;
    err = inf;

    while err >= epsi
        k = k + 1;
        len = len / 2;
        T(k + 1, 1) = T(k, 1) / 2 + len * sum(inputf(l + (2 * (1:(2^(k - 1))) - 1) .* len));

        for j = 1:k
            T(k + 1, j + 1) = T(k + 1, j) + (T(k + 1, j) - T(k, j)) / (4^j - 1);
        end

        err = abs(T(k + 1, k + 1) - T(k, k));
    end

    val = vpa(T(k + 1, k + 1));
    min_step = 1/2^k;
end
