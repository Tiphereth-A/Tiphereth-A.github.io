function x = gauss_advanced(A, b)

    % @Author: Tifa
    % @LastEditTime: 2021-06-09 00:22:44

    input_check(A, b)

    A = [A b];
    len = length(b);

    for i = 1:len - 1
        [~, idxA] = max(abs(A(i:len, i)));
        idxA = idxA + i - 1;
        tmp = A(idxA, :);
        A(idxA, :) = A(i, :);
        A(i, :) = tmp;
        A(i + 1:len, i + 1:len + 1) = A(i + 1:len, i + 1:len + 1) - A(i + 1:len, i) * A(i, i + 1:len + 1) / A(i, i);
    end

    b = A(:, end);
    x = zeros(len, 1);
    for i = len:-1:1
        x(i) = (b(i) - A(i, i + 1:len) * x(i + 1:len)) / A(i, i);
    end
end
