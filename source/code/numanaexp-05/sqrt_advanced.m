function x = sqrt_advanced(A, b)

    % @Author: Tifa
    % @LastEditTime: 2021-06-09 00:22:44

    input_check(A, b)

    len = length(b);
    for k = 1:len
        if det(A(1:k, 1:k)) <= 0
            error('A should be a positive definite matrix')
        end
    end
    if ~issymmetric(A)
        error('A should be a symmetric matrix')
    end

    L = diag(ones(len, 1));
    D = zeros(len); D(1, 1) = A(1, 1);
    S = zeros(len);

    for i = 2:len
        for j = 1:i - 1
            S(i, j) = A(i, j) - S(i, 1:j - 1) * L(j, 1:j - 1)';
        end
        L(i, 1:i - 1) = S(i, 1:i - 1) / D(1:i - 1, 1:i - 1)';
        D(i, i) = A(i, i) - S(i, 1:i - 1) * L(i, 1:i - 1)';
    end

    x = zeros(len, 1);
    y = zeros(len, 1);
    for i = 1:len
        y(i) = (b(i) - L(i, 1:i - 1) * D(1:i - 1, 1:i - 1) * y(1:i - 1)) / D(i, i);
    end
    x(len) = y(len);
    for i = len - 1:-1:1
        x(i) = y(i) - L(i + 1:len, i)' * x(i + 1:len);
    end
end
