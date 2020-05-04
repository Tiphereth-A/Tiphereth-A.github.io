% Exp.4

% @Author: Tifa
% @LastEditTime: 2021-05-06 23:06:44

% Global arguments
now_type = 2;
round_digit = 12;
if now_type == 1
    now_integral = @integral_with_h;
    now_arg = 4;
    get_step = false;
elseif now_type == 2
    now_integral = @integral_with_eps;
    now_arg = 1e-10;
    get_step = true;
end

% Data
syms x
f = {@(x) sqrt(4 - sin(x).^2), @(x) sin(x) ./ x, @(x) exp(x) ./ (4 + x.^2), @(x) log(1 + x) ./ (1 + x.^2)};
ranges = [0, 0.25; 0 + eps, 1; 0, 1; 0, 1];
method_key = ['tpz'; 'sps'; 'rbg'];
method_name = {'Trapezoid'; 'Simpson'; 'Romberg'};

disp(['Now : ', func2str(now_integral)])

for i = 1:length(method_key)
    disp(['Method: ', method_name{i}])

    for j = 1:length(f)
        now_funcstr = regexp(func2str(f{j}), '^@\([a-z,]*[a-z]\)', 'split');
        fprintf(['\tFunction: ', now_funcstr{end}, '; from %.2f to %.2f\n'], ranges(j, 1), ranges(j, 2))

        if get_step
            [val, step] = now_integral(f{j}, method_key(i, :), ranges(j, 1), ranges(j, 2), now_arg);
            now_vals = [val, step];
        else
            now_vals = now_integral(f{j}, method_key(i, :), ranges(j, 1), ranges(j, 2), now_arg);
        end

        fprintf('\tValue: ')
        disp(vpa(now_vals, round_digit))
    end

end
