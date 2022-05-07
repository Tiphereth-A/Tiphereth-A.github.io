function [x, k] = gauss_seidol(A, b, epsi)

    % @Author: Tifa
    % @LastEditTime: 2021-06-22 23:03:26

    G = (diag(diag(A)) + tril(A, -1)) \ -triu(A, 1);
    if max(abs(eig(G))) >= 1
      error('Not convergent!');
    end
    k = 1;
    x_pre = ones(length(b), 1);
    b = (diag(diag(A)) + tril(A, -1)) \ b;
    x = G * x_pre + b;
    while norm(x - x_pre, inf) > epsi
        x_pre = x;
        x = G * x + b;
        k = k + 1;
    end
end
