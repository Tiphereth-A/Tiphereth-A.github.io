function outputFunc = cycle_sequence_generator(sequence)
    %CYCLE_SEQUENCE_GENERATOR
    %    generate a symfun $f(n)$ with given vector
    % $s$, which subject to $f(n)=f(n-l), \forall n>l$ and
    % $f(n)=s(n), \forall 1\leq n\leq l$, assume $|s|=l$
    %
    % Syntax: outputFunc = cycle_sequence_generator(sequence)
    %     sequence: given vector $s$
    %     outputFunc: $f(n)$

    % @Author: Tifa
    % @LastEditTime: 2021-10-21 00:43:45

    if (~isvector(sequence))
        error("sequence should be a vector");
    end

    if (isrow(sequence))
        sequence = sequence';
    end

    N = length(sequence);

    syms w a(n)

    w = sym(cos(2 * pi / N) + 1i * sin(2 * pi / N));
    W = simplify(cumprod(ones(1, N) * w) ./ w);
    a(n) = simplify((W.^(n - 1)) * (fliplr(vander(W))^(-1) * sequence));

    outputFunc = a;
end
