function poly_out = calc_lagrange_fast(input_x, input_y)
    %calc_lagrange_fast - Calculating Lagrange interpolating polynomial with given points with O(n log^2 n)
    %
    % Syntax: poly_out = calc_lagrange_fast(input_x, input_y)

    % @Author: Tifa
    % @LastEditTime: 2021-04-16 20:49:47

    input_check(input_x, input_y);

    d_omega = domg(1, length(input_x));
    poly_out = llr(1, length(input_x));

    function output = domg(l, r)
    %domg - Calculating {\omega'(x_k)} based on divide and conquer

        if l == r
            output = input_x - input_x(l);
            output(l) = 1;
            return
        end

        mid = floor(l + (r - l) / 2);
        output = domg(l, mid) .* domg(mid + 1, r);
    end

    function [poly_ret, omega_l, omega_r] = llr(l, r)
    %llr - Calculating {L_{l,r}} based on divide and conquer

        if l == r
            poly_ret = input_y(l) / d_omega(l);
            omega_l = 1;
            omega_r = 1;
            return
        end

        mid = floor(l + (r - l) / 2);
        [poly_ret1, omega_l1, omega_r1] = llr(l, mid);
        [poly_ret2, omega_l2, omega_r2] = llr(mid + 1, r);
        omega_l = conv(omega_l1, omega_r1);
        omega_r = conv(omega_l2, omega_r2);

        if mid == l
            omega_l = [1, -input_x(l)];
        end

        if mid == r - 1
            omega_r = [1, -input_x(r)];
        end

        tmp_l = conv(poly_ret1, omega_r); tmp_r = conv(poly_ret2, omega_l);
        len_l = length(tmp_l); len_r = length(tmp_r);

        if len_l > len_r
            tmp = tmp_l; tmp_l = tmp_r; tmp_r = tmp;
            tmp = len_l; len_l = len_r; len_r = tmp;
        end

        tmp_r(len_r - len_l + 1:end) = tmp_r(len_r - len_l + 1:end) + tmp_l;
        poly_ret = tmp_r;

    end

end
