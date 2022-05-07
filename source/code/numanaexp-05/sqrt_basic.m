function x = sqrt_basic(A, b)

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

    for k = 1:len
        A(k, k) = sqrt(A(k, k));
        A(k + 1:len, k) = A(k + 1:len, k) / A(k, k);
        for j = k + 1:len
            A(j:len, j) = A(j:len, j) - A(j:len, j) * A(j, k);
        end
    end
    for j = 1:len - 1
        b(j) = b(j) / A(j, j);
        b(j + 1:len) = b(j + 1:len) - b(j) * A(j + 1:len, j);
    end
    for j = len:-1:2
        b(j) = b(j) / A(j, j);
        b(1:j - 1) = b(1:j - 1) - b(j) * A(1:j - 1, j);
    end
    x = b;
end
