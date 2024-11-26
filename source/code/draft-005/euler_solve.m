function output = euler_solve(u_start, a0, A, h, n)
    u_curr = u_start;
    res = zeros(n, size(u_start, 1));
    res(1, :) = u_start;

    for i = 2:n
        u_next = u_curr + h .* u_curr .* (a0 + A * u_curr);
        res(i, :) = u_next;
        u_curr = u_next;
    end

    output = res;
end
