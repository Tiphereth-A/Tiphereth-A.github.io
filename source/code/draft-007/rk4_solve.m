function output = rk4_solve(u_start, a0, A, h, n)
    u_curr = u_start;
    res = zeros(n, size(u_start, 1));
    res(1, :) = u_start;

    for i = 2:n
        k1 = h .* u_curr .* (a0 + A * u_curr);
        k2 = h .* (u_curr + 1/2) .* (a0 + A * (u_curr + k1 / 2));
        k3 = h .* (u_curr + 1/2) .* (a0 + A * (u_curr + k2 / 2));
        k4 = h .* u_curr .* (a0 + A * (u_curr + k3));
        u_next = u_curr + (k1 + 2 * k2 + 2 * k3 + k4) / 6;
        res(i, :) = u_next;
        u_curr = u_next;
    end

    output = res;
end
