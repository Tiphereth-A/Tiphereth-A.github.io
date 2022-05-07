function [x, k] = sor(A, b, epsi, omegas)

    % @Author: Tifa
    % @LastEditTime: 2021-06-22 23:03:26

    x = zeros(length(b), length(omegas));
    k = zeros(1, length(omegas));
    for i = 1:length(omegas)
        G = (diag(diag(A)) + omegas(i) * tril(A, -1)) \ ((1 - omegas(i)) * diag(diag(A)) - omegas(i) * triu(A, 1));
        if max(abs(eig(G))) >= 1
            error('Not convergent!');
        end
        k(i) = 1;
        x_pre = ones(length(b), 1);
        b1 = omegas(i) * (diag(diag(A)) + omegas(i) * tril(A, -1)) \ b;
        xx = G * x_pre + b1;
        while norm(xx - x_pre, inf) > epsi
            x_pre = xx;
            xx = G * xx + b1;
            k(i) = k(i) + 1;
        end
        x(:, i) = xx;
    end
end
