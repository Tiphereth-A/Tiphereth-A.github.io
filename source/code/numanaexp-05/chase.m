function x = chase(A, f)

    % @Author: Tifa
    % @LastEditTime: 2021-06-09 00:22:44

    input_check(A, f);

    if ~isempty(find(A ~= diag(diag(A, -1), -1) + diag(diag(A)) + diag(diag(A, 1), 1), 1))
        error('A should be a tri-diagonal matrix')
    end

    a = [0; diag(A, -1)];
    b = diag(A);
    c = [diag(A, 1); 0];

    len = length(f);
    u = zeros(len, 1);
    d = zeros(len, 1); d(1) = b(1);
    for i = 1:len - 1
        u(i) = c(i) / d(i);
        d(i + 1) = b(i + 1) - a(i + 1) * u(i);
    end

    y = zeros(len, 1); y(1) = f(1) / d(1);
    for i = 2:len
        y(i) = (f(i) - a(i) * y(i - 1)) / d(i);
    end
    x = zeros(len, 1); x(len) = y(len);
    for i = len - 1:-1:1
        x(i) = y(i) - u(i) * x(i + 1);
    end
end
