function input_check(A, b)
    % @Author: Tifa
    % @LastEditTime: 2021-06-09 00:22:44

    if ~iscolumn(b)
        error('Error: b should be a column vector!')
    end
    if ~ismatrix(A)
        error('Error: A should be a matrix!')
    end
    if size(A, 1) ~= size(A, 2)
        error('Error: A should be a square matrix!')
    end
    if det(A) == 0
        error('Error: A should be a nonsingular matrix!')
    end
end
